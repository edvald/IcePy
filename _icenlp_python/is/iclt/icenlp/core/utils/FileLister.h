#ifndef is_iclt_icenlp_core_utils_FileLister_H
#define is_iclt_icenlp_core_utils_FileLister_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace util {
        class List;
    }
    namespace io {
        class File;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {

                    class FileLister : public ::java::lang::Object {
                    public:
                        enum {
                            mid_create_dccf34f1,
                            mid_create_f9574bdf,
                            mid_getFiles_87851566,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit FileLister(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        FileLister(const FileLister& obj) : ::java::lang::Object(obj) {}

                        static ::java::util::List create(const ::java::io::File &);
                        static ::java::util::List create(const ::java::io::File &, const ::java::lang::String &);
                        ::java::util::List getFiles() const;
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
                    extern PyTypeObject PY_TYPE(FileLister);

                    class t_FileLister {
                    public:
                        PyObject_HEAD
                        FileLister object;
                        static PyObject *wrap_Object(const FileLister&);
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
