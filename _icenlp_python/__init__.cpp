#include <jni.h>
#include <Python.h>
#include "JCCEnv.h"
#include "functions.h"

PyObject *initVM(PyObject *module, PyObject *args, PyObject *kwds);

namespace is {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
}
namespace java {
    void __install__(PyObject *module);
    void __initialize__(PyObject *module);
}

void __install__(PyObject *module)
{
    is::__install__(module);
    java::__install__(module);
}

PyObject *__initialize__(PyObject *module, PyObject *args, PyObject *kwds)
{
    PyObject *env = initVM(module, args, kwds);

    if (env == NULL)
        return NULL;

    try {
        is::__initialize__(module);
        java::__initialize__(module);
        return env;
    } catch (int e) {
        switch(e) {
          case _EXC_JAVA:
            return PyErr_SetJavaError();
          default:
            throw;
        }
    }
}


namespace is {

    namespace iclt {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
    }

    void __install__(PyObject *module)
    {
        iclt::__install__(module);
    }

    void __initialize__(PyObject *module)
    {
        iclt::__initialize__(module);
    }
}


namespace is {
    namespace iclt {

        namespace icenlp {
            void __install__(PyObject *module);
            void __initialize__(PyObject *module);
        }

        void __install__(PyObject *module)
        {
            icenlp::__install__(module);
        }

        void __initialize__(PyObject *module)
        {
            icenlp::__initialize__(module);
        }
    }
}


namespace is {
    namespace iclt {
        namespace icenlp {

            namespace core {
                void __install__(PyObject *module);
                void __initialize__(PyObject *module);
            }
            namespace facade {
                void __install__(PyObject *module);
                void __initialize__(PyObject *module);
            }
            namespace runner {
                void __install__(PyObject *module);
                void __initialize__(PyObject *module);
            }

            void __install__(PyObject *module)
            {
                core::__install__(module);
                facade::__install__(module);
                runner::__install__(module);
            }

            void __initialize__(PyObject *module)
            {
                core::__initialize__(module);
                facade::__initialize__(module);
                runner::__initialize__(module);
            }
        }
    }
}


namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {

                namespace formald {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }
                namespace iceNER {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }
                namespace icemorphy {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }
                namespace iceparser {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }
                namespace icetagger {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }
                namespace lemmald {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }
                namespace tokenizer {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }
                namespace tritagger {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }
                namespace utils {
                    void __install__(PyObject *module);
                    void __initialize__(PyObject *module);
                }

                void __install__(PyObject *module)
                {
                    formald::__install__(module);
                    iceNER::__install__(module);
                    icemorphy::__install__(module);
                    iceparser::__install__(module);
                    icetagger::__install__(module);
                    lemmald::__install__(module);
                    tokenizer::__install__(module);
                    tritagger::__install__(module);
                    utils::__install__(module);
                }

                void __initialize__(PyObject *module)
                {
                    formald::__initialize__(module);
                    iceNER::__initialize__(module);
                    icemorphy::__initialize__(module);
                    iceparser::__initialize__(module);
                    icetagger::__initialize__(module);
                    lemmald::__initialize__(module);
                    tokenizer::__initialize__(module);
                    tritagger::__initialize__(module);
                    utils::__initialize__(module);
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/formald/Format.h"
#include "is/iclt/icenlp/core/formald/FormatConverter.h"
#include "is/iclt/icenlp/core/formald/Text.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {

                    namespace tags {
                        void __install__(PyObject *module);
                        void __initialize__(PyObject *module);
                    }
                    namespace tagsets {
                        void __install__(PyObject *module);
                        void __initialize__(PyObject *module);
                    }

                    void __install__(PyObject *module)
                    {
                        t_Format::install(module);
                        t_FormatConverter::install(module);
                        t_Text::install(module);
                        tags::__install__(module);
                        tagsets::__install__(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_Format::initialize(module);
                        t_FormatConverter::initialize(module);
                        t_Text::initialize(module);
                        tags::__initialize__(module);
                        tagsets::__initialize__(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/formald/tags/Ice1TagFormat.h"
#include "is/iclt/icenlp/core/formald/tags/Ice2TagFormat.h"
#include "is/iclt/icenlp/core/formald/tags/TagFormat.h"
#include "is/iclt/icenlp/core/formald/tags/TagFormatConverter.h"
#include "is/iclt/icenlp/core/formald/tags/TaggedSentence.h"
#include "is/iclt/icenlp/core/formald/tags/TaggedText.h"
#include "is/iclt/icenlp/core/formald/tags/TaggedToken.h"
#include "is/iclt/icenlp/core/formald/tags/XMLTagFormat.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {


                        void __install__(PyObject *module)
                        {
                            t_Ice1TagFormat::install(module);
                            t_Ice2TagFormat::install(module);
                            t_TagFormat::install(module);
                            t_TagFormatConverter::install(module);
                            t_TaggedSentence::install(module);
                            t_TaggedText::install(module);
                            t_TaggedToken::install(module);
                            t_XMLTagFormat::install(module);
                        }

                        void __initialize__(PyObject *module)
                        {
                            t_Ice1TagFormat::initialize(module);
                            t_Ice2TagFormat::initialize(module);
                            t_TagFormat::initialize(module);
                            t_TagFormatConverter::initialize(module);
                            t_TaggedSentence::initialize(module);
                            t_TaggedText::initialize(module);
                            t_TaggedToken::initialize(module);
                            t_XMLTagFormat::initialize(module);
                        }
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/formald/tagsets/CustomTagset.h"
#include "is/iclt/icenlp/core/formald/tagsets/IfdEnglish.h"
#include "is/iclt/icenlp/core/formald/tagsets/Tagset.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tagsets {


                        void __install__(PyObject *module)
                        {
                            t_CustomTagset::install(module);
                            t_IfdEnglish::install(module);
                            t_Tagset::install(module);
                        }

                        void __initialize__(PyObject *module)
                        {
                            t_CustomTagset::initialize(module);
                            t_IfdEnglish::initialize(module);
                            t_Tagset::initialize(module);
                        }
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/iceNER/NameScanner.h"
#include "is/iclt/icenlp/core/iceNER/NameSearcher.h"
#include "is/iclt/icenlp/core/iceNER/NameSearcher$Role.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace iceNER {


                    void __install__(PyObject *module)
                    {
                        t_NameScanner::install(module);
                        t_NameSearcher::install(module);
                        t_NameSearcher$Role::install(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_NameScanner::initialize(module);
                        t_NameSearcher::initialize(module);
                        t_NameSearcher$Role::initialize(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/icemorphy/IceMorphy.h"
#include "is/iclt/icenlp/core/icemorphy/IceMorphy$MorphoClass.h"
#include "is/iclt/icenlp/core/icemorphy/IceMorphyLexicons.h"
#include "is/iclt/icenlp/core/icemorphy/MorphoRule.h"
#include "is/iclt/icenlp/core/icemorphy/MorphoRuleNounAdjective.h"
#include "is/iclt/icenlp/core/icemorphy/MorphoRuleVerb.h"
#include "is/iclt/icenlp/core/icemorphy/MorphoRuleVerb$Mood.h"
#include "is/iclt/icenlp/core/icemorphy/MorphoRuleVerb$Voice.h"
#include "is/iclt/icenlp/core/icemorphy/MorphoRuleVerbFinite.h"
#include "is/iclt/icenlp/core/icemorphy/MorphoRuleVerbPastParticiple.h"
#include "is/iclt/icenlp/core/icemorphy/MorphoRules.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icemorphy {


                    void __install__(PyObject *module)
                    {
                        t_IceMorphy::install(module);
                        t_IceMorphy$MorphoClass::install(module);
                        t_IceMorphyLexicons::install(module);
                        t_MorphoRule::install(module);
                        t_MorphoRuleNounAdjective::install(module);
                        t_MorphoRuleVerb::install(module);
                        t_MorphoRuleVerb$Mood::install(module);
                        t_MorphoRuleVerb$Voice::install(module);
                        t_MorphoRuleVerbFinite::install(module);
                        t_MorphoRuleVerbPastParticiple::install(module);
                        t_MorphoRules::install(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_IceMorphy::initialize(module);
                        t_IceMorphy$MorphoClass::initialize(module);
                        t_IceMorphyLexicons::initialize(module);
                        t_MorphoRule::initialize(module);
                        t_MorphoRuleNounAdjective::initialize(module);
                        t_MorphoRuleVerb::initialize(module);
                        t_MorphoRuleVerb$Mood::initialize(module);
                        t_MorphoRuleVerb$Voice::initialize(module);
                        t_MorphoRuleVerbFinite::initialize(module);
                        t_MorphoRuleVerbPastParticiple::initialize(module);
                        t_MorphoRules::initialize(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/iceparser/Case_AP.h"
#include "is/iclt/icenlp/core/iceparser/Case_NP.h"
#include "is/iclt/icenlp/core/iceparser/Clean1.h"
#include "is/iclt/icenlp/core/iceparser/Clean2.h"
#include "is/iclt/icenlp/core/iceparser/Func_COMP.h"
#include "is/iclt/icenlp/core/iceparser/Func_OBJ.h"
#include "is/iclt/icenlp/core/iceparser/Func_OBJ2.h"
#include "is/iclt/icenlp/core/iceparser/Func_OBJ3.h"
#include "is/iclt/icenlp/core/iceparser/Func_QUAL.h"
#include "is/iclt/icenlp/core/iceparser/Func_SUBJ.h"
#include "is/iclt/icenlp/core/iceparser/Func_SUBJ2.h"
#include "is/iclt/icenlp/core/iceparser/Func_TIMEX.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_AP.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_APs.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_AdvP.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_MWE.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_MWEP1.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_MWEP2.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_NP.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_NPs.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_PP.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_Per_Line.h"
#include "is/iclt/icenlp/core/iceparser/Phrase_VP.h"
#include "is/iclt/icenlp/core/iceparser/Preprocess.h"
#include "is/iclt/icenlp/core/iceparser/StringSearch.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace iceparser {


                    void __install__(PyObject *module)
                    {
                        t_Case_AP::install(module);
                        t_Case_NP::install(module);
                        t_Clean1::install(module);
                        t_Clean2::install(module);
                        t_Func_COMP::install(module);
                        t_Func_OBJ::install(module);
                        t_Func_OBJ2::install(module);
                        t_Func_OBJ3::install(module);
                        t_Func_QUAL::install(module);
                        t_Func_SUBJ::install(module);
                        t_Func_SUBJ2::install(module);
                        t_Func_TIMEX::install(module);
                        t_Phrase_AP::install(module);
                        t_Phrase_APs::install(module);
                        t_Phrase_AdvP::install(module);
                        t_Phrase_MWE::install(module);
                        t_Phrase_MWEP1::install(module);
                        t_Phrase_MWEP2::install(module);
                        t_Phrase_NP::install(module);
                        t_Phrase_NPs::install(module);
                        t_Phrase_PP::install(module);
                        t_Phrase_Per_Line::install(module);
                        t_Phrase_VP::install(module);
                        t_Preprocess::install(module);
                        t_StringSearch::install(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_Case_AP::initialize(module);
                        t_Case_NP::initialize(module);
                        t_Clean1::initialize(module);
                        t_Clean2::initialize(module);
                        t_Func_COMP::initialize(module);
                        t_Func_OBJ::initialize(module);
                        t_Func_OBJ2::initialize(module);
                        t_Func_OBJ3::initialize(module);
                        t_Func_QUAL::initialize(module);
                        t_Func_SUBJ::initialize(module);
                        t_Func_SUBJ2::initialize(module);
                        t_Func_TIMEX::initialize(module);
                        t_Phrase_AP::initialize(module);
                        t_Phrase_APs::initialize(module);
                        t_Phrase_AdvP::initialize(module);
                        t_Phrase_MWE::initialize(module);
                        t_Phrase_MWEP1::initialize(module);
                        t_Phrase_MWEP2::initialize(module);
                        t_Phrase_NP::initialize(module);
                        t_Phrase_NPs::initialize(module);
                        t_Phrase_PP::initialize(module);
                        t_Phrase_Per_Line::initialize(module);
                        t_Phrase_VP::initialize(module);
                        t_Preprocess::initialize(module);
                        t_StringSearch::initialize(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/icetagger/IceDisambiguator.h"
#include "is/iclt/icenlp/core/icetagger/IceFrequency.h"
#include "is/iclt/icenlp/core/icetagger/IceHeuristics.h"
#include "is/iclt/icenlp/core/icetagger/IceLocalRules.h"
#include "is/iclt/icenlp/core/icetagger/IceTagger.h"
#include "is/iclt/icenlp/core/icetagger/IceTagger$HmmModelType.h"
#include "is/iclt/icenlp/core/icetagger/IceTaggerLexicons.h"
#include "is/iclt/icenlp/core/icetagger/IceTaggerOutput.h"
#include "is/iclt/icenlp/core/icetagger/IceTaggerOutputApertium.h"
#include "is/iclt/icenlp/core/icetagger/IceTaggerResources.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {


                    void __install__(PyObject *module)
                    {
                        t_IceDisambiguator::install(module);
                        t_IceFrequency::install(module);
                        t_IceHeuristics::install(module);
                        t_IceLocalRules::install(module);
                        t_IceTagger::install(module);
                        t_IceTagger$HmmModelType::install(module);
                        t_IceTaggerLexicons::install(module);
                        t_IceTaggerOutput::install(module);
                        t_IceTaggerOutputApertium::install(module);
                        t_IceTaggerResources::install(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_IceDisambiguator::initialize(module);
                        t_IceFrequency::initialize(module);
                        t_IceHeuristics::initialize(module);
                        t_IceLocalRules::initialize(module);
                        t_IceTagger::initialize(module);
                        t_IceTagger$HmmModelType::initialize(module);
                        t_IceTaggerLexicons::initialize(module);
                        t_IceTaggerOutput::initialize(module);
                        t_IceTaggerOutputApertium::initialize(module);
                        t_IceTaggerResources::initialize(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/lemmald/LemmaResult.h"
#include "is/iclt/icenlp/core/lemmald/LemmaRule.h"
#include "is/iclt/icenlp/core/lemmald/LemmaWord.h"
#include "is/iclt/icenlp/core/lemmald/Lemmald.h"
#include "is/iclt/icenlp/core/lemmald/LemmaldSettings.h"
#include "is/iclt/icenlp/core/lemmald/LemmaldUtils.h"
#include "is/iclt/icenlp/core/lemmald/PostFixer.h"
#include "is/iclt/icenlp/core/lemmald/RuleDatabase.h"
#include "is/iclt/icenlp/core/lemmald/SuccessCounter.h"
#include "is/iclt/icenlp/core/lemmald/Tester.h"
#include "is/iclt/icenlp/core/lemmald/Trainer.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {


                    void __install__(PyObject *module)
                    {
                        t_LemmaResult::install(module);
                        t_LemmaRule::install(module);
                        t_LemmaWord::install(module);
                        t_Lemmald::install(module);
                        t_LemmaldSettings::install(module);
                        t_LemmaldUtils::install(module);
                        t_PostFixer::install(module);
                        t_RuleDatabase::install(module);
                        t_SuccessCounter::install(module);
                        t_Tester::install(module);
                        t_Trainer::install(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_LemmaResult::initialize(module);
                        t_LemmaRule::initialize(module);
                        t_LemmaWord::initialize(module);
                        t_Lemmald::initialize(module);
                        t_LemmaldSettings::initialize(module);
                        t_LemmaldUtils::initialize(module);
                        t_PostFixer::initialize(module);
                        t_RuleDatabase::initialize(module);
                        t_SuccessCounter::initialize(module);
                        t_Tester::initialize(module);
                        t_Trainer::initialize(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/tokenizer/HmmTokenTags.h"
#include "is/iclt/icenlp/core/tokenizer/IceTokenTags.h"
#include "is/iclt/icenlp/core/tokenizer/IceTokenTags$Condition.h"
#include "is/iclt/icenlp/core/tokenizer/IceTokenTags$Match.h"
#include "is/iclt/icenlp/core/tokenizer/IceTokenTags$SVOMark.h"
#include "is/iclt/icenlp/core/tokenizer/IceTokenTags$UnknownType.h"
#include "is/iclt/icenlp/core/tokenizer/Segmentizer.h"
#include "is/iclt/icenlp/core/tokenizer/Sentence.h"
#include "is/iclt/icenlp/core/tokenizer/Sentences.h"
#include "is/iclt/icenlp/core/tokenizer/SrxSegmentizer.h"
#include "is/iclt/icenlp/core/tokenizer/Token.h"
#include "is/iclt/icenlp/core/tokenizer/Token$MWECode.h"
#include "is/iclt/icenlp/core/tokenizer/Token$TokenCode.h"
#include "is/iclt/icenlp/core/tokenizer/TokenTags.h"
#include "is/iclt/icenlp/core/tokenizer/Tokenizer.h"
#include "is/iclt/icenlp/core/tokenizer/TokenizerResources.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {


                    void __install__(PyObject *module)
                    {
                        t_HmmTokenTags::install(module);
                        t_IceTokenTags::install(module);
                        t_IceTokenTags$Condition::install(module);
                        t_IceTokenTags$Match::install(module);
                        t_IceTokenTags$SVOMark::install(module);
                        t_IceTokenTags$UnknownType::install(module);
                        t_Segmentizer::install(module);
                        t_Sentence::install(module);
                        t_Sentences::install(module);
                        t_SrxSegmentizer::install(module);
                        t_Token::install(module);
                        t_Token$MWECode::install(module);
                        t_Token$TokenCode::install(module);
                        t_TokenTags::install(module);
                        t_Tokenizer::install(module);
                        t_TokenizerResources::install(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_HmmTokenTags::initialize(module);
                        t_IceTokenTags::initialize(module);
                        t_IceTokenTags$Condition::initialize(module);
                        t_IceTokenTags$Match::initialize(module);
                        t_IceTokenTags$SVOMark::initialize(module);
                        t_IceTokenTags$UnknownType::initialize(module);
                        t_Segmentizer::initialize(module);
                        t_Sentence::initialize(module);
                        t_Sentences::initialize(module);
                        t_SrxSegmentizer::initialize(module);
                        t_Token::initialize(module);
                        t_Token$MWECode::initialize(module);
                        t_Token$TokenCode::initialize(module);
                        t_TokenTags::initialize(module);
                        t_Tokenizer::initialize(module);
                        t_TokenizerResources::initialize(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/tritagger/FreqLexEntry.h"
#include "is/iclt/icenlp/core/tritagger/FreqLexicon.h"
#include "is/iclt/icenlp/core/tritagger/Ngrams.h"
#include "is/iclt/icenlp/core/tritagger/StateMap.h"
#include "is/iclt/icenlp/core/tritagger/TriTagger.h"
#include "is/iclt/icenlp/core/tritagger/TriTaggerLexicons.h"
#include "is/iclt/icenlp/core/tritagger/TriTaggerOutput.h"
#include "is/iclt/icenlp/core/tritagger/TriTaggerResources.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tritagger {


                    void __install__(PyObject *module)
                    {
                        t_FreqLexEntry::install(module);
                        t_FreqLexicon::install(module);
                        t_Ngrams::install(module);
                        t_StateMap::install(module);
                        t_TriTagger::install(module);
                        t_TriTaggerLexicons::install(module);
                        t_TriTaggerOutput::install(module);
                        t_TriTaggerResources::install(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_FreqLexEntry::initialize(module);
                        t_FreqLexicon::initialize(module);
                        t_Ngrams::initialize(module);
                        t_StateMap::initialize(module);
                        t_TriTagger::initialize(module);
                        t_TriTaggerLexicons::initialize(module);
                        t_TriTaggerOutput::initialize(module);
                        t_TriTaggerResources::initialize(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/core/utils/FileEncoding.h"
#include "is/iclt/icenlp/core/utils/FileLister.h"
#include "is/iclt/icenlp/core/utils/FileOperations.h"
#include "is/iclt/icenlp/core/utils/IceLog.h"
#include "is/iclt/icenlp/core/utils/IceTag.h"
#include "is/iclt/icenlp/core/utils/IceTag$WordClass.h"
#include "is/iclt/icenlp/core/utils/Idioms.h"
#include "is/iclt/icenlp/core/utils/Lexicon.h"
#include "is/iclt/icenlp/core/utils/PropertiesEncoding.h"
#include "is/iclt/icenlp/core/utils/Tag.h"
#include "is/iclt/icenlp/core/utils/Trie.h"
#include "is/iclt/icenlp/core/utils/TrieNode.h"
#include "is/iclt/icenlp/core/utils/WordList.h"
#include "is/iclt/icenlp/core/utils/XmlOperations.h"
#include "is/iclt/icenlp/core/utils/ZipGzipper.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {


                    void __install__(PyObject *module)
                    {
                        t_FileEncoding::install(module);
                        t_FileLister::install(module);
                        t_FileOperations::install(module);
                        t_IceLog::install(module);
                        t_IceTag::install(module);
                        t_IceTag$WordClass::install(module);
                        t_Idioms::install(module);
                        t_Lexicon::install(module);
                        t_PropertiesEncoding::install(module);
                        t_Tag::install(module);
                        t_Trie::install(module);
                        t_TrieNode::install(module);
                        t_WordList::install(module);
                        t_XmlOperations::install(module);
                        t_ZipGzipper::install(module);
                    }

                    void __initialize__(PyObject *module)
                    {
                        t_FileEncoding::initialize(module);
                        t_FileLister::initialize(module);
                        t_FileOperations::initialize(module);
                        t_IceLog::initialize(module);
                        t_IceTag::initialize(module);
                        t_IceTag$WordClass::initialize(module);
                        t_Idioms::initialize(module);
                        t_Lexicon::initialize(module);
                        t_PropertiesEncoding::initialize(module);
                        t_Tag::initialize(module);
                        t_Trie::initialize(module);
                        t_TrieNode::initialize(module);
                        t_WordList::initialize(module);
                        t_XmlOperations::initialize(module);
                        t_ZipGzipper::initialize(module);
                    }
                }
            }
        }
    }
}

#include "is/iclt/icenlp/facade/IceMorphyFacade.h"
#include "is/iclt/icenlp/facade/IceNLP.h"
#include "is/iclt/icenlp/facade/IceNLPTest.h"
#include "is/iclt/icenlp/facade/IceParserFacade.h"
#include "is/iclt/icenlp/facade/IceTaggerFacade.h"
#include "is/iclt/icenlp/facade/TokenizerFacade.h"
#include "is/iclt/icenlp/facade/TriTaggerFacade.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {


                void __install__(PyObject *module)
                {
                    t_IceMorphyFacade::install(module);
                    t_IceNLP::install(module);
                    t_IceNLPTest::install(module);
                    t_IceParserFacade::install(module);
                    t_IceTaggerFacade::install(module);
                    t_TokenizerFacade::install(module);
                    t_TriTaggerFacade::install(module);
                }

                void __initialize__(PyObject *module)
                {
                    t_IceMorphyFacade::initialize(module);
                    t_IceNLP::initialize(module);
                    t_IceNLPTest::initialize(module);
                    t_IceParserFacade::initialize(module);
                    t_IceTaggerFacade::initialize(module);
                    t_TokenizerFacade::initialize(module);
                    t_TriTaggerFacade::initialize(module);
                }
            }
        }
    }
}

#include "is/iclt/icenlp/runner/RunIceMorphy.h"
#include "is/iclt/icenlp/runner/RunIceParser.h"
#include "is/iclt/icenlp/runner/RunIceTagger.h"
#include "is/iclt/icenlp/runner/RunIceTaggerApertium.h"
#include "is/iclt/icenlp/runner/RunLemmald.h"
#include "is/iclt/icenlp/runner/RunNameFinder.h"
#include "is/iclt/icenlp/runner/RunTokenizer.h"
#include "is/iclt/icenlp/runner/RunTriTagger.h"
#include "is/iclt/icenlp/runner/RunTrie.h"
#include "is/iclt/icenlp/runner/TagAndParse.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace runner {


                void __install__(PyObject *module)
                {
                    t_RunIceMorphy::install(module);
                    t_RunIceParser::install(module);
                    t_RunIceTagger::install(module);
                    t_RunIceTaggerApertium::install(module);
                    t_RunLemmald::install(module);
                    t_RunNameFinder::install(module);
                    t_RunTokenizer::install(module);
                    t_RunTriTagger::install(module);
                    t_RunTrie::install(module);
                    t_TagAndParse::install(module);
                }

                void __initialize__(PyObject *module)
                {
                    t_RunIceMorphy::initialize(module);
                    t_RunIceParser::initialize(module);
                    t_RunIceTagger::initialize(module);
                    t_RunIceTaggerApertium::initialize(module);
                    t_RunLemmald::initialize(module);
                    t_RunNameFinder::initialize(module);
                    t_RunTokenizer::initialize(module);
                    t_RunTriTagger::initialize(module);
                    t_RunTrie::initialize(module);
                    t_TagAndParse::initialize(module);
                }
            }
        }
    }
}


namespace java {

    namespace io {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
    }
    namespace lang {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
    }
    namespace util {
        void __install__(PyObject *module);
        void __initialize__(PyObject *module);
    }

    void __install__(PyObject *module)
    {
        io::__install__(module);
        lang::__install__(module);
        util::__install__(module);
    }

    void __initialize__(PyObject *module)
    {
        io::__initialize__(module);
        lang::__initialize__(module);
        util::__initialize__(module);
    }
}

#include "java/io/BufferedReader.h"
#include "java/io/BufferedWriter.h"
#include "java/io/Closeable.h"
#include "java/io/File.h"
#include "java/io/FileFilter.h"
#include "java/io/FileNotFoundException.h"
#include "java/io/FilenameFilter.h"
#include "java/io/FilterOutputStream.h"
#include "java/io/Flushable.h"
#include "java/io/IOException.h"
#include "java/io/InputStream.h"
#include "java/io/OutputStream.h"
#include "java/io/PrintStream.h"
#include "java/io/PrintWriter.h"
#include "java/io/Reader.h"
#include "java/io/Serializable.h"
#include "java/io/StringWriter.h"
#include "java/io/UnsupportedEncodingException.h"
#include "java/io/Writer.h"

namespace java {
    namespace io {


        void __install__(PyObject *module)
        {
            t_BufferedReader::install(module);
            t_BufferedWriter::install(module);
            t_Closeable::install(module);
            t_File::install(module);
            t_FileFilter::install(module);
            t_FileNotFoundException::install(module);
            t_FilenameFilter::install(module);
            t_FilterOutputStream::install(module);
            t_Flushable::install(module);
            t_IOException::install(module);
            t_InputStream::install(module);
            t_OutputStream::install(module);
            t_PrintStream::install(module);
            t_PrintWriter::install(module);
            t_Reader::install(module);
            t_Serializable::install(module);
            t_StringWriter::install(module);
            t_UnsupportedEncodingException::install(module);
            t_Writer::install(module);
        }

        void __initialize__(PyObject *module)
        {
            t_BufferedReader::initialize(module);
            t_BufferedWriter::initialize(module);
            t_Closeable::initialize(module);
            t_File::initialize(module);
            t_FileFilter::initialize(module);
            t_FileNotFoundException::initialize(module);
            t_FilenameFilter::initialize(module);
            t_FilterOutputStream::initialize(module);
            t_Flushable::initialize(module);
            t_IOException::initialize(module);
            t_InputStream::initialize(module);
            t_OutputStream::initialize(module);
            t_PrintStream::initialize(module);
            t_PrintWriter::initialize(module);
            t_Reader::initialize(module);
            t_Serializable::initialize(module);
            t_StringWriter::initialize(module);
            t_UnsupportedEncodingException::initialize(module);
            t_Writer::initialize(module);
        }
    }
}

#include "java/lang/AbstractStringBuilder.h"
#include "java/lang/Appendable.h"
#include "java/lang/Boolean.h"
#include "java/lang/Byte.h"
#include "java/lang/CharSequence.h"
#include "java/lang/Character.h"
#include "java/lang/Class.h"
#include "java/lang/ClassLoader.h"
#include "java/lang/ClassNotFoundException.h"
#include "java/lang/Cloneable.h"
#include "java/lang/Comparable.h"
#include "java/lang/Double.h"
#include "java/lang/Enum.h"
#include "java/lang/Exception.h"
#include "java/lang/Float.h"
#include "java/lang/IllegalAccessException.h"
#include "java/lang/IllegalArgumentException.h"
#include "java/lang/InstantiationException.h"
#include "java/lang/Integer.h"
#include "java/lang/InterruptedException.h"
#include "java/lang/Iterable.h"
#include "java/lang/Long.h"
#include "java/lang/NullPointerException.h"
#include "java/lang/Number.h"
#include "java/lang/NumberFormatException.h"
#include "java/lang/Object.h"
#include "java/lang/Package.h"
#include "java/lang/Readable.h"
#include "java/lang/RuntimeException.h"
#include "java/lang/SecurityException.h"
#include "java/lang/Short.h"
#include "java/lang/StackTraceElement.h"
#include "java/lang/String.h"
#include "java/lang/StringBuffer.h"
#include "java/lang/StringBuilder.h"
#include "java/lang/Throwable.h"

namespace java {
    namespace lang {


        void __install__(PyObject *module)
        {
            t_AbstractStringBuilder::install(module);
            t_Appendable::install(module);
            t_Boolean::install(module);
            t_Byte::install(module);
            t_CharSequence::install(module);
            t_Character::install(module);
            t_Class::install(module);
            t_ClassLoader::install(module);
            t_ClassNotFoundException::install(module);
            t_Cloneable::install(module);
            t_Comparable::install(module);
            t_Double::install(module);
            t_Enum::install(module);
            t_Exception::install(module);
            t_Float::install(module);
            t_IllegalAccessException::install(module);
            t_IllegalArgumentException::install(module);
            t_InstantiationException::install(module);
            t_Integer::install(module);
            t_InterruptedException::install(module);
            t_Iterable::install(module);
            t_Long::install(module);
            t_NullPointerException::install(module);
            t_Number::install(module);
            t_NumberFormatException::install(module);
            t_Object::install(module);
            t_Package::install(module);
            t_Readable::install(module);
            t_RuntimeException::install(module);
            t_SecurityException::install(module);
            t_Short::install(module);
            t_StackTraceElement::install(module);
            t_String::install(module);
            t_StringBuffer::install(module);
            t_StringBuilder::install(module);
            t_Throwable::install(module);
        }

        void __initialize__(PyObject *module)
        {
            t_AbstractStringBuilder::initialize(module);
            t_Appendable::initialize(module);
            t_Boolean::initialize(module);
            t_Byte::initialize(module);
            t_CharSequence::initialize(module);
            t_Character::initialize(module);
            t_Class::initialize(module);
            t_ClassLoader::initialize(module);
            t_ClassNotFoundException::initialize(module);
            t_Cloneable::initialize(module);
            t_Comparable::initialize(module);
            t_Double::initialize(module);
            t_Enum::initialize(module);
            t_Exception::initialize(module);
            t_Float::initialize(module);
            t_IllegalAccessException::initialize(module);
            t_IllegalArgumentException::initialize(module);
            t_InstantiationException::initialize(module);
            t_Integer::initialize(module);
            t_InterruptedException::initialize(module);
            t_Iterable::initialize(module);
            t_Long::initialize(module);
            t_NullPointerException::initialize(module);
            t_Number::initialize(module);
            t_NumberFormatException::initialize(module);
            t_Object::initialize(module);
            t_Package::initialize(module);
            t_Readable::initialize(module);
            t_RuntimeException::initialize(module);
            t_SecurityException::initialize(module);
            t_Short::initialize(module);
            t_StackTraceElement::initialize(module);
            t_String::initialize(module);
            t_StringBuffer::initialize(module);
            t_StringBuilder::initialize(module);
            t_Throwable::initialize(module);
        }
    }
}

#include "java/util/AbstractCollection.h"
#include "java/util/AbstractList.h"
#include "java/util/AbstractSet.h"
#include "java/util/ArrayList.h"
#include "java/util/Collection.h"
#include "java/util/Comparator.h"
#include "java/util/Dictionary.h"
#include "java/util/Enumeration.h"
#include "java/util/HashSet.h"
#include "java/util/Hashtable.h"
#include "java/util/InvalidPropertiesFormatException.h"
#include "java/util/Iterator.h"
#include "java/util/List.h"
#include "java/util/ListIterator.h"
#include "java/util/Locale.h"
#include "java/util/Map.h"
#include "java/util/Map$Entry.h"
#include "java/util/MissingResourceException.h"
#include "java/util/Properties.h"
#include "java/util/RandomAccess.h"
#include "java/util/Set.h"
#include "java/util/Vector.h"

namespace java {
    namespace util {


        void __install__(PyObject *module)
        {
            t_AbstractCollection::install(module);
            t_AbstractList::install(module);
            t_AbstractSet::install(module);
            t_ArrayList::install(module);
            t_Collection::install(module);
            t_Comparator::install(module);
            t_Dictionary::install(module);
            t_Enumeration::install(module);
            t_HashSet::install(module);
            t_Hashtable::install(module);
            t_InvalidPropertiesFormatException::install(module);
            t_Iterator::install(module);
            t_List::install(module);
            t_ListIterator::install(module);
            t_Locale::install(module);
            t_Map::install(module);
            t_Map$Entry::install(module);
            t_MissingResourceException::install(module);
            t_Properties::install(module);
            t_RandomAccess::install(module);
            t_Set::install(module);
            t_Vector::install(module);
        }

        void __initialize__(PyObject *module)
        {
            t_AbstractCollection::initialize(module);
            t_AbstractList::initialize(module);
            t_AbstractSet::initialize(module);
            t_ArrayList::initialize(module);
            t_Collection::initialize(module);
            t_Comparator::initialize(module);
            t_Dictionary::initialize(module);
            t_Enumeration::initialize(module);
            t_HashSet::initialize(module);
            t_Hashtable::initialize(module);
            t_InvalidPropertiesFormatException::initialize(module);
            t_Iterator::initialize(module);
            t_List::initialize(module);
            t_ListIterator::initialize(module);
            t_Locale::initialize(module);
            t_Map::initialize(module);
            t_Map$Entry::initialize(module);
            t_MissingResourceException::initialize(module);
            t_Properties::initialize(module);
            t_RandomAccess::initialize(module);
            t_Set::initialize(module);
            t_Vector::initialize(module);
        }
    }
}

