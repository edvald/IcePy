#ifndef java_io_IOException_H
#define java_io_IOException_H

#include "java/lang/Exception.h"

namespace java {
    namespace lang {
        class Throwable;
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class IOException : public ::java::lang::Exception {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                mid_init$_c5ec8ca4,
                mid_init$_01646a2e,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit IOException(jobject obj) : ::java::lang::Exception(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            IOException(const IOException& obj) : ::java::lang::Exception(obj) {}

            IOException();
            IOException(const ::java::lang::String &);
            IOException(const ::java::lang::Throwable &);
            IOException(const ::java::lang::String &, const ::java::lang::Throwable &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(IOException);

        class t_IOException {
        public:
            PyObject_HEAD
            IOException object;
            static PyObject *wrap_Object(const IOException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
