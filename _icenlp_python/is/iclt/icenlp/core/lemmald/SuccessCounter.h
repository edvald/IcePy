#ifndef is_iclt_icenlp_core_lemmald_SuccessCounter_H
#define is_iclt_icenlp_core_lemmald_SuccessCounter_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {

                    class SuccessCounter : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_getCorrect_54c6a179,
                            mid_getTotal_54c6a179,
                            mid_getWrong_54c6a179,
                            mid_increment_bb0c767f,
                            mid_incrementCorrect_54c6a166,
                            mid_incrementWrong_54c6a166,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit SuccessCounter(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        SuccessCounter(const SuccessCounter& obj) : ::java::lang::Object(obj) {}

                        SuccessCounter();

                        jint getCorrect() const;
                        jint getTotal() const;
                        jint getWrong() const;
                        void increment(jboolean) const;
                        void incrementCorrect() const;
                        void incrementWrong() const;
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
                    extern PyTypeObject PY_TYPE(SuccessCounter);

                    class t_SuccessCounter {
                    public:
                        PyObject_HEAD
                        SuccessCounter object;
                        static PyObject *wrap_Object(const SuccessCounter&);
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
