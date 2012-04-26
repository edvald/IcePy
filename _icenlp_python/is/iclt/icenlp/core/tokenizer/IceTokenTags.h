#ifndef is_iclt_icenlp_core_tokenizer_IceTokenTags_H
#define is_iclt_icenlp_core_tokenizer_IceTokenTags_H

#include "is/iclt/icenlp/core/tokenizer/TokenTags.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class IceTag$WordClass;
                }
                namespace tokenizer {
                    class Token$TokenCode;
                    class IceTokenTags$UnknownType;
                    class IceTokenTags$SVOMark;
                    class IceTokenTags$Condition;
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

                    class IceTokenTags : public ::is::iclt::icenlp::core::tokenizer::TokenTags {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_7f9b69a7,
                            mid_addArticle_54c6a166,
                            mid_addInfinitiveVerbForm_54c6a166,
                            mid_addTag_5fdc3f48,
                            mid_addTagFront_5fdc3f48,
                            mid_allWordClasses_14c7b5c5,
                            mid_caseMatch_9ee1b518,
                            mid_cleanTags_54c6a166,
                            mid_genderMatch_9ee1b518,
                            mid_genderNumberCaseMatch_9ee1b518,
                            mid_getFirstWordClass_14c7b5c5,
                            mid_getSVOMark_130ccb3e,
                            mid_getSVOMarkString_14c7b5c5,
                            mid_hasArticle_54c6a16a,
                            mid_hasGender_54c6a16a,
                            mid_isAdjective_54c6a16a,
                            mid_isAdjectiveComparative_54c6a16a,
                            mid_isAdjectiveIndeclineable_54c6a16a,
                            mid_isAdjectivePositive_54c6a16a,
                            mid_isAdjectiveStrong_54c6a16a,
                            mid_isAdjectiveSuper_54c6a16a,
                            mid_isAdjectiveWeak_54c6a16a,
                            mid_isAdverb_54c6a16a,
                            mid_isAdverbComparative_54c6a16a,
                            mid_isAdverbSuper_54c6a16a,
                            mid_isArticle_54c6a16a,
                            mid_isCase_87fd5456,
                            mid_isCompound_54c6a16a,
                            mid_isCondition_db04de5b,
                            mid_isConjunction_54c6a16a,
                            mid_isDeclension_87fd5456,
                            mid_isDemonstrativePronoun_54c6a16a,
                            mid_isExclamation_54c6a16a,
                            mid_isGenderPerson_87fd5456,
                            mid_isIndefinitePronoun_54c6a16a,
                            mid_isInfinitive_54c6a16a,
                            mid_isInterrogativePronoun_54c6a16a,
                            mid_isNominal_54c6a16a,
                            mid_isNoun_54c6a16a,
                            mid_isNumber_87fd5456,
                            mid_isNumeral_54c6a16a,
                            mid_isNumeralOrdinal_54c6a16a,
                            mid_isOnlyAdjectiveSuper_54c6a16a,
                            mid_isOnlyAdverbSuper_54c6a16a,
                            mid_isOnlyCase_87fd5456,
                            mid_isOnlyGender_87fd5456,
                            mid_isOnlyNumber_87fd5456,
                            mid_isOnlyOneGender_54c6a16a,
                            mid_isOnlyOneGenderNumber_54c6a16a,
                            mid_isOnlyVerbAny_54c6a16a,
                            mid_isOnlyWordClass_0dc1bb34,
                            mid_isOtherThanWordClass_0dc1bb34,
                            mid_isPersonalPronoun_54c6a16a,
                            mid_isPossessivePronoun_54c6a16a,
                            mid_isPreposition_54c6a16a,
                            mid_isPronoun_54c6a16a,
                            mid_isProperNoun_54c6a16a,
                            mid_isReflexivePronoun_54c6a16a,
                            mid_isRelativeConjunction_54c6a16a,
                            mid_isRelativePronoun_54c6a16a,
                            mid_isSVOMainSubject_54c6a16a,
                            mid_isSVOMainVerb_54c6a16a,
                            mid_isSVONone_54c6a16a,
                            mid_isSVOObject_54c6a16a,
                            mid_isSVOPrepPhrase_54c6a16a,
                            mid_isSVOSubject_54c6a16a,
                            mid_isSVOVerb_54c6a16a,
                            mid_isUnknownEnding_54c6a16a,
                            mid_isUnknownGuessed_54c6a16a,
                            mid_isUnknownMorpho_54c6a16a,
                            mid_isUnknownNone_54c6a16a,
                            mid_isUnknownProperNoun_54c6a16a,
                            mid_isVerb_54c6a16a,
                            mid_isVerbActive_54c6a16a,
                            mid_isVerbAny_54c6a16a,
                            mid_isVerbAuxiliary_54c6a16a,
                            mid_isVerbBe_54c6a16a,
                            mid_isVerbCaseMarking_54c6a16a,
                            mid_isVerbImperative_54c6a16a,
                            mid_isVerbIndicative_54c6a16a,
                            mid_isVerbInf_54c6a16a,
                            mid_isVerbInfinitive_54c6a16a,
                            mid_isVerbMiddleForm_54c6a16a,
                            mid_isVerbPastPart_54c6a16a,
                            mid_isVerbPresentPart_54c6a16a,
                            mid_isVerbSpecialAuxiliary_54c6a16a,
                            mid_isVerbSpecialInf_54c6a16a,
                            mid_isVerbSubjunctive_54c6a16a,
                            mid_isVerbSupine_54c6a16a,
                            mid_isWordClass_0dc1bb34,
                            mid_makeCopy_265fd945,
                            mid_numCases_54c6a179,
                            mid_numGenders_54c6a179,
                            mid_numNominals_54c6a179,
                            mid_numberCaseMatch_9ee1b518,
                            mid_numberMatch_9ee1b518,
                            mid_personNumberMatch_9ee1b518,
                            mid_removeAllBut_0dc1bb38,
                            mid_removeAllButCase_87fd545a,
                            mid_removeAllButGender_64a6756b,
                            mid_removeAllButNounAdj_54c6a166,
                            mid_removeAllButNumber_87fd545a,
                            mid_removeAllButProperNounType_87fd545a,
                            mid_removeAllButVerbs_bb0c767f,
                            mid_removeArticle_54c6a166,
                            mid_removeCase_64a6756b,
                            mid_removeGender_64a6756b,
                            mid_removeNumber_64a6756b,
                            mid_removeOnCondition_f94153a7,
                            mid_removePronouns_54c6a166,
                            mid_removeProperNounType_87fd545a,
                            mid_removeVerbForm_db04de57,
                            mid_removeVerbs_54c6a166,
                            mid_removeWordClass_0dc1bb38,
                            mid_setCase_87fd545a,
                            mid_setCompound_bb0c767f,
                            mid_setDeclension_87fd545a,
                            mid_setDegree_87fd545a,
                            mid_setGender_87fd545a,
                            mid_setPlural_54c6a166,
                            mid_setProperNameType_87fd545a,
                            mid_setSVOMark_7452ef2b,
                            mid_setUnknownType_ebf9e07a,
                            mid_toString_14c7b5c5,
                            mid_toStringSpecial_14c7b5c5,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTokenTags(jobject obj) : ::is::iclt::icenlp::core::tokenizer::TokenTags(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTokenTags(const IceTokenTags& obj) : ::is::iclt::icenlp::core::tokenizer::TokenTags(obj) {}

                        IceTokenTags();
                        IceTokenTags(const ::java::lang::String &, const ::is::iclt::icenlp::core::tokenizer::Token$TokenCode &);

                        void addArticle() const;
                        void addInfinitiveVerbForm() const;
                        void addTag(const ::java::lang::String &) const;
                        void addTagFront(const ::java::lang::String &) const;
                        ::java::lang::String allWordClasses() const;
                        jboolean caseMatch(const IceTokenTags &) const;
                        void cleanTags() const;
                        jboolean genderMatch(const IceTokenTags &) const;
                        jboolean genderNumberCaseMatch(const IceTokenTags &) const;
                        ::java::lang::String getFirstWordClass() const;
                        ::is::iclt::icenlp::core::tokenizer::IceTokenTags$SVOMark getSVOMark() const;
                        ::java::lang::String getSVOMarkString() const;
                        jboolean hasArticle() const;
                        jboolean hasGender() const;
                        jboolean isAdjective() const;
                        jboolean isAdjectiveComparative() const;
                        jboolean isAdjectiveIndeclineable() const;
                        jboolean isAdjectivePositive() const;
                        jboolean isAdjectiveStrong() const;
                        jboolean isAdjectiveSuper() const;
                        jboolean isAdjectiveWeak() const;
                        jboolean isAdverb() const;
                        jboolean isAdverbComparative() const;
                        jboolean isAdverbSuper() const;
                        jboolean isArticle() const;
                        jboolean isCase(jchar) const;
                        jboolean isCompound() const;
                        jboolean isCondition(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags$Condition &) const;
                        jboolean isConjunction() const;
                        jboolean isDeclension(jchar) const;
                        jboolean isDemonstrativePronoun() const;
                        jboolean isExclamation() const;
                        jboolean isGenderPerson(jchar) const;
                        jboolean isIndefinitePronoun() const;
                        jboolean isInfinitive() const;
                        jboolean isInterrogativePronoun() const;
                        jboolean isNominal() const;
                        jboolean isNoun() const;
                        jboolean isNumber(jchar) const;
                        jboolean isNumeral() const;
                        jboolean isNumeralOrdinal() const;
                        jboolean isOnlyAdjectiveSuper() const;
                        jboolean isOnlyAdverbSuper() const;
                        jboolean isOnlyCase(jchar) const;
                        jboolean isOnlyGender(jchar) const;
                        jboolean isOnlyNumber(jchar) const;
                        jboolean isOnlyOneGender() const;
                        jboolean isOnlyOneGenderNumber() const;
                        jboolean isOnlyVerbAny() const;
                        jboolean isOnlyWordClass(const ::is::iclt::icenlp::core::utils::IceTag$WordClass &) const;
                        jboolean isOtherThanWordClass(const ::is::iclt::icenlp::core::utils::IceTag$WordClass &) const;
                        jboolean isPersonalPronoun() const;
                        jboolean isPossessivePronoun() const;
                        jboolean isPreposition() const;
                        jboolean isPronoun() const;
                        jboolean isProperNoun() const;
                        jboolean isReflexivePronoun() const;
                        jboolean isRelativeConjunction() const;
                        jboolean isRelativePronoun() const;
                        jboolean isSVOMainSubject() const;
                        jboolean isSVOMainVerb() const;
                        jboolean isSVONone() const;
                        jboolean isSVOObject() const;
                        jboolean isSVOPrepPhrase() const;
                        jboolean isSVOSubject() const;
                        jboolean isSVOVerb() const;
                        jboolean isUnknownEnding() const;
                        jboolean isUnknownGuessed() const;
                        jboolean isUnknownMorpho() const;
                        jboolean isUnknownNone() const;
                        jboolean isUnknownProperNoun() const;
                        jboolean isVerb() const;
                        jboolean isVerbActive() const;
                        jboolean isVerbAny() const;
                        jboolean isVerbAuxiliary() const;
                        jboolean isVerbBe() const;
                        jboolean isVerbCaseMarking() const;
                        jboolean isVerbImperative() const;
                        jboolean isVerbIndicative() const;
                        jboolean isVerbInf() const;
                        jboolean isVerbInfinitive() const;
                        jboolean isVerbMiddleForm() const;
                        jboolean isVerbPastPart() const;
                        jboolean isVerbPresentPart() const;
                        jboolean isVerbSpecialAuxiliary() const;
                        jboolean isVerbSpecialInf() const;
                        jboolean isVerbSubjunctive() const;
                        jboolean isVerbSupine() const;
                        jboolean isWordClass(const ::is::iclt::icenlp::core::utils::IceTag$WordClass &) const;
                        IceTokenTags makeCopy() const;
                        jint numCases() const;
                        jint numGenders() const;
                        jint numNominals() const;
                        jboolean numberCaseMatch(const IceTokenTags &) const;
                        jboolean numberMatch(const IceTokenTags &) const;
                        jboolean personNumberMatch(const IceTokenTags &) const;
                        void removeAllBut(const ::is::iclt::icenlp::core::utils::IceTag$WordClass &) const;
                        void removeAllButCase(jchar) const;
                        void removeAllButGender(jchar, jboolean) const;
                        void removeAllButNounAdj() const;
                        void removeAllButNumber(jchar) const;
                        void removeAllButProperNounType(jchar) const;
                        void removeAllButVerbs(jboolean) const;
                        void removeArticle() const;
                        void removeCase(jchar, jboolean) const;
                        void removeGender(jchar, jboolean) const;
                        void removeNumber(jchar, jboolean) const;
                        void removeOnCondition(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags$Condition &, const ::is::iclt::icenlp::core::utils::IceTag$WordClass &, jchar) const;
                        void removePronouns() const;
                        void removeProperNounType(jchar) const;
                        void removeVerbForm(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags$Condition &) const;
                        void removeVerbs() const;
                        void removeWordClass(const ::is::iclt::icenlp::core::utils::IceTag$WordClass &) const;
                        void setCase(jchar) const;
                        void setCompound(jboolean) const;
                        void setDeclension(jchar) const;
                        void setDegree(jchar) const;
                        void setGender(jchar) const;
                        void setPlural() const;
                        void setProperNameType(jchar) const;
                        void setSVOMark(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags$SVOMark &) const;
                        void setUnknownType(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags$UnknownType &) const;
                        ::java::lang::String toString() const;
                        ::java::lang::String toStringSpecial() const;
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
                    extern PyTypeObject PY_TYPE(IceTokenTags);

                    class t_IceTokenTags {
                    public:
                        PyObject_HEAD
                        IceTokenTags object;
                        static PyObject *wrap_Object(const IceTokenTags&);
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
