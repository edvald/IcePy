#ifndef is_iclt_icenlp_core_formald_tags_XMLTagFormat_H
#define is_iclt_icenlp_core_formald_tags_XMLTagFormat_H

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

                        class XMLTagFormat : public ::is::iclt::icenlp::core::formald::tags::TagFormat {
                        public:
                            enum {
                                mid_newInstance_f7326a91,
                                mid_sampleData_14c7b5c5,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit XMLTagFormat(jobject obj) : ::is::iclt::icenlp::core::formald::tags::TagFormat(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            XMLTagFormat(const XMLTagFormat& obj) : ::is::iclt::icenlp::core::formald::tags::TagFormat(obj) {}

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
                        extern PyTypeObject PY_TYPE(XMLTagFormat);

                        class t_XMLTagFormat {
                        public:
                            PyObject_HEAD
                            XMLTagFormat object;
                            static PyObject *wrap_Object(const XMLTagFormat&);
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
