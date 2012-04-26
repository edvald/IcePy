#ifndef is_iclt_icenlp_core_utils_IceLog_H
#define is_iclt_icenlp_core_utils_IceLog_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class IOException;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {

                    class IceLog : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_5fdc3f48,
                            mid_close_54c6a166,
                            mid_log_5fdc3f48,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceLog(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceLog(const IceLog& obj) : ::java::lang::Object(obj) {}

                        IceLog(const ::java::lang::String &);

                        void close() const;
                        void log(const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(IceLog);

                    class t_IceLog {
                    public:
                        PyObject_HEAD
                        IceLog object;
                        static PyObject *wrap_Object(const IceLog&);
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
