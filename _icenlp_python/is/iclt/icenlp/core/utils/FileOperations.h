#ifndef is_iclt_icenlp_core_utils_FileOperations_H
#define is_iclt_icenlp_core_utils_FileOperations_H

#include "java/lang/Object.h"

namespace java {
    namespace util {
        class ArrayList;
    }
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
                namespace utils {

                    class FileOperations : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_fileToString_97a5258f,
                            mid_getFilePaths_e5d0f376,
                            mid_stringToFile_4a264742,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit FileOperations(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        FileOperations(const FileOperations& obj) : ::java::lang::Object(obj) {}

                        FileOperations();

                        static ::java::lang::String fileToString(const ::java::lang::String &);
                        static ::java::util::ArrayList getFilePaths(const ::java::lang::String &);
                        static void stringToFile(const ::java::lang::String &, const ::java::lang::String &);
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
                    extern PyTypeObject PY_TYPE(FileOperations);

                    class t_FileOperations {
                    public:
                        PyObject_HEAD
                        FileOperations object;
                        static PyObject *wrap_Object(const FileOperations&);
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
