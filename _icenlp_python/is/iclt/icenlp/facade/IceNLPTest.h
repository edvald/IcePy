#ifndef is_iclt_icenlp_facade_IceNLPTest_H
#define is_iclt_icenlp_facade_IceNLPTest_H

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
            namespace facade {

                class IceNLPTest : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_main_4dd4540c,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit IceNLPTest(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    IceNLPTest(const IceNLPTest& obj) : ::java::lang::Object(obj) {}

                    IceNLPTest();

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
            namespace facade {
                extern PyTypeObject PY_TYPE(IceNLPTest);

                class t_IceNLPTest {
                public:
                    PyObject_HEAD
                    IceNLPTest object;
                    static PyObject *wrap_Object(const IceNLPTest&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
