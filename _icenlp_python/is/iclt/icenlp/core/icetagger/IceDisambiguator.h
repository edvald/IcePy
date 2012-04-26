#ifndef is_iclt_icenlp_core_icetagger_IceDisambiguator_H
#define is_iclt_icenlp_core_icetagger_IceDisambiguator_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class IceLog;
                    class Lexicon;
                }
                namespace tokenizer {
                    class IceTokenTags;
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
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {

                    class IceDisambiguator : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_0df54ce1,
                            mid_disAmbiguateGlobal_54c6a166,
                            mid_disAmbiguateLocal_54c6a166,
                            mid_removeTags_a1b441dc,
                            mid_setFullDisambiguation_bb0c767f,
                            mid_setTokens_b3f662f9,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceDisambiguator(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceDisambiguator(const IceDisambiguator& obj) : ::java::lang::Object(obj) {}

                        IceDisambiguator(const ::is::iclt::icenlp::core::utils::IceLog &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Lexicon &, jboolean);

                        void disAmbiguateGlobal() const;
                        void disAmbiguateLocal() const;
                        void removeTags(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void setFullDisambiguation(jboolean) const;
                        void setTokens(const ::java::util::ArrayList &) const;
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
                namespace icetagger {
                    extern PyTypeObject PY_TYPE(IceDisambiguator);

                    class t_IceDisambiguator {
                    public:
                        PyObject_HEAD
                        IceDisambiguator object;
                        static PyObject *wrap_Object(const IceDisambiguator&);
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
