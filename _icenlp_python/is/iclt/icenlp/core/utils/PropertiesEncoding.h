#ifndef is_iclt_icenlp_core_utils_PropertiesEncoding_H
#define is_iclt_icenlp_core_utils_PropertiesEncoding_H

#include "java/util/Properties.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class OutputStream;
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

                    class PropertiesEncoding : public ::java::util::Properties {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_c4afb15c,
                            mid_load_be2e4f90,
                            mid_removeWhiteSpaces_97a5258f,
                            mid_store_c195c3b2,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit PropertiesEncoding(jobject obj) : ::java::util::Properties(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        PropertiesEncoding(const PropertiesEncoding& obj) : ::java::util::Properties(obj) {}

                        PropertiesEncoding();
                        PropertiesEncoding(const ::java::util::Properties &);

                        void load(const ::java::io::InputStream &) const;
                        static ::java::lang::String removeWhiteSpaces(const ::java::lang::String &);
                        void store(const ::java::io::OutputStream &, const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(PropertiesEncoding);

                    class t_PropertiesEncoding {
                    public:
                        PyObject_HEAD
                        PropertiesEncoding object;
                        static PyObject *wrap_Object(const PropertiesEncoding&);
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
