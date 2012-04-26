#ifndef is_iclt_icenlp_core_tokenizer_Sentences_H
#define is_iclt_icenlp_core_tokenizer_Sentences_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {
                    class Sentence;
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
                namespace tokenizer {

                    class Sentences : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_add_8c932910,
                            mid_getSentences_21eb51b0,
                            mid_toString_14c7b5c5,
                            mid_toStringNewline_445a175e,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Sentences(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Sentences(const Sentences& obj) : ::java::lang::Object(obj) {}

                        Sentences();

                        void add(const ::is::iclt::icenlp::core::tokenizer::Sentence &) const;
                        ::java::util::ArrayList getSentences() const;
                        ::java::lang::String toString() const;
                        ::java::lang::String toStringNewline(jboolean) const;
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
                    extern PyTypeObject PY_TYPE(Sentences);

                    class t_Sentences {
                    public:
                        PyObject_HEAD
                        Sentences object;
                        static PyObject *wrap_Object(const Sentences&);
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
