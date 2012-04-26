#ifndef is_iclt_icenlp_core_formald_tags_Ice1TagFormat_H
#define is_iclt_icenlp_core_formald_tags_Ice1TagFormat_H

#include "is/iclt/icenlp/core/formald/tags/TagFormat.h"

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
                    namespace tags {

                        class Ice1TagFormat : public ::is::iclt::icenlp::core::formald::tags::TagFormat {
                        public:
                            enum {
                                mid_newInstance_f7326a91,
                                mid_sampleData_14c7b5c5,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit Ice1TagFormat(jobject obj) : ::is::iclt::icenlp::core::formald::tags::TagFormat(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            Ice1TagFormat(const Ice1TagFormat& obj) : ::is::iclt::icenlp::core::formald::tags::TagFormat(obj) {}

                            static ::is::iclt::icenlp::core::formald::tags::TagFormat newInstance();
                            ::java::lang::String sampleData() const;
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
                        extern PyTypeObject PY_TYPE(Ice1TagFormat);

                        class t_Ice1TagFormat {
                        public:
                            PyObject_HEAD
                            Ice1TagFormat object;
                            static PyObject *wrap_Object(const Ice1TagFormat&);
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
