#ifndef is_iclt_icenlp_core_icemorphy_MorphoRuleVerb_H
#define is_iclt_icenlp_core_icemorphy_MorphoRuleVerb_H

#include "is/iclt/icenlp/core/icemorphy/MorphoRule.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icemorphy {
                    class IceMorphy$MorphoClass;
                    class MorphoRuleVerb$Voice;
                    class MorphoRuleVerb$Mood;
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

                    class MorphoRuleVerb : public ::is::iclt::icenlp::core::icemorphy::MorphoRule {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_7d3c0178,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit MorphoRuleVerb(jobject obj) : ::is::iclt::icenlp::core::icemorphy::MorphoRule(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        MorphoRuleVerb(const MorphoRuleVerb& obj) : ::is::iclt::icenlp::core::icemorphy::MorphoRule(obj) {}

                        MorphoRuleVerb();
                        MorphoRuleVerb(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Mood &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Voice &, jchar);
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
                    extern PyTypeObject PY_TYPE(MorphoRuleVerb);

                    class t_MorphoRuleVerb {
                    public:
                        PyObject_HEAD
                        MorphoRuleVerb object;
                        static PyObject *wrap_Object(const MorphoRuleVerb&);
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
