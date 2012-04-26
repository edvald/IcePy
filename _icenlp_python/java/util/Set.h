#ifndef java_util_Set_H
#define java_util_Set_H

#include "java/util/Collection.h"

namespace java {
    namespace util {
        class Iterator;
    }
    namespace lang {
        class Object;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class Set : public ::java::util::Collection {
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
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Set(jobject obj) : ::java::util::Collection(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Set(const Set& obj) : ::java::util::Collection(obj) {}

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
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(Set);

        class t_Set {
        public:
            PyObject_HEAD
            Set object;
            PyTypeObject *parameters[1];
            static PyTypeObject **parameters_(t_Set *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const Set&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const Set&, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
