#ifndef is_iclt_icenlp_core_tritagger_TriTaggerResources_H
#define is_iclt_icenlp_core_tritagger_TriTaggerResources_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
    namespace io {
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tritagger {

                    class TriTaggerResources : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            max_mid
                        };

                        enum {
                            fid_isFrequency,
                            fid_isLambda,
                            fid_isNgrams,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit TriTaggerResources(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        TriTaggerResources(const TriTaggerResources& obj) : ::java::lang::Object(obj) {}

                        ::java::io::InputStream _get_isFrequency() const;
                        void _set_isFrequency(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isLambda() const;
                        void _set_isLambda(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isNgrams() const;
                        void _set_isNgrams(const ::java::io::InputStream &) const;

                        TriTaggerResources();
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
                namespace tritagger {
                    extern PyTypeObject PY_TYPE(TriTaggerResources);

                    class t_TriTaggerResources {
                    public:
                        PyObject_HEAD
                        TriTaggerResources object;
                        static PyObject *wrap_Object(const TriTaggerResources&);
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
