#ifndef is_iclt_icenlp_facade_TriTaggerFacade_H
#define is_iclt_icenlp_facade_TriTaggerFacade_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Lexicon;
                }
                namespace tritagger {
                    class TriTaggerLexicons;
                }
                namespace tokenizer {
                    class Sentences;
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
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {

                class TriTaggerFacade : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_init$_f4e26f98,
                        mid_tag_6359824b,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit TriTaggerFacade(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    TriTaggerFacade(const TriTaggerFacade& obj) : ::java::lang::Object(obj) {}

                    TriTaggerFacade();
                    TriTaggerFacade(const ::is::iclt::icenlp::core::tritagger::TriTaggerLexicons &, const ::is::iclt::icenlp::core::utils::Lexicon &);

                    ::is::iclt::icenlp::core::tokenizer::Sentences tag(const ::java::lang::String &) const;
                };
            }
        }
    }
}

#include <Python.h>

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {
                extern PyTypeObject PY_TYPE(TriTaggerFacade);

                class t_TriTaggerFacade {
                public:
                    PyObject_HEAD
                    TriTaggerFacade object;
                    static PyObject *wrap_Object(const TriTaggerFacade&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
