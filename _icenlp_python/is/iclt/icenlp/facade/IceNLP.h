#ifndef is_iclt_icenlp_facade_IceNLP_H
#define is_iclt_icenlp_facade_IceNLP_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace formald {
                    namespace tags {
                        class TaggedText;
                    }
                }
            }
        }
    }
}
namespace java {
    namespace lang {
        class String;
        class Class;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {

                class IceNLP : public ::java::lang::Object {
                public:
                    enum {
                        mid_analyze_97a5258f,
                        mid_getInstance_3c763880,
                        mid_newInstance_3c763880,
                        mid_parseLines_97a5258f,
                        mid_srxSegmentize_97a5258f,
                        mid_tagAndLemmatizeLines_cb9f349c,
                        mid_tagAndLemmatizeText_cb9f349c,
                        mid_tagAndParseLines_97a5258f,
                        mid_tagAndParseText_97a5258f,
                        mid_tagLines_cb9f349c,
                        mid_tagText_cb9f349c,
                        mid_terminate_54c6a166,
                        mid_tokenize_97a5258f,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit IceNLP(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    IceNLP(const IceNLP& obj) : ::java::lang::Object(obj) {}

                    ::java::lang::String analyze(const ::java::lang::String &) const;
                    static IceNLP getInstance();
                    static IceNLP newInstance();
                    ::java::lang::String parseLines(const ::java::lang::String &) const;
                    ::java::lang::String srxSegmentize(const ::java::lang::String &) const;
                    ::is::iclt::icenlp::core::formald::tags::TaggedText tagAndLemmatizeLines(const ::java::lang::String &) const;
                    ::is::iclt::icenlp::core::formald::tags::TaggedText tagAndLemmatizeText(const ::java::lang::String &) const;
                    ::java::lang::String tagAndParseLines(const ::java::lang::String &) const;
                    ::java::lang::String tagAndParseText(const ::java::lang::String &) const;
                    ::is::iclt::icenlp::core::formald::tags::TaggedText tagLines(const ::java::lang::String &) const;
                    ::is::iclt::icenlp::core::formald::tags::TaggedText tagText(const ::java::lang::String &) const;
                    static void terminate();
                    ::java::lang::String tokenize(const ::java::lang::String &) const;
                };
            }
        }
    }
}

#include <Python.h>

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {
                extern PyTypeObject PY_TYPE(IceNLP);

                class t_IceNLP {
                public:
                    PyObject_HEAD
                    IceNLP object;
                    static PyObject *wrap_Object(const IceNLP&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
