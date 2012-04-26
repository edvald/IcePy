#ifndef java_util_Hashtable_H
#define java_util_Hashtable_H

#include "java/util/Dictionary.h"

namespace java {
    namespace util {
        class Map$Entry;
        class Map;
        class Set;
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

        class Hashtable : public ::java::util::Dictionary {
        public:
            enum {
                mid_init$_54c6a166,
                mid_init$_39c7bd3c,
                mid_init$_4c9e2b1c,
                mid_init$_abdf2c51,
                mid_clear_54c6a166,
                mid_clone_846352c3,
                mid_contains_290588e2,
                mid_containsKey_290588e2,
                mid_containsValue_290588e2,
                mid_elements_39f88070,
                mid_entrySet_03e99967,
                mid_equals_290588e2,
                mid_get_a932a95f,
                mid_hashCode_54c6a179,
                mid_isEmpty_54c6a16a,
                mid_keySet_03e99967,
                mid_keys_39f88070,
                mid_put_537d5bdf,
                mid_putAll_4c9e2b1c,
                mid_remove_a932a95f,
                mid_size_54c6a179,
                mid_toString_14c7b5c5,
                mid_values_2d2d7de4,
                mid_rehash_54c6a166,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Hashtable(jobject obj) : ::java::util::Dictionary(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Hashtable(const Hashtable& obj) : ::java::util::Dictionary(obj) {}

            Hashtable();
            Hashtable(jint);
            Hashtable(const ::java::util::Map &);
            Hashtable(jint, jfloat);

            void clear() const;
            ::java::lang::Object clone() const;
            jboolean contains(const ::java::lang::Object &) const;
            jboolean containsKey(const ::java::lang::Object &) const;
            jboolean containsValue(const ::java::lang::Object &) const;
            ::java::util::Enumeration elements() const;
            ::java::util::Set entrySet() const;
            jboolean equals(const ::java::lang::Object &) const;
            ::java::lang::Object get(const ::java::lang::Object &) const;
            jint hashCode() const;
            jboolean isEmpty() const;
            ::java::util::Set keySet() const;
            ::java::util::Enumeration keys() const;
            ::java::lang::Object put(const ::java::lang::Object &, const ::java::lang::Object &) const;
            void putAll(const ::java::util::Map &) const;
            ::java::lang::Object remove(const ::java::lang::Object &) const;
            jint size() const;
            ::java::lang::String toString() const;
            ::java::util::Collection values() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(Hashtable);

        class t_Hashtable {
        public:
            PyObject_HEAD
            Hashtable object;
            PyTypeObject *parameters[2];
            static PyTypeObject **parameters_(t_Hashtable *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const Hashtable&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const Hashtable&, PyTypeObject *, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
