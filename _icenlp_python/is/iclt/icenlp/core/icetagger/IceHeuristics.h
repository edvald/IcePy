#ifndef is_iclt_icenlp_core_icetagger_IceHeuristics_H
#define is_iclt_icenlp_core_icetagger_IceHeuristics_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class Lexicon;
                    class IceLog;
                }
                namespace tokenizer {
                    class IceTokenTags;
                    class IceTokenTags$Match;
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
        class String;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {

                    class IceHeuristics : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_c386ef44,
                            mid_ambiguateAdjectives_d8d154a6,
                            mid_checkCorrectPrep_d8d154a6,
                            mid_checkEnumeration_54c6a166,
                            mid_checkNominalAgreement_d8d154a6,
                            mid_checkPrepAgreement_d8d154a6,
                            mid_checkReflexives_54c6a166,
                            mid_checkSVO_d8d154a6,
                            mid_checkSubjectObjectAgreement_d3236aa8,
                            mid_checkSubjunctive_54c6a166,
                            mid_forceAgreement_281ca35a,
                            mid_getLastPluralSubject_265fd945,
                            mid_match_6506aa73,
                            mid_setTokens_b3f662f9,
                            mid_verbPrepLookup_9f352141,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceHeuristics(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceHeuristics(const IceHeuristics& obj) : ::java::lang::Object(obj) {}

                        IceHeuristics(const ::is::iclt::icenlp::core::utils::IceLog &, const ::is::iclt::icenlp::core::utils::Lexicon &, const ::is::iclt::icenlp::core::utils::Lexicon &);

                        void ambiguateAdjectives(jint, jint) const;
                        void checkCorrectPrep(jint, jint) const;
                        void checkEnumeration() const;
                        void checkNominalAgreement(jint, jint) const;
                        void checkPrepAgreement(jint, jint) const;
                        void checkReflexives() const;
                        void checkSVO(jint, jint) const;
                        jboolean checkSubjectObjectAgreement(jint, jint, jint) const;
                        void checkSubjunctive() const;
                        void forceAgreement(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        ::is::iclt::icenlp::core::tokenizer::IceTokenTags getLastPluralSubject() const;
                        jboolean match(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags$Match &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
                        void setTokens(const ::java::util::ArrayList &) const;
                        ::java::lang::String verbPrepLookup(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
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
                    extern PyTypeObject PY_TYPE(IceHeuristics);

                    class t_IceHeuristics {
                    public:
                        PyObject_HEAD
                        IceHeuristics object;
                        static PyObject *wrap_Object(const IceHeuristics&);
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
