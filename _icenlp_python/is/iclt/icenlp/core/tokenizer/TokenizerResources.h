#ifndef is_iclt_icenlp_core_tokenizer_TokenizerResources_H
#define is_iclt_icenlp_core_tokenizer_TokenizerResources_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
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
                namespace tokenizer {

                    class TokenizerResources : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            max_mid
                        };

                        enum {
                            fid_isLexicon,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit TokenizerResources(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        TokenizerResources(const TokenizerResources& obj) : ::java::lang::Object(obj) {}

                        ::java::io::InputStream _get_isLexicon() const;
                        void _set_isLexicon(const ::java::io::InputStream &) const;

                        TokenizerResources();
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
                namespace tokenizer {
                    extern PyTypeObject PY_TYPE(TokenizerResources);

                    class t_TokenizerResources {
                    public:
                        PyObject_HEAD
                        TokenizerResources object;
                        static PyObject *wrap_Object(const TokenizerResources&);
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
