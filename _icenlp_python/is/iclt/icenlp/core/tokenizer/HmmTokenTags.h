#ifndef is_iclt_icenlp_core_tokenizer_HmmTokenTags_H
#define is_iclt_icenlp_core_tokenizer_HmmTokenTags_H

#include "is/iclt/icenlp/core/tokenizer/TokenTags.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {
                    class Token$TokenCode;
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
                namespace tokenizer {

                    class HmmTokenTags : public ::is::iclt::icenlp::core::tokenizer::TokenTags {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_7f9b69a7,
                            mid_getCardinalKey_14c7b5c5,
                            mid_getSuffixLength_54c6a179,
                            mid_isCardinal_54c6a16a,
                            mid_isMorpho_54c6a16a,
                            mid_setCardinalKey_5fdc3f48,
                            mid_setMorpho_bb0c767f,
                            mid_setSuffixLength_39c7bd3c,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit HmmTokenTags(jobject obj) : ::is::iclt::icenlp::core::tokenizer::TokenTags(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        HmmTokenTags(const HmmTokenTags& obj) : ::is::iclt::icenlp::core::tokenizer::TokenTags(obj) {}

                        HmmTokenTags();
                        HmmTokenTags(const ::java::lang::String &, const ::is::iclt::icenlp::core::tokenizer::Token$TokenCode &);

                        ::java::lang::String getCardinalKey() const;
                        jint getSuffixLength() const;
                        jboolean isCardinal() const;
                        jboolean isMorpho() const;
                        void setCardinalKey(const ::java::lang::String &) const;
                        void setMorpho(jboolean) const;
                        void setSuffixLength(jint) const;
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
                    extern PyTypeObject PY_TYPE(HmmTokenTags);

                    class t_HmmTokenTags {
                    public:
                        PyObject_HEAD
                        HmmTokenTags object;
                        static PyObject *wrap_Object(const HmmTokenTags&);
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
