#ifndef java_io_FileNotFoundException_H
#define java_io_FileNotFoundException_H

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

        class FileNotFoundException : public ::java::io::IOException {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_5fdc3f48,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit FileNotFoundException(jobject obj) : ::java::io::IOException(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            FileNotFoundException(const FileNotFoundException& obj) : ::java::io::IOException(obj) {}

            FileNotFoundException();
            FileNotFoundException(const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(FileNotFoundException);

        class t_FileNotFoundException {
        public:
            PyObject_HEAD
            FileNotFoundException object;
            static PyObject *wrap_Object(const FileNotFoundException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
