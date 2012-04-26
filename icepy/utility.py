#-*- coding: utf-8 -*-
"""
This module isn't really designed for broad use, but is more of a sandbox for
all sorts of ad-hoc utility functions which haven't found a place (or simply 
don't belong) anywhere else.
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
from corpustools import read_bin, read_bin_grouped
from misc import translate_tag
from constants import CATEGORY_MAP

def letter_frequency():
    """ Reads the BÍN corpus and counts instances of each letter found in the
    corpus. Returns a letter=>count mapping.
    """
    d = defaultdict(int)
    for entry in read_bin():
        for letter in entry.ordmynd: d[letter] += 1
    return d

def tag_frequency():
    """ Reads the BÍN corpus and counts instances of each tag (translated to
    IceNLP format) found in the corpus. Returns a tag=>count mapping.
    """
    d = defaultdict(int)
    for entry in read_bin():
        tag = translate_tag(CATEGORY_MAP[entry.flokkur],entry.flokkur,entry.hluti,entry.greining)
        d[(tag,entry.flokkur,entry.hluti,entry.greining)] += 1
    return d

def bin_read():
    """ Simply prints all the entries in the BÍN corpus to screen.
    """
    for entry in read_bin(silent=True):
        print unicode(entry).encode('utf-8')

def bin_debug():
    """ Prints a list of all entries in the BÍN corpus where the first letter of
    the word form is not the same as the first letter of the lemma.

    Useful for debugging, not much else.
    """
    for entry in read_bin(silent=True):
        if entry.ordmynd[0]!=entry.lemma[0]:
            print unicode(entry).encode('utf-8')

def bin_debug_hk():
    """ A short routine created to detect a strange bug in the BÍN corpus where
    certain types of compound words ('hk', 'alm') were incorrectly entered.

    This bug has apparently been fixed but the code may be useful as a reference.
    """
    for entries in read_bin_grouped(silent=True):
        first_entry = entries[0]

        #handle strange bug in BIN, where certain compound words are incorrectly specified
        if first_entry.flokkur=='hk' and first_entry.hluti=='alm':
            proper = [entry for entry in entries if entry.ordmynd[0]==first_entry.ordmynd[0]
                      and not (len(entry.lemma) > 3 and len(entry.ordmynd)<=len(entry.lemma)-2)]
            if len(entries) - len(proper) == 4:
                print first_entry.lemma_id, first_entry.lemma
                continue

def write_wordlist(fout, encoding='utf8'):
    """ Converts the BÍN database into a simple list of word forms and dumps
    into fout, which should be a file or file-like object.
    """
    for entry in read_bin():
        fout.write(entry.ordmynd.encode(encoding)+'\n')

def expansion_pattern_frequency(expansions):
    """ Given a list of AnalysisMatch which contain one or more parts (such as
    the output of Morph.expand(), returns a mapping of tags=>count where *tags*
    is a tuple of each expansion segments' tags and *count* is the total number
    of such patterns found in the input list.
    """
    freqs = defaultdict(int)
    for match in expansions:
        freqs[match.tags()] += 1
    return dict(freqs)

