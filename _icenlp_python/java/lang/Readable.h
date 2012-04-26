#ifndef java_lang_Readable_H
#define java_lang_Readable_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Readable : public ::java::lang::Object {
        public:

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Readable(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Readable(const Readable& obj) : ::java::lang::Object(obj) {}
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Readable);

        class t_Readable {
        public:
            PyObject_HEAD
            Readable object;
            static PyObject *wrap_Object(const Readable&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
