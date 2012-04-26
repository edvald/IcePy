#ifndef is_iclt_icenlp_runner_RunIceMorphy_H
#define is_iclt_icenlp_runner_RunIceMorphy_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icemorphy {
                    class IceMorphy;
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

                class RunIceMorphy : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_generateMissingTags_de9b100f,
                        mid_main_4dd4540c,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit RunIceMorphy(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    RunIceMorphy(const RunIceMorphy& obj) : ::java::lang::Object(obj) {}

                    RunIceMorphy();

                    void generateMissingTags(const ::java::lang::String &, const ::java::lang::String &, const ::is::iclt::icenlp::core::icemorphy::IceMorphy &, const ::java::lang::String &, const ::java::lang::String &) const;
                    static void main(const JArray< ::java::lang::String > &);
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
                extern PyTypeObject PY_TYPE(RunIceMorphy);

                class t_RunIceMorphy {
                public:
                    PyObject_HEAD
                    RunIceMorphy object;
                    static PyObject *wrap_Object(const RunIceMorphy&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
