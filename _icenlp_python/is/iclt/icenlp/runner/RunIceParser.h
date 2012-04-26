#ifndef is_iclt_icenlp_runner_RunIceParser_H
#define is_iclt_icenlp_runner_RunIceParser_H

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

                class RunIceParser : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_getParam_4dd4540c,
                        mid_main_4dd4540c,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit RunIceParser(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    RunIceParser(const RunIceParser& obj) : ::java::lang::Object(obj) {}

                    RunIceParser();

                    void getParam(const JArray< ::java::lang::String > &) const;
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
                extern PyTypeObject PY_TYPE(RunIceParser);

                class t_RunIceParser {
                public:
                    PyObject_HEAD
                    RunIceParser object;
                    static PyObject *wrap_Object(const RunIceParser&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
