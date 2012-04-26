#ifndef is_iclt_icenlp_core_tritagger_TriTagger_H
#define is_iclt_icenlp_core_tritagger_TriTagger_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Idioms;
                }
                namespace icemorphy {
                    class IceMorphy;
                }
                namespace tritagger {
                    class Ngrams;
                    class FreqLexicon;
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
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tritagger {

                    class TriTagger : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_dd583aec,
                            mid_getNumAmbiguousTokens_54c6a179,
                            mid_getTotalTags_54c6a179,
                            mid_getTotalTagsAmbiguous_54c6a179,
                            mid_setNgram_39c7bd3c,
                            mid_tagTokens_0a109d06,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit TriTagger(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        TriTagger(const TriTagger& obj) : ::java::lang::Object(obj) {}

                        static jint bigrams;
                        static jint sentenceStartLowerCase;
                        static jint sentenceStartUpperCase;
                        static jint trigrams;

                        TriTagger(jint, jint, const ::is::iclt::icenlp::core::tritagger::Ngrams &, const ::is::iclt::icenlp::core::tritagger::FreqLexicon &, const ::is::iclt::icenlp::core::tritagger::FreqLexicon &, const ::is::iclt::icenlp::core::utils::Idioms &, const ::is::iclt::icenlp::core::icemorphy::IceMorphy &);

                        jint getNumAmbiguousTokens() const;
                        jint getTotalTags() const;
                        jint getTotalTagsAmbiguous() const;
                        void setNgram(jint) const;
                        void tagTokens(const ::java::util::ArrayList &, jboolean) const;
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
                namespace tritagger {
                    extern PyTypeObject PY_TYPE(TriTagger);

                    class t_TriTagger {
                    public:
                        PyObject_HEAD
                        TriTagger object;
                        static PyObject *wrap_Object(const TriTagger&);
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
