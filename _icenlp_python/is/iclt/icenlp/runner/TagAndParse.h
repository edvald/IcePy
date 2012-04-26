#ifndef is_iclt_icenlp_runner_TagAndParse_H
#define is_iclt_icenlp_runner_TagAndParse_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
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
            namespace runner {

                class TagAndParse : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_init$_bb0c767f,
                        mid_main_4dd4540c,
                        mid_tagText_6359824b,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit TagAndParse(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    TagAndParse(const TagAndParse& obj) : ::java::lang::Object(obj) {}

                    TagAndParse();
                    TagAndParse(jboolean);

                    static void main(const JArray< ::java::lang::String > &);
                    ::is::iclt::icenlp::core::tokenizer::Sentences tagText(const ::java::lang::String &) const;
                };
            }
        }
    }
}

#include <Python.h>

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace runner {
                extern PyTypeObject PY_TYPE(TagAndParse);

                class t_TagAndParse {
                public:
                    PyObject_HEAD
                    TagAndParse object;
                    static PyObject *wrap_Object(const TagAndParse&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
