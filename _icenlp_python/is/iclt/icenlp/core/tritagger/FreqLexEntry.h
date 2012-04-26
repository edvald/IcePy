#ifndef is_iclt_icenlp_core_tritagger_FreqLexEntry_H
#define is_iclt_icenlp_core_tritagger_FreqLexEntry_H

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
                namespace tritagger {

                    class FreqLexEntry : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_6e53ccc6,
                            mid_getFrequency_54c6a179,
                            mid_getTag_14c7b5c5,
                            mid_setFrequency_39c7bd3c,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit FreqLexEntry(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        FreqLexEntry(const FreqLexEntry& obj) : ::java::lang::Object(obj) {}

                        FreqLexEntry(const ::java::lang::String &, jint);

                        jint getFrequency() const;
                        ::java::lang::String getTag() const;
                        void setFrequency(jint) const;
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
                namespace tritagger {
                    extern PyTypeObject PY_TYPE(FreqLexEntry);

                    class t_FreqLexEntry {
                    public:
                        PyObject_HEAD
                        FreqLexEntry object;
                        static PyObject *wrap_Object(const FreqLexEntry&);
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
