#ifndef java_io_Closeable_H
#define java_io_Closeable_H

#include "java/lang/Object.h"

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

        class Closeable : public ::java::lang::Object {
        public:
            enum {
                mid_close_54c6a166,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Closeable(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Closeable(const Closeable& obj) : ::java::lang::Object(obj) {}

            void close() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(Closeable);

        class t_Closeable {
        public:
            PyObject_HEAD
            Closeable object;
            static PyObject *wrap_Object(const Closeable&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
