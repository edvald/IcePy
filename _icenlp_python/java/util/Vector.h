#ifndef java_util_Vector_H
#define java_util_Vector_H

#include "java/util/AbstractList.h"

namespace java {
    namespace util {
        class RandomAccess;
        class List;
        class Enumeration;
        class Collection;
    }
    namespace lang {
        class Object;
        class Class;
        class Cloneable;
        class String;
    }
    namespace io {
        class Serializable;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class Vector : public ::java::util::AbstractList {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_39c7bd3c,
                mid_init$_9bfb370d,
                mid_init$_d8d154a6,
                mid_add_290588e2,
                mid_add_f7cd74a4,
                mid_addAll_9bfb3701,
                mid_addAll_006cd2b7,
                mid_addElement_290588ee,
                mid_capacity_54c6a179,
                mid_clear_54c6a166,
                mid_clone_846352c3,
                mid_contains_290588e2,
                mid_containsAll_9bfb3701,
                mid_copyInto_c0f5dada,
                mid_elementAt_29be6a55,
                mid_elements_39f88070,
                mid_ensureCapacity_39c7bd3c,
                mid_equals_290588e2,
                mid_firstElement_846352c3,
                mid_get_29be6a55,
                mid_hashCode_54c6a179,
                mid_indexOf_290588f1,
                mid_indexOf_8d1da273,
                mid_insertElementAt_8d1da26c,
                mid_isEmpty_54c6a16a,
                mid_lastElement_846352c3,
                mid_lastIndexOf_290588f1,
                mid_lastIndexOf_8d1da273,
                mid_remove_29be6a55,
                mid_remove_290588e2,
                mid_removeAll_9bfb3701,
                mid_removeAllElements_54c6a166,
                mid_removeElement_290588e2,
                mid_removeElementAt_39c7bd3c,
                mid_retainAll_9bfb3701,
                mid_set_211591b1,
                mid_setElementAt_8d1da26c,
                mid_setSize_39c7bd3c,
                mid_size_54c6a179,
                mid_subList_6bc635fe,
                mid_toArray_94e49c77,
                mid_toArray_ae67dbcf,
                mid_toString_14c7b5c5,
                mid_trimToSize_54c6a166,
                mid_removeRange_d8d154a6,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Vector(jobject obj) : ::java::util::AbstractList(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Vector(const Vector& obj) : ::java::util::AbstractList(obj) {}

            Vector();
            Vector(jint);
            Vector(const ::java::util::Collection &);
            Vector(jint, jint);

            jboolean add(const ::java::lang::Object &) const;
            void add(jint, const ::java::lang::Object &) const;
            jboolean addAll(const ::java::util::Collection &) const;
            jboolean addAll(jint, const ::java::util::Collection &) const;
            void addElement(const ::java::lang::Object &) const;
            jint capacity() const;
            void clear() const;
            ::java::lang::Object clone() const;
            jboolean contains(const ::java::lang::Object &) const;
            jboolean containsAll(const ::java::util::Collection &) const;
            void copyInto(const JArray< ::java::lang::Object > &) const;
            ::java::lang::Object elementAt(jint) const;
            ::java::util::Enumeration elements() const;
            void ensureCapacity(jint) const;
            jboolean equals(const ::java::lang::Object &) const;
            ::java::lang::Object firstElement() const;
            ::java::lang::Object get(jint) const;
            jint hashCode() const;
            jint indexOf(const ::java::lang::Object &) const;
            jint indexOf(const ::java::lang::Object &, jint) const;
            void insertElementAt(const ::java::lang::Object &, jint) const;
            jboolean isEmpty() const;
            ::java::lang::Object lastElement() const;
            jint lastIndexOf(const ::java::lang::Object &) const;
            jint lastIndexOf(const ::java::lang::Object &, jint) const;
            ::java::lang::Object remove(jint) const;
            jboolean remove(const ::java::lang::Object &) const;
            jboolean removeAll(const ::java::util::Collection &) const;
            void removeAllElements() const;
            jboolean removeElement(const ::java::lang::Object &) const;
            void removeElementAt(jint) const;
            jboolean retainAll(const ::java::util::Collection &) const;
            ::java::lang::Object set(jint, const ::java::lang::Object &) const;
            void setElementAt(const ::java::lang::Object &, jint) const;
            void setSize(jint) const;
            jint size() const;
            ::java::util::List subList(jint, jint) const;
            JArray< ::java::lang::Object > toArray() const;
            JArray< ::java::lang::Object > toArray(const JArray< ::java::lang::Object > &) const;
            ::java::lang::String toString() const;
            void trimToSize() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(Vector);

        class t_Vector {
        public:
            PyObject_HEAD
            Vector object;
            PyTypeObject *parameters[1];
            static PyTypeObject **parameters_(t_Vector *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const Vector&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const Vector&, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
