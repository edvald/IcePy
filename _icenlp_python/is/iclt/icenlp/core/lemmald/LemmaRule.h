#ifndef is_iclt_icenlp_core_lemmald_LemmaRule_H
#define is_iclt_icenlp_core_lemmald_LemmaRule_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {

                    class LemmaRule : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_6e53ccc6,
                            mid_applyTo_97a5258f,
                            mid_getMapping_14c7b5c5,
                            mid_getMappingFrom_14c7b5c5,
                            mid_getMappingTo_14c7b5c5,
                            mid_getSuccessRate_54c6a179,
                            mid_setMapping_5fdc3f48,
                            mid_setSuccessRate_39c7bd3c,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit LemmaRule(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        LemmaRule(const LemmaRule& obj) : ::java::lang::Object(obj) {}

                        LemmaRule(const ::java::lang::String &, jint);

                        ::java::lang::String applyTo(const ::java::lang::String &) const;
                        ::java::lang::String getMapping() const;
                        ::java::lang::String getMappingFrom() const;
                        ::java::lang::String getMappingTo() const;
                        jint getSuccessRate() const;
                        void setMapping(const ::java::lang::String &) const;
                        void setSuccessRate(jint) const;
                    };
                }
            }
        }
    }
}

#include <Python.h>

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {
                    extern PyTypeObject PY_TYPE(LemmaRule);

                    class t_LemmaRule {
                    public:
                        PyObject_HEAD
                        LemmaRule object;
                        static PyObject *wrap_Object(const LemmaRule&);
                        static PyObject *wrap_jobject(const jobject&);
                        static void install(PyObject *module);
                        static void initialize(PyObject *module);
                    };
                }
            }
        }
    }
}

#endif
