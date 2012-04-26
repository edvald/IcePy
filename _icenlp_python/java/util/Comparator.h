#ifndef java_util_Comparator_H
#define java_util_Comparator_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class Comparator : public ::java::lang::Object {
        public:
            enum {
                mid_compare_466982ed,
                mid_equals_290588e2,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Comparator(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Comparator(const Comparator& obj) : ::java::lang::Object(obj) {}

            jint compare(const ::java::lang::Object &, const ::java::lang::Object &) const;
            jboolean equals(const ::java::lang::Object &) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(Comparator);

        class t_Comparator {
        public:
            PyObject_HEAD
            Comparator object;
            PyTypeObject *parameters[1];
            static PyTypeObject **parameters_(t_Comparator *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const Comparator&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const Comparator&, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
