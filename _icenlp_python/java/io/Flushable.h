#ifndef java_io_Flushable_H
#define java_io_Flushable_H

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

        class Flushable : public ::java::lang::Object {
        public:
            enum {
                mid_flush_54c6a166,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Flushable(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Flushable(const Flushable& obj) : ::java::lang::Object(obj) {}

            void flush() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(Flushable);

        class t_Flushable {
        public:
            PyObject_HEAD
            Flushable object;
            static PyObject *wrap_Object(const Flushable&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
