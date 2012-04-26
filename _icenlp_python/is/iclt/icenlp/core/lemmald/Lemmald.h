#ifndef is_iclt_icenlp_core_lemmald_Lemmald_H
#define is_iclt_icenlp_core_lemmald_Lemmald_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {
                        class TaggedText;
                    }
                }
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
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {

                    class Lemmald : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_4a264742,
                            mid_getInstance_b3151502,
                            mid_lemmatize_79d992ab,
                            mid_lemmatizeTagged_37274943,
                            mid_lemmatizeText_cb9f349c,
                            mid_newInstance_b3151502,
                            mid_terminate_54c6a166,
                            mid_createRuleIds_1034579c,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Lemmald(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Lemmald(const Lemmald& obj) : ::java::lang::Object(obj) {}

                        Lemmald();
                        Lemmald(const ::java::lang::String &, const ::java::lang::String &);

                        static Lemmald getInstance();
                        ::is::iclt::icenlp::core::lemmald::LemmaResult lemmatize(const ::java::lang::String &, const ::java::lang::String &) const;
                        void lemmatizeTagged(const ::is::iclt::icenlp::core::formald::tags::TaggedText &) const;
                        ::is::iclt::icenlp::core::formald::tags::TaggedText lemmatizeText(const ::java::lang::String &) const;
                        static Lemmald newInstance();
                        static void terminate();
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
                    extern PyTypeObject PY_TYPE(Lemmald);

                    class t_Lemmald {
                    public:
                        PyObject_HEAD
                        Lemmald object;
                        static PyObject *wrap_Object(const Lemmald&);
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
