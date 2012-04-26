#ifndef java_io_Reader_H
#define java_io_Reader_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Readable;
        class Class;
    }
    namespace io {
        class IOException;
        class Closeable;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class Reader : public ::java::lang::Object {
        public:
            enum {
                mid_close_54c6a166,
                mid_mark_39c7bd3c,
                mid_markSupported_54c6a16a,
                mid_read_54c6a179,
                mid_read_700e23c9,
                mid_read_6f0bb349,
                mid_ready_54c6a16a,
                mid_reset_54c6a166,
                mid_skip_0ee6df33,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Reader(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Reader(const Reader& obj) : ::java::lang::Object(obj) {}

            void close() const;
            void mark(jint) const;
            jboolean markSupported() const;
            jint read() const;
            jint read(const JArray< jchar > &) const;
            jint read(const JArray< jchar > &, jint, jint) const;
            jboolean ready() const;
            void reset() const;
            jlong skip(jlong) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(Reader);

        class t_Reader {
        public:
            PyObject_HEAD
            Reader object;
            static PyObject *wrap_Object(const Reader&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
