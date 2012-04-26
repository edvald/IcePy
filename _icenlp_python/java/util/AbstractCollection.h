#ifndef java_util_AbstractCollection_H
#define java_util_AbstractCollection_H

#include "java/lang/Object.h"

namespace java {
    namespace util {
        class Iterator;
        class Collection;
    }
    namespace lang {
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class AbstractCollection : public ::java::lang::Object {
        public:
            enum {
                mid_add_290588e2,
                mid_addAll_9bfb3701,
                mid_clear_54c6a166,
                mid_contains_290588e2,
                mid_containsAll_9bfb3701,
                mid_equals_290588e2,
                mid_hashCode_54c6a179,
                mid_isEmpty_54c6a16a,
                mid_iterator_40858c90,
                mid_remove_290588e2,
                mid_removeAll_9bfb3701,
                mid_retainAll_9bfb3701,
                mid_size_54c6a179,
                mid_toArray_94e49c77,
                mid_toArray_ae67dbcf,
                mid_toString_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit AbstractCollection(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            AbstractCollection(const AbstractCollection& obj) : ::java::lang::Object(obj) {}

            jboolean add(const ::java::lang::Object &) const;
            jboolean addAll(const ::java::util::Collection &) const;
            void clear() const;
            jboolean contains(const ::java::lang::Object &) const;
            jboolean containsAll(const ::java::util::Collection &) const;
            jboolean equals(const ::java::lang::Object &) const;
            jint hashCode() const;
            jboolean isEmpty() const;
            ::java::util::Iterator iterator() const;
            jboolean remove(const ::java::lang::Object &) const;
            jboolean removeAll(const ::java::util::Collection &) const;
            jboolean retainAll(const ::java::util::Collection &) const;
            jint size() const;
            JArray< ::java::lang::Object > toArray() const;
            JArray< ::java::lang::Object > toArray(const JArray< ::java::lang::Object > &) const;
            ::java::lang::String toString() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(AbstractCollection);

        class t_AbstractCollection {
        public:
            PyObject_HEAD
            AbstractCollection object;
            PyTypeObject *parameters[1];
            static PyTypeObject **parameters_(t_AbstractCollection *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const AbstractCollection&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const AbstractCollection&, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
