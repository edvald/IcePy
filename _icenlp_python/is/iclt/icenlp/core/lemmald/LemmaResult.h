#ifndef is_iclt_icenlp_core_lemmald_LemmaResult_H
#define is_iclt_icenlp_core_lemmald_LemmaResult_H

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

                    class LemmaResult : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_55e0e853,
                            mid_getLemma_14c7b5c5,
                            mid_getMessage_14c7b5c5,
                            mid_getTag_14c7b5c5,
                            mid_getWordForm_14c7b5c5,
                            mid_getWordId_14c7b5c5,
                            mid_isSuccess_54c6a16a,
                            mid_setLemma_5fdc3f48,
                            mid_setMessage_5fdc3f48,
                            mid_setSuccess_bb0c767f,
                            mid_setTag_5fdc3f48,
                            mid_setWordForm_5fdc3f48,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit LemmaResult(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        LemmaResult(const LemmaResult& obj) : ::java::lang::Object(obj) {}

                        LemmaResult(const ::java::lang::String &, const ::java::lang::String &, jboolean);

                        ::java::lang::String getLemma() const;
                        ::java::lang::String getMessage() const;
                        ::java::lang::String getTag() const;
                        ::java::lang::String getWordForm() const;
                        ::java::lang::String getWordId() const;
                        jboolean isSuccess() const;
                        void setLemma(const ::java::lang::String &) const;
                        void setMessage(const ::java::lang::String &) const;
                        void setSuccess(jboolean) const;
                        void setTag(const ::java::lang::String &) const;
                        void setWordForm(const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(LemmaResult);

                    class t_LemmaResult {
                    public:
                        PyObject_HEAD
                        LemmaResult object;
                        static PyObject *wrap_Object(const LemmaResult&);
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
