#ifndef is_iclt_icenlp_core_tokenizer_IceTokenTags$UnknownType_H
#define is_iclt_icenlp_core_tokenizer_IceTokenTags$UnknownType_H

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

                    class IceTokenTags$UnknownType : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_65d2bc21,
                            mid_values_4ef5d6c7,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTokenTags$UnknownType(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTokenTags$UnknownType(const IceTokenTags$UnknownType& obj) : ::java::lang::Enum(obj) {}

                        static IceTokenTags$UnknownType *ending;
                        static IceTokenTags$UnknownType *guessed;
                        static IceTokenTags$UnknownType *morpho;
                        static IceTokenTags$UnknownType *none;
                        static IceTokenTags$UnknownType *properNoun;

                        static IceTokenTags$UnknownType valueOf(const ::java::lang::String &);
                        static JArray< IceTokenTags$UnknownType > values();
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
                    extern PyTypeObject PY_TYPE(IceTokenTags$UnknownType);

                    class t_IceTokenTags$UnknownType {
                    public:
                        PyObject_HEAD
                        IceTokenTags$UnknownType object;
                        static PyObject *wrap_Object(const IceTokenTags$UnknownType&);
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
