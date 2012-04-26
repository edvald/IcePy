#ifndef is_iclt_icenlp_core_icemorphy_MorphoRuleVerbFinite_H
#define is_iclt_icenlp_core_icemorphy_MorphoRuleVerbFinite_H

#include "is/iclt/icenlp/core/icemorphy/MorphoRuleVerb.h"

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

                    class MorphoRuleVerbFinite : public ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb {
                    public:
                        enum {
                            mid_init$_8f0e2a90,
                            mid_init$_66cab6fd,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit MorphoRuleVerbFinite(jobject obj) : ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        MorphoRuleVerbFinite(const MorphoRuleVerbFinite& obj) : ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb(obj) {}

                        MorphoRuleVerbFinite(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Mood &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Voice &, jchar, jchar, jchar, jchar, jchar);
                        MorphoRuleVerbFinite(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Mood &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Voice &, jchar, jchar, jchar, jchar, jchar, jboolean);
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
                    extern PyTypeObject PY_TYPE(MorphoRuleVerbFinite);

                    class t_MorphoRuleVerbFinite {
                    public:
                        PyObject_HEAD
                        MorphoRuleVerbFinite object;
                        static PyObject *wrap_Object(const MorphoRuleVerbFinite&);
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
