#ifndef is_iclt_icenlp_core_icemorphy_MorphoRuleVerb$Voice_H
#define is_iclt_icenlp_core_icemorphy_MorphoRuleVerb$Voice_H

#include "java/lang/Enum.h"

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

                    class MorphoRuleVerb$Voice : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_195d74f1,
                            mid_values_b2aa1e5f,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit MorphoRuleVerb$Voice(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        MorphoRuleVerb$Voice(const MorphoRuleVerb$Voice& obj) : ::java::lang::Enum(obj) {}

                        static MorphoRuleVerb$Voice *Active;
                        static MorphoRuleVerb$Voice *Middle;

                        static MorphoRuleVerb$Voice valueOf(const ::java::lang::String &);
                        static JArray< MorphoRuleVerb$Voice > values();
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
                    extern PyTypeObject PY_TYPE(MorphoRuleVerb$Voice);

                    class t_MorphoRuleVerb$Voice {
                    public:
                        PyObject_HEAD
                        MorphoRuleVerb$Voice object;
                        static PyObject *wrap_Object(const MorphoRuleVerb$Voice&);
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
