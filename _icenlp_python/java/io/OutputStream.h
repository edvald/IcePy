#ifndef java_io_OutputStream_H
#define java_io_OutputStream_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
    namespace io {
        class IOException;
        class Closeable;
        class Flushable;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class OutputStream : public ::java::lang::Object {
        public:
            enum {
                mid_init$_54c6a166,
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

            explicit OutputStream(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            OutputStream(const OutputStream& obj) : ::java::lang::Object(obj) {}

            OutputStream();

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
        extern PyTypeObject PY_TYPE(OutputStream);

        class t_OutputStream {
        public:
            PyObject_HEAD
            OutputStream object;
            static PyObject *wrap_Object(const OutputStream&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
