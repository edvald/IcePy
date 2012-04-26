#ifndef is_iclt_icenlp_core_utils_Trie_H
#define is_iclt_icenlp_core_utils_Trie_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class TrieNode;
                }
            }
        }
    }
}
namespace java {
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
                namespace utils {

                    class Trie : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_f3691645,
                            mid_init$_3d3c1009,
                            mid_find_0954911e,
                            mid_getKeyFound_14c7b5c5,
                            mid_getValueFound_14c7b5c5,
                            mid_insert_0954911e,
                            mid_insert_33295de4,
                            mid_insertKeyValue_33295de4,
                            mid_lookup_edaaade4,
                            mid_lookupSuffix_f536a869,
                            mid_numCharacters_54c6a179,
                            mid_numStrings_54c6a179,
                            mid_print_54c6a166,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Trie(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Trie(const Trie& obj) : ::java::lang::Object(obj) {}

                        static jchar dummyLabel;

                        Trie();
                        Trie(const ::java::lang::String &, jboolean);
                        Trie(const ::java::io::InputStream &, jboolean);

                        ::is::iclt::icenlp::core::utils::TrieNode find(const ::java::lang::String &) const;
                        ::java::lang::String getKeyFound() const;
                        ::java::lang::String getValueFound() const;
                        ::is::iclt::icenlp::core::utils::TrieNode insert(const ::java::lang::String &) const;
                        ::is::iclt::icenlp::core::utils::TrieNode insert(const ::java::lang::String &, const ::java::lang::String &) const;
                        ::is::iclt::icenlp::core::utils::TrieNode insertKeyValue(const ::java::lang::String &, const ::java::lang::String &) const;
                        ::java::lang::String lookup(const ::java::lang::String &, jboolean) const;
                        jboolean lookupSuffix(const ::java::lang::String &, jboolean, jint) const;
                        jint numCharacters() const;
                        jint numStrings() const;
                        void print() const;
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
                namespace utils {
                    extern PyTypeObject PY_TYPE(Trie);

                    class t_Trie {
                    public:
                        PyObject_HEAD
                        Trie object;
                        static PyObject *wrap_Object(const Trie&);
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
