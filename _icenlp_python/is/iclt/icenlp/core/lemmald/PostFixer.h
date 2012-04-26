#ifndef is_iclt_icenlp_core_lemmald_PostFixer_H
#define is_iclt_icenlp_core_lemmald_PostFixer_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {
                    class LemmaResult;
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
    namespace io {
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {

                    class PostFixer : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_loadPostfixRules_be2e4f90,
                            mid_loadPostfixRules_5fdc3f48,
                            mid_postfix_56a7972e,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit PostFixer(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        PostFixer(const PostFixer& obj) : ::java::lang::Object(obj) {}

                        PostFixer();

                        static void loadPostfixRules(const ::java::io::InputStream &);
                        static void loadPostfixRules(const ::java::lang::String &);
                        static void postfix(const ::is::iclt::icenlp::core::lemmald::LemmaResult &);
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
                    extern PyTypeObject PY_TYPE(PostFixer);

                    class t_PostFixer {
                    public:
                        PyObject_HEAD
                        PostFixer object;
                        static PyObject *wrap_Object(const PostFixer&);
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
