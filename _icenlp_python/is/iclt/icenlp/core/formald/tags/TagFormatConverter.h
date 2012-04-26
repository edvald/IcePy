#ifndef is_iclt_icenlp_core_formald_tags_TagFormatConverter_H
#define is_iclt_icenlp_core_formald_tags_TagFormatConverter_H

#include "is/iclt/icenlp/core/formald/FormatConverter.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {
                        class TagFormat;
                    }
                }
            }
        }
    }
}
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

                        class TagFormatConverter : public ::is::iclt::icenlp::core::formald::FormatConverter {
                        public:
                            enum {
                                mid_newInstance_c1a556d4,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit TagFormatConverter(jobject obj) : ::is::iclt::icenlp::core::formald::FormatConverter(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            TagFormatConverter(const TagFormatConverter& obj) : ::is::iclt::icenlp::core::formald::FormatConverter(obj) {}

                            static TagFormatConverter newInstance(const ::is::iclt::icenlp::core::formald::tags::TagFormat &, const ::is::iclt::icenlp::core::formald::tags::TagFormat &);
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
                        extern PyTypeObject PY_TYPE(TagFormatConverter);

                        class t_TagFormatConverter {
                        public:
                            PyObject_HEAD
                            TagFormatConverter object;
                            static PyObject *wrap_Object(const TagFormatConverter&);
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
