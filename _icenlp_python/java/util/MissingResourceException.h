#ifndef java_util_MissingResourceException_H
#define java_util_MissingResourceException_H

#include "java/lang/RuntimeException.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class MissingResourceException : public ::java::lang::RuntimeException {
        public:
            enum {
                mid_init$_9c119564,
                mid_getClassName_14c7b5c5,
                mid_getKey_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit MissingResourceException(jobject obj) : ::java::lang::RuntimeException(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            MissingResourceException(const MissingResourceException& obj) : ::java::lang::RuntimeException(obj) {}

            MissingResourceException(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &);

            ::java::lang::String getClassName() const;
            ::java::lang::String getKey() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(MissingResourceException);

        class t_MissingResourceException {
        public:
            PyObject_HEAD
            MissingResourceException object;
            static PyObject *wrap_Object(const MissingResourceException&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
