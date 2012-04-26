#ifndef is_iclt_icenlp_core_iceparser_StringSearch_H
#define is_iclt_icenlp_core_iceparser_StringSearch_H

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
                namespace iceparser {

                    class StringSearch : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_splitString_71a6a0cc,
                            mid_splitString2_9c11957b,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit StringSearch(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        StringSearch(const StringSearch& obj) : ::java::lang::Object(obj) {}

                        static ::java::lang::String *firstString;
                        static ::java::lang::String *nextString;

                        StringSearch();

                        static jint splitString(const ::java::lang::String &, const ::java::lang::String &, jboolean, jint);
                        static jint splitString2(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &);
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
                namespace iceparser {
                    extern PyTypeObject PY_TYPE(StringSearch);

                    class t_StringSearch {
                    public:
                        PyObject_HEAD
                        StringSearch object;
                        static PyObject *wrap_Object(const StringSearch&);
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
