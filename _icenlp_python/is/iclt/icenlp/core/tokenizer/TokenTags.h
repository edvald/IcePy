#ifndef is_iclt_icenlp_core_tokenizer_TokenTags_H
#define is_iclt_icenlp_core_tokenizer_TokenTags_H

#include "is/iclt/icenlp/core/tokenizer/Token.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Tag;
                }
                namespace tokenizer {
                    class Token$TokenCode;
                }
            }
        }
    }
}
namespace java {
    namespace util {
        class ArrayList;
    }
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
                namespace tokenizer {

                    class TokenTags : public ::is::iclt::icenlp::core::tokenizer::Token {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_7f9b69a7,
                            mid_addAllTags_5fdc3f48,
                            mid_addAllTagsFront_5fdc3f48,
                            mid_addAllTagsReverse_5fdc3f48,
                            mid_addAllTagsWithSeparator_4a264742,
                            mid_addTag_5fdc3f48,
                            mid_addTag_7c5bc380,
                            mid_addTagFront_5fdc3f48,
                            mid_allTagStrings_14c7b5c5,
                            mid_allTagStringsWithSeparator_97a5258f,
                            mid_clearTags_54c6a166,
                            mid_getCardinalKey_14c7b5c5,
                            mid_getFirstTag_fdc96bad,
                            mid_getFirstTagStr_14c7b5c5,
                            mid_getLastTag_fdc96bad,
                            mid_getLastTagStr_14c7b5c5,
                            mid_getProbSuffix_54c6a174,
                            mid_getSuffixLength_54c6a179,
                            mid_getTags_21eb51b0,
                            mid_isCardinal_54c6a16a,
                            mid_isMorpho_54c6a16a,
                            mid_isUnknown_54c6a16a,
                            mid_noTags_54c6a16a,
                            mid_numTags_54c6a179,
                            mid_removeAllBut_5fdc3f48,
                            mid_removeAllButFirstTag_54c6a166,
                            mid_removeInvalidTags_54c6a166,
                            mid_setAllTags_5fdc3f48,
                            mid_setAllTags_b3f662f9,
                            mid_setCardinalKey_5fdc3f48,
                            mid_setMorpho_bb0c767f,
                            mid_setProbSuffix_5d1c7645,
                            mid_setSuffixLength_39c7bd3c,
                            mid_setTag_7c5bc380,
                            mid_setTag_5fdc3f48,
                            mid_setUnknown_bb0c767f,
                            mid_tagExists_5fdc3f44,
                            mid_toString_14c7b5c5,
                            mid_splitTags_1f6a174f,
                            mid_splitTagsWithSeparator_6aa2a869,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit TokenTags(jobject obj) : ::is::iclt::icenlp::core::tokenizer::Token(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        TokenTags(const TokenTags& obj) : ::is::iclt::icenlp::core::tokenizer::Token(obj) {}

                        TokenTags();
                        TokenTags(const ::java::lang::String &, const ::is::iclt::icenlp::core::tokenizer::Token$TokenCode &);

                        void addAllTags(const ::java::lang::String &) const;
                        void addAllTagsFront(const ::java::lang::String &) const;
                        void addAllTagsReverse(const ::java::lang::String &) const;
                        void addAllTagsWithSeparator(const ::java::lang::String &, const ::java::lang::String &) const;
                        void addTag(const ::java::lang::String &) const;
                        void addTag(const ::is::iclt::icenlp::core::utils::Tag &) const;
                        void addTagFront(const ::java::lang::String &) const;
                        ::java::lang::String allTagStrings() const;
                        ::java::lang::String allTagStringsWithSeparator(const ::java::lang::String &) const;
                        void clearTags() const;
                        ::java::lang::String getCardinalKey() const;
                        ::is::iclt::icenlp::core::utils::Tag getFirstTag() const;
                        ::java::lang::String getFirstTagStr() const;
                        ::is::iclt::icenlp::core::utils::Tag getLastTag() const;
                        ::java::lang::String getLastTagStr() const;
                        jdouble getProbSuffix() const;
                        jint getSuffixLength() const;
                        ::java::util::ArrayList getTags() const;
                        jboolean isCardinal() const;
                        jboolean isMorpho() const;
                        jboolean isUnknown() const;
                        jboolean noTags() const;
                        jint numTags() const;
                        void removeAllBut(const ::java::lang::String &) const;
                        void removeAllButFirstTag() const;
                        void removeInvalidTags() const;
                        void setAllTags(const ::java::lang::String &) const;
                        void setAllTags(const ::java::util::ArrayList &) const;
                        void setCardinalKey(const ::java::lang::String &) const;
                        void setMorpho(jboolean) const;
                        void setProbSuffix(jdouble) const;
                        void setSuffixLength(jint) const;
                        void setTag(const ::is::iclt::icenlp::core::utils::Tag &) const;
                        void setTag(const ::java::lang::String &) const;
                        void setUnknown(jboolean) const;
                        jboolean tagExists(const ::java::lang::String &) const;
                        ::java::lang::String toString() const;
                    };
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
                namespace tokenizer {
                    extern PyTypeObject PY_TYPE(TokenTags);

                    class t_TokenTags {
                    public:
                        PyObject_HEAD
                        TokenTags object;
                        static PyObject *wrap_Object(const TokenTags&);
                        static PyObject *wrap_jobject(const jobject&);
                        static void install(PyObject *module);
                        static void initialize(PyObject *module);
                    };
                }
            }
        }
    }
}

#endif
