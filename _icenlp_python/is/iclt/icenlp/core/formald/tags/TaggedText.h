#ifndef is_iclt_icenlp_core_formald_tags_TaggedText_H
#define is_iclt_icenlp_core_formald_tags_TaggedText_H

#include "is/iclt/icenlp/core/formald/Text.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tagsets {
                        class Tagset;
                    }
                    namespace tags {
                        class TagFormat;
                        class TaggedToken;
                        class TaggedSentence;
                    }
                }
            }
        }
    }
}
namespace java {
    namespace util {
        class List;
    }
    namespace lang {
        class String;
        class Class;
    }
    namespace io {
        class File;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {

                        class TaggedText : public ::is::iclt::icenlp::core::formald::Text {
                        public:
                            enum {
                                mid_addSentence_4b6dd875,
                                mid_createSentence_060fbffc,
                                mid_getSentence_feeeaaca,
                                mid_getSentenceCount_54c6a179,
                                mid_getSentences_87851566,
                                mid_getTagFormat_f7326a91,
                                mid_getTagset_cc201b9a,
                                mid_getTokens_87851566,
                                mid_isDefaultTagset_54c6a16a,
                                mid_newInstance_db88959a,
                                mid_newInstance_5b238eeb,
                                mid_newInstance_5d7d294a,
                                mid_newInstanceFromFile_55e241c1,
                                mid_removeSentence_4b6dd875,
                                mid_setTagFormat_bb3e15b8,
                                mid_setTagset_3483f5cb,
                                mid_toString_14c7b5c5,
                                mid_toString_b9f5ff67,
                                max_mid
                            };

                            static ::java::lang::Class *class$;
                            static jmethodID *mids$;
                            static jclass initializeClass();

                            explicit TaggedText(jobject obj) : ::is::iclt::icenlp::core::formald::Text(obj) {
                                if (obj != NULL)
                                    initializeClass();
                            }
                            TaggedText(const TaggedText& obj) : ::is::iclt::icenlp::core::formald::Text(obj) {}

                            void addSentence(const ::is::iclt::icenlp::core::formald::tags::TaggedSentence &) const;
                            ::is::iclt::icenlp::core::formald::tags::TaggedSentence createSentence() const;
                            ::is::iclt::icenlp::core::formald::tags::TaggedSentence getSentence(jint) const;
                            jint getSentenceCount() const;
                            ::java::util::List getSentences() const;
                            ::is::iclt::icenlp::core::formald::tags::TagFormat getTagFormat() const;
                            ::is::iclt::icenlp::core::formald::tagsets::Tagset getTagset() const;
                            ::java::util::List getTokens() const;
                            jboolean isDefaultTagset() const;
                            static TaggedText newInstance();
                            static TaggedText newInstance(const ::is::iclt::icenlp::core::formald::tagsets::Tagset &);
                            static TaggedText newInstance(const ::java::lang::String &, const ::is::iclt::icenlp::core::formald::tags::TagFormat &);
                            static TaggedText newInstanceFromFile(const ::java::io::File &, const ::is::iclt::icenlp::core::formald::tags::TagFormat &);
                            void removeSentence(const ::is::iclt::icenlp::core::formald::tags::TaggedSentence &) const;
                            void setTagFormat(const ::is::iclt::icenlp::core::formald::tags::TagFormat &) const;
                            void setTagset(const ::is::iclt::icenlp::core::formald::tagsets::Tagset &) const;
                            ::java::lang::String toString() const;
                            ::java::lang::String toString(const ::is::iclt::icenlp::core::formald::tags::TagFormat &) const;
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
                        extern PyTypeObject PY_TYPE(TaggedText);

                        class t_TaggedText {
                        public:
                            PyObject_HEAD
                            TaggedText object;
                            static PyObject *wrap_Object(const TaggedText&);
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
