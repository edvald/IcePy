#-*- coding: utf-8 -*-

"""
This module contains the IcePy morphological analysis functionality, including
an in-memory representation of the BÍN dictionary.

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

import os
import re
import traceback
import sys
from collections import defaultdict
import logging

from icepy.ext.bloom import BloomFilter
from icepy.ext.collections_backport import OrderedDict

from _config import BASE_PATH
from _tools import ExpansionMatch
from _tools import ExpansionPart
import corpustools
from misc import Timing, icepy_decode, icepy_encode, translate_tag
from constants import BLACKTAGS
from constants import CATEGORY_MAP
from constants import COMBO_VOWELS
from constants import VOWELS

try:
    import cPickle as pickle
except ImportError:
    import pickle

PICKLE_PROTOCOL = 2
SUPPORTED_WORD_CLASSES = set(['a','s','l','n'])

ALPHA_RE = re.compile(r'[\w-]', re.U)

class Morph(object):
    def __init__(self, path_prefix=None):
        """
        Initialise a Morph class. When first executed/deployed the initialiser
        will construct several maps from raw data, which is included in the
        distribution. The process will take several minutes, but once it has
        been done once, the class will load the generated maps from cache files
        which it outputs after processing the raw data.

        By default the data is stored in the data/ subfolder of the distribution
        but you may specify a path_prefix to have the class look for data files
        elsewhere.

        Also note that, while the in-memory maps are quite efficient, they still
        consume a noticable amount of RAM (approx 150-200MB) so using more than
        one Morph instance in a single application is to be avoided.

        """
        logging.debug("Starting the IcePy morphological analyser...")

        #data maps
        self.prefix_map  = defaultdict(list)
        self.tag_count   = defaultdict(int)
        self.id_lemma    = {}
        self.id_suffixes = {}
        self.bloom       = None

        #statistics / counters
        self.timing      = Timing()
        self.nofix_count = 0
        self.lookup_count = 0
        self.expand_count = 0
        self.bloom_negatives = 0
        self.lookup_negatives = 0

        self.stem_minimum_length = 0 #setting this to anything higher than 0 breaks the get_wordforms functionality
        
        if not path_prefix:
            path_prefix = os.path.join(BASE_PATH,"data/")

        self.maps = [
            ('prefixmap.cache', self.prefix_map),
            ('lemmamap.cache' , self.id_lemma),
            ('suffixes.cache' , self.id_suffixes),
            ('tagcount.cache' , self.tag_count),
            ('bloom.cache'    , 'bloom')
        ]
        for x, item in enumerate(self.maps):
            self.maps[x] = (path_prefix+item[0],item[1])

        #static maps
        sys.stdout.flush()
        self.expansion_tag_patterns = {}
        self.static_maps = [
            ('expansion_tag_patterns', self.expansion_tag_patterns)
        ]
        self._load_static(path_prefix)

        #if all cache files are available, try to load
        use_cache = True
        for filename in (v[0] for v in self.maps):
            if not os.path.exists(filename):
                use_cache = False
                break

        if use_cache:
            logging.debug("-> loading from cache")

            try:
                self._load_cache()
            except KeyboardInterrupt:
                raise
            except:
                logging.warning("-> loading from cache failed!")
                traceback.print_exc()
            else:
                return

        #else load raw data from BIN file and write new cache
        logging.warning("IcePy Morph: Performing initial processing of BIN corpus (this will take several minutes but \
                        only needs to be done once)")
        self._process_raw()
        self._write_cache()
        logging.debug("-> completed building Morph dictionary")

    def _process_raw(self):
        suffix_tmp = {}

        #load OTB
        otb = {}
        adverbs = []
        for word, tag, count in corpustools.read_otb():
            otb[word] = count
            #pluck out any adverbs
            if tag[0]=='a': adverbs.append((word,tag,count))

        #load BIN
        lemma_id = 0
        for entries in corpustools.read_bin_grouped(filter=True):
            count = 0
            category = CATEGORY_MAP[entries[0].flokkur]
            lemma = None

            coded_entries = []
            for entry in entries:
                count   += otb.get(entry.ordmynd, 0)

                #encode/preprocess entries
                tag   = icepy_encode(
                            translate_tag(category,entry.flokkur,entry.hluti,entry.greining)
                        )
                #add proper noun marker to tag
                if tag[0]=='n' and entry.lemma[0].isupper() and '-' not in tag:
                    if tag[-1]=='g':
                        tag += 's'
                    else:
                        tag += '-s'

                if not lemma: lemma = icepy_encode(entry.lemma.lower())
                word  = icepy_encode(entry.ordmynd.lower())
                
                self.tag_count[tag] += 1
                coded_entries.append((word,tag))

            lemma_id += 1

            self.id_lemma[lemma_id] = (lemma, category, count)
            self._prefix_fill(lemma_id,coded_entries,suffix_tmp)

        #inject morphemes
        for lemma,entries in corpustools.read_morphemes_grouped():
            count = 0 #currently no count info available for morphemes
            category = 'm'
            lemma = icepy_encode(lemma)
            entries = [icepy_encode(e) for e in entries]

            for word,tag in entries:
                self.tag_count[tag] += 1

            lemma_id += 1
            self.id_lemma[lemma_id] = (lemma, category, count)
            self._prefix_fill(lemma_id,entries,suffix_tmp)

        #inject adverb tags from OTB
        for word,tag,count in adverbs:
            tag = icepy_encode(tag)
            frozenmap = (('', (tag,)),)
            self.tag_count[tag] += 1    
            if frozenmap in suffix_tmp:
                suffix_id = suffix_tmp[frozenmap]
            else:
                suffix_id = len(suffix_tmp)
                suffix_tmp[frozenmap] = suffix_id

        #reverse suffix and tag maps
        for suffixes,suffix_id in suffix_tmp.iteritems():
            self.id_suffixes[suffix_id] = dict(suffixes)

        #inject adverbs from OTB, if they are not already in the maps
        for word,tag,count in adverbs:
            if not self._lookup_candidates(word,tag=tag):
                word = icepy_encode(word)
                lemma_id += 1
                self.id_lemma[lemma_id] = (word, 'a', count)

                frozenmap = (('', (icepy_encode(tag),)),)
                suffix_id = suffix_tmp[frozenmap]

                self.prefix_map[word].append( (lemma_id, suffix_id, 1) )

        #generate bloom filter
        self._generate_bloom()


    def _prefix_fill(self, lemma_id, entries, suffix_tmp):
        if len(entries) == 0: return
        first_word = entries[0]

        prefix = first_word[0]

        okay = False
        while len(prefix) >= self.stem_minimum_length and not okay:
            okay = True
            if len(prefix)==0:
                break
            for wordform in entries:
                if not wordform[0].startswith(prefix):
                    okay = False
                    break
            if not okay: prefix = prefix[:-1]

        if okay:
            suffixes = [e[0][len(prefix):] for e in entries]
            tags = [tag for word,tag in entries]

            formcount = len(tags)
            suffixmap = OrderedDict.fromkeys( sorted(list(set(suffixes))) )

            for key in suffixmap.iterkeys():
                suffixmap[key] = []

            for suffix,tag in zip(suffixes,tags):
                suffixmap[suffix].append(tag)

            for key,val in suffixmap.iteritems():
                suffixmap[key] = tuple(val)

            frozenmap = tuple(suffixmap.items())
            if frozenmap in suffix_tmp:
                suffix_id = suffix_tmp[frozenmap]
            else:
                suffix_id = len(suffix_tmp)
                suffix_tmp[frozenmap] = suffix_id

            self.prefix_map[prefix].append( (lemma_id, suffix_id, formcount) )
            return prefix

        else:
            for word,tag in set(entries):
                frozenmap = (('', (tag,)),)
                if frozenmap in suffix_tmp:
                    suffix_id = suffix_tmp[frozenmap]
                else:
                    suffix_id = len(suffix_tmp)
                    suffix_tmp[frozenmap] = suffix_id

                self.prefix_map[word].append( (lemma_id, suffix_id, 1) )

    def _count_wordforms(self):
        return sum((p[2] for prefix in self.prefix_map.itervalues() for p in prefix))

    def _delete_cache(self):
        for filename,obj in self.maps:
            try: os.remove(filename)
            except: pass

    def _write_cache(self):
        self._delete_cache()
        for filename,obj in self.maps:
            outfile = open(filename, 'wb')
            if isinstance(obj, str):
                obj = eval('self.'+obj)
            pickle.dump(obj, outfile, PICKLE_PROTOCOL)
            outfile.close()

    def _load_cache(self):
        sys.stdout.flush()
        for filename,obj in self.maps:
            outfile = open(filename,'rb')
            if isinstance(obj, dict):
                cache = pickle.load(outfile)
                obj.update(cache)
            elif isinstance(obj, str):
                exec 'self.%s = pickle.load(outfile)' % obj
            else:
                obj = pickle.load(outfile)
            outfile.close()
            print '.',
            sys.stdout.flush()

    def _load_static(self, path_prefix):
        for filename,obj in self.static_maps:
            infile = open(path_prefix+filename+'.static','rb')
            cache = pickle.load(infile)
            obj.update(cache)
            infile.close()

    def _generate_bloom(self):
        print "-> preparing bloom filter"

        #initialize bloom filter
        filter_m = self._count_wordforms() * 10 #using 10 bits per wordform
        filter_k = 4
        self.bloom = BloomFilter(filter_m,filter_k)

        #load wordforms into filter
        for word,tag in self.iterate_words(show_status=True, decode=False):
            self.bloom.Insert(word)

    def print_stats(self):
        """ Prints a few statistics about the data in the class along with some
        usage data for the instance.
        """
        stats = {
            'prefixes in maps':     len(self.prefix_map),
            'distinct suffix sets': len(self.id_suffixes),
            'lemmas in maps':       len(self.id_lemma),
            'bloom negatives':      self.bloom_negatives,
            'lookup negatives':     self.lookup_negatives,
            'expansions performed': self.expand_count,
            'lookups performed':    self.lookup_count,
            'total wordforms in maps': self._count_wordforms()
        }
        for id, stat in sorted(stats.items()):
            print "%s\t%s" % (id.ljust(30), stat)

    def iterate_words(self, show_status=False, decode=True):
        """ Returns an iterator over all the word forms in the maps.

        Set show_status=True to have the generator print a progress counter.

        By default the output is a decoded unicode string. Set decode=False if
        you need the IcePy encoded string.
        """
        i = 0
        total = self._count_wordforms()
        for prefix,idlist in self.prefix_map.iteritems():
            for lemma_id, suffix_id, wordform_count in idlist:
                for suffix,tags in self.id_suffixes[suffix_id].iteritems():
                    for tag in tags:
                        i += 1
                        if show_status and i%1000==0:
                            print '%d / %d\r' % (i, total),
                            sys.stdout.flush()
                        if decode:
                            yield icepy_decode(prefix+suffix), icepy_decode(tag)
                        else:
                            yield prefix+suffix, tag

        if show_status: print '%d / %d' % (i, total)

    def iterate_words_grouped(self, show_status=False, decode=True):
        """ Returns an iterator over all the word forms in the maps, grouped by
        lemma. That is, yields a list for every lexeme in the maps.

        Accepts the same options as iterate_words().
        """
        #TODO: refactor this and iterate_words to use more of the same code
        i = 0
        total = len(self.id_lemma)
        for prefix,idlist in self.prefix_map.iteritems():
            for lemma_id, suffix_id, wordform_count in idlist:
                group = []
                for suffix,tags in self.id_suffixes[suffix_id].iteritems():
                    for tag in tags:
                        if decode:
                            try:
                                group.append((icepy_decode(prefix+suffix),icepy_decode(tag)))
                            except KeyError:
                                print "Could not decode word/tag %s/%s!" % (repr(prefix+suffix),repr(tag))
                                raise
                        else:
                            group.append((prefix+suffix,tag))
                i += 1
                if show_status:
                    print '%d / %d\r' % (i, total),
                    sys.stdout.flush()
                yield group

        if show_status: print '%d / %d' % (i, total)

    def _check_input(self, string, category=None, tag=None):
        if tag: category = tag[0]
        return category not in BLACKTAGS and ALPHA_RE.match(string)

    def _lookup_candidates(self, wordform, category=None, tag=None):
        self.lookup_count += 1

        #encode input strings
        try:
            wordform = icepy_encode(wordform.lower())
            if tag:
                tag = icepy_encode(tag.lower())
                category = tag[0]
        except ValueError:
            #print "warning: could not encode word/tag %s/%s" % (repr(wordform),repr(tag))
            return []

        #first check if wordform is in the bloom filter. this is primarily used
        #to increase performance in expansions, as they frequently include a
        #large number of lookups of non-existent words. this may return a
        #false positive but then the prefix lookup will simply return an empty set.
        self.timing.start('bloom_lookup')
        in_bloom = True
        if self.bloom and not self.bloom.InFilter(wordform):
            in_bloom = False
            self.bloom_negatives += 1
        self.timing.end('bloom_lookup')

        if not in_bloom: return []

        #look for prefix in prefix map.
        self.timing.start('prefix_lookup')
        prefix = wordform
        candidates = []
        while True:
            if prefix in self.prefix_map:
                #search for the word in the selected prefixes suffix map
                word_suffix = wordform[len(prefix):]

                self.timing.start('lookup_prefix_loop')
                for candidate_id,candidate_suffix_id,wordform_count in self.prefix_map[prefix]:
                    suffixmap = self.id_suffixes[candidate_suffix_id]

                    tags = suffixmap.get(word_suffix, None)
                    if not tags: continue

                    lemma, lemma_category, otb_count = self.id_lemma[candidate_id]

                    if lemma_category=='m' and tag and tag[0]!='m':
                        if tag not in [t[3:] for t in tags]: continue
                        tags = [tags[0][:3] + tag]
                    elif tag:
                        if tag not in tags: continue
                        tags = [tag]
                    elif category and lemma_category not in (category,'m'):
                        continue

                    candidates.extend([
                        AnalysisMatch(prefix, word_suffix, candidate_id, lemma,
                        otb_count, candidate_suffix_id, candidate_tag, 'lookup')
                        for candidate_tag in tags
                    ])
                self.timing.end('lookup_prefix_loop')
                        
            if not prefix or len(prefix) < self.stem_minimum_length: break
            prefix = prefix[:-1]

        if not candidates:
            self.lookup_negatives += 1

        self.timing.end('prefix_lookup')
        return candidates

    def lookup(self, wordform, category=None, tag=None):
        """ Performs a lookup of the specified word form and returns a list of
        AnalysisMatch objects.

        Specify category as a string of length 1 to filter by word category. For
        example, set category='n' to filter by nouns.

        Specify tag as a string to filter by specific POS tag, as defined in the
        tagset specification used for IceNLP. Note that the tags returned by the
        IceNLP tagger may not always match 100% with those derived from the BÍN
        analysis markup, due to some differences in approach between the two
        projects.
        """
        if not self._check_input(wordform,category,tag): return WordformAnalysis([])

        candidates = self._lookup_candidates(wordform, category, tag)

        #don't return bound morphemes in direct lookup
        candidates = [c for c in candidates if not c.match_tag.startswith(('mb','md'))]
        
        #add tag count information to results
        for c in candidates:
            c.tag_count = self.tag_count.get(c.match_tag)

        return WordformAnalysis(candidates)

    def inflection_analysis(self, input):
        """ Generate a InflectionAnalysis object, given an AnalysisMatch object
        or a list/tuple of words.

        The InflectionAnalysis object contains a breakdown of how the given word
        is declined. It includes a stem, a list of stem-variables
        and corresponding lists of tags and inflectional suffixes.
        """
        wordforms = []
        tags = []
        if isinstance(input, AnalysisMatch):
            for suffix,tagset in self.id_suffixes[input.suffix_id].iteritems():
                for tag in tagset:
                    wordforms.append(input.prefix+suffix)
                    tags.append(tag)
        elif isinstance(input, (list,tuple)):
            for word in input:
                if isinstance(word, str):
                    wordforms.append(word)
                elif isinstance(word, unicode):
                    wordforms.append(icepy_encode(word))
                else:
                    raise ValueError('input list/tuple must only contain strings')
            tags = ['' for w in wordforms]
        else:
            raise ValueError('input object must be AnalysisMatch instance or list/tuple of wordforms')

        wordforms.sort(key=lambda x: len(x))

        base = wordforms[0]
        pattern = r''
        
        variables = []
        for i in range(len(wordforms)): variables.append([])

        running_vars   = [None for i in range(len(wordforms))]
        suffixes       = [None for i in range(len(wordforms))]
        last_constant  = -1
        for x,char in enumerate(base):
            #determine if character at offset X is a constant (that is, appears
            #predictably in all wordforms)
            range_start = last_constant + 1
            range_end   = x + 1
            is_constant = True

            for w,word in enumerate(wordforms[1:]):
                index = word[range_start:range_end].find(char)
                #print word, char, range_end, range_start, index
                if index < 0:
                    is_constant = False

            if not is_constant:
                for w,word in enumerate(wordforms[1:]):
                    if running_vars[w+1] is None:
                        running_vars[w+1] = word[x]
                    else:
                        running_vars[w+1] += word[x]
            else:
                for w,word in enumerate(wordforms[1:]):
                    index = word[range_start:range_end].find(char)
                    suffixes[w+1] = word[range_start+index+1:]

            if is_constant:
                if x > range_start:
                    var_set = set()
                    for i,v in enumerate(running_vars):
                        variables[i].append(v)
                        if v is not None: var_set.add(v)
                    vars = r'|'.join( sorted(var_set,key=lambda x: len(x),reverse=True) )
                    pattern += r'(%s)' % vars
                pattern += char
                last_constant = x
                running_vars = [None for i in range(len(wordforms))]
            else:
                if running_vars[0] is None:
                    running_vars[0] = char
                else:
                    running_vars[0] += char

        suffixes[0] = base[last_constant+1:]

        return InflectionAnalysis(pattern, suffixes, variables, tags, wordforms)

    def analyse(self, wordform, category=None, tag=None, force_expand=False):
        """
        Uses the available methods (currently lookup() and expand()) to
        analyse the given word form. category and tag can be specified in the
        same manner as in lookup() to narrow the results. The output is a
        WordformAnalysis object.

        By default the function will stop and return the results if a direct
        lookup yields one or more matches, and will only attempt an expanded
        lookup if nothing is found by direct lookup. You can specify
        force_expand=True to override this.

        Note that the AnalysisMatch object's *type* attribute indicates which
        type of lookup returned the match.
        """
        if not self._check_input(wordform,category,tag): return WordformAnalysis([])

        results = []

        wordform = wordform.lower()
        if wordform.endswith(('-',"'")): wordform = wordform[:-1]

        #first do a direct lookup
        results.extend(self._lookup_candidates(wordform, category, tag))

        #if no results are found or force_expand is set, try expanded lookup
        if not results or force_expand:
            expansion = self.expand(wordform, category, tag)
            #not including direct lookups (single part in expansion)
            results.extend([e for e in expansion.matches if len(e.parts)>1])

        return WordformAnalysis(results)

    def expand(self, wordform, category=None, tag=None, single_part=True,
                     allow_morphemes=True):
        """
        Splits the input wordform into segments and returns a list of
        AnalysisMatch objects. Each AnalysisMatch object contains a *parts*
        attribute, which is a list of matches for each of the segments. Refer to
        the AnalysisMatch object documentation for information about it's
        properties.

        category and tag can be specified to filter in the same manner as in
        lookup().

        If you specify single_part=False the function will not return or attempt
        to lookup the entire word form.

        By default, non-standalone morphemes (category 'm') are included in
        expansions if found. You may specify allow_morphemes=False to disable
        these, to only get independent word segments.
        """
        self.expand_count += 1

        if not self._check_input(wordform,category,tag): return WordformAnalysis([])

        #special case for nouns, a compound word segment should not be a proper noun
        if tag: tag = tag.split('-')[0]

        wordform = wordform.replace('-','')

        instances   = defaultdict(list)

        word_len = len(wordform)
        done = False
        self.timing.start('expand_loop')
        for sublen in range(word_len,1,-1):
            index = -1
            while index+sublen < word_len:
                index += 1
                word = wordform[index:index+sublen]

                if not single_part and sublen==word_len: continue
                if index+sublen==word_len-1: continue

                #make sure last segment matches the specified filter
                if index+sublen==word_len:
                    lookup = self._lookup_candidates(word, category, tag)
                else:
                    lookup = self._lookup_candidates(word, None, None)

                for match in lookup:
                    if not allow_morphemes and match.match_tag[0]=='m': continue
                    instances[index].append(ExpansionPart(index,word,match))

            if done: break
        self.timing.end('expand_loop')

        #for index,parts in instances.iteritems():
        #    print index, ''.join([str(p)+' ' for p in parts])
        if not instances: return WordformAnalysis([])
        
        """find all valid matches"""
        matches = []
        #loop through the "roots" (i.e. instances with index 0)
        if 0 not in instances: return WordformAnalysis([])
        self.timing.start('match_traverse')
        for root in instances[0]:
            if root.index > 0: break

            candidate = [root]
            #special case of entire word being found on first index
            if root.end == word_len:
                matches.append(ExpansionMatch(candidate))

            #recursively traverse the "tree" of parts to find all sets which add up
            #to the full length of the word
            _traverse_parts(instances, matches, root.end, word_len, candidate, [0])
        self.timing.end('match_traverse')

        if not matches: return WordformAnalysis([])

        #filter matches and set attributes for AnalysisMatch objects
        results = []
        for match in matches:
            if not len(match): continue
            if not single_part and len(match.parts) < 2: continue

            last_tag = match[-1].analysis.match_tag
            if len(match)==1 and last_tag[0]=='m': continue
            
            #a compound word should not end with a proper noun. at least that's
            #not a supported case for now.
            if last_tag[0]=='n' and len(last_tag)>2 and last_tag[-2]=='-': continue

            result_tag = last_tag if last_tag[0]!='m' else last_tag[3:]

            prefix = ''.join([m.analysis.word for m in match[:-1]])
            lemma  = prefix + match[-1].analysis.lemma
            prefix = prefix + match[-1].analysis.prefix
            suffix = icepy_encode(wordform[len(prefix):])

            result = AnalysisMatch(prefix, suffix, 0, lemma, match[-1].analysis.otb_count,
                               match[-1].analysis.suffix_id, result_tag,
                               'expanded_lookup', match.parts)

            result.tag_count = self.tag_count.get(result_tag,0)
            result.tag_pattern_count = self.expansion_tag_patterns.get(result.tags(),0)

            results.append(result)

        return WordformAnalysis(results)

    def wordforms(self, match):
        """ Return list of all wordforms for an AnalysisMatch object's lexeme.
        """
        if not isinstance(match, AnalysisMatch):
            raise ValueError('input object must be AnalysisMatch instance')

        return [icepy_decode(match.prefix+suffix) for suffix in self.id_suffixes[match.suffix_id]]

    def inflections(self, match):
        """ Return list of all inflections for an AnalysisMatch object's lexeme.
        """
        if not isinstance(match, AnalysisMatch):
            raise ValueError('input object must be AnalysisMatch instance')

        results = []
        for suffix,tags in self.id_suffixes[match.suffix_id].iteritems():
            for tag in tags:
                results.append((icepy_decode(match.prefix+suffix),icepy_decode(tag)))
        return results

    def lemmatise(self, wordform, category=None, tag=None, return_original=True):
        """ Return a tuple (lemma,tag) with the lemma of the input wordform,
        along with the assumed tag.

        Basically this function does the same as analyse() but attempts to
        select one best match and return the lemma string for that.

        By default the input is returned back (in a tuple) if nothing is found.
        If return_original=False is set, None is return instead.

        """
        if self._check_input(wordform,category,tag):
            #first try to lookup the whole word directly
            candidates = self.lookup(wordform,category,tag)
            if candidates:
                #TODO: (vastly) improve selection process
                m = candidates.top_pick()
                return icepy_decode((m.lemma,m.match_tag))

            #else try expanding the word
            candidates = self.expand(wordform,category)
            if candidates:
                #TODO: (vastly) improve selection process
                #prefer matches with fewer parts
                m = candidates.top_pick()
                return icepy_decode((m.lemma,m.match_tag))

        #else return original or none
        if return_original: return (wordform,tag or category or None)
        return None

    def group_lexemes(self, chunks):
        """ Accepts a list of lists of (word,tag) tuples (chunks) and groups the
        chunks together by lexeme. Returns a mapping of
        (lemmatised words) => [tuples]

        Works by lemmatising each of the words and grouping together those chunks
        which have all the same lemmas for each of their words. A bit crude, but
        works reasonably well in many cases.

        """
        map = defaultdict(list)
        for chunk in chunks:
            analysed = [self.analyse(word, tag=tag) for word,tag in chunk]
            lemmas = []
            
            for a in analysed:
                match = a.top_pick()
                if not match:
                    lemmas = []
                    break

                if match.lemma_id:
                    lemmas.append(match.lemma_id)
                else:
                    lemmas.append(match.lemma)

            if lemmas:
                lemma_tuple = tuple(lemmas)
            else:
                lemma_tuple = tuple([word for word,tag in chunk])

            map[lemma_tuple].append(chunk)

        return dict(map)

    def group_lexemes_count(self, chunks):

        map = defaultdict(list)
        for chunk in chunks:
            analysed = [self.analyse(word, category=tag[0]) for word,tag in chunk]

            lemmas = []
            for a in analysed:
                match = a.top_pick()
                if not match:
                    lemmas = []
                    break

                lemmas.append(match.lemma)

            if lemmas:
                lemma_strings = tuple(lemmas)
            else:
                lemma_strings = tuple([word for word,tag in chunk])

            lemma_list = []
            for i in range(len(chunk)):
                lemma_list.append((lemma_strings[i],chunk[i][1][-1]))

            lemma_tuple = tuple(lemma_list)
            map[lemma_tuple].append(chunk)

        return dict(map)

    def unambiguous_expansions(self, category=None, tag=None, silent=False):
        """ Runs through all of the word forms in the database, expands them
        and gathers those that return only one expansion candidate.

        This is useful for making training data and gathering statistics, but be
        warned: It will take many hours to complete!

        Specify category or tag to filter the search (which should make the
        process considerably faster).

        By default the function prints every unambiguous expansion it finds but
        you may set silent=True to avoid this.

        """
        print """Computing all unambiguous word expansions in BÍN.
        Warning: This will take many hours!"""
        
        expansions = []
        #iterate all wordforms
        for words in self.iterate_words_grouped(True):
            for wordform,wordtag in words:
                if tag and tag!=wordtag: continue
                elif category and category!=wordtag[0]: continue
                #expand the wordform
                expansion = self.expand(wordform,tag=wordtag,single_part=False)
                #add to expansion list if it has only one expansion
                if len(expansion)==1:
                    expansions.append(expansion.matches[0])
                    if not silent: print expansion.matches[0]

        if not silent: print "Done!"
        return expansions

class InflectionAnalysis(object):
    __slots__ = ('stem','morphs','suffixes','tags','wordforms','stem_regex')

    def __init__(self, stem, suffixes, morphs, tags, wordforms):
        """ This class is constructed by the Morph.inflection_analyse()
        function. It contains a few attributes and methods useful for examining
        the inflections of a lexeme:

        stem - The stem of the lexeme as determined by examining which parts of
        the word are constant throughout all inflections. A stem may contain
        'variables' which usually correspond to vowel transformations. For
        example, the verb 'drjúpa' has the stem *dr(au|jú|o|y)p*, the noun
        'banki' has *b(a|ö)nk* and 'hús' simply has *hús*.

        *suffixes* - A list of suffixes following the stem, for all the word
        forms.

        *morphs* - A list, corresponding to suffixes, which specifies which (if
        any) variables should be substituted in the variable parts of the stem.

        *tags* - Another list, corresponding to the other ones, containing the
        tag of each word form.

        *wordforms* - Lists all the word forms, in the same sequence as the
        other lists.
        """
        self.stem      = icepy_decode(stem)
        self.suffixes  = icepy_decode(suffixes)
        self.morphs    = icepy_decode(morphs)
        self.tags      = icepy_decode(tags)
        self.wordforms = icepy_decode(wordforms)

    def suffix_split(self):
        """ Returns a mapping of the form result[tag]=(prefix,suffix), where
        each wordform in the object has been split so the inflectional morpheme
        is separate.

        This is not the same as making the map directly from the
        *tags* and *suffixes* list, as those suffixes may in some cases include
        more than the inflectional morpheme, or may be missing a part of it.
        """
        result = {}

        #check if stem ends with vowel. split on that, if it does.
        fragment = None
        if self.stem[-2:] in COMBO_VOWELS:
            fragment = self.stem[-2:]
        elif self.stem[-1] in VOWELS:
            fragment = self.stem[-1]

        if fragment:
            for wordform,suffix,tag in zip(self.wordforms,self.suffixes,self.tags):
                suffix = fragment+suffix
                result[tag] = (wordform[:-len(suffix)],suffix)
        else:
            for wordform,suffix,tag in zip(self.wordforms,self.suffixes,self.tags):
                if not suffix:
                    result[tag] = (wordform,suffix)
                    continue
                #vowel_match = VOWELS_RE.search(suffix)
                #index = vowel_match.start(0) if vowel_match else 0
                #suffix = suffix[index:]
                result[tag] = (wordform[:-len(suffix)],suffix)

        return result

    def stem_regex(self):
        """ Returns the root stem as a compiled regular expression object.
        Useful for matching against a word or list of words.
        """
        return re.compile(self.stem, re.U)

class WordformAnalysis(object):
    __slots__ = ('matches')

    def __init__(self, matches=None):
        """ Constructed by analysis functions. Carries a list of AnalysisMatch
        objects in the attribute *matches* and provides a few convenience
        functions.
        """
        self.matches = matches or []

    def __len__(self):
        return len(self.matches)

    def __bool__(self):
        return True if len(self.matches) else False

    def tags(self):
        """ Return a set of all the tags in the list of *matches*.
        """
        alltags = (icepy_decode(m.match_tag) for m in self.matches)
        return set(alltags)

    def by_tag(self, tag):
        d = dict((icepy_decode(m.match_tag),m) for m in self.matches)
        return d.get(tag, None)
    
    def probability_sorted(self):
        """ Returns the objects' matches sorted by frequency information.
        Useful for picking the most probable results.
        """
        return sorted(self.matches, 
                      key=lambda m:(m.tag_pattern_count,m.tag_count), 
                      reverse=True)

    def top_pick(self):
        """ Returns the most probable result according to frequency information.
        Shorthand for WordformAnalysis.probability_sorted()[0].
        """
        ps = self.probability_sorted()
        if ps: return ps[0]

    def prettyprint(self):
        """ Prints an list of all the matches contained in the analysis.
        """
        for e in self.matches:
            decoded = e._decode()
            print "\t", decoded
            for p in e.parts:
                print "\t\t", p

    def __repr__(self):
        return "<WordformAnalysis:\n" + '\n'.join([repr(m) for m in self.matches]) + "\n>"

class AnalysisMatch(object):
    __slots__ = ('prefix','suffix','lemma_id','lemma','otb_count','suffix_id',
                 'match_tag','type','parts','tag_count','tag_pattern_count')

    def __init__(self, prefix, suffix, lemma_id, lemma, otb_count, suffix_id, match_tag, type, parts=None):
        """ This class is constructed by the lookup functions of the Morph
        class. It contains several properties which describe a result of a
        lookup.


        *prefix*    - The prefix of the word, as indexed in Morph.prefix_map

        *suffix*    - The corresponding suffix, to the above prefix

        *lemma_id*  - An identifier number, as indexed in Morph.id_lemma

        *lemma*     - The lemma of the word form

        *suffix_id* - The identifier number, as indexed in Morph.id_suffix

        *type*      - The type of lookup which returned the match

        *otb_count* - The word frequency count of the lexeme

        *tag_count* - The frequency of the matches tag in BÍN

        *tag_pattern_count* - If applicable, the frequency of the pattern of
        tags, based on the detected word parts. The reference count is currently
        derived from data generated by unambiguous_expansions().

        *otb_count* - The word frequency count of the lexeme

        *parts*     - If the match was returned by expand() this property
        contains a list of AnalysisMatch objects for each segment of the
        word.

        """
        self.prefix    = prefix
        self.suffix    = suffix
        self.lemma_id  = lemma_id
        self.lemma     = lemma
        self.otb_count = otb_count
        self.suffix_id = suffix_id
        self.match_tag = match_tag
        self.type      = type
        self.parts     = parts or []

        self.tag_count = 0
        self.tag_pattern_count = 0

    @property
    def category(self):
        """ Returns the category of the match. Quite simple, as the category is
        always the first character of the tag.
        """
        return self.match_tag[0]

    @property
    def word(self):
        """ Returns the word form described by the match. Shorthand for
        match.prefix+match.suffix
        """
        return self.prefix+self.suffix

    def decoded_word(self):
        """ Returns the word form described by the match in unicode format.
        """
        return icepy_decode(self.word)

    def decoded_tag(self):
        """ Returns the word form described by the match in unicode format.
        """
        return icepy_decode(self.match_tag)

    def decoded_lemma(self):
        return icepy_decode(self.lemma)

    def split_indices(self):
        """ Returns a list of the indices where the word if segmented. Returns
        an empty list if there are no parts.
        """
        return [part.index for part in self.parts]

    def tags(self):
        """ Returns a list of the tags for each segment of the word. Returns an
        empty list if there are no parts/segments in the match.
        """
        return tuple([part.analysis.match_tag for part in self.parts])

    def __repr__(self):
        return "<AnalysisMatch: %s, %d parts>" % (
            repr((
                self.match_tag,self.prefix,self.suffix,self.lemma_id,self.lemma,
                self.suffix_id,self.type,
                self.otb_count,self.tag_count,self.tag_pattern_count)
            ),
            len(self.parts)
            )

    def _decode(self):
        a = AnalysisMatch(icepy_decode(self.prefix),icepy_decode(self.suffix),
                             self.lemma_id,icepy_decode(self.lemma),self.otb_count,
                             self.suffix_id,
                             icepy_decode(self.match_tag),self.type,
                             self.parts)
        a.tag_count = self.tag_count
        a.tag_pattern_count = self.tag_count
        return a

    def _encode(self, encoding):
        a = AnalysisMatch(icepy_decode(self.prefix).encode(encoding),
                             icepy_decode(self.suffix).encode(encoding),
                             self.lemma_id,icepy_decode(self.lemma).encode(encoding),
                             self.otb_count, self.suffix_id,
                             icepy_decode(self.match_tag).encode(encoding),
                             self.type, self.parts)
        a.tag_count = self.tag_count
        a.tag_pattern_count = self.tag_count
        return a

def _traverse_parts(instances, matches, index, word_len, candidate, branches):
    if branches[0] >= 1000: return
    for node in instances[index]:
        c = candidate+[node]
        if node.end == word_len:
            matches.append(ExpansionMatch(c))
            continue
        branches[0] += 1
        _traverse_parts(instances, matches, index+node.wlen, word_len, c, branches)


def main():
    m = Morph()

    """
    expansions = m.unambiguous_expansions(category='l')
    fout = open('expansions','w')
    pickle.dump(expansions, fout, PICKLE_PROTOCOL)
    fout.close()
    
    import time
    d = {}
    for word,tag in m.iterate_words(True,decode=False):
        d[word] = (257,114125)

    time.sleep(5)

    print
    m.timing.prettyprint()

    """
    print
    m.print_stats()

    raw_input('trall!')

if __name__=="__main__":
    main()

