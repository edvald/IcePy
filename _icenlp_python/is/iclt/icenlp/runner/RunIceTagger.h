#ifndef is_iclt_icenlp_runner_RunIceTagger_H
#define is_iclt_icenlp_runner_RunIceTagger_H

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

                class RunIceTagger : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_main_4dd4540c,
                        mid_initialize_8d71b8e0,
                        mid_printResults_e001e437,
                        mid_performTagging_54c6a166,
                        mid_finish_aa83a4b3,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit RunIceTagger(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    RunIceTagger(const RunIceTagger& obj) : ::java::lang::Object(obj) {}

                    RunIceTagger();

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
                extern PyTypeObject PY_TYPE(RunIceTagger);

                class t_RunIceTagger {
                public:
                    PyObject_HEAD
                    RunIceTagger object;
                    static PyObject *wrap_Object(const RunIceTagger&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
