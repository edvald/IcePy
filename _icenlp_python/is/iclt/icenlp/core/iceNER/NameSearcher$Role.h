#ifndef is_iclt_icenlp_core_iceNER_NameSearcher$Role_H
#define is_iclt_icenlp_core_iceNER_NameSearcher$Role_H

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
                namespace iceNER {

                    class NameSearcher$Role : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_toRole_71411865,
                            mid_valueOf_71411865,
                            mid_values_429eaf57,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit NameSearcher$Role(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        NameSearcher$Role(const NameSearcher$Role& obj) : ::java::lang::Enum(obj) {}

                        static NameSearcher$Role *NOVALUE;
                        static NameSearcher$Role *RELATION_PERSON;
                        static NameSearcher$Role *ROLE_COMPANY;
                        static NameSearcher$Role *ROLE_EVENT;
                        static NameSearcher$Role *ROLE_LOCATION;
                        static NameSearcher$Role *ROLE_PERSON;

                        static NameSearcher$Role toRole(const ::java::lang::String &);
                        static NameSearcher$Role valueOf(const ::java::lang::String &);
                        static JArray< NameSearcher$Role > values();
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
                namespace iceNER {
                    extern PyTypeObject PY_TYPE(NameSearcher$Role);

                    class t_NameSearcher$Role {
                    public:
                        PyObject_HEAD
                        NameSearcher$Role object;
                        static PyObject *wrap_Object(const NameSearcher$Role&);
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
