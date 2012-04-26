#ifndef is_iclt_icenlp_core_icemorphy_MorphoRuleNounAdjective_H
#define is_iclt_icenlp_core_icemorphy_MorphoRuleNounAdjective_H

#include "is/iclt/icenlp/core/icemorphy/MorphoRule.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class IceTag$WordClass;
                }
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

                    class MorphoRuleNounAdjective : public ::is::iclt::icenlp::core::icemorphy::MorphoRule {
                    public:
                        enum {
                            mid_init$_a96b4742,
                            mid_init$_ca3dbd90,
                            mid_init$_e7fdcd01,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit MorphoRuleNounAdjective(jobject obj) : ::is::iclt::icenlp::core::icemorphy::MorphoRule(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        MorphoRuleNounAdjective(const MorphoRuleNounAdjective& obj) : ::is::iclt::icenlp::core::icemorphy::MorphoRule(obj) {}

                        MorphoRuleNounAdjective(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &, jboolean, jboolean, jboolean, jboolean, jchar, jchar);
                        MorphoRuleNounAdjective(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &, const ::is::iclt::icenlp::core::utils::IceTag$WordClass &, jboolean, jboolean, jboolean, jboolean, jchar, jchar, jchar);
                        MorphoRuleNounAdjective(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &, const ::is::iclt::icenlp::core::utils::IceTag$WordClass &, jboolean, jboolean, jboolean, jboolean, jchar, jchar, jchar, jboolean);
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
                    extern PyTypeObject PY_TYPE(MorphoRuleNounAdjective);

                    class t_MorphoRuleNounAdjective {
                    public:
                        PyObject_HEAD
                        MorphoRuleNounAdjective object;
                        static PyObject *wrap_Object(const MorphoRuleNounAdjective&);
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
