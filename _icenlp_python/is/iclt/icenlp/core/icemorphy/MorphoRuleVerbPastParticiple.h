#ifndef is_iclt_icenlp_core_icemorphy_MorphoRuleVerbPastParticiple_H
#define is_iclt_icenlp_core_icemorphy_MorphoRuleVerbPastParticiple_H

#include "is/iclt/icenlp/core/icemorphy/MorphoRuleVerbFinite.h"

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

                    class MorphoRuleVerbPastParticiple : public ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerbFinite {
                    public:
                        enum {
                            mid_init$_5b0ae4fd,
                            mid_init$_d1abb45a,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit MorphoRuleVerbPastParticiple(jobject obj) : ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerbFinite(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        MorphoRuleVerbPastParticiple(const MorphoRuleVerbPastParticiple& obj) : ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerbFinite(obj) {}

                        MorphoRuleVerbPastParticiple(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Mood &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Voice &, jchar, jchar, jchar, jchar, jboolean);
                        MorphoRuleVerbPastParticiple(const ::java::lang::String &, jint, const ::is::iclt::icenlp::core::icemorphy::IceMorphy$MorphoClass &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Mood &, const ::is::iclt::icenlp::core::icemorphy::MorphoRuleVerb$Voice &, jchar, jchar, jchar, jchar, jboolean, jboolean);
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
                    extern PyTypeObject PY_TYPE(MorphoRuleVerbPastParticiple);

                    class t_MorphoRuleVerbPastParticiple {
                    public:
                        PyObject_HEAD
                        MorphoRuleVerbPastParticiple object;
                        static PyObject *wrap_Object(const MorphoRuleVerbPastParticiple&);
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
