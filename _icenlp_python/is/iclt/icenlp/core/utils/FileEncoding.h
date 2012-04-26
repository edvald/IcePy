#ifndef is_iclt_icenlp_core_utils_FileEncoding_H
#define is_iclt_icenlp_core_utils_FileEncoding_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class BufferedReader;
        class OutputStream;
        class IOException;
        class BufferedWriter;
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {

                    class FileEncoding : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_getReader_a4b8cb84,
                            mid_getReader_c4d3c0e4,
                            mid_getWriter_1bd047f0,
                            mid_getWriter_b63a3030,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit FileEncoding(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        FileEncoding(const FileEncoding& obj) : ::java::lang::Object(obj) {}

                        static ::java::lang::String *ENCODING;

                        FileEncoding();

                        static ::java::io::BufferedReader getReader(const ::java::io::InputStream &);
                        static ::java::io::BufferedReader getReader(const ::java::lang::String &);
                        static ::java::io::BufferedWriter getWriter(const ::java::lang::String &);
                        static ::java::io::BufferedWriter getWriter(const ::java::io::OutputStream &);
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
                    extern PyTypeObject PY_TYPE(FileEncoding);

                    class t_FileEncoding {
                    public:
                        PyObject_HEAD
                        FileEncoding object;
                        static PyObject *wrap_Object(const FileEncoding&);
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
