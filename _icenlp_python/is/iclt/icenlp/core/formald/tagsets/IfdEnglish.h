#ifndef is_iclt_icenlp_core_formald_tagsets_IfdEnglish_H
#define is_iclt_icenlp_core_formald_tagsets_IfdEnglish_H

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

                        class IfdEnglish : public ::java::lang::Object {
                        public:
                            enum {
                                mid_init$_54c6a166,
                                mid_getMapping_97a5258f,
                                mid_getTag_97a5258f,
                                mid_loadPostmap_54c6a166,
                                mid_loadTagmaps_54c6a166,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit IfdEnglish(jobject obj) : ::java::lang::Object(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            IfdEnglish(const IfdEnglish& obj) : ::java::lang::Object(obj) {}

                            IfdEnglish();

                            ::java::lang::String getMapping(const ::java::lang::String &) const;
                            ::java::lang::String getTag(const ::java::lang::String &) const;
                            void loadPostmap() const;
                            void loadTagmaps() const;
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
                        extern PyTypeObject PY_TYPE(IfdEnglish);

                        class t_IfdEnglish {
                        public:
                            PyObject_HEAD
                            IfdEnglish object;
                            static PyObject *wrap_Object(const IfdEnglish&);
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
