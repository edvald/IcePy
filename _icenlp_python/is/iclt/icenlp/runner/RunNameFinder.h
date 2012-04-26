#ifndef is_iclt_icenlp_runner_RunNameFinder_H
#define is_iclt_icenlp_runner_RunNameFinder_H

#include "java/lang/Object.h"

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
            namespace runner {

                class RunNameFinder : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_main_4dd4540c,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit RunNameFinder(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    RunNameFinder(const RunNameFinder& obj) : ::java::lang::Object(obj) {}

                    RunNameFinder();

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
                extern PyTypeObject PY_TYPE(RunNameFinder);

                class t_RunNameFinder {
                public:
                    PyObject_HEAD
                    RunNameFinder object;
                    static PyObject *wrap_Object(const RunNameFinder&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
