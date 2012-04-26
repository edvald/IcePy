#ifndef java_util_Dictionary_H
#define java_util_Dictionary_H

#include "java/lang/Object.h"

namespace java {
    namespace util {
        class Enumeration;
    }
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class Dictionary : public ::java::lang::Object {
        public:
            enum {
                mid_init$_54c6a166,
                mid_elements_39f88070,
                mid_get_a932a95f,
                mid_isEmpty_54c6a16a,
                mid_keys_39f88070,
                mid_put_537d5bdf,
                mid_remove_a932a95f,
                mid_size_54c6a179,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Dictionary(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Dictionary(const Dictionary& obj) : ::java::lang::Object(obj) {}

            Dictionary();

            ::java::util::Enumeration elements() const;
            ::java::lang::Object get(const ::java::lang::Object &) const;
            jboolean isEmpty() const;
            ::java::util::Enumeration keys() const;
            ::java::lang::Object put(const ::java::lang::Object &, const ::java::lang::Object &) const;
            ::java::lang::Object remove(const ::java::lang::Object &) const;
            jint size() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(Dictionary);

        class t_Dictionary {
        public:
            PyObject_HEAD
            Dictionary object;
            PyTypeObject *parameters[2];
            static PyTypeObject **parameters_(t_Dictionary *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const Dictionary&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const Dictionary&, PyTypeObject *, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
