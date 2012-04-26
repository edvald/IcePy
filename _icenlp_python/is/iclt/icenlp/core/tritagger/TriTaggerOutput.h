#ifndef is_iclt_icenlp_core_tritagger_TriTaggerOutput_H
#define is_iclt_icenlp_core_tritagger_TriTaggerOutput_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {
                    class TokenTags;
                }
            }
        }
    }
}
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

                    class TriTaggerOutput : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_39c7bd3c,
                            mid_buildOutput_8d34d1cd,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit TriTaggerOutput(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        TriTaggerOutput(const TriTaggerOutput& obj) : ::java::lang::Object(obj) {}

                        TriTaggerOutput(jint);

                        ::java::lang::String buildOutput(const ::is::iclt::icenlp::core::tokenizer::TokenTags &, jint, jint) const;
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
                    extern PyTypeObject PY_TYPE(TriTaggerOutput);

                    class t_TriTaggerOutput {
                    public:
                        PyObject_HEAD
                        TriTaggerOutput object;
                        static PyObject *wrap_Object(const TriTaggerOutput&);
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
