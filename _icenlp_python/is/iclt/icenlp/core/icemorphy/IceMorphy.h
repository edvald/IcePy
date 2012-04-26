#ifndef is_iclt_icenlp_core_icemorphy_IceMorphy_H
#define is_iclt_icenlp_core_icemorphy_IceMorphy_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class WordList;
                    class Trie;
                    class Lexicon;
                    class IceTag$WordClass;
                    class IceLog;
                }
                namespace icetagger {
                    class IceFrequency;
                }
                namespace tokenizer {
                    class IceTokenTags;
                }
            }
        }
    }
}
namespace java {
    namespace util {
        class ArrayList;
    }
    namespace lang {
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icemorphy {

                    class IceMorphy : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_e0806810,
                            mid_addPrefix_9ee1b518,
                            mid_analyzeProperNoun_171fb4bd,
                            mid_compoundAnalysisPrefix_9ee1b518,
                            mid_compoundAnalysisSuffix_171fb4bd,
                            mid_compoundVerbAnalysis_9ee1b518,
                            mid_dictionaryLookup_edaaade4,
                            mid_dictionaryTokenLookup_171fb4b1,
                            mid_endingAnalysis_1ba6ff83,
                            mid_endingAnalysisProper_9ee1b518,
                            mid_foreignAnalysis_9ee1b518,
                            mid_generateMissingTags_9ee1b514,
                            mid_isForeignLexeme_5fdc3f44,
                            mid_maxFrequency_e57c73cb,
                            mid_morphoAnalysis_54c6a166,
                            mid_morphoAnalysisSuffix_171fb4bd,
                            mid_morphoAnalysisToken_281ca356,
                            mid_numberAnalysis_9ee1b518,
                            mid_setTokens_b3f662f9,
                            mid_verbAnalysis_281ca356,
                            mid_verbFiniteAnalysis_9ee1b518,
                            mid_verbInfinitiveAnalysis_9ee1b518,
                            mid_verbInfinitiveOrPresentParticpleOnly_281ca356,
                            mid_verbPastParticipleAnalysis_9ee1b518,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceMorphy(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceMorphy(const IceMorphy& obj) : ::java::lang::Object(obj) {}

                        IceMorphy(const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Trie &, const ::is::iclt::icenlp::core::utils::Trie &, const ::is::iclt::icenlp::core::utils::Trie &, const ::is::iclt::icenlp::core::utils::WordList &, const ::is::iclt::icenlp::core::icetagger::IceFrequency &, const ::is::iclt::icenlp::core::utils::IceLog &);

                        jboolean addPrefix(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean analyzeProperNoun(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, jboolean) const;
                        jboolean compoundAnalysisPrefix(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean compoundAnalysisSuffix(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, jboolean) const;
                        jboolean compoundVerbAnalysis(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        ::java::lang::String dictionaryLookup(const ::java::lang::String &, jboolean) const;
                        void dictionaryTokenLookup(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, jboolean) const;
                        jboolean endingAnalysis(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::utils::IceTag$WordClass &, jboolean) const;
                        jboolean endingAnalysisProper(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean foreignAnalysis(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void generateMissingTags(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean isForeignLexeme(const ::java::lang::String &) const;
                        ::java::lang::String maxFrequency(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void morphoAnalysis() const;
                        jboolean morphoAnalysisSuffix(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, jboolean) const;
                        jboolean morphoAnalysisToken(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean numberAnalysis(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void setTokens(const ::java::util::ArrayList &) const;
                        jboolean verbAnalysis(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean verbFiniteAnalysis(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean verbInfinitiveAnalysis(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean verbInfinitiveOrPresentParticpleOnly(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean verbPastParticipleAnalysis(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                    };
                }
            }
        }
    }
}

#include <Python.h>

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icemorphy {
                    extern PyTypeObject PY_TYPE(IceMorphy);

                    class t_IceMorphy {
                    public:
                        PyObject_HEAD
                        IceMorphy object;
                        static PyObject *wrap_Object(const IceMorphy&);
                        static PyObject *wrap_jobject(const jobject&);
                        static void install(PyObject *module);
                        static void initialize(PyObject *module);
                    };
                }
            }
        }
    }
}

#endif
