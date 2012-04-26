#ifndef java_lang_NullPointerException_H
#define java_lang_NullPointerException_H

#include "java/lang/RuntimeException.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class NullPointerException : public ::java::lang::RuntimeException {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit NullPointerException(jobject obj) : ::java::lang::RuntimeException(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            NullPointerException(const NullPointerException& obj) : ::java::lang::RuntimeException(obj) {}

            NullPointerException();
            NullPointerException(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(NullPointerException);

        class t_NullPointerException {
        public:
            PyObject_HEAD
            NullPointerException object;
            static PyObject *wrap_Object(const NullPointerException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
