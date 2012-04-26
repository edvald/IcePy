#ifndef is_iclt_icenlp_core_formald_tags_TaggedToken_H
#define is_iclt_icenlp_core_formald_tags_TaggedToken_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {
                        class TaggedSentence;
                    }
                }
            }
        }
    }
}
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

                        class TaggedToken : public ::java::lang::Object {
                        public:
                            enum {
                                mid_getLemma_14c7b5c5,
                                mid_getParentSentence_060fbffc,
                                mid_getTag_14c7b5c5,
                                mid_getWord_14c7b5c5,
                                mid_hasLemma_54c6a16a,
                                mid_hasTag_54c6a16a,
                                mid_setLemma_5fdc3f48,
                                mid_setTag_5fdc3f48,
                                mid_setWord_5fdc3f48,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit TaggedToken(jobject obj) : ::java::lang::Object(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            TaggedToken(const TaggedToken& obj) : ::java::lang::Object(obj) {}

                            ::java::lang::String getLemma() const;
                            ::is::iclt::icenlp::core::formald::tags::TaggedSentence getParentSentence() const;
                            ::java::lang::String getTag() const;
                            ::java::lang::String getWord() const;
                            jboolean hasLemma() const;
                            jboolean hasTag() const;
                            void setLemma(const ::java::lang::String &) const;
                            void setTag(const ::java::lang::String &) const;
                            void setWord(const ::java::lang::String &) const;
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
                        extern PyTypeObject PY_TYPE(TaggedToken);

                        class t_TaggedToken {
                        public:
                            PyObject_HEAD
                            TaggedToken object;
                            static PyObject *wrap_Object(const TaggedToken&);
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
