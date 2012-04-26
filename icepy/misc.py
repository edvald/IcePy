# -*- coding: utf-8 -*-

"""
Contains various utility functions and objects used in IcePy.

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

from constants import ALPHABET
from constants import COMBO_VOWELS
from constants import DECODE_MAP
from constants import ENCODE_MAP
from constants import VOWELS
from operator import itemgetter
from time import time
from _config import BASE_PATH
import os

from collections import defaultdict
from icepy.ext.collections_backport import OrderedDict
import re
from threading import Lock

import yaml

TAG_MAP = yaml.load(open(os.path.join(BASE_PATH,'data/tag_translation.yml'),'r'))
ALPHABET_RE = re.compile(ur'[^%s]' % re.escape(ALPHABET), re.U)

def icepy_encode(input, errors='fail'):
    """ Accepts a unicode string containing all Icelandic characters and returns
    a bytestring encoded using the IcePy encoding map.

    This is primarily used to reduce the memory needed by the Morph maps, as
    storing unicode strings can consume up to 4x the space of 8-bit strings.

    By default raises a ValueError if the input string contains one or more
    characters which are not in the translation table. You can specify
    errors='ignore' to have the suspect characters omitted in the output string
    or errors='replace' to have them replaced by a '?' character.
    """
    if isinstance(input, (list,tuple)):
        #recursively decode an iterable
        return [icepy_encode(s) for s in input]
    elif isinstance(input, (str,unicode)):
        if input=='': return ''
        repl = '?'
        if ALPHABET_RE.search(input):
            if errors=='fail':
                raise ValueError('one or more characters in string %s is not in IcePy alphabet' % repr(input))
            elif errors=='ignore':
                repl = ''
            elif not errors=='replace':
                raise ValueError('unknown value for errors: %s' % repr(errors))
        return ''.join([ENCODE_MAP.get(s,repl) for s in input])
    else:
        raise ValueError('Expected list/tuple or string, got %s' % type(input))


def icepy_decode(*args):
    """ Accepts a string encoded by icepy_encode and returns a decoded unicode
    string.

    If passed a list/tuple of strings, recursively iterates the list and returns
    a corresponding list of decoded strings.
    """
    input = args if len(args)>1 else args[0]
    if isinstance(input, unicode):
        #just pass through is string is already unicode
        return input
    if isinstance(input, (list,tuple)):
        #recursively decode an iterable
        return [icepy_decode(s) for s in input]
    elif isinstance(input, str):
        return u''.join([DECODE_MAP[s] for s in input])
    else:
        raise ValueError('Expected list/tuple or string, got %s' % type(input))

def syllable_split(string):
    """ A simple function for splitting a word into syllables. It's rather
    naive, so it always just splits at a vowel (or double vowel such as 'au').
    This makes it mostly useful for counting syllables.
    """
    syllables = []

    syllable  = ''
    is_vowel = got_vowel = False
    for x,letter in enumerate(string):
        #was_vowel = is_vowel
        is_vowel  = letter in VOWELS

        if is_vowel and got_vowel:
            if string[x-1:x+1] in COMBO_VOWELS:
                syllable += letter
            else:
                syllables.append(syllable)
                syllable = letter
            continue

        got_vowel = is_vowel or got_vowel
        syllable += letter

    syllables.append(syllable)

    return syllables

def count_syllables(string):
    """ Shorthand for len(syllable_split(string)).
    """
    return len(syllable_split(string))

def lemma_deduplicate(matches):
    """ Accepts an iterable of AnalysisMatch objects and returns a list
    deduplicated by lemma, so that only one match object per lemma is returned.
    """
    output = OrderedDict()
    for m in matches:
        output[m.lemma_id] = m
    return output.values()

def translate_tag(tegund, flokkur, hluti, greining):
    """ Accepts the analysis strings for a BÍN entry and returns the
    corresponding IceNLP-style tag.

    Note that there is not always a direct correlation between the BÍN analysis
    markup and the IceNLP tags, but in many cases this works just fine.
    """
    tag = [u'' for r in range(7)]
    
    try:
        base_map = TAG_MAP[tegund]
    except KeyError:
        raise ValueError('cannot translate tag: %s,%s,%s,%s' % (tegund, flokkur, hluti, greining))

    tag[0] = tegund
    if 'def' in base_map:
        for index,symbol in base_map['def']:
            tag[int(index)-1] = symbol

    for key,part_map in base_map.iteritems():
        if key=='def': continue
        if   key=='f': target = flokkur
        elif key=='h': target = hluti
        elif key=='g': target = greining
        else: raise ValueError('invalid key %s in tagmap' % key)

        for part,val in sorted(part_map.iteritems(), key=lambda kv: len(kv[0])):
            if part not in target: continue
            val = val if isinstance(val,list) else [val]
            for index,symbol in val:
                tag[int(index)-1] = symbol

    return u''.join(tag)

class Timing(object):
    slots = ('_timings','_running')

    def __init__(self):
        """ A utility class used for timing portions of code. Useful for
        profiling long-running applications. Use it sparely though, because in
        short loops it might have an effect on performance and thus skew the
        measurements.

        Contains a id=>time map which is incremented for each run of start() and
        end().
        """
        self._timings = defaultdict(float)
        self._running = {}
        self.lock = Lock()

    def start(self, id, restart=False, exclusive=True):
        """ Starts a timer with id. If restart=True, resets any previous timer
        already running with same id. If exclusive=True and reset=False,
        attempting to start a timer which has already been started raises a
        ValueError.
        """
        self.lock.acquire()
        if id in self._running:
            if restart:
                self._running[id] = time()
            elif exclusive:
                raise ValueError('Another timing with ID %s is currently active' % repr(id))
        else:
            self._running[id] = time()
        self.lock.release()
            
    def end(self, id, reset=False):
        """ Stops timer id and increments the result into the result set. If
        reset=True, clears any previous timing results and replaces with just
        the latest one.
        """
        self.lock.acquire()
        if id in self._running:
            timing = time()-self._running[id]
            del self._running[id]
            if reset:
                self._timings[id] = timing
            else:
                self._timings[id] += timing
        else:
            raise ValueError('No active timing with ID %s' % repr(id))
        self.lock.release()

    def reset(self, id):
        """ Resets the timing results for id.
        """
        self.lock.acquire()
        self._timings[id] = 0.0
        self.lock.release()

    def results(self):
        """ Returns a list of (id, time) tuples, sorted by total time in
        descending order.
        """
        return sorted(self._timings.items(), key=itemgetter(1), reverse=True)

    def prettyprint(self):
        """ Pretty prints the output of the above results() function.
        """
        for id, timing in self.results():
            print "%s\t%.4f" % (repr(id).ljust(30), timing)


if __name__=="__main__":
    """ insert simple test code """
    testwords = [
        u'mamma',
        u'lambapottréttur',
        u'bíll',
        u'þorskhaus',
        u'þurrkari',
        u'óáreiðanleiki',
        u'forskeyti',
        u'mþþ',
        u'',
        u'ruglib&ll'
    ]
    for t in testwords:
        print syllable_split(t)
        print repr(icepy_encode(t))

