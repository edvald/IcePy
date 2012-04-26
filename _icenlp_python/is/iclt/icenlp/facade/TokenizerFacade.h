#ifndef is_iclt_icenlp_facade_TokenizerFacade_H
#define is_iclt_icenlp_facade_TokenizerFacade_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Lexicon;
                }
                namespace tokenizer {
                    class Sentences;
                }
            }
        }
    }
}
namespace java {
    namespace lang {
        class String;
        class Class;
    }
    namespace io {
        class IOException;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {

                class TokenizerFacade : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_244a19ea,
                        mid_tokenize_6359824b,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit TokenizerFacade(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    TokenizerFacade(const TokenizerFacade& obj) : ::java::lang::Object(obj) {}

                    TokenizerFacade(const ::is::iclt::icenlp::core::utils::Lexicon &, jint);

                    ::is::iclt::icenlp::core::tokenizer::Sentences tokenize(const ::java::lang::String &) const;
                };
            }
        }
    }
}

#include <Python.h>

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {
                extern PyTypeObject PY_TYPE(TokenizerFacade);

                class t_TokenizerFacade {
                public:
                    PyObject_HEAD
                    TokenizerFacade object;
                    static PyObject *wrap_Object(const TokenizerFacade&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
