#ifndef is_iclt_icenlp_core_utils_XmlOperations_H
#define is_iclt_icenlp_core_utils_XmlOperations_H

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
            namespace core {
                namespace utils {

                    class XmlOperations : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit XmlOperations(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        XmlOperations(const XmlOperations& obj) : ::java::lang::Object(obj) {}

                        XmlOperations();
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
                namespace utils {
                    extern PyTypeObject PY_TYPE(XmlOperations);

                    class t_XmlOperations {
                    public:
                        PyObject_HEAD
                        XmlOperations object;
                        static PyObject *wrap_Object(const XmlOperations&);
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
