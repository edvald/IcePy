#ifndef is_iclt_icenlp_core_icemorphy_MorphoRule_H
#define is_iclt_icenlp_core_icemorphy_MorphoRule_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icemorphy {
                    class IceMorphy$MorphoClass;
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
                namespace icemorphy {

                    class MorphoRule : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_1bb6441e,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit MorphoRule(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        MorphoRule(const MorphoRule& obj) : ::java::lang::Object(obj) {}

                        MorphoRule();
                        MorphoRule(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &);
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
                namespace icemorphy {
                    extern PyTypeObject PY_TYPE(MorphoRule);

                    class t_MorphoRule {
                    public:
                        PyObject_HEAD
                        MorphoRule object;
                        static PyObject *wrap_Object(const MorphoRule&);
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
