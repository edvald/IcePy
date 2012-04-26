#ifndef java_util_InvalidPropertiesFormatException_H
#define java_util_InvalidPropertiesFormatException_H

#include "java/io/IOException.h"

namespace java {
    namespace lang {
        class Throwable;
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class InvalidPropertiesFormatException : public ::java::io::IOException {
        public:
            enum {
                mid_init$_c5ec8ca4,
                mid_init$_5fdc3f48,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit InvalidPropertiesFormatException(jobject obj) : ::java::io::IOException(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            InvalidPropertiesFormatException(const InvalidPropertiesFormatException& obj) : ::java::io::IOException(obj) {}

            InvalidPropertiesFormatException(const ::java::lang::Throwable &);
            InvalidPropertiesFormatException(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(InvalidPropertiesFormatException);

        class t_InvalidPropertiesFormatException {
        public:
            PyObject_HEAD
            InvalidPropertiesFormatException object;
            static PyObject *wrap_Object(const InvalidPropertiesFormatException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
