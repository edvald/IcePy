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

import time

from corpustools import read_otb_tagmap
from morph import SUPPORTED_WORD_CLASSES
from morph import Morph

if __name__=="__main__":
    from optparse import OptionParser
    parser = OptionParser()
    parser.add_option('-v', '--verbose', dest='verbose', action='store_true', help='prints the result of each tested word form')
    parser.add_option('-s', '--surplus', dest='surplus', action='store_true', help='regard surplus tags in analysis as failure')
    parser.add_option('-i', '--ignore_unsupported', dest='ignore_unsupported', action='store_true',
                        help='ignore any word classes not specifically supported by Morph')
    parser.add_option('-f', '--failures', dest='failures', action='store_true', help='prints the result of every failed test')
    parser.add_option('-c', '--wordclass', dest='wordclass', default='', help="limit tests to specific word class ('n' for noun, 's' for verb etc.)")
    parser.add_option('-l', '--loose', dest='loose', action="store_true", help="allow a more 'loose' comparison, omitting certain parts of tags")
    options, args = parser.parse_args()

    m = Morph()

    total = 0.0
    total_full = 0.0
    total_tags = 0.0
    total_tags_full = 0
    tags_missed = 0
    missing = 0
    all_missing = 0
    no_candidates = 0
    surplus = 0
    wrong_pick = 0
    tags_ignored = 0
    words_ignored = 0

    start_time = time.time()

    word_classes = set([options.wordclass]) if options.wordclass else SUPPORTED_WORD_CLASSES

    for word,tags in read_otb_tagmap():
        total_full += 1
        total_tags_full += len(tags)

        if options.ignore_unsupported or options.wordclass:
            new_tags = set([t for t in tags if t[0] in word_classes])
            if len(new_tags)==0:
                words_ignored += 1
                tags_ignored += len(tags)
                continue
            tags_ignored += len(tags)-len(new_tags)
            tags = new_tags

        total += 1
        total_tags += len(tags)
        failed = False

        candidates = m.analyse(word)
        result_tags = candidates.tags()

        #TODO: instead of doing this, making a comparison function would be cleaner
        if options.loose:
            new_tags = set()
            for tag in tags:
                if tag[0]=='n' and tag[-1] in (u'm',u'ö',u'o'):
                    tag = tag[:-1] + 's'
                new_tags.add(tag)
            tags = new_tags
            
            new_tags = set()
            for tag in result_tags:
                if tag[0]=='n' and tag[-1] in (u'm',u'ö',u'o'):
                    tag = tag[:-1] + 's'
                new_tags.add(tag)
            result_tags = new_tags

        if len(tags-result_tags)==len(tags):
            all_missing += 1
            tags_missed += len(tags)
            failed = True
        elif len(tags-result_tags):
            missing += 1
            tags_missed += len(tags-result_tags)
            failed = True

        if len(result_tags-tags):
            surplus += 1
            if options.surplus: failed = True
        if not result_tags:
            no_candidates += 1
            failed = True

        if options.verbose or (options.failures and failed):
            print word,
            print '[%s]' % ','.join([t.encode('utf8') for t in tags]),
            print '[%s]' % ','.join([t.encode('utf8') for t in candidates.tags()])

        top_pick = candidates.top_pick()
        if top_pick and top_pick.match_tag not in tags:
            wrong_pick += 1

    total_time = time.time() - start_time

    print """

        Word forms analysed: %d
        Words ignored: %d / %.2f%%
        Missing tags: %d / %.2f%%
        Missing all tags: %d / %.2f%%
        No candidates: %d / %.2f%%
        Surplus tags: %d / %.2f%%
        Top pick not in target tags: %d / %.2f%%
        ---
        Total tags: %d
        Tags missed: %d / %.2f%%
        Tags ignored: %d
        ---
        Total time: %.2f secs
        Avg time: %.8f secs

    """ % (
        total,
        words_ignored, words_ignored/total_full*100,
        missing, missing/total*100,
        all_missing, all_missing/total*100,
        no_candidates, no_candidates/total*100,
        surplus, surplus/total*100,
        wrong_pick, wrong_pick/total*100,

        total_tags_full,
        tags_missed, tags_missed/total_tags*100,
        tags_ignored,

        total_time,
        total_time / total
    )
