#ifndef is_iclt_icenlp_core_tokenizer_IceTokenTags$SVOMark_H
#define is_iclt_icenlp_core_tokenizer_IceTokenTags$SVOMark_H

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

                    class IceTokenTags$SVOMark : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_92643338,
                            mid_values_fe9190da,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTokenTags$SVOMark(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTokenTags$SVOMark(const IceTokenTags$SVOMark& obj) : ::java::lang::Enum(obj) {}

                        static IceTokenTags$SVOMark *svoMainSubject;
                        static IceTokenTags$SVOMark *svoMainVerb;
                        static IceTokenTags$SVOMark *svoNone;
                        static IceTokenTags$SVOMark *svoObject;
                        static IceTokenTags$SVOMark *svoPrepPhrase;
                        static IceTokenTags$SVOMark *svoSubject;
                        static IceTokenTags$SVOMark *svoVerb;

                        static IceTokenTags$SVOMark valueOf(const ::java::lang::String &);
                        static JArray< IceTokenTags$SVOMark > values();
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
                    extern PyTypeObject PY_TYPE(IceTokenTags$SVOMark);

                    class t_IceTokenTags$SVOMark {
                    public:
                        PyObject_HEAD
                        IceTokenTags$SVOMark object;
                        static PyObject *wrap_Object(const IceTokenTags$SVOMark&);
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
