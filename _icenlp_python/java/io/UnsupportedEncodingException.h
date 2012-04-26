#ifndef java_io_UnsupportedEncodingException_H
#define java_io_UnsupportedEncodingException_H

#include "java/io/IOException.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class UnsupportedEncodingException : public ::java::io::IOException {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit UnsupportedEncodingException(jobject obj) : ::java::io::IOException(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            UnsupportedEncodingException(const UnsupportedEncodingException& obj) : ::java::io::IOException(obj) {}

            UnsupportedEncodingException();
            UnsupportedEncodingException(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(UnsupportedEncodingException);

        class t_UnsupportedEncodingException {
        public:
            PyObject_HEAD
            UnsupportedEncodingException object;
            static PyObject *wrap_Object(const UnsupportedEncodingException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
