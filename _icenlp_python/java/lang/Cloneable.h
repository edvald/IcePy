#ifndef java_lang_Cloneable_H
#define java_lang_Cloneable_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Cloneable : public ::java::lang::Object {
        public:

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Cloneable(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Cloneable(const Cloneable& obj) : ::java::lang::Object(obj) {}
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Cloneable);

        class t_Cloneable {
        public:
            PyObject_HEAD
            Cloneable object;
            static PyObject *wrap_Object(const Cloneable&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
