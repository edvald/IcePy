#ifndef is_iclt_icenlp_runner_RunTokenizer_H
#define is_iclt_icenlp_runner_RunTokenizer_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class IOException;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace runner {

                class RunTokenizer : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_main_4dd4540c,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit RunTokenizer(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    RunTokenizer(const RunTokenizer& obj) : ::java::lang::Object(obj) {}

                    RunTokenizer();

                    static void main(const JArray< ::java::lang::String > &);
                };
            }
        }
    }
}

#include <Python.h>

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace runner {
                extern PyTypeObject PY_TYPE(RunTokenizer);

                class t_RunTokenizer {
                public:
                    PyObject_HEAD
                    RunTokenizer object;
                    static PyObject *wrap_Object(const RunTokenizer&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
