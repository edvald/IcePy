#ifndef is_iclt_icenlp_core_utils_ZipGzipper_H
#define is_iclt_icenlp_core_utils_ZipGzipper_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class File;
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {

                    class ZipGzipper : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_getStatusMessage_141401b3,
                            mid_gunzipFile_ffd62139,
                            mid_gz2String_97a5258f,
                            mid_gz2String_7b17797f,
                            mid_gzipFile_b8789396,
                            mid_unzipFile_ffd62139,
                            mid_zipFile_ffd62139,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit ZipGzipper(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        ZipGzipper(const ZipGzipper& obj) : ::java::lang::Object(obj) {}

                        static jint BUF_SIZE;
                        static jint STATUS_GUNZIP_FAIL;
                        static jint STATUS_GZIP_FAIL;
                        static jint STATUS_IN_FAIL;
                        static jint STATUS_OK;
                        static jint STATUS_OUT_FAIL;
                        static jint STATUS_UNZIP_FAIL;
                        static jint STATUS_ZIP_FAIL;

                        ZipGzipper();

                        static ::java::lang::String getStatusMessage(jint);
                        static jint gunzipFile(const ::java::io::File &, const ::java::io::File &);
                        static ::java::lang::String gz2String(const ::java::lang::String &);
                        static ::java::lang::String gz2String(const ::java::io::InputStream &);
                        static jint gzipFile(const ::java::io::File &, const ::java::lang::String &);
                        static jint unzipFile(const ::java::io::File &, const ::java::io::File &);
                        static jint zipFile(const ::java::io::File &, const ::java::io::File &);
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
                    extern PyTypeObject PY_TYPE(ZipGzipper);

                    class t_ZipGzipper {
                    public:
                        PyObject_HEAD
                        ZipGzipper object;
                        static PyObject *wrap_Object(const ZipGzipper&);
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
