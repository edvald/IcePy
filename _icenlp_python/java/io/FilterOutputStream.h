#ifndef java_io_FilterOutputStream_H
#define java_io_FilterOutputStream_H

#include "java/io/OutputStream.h"

namespace java {
    namespace lang {
        class Class;
    }
    namespace io {
        class IOException;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class FilterOutputStream : public ::java::io::OutputStream {
        public:
            enum {
                mid_init$_82d865f8,
                mid_close_54c6a166,
                mid_flush_54c6a166,
                mid_write_49b4f12b,
                mid_write_39c7bd3c,
                mid_write_86f4435f,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit FilterOutputStream(jobject obj) : ::java::io::OutputStream(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            FilterOutputStream(const FilterOutputStream& obj) : ::java::io::OutputStream(obj) {}

            FilterOutputStream(const ::java::io::OutputStream &);

            void close() const;
            void flush() const;
            void write(const JArray< jbyte > &) const;
            void write(jint) const;
            void write(const JArray< jbyte > &, jint, jint) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(FilterOutputStream);

        class t_FilterOutputStream {
        public:
            PyObject_HEAD
            FilterOutputStream object;
            static PyObject *wrap_Object(const FilterOutputStream&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
