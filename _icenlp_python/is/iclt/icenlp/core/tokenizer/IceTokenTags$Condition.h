#ifndef is_iclt_icenlp_core_tokenizer_IceTokenTags$Condition_H
#define is_iclt_icenlp_core_tokenizer_IceTokenTags$Condition_H

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
                namespace tokenizer {

                    class IceTokenTags$Condition : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_9469d4f0,
                            mid_values_cf495cd2,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTokenTags$Condition(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTokenTags$Condition(const IceTokenTags$Condition& obj) : ::java::lang::Enum(obj) {}

                        static IceTokenTags$Condition *condAdjComp;
                        static IceTokenTags$Condition *condAdjIndeclineable;
                        static IceTokenTags$Condition *condAdjPositive;
                        static IceTokenTags$Condition *condAdjStrong;
                        static IceTokenTags$Condition *condAdjSuper;
                        static IceTokenTags$Condition *condAdjWeak;
                        static IceTokenTags$Condition *condAdverbComp;
                        static IceTokenTags$Condition *condAdverbSuper;
                        static IceTokenTags$Condition *condArticle;
                        static IceTokenTags$Condition *condCase;
                        static IceTokenTags$Condition *condHasGender;
                        static IceTokenTags$Condition *condOrdinal;
                        static IceTokenTags$Condition *condPronoun;
                        static IceTokenTags$Condition *condProperNoun;
                        static IceTokenTags$Condition *condVerbActive;
                        static IceTokenTags$Condition *condVerbAny;
                        static IceTokenTags$Condition *condVerbAux;
                        static IceTokenTags$Condition *condVerbBe;
                        static IceTokenTags$Condition *condVerbCaseMark;
                        static IceTokenTags$Condition *condVerbImperative;
                        static IceTokenTags$Condition *condVerbIndicative;
                        static IceTokenTags$Condition *condVerbInf;
                        static IceTokenTags$Condition *condVerbMiddle;
                        static IceTokenTags$Condition *condVerbPresentPart;
                        static IceTokenTags$Condition *condVerbSpecialAux;
                        static IceTokenTags$Condition *condVerbSpecialInf;
                        static IceTokenTags$Condition *condVerbSubjunctive;
                        static IceTokenTags$Condition *condVerbSupine;
                        static IceTokenTags$Condition *condWordClass;

                        static IceTokenTags$Condition valueOf(const ::java::lang::String &);
                        static JArray< IceTokenTags$Condition > values();
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
                namespace tokenizer {
                    extern PyTypeObject PY_TYPE(IceTokenTags$Condition);

                    class t_IceTokenTags$Condition {
                    public:
                        PyObject_HEAD
                        IceTokenTags$Condition object;
                        static PyObject *wrap_Object(const IceTokenTags$Condition&);
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
