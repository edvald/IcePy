#ifndef is_iclt_icenlp_core_formald_tags_TaggedSentence_H
#define is_iclt_icenlp_core_formald_tags_TaggedSentence_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {
                        class TaggedToken;
                        class TaggedText;
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
    namespace util {
        class List;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {

                        class TaggedSentence : public ::java::lang::Object {
                        public:
                            enum {
                                mid_addToken_7aca71b8,
                                mid_createToken_8558cb03,
                                mid_createToken_67d3d71d,
                                mid_createToken_d4e92d27,
                                mid_getParentText_db88959a,
                                mid_getToken_7b9bf097,
                                mid_getTokenCount_54c6a179,
                                mid_getTokens_87851566,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit TaggedSentence(jobject obj) : ::java::lang::Object(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            TaggedSentence(const TaggedSentence& obj) : ::java::lang::Object(obj) {}

                            void addToken(const ::is::iclt::icenlp::core::formald::tags::TaggedToken &) const;
                            ::is::iclt::icenlp::core::formald::tags::TaggedToken createToken(const ::java::lang::String &) const;
                            ::is::iclt::icenlp::core::formald::tags::TaggedToken createToken(const ::java::lang::String &, const ::java::lang::String &) const;
                            ::is::iclt::icenlp::core::formald::tags::TaggedToken createToken(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &) const;
                            ::is::iclt::icenlp::core::formald::tags::TaggedText getParentText() const;
                            ::is::iclt::icenlp::core::formald::tags::TaggedToken getToken(jint) const;
                            jint getTokenCount() const;
                            ::java::util::List getTokens() const;
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
                        extern PyTypeObject PY_TYPE(TaggedSentence);

                        class t_TaggedSentence {
                        public:
                            PyObject_HEAD
                            TaggedSentence object;
                            static PyObject *wrap_Object(const TaggedSentence&);
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
