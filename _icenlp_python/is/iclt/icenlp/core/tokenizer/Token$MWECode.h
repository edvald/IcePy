#ifndef is_iclt_icenlp_core_tokenizer_Token$MWECode_H
#define is_iclt_icenlp_core_tokenizer_Token$MWECode_H

#include "java/lang/Enum.h"

namespace java {
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

                    class Token$MWECode : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_2e8728ea,
                            mid_values_3d238c7c,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Token$MWECode(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Token$MWECode(const Token$MWECode& obj) : ::java::lang::Enum(obj) {}

                        static Token$MWECode *begins;
                        static Token$MWECode *ends;
                        static Token$MWECode *none;

                        static Token$MWECode valueOf(const ::java::lang::String &);
                        static JArray< Token$MWECode > values();
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
                    extern PyTypeObject PY_TYPE(Token$MWECode);

                    class t_Token$MWECode {
                    public:
                        PyObject_HEAD
                        Token$MWECode object;
                        static PyObject *wrap_Object(const Token$MWECode&);
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
