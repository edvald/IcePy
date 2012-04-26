#ifndef is_iclt_icenlp_core_tokenizer_Sentence_H
#define is_iclt_icenlp_core_tokenizer_Sentence_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {
                    class Token;
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

                    class Sentence : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_b3f662f9,
                            mid_add_eae64d83,
                            mid_getTokens_21eb51b0,
                            mid_toString_14c7b5c5,
                            mid_toStringNewline_445a175e,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Sentence(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Sentence(const Sentence& obj) : ::java::lang::Object(obj) {}

                        Sentence();
                        Sentence(const ::java::util::ArrayList &);

                        void add(const ::is::iclt::icenlp::core::tokenizer::Token &) const;
                        ::java::util::ArrayList getTokens() const;
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
                    extern PyTypeObject PY_TYPE(Sentence);

                    class t_Sentence {
                    public:
                        PyObject_HEAD
                        Sentence object;
                        static PyObject *wrap_Object(const Sentence&);
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
