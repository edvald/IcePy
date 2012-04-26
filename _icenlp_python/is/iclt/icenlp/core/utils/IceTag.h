#ifndef is_iclt_icenlp_core_utils_IceTag_H
#define is_iclt_icenlp_core_utils_IceTag_H

#include "is/iclt/icenlp/core/utils/Tag.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class IceTag$WordClass;
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
                namespace utils {

                    class IceTag : public ::is::iclt::icenlp::core::utils::Tag {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_5fdc3f48,
                            mid_addArticle_54c6a166,
                            mid_annotation_445a175e,
                            mid_caseMatch_9c6a1362,
                            mid_caseMatch_b3f662f5,
                            mid_genderNumberCaseMatch_9c6a1362,
                            mid_genderNumberCaseMatch_b3f662f5,
                            mid_getCaseLetter_54c6a173,
                            mid_getDeclension_54c6a173,
                            mid_getNumberLetter_54c6a173,
                            mid_getPersonGenderLetter_54c6a173,
                            mid_getProperNounType_54c6a173,
                            mid_getWordClass_14c7b5c5,
                            mid_getWordClassCode_230f6e5d,
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
                            mid_isConjunction_54c6a16a,
                            mid_isDeclension_87fd5456,
                            mid_isDemonstrativePronoun_54c6a16a,
                            mid_isExclamation_54c6a16a,
                            mid_isForeign_54c6a16a,
                            mid_isGender_87fd5456,
                            mid_isIndefinitePronoun_54c6a16a,
                            mid_isInfinitive_54c6a16a,
                            mid_isInterrogativePronoun_54c6a16a,
                            mid_isNominal_54c6a16a,
                            mid_isNoun_54c6a16a,
                            mid_isNumber_87fd5456,
                            mid_isNumeral_54c6a16a,
                            mid_isNumeralNominal_54c6a16a,
                            mid_isNumeralOrdinal_54c6a16a,
                            mid_isPersonalPronoun_54c6a16a,
                            mid_isPossessivePronoun_54c6a16a,
                            mid_isPreposition_54c6a16a,
                            mid_isPronoun_54c6a16a,
                            mid_isProperNoun_54c6a16a,
                            mid_isProperNounType_87fd5456,
                            mid_isReflexivePronoun_54c6a16a,
                            mid_isRelativeConjunction_54c6a16a,
                            mid_isRelativePronoun_54c6a16a,
                            mid_isVerb_54c6a16a,
                            mid_isVerbActiveForm_54c6a16a,
                            mid_isVerbAny_54c6a16a,
                            mid_isVerbAuxiliary_54c6a16a,
                            mid_isVerbBe_54c6a16a,
                            mid_isVerbCaseMarking_54c6a16a,
                            mid_isVerbImperative_54c6a16a,
                            mid_isVerbIndicativeForm_54c6a16a,
                            mid_isVerbInfinitive_54c6a16a,
                            mid_isVerbMarking_54c6a16a,
                            mid_isVerbMiddleForm_54c6a16a,
                            mid_isVerbPastParticiple_54c6a16a,
                            mid_isVerbPresentPart_54c6a16a,
                            mid_isVerbSpecialAuxiliary_54c6a16a,
                            mid_isVerbSpecialInf_54c6a16a,
                            mid_isVerbSubjunctiveForm_54c6a16a,
                            mid_isVerbSupine_54c6a16a,
                            mid_isWordClass_0dc1bb34,
                            mid_numberCaseMatch_b3f662f5,
                            mid_numberCaseMatch_9c6a1362,
                            mid_numberMatch_9c6a1362,
                            mid_numberMatch_b3f662f5,
                            mid_personGenderMatch_b3f662f5,
                            mid_personGenderMatch_9c6a1362,
                            mid_personGenderNumberMatch_b3f662f5,
                            mid_personGenderNumberMatch_9c6a1362,
                            mid_removeArticle_54c6a166,
                            mid_setCase_87fd545a,
                            mid_setDeclension_87fd545a,
                            mid_setDegree_87fd545a,
                            mid_setGenderNumberCase_094d1f92,
                            mid_setNumber_87fd545a,
                            mid_setPersonGender_87fd545a,
                            mid_setPersonName_54c6a166,
                            mid_setProperNameType_87fd545a,
                            mid_setTense_87fd545a,
                            mid_setVoice_87fd545a,
                            mid_interpretTag_54c6a166,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTag(jobject obj) : ::is::iclt::icenlp::core::utils::Tag(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTag(const IceTag& obj) : ::is::iclt::icenlp::core::utils::Tag(obj) {}

                        static jchar cAbbreviation;
                        static jchar cAccusative;
                        static jchar cActive;
                        static jchar cAdverb;
                        static jchar cArticle;
                        static jchar cArticlePreceding;
                        static jchar cComparative;
                        static jchar cConjunction;
                        static jchar cConjunctionRel;
                        static jchar cDative;
                        static jchar cDemPronoun;
                        static jchar cExclamation;
                        static jchar cFeminine;
                        static jchar cFirstPerson;
                        static jchar cGenderUnspec;
                        static jchar cGenitive;
                        static jchar cImperative;
                        static jchar cIndeclineable;
                        static jchar cIndefPronoun;
                        static jchar cIndicative;
                        static jchar cInfinitive;
                        static jchar cInterPronoun;
                        static jchar cMasculine;
                        static jchar cMiddle;
                        static jchar cNeuter;
                        static jchar cNoDeclension;
                        static jchar cNoMatch;
                        static jchar cNominative;
                        static jchar cNumberUnspec;
                        static jchar cOtherName;
                        static jchar cPast;
                        static jchar cPastParticiple;
                        static jchar cPersPronoun;
                        static jchar cPersonName;
                        static jchar cPlaceName;
                        static jchar cPlural;
                        static jchar cPositive;
                        static jchar cPossPronoun;
                        static jchar cPresParticiple;
                        static jchar cPresent;
                        static jchar cReflPronoun;
                        static jchar cRelPronoun;
                        static jchar cSecondPerson;
                        static jchar cSingular;
                        static jchar cStrong;
                        static jchar cSubjunctive;
                        static jchar cSuperlative;
                        static jchar cSupine;
                        static jchar cThirdPerson;
                        static jchar cUndef;
                        static jchar cWeak;
                        static jchar cWildCard;
                        static ::java::lang::String *tagAdj;
                        static ::java::lang::String *tagAdjectiveComparative;
                        static ::java::lang::String *tagAdjectiveFeminineSingularStrongNominative;
                        static ::java::lang::String *tagAdjectiveNeuterPluralStrongAccusative;
                        static ::java::lang::String *tagAdjectiveNeuterPluralStrongNominative;
                        static ::java::lang::String *tagAdjectivesIndeclineable;
                        static ::java::lang::String *tagAdjectivesPlural;
                        static ::java::lang::String *tagAdjectivesSingular;
                        static ::java::lang::String *tagAdverb;
                        static ::java::lang::String *tagCardinalsPlural;
                        static ::java::lang::String *tagCardinalsSingular;
                        static ::java::lang::String *tagForeign;
                        static ::java::lang::String *tagMostFrequentNoun;
                        static ::java::lang::String *tagMostFrequentProperNoun;
                        static ::java::lang::String *tagNoun;
                        static ::java::lang::String *tagNounFeminineFirstThree;
                        static ::java::lang::String *tagNounMasculinePluralNominative;
                        static ::java::lang::String *tagNounMasculinePluralNominativeArticle;
                        static ::java::lang::String *tagNounMasculineWeak;
                        static ::java::lang::String *tagNounNeuter;
                        static ::java::lang::String *tagNounNeuterPlural;
                        static ::java::lang::String *tagNounNeuterPluralArticle;
                        static ::java::lang::String *tagNounNeuterSingular;
                        static ::java::lang::String *tagNounNeuterSingularArticle;
                        static ::java::lang::String *tagOrdinal;
                        static ::java::lang::String *tagOrdinal2;
                        static ::java::lang::String *tagPercentage;
                        static ::java::lang::String *tagProperNoun;
                        static ::java::lang::String *tagProperNounOther;
                        static ::java::lang::String *tagProperNounPlace;
                        static ::java::lang::String *tagVerb;
                        static ::java::lang::String *tagVerbFirstSingular;
                        static ::java::lang::String *tagVerbFirstSingularPast;
                        static ::java::lang::String *tagVerbFirstSingularSubjunctive;
                        static ::java::lang::String *tagVerbImperative;
                        static ::java::lang::String *tagVerbInfActive;
                        static ::java::lang::String *tagVerbInfMiddle;
                        static ::java::lang::String *tagVerbMiddle;
                        static ::java::lang::String *tagVerbPastPart;
                        static ::java::lang::String *tagVerbPresentPart;
                        static ::java::lang::String *tagVerbSecondSingular;
                        static ::java::lang::String *tagVerbSubjunctive;
                        static ::java::lang::String *tagVerbSupine;
                        static ::java::lang::String *tagVerbSupineMiddle;
                        static ::java::lang::String *tagVerbThirdPlural;
                        static ::java::lang::String *tagVerbThirdPluralMiddle;
                        static ::java::lang::String *tagVerbThirdPluralSubjunctive;
                        static ::java::lang::String *tagVerbThirdSingular;
                        static ::java::lang::String *tagVerbThirdSingularPast;
                        static ::java::lang::String *tagVerbThirdSingularSubjunctive;

                        IceTag();
                        IceTag(const ::java::lang::String &);

                        void addArticle() const;
                        ::java::lang::String annotation(jboolean) const;
                        jboolean caseMatch(const IceTag &) const;
                        jboolean caseMatch(const ::java::util::ArrayList &) const;
                        jboolean genderNumberCaseMatch(const IceTag &) const;
                        jboolean genderNumberCaseMatch(const ::java::util::ArrayList &) const;
                        jchar getCaseLetter() const;
                        jchar getDeclension() const;
                        jchar getNumberLetter() const;
                        jchar getPersonGenderLetter() const;
                        jchar getProperNounType() const;
                        ::java::lang::String getWordClass() const;
                        ::is::iclt::icenlp::core::utils::IceTag$WordClass getWordClassCode() const;
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
                        jboolean isConjunction() const;
                        jboolean isDeclension(jchar) const;
                        jboolean isDemonstrativePronoun() const;
                        jboolean isExclamation() const;
                        jboolean isForeign() const;
                        jboolean isGender(jchar) const;
                        jboolean isIndefinitePronoun() const;
                        jboolean isInfinitive() const;
                        jboolean isInterrogativePronoun() const;
                        jboolean isNominal() const;
                        jboolean isNoun() const;
                        jboolean isNumber(jchar) const;
                        jboolean isNumeral() const;
                        jboolean isNumeralNominal() const;
                        jboolean isNumeralOrdinal() const;
                        jboolean isPersonalPronoun() const;
                        jboolean isPossessivePronoun() const;
                        jboolean isPreposition() const;
                        jboolean isPronoun() const;
                        jboolean isProperNoun() const;
                        jboolean isProperNounType(jchar) const;
                        jboolean isReflexivePronoun() const;
                        jboolean isRelativeConjunction() const;
                        jboolean isRelativePronoun() const;
                        jboolean isVerb() const;
                        jboolean isVerbActiveForm() const;
                        jboolean isVerbAny() const;
                        jboolean isVerbAuxiliary() const;
                        jboolean isVerbBe() const;
                        jboolean isVerbCaseMarking() const;
                        jboolean isVerbImperative() const;
                        jboolean isVerbIndicativeForm() const;
                        jboolean isVerbInfinitive() const;
                        jboolean isVerbMarking() const;
                        jboolean isVerbMiddleForm() const;
                        jboolean isVerbPastParticiple() const;
                        jboolean isVerbPresentPart() const;
                        jboolean isVerbSpecialAuxiliary() const;
                        jboolean isVerbSpecialInf() const;
                        jboolean isVerbSubjunctiveForm() const;
                        jboolean isVerbSupine() const;
                        jboolean isWordClass(const ::is::iclt::icenlp::core::utils::IceTag$WordClass &) const;
                        jboolean numberCaseMatch(const ::java::util::ArrayList &) const;
                        jboolean numberCaseMatch(const IceTag &) const;
                        jboolean numberMatch(const IceTag &) const;
                        jboolean numberMatch(const ::java::util::ArrayList &) const;
                        jboolean personGenderMatch(const ::java::util::ArrayList &) const;
                        jboolean personGenderMatch(const IceTag &) const;
                        jboolean personGenderNumberMatch(const ::java::util::ArrayList &) const;
                        jboolean personGenderNumberMatch(const IceTag &) const;
                        void removeArticle() const;
                        void setCase(jchar) const;
                        void setDeclension(jchar) const;
                        void setDegree(jchar) const;
                        void setGenderNumberCase(jchar, jchar, jchar) const;
                        void setNumber(jchar) const;
                        void setPersonGender(jchar) const;
                        void setPersonName() const;
                        void setProperNameType(jchar) const;
                        void setTense(jchar) const;
                        void setVoice(jchar) const;
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
                    extern PyTypeObject PY_TYPE(IceTag);

                    class t_IceTag {
                    public:
                        PyObject_HEAD
                        IceTag object;
                        static PyObject *wrap_Object(const IceTag&);
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
