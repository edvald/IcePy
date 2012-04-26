#ifndef is_iclt_icenlp_runner_RunIceTaggerApertium_H
#define is_iclt_icenlp_runner_RunIceTaggerApertium_H

#include "is/iclt/icenlp/runner/RunIceTagger.h"

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

                class RunIceTaggerApertium : public ::is::iclt::icenlp::runner::RunIceTagger {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_main_4dd4540c,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit RunIceTaggerApertium(jobject obj) : ::is::iclt::icenlp::runner::RunIceTagger(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    RunIceTaggerApertium(const RunIceTaggerApertium& obj) : ::is::iclt::icenlp::runner::RunIceTagger(obj) {}

                    RunIceTaggerApertium();

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
                extern PyTypeObject PY_TYPE(RunIceTaggerApertium);

                class t_RunIceTaggerApertium {
                public:
                    PyObject_HEAD
                    RunIceTaggerApertium object;
                    static PyObject *wrap_Object(const RunIceTaggerApertium&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
