#ifndef is_iclt_icenlp_core_tokenizer_Segmentizer_H
#define is_iclt_icenlp_core_tokenizer_Segmentizer_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Lexicon;
                }
            }
        }
    }
}
namespace java {
    namespace lang {
        class String;
        class NullPointerException;
        class Class;
    }
    namespace io {
        class BufferedReader;
        class IOException;
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {

                    class Segmentizer : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_be2e4f90,
                            mid_init$_4f633a30,
                            mid_init$_244a19ea,
                            mid_init$_4a264742,
                            mid_init$_923b8828,
                            mid_init$_54da3710,
                            mid_init$_632ddaa0,
                            mid_init$_63ea6fb1,
                            mid_init$_44d26aaf,
                            mid_init$_4e96167b,
                            mid_getNextSentence_14c7b5c5,
                            mid_hasMoreSentences_54c6a16a,
                            mid_interpretLineFormat_141401b3,
                            mid_segmentize_5fdc3f48,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Segmentizer(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Segmentizer(const Segmentizer& obj) : ::java::lang::Object(obj) {}

                        static jint otherDifferentFormat;
                        static jint sentencePerLine;
                        static jint tokenPerLine;

                        Segmentizer(const ::java::io::InputStream &);
                        Segmentizer(const ::is::iclt::icenlp::core::utils::Lexicon &);
                        Segmentizer(const ::is::iclt::icenlp::core::utils::Lexicon &, jint);
                        Segmentizer(const ::java::lang::String &, const ::java::lang::String &);
                        Segmentizer(const ::java::lang::String &, jint, const ::java::lang::String &);
                        Segmentizer(const ::java::lang::String &, jint, const ::java::io::InputStream &);
                        Segmentizer(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::utils::Lexicon &);
                        Segmentizer(const ::java::io::BufferedReader &, jint, const ::java::lang::String &);
                        Segmentizer(const ::java::io::BufferedReader &, jint, const ::java::io::InputStream &);
                        Segmentizer(const ::java::io::BufferedReader &, jint, const ::is::iclt::icenlp::core::utils::Lexicon &);

                        ::java::lang::String getNextSentence() const;
                        jboolean hasMoreSentences() const;
                        static ::java::lang::String interpretLineFormat(jint);
                        void segmentize(const ::java::lang::String &) const;
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
                namespace tokenizer {
                    extern PyTypeObject PY_TYPE(Segmentizer);

                    class t_Segmentizer {
                    public:
                        PyObject_HEAD
                        Segmentizer object;
                        static PyObject *wrap_Object(const Segmentizer&);
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
