#ifndef is_iclt_icenlp_core_tokenizer_IceTokenTags$Match_H
#define is_iclt_icenlp_core_tokenizer_IceTokenTags$Match_H

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

                    class IceTokenTags$Match : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_d10e5240,
                            mid_values_398b45be,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTokenTags$Match(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTokenTags$Match(const IceTokenTags$Match& obj) : ::java::lang::Enum(obj) {}

                        static IceTokenTags$Match *aCase;
                        static IceTokenTags$Match *gender;
                        static IceTokenTags$Match *genderNumberCase;
                        static IceTokenTags$Match *number;
                        static IceTokenTags$Match *numberCase;
                        static IceTokenTags$Match *personGenderNumber;

                        static IceTokenTags$Match valueOf(const ::java::lang::String &);
                        static JArray< IceTokenTags$Match > values();
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
                    extern PyTypeObject PY_TYPE(IceTokenTags$Match);

                    class t_IceTokenTags$Match {
                    public:
                        PyObject_HEAD
                        IceTokenTags$Match object;
                        static PyObject *wrap_Object(const IceTokenTags$Match&);
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
