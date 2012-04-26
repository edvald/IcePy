#ifndef is_iclt_icenlp_core_lemmald_LemmaWord_H
#define is_iclt_icenlp_core_lemmald_LemmaWord_H

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

                    class LemmaWord : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_9c119564,
                            mid_equals_290588e2,
                            mid_getLemma_14c7b5c5,
                            mid_getTag_14c7b5c5,
                            mid_getWordForm_14c7b5c5,
                            mid_setLemma_5fdc3f48,
                            mid_setTag_5fdc3f48,
                            mid_setWordForm_5fdc3f48,
                            mid_toString_14c7b5c5,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit LemmaWord(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        LemmaWord(const LemmaWord& obj) : ::java::lang::Object(obj) {}

                        LemmaWord(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &);

                        jboolean equals(const ::java::lang::Object &) const;
                        ::java::lang::String getLemma() const;
                        ::java::lang::String getTag() const;
                        ::java::lang::String getWordForm() const;
                        void setLemma(const ::java::lang::String &) const;
                        void setTag(const ::java::lang::String &) const;
                        void setWordForm(const ::java::lang::String &) const;
                        ::java::lang::String toString() const;
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
                    extern PyTypeObject PY_TYPE(LemmaWord);

                    class t_LemmaWord {
                    public:
                        PyObject_HEAD
                        LemmaWord object;
                        static PyObject *wrap_Object(const LemmaWord&);
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
