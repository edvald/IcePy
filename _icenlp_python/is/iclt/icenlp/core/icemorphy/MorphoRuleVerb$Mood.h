#ifndef is_iclt_icenlp_core_icemorphy_MorphoRuleVerb$Mood_H
#define is_iclt_icenlp_core_icemorphy_MorphoRuleVerb$Mood_H

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

                    class MorphoRuleVerb$Mood : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_e55c4a17,
                            mid_values_f92252f5,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit MorphoRuleVerb$Mood(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        MorphoRuleVerb$Mood(const MorphoRuleVerb$Mood& obj) : ::java::lang::Enum(obj) {}

                        static MorphoRuleVerb$Mood *Imperative;
                        static MorphoRuleVerb$Mood *Indicative;
                        static MorphoRuleVerb$Mood *IndicativeSubjunctive;
                        static MorphoRuleVerb$Mood *Infinitive;
                        static MorphoRuleVerb$Mood *Subjunctive;

                        static MorphoRuleVerb$Mood valueOf(const ::java::lang::String &);
                        static JArray< MorphoRuleVerb$Mood > values();
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
                    extern PyTypeObject PY_TYPE(MorphoRuleVerb$Mood);

                    class t_MorphoRuleVerb$Mood {
                    public:
                        PyObject_HEAD
                        MorphoRuleVerb$Mood object;
                        static PyObject *wrap_Object(const MorphoRuleVerb$Mood&);
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
