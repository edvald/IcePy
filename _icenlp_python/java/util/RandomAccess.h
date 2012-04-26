#ifndef java_util_RandomAccess_H
#define java_util_RandomAccess_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class RandomAccess : public ::java::lang::Object {
        public:

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit RandomAccess(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            RandomAccess(const RandomAccess& obj) : ::java::lang::Object(obj) {}
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(RandomAccess);

        class t_RandomAccess {
        public:
            PyObject_HEAD
            RandomAccess object;
            static PyObject *wrap_Object(const RandomAccess&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
