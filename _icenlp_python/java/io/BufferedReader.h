#ifndef java_io_BufferedReader_H
#define java_io_BufferedReader_H

#include "java/io/Reader.h"

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

        class BufferedReader : public ::java::io::Reader {
        public:
            enum {
                mid_init$_cf2e3c10,
                mid_init$_8c604f56,
                mid_close_54c6a166,
                mid_mark_39c7bd3c,
                mid_markSupported_54c6a16a,
                mid_read_54c6a179,
                mid_read_6f0bb349,
                mid_readLine_14c7b5c5,
                mid_ready_54c6a16a,
                mid_reset_54c6a166,
                mid_skip_0ee6df33,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit BufferedReader(jobject obj) : ::java::io::Reader(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            BufferedReader(const BufferedReader& obj) : ::java::io::Reader(obj) {}

            BufferedReader(const ::java::io::Reader &);
            BufferedReader(const ::java::io::Reader &, jint);

            void close() const;
            void mark(jint) const;
            jboolean markSupported() const;
            jint read() const;
            jint read(const JArray< jchar > &, jint, jint) const;
            ::java::lang::String readLine() const;
            jboolean ready() const;
            void reset() const;
            jlong skip(jlong) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(BufferedReader);

        class t_BufferedReader {
        public:
            PyObject_HEAD
            BufferedReader object;
            static PyObject *wrap_Object(const BufferedReader&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
