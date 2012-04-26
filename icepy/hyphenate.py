#-*- coding: utf-8 -*-
"""
This module contains a (quite) simple hyphenator, primarily designed to
showcase and test some of the functionality of IcePy.

Uses the IceNLP wrapper, so requires JPype by extension.
"""
"""
This file is a part of the IcePy natural language processing toolkit.
IcePy is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

IcePy is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with IcePy. If not,  see <http://www.gnu.org/licenses/>.

Contact information:
Jón Eðvald Vignisson, CTO, CLARA Ltd.
jon.edvald@clara.is
"""

from collections import defaultdict
from constants import VOWELS_RE
from misc import lemma_deduplicate
from morph import Morph
import re
import icenlp

SOFT_HYPHEN = '\u00ad'.decode('raw-unicode-escape')
BOUNDARIES  = re.compile(ur'[\b]+', re.U)
SEGMENT_SPLIT = re.compile(r'~+')

class Hyphenator(object):
    def __init__(self, morph=None, quality=None):
        """ Initialize a Hyphenator class. You may pass in a Morph() instance,
        or it can create a new one. If you specify quality, that quality will be
        used by default for every call to the hyphenate functions.
        """
        self.morph  = morph or Morph()
        self.default_quality = quality or 2

    def hyphenate_word(self, word, tag, quality=None):
        """ Accepts a word and its POS tag and returns the word with
        hyphenation markers.

        The format is based on the format used in Indehyph, an extension for
        Adobe's InDesign, used for professional layout and design. Hyphenation
        markers ('~' symbols) are inserted into the word where applicable. To
        indicate variable 'quality' levels, a variable number of markers is
        placed at each split index. More markers indicate higher quality. For

        Specify quality as an integer in the range [1:5] to limit the number of
        hyphenation markers. Higher numbers call for higher 'quality' splits,
        such as those at between compound word segments. Lower quality splits
        include for example inflectional suffixes. Example: *kaffi~~~~brús~inn*

        The function uses a number of the morphological analysis features in
        IcePy, primarily word expansion and inflection analysis.
        """
        if not word: return ''
        quality = quality or self.default_quality

        result_indices = defaultdict(float)
        result_set = set()

        #determine split indices based on type of split:
        #1. compound word segments
        #2. inflectional suffixes
        #3. syllables
        #TODO: when available, lookup hand-labelled word splits

        tag = tag.split('-')[0]

        #first see if we can do a direct lookup to find decl. suffixes
        lookup = self.morph.lookup(word,tag=tag)
        for match in lemma_deduplicate(lookup):
            dec_split = self.morph.inflection_analysis(match).suffix_split()
            try:
                index = len(dec_split[tag][0])
            except KeyError:
                #TODO: this should not happen - fix
                print word, tag, dec_split
                continue
            result_indices[index] += 0.1 / len(lookup)

        if not lookup:
            lookup = self.morph.lookup(word,category=tag[0])
            for match in lemma_deduplicate(lookup):
                dec_split = self.morph.inflection_analysis(match).suffix_split()
                splits = [c for c in dec_split.itervalues() if ''.join(c)==word]
                for c in splits:
                    index = len(c[0])
                    result_indices[index] += 0.4 / len(lookup) / len(splits)

        #expand word with tag constraint
        expansion = self.morph.expand(word,tag=tag,single_part=False)
        indices = [index for match in expansion for index in match.split_indices() if index>0]
        candidates = set(indices)

        for match in expansion:
            for c in match.split_indices():
                if indices.count(c)==len(expansion):
                    #assign high quality to unambiguous indices
                    result_indices[c] += 8.0 / len(match.parts)
                else:
                    #assign lower quality to other indices
                    result_indices[c] += 5.0 / len(match.parts)

        if not lookup:
            for match in expansion:
                dec_split = self.morph.inflection_analysis(match).suffix_split()
                index = len(dec_split[tag][0])
                result_indices[index] += 1.0

        result_set |= candidates

        #expand word with more open category constraint
        expansion = self.morph.expand(word,category=tag[0],single_part=False)
        indices = [index for match in expansion for index in match.split_indices() if index>0]
        candidates = set(indices) - result_set

        #assign additional indices with quality 2
        for c in candidates:
            #assign lower quality to other indices
            result_indices[c] += 1.0

        if not lookup:
            for match in expansion:
                dec_split = self.morph.inflection_analysis(match).suffix_split()
                for c in dec_split.itervalues():
                    if ''.join(c) == word:
                        index = len(c[0])
                        result_indices[index] += 0.02

        result_set |= candidates

        #TODO: improve syllable split function and use that to determine
        #      lowest quality indices

        if not result_indices: return word

        #apply indices to word (omitting index 0 for obvious reasons)
        offset = 0
        max_q  = max(result_indices.values())
        factor = 4.0 / max_q if max_q > 4 else 1.0
        for index,q in sorted(result_indices.iteritems()):
            if index>=len(word): break

            q = max( int(round(q*factor,0)) , 1)
            if q < quality: continue

            index += offset
            segment = word[:index]

            #make sure all segments have a vowel
            if not VOWELS_RE.search(segment): q = 0

            word = segment + q * '~' + word[index:]
            offset += q

        return word.strip('~')

    def hyphenate(self, text, quality=None):
        """ Accepts a block of Icelandic text and returns it back with
        hyphenation markers. See hyphenate_word() for details about the format.

        The function runs the text through the IceNLP tokenizer and tagger, but
        uses the IceNLP wrappers' tag_and_iterate() function to maintain the
        original structure of the text.
        """
        output = []
        quality = quality or self.default_quality

        #tokenize/tag text
        for space,word,tag,x in icenlp.tag_and_iterate(text):
            new_word = self.hyphenate_word(word,tag,quality)
            output.append(space+new_word)

        return ''.join(output)

    def soft_hyphenate(self, text, quality=None):
        """ Accepts Icelandic text and returns it back with soft hyphenation
        markers. A soft hyphen is a special character used to indicate an
        optional hyphen in a word. It is supported in most of the latest web
        browsers and some word processing suites, so it might be quite useful.
        """
        return SEGMENT_SPLIT.replace(self.hyphenate(text,quality=quality),SOFT_HYPHEN)


if __name__=="__main__":
    h = Hyphenator()

    article = u"""
    Niðurstöður tveggja skoðanakannana sem birtar voru í Bretlandi í dag sýna að líklega verði niðurstaða þingkosninganna í júní n.k. sú að enginn einn flokkur fái hreinan meirihluta í breska þinginu, að sögn Reuters fréttastofunnar.

Dagblöðin Mail on Sunday og People létu gera skoðanakannanirnar. Niðurstaða beggja varð sú að Íhaldsflokkurinn fengi um 9% meira fylgi en Verkamannaflokkur Gordons Brown forsætisráðherra. Báðar  benda til þess að enginn einn flokkur fái hreinan þingmeirihluta.

Verði niðurstaða kosninganna samkvæmt þessu þá verður það í fyrsta sinn frá miðjum áttunda áratug síðustu aldar að enginn einn flokkur fari með hreinan meirihluta í breska þinginu.
    """

    #print h.icenlp.tag(article)
    #print

    hyphenated =  h.hyphenate(article,quality=1)

    #for i in range(10):
    #    hyphenated =  h.hyphenate(article,quality=3)

    print hyphenated
    print

    #print h.hyphenate(article,quality=2)
    #print

    h.morph.timing.prettyprint()
    print

    h.morph.print_stats()
