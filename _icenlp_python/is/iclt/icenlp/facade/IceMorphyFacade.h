#ifndef is_iclt_icenlp_facade_IceMorphyFacade_H
#define is_iclt_icenlp_facade_IceMorphyFacade_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Lexicon;
                }
                namespace icemorphy {
                    class IceMorphyLexicons;
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

                class IceMorphyFacade : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_dc42a542,
                        mid_analyze_6359824b,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit IceMorphyFacade(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    IceMorphyFacade(const IceMorphyFacade& obj) : ::java::lang::Object(obj) {}

                    IceMorphyFacade(const ::is::iclt::icenlp::core::icemorphy::IceMorphyLexicons &, const ::is::iclt::icenlp::core::utils::Lexicon &, jint);

                    ::is::iclt::icenlp::core::tokenizer::Sentences analyze(const ::java::lang::String &) const;
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
                extern PyTypeObject PY_TYPE(IceMorphyFacade);

                class t_IceMorphyFacade {
                public:
                    PyObject_HEAD
                    IceMorphyFacade object;
                    static PyObject *wrap_Object(const IceMorphyFacade&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
