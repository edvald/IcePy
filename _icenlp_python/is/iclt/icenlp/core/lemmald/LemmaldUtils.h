#ifndef is_iclt_icenlp_core_lemmald_LemmaldUtils_H
#define is_iclt_icenlp_core_lemmald_LemmaldUtils_H

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

                    class LemmaldUtils : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_applyMapping_aacea7e9,
                            mid_applyMapping_af6d27e3,
                            mid_createBestMapping_aacea7e9,
                            mid_firstVowel_5fdc3f57,
                            mid_getWordClass_97a5258f,
                            mid_isPunctuation_5fdc3f44,
                            mid_isVowel_87fd5456,
                            mid_isWordClass_5fdc3f44,
                            mid_lastVowel_5fdc3f57,
                            mid_print_5fdc3f48,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit LemmaldUtils(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        LemmaldUtils(const LemmaldUtils& obj) : ::java::lang::Object(obj) {}

                        LemmaldUtils();

                        static ::java::lang::String applyMapping(const ::java::lang::String &, const ::java::lang::String &);
                        static ::java::lang::String applyMapping(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &);
                        static ::java::lang::String createBestMapping(const ::java::lang::String &, const ::java::lang::String &);
                        static jint firstVowel(const ::java::lang::String &);
                        static ::java::lang::String getWordClass(const ::java::lang::String &);
                        static jboolean isPunctuation(const ::java::lang::String &);
                        static jboolean isVowel(jchar);
                        static jboolean isWordClass(const ::java::lang::String &);
                        static jint lastVowel(const ::java::lang::String &);
                        static void print(const ::java::lang::String &);
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
                    extern PyTypeObject PY_TYPE(LemmaldUtils);

                    class t_LemmaldUtils {
                    public:
                        PyObject_HEAD
                        LemmaldUtils object;
                        static PyObject *wrap_Object(const LemmaldUtils&);
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
