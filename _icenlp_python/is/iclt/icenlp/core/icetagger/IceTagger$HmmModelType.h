#ifndef is_iclt_icenlp_core_icetagger_IceTagger$HmmModelType_H
#define is_iclt_icenlp_core_icetagger_IceTagger$HmmModelType_H

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
                namespace icetagger {

                    class IceTagger$HmmModelType : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_321d7bf4,
                            mid_values_7e2769ba,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTagger$HmmModelType(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTagger$HmmModelType(const IceTagger$HmmModelType& obj) : ::java::lang::Enum(obj) {}

                        static IceTagger$HmmModelType *end;
                        static IceTagger$HmmModelType *none;
                        static IceTagger$HmmModelType *start;
                        static IceTagger$HmmModelType *startend;

                        static IceTagger$HmmModelType valueOf(const ::java::lang::String &);
                        static JArray< IceTagger$HmmModelType > values();
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
                namespace icetagger {
                    extern PyTypeObject PY_TYPE(IceTagger$HmmModelType);

                    class t_IceTagger$HmmModelType {
                    public:
                        PyObject_HEAD
                        IceTagger$HmmModelType object;
                        static PyObject *wrap_Object(const IceTagger$HmmModelType&);
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
