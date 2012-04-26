#ifndef is_iclt_icenlp_core_tritagger_FreqLexicon_H
#define is_iclt_icenlp_core_tritagger_FreqLexicon_H

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

                    class FreqLexicon : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_d41a79ef,
                            mid_init$_a587ce43,
                            mid_getFrequencySuffix_f369165a,
                            mid_getFrequencySuffixTag_55e0e84c,
                            mid_getFrequencyWord_5fdc3f57,
                            mid_getFrequencyWordTag_4a26475d,
                            mid_getLongestSuffixLength_f369165a,
                            mid_getNumEntries_54c6a179,
                            mid_getProbSuffix_f3691657,
                            mid_getProbWord_5fdc3f5a,
                            mid_getTagsLower_38f24ddb,
                            mid_getTagsUpper_38f24ddb,
                            mid_getTheta_54c6a174,
                            mid_lookupSuffix_edaaade4,
                            mid_lookupWord_edaaade4,
                            mid_suffixesCreated_54c6a16a,
                            max_mid
                        };

                        enum {
                            fid_corpusSize,
                            fid_suffixLength,
                            fid_suffixStart,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit FreqLexicon(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        FreqLexicon(const FreqLexicon& obj) : ::java::lang::Object(obj) {}

                        static jint formatFrequency;
                        static jint formatNoFrequency;

                        jint _get_corpusSize() const;
                        void _set_corpusSize(jint) const;
                        jint _get_suffixLength() const;
                        jint _get_suffixStart() const;

                        FreqLexicon(const ::java::lang::String &, jint, jboolean);
                        FreqLexicon(const ::java::io::InputStream &, jint, jboolean);

                        jint getFrequencySuffix(const ::java::lang::String &, jboolean) const;
                        jint getFrequencySuffixTag(const ::java::lang::String &, const ::java::lang::String &, jboolean) const;
                        jint getFrequencyWord(const ::java::lang::String &) const;
                        jint getFrequencyWordTag(const ::java::lang::String &, const ::java::lang::String &) const;
                        jint getLongestSuffixLength(const ::java::lang::String &, jboolean) const;
                        jint getNumEntries() const;
                        jdouble getProbSuffix(const ::java::lang::String &, jboolean) const;
                        jdouble getProbWord(const ::java::lang::String &) const;
                        ::java::util::Vector getTagsLower() const;
                        ::java::util::Vector getTagsUpper() const;
                        jdouble getTheta() const;
                        ::java::lang::String lookupSuffix(const ::java::lang::String &, jboolean) const;
                        ::java::lang::String lookupWord(const ::java::lang::String &, jboolean) const;
                        jboolean suffixesCreated() const;
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
                    extern PyTypeObject PY_TYPE(FreqLexicon);

                    class t_FreqLexicon {
                    public:
                        PyObject_HEAD
                        FreqLexicon object;
                        static PyObject *wrap_Object(const FreqLexicon&);
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
