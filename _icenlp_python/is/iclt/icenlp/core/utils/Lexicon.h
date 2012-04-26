#ifndef is_iclt_icenlp_core_utils_Lexicon_H
#define is_iclt_icenlp_core_utils_Lexicon_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class PropertiesEncoding;
                }
            }
        }
    }
}
namespace java {
    namespace util {
        class Set;
        class Enumeration;
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

                    class Lexicon : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_be2e4f90,
                            mid_init$_5fdc3f48,
                            mid_containsKey_5fdc3f44,
                            mid_getEntrySet_03e99967,
                            mid_getProperties_d345f89e,
                            mid_getSize_54c6a179,
                            mid_keys_39f88070,
                            mid_load_5fdc3f48,
                            mid_load_be2e4f90,
                            mid_lookup_edaaade4,
                            mid_put_4a264742,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Lexicon(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Lexicon(const Lexicon& obj) : ::java::lang::Object(obj) {}

                        Lexicon();
                        Lexicon(const ::java::io::InputStream &);
                        Lexicon(const ::java::lang::String &);

                        jboolean containsKey(const ::java::lang::String &) const;
                        ::java::util::Set getEntrySet() const;
                        ::is::iclt::icenlp::core::utils::PropertiesEncoding getProperties() const;
                        jint getSize() const;
                        ::java::util::Enumeration keys() const;
                        void load(const ::java::lang::String &) const;
                        void load(const ::java::io::InputStream &) const;
                        ::java::lang::String lookup(const ::java::lang::String &, jboolean) const;
                        void put(const ::java::lang::String &, const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(Lexicon);

                    class t_Lexicon {
                    public:
                        PyObject_HEAD
                        Lexicon object;
                        static PyObject *wrap_Object(const Lexicon&);
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
