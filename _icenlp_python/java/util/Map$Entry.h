#ifndef java_util_Map$Entry_H
#define java_util_Map$Entry_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class Map$Entry : public ::java::lang::Object {
        public:
            enum {
                mid_equals_290588e2,
                mid_getKey_846352c3,
                mid_getValue_846352c3,
                mid_hashCode_54c6a179,
                mid_setValue_a932a95f,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Map$Entry(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Map$Entry(const Map$Entry& obj) : ::java::lang::Object(obj) {}

            jboolean equals(const ::java::lang::Object &) const;
            ::java::lang::Object getKey() const;
            ::java::lang::Object getValue() const;
            jint hashCode() const;
            ::java::lang::Object setValue(const ::java::lang::Object &) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(Map$Entry);

        class t_Map$Entry {
        public:
            PyObject_HEAD
            Map$Entry object;
            PyTypeObject *parameters[2];
            static PyTypeObject **parameters_(t_Map$Entry *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const Map$Entry&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const Map$Entry&, PyTypeObject *, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
