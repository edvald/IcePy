#ifndef is_iclt_icenlp_core_formald_Format_H
#define is_iclt_icenlp_core_formald_Format_H

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
                namespace formald {

                    class Format : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_sampleData_14c7b5c5,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Format(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Format(const Format& obj) : ::java::lang::Object(obj) {}

                        Format();

                        ::java::lang::String sampleData() const;
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
                namespace formald {
                    extern PyTypeObject PY_TYPE(Format);

                    class t_Format {
                    public:
                        PyObject_HEAD
                        Format object;
                        static PyObject *wrap_Object(const Format&);
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
