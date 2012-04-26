#ifndef is_iclt_icenlp_runner_RunTrie_H
#define is_iclt_icenlp_runner_RunTrie_H

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

                class RunTrie : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_main_4dd4540c,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit RunTrie(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    RunTrie(const RunTrie& obj) : ::java::lang::Object(obj) {}

                    RunTrie();

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
                extern PyTypeObject PY_TYPE(RunTrie);

                class t_RunTrie {
                public:
                    PyObject_HEAD
                    RunTrie object;
                    static PyObject *wrap_Object(const RunTrie&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
