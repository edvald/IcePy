#ifndef is_iclt_icenlp_core_icetagger_IceFrequency_H
#define is_iclt_icenlp_core_icetagger_IceFrequency_H

#include "is/iclt/icenlp/core/utils/Lexicon.h"

namespace java {
    namespace lang {
        class String;
        class NullPointerException;
        class Class;
    }
    namespace io {
        class IOException;
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {

                    class IceFrequency : public ::is::iclt::icenlp::core::utils::Lexicon {
                    public:
                        enum {
                            mid_init$_5fdc3f48,
                            mid_init$_be2e4f90,
                            mid_getFrequency_5fdc3f57,
                            mid_maxFrequency_1034289b,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceFrequency(jobject obj) : ::is::iclt::icenlp::core::utils::Lexicon(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceFrequency(const IceFrequency& obj) : ::is::iclt::icenlp::core::utils::Lexicon(obj) {}

                        IceFrequency(const ::java::lang::String &);
                        IceFrequency(const ::java::io::InputStream &);

                        jint getFrequency(const ::java::lang::String &) const;
                        ::java::lang::String maxFrequency(const JArray< ::java::lang::String > &) const;
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
                    extern PyTypeObject PY_TYPE(IceFrequency);

                    class t_IceFrequency {
                    public:
                        PyObject_HEAD
                        IceFrequency object;
                        static PyObject *wrap_Object(const IceFrequency&);
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
