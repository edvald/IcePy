#ifndef is_iclt_icenlp_core_formald_tagsets_Tagset_H
#define is_iclt_icenlp_core_formald_tagsets_Tagset_H

#include "java/lang/Object.h"

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
                    namespace tagsets {

                        class Tagset : public ::java::lang::Object {
                        public:
                            enum {
                                mid_init$_54c6a166,
                                mid_getDefault_cc201b9a,
                                mid_getStandardTag_97a5258f,
                                mid_getTag_97a5258f,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit Tagset(jobject obj) : ::java::lang::Object(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            Tagset(const Tagset& obj) : ::java::lang::Object(obj) {}

                            static Tagset *APERTIUM;
                            static Tagset *IFD;

                            Tagset();

                            static Tagset getDefault();
                            ::java::lang::String getStandardTag(const ::java::lang::String &) const;
                            ::java::lang::String getTag(const ::java::lang::String &) const;
                        };
                    }
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
                    namespace tagsets {
                        extern PyTypeObject PY_TYPE(Tagset);

                        class t_Tagset {
                        public:
                            PyObject_HEAD
                            Tagset object;
                            static PyObject *wrap_Object(const Tagset&);
                            static PyObject *wrap_jobject(const jobject&);
                            static void install(PyObject *module);
                            static void initialize(PyObject *module);
                        };
                    }
                }
            }
        }
    }
}

#endif
