#ifndef java_io_FileFilter_H
#define java_io_FileFilter_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
    namespace io {
        class File;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class FileFilter : public ::java::lang::Object {
        public:
            enum {
                mid_accept_c3dacf5b,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit FileFilter(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            FileFilter(const FileFilter& obj) : ::java::lang::Object(obj) {}

            jboolean accept(const ::java::io::File &) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(FileFilter);

        class t_FileFilter {
        public:
            PyObject_HEAD
            FileFilter object;
            static PyObject *wrap_Object(const FileFilter&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
