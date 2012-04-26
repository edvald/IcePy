#ifndef is_iclt_icenlp_core_utils_WordList_H
#define is_iclt_icenlp_core_utils_WordList_H

#include "java/lang/Object.h"

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

                    class WordList : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_5fdc3f48,
                            mid_init$_be2e4f90,
                            mid_getWords_21eb51b0,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit WordList(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        WordList(const WordList& obj) : ::java::lang::Object(obj) {}

                        WordList(const ::java::lang::String &);
                        WordList(const ::java::io::InputStream &);

                        ::java::util::ArrayList getWords() const;
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
                    extern PyTypeObject PY_TYPE(WordList);

                    class t_WordList {
                    public:
                        PyObject_HEAD
                        WordList object;
                        static PyObject *wrap_Object(const WordList&);
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
