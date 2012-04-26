#ifndef is_iclt_icenlp_core_formald_tagsets_CustomTagset_H
#define is_iclt_icenlp_core_formald_tagsets_CustomTagset_H

#include "is/iclt/icenlp/core/formald/tagsets/Tagset.h"

namespace java {
    namespace lang {
        class String;
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
                namespace formald {
                    namespace tagsets {

                        class CustomTagset : public ::is::iclt::icenlp::core::formald::tagsets::Tagset {
                        public:
                            enum {
                                mid_getStandardTag_97a5258f,
                                mid_getTag_97a5258f,
                                mid_newInstance_67bafd3c,
                                mid_newInstance_0452f6bc,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit CustomTagset(jobject obj) : ::is::iclt::icenlp::core::formald::tagsets::Tagset(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            CustomTagset(const CustomTagset& obj) : ::is::iclt::icenlp::core::formald::tagsets::Tagset(obj) {}

                            ::java::lang::String getStandardTag(const ::java::lang::String &) const;
                            ::java::lang::String getTag(const ::java::lang::String &) const;
                            static ::is::iclt::icenlp::core::formald::tagsets::Tagset newInstance(const ::java::lang::String &);
                            static ::is::iclt::icenlp::core::formald::tagsets::Tagset newInstance(const ::java::io::InputStream &);
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
                        extern PyTypeObject PY_TYPE(CustomTagset);

                        class t_CustomTagset {
                        public:
                            PyObject_HEAD
                            CustomTagset object;
                            static PyObject *wrap_Object(const CustomTagset&);
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
