#ifndef is_iclt_icenlp_core_tritagger_Ngrams_H
#define is_iclt_icenlp_core_tritagger_Ngrams_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class String;
        class NullPointerException;
        class Class;
    }
    namespace util {
        class Vector;
    }
    namespace io {
        class IOException;
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tritagger {

                    class Ngrams : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_4a264742,
                            mid_init$_adde7c2e,
                            mid_contextualProbSmoothing_4a264750,
                            mid_contextualProbSmoothing_9c119576,
                            mid_corpusSize_54c6a179,
                            mid_getEntropy_54c6a174,
                            mid_getFrequency_5fdc3f57,
                            mid_getFrequency_4a26475d,
                            mid_getFrequency_9c11957b,
                            mid_getMostFrequentTag_14c7b5c5,
                            mid_getNumBigrams_54c6a179,
                            mid_getNumTags_54c6a179,
                            mid_getNumTrigrams_54c6a179,
                            mid_getNumUnigrams_54c6a179,
                            mid_getTags_38f24ddb,
                            mid_getTheta_54c6a174,
                            mid_getUnigramProb_5fdc3f5a,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Ngrams(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Ngrams(const Ngrams& obj) : ::java::lang::Object(obj) {}

                        static ::java::lang::String *boundaryTag;

                        Ngrams(const ::java::lang::String &, const ::java::lang::String &);
                        Ngrams(const ::java::io::InputStream &, const ::java::io::InputStream &);

                        jdouble contextualProbSmoothing(const ::java::lang::String &, const ::java::lang::String &) const;
                        jdouble contextualProbSmoothing(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &) const;
                        jint corpusSize() const;
                        jdouble getEntropy() const;
                        jint getFrequency(const ::java::lang::String &) const;
                        jint getFrequency(const ::java::lang::String &, const ::java::lang::String &) const;
                        jint getFrequency(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &) const;
                        ::java::lang::String getMostFrequentTag() const;
                        jint getNumBigrams() const;
                        jint getNumTags() const;
                        jint getNumTrigrams() const;
                        jint getNumUnigrams() const;
                        ::java::util::Vector getTags() const;
                        jdouble getTheta() const;
                        jdouble getUnigramProb(const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(Ngrams);

                    class t_Ngrams {
                    public:
                        PyObject_HEAD
                        Ngrams object;
                        static PyObject *wrap_Object(const Ngrams&);
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
