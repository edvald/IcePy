#ifndef is_iclt_icenlp_core_tokenizer_Tokenizer_H
#define is_iclt_icenlp_core_tokenizer_Tokenizer_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Lexicon;
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
        class String;
        class NullPointerException;
        class Class;
    }
    namespace io {
        class IOException;
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {

                    class Tokenizer : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_b3a85a05,
                            mid_init$_fc4c7e87,
                            mid_init$_9653df11,
                            mid_init$_875cc3e1,
                            mid_combineMultiWords_39c7bd30,
                            mid_findMultiWords_bb0c767f,
                            mid_initialize_b3a85a05,
                            mid_nextToken_54c6a166,
                            mid_splitAbbreviations_54c6a166,
                            mid_tokenize_5fdc3f48,
                            mid_tokenizeSplit_5fdc3f48,
                            max_mid
                        };

                        enum {
                            fid_tokens,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit Tokenizer(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Tokenizer(const Tokenizer& obj) : ::java::lang::Object(obj) {}

                        static jint typeHmmTokenTags;
                        static jint typeIceTokenTags;
                        static jint typeToken;
                        static jint typeTokenTags;

                        ::java::util::ArrayList _get_tokens() const;
                        void _set_tokens(const ::java::util::ArrayList &) const;

                        Tokenizer(jint, jboolean);
                        Tokenizer(jint, jboolean, const ::java::lang::String &);
                        Tokenizer(jint, jboolean, const ::java::io::InputStream &);
                        Tokenizer(jint, jboolean, const ::is::iclt::icenlp::core::utils::Lexicon &);

                        jboolean combineMultiWords(jint) const;
                        void findMultiWords(jboolean) const;
                        void initialize(jint, jboolean) const;
                        void nextToken() const;
                        void splitAbbreviations() const;
                        void tokenize(const ::java::lang::String &) const;
                        void tokenizeSplit(const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(Tokenizer);

                    class t_Tokenizer {
                    public:
                        PyObject_HEAD
                        Tokenizer object;
                        static PyObject *wrap_Object(const Tokenizer&);
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
