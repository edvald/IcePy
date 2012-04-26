#ifndef is_iclt_icenlp_core_tokenizer_Token$TokenCode_H
#define is_iclt_icenlp_core_tokenizer_Token$TokenCode_H

#include "java/lang/Enum.h"

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

                    class Token$TokenCode : public ::java::lang::Enum {
                    public:
                        enum {
                            mid_valueOf_9d5a6536,
                            mid_values_b00a3150,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Token$TokenCode(jobject obj) : ::java::lang::Enum(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Token$TokenCode(const Token$TokenCode& obj) : ::java::lang::Enum(obj) {}

                        static Token$TokenCode *tcAbbrev;
                        static Token$TokenCode *tcAnd;
                        static Token$TokenCode *tcArrow;
                        static Token$TokenCode *tcBackSlash;
                        static Token$TokenCode *tcColon;
                        static Token$TokenCode *tcComma;
                        static Token$TokenCode *tcCurrency;
                        static Token$TokenCode *tcDollar;
                        static Token$TokenCode *tcDoubleQuote;
                        static Token$TokenCode *tcDownQuote;
                        static Token$TokenCode *tcEOS;
                        static Token$TokenCode *tcEqualSign;
                        static Token$TokenCode *tcExclamation;
                        static Token$TokenCode *tcGreater;
                        static Token$TokenCode *tcHyphen;
                        static Token$TokenCode *tcLArrow;
                        static Token$TokenCode *tcLBracket;
                        static Token$TokenCode *tcLCurlyBracket;
                        static Token$TokenCode *tcLParen;
                        static Token$TokenCode *tcLess;
                        static Token$TokenCode *tcMultiWord;
                        static Token$TokenCode *tcNone;
                        static Token$TokenCode *tcNumber;
                        static Token$TokenCode *tcNumberSign;
                        static Token$TokenCode *tcPeriod;
                        static Token$TokenCode *tcPlus;
                        static Token$TokenCode *tcPlusMinus;
                        static Token$TokenCode *tcQuestion;
                        static Token$TokenCode *tcRArrow;
                        static Token$TokenCode *tcRBracket;
                        static Token$TokenCode *tcRCurlyBracket;
                        static Token$TokenCode *tcRParen;
                        static Token$TokenCode *tcSemicolon;
                        static Token$TokenCode *tcSingleQuote;
                        static Token$TokenCode *tcSlash;
                        static Token$TokenCode *tcStar;
                        static Token$TokenCode *tcUnderscore;
                        static Token$TokenCode *tcUnknown;
                        static Token$TokenCode *tcUpQuote;
                        static Token$TokenCode *tcUrl;
                        static Token$TokenCode *tcWhitespace;
                        static Token$TokenCode *tcWord;

                        static Token$TokenCode valueOf(const ::java::lang::String &);
                        static JArray< Token$TokenCode > values();
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
                    extern PyTypeObject PY_TYPE(Token$TokenCode);

                    class t_Token$TokenCode {
                    public:
                        PyObject_HEAD
                        Token$TokenCode object;
                        static PyObject *wrap_Object(const Token$TokenCode&);
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
