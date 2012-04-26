#ifndef java_util_HashSet_H
#define java_util_HashSet_H

#include "java/util/AbstractSet.h"

namespace java {
    namespace util {
        class Iterator;
        class Collection;
    }
    namespace lang {
        class Object;
        class Class;
        class Cloneable;
    }
    namespace io {
        class Serializable;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class HashSet : public ::java::util::AbstractSet {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_9bfb370d,
                mid_init$_39c7bd3c,
                mid_init$_abdf2c51,
                mid_add_290588e2,
                mid_clear_54c6a166,
                mid_clone_846352c3,
                mid_contains_290588e2,
                mid_isEmpty_54c6a16a,
                mid_iterator_40858c90,
                mid_remove_290588e2,
                mid_size_54c6a179,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit HashSet(jobject obj) : ::java::util::AbstractSet(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            HashSet(const HashSet& obj) : ::java::util::AbstractSet(obj) {}

            HashSet();
            HashSet(const ::java::util::Collection &);
            HashSet(jint);
            HashSet(jint, jfloat);

            jboolean add(const ::java::lang::Object &) const;
            void clear() const;
            ::java::lang::Object clone() const;
            jboolean contains(const ::java::lang::Object &) const;
            jboolean isEmpty() const;
            ::java::util::Iterator iterator() const;
            jboolean remove(const ::java::lang::Object &) const;
            jint size() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(HashSet);

        class t_HashSet {
        public:
            PyObject_HEAD
            HashSet object;
            PyTypeObject *parameters[1];
            static PyTypeObject **parameters_(t_HashSet *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const HashSet&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const HashSet&, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
