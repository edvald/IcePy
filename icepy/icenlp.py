# -*- coding: utf-8 -*-
"""
This module contains a wrapper for IceNLP, along with a few helper functions for
processing the output from IceNLP.

The wrapper is not implemented as a class because it has to be implemented in a
singleton pattern to account for the lack of thread-safety in JCC.
Thread-safety is emulated using locks, so only one thread at a time can call
the Java based functions. Note that the wrapper is lazy-loaded, so it is started
the first time you call a tagger function. You may also manually initialize the
wrapper using init_icenlp() is you prefer.

For this module to work from CPython you need a working installation of JCC.
Please refer to the IcePy homepage for installation instructions.

If you are running Jython all you need to do is make sure your IceNLP
distribution is on your classpath. You can initialize the script with
    jython2.5 -Dpython.path=.:ext/IceNLPCore.jar icenlp.py
or add the path to IceNLP to your environment CLASSPATH. A jython-run.sh script
is also in the distribution which does the same as the above, so you can run
    ./jython-run.sh {any_module}.py

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

from itertools import izip
from threading import Lock
import logging

from lib.pyparsing import Word, alphas, alphas8bit, OneOrMore, Suppress, Forward, Combine, Group, nums

try:
    import java
except:
    java = None
    try:
        import icenlp_python
    except:
        icenlp_python = None
        msg = "Could not load Jython or icenlp_python wrapper to interface with IceNLP!"
        raise ImportError(msg)

_sentences = None
_tagger_instance = None
_parser_instance = None
_tokenizer = None
_segmentizer = None
_env = None
_lock = Lock()
def init_icenlp():
    global _sentences, _tagger_instance, _parser_instance, _tokenizer
    global _segmentizer, _env

    if java:
        logging.debug("Initializing IceNLP... -> using Jython")
        #TODO: implement full set of functions
        #a bit of a hack, due to the reserved keyword 'is'
        #within the IceNLP package tree
        _temp = __import__('is.iclt', globals(), locals(), ['icenlp'], -1)
        _icenlp = _temp.icenlp

        tokLexicon   = _icenlp.core.utils.Lexicon(
                            _icenlp.core.tokenizer.TokenizerResources().isLexicon
                        )
        iceLexicons  = _icenlp.core.icetagger.IceTaggerLexicons(
                            _icenlp.core.icetagger.IceTaggerResources()
                        )
        _tagger_instance       = _icenlp.facade.IceTaggerFacade(iceLexicons, tokLexicon)

        #TODO: allow selecting specific HMM mode when running in Jython
        _tagger_instance.useTriTagger(False)

        sentencesClass = _icenlp.core.tokenizer.Sentences
        _sentences = sentencesClass()

        _env = True

    elif icenlp_python:
        logging.debug("Initializing IceNLP... -> using JCC wrapper")
        try:
            _env = icenlp_python.initVM(maxheap='512M')
        except ValueError:
            _env = icenlp_python.initVM()

        _tagger_instance = icenlp_python.IceTaggerFacade(icenlp_python.IceTagger.HmmModelType.none)
        _parser_instance = icenlp_python.IceParserFacade()

        tokenizer_lexicon = icenlp_python.TokenizerResources().isLexicon
        _segmentizer = icenlp_python.Segmentizer(tokenizer_lexicon)
        _tokenizer   = icenlp_python.Tokenizer(icenlp_python.Tokenizer.typeToken, True, tokenizer_lexicon)

def _tagger():
    return _tagger_instance

def _parser():
    return _parser_instance

def _get_tokenizer():
    return _tokenizer

def _get_segmentizer():
    return _segmentizer

def _acquire_lock():
    _lock.acquire()
    if _env is None: init_icenlp()
    if _env!=True: _env.attachCurrentThread()

def _release_lock():
    _lock.release()

def tag(text):
    """ Passes text to the IceNLP tagger. Returns a list of sentences, each
    tagged and tokenized in the standard IceNLP format.
    """
    _acquire_lock()

    tagged = _tagger().tag(text)
    tagged_sentences = []
    for s in tagged.getSentences():
        if s is None: continue
        tagged_sentences.append(s.toString())

    _release_lock()

    return tagged_sentences

def split_sentences(text):
    _acquire_lock()
    segmentizer = _get_segmentizer()
    segmentizer.segmentize(text)
    output = []
    while segmentizer.hasMoreSentences():
        output.append(segmentizer.getNextSentence())
    _release_lock()
    return output

def tokenize(sentences):
    output = []
    for sent in sentences:
        _acquire_lock()
        tokenizer = _get_tokenizer()
        tokenized = []

        if sent!='':
            tokenizer.tokenize(sent)
            if tokenizer.tokens.size() >= 0:
                tokenizer.splitAbbreviations()
                tokenized = [t.toString() for t in tokenizer.tokens]
        _release_lock()

        output.append(tokenized)
    return output

def tag_and_iterate(text):
    """ Passes text to the IceNLP tagger. Returns an iterator of
    (space,word,tag) tuples, where *word* is the original word or symbol, *tag*
    is the tag returned by the tagger and *space* is the leading whitespace
    before the word.

    This is useful for maintaining the structure of the input text. The original
    input can be reconstructed with
    _''.join([space+word for space,word,tag,sentence_no in output])_.

    A usage example can by found in the Hyphenator.hyphenate() function.
    """
    tagged = tag(text)
    return iter_combined(text,tagged)

def tag_with_whitespace(text):
    """ Passes text to the IceNLP tagger and returns the article with tags, but
    maintaining the original structure, i.e. the whitespace, which is normally
    lost during tokenization.
    """
    return ''.join([u'%s%s %s'%t[:3] for t in tag_and_iterate(text)])

class ParseTreeParser(object):
    def __init__(self):
        self._parser = self.parser()

    def parser(self):
        lowers = ''.join(set(alphas.lower()+alphas8bit.lower()))
        puns = u',.!?\u201e\u201c\u2013-()<>:="\xa0/;_\xb4\u2018*@\u201d\xad\xa7\'\\'

        token = Group(
            Word(alphas+alphas8bit+puns+nums) + Word(lowers+puns+nums)
        ).setResultsName("token")

        chunk_type = Word(alphas+'_<>')        
        parts = Forward()

        chunk = Group(
            Group(Combine(Suppress("[") + chunk_type)).setResultsName("chunk_type") + \
            parts + \
            Suppress(Combine(chunk_type + Suppress("]")))
        ).setResultsName("chunk")

        part = Group(
            Group(Combine(Suppress("{*") + chunk_type)).setResultsName("part_type") + \
            parts + \
            Suppress(Combine(Suppress("*") + chunk_type + Suppress("}")))
        ).setResultsName("part")

        parts << OneOrMore(token | part | chunk)

        return parts.parseString

    def parse(self, v):
        return self._parser(v)

def _process_chunk(part, index, parent=None):
    item = {'tokens':[], 'children':[], 'type':part[0][0], 'parent':parent, 'index':index}
    for child in part[1:]:
        n = child.getName()
        if n=='token':
            item['tokens'].append(child[:2])
            #item['children'].append({'tokens':[child], 'children':[], 'type':'PUN'})
        elif n in ('chunk','part'):
            sub = _process_chunk(child, index+len(item['tokens']), item)
            item['tokens'].extend(sub['tokens'])
            item['children'].append(sub)
    return item

PARSER = ParseTreeParser()
def parse_sentence(tagged_sentence, include_func=True):
    """ Parse a tagged sentence using IceNLP and return a dict with the results
    """
    _acquire_lock()
    nlp_parsed = _parser().parse(tagged_sentence, include_func, True)
    _release_lock()

    # Example IceNLP parser output (for reference):
    # [NPs [NP Konan nveng \xfe\xedn feven NP] , , [NP ma\xf0urinn nkeng \xfeinn feken NP] [CP og c CP] [NP \xfalpan nveng m\xedn feven NP] NPs]

    output = {'tokens':[], 'children':[], 'type':'SENT', 'parent':None, 'index':0}
    for part in nlp_parsed.splitlines():
        if part.startswith(('[','{')):
            #we have a bare chunk
            parsed = PARSER.parse(part)
            item = _process_chunk(parsed[0], len(output['tokens']), output)
            output['tokens'].extend(item['tokens'])
            output['children'].append(item)
        else:
            #deals with punctuation parts
            output['tokens'].append(part.split())
    return output, nlp_parsed

def use_tritagger(v):
    """ Use this to select whether the IceNLP tagger should use the statistical
    TriTagger as well as the state-machine. By default this is set to False.
    """
    _acquire_lock()
    _tagger().useTriTagger(v)
    _release_lock()


### UTILITY FUNCTIONS ###

def sentence_tuples(tagged_sentence):
    """ Given a tagged sentence, return a list of (word,tag) tuples.
    """
    return list(izip(*[iter(tagged_sentence.split(" "))]* 2))

def iter_sentence_tuples(tagged_sentence):
    """ Given a tagged sentence, returns an iterator of (word,tag) tuples.
    """
    return izip(*[iter(tagged_sentence.split(" "))]* 2)

def pos_to_simple(postag):
    """ Returns the category of the given POS tag, which is quite simply the
    first character of the tag.
    """
    return postag[0].lower()

def iter_combined(text, tagged):
    """ Given an article and the corresponding list of tagged sentences (i.e.
    tagger output), returns an iterator of (space,word,tag,sentence_no) tuples. See the
    above tag_and_iterate() function for usage.
    """
    offset = 0
    for x,(word,tag) in ((s,word_tag) for s,sentence in enumerate(tagged) for word_tag in iter_sentence_tuples(sentence)):
        index = text.find(word, offset)
        space = text[offset:index]
        offset = index+len(word)
        yield (space,word,tag,x)


def main():
    """ insert simple test code """
    article = u"""
    &bdquo;FLUGELDASÖLUNNI er ekki lokið því þrettándinn er ennþá eftir,&ldquo; segir Ólöf Snæhólm Baldursdóttir, upplýsingafulltrúi Slysavarnarfélagsins Landsbjargar innt eftir því hvernig flugeldasalan fyrir áramótin gekk hjá björgunarsveitunum. &bdquo;En salan gekk nokkuð vel fyrir áramótin og það er mjög gott hljóð í fólkinu á sölustöðunum.&ldquo;
Hún segir björgunarsveitirnar fjárhagslega sjálfstæðar einingar og því sé ekki vitað hvenær endanlegar sölutölur liggi fyrir. &bdquo;Ég hef heyrt að salan hafi gengið betur en í fyrra, og að aukningin nemi kannski um 10 prósentum. Það er í rauninni framar okkar vonum.&ldquo;
Hún segist ekki vita hvort salan hafi verið svona góð vegna þess að almennt hafi verið keypt meira af flugeldum nú en í fyrra eða vegna þess að fólk hafi frekar beint viðskiptum sínum til hjálparsveitanna fremur en annarra. &bdquo;Við finnum þó vel fyrir því að fólk vill styðja björgunarsveitirnar.&ldquo;
Ekki liggja sölutölur fyrir hjá þeim íþróttafélögum sem haft var samband við. Kristinn R. Jónsson framkvæmdastjóri Fram segir þó að heldur hafi selst minna af flugeldum í ár en áður. Jónas Kristinsson, framkvæmdastjóri KR, segir söluna hafa gengið þokkalega og hún hafi verið svipuð og á síðasta ári. &bdquo;Við erum bara ánægðir með að fólk skuli skila sér til íþróttafélaganna líka því sumir fá meira pláss en aðrir í þessari umfjöllun.&ldquo;
    """
    article = article.replace('&bdquo;',u'\u201E').replace('&ldquo;',u'\u201C')
    tagged = tag(article)
    for sentence in tagged:
        print sentence

    for i in range(10000):
        tagged = tag(article+' %d'%i)

    raw_input('bla')

if __name__=="__main__":
    main()