#ifndef is_iclt_icenlp_core_utils_IceTag$WordClass_H
#define is_iclt_icenlp_core_utils_IceTag$WordClass_H

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
                namespace utils {

                    class IceTag$WordClass : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_0c08f7cb,
                            mid_values_6cfe09b9,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTag$WordClass(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTag$WordClass(const IceTag$WordClass& obj) : ::java::lang::Enum(obj) {}

                        static IceTag$WordClass *wcAdj;
                        static IceTag$WordClass *wcAdverb;
                        static IceTag$WordClass *wcArticle;
                        static IceTag$WordClass *wcConj;
                        static IceTag$WordClass *wcConjRel;
                        static IceTag$WordClass *wcDemPronoun;
                        static IceTag$WordClass *wcExcl;
                        static IceTag$WordClass *wcForeign;
                        static IceTag$WordClass *wcIndefPronoun;
                        static IceTag$WordClass *wcInf;
                        static IceTag$WordClass *wcIntPronoun;
                        static IceTag$WordClass *wcNoun;
                        static IceTag$WordClass *wcNumeral;
                        static IceTag$WordClass *wcPersPronoun;
                        static IceTag$WordClass *wcPossPronoun;
                        static IceTag$WordClass *wcPrep;
                        static IceTag$WordClass *wcPronoun;
                        static IceTag$WordClass *wcProperNoun;
                        static IceTag$WordClass *wcPunct;
                        static IceTag$WordClass *wcReflPronoun;
                        static IceTag$WordClass *wcRelativePronoun;
                        static IceTag$WordClass *wcUndef;
                        static IceTag$WordClass *wcVerb;
                        static IceTag$WordClass *wcVerbInf;
                        static IceTag$WordClass *wcVerbPastPart;

                        static IceTag$WordClass valueOf(const ::java::lang::String &);
                        static JArray< IceTag$WordClass > values();
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
                namespace utils {
                    extern PyTypeObject PY_TYPE(IceTag$WordClass);

                    class t_IceTag$WordClass {
                    public:
                        PyObject_HEAD
                        IceTag$WordClass object;
                        static PyObject *wrap_Object(const IceTag$WordClass&);
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
