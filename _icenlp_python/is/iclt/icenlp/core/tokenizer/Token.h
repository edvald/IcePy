#ifndef is_iclt_icenlp_core_tokenizer_Token_H
#define is_iclt_icenlp_core_tokenizer_Token_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {
                    class Token$TokenCode;
                    class Token$MWECode;
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

                    class Token : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_7f9b69a7,
                            mid_isEOS_54c6a16a,
                            mid_isMultiWord_54c6a16a,
                            mid_isPunctuation_54c6a16a,
                            mid_isQuote_54c6a16a,
                            mid_isUnknown_54c6a16a,
                            mid_splitLexeme_1f6a174f,
                            mid_toString_14c7b5c5,
                            mid_toStringWithCode_14c7b5c5,
                            max_mid
                        };

                        enum {
                            fid_lexeme,
                            fid_mweCode,
                            fid_tokenCode,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit Token(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Token(const Token& obj) : ::java::lang::Object(obj) {}

                        ::java::lang::String _get_lexeme() const;
                        void _set_lexeme(const ::java::lang::String &) const;
                        ::is::iclt::icenlp::core::tokenizer::Token$MWECode _get_mweCode() const;
                        void _set_mweCode(const ::is::iclt::icenlp::core::tokenizer::Token$MWECode &) const;
                        ::is::iclt::icenlp::core::tokenizer::Token$TokenCode _get_tokenCode() const;
                        void _set_tokenCode(const ::is::iclt::icenlp::core::tokenizer::Token$TokenCode &) const;

                        Token();
                        Token(const ::java::lang::String &, const ::is::iclt::icenlp::core::tokenizer::Token$TokenCode &);

                        jboolean isEOS() const;
                        jboolean isMultiWord() const;
                        jboolean isPunctuation() const;
                        jboolean isQuote() const;
                        jboolean isUnknown() const;
                        JArray< ::java::lang::String > splitLexeme(const ::java::lang::String &) const;
                        ::java::lang::String toString() const;
                        ::java::lang::String toStringWithCode() const;
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
                    extern PyTypeObject PY_TYPE(Token);

                    class t_Token {
                    public:
                        PyObject_HEAD
                        Token object;
                        static PyObject *wrap_Object(const Token&);
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
