#ifndef is_iclt_icenlp_core_utils_TrieNode_H
#define is_iclt_icenlp_core_utils_TrieNode_H

#include "java/lang/Object.h"

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
                namespace utils {

                    class TrieNode : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_64a6756b,
                            mid_init$_53c95395,
                            mid_addSubNode_cb603d8d,
                            mid_findSubNode_09702e88,
                            mid_getLabel_54c6a173,
                            mid_getNextNodes_21eb51b0,
                            mid_getValue_14c7b5c5,
                            mid_numCharacters_54c6a179,
                            mid_numStrings_54c6a179,
                            mid_setValue_5fdc3f48,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit TrieNode(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        TrieNode(const TrieNode& obj) : ::java::lang::Object(obj) {}

                        TrieNode();
                        TrieNode(jchar, jboolean);
                        TrieNode(jchar, jboolean, const ::java::lang::String &);

                        void addSubNode(const TrieNode &) const;
                        TrieNode findSubNode(jchar) const;
                        jchar getLabel() const;
                        ::java::util::ArrayList getNextNodes() const;
                        ::java::lang::String getValue() const;
                        jint numCharacters() const;
                        jint numStrings() const;
                        void setValue(const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(TrieNode);

                    class t_TrieNode {
                    public:
                        PyObject_HEAD
                        TrieNode object;
                        static PyObject *wrap_Object(const TrieNode&);
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
