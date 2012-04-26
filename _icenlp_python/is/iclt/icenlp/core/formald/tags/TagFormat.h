#ifndef is_iclt_icenlp_core_formald_tags_TagFormat_H
#define is_iclt_icenlp_core_formald_tags_TagFormat_H

#include "is/iclt/icenlp/core/formald/Format.h"

namespace java {
    namespace lang {
        class Class;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {

                        class TagFormat : public ::is::iclt::icenlp::core::formald::Format {
                        public:
                            enum {
                                mid_init$_54c6a166,
                                mid_getDefault_f7326a91,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit TagFormat(jobject obj) : ::is::iclt::icenlp::core::formald::Format(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            TagFormat(const TagFormat& obj) : ::is::iclt::icenlp::core::formald::Format(obj) {}

                            static TagFormat *ICE1;
                            static TagFormat *ICE2;
                            static TagFormat *XML;

                            TagFormat();

                            static TagFormat getDefault();
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
                    namespace tags {
                        extern PyTypeObject PY_TYPE(TagFormat);

                        class t_TagFormat {
                        public:
                            PyObject_HEAD
                            TagFormat object;
                            static PyObject *wrap_Object(const TagFormat&);
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
