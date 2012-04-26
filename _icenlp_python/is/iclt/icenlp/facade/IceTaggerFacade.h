#ifndef is_iclt_icenlp_facade_IceTaggerFacade_H
#define is_iclt_icenlp_facade_IceTaggerFacade_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {
                    class IceTagger$HmmModelType;
                    class IceTaggerLexicons;
                }
                namespace tritagger {
                    class TriTaggerLexicons;
                }
                namespace utils {
                    class Lexicon;
                }
                namespace tokenizer {
                    class Sentences;
                }
            }
        }
    }
}
namespace java {
    namespace lang {
        class StringBuffer;
        class Class;
        class String;
    }
    namespace io {
        class IOException;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {

                class IceTaggerFacade : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_50cf6b0f,
                        mid_init$_6b7ed9f0,
                        mid_init$_085c1b5d,
                        mid_init$_3de8f566,
                        mid_init$_82a27dcb,
                        mid_createTriTagger_ad30c87a,
                        mid_setModelType_50cf6b0f,
                        mid_tag_6359824b,
                        mid_tagApertium_97a5258f,
                        mid_tagSentence_2979b2bb,
                        mid_useTriTagger_bb0c767f,
                        max_mid
                    };

                    enum {
                        fid_modelPath,
                        max_fid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jfieldID *fids$;
                    static jclass initializeClass();

                    explicit IceTaggerFacade(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    IceTaggerFacade(const IceTaggerFacade& obj) : ::java::lang::Object(obj) {}

                    ::java::lang::String _get_modelPath() const;
                    void _set_modelPath(const ::java::lang::String &) const;

                    IceTaggerFacade(const ::is::iclt::icenlp::core::icetagger::IceTagger$HmmModelType &);
                    IceTaggerFacade(const ::is::iclt::icenlp::core::icetagger::IceTaggerLexicons &, const ::is::iclt::icenlp::core::utils::Lexicon &);
                    IceTaggerFacade(const ::is::iclt::icenlp::core::icetagger::IceTaggerLexicons &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::icetagger::IceTagger$HmmModelType &);
                    IceTaggerFacade(const ::is::iclt::icenlp::core::icetagger::IceTaggerLexicons &, const ::is::iclt::icenlp::core::utils::Lexicon &, jint);
                    IceTaggerFacade(const ::is::iclt::icenlp::core::icetagger::IceTaggerLexicons &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Lexicon &, jboolean);

                    void createTriTagger(const ::is::iclt::icenlp::core::tritagger::TriTaggerLexicons &) const;
                    void setModelType(const ::is::iclt::icenlp::core::icetagger::IceTagger$HmmModelType &) const;
                    ::is::iclt::icenlp::core::tokenizer::Sentences tag(const ::java::lang::String &) const;
                    ::java::lang::String tagApertium(const ::java::lang::String &) const;
                    ::java::lang::StringBuffer tagSentence(const ::java::lang::String &) const;
                    void useTriTagger(jboolean) const;
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
                extern PyTypeObject PY_TYPE(IceTaggerFacade);

                class t_IceTaggerFacade {
                public:
                    PyObject_HEAD
                    IceTaggerFacade object;
                    static PyObject *wrap_Object(const IceTaggerFacade&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
