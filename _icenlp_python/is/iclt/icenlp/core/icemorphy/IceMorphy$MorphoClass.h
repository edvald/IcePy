#ifndef is_iclt_icenlp_core_icemorphy_IceMorphy$MorphoClass_H
#define is_iclt_icenlp_core_icemorphy_IceMorphy$MorphoClass_H

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

                    class IceMorphy$MorphoClass : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_ebdab811,
                            mid_values_a2c2c6c7,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceMorphy$MorphoClass(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceMorphy$MorphoClass(const IceMorphy$MorphoClass& obj) : ::java::lang::Enum(obj) {}

                        static IceMorphy$MorphoClass *Adj1;
                        static IceMorphy$MorphoClass *Adj2;
                        static IceMorphy$MorphoClass *Adj3;
                        static IceMorphy$MorphoClass *Adj4;
                        static IceMorphy$MorphoClass *Adj5;
                        static IceMorphy$MorphoClass *None;
                        static IceMorphy$MorphoClass *NounFeminine1;
                        static IceMorphy$MorphoClass *NounFeminine2;
                        static IceMorphy$MorphoClass *NounFeminine3;
                        static IceMorphy$MorphoClass *NounFeminine4;
                        static IceMorphy$MorphoClass *NounFeminine5;
                        static IceMorphy$MorphoClass *NounFeminine6;
                        static IceMorphy$MorphoClass *NounMasculine1;
                        static IceMorphy$MorphoClass *NounMasculine10;
                        static IceMorphy$MorphoClass *NounMasculine2;
                        static IceMorphy$MorphoClass *NounMasculine3;
                        static IceMorphy$MorphoClass *NounMasculine4;
                        static IceMorphy$MorphoClass *NounMasculine5;
                        static IceMorphy$MorphoClass *NounMasculine6;
                        static IceMorphy$MorphoClass *NounMasculine7;
                        static IceMorphy$MorphoClass *NounMasculine8;
                        static IceMorphy$MorphoClass *NounMasculine9;
                        static IceMorphy$MorphoClass *NounNeuter1;
                        static IceMorphy$MorphoClass *NounNeuter2;
                        static IceMorphy$MorphoClass *NounNeuter3;
                        static IceMorphy$MorphoClass *NounNeuter4;
                        static IceMorphy$MorphoClass *VerbActive1;
                        static IceMorphy$MorphoClass *VerbActive2;
                        static IceMorphy$MorphoClass *VerbActive3;
                        static IceMorphy$MorphoClass *VerbActive4;
                        static IceMorphy$MorphoClass *VerbActive5;
                        static IceMorphy$MorphoClass *VerbActive6;
                        static IceMorphy$MorphoClass *VerbMiddle1;
                        static IceMorphy$MorphoClass *VerbMiddle2;

                        static IceMorphy$MorphoClass valueOf(const ::java::lang::String &);
                        static JArray< IceMorphy$MorphoClass > values();
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
                    extern PyTypeObject PY_TYPE(IceMorphy$MorphoClass);

                    class t_IceMorphy$MorphoClass {
                    public:
                        PyObject_HEAD
                        IceMorphy$MorphoClass object;
                        static PyObject *wrap_Object(const IceMorphy$MorphoClass&);
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
