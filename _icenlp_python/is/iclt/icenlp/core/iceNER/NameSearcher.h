#ifndef is_iclt_icenlp_core_iceNER_NameSearcher_H
#define is_iclt_icenlp_core_iceNER_NameSearcher_H

#include "java/lang/Object.h"

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
                namespace iceNER {

                    class NameSearcher : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_bb0c767f,
                            mid_init$_aa079ca4,
                            mid_init$_b91b375c,
                            mid_cleanup_54c6a166,
                            mid_cleanupPersons_54c6a166,
                            mid_completePartlyFoundNames_54c6a166,
                            mid_findCompanyByLocation_54c6a166,
                            mid_findFromAction_54c6a166,
                            mid_findFromCapitalLetters_54c6a166,
                            mid_findFromInitilas_54c6a166,
                            mid_findFromRole_54c6a166,
                            mid_findLocationsFromAdverb_54c6a166,
                            mid_findPersonByAge_54c6a166,
                            mid_findPersonFromLocation_54c6a166,
                            mid_findPersonFromRole_54c6a166,
                            mid_fixCompanyLocation_54c6a166,
                            mid_fixPersonNames_54c6a166,
                            mid_getNameTag_97a5258f,
                            mid_getRoleTag_97a5258f,
                            mid_indexNamedEntity_54c6a166,
                            mid_listAllIndexedNames_54c6a166,
                            mid_loadNameHash_4a264742,
                            mid_loadRoleHash_4a264742,
                            mid_loadScannerFile_6e53ccca,
                            mid_loadSearcher_aa079ca4,
                            mid_loadSearcher_b91b375c,
                            mid_loadTaggedFile_6e53ccca,
                            mid_looForPairs_54c6a166,
                            mid_lookForAdjectiveInName_54c6a166,
                            mid_lookForDifferentCases_54c6a166,
                            mid_lookForListings_54c6a166,
                            mid_lookForMissedCompanies_54c6a166,
                            mid_lookForNounInName_54c6a166,
                            mid_lookForUnmatchedFromHash_54c6a166,
                            mid_lookForUnmatchedFromRole_54c6a166,
                            mid_markFromHash_bb0c767f,
                            mid_markMiscEntities_54c6a166,
                            mid_nameHashcontains_5fdc3f44,
                            mid_overwriteNameHash_4a264742,
                            mid_printIndexList_54c6a166,
                            mid_printMarkedText_54c6a166,
                            mid_printNameHash_54c6a166,
                            mid_printRoleHash_54c6a166,
                            mid_roleHashContains_5fdc3f44,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit NameSearcher(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        NameSearcher(const NameSearcher& obj) : ::java::lang::Object(obj) {}

                        NameSearcher(jboolean);
                        NameSearcher(const ::java::lang::String &, jint, const ::java::lang::String &, jint, const ::java::lang::String &);
                        NameSearcher(const ::java::lang::String &, jint, const ::java::lang::String &, jint, const ::java::lang::String &, const ::java::lang::String &, jint);

                        void cleanup() const;
                        void cleanupPersons() const;
                        void completePartlyFoundNames() const;
                        void findCompanyByLocation() const;
                        void findFromAction() const;
                        void findFromCapitalLetters() const;
                        void findFromInitilas() const;
                        void findFromRole() const;
                        void findLocationsFromAdverb() const;
                        void findPersonByAge() const;
                        void findPersonFromLocation() const;
                        void findPersonFromRole() const;
                        void fixCompanyLocation() const;
                        void fixPersonNames() const;
                        ::java::lang::String getNameTag(const ::java::lang::String &) const;
                        ::java::lang::String getRoleTag(const ::java::lang::String &) const;
                        void indexNamedEntity() const;
                        void listAllIndexedNames() const;
                        void loadNameHash(const ::java::lang::String &, const ::java::lang::String &) const;
                        void loadRoleHash(const ::java::lang::String &, const ::java::lang::String &) const;
                        jboolean loadScannerFile(const ::java::lang::String &, jint) const;
                        void loadSearcher(const ::java::lang::String &, jint, const ::java::lang::String &, jint, const ::java::lang::String &) const;
                        void loadSearcher(const ::java::lang::String &, jint, const ::java::lang::String &, jint, const ::java::lang::String &, const ::java::lang::String &, jint) const;
                        jboolean loadTaggedFile(const ::java::lang::String &, jint) const;
                        void looForPairs() const;
                        void lookForAdjectiveInName() const;
                        void lookForDifferentCases() const;
                        void lookForListings() const;
                        void lookForMissedCompanies() const;
                        void lookForNounInName() const;
                        void lookForUnmatchedFromHash() const;
                        void lookForUnmatchedFromRole() const;
                        void markFromHash(jboolean) const;
                        void markMiscEntities() const;
                        jboolean nameHashcontains(const ::java::lang::String &) const;
                        void overwriteNameHash(const ::java::lang::String &, const ::java::lang::String &) const;
                        void printIndexList() const;
                        void printMarkedText() const;
                        void printNameHash() const;
                        void printRoleHash() const;
                        jboolean roleHashContains(const ::java::lang::String &) const;
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
                namespace iceNER {
                    extern PyTypeObject PY_TYPE(NameSearcher);

                    class t_NameSearcher {
                    public:
                        PyObject_HEAD
                        NameSearcher object;
                        static PyObject *wrap_Object(const NameSearcher&);
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
