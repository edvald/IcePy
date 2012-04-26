#ifndef is_iclt_icenlp_core_icetagger_IceLocalRules_H
#define is_iclt_icenlp_core_icetagger_IceLocalRules_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class IceTag;
                    class IceLog;
                }
                namespace tokenizer {
                    class IceTokenTags;
                }
            }
        }
    }
}
namespace java {
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

                    class IceLocalRules : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_559a0ab8,
                            mid_checkAdj_93a073e8,
                            mid_checkAdverb_93a073e8,
                            mid_checkArticle_93a073e8,
                            mid_checkConjunction_93a073e8,
                            mid_checkDemonstrativePronoun_93a073e8,
                            mid_checkExclamation_93a073e8,
                            mid_checkIndefinitePronoun_93a073e8,
                            mid_checkInfinitive_93a073e8,
                            mid_checkInterrogativePronoun_93a073e8,
                            mid_checkNoun_93a073e8,
                            mid_checkNumeral_93a073e8,
                            mid_checkPersonalPronoun_93a073e8,
                            mid_checkPossessivePronoun_93a073e8,
                            mid_checkPreposition_93a073e8,
                            mid_checkProperNoun_93a073e8,
                            mid_checkReflexivePronoun_93a073e8,
                            mid_checkRelativeConjunction_93a073e8,
                            mid_checkVerb_93a073e8,
                            mid_checkVerbInfinitive_93a073e8,
                            mid_getDisambiguateFlag_54c6a16a,
                            mid_setDisambiguateFlag_bb0c767f,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceLocalRules(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceLocalRules(const IceLocalRules& obj) : ::java::lang::Object(obj) {}

                        IceLocalRules(const ::is::iclt::icenlp::core::utils::IceLog &);

                        void checkAdj(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkAdverb(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkArticle(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkConjunction(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkDemonstrativePronoun(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkExclamation(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkIndefinitePronoun(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkInfinitive(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkInterrogativePronoun(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkNoun(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkNumeral(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkPersonalPronoun(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkPossessivePronoun(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkPreposition(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkProperNoun(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkReflexivePronoun(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkRelativeConjunction(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkVerb(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void checkVerbInfinitive(const ::is::iclt::icenlp::core::utils::IceTag &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        jboolean getDisambiguateFlag() const;
                        void setDisambiguateFlag(jboolean) const;
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
                    extern PyTypeObject PY_TYPE(IceLocalRules);

                    class t_IceLocalRules {
                    public:
                        PyObject_HEAD
                        IceLocalRules object;
                        static PyObject *wrap_Object(const IceLocalRules&);
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
