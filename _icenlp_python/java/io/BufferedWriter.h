#ifndef java_io_BufferedWriter_H
#define java_io_BufferedWriter_H

#include "java/io/Writer.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class IOException;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class BufferedWriter : public ::java::io::Writer {
        public:
            enum {
                mid_init$_5bcd5850,
                mid_init$_7f1d4d96,
                mid_close_54c6a166,
                mid_flush_54c6a166,
                mid_newLine_54c6a166,
                mid_write_39c7bd3c,
                mid_write_6f0bb356,
                mid_write_555f322c,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit BufferedWriter(jobject obj) : ::java::io::Writer(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            BufferedWriter(const BufferedWriter& obj) : ::java::io::Writer(obj) {}

            BufferedWriter(const ::java::io::Writer &);
            BufferedWriter(const ::java::io::Writer &, jint);

            void close() const;
            void flush() const;
            void newLine() const;
            void write(jint) const;
            void write(const JArray< jchar > &, jint, jint) const;
            void write(const ::java::lang::String &, jint, jint) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(BufferedWriter);

        class t_BufferedWriter {
        public:
            PyObject_HEAD
            BufferedWriter object;
            static PyObject *wrap_Object(const BufferedWriter&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
