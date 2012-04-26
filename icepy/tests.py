#-*- coding: utf-8 -*-

"""
A collection of unit tests for IcePy, designed for the *nose* testing framework.
These tests are currently rather simplistic. They only deal with functionality
rather than checking the actual analysis output, as that would need some work in
creating actual test data.

---

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

from ext.collections_backport import OrderedDict
from misc import icepy_decode
from misc import icepy_encode
from morph import Morph
from morph import AnalysisMatch
from _tools import ExpansionPart
from morph import WordformAnalysis
import corpustools
from _testconstants import LOOKUP_TEST

morph = None

def init_morph():
    global morph
    if not morph: morph = Morph()

def setup():
    #TODO: get random lines from BIN
    return

def test_setup():
    #make sure test data prepared by setup() is OK
    return

def test_translate_tag():
    return

def test_read_morphemes():
    for line in corpustools.read_morphemes():
        print line
        assert isinstance(line, tuple)
        assert len(line)==3
        lemma, word, tag = line
        assert isinstance(lemma, (str,unicode))
        assert isinstance(word, (str,unicode))
        assert isinstance(tag, (str,unicode))

def test_read_morphemes_grouped():
    for line in corpustools.read_morphemes_grouped():
        print line
        assert isinstance(line, tuple)
        assert len(line)==2
        lemma, entries = line
        assert isinstance(lemma, (str,unicode))
        assert isinstance(entries, list)
        for word,tag in entries:
            assert isinstance(word, (str,unicode))
            assert isinstance(tag, (str,unicode))

def test_morph():
    init_morph()
    assert isinstance(morph, Morph)
    
    #make sure none of the maps are empty
    #TODO: do a full integrity test on the maps, i.e. check for orphans and
    #      missing ids and such
    assert morph.prefix_map
    assert morph.id_lemma
    assert morph.id_suffixes
    assert morph.bloom

def test_lookup_candidates():
    init_morph()

    for args in LOOKUP_TEST:
        candidates = morph._lookup_candidates(*args)
        print args, ":", candidates
        assert isinstance(candidates, list)

def test_inflection_analysis():
    init_morph()

    for args in LOOKUP_TEST:
        candidates = morph._lookup_candidates(*args)
        #deduplicate by lemma
        matches = OrderedDict()
        for c in candidates:
            matches[c.lemma_id] = c
        for m in matches.itervalues():
            analysis = morph.inflection_analysis(m)
            print args[0].encode('utf8')
            print analysis.suffix_split()
            print

def test_lemma_lookup():
    init_morph()
    #TODO: add expected lemmas to test data, print statistics

    for args in LOOKUP_TEST:
        lemma = morph._lookup_candidates(*args)
        print args, ":", lemma
        if lemma: one = lemma
        assert isinstance(lemma, list)

    #make sure at least one of the strings was found in lookup
    assert one is not None

def test_expand():
    init_morph()

    for args in LOOKUP_TEST:
        print args, ":"
        expansion = morph.expand(*args)
        assert isinstance(expansion, WordformAnalysis)
        for e in expansion.matches:
            assert isinstance(e, AnalysisMatch)
            decoded = e._decode()
            assert isinstance(decoded, AnalysisMatch)
            #print "\t", decoded
            for p in e.parts:
                #print "\t\t", p
                assert isinstance(p, ExpansionPart)

def test_analyse():
    init_morph()

    for args in LOOKUP_TEST:
        result = morph.analyse(*args)

        assert isinstance(result, WordformAnalysis)

        tags = result.tags()
        assert isinstance(tags, set)
        
        if result.matches:
            assert len(tags)>0

        for e in result.matches:
            assert isinstance(e, AnalysisMatch)
            decoded = e._decode()
            assert isinstance(decoded, AnalysisMatch)
            #print "\t", decoded
            for p in e.parts:
                #print "\t\t", p
                assert isinstance(p, ExpansionPart)

def test_iterate_wordforms():
    init_morph()

    i = 0
    for word,tag in morph.iterate_words(True):
        assert isinstance(word, unicode)
        assert isinstance(tag, unicode)
        #maybe we don't have to iterate the whole thing...
        i += 1
        if i > 100000: break

def test_iterate_wordforms_grouped():
    init_morph()

    i = 0
    for group in morph.iterate_words_grouped(True):
        for word,tag in group:
            assert isinstance(word, unicode)
            assert isinstance(tag, unicode)
        #maybe we don't have to iterate the whole thing...
        i += 1
        if i > 10000: break

def test_codec():
    for args in LOOKUP_TEST:
        word = args[0]
        try:
            encoded = icepy_encode(word)
        except ValueError:
            print "Could not encode %s" % repr(word)
            continue
        decoded = icepy_decode(encoded)

        assert word==decoded

def run_tests():
    """The tests are designed to be run by Nose. But since I ran into
    trouble getting Nose to work with Jython here's a quick and dirty
    run through of the above test functions"""

    import StringIO
    import sys

    funcs = (
        setup,
        test_setup,
        test_morph,
        test_analyse,
        test_codec,
        test_expand,
        test_lemma_lookup,
        test_lookup_candidates,
        test_translate_tag
    )

    for f in funcs:
        print "Testing %s..."
        #capture stdout
        buffer = StringIO.StringIO()
        stdout = sys.stdout
        sys.stdout = buffer

if __name__=="__main__":
    run_tests()
