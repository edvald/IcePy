#-*- coding: utf-8 -*-

"""
This module contains helper functions for reading and processing the corpora
used by IcePy. This currently includes BÍN and the extract from the Icelandic
word frequency book (OTB) provided in the distribution.

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

from constants import VOWELS
from itertools import izip
import os.path
import sys
from sys import stdout

from _config import BASE_PATH
from _config import OTB_FILENAME
import gzip
from _config import OTB_TAGMAP_FILENAME
import re
from zipfile import ZipFile

import yaml

PICKLE_PROTOCOL = 2
ALPHA_STRICT_RE = re.compile(r'\w', re.U)

class BINEntry(object):
    __slots__ = ('lemma','lemma_id','flokkur','hluti','ordmynd','greining')
    def __init__(self, lemma, lemma_id, flokkur, hluti, ordmynd, greining):
        """
        Constructs a BINEntry object, which is essentially a named tuple
        containing all the attributes extractable from the BÍN corpus.
        """
        self.lemma    = lemma
        self.lemma_id = lemma_id
        self.flokkur  = flokkur
        self.hluti    = hluti
        self.ordmynd  = ordmynd
        self.greining = greining

    def __str__(self):
        return repr(unicode(self))

    def __unicode__(self):
        return u'\t'.join([str(self.lemma_id), self.lemma, self.ordmynd, self.flokkur, self.hluti, self.greining])

FILETYPES = [
    ('csv','','SHsnid.csv'),
    ('csv','gzip','SHsnid.csv.gz'),
    ('csv','zip','SHsnid.csv.zip')
]
def read_bin(silent=False, filter=False):
    """
    Returns an iterator over all the lines in the BÍN corpus file, in the form
    of BINEntry objects. It currently only accepts the SH CSV format.

    If you specify filter=True the iterator will attempt to 'weed out' some of
    the bugs and oddities one might find in the corpus. For details just have a
    look at the function source.

    Set silent=True if you don't want the generator to print progress status
    while iterating.

    Important note: Reading a zipped file directly is currently only supported
    in Python 2.6+! For others versions of Python you must extract the Zip file
    into the data folder.

    """
    #detect which fileformat is appropriate
    #- only supported format now is 'csv' so the format is ignored
    for format,compression,filename in FILETYPES:
        filename = os.path.join(BASE_PATH,'data',filename)
        if not os.path.exists(filename): continue

        if compression=='':
            datafile = open(filename, 'r')
        elif compression=='gzip':
            datafile = gzip.open(filename)
        elif compression=='zip':
            try:
                zip = ZipFile(filename, 'r')
                datafile = zip.open('SHsnid.csv', 'r')
            except:
                continue
    
        break
    else:
        msg = "Could not find a supported BÍN corpus file in the data/ folder."
        if sys.version_info[:2] != (2,6):
            msg += """\nImportant note: Reading a zipped file directly is currently
                     only supported in Python 2.6+! For others versions of Python
                     you must extract the Zip file into the data folder."""
        raise IOError(msg)

    i = 0

    if not silent: print 'BIN:',
    current_lemma = None
    lemma_id = 0
    for line in datafile:
        try:
            lemma,bin_lemma_id,flokkur,hluti,ordmynd,greining = line.decode('utf-8').strip().split(';')
        except:
            continue
        if '' in (lemma,flokkur,ordmynd):
            #print lemma,lemma_id,tegund,flokkur,ordmynd,beyging
            continue

        #we can't use the BÍN lemma id as a reference since it is missing or invalid in some cases
        bin_lemma = bin_lemma_id or lemma
        if bin_lemma != current_lemma:
            current_lemma = bin_lemma
            lemma_id += 1

        if filter:
            #handle BÍN bugs

            #if wordform is '--', replace it with the lemma (which I gather is the intention)
            if ordmynd in ('--','-'): ordmynd = lemma

            #discard wordforms which don't begin with an alphanumeric
            if not ALPHA_STRICT_RE.match(ordmynd): continue

            #if wordform starts with 'xxx' (for some reason), just strip it off
            if ordmynd.startswith('xxx'):
                ordmynd = ordmynd[3:]

            #discard wordforms of unusual length
            if len(ordmynd)==1 and len(lemma)>2: continue

            #if lemma starts with consonant, wordform should start with consonant
            if lemma[0] not in VOWELS and ordmynd[0] in VOWELS: continue

        yield BINEntry(lemma,lemma_id,flokkur,hluti,ordmynd,greining)

        i += 1
        if not silent and i % 1000 == 0:
            print '\rBIN: ' + str(i).ljust(10),
            stdout.flush()

    if not silent: print '\rBIN: ' + str(i).ljust(10)

def read_bin_grouped(**kwargs):
    """
    Returns an iterator of lines in the BÍN corpus, grouped by lemma. That is,
    it yields tuples of BINEntry objects.

    Any keyword arguments will be passed straight through to the underlying
    read_bin function.
    """
    last_id = -1
    group = []
    for entry in read_bin(**kwargs):
        if entry.lemma_id != last_id and group:
            if filter:
                first_entry = group[0]
                #handle strange bug in BIN, where certain compound words are incorrectly specified
                if first_entry.flokkur=='hk' and first_entry.hluti=='alm':
                    proper = [e for e in group if e.ordmynd[0]==e.ordmynd[0]
                              and not (len(e.lemma) > 3 and len(e.ordmynd)<=len(e.lemma)-2)]
                    if len(group) - len(proper) == 4:
                        #print first_entry.lemma_id, first_entry.lemma
                        group = proper
            yield tuple(group)
            group = []
        last_id = entry.lemma_id
        group.append(entry)
    yield tuple(group)

def read_otb(silent=False):
    """
    Returns an iterator over the entries in the OTB word frequency data file
    included in the distribution. The iterator splits the lines in the file and
    yields (word, tag, count) tuples for each word/tag pair.

    Set silent=True if you don't want the generator to print progress status
    while iterating.

    """
    datafile = open(os.path.join(BASE_PATH,'data',OTB_FILENAME), 'r')
    i = 0

    if not silent: print 'OTB:',
    for line in datafile:
        try:
            data = line.decode('utf-8').strip().split()
        except:
            continue
        if not data or len(data) < 2: continue

        word = data[0].lower().strip()
        if not word: continue

        for count,tag in list(izip(*[iter(data[1:])]* 2)):
            yield word, tag, int(count)

        i += 1
        if not silent and i % 1000 == 0:
            print '\rOTB: ' + str(i).ljust(10),
            stdout.flush()

    if not silent: print '\rOTB: ' + str(i).ljust(10)

def read_otb_tagmap(silent=False):
    """
    Returns an iterator over the entries in the OTB word=>tags data file
    included in the distribution (otb.dict). The iterator yields a
    (word, set([tags])) tuple for each line in the file.

    Set silent=True if you don't want the generator to print progress status
    while iterating.

    """
    datafile = open(os.path.join(BASE_PATH,'data',OTB_TAGMAP_FILENAME), 'r')
    i = 0

    if not silent: print 'OTB: 0\r',
    for line in datafile:
        try:
            data = line.decode('utf-8').strip().split('=')
        except:
            continue
        if not data or len(data) != 2: continue

        word = data[0].lower().strip()
        if not word: continue

        tags = set([t for t in data[1].split('_') if t])

        yield word, tags

        i += 1
        if not silent and i % 1000 == 0:
            print 'OTB:', str(i).ljust(10), '\r',
            stdout.flush()

    if not silent: print 'OTB: ' + str(i).ljust(10)

def read_morphemes():
    """
    Returns an iterator over the entries in the morphemes list included in the
    distribution. Yields (lemma, word, tag) tuples.

    """
    map = yaml.load(open(os.path.join(BASE_PATH,'data/morphemes.yml'),'r'))

    for lemma,value in map.iteritems():
        if isinstance(value, (str,unicode)):
            yield lemma, lemma, value #in this case, value:=tag
            continue

        for item in value:
            word,tag = item.split(' ')
            yield lemma, word, tag

def read_morphemes_grouped():
    """
    Returns an iterator over the entries in the morphemes list included in the
    distribution. Yields (lemma, entries) tuples, where *entries* is a list of
    (word, tag) tuples.

    """
    map = yaml.load(open(os.path.join(BASE_PATH,'data/morphemes.yml'),'r'))

    for lemma,value in map.iteritems():
        if isinstance(value, (str,unicode)):
            yield lemma, [(lemma, value)] #in this case, value:=tag
            continue

        yield lemma, [tuple(item.split(' ')) for item in value]
