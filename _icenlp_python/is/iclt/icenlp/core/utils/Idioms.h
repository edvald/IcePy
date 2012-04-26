#ifndef is_iclt_icenlp_core_utils_Idioms_H
#define is_iclt_icenlp_core_utils_Idioms_H

#include "is/iclt/icenlp/core/utils/Lexicon.h"

namespace java {
    namespace util {
        class ArrayList;
    }
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
                namespace utils {

                    class Idioms : public ::is::iclt::icenlp::core::utils::Lexicon {
                    public:
                        enum {
                            mid_init$_5fdc3f48,
                            mid_init$_be2e4f90,
                            mid_findIdioms_b3f662f9,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Idioms(jobject obj) : ::is::iclt::icenlp::core::utils::Lexicon(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Idioms(const Idioms& obj) : ::is::iclt::icenlp::core::utils::Lexicon(obj) {}

                        Idioms(const ::java::lang::String &);
                        Idioms(const ::java::io::InputStream &);

                        void findIdioms(const ::java::util::ArrayList &) const;
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
                    extern PyTypeObject PY_TYPE(Idioms);

                    class t_Idioms {
                    public:
                        PyObject_HEAD
                        Idioms object;
                        static PyObject *wrap_Object(const Idioms&);
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
