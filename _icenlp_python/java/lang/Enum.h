#ifndef java_lang_Enum_H
#define java_lang_Enum_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Comparable;
        class Class;
        class String;
    }
    namespace io {
        class Serializable;
    }
}
template<class T> class JArray;

namespace java {
    namespace lang {

        class Enum : public ::java::lang::Object {
        public:
            enum {
                mid_compareTo_618aa849,
                mid_compareTo_290588f1,
                mid_equals_290588e2,
                mid_getDeclaringClass_44a5f2c9,
                mid_hashCode_54c6a179,
                mid_name_14c7b5c5,
                mid_ordinal_54c6a179,
                mid_toString_14c7b5c5,
                mid_valueOf_46e8491f,
                mid_finalize_54c6a166,
                mid_clone_846352c3,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Enum(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Enum(const Enum& obj) : ::java::lang::Object(obj) {}

            jint compareTo(const Enum &) const;
            jint compareTo(const ::java::lang::Object &) const;
            jboolean equals(const ::java::lang::Object &) const;
            ::java::lang::Class getDeclaringClass() const;
            jint hashCode() const;
            ::java::lang::String name() const;
            jint ordinal() const;
            ::java::lang::String toString() const;
            static Enum valueOf(const ::java::lang::Class &, const ::java::lang::String &);
        };
    }
}

#include <Python.h>

namespace java {
    namespace lang {
        extern PyTypeObject PY_TYPE(Enum);

        class t_Enum {
        public:
            PyObject_HEAD
            Enum object;
            PyTypeObject *parameters[1];
            static PyTypeObject **parameters_(t_Enum *self)
            {
                return (PyTypeObject **) &(self->parameters);
            }
            static PyObject *wrap_Object(const Enum&);
            static PyObject *wrap_jobject(const jobject&);
            static PyObject *wrap_Object(const Enum&, PyTypeObject *);
            static PyObject *wrap_jobject(const jobject&, PyTypeObject *);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
