#ifndef java_util_ListIterator_H
#define java_util_ListIterator_H

#include "java/util/Iterator.h"

namespace java {
    namespace lang {
        class Object;
        class Class;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class ListIterator : public ::java::util::Iterator {
        public:
            enum {
                mid_add_290588ee,
                mid_hasNext_54c6a16a,
                mid_hasPrevious_54c6a16a,
                mid_next_846352c3,
                mid_nextIndex_54c6a179,
                mid_previous_846352c3,
                mid_previousIndex_54c6a179,
                mid_remove_54c6a166,
                mid_set_290588ee,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit ListIterator(jobject obj) : ::java::util::Iterator(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            ListIterator(const ListIterator& obj) : ::java::util::Iterator(obj) {}

            void add(const ::java::lang::Object &) const;
            jboolean hasNext() const;
            jboolean hasPrevious() const;
            ::java::lang::Object next() const;
            jint nextIndex() const;
            ::java::lang::Object previous() const;
            jint previousIndex() const;
            void remove() const;
            void set(const ::java::lang::Object &) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(ListIterator);

        class t_ListIterator {
        public:
            PyObject_HEAD
            ListIterator object;
            PyTypeObject *parameters[1];
            static PyTypeObject **parameters_(t_ListIterator *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const ListIterator&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const ListIterator&, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
