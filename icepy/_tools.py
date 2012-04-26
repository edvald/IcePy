#-*- coding: utf-8 -*-

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

from math import sqrt

from random import randint
import re

PICKLE_PROTOCOL = 2
ALPHA_STRICT_RE = re.compile(r'\w', re.U)

def stdev(values):
    n = len(values)
    mean       = sum(values) / float(n)
    deviations = [i-mean for i in values]
    sum_square = sum((i*i for i in deviations))
    variance   = sum_square / float(n-1)
    return sqrt(variance)

def dict_random(d):
    if not len(d): return None
    index = randint(0,len(d)-1)
    i = -1
    item = None
    for s in d.itervalues():
        i += 1
        if i < index: continue
        item = s
        break
    return item

class ExpansionMatch(list):
    __slots__ = ('lemma','category')

    def __init__(self, parts=None, lemma=None, category=None):
        list.__init__(self)
        if parts: self.extend(parts)
        if lemma: self.lemma = lemma
        if category: self.category = category

    def __str__(self):
        return ''.join((str(s)+' ' for s in self))

    @property
    def parts(self):
        return [p for p in self]

class ExpansionPart(object):
    __slots__ = ('index','lemma','analysis','wlen')

    def __init__(self, index, lemma, analysis):
        self.index = index
        self.lemma = lemma
        self.analysis = analysis
        self.wlen  = len(analysis.word)

    @property
    def end(self):
        return self.index + self.wlen

    def __unicode__(self):
        return u"(%s,%s,%s)" % (self.index, self.lemma, self.analysis)

    def __str__(self):
        return  self.__unicode__().encode('utf8')

    def __repr__(self):
        return "<ExpansionPart: %s>" % repr((self.index,self.lemma,self.analysis.word))

    def __cmp__(self, other):
        if self.index <  other.index: return -1
        if self.index == other.index: return 0
        return 1
