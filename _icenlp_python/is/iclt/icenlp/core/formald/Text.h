#ifndef is_iclt_icenlp_core_formald_Text_H
#define is_iclt_icenlp_core_formald_Text_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {

                    class Text : public ::java::lang::Object {
                    public:

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Text(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Text(const Text& obj) : ::java::lang::Object(obj) {}
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
                    extern PyTypeObject PY_TYPE(Text);

                    class t_Text {
                    public:
                        PyObject_HEAD
                        Text object;
                        static PyObject *wrap_Object(const Text&);
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
