#ifndef is_iclt_icenlp_core_formald_FormatConverter_H
#define is_iclt_icenlp_core_formald_FormatConverter_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    class Format;
                }
            }
        }
    }
}
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
                namespace formald {

                    class FormatConverter : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_c7d69f16,
                            mid_convert_97a5258f,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit FormatConverter(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        FormatConverter(const FormatConverter& obj) : ::java::lang::Object(obj) {}

                        FormatConverter(const ::is::iclt::icenlp::core::formald::Format &, const ::is::iclt::icenlp::core::formald::Format &);

                        ::java::lang::String convert(const ::java::lang::String &) const;
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
                namespace formald {
                    extern PyTypeObject PY_TYPE(FormatConverter);

                    class t_FormatConverter {
                    public:
                        PyObject_HEAD
                        FormatConverter object;
                        static PyObject *wrap_Object(const FormatConverter&);
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
