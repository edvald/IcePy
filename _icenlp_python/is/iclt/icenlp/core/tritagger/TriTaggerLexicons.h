#ifndef is_iclt_icenlp_core_tritagger_TriTaggerLexicons_H
#define is_iclt_icenlp_core_tritagger_TriTaggerLexicons_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tritagger {
                    class Ngrams;
                    class FreqLexicon;
                    class TriTaggerResources;
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
        class IOException;
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tritagger {

                    class TriTaggerLexicons : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_f3691645,
                            mid_init$_1aa7b2ce,
                            mid_init$_2555570e,
                            mid_init$_efbd1c95,
                            max_mid
                        };

                        enum {
                            fid_freqLexicon,
                            fid_ngrams,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit TriTaggerLexicons(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        TriTaggerLexicons(const TriTaggerLexicons& obj) : ::java::lang::Object(obj) {}

                        static ::java::lang::String *lambdaEnding;
                        static ::java::lang::String *lexEnding;
                        static ::java::lang::String *modelName;
                        static ::java::lang::String *modelPath;
                        static ::java::lang::String *ngramsEnding;

                        ::is::iclt::icenlp::core::tritagger::FreqLexicon _get_freqLexicon() const;
                        void _set_freqLexicon(const ::is::iclt::icenlp::core::tritagger::FreqLexicon &) const;
                        ::is::iclt::icenlp::core::tritagger::Ngrams _get_ngrams() const;
                        void _set_ngrams(const ::is::iclt::icenlp::core::tritagger::Ngrams &) const;

                        TriTaggerLexicons(const ::java::lang::String &, jboolean);
                        TriTaggerLexicons(const ::is::iclt::icenlp::core::tritagger::TriTaggerResources &, jboolean);
                        TriTaggerLexicons(const ::java::lang::String &, jboolean, jboolean);
                        TriTaggerLexicons(const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, jboolean);
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
                    extern PyTypeObject PY_TYPE(TriTaggerLexicons);

                    class t_TriTaggerLexicons {
                    public:
                        PyObject_HEAD
                        TriTaggerLexicons object;
                        static PyObject *wrap_Object(const TriTaggerLexicons&);
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
