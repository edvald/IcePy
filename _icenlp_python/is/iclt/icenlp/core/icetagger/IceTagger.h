#ifndef is_iclt_icenlp_core_icetagger_IceTagger_H
#define is_iclt_icenlp_core_icetagger_IceTagger_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Idioms;
                    class Lexicon;
                    class IceLog;
                }
                namespace icemorphy {
                    class IceMorphy;
                }
                namespace tritagger {
                    class TriTagger;
                }
                namespace icetagger {
                    class IceTagger$HmmModelType;
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
                namespace icetagger {

                    class IceTagger : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_6e310e5b,
                            mid_forceAgreement_281ca35a,
                            mid_getEndWithHmmModel_54c6a16a,
                            mid_getNumAmbiguousTokens_54c6a179,
                            mid_getStartWithHmmModel_54c6a16a,
                            mid_getTagMaxFreq_e57c73cb,
                            mid_getTotalTags_54c6a179,
                            mid_getTotalTagsAmbiguous_54c6a179,
                            mid_initStatistics_54c6a166,
                            mid_setHmmModelType_50cf6b0f,
                            mid_setTriTagger_ef785e23,
                            mid_tagTokens_b3f662f9,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTagger(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTagger(const IceTagger& obj) : ::java::lang::Object(obj) {}

                        static jint sentenceStartLowerCase;
                        static jint sentenceStartUpperCase;

                        IceTagger(jint, const ::is::iclt::icenlp::core::utils::IceLog &, const ::is::iclt::icenlp::core::icemorphy::IceMorphy &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Idioms &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Lexicon &, jboolean, jboolean, const ::is::iclt::icenlp::core::tritagger::TriTagger &, const ::is::iclt::icenlp::core::icetagger::IceTagger$HmmModelType &);

                        void forceAgreement(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean getEndWithHmmModel() const;
                        jint getNumAmbiguousTokens() const;
                        jboolean getStartWithHmmModel() const;
                        ::java::lang::String getTagMaxFreq(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jint getTotalTags() const;
                        jint getTotalTagsAmbiguous() const;
                        void initStatistics() const;
                        void setHmmModelType(const ::is::iclt::icenlp::core::icetagger::IceTagger$HmmModelType &) const;
                        void setTriTagger(const ::is::iclt::icenlp::core::tritagger::TriTagger &) const;
                        void tagTokens(const ::java::util::ArrayList &) const;
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
                namespace icetagger {
                    extern PyTypeObject PY_TYPE(IceTagger);

                    class t_IceTagger {
                    public:
                        PyObject_HEAD
                        IceTagger object;
                        static PyObject *wrap_Object(const IceTagger&);
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
