#ifndef is_iclt_icenlp_core_icemorphy_MorphoRules_H
#define is_iclt_icenlp_core_icemorphy_MorphoRules_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icemorphy {
                    class MorphoRuleVerbFinite;
                    class MorphoRuleVerbPastParticiple;
                    class MorphoRuleVerb;
                    class MorphoRuleNounAdjective;
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
                namespace icemorphy {

                    class MorphoRules : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_createNounAdjectivePluralRules_54c6a166,
                            mid_createNounAdjectiveSingularRules_54c6a166,
                            mid_createNounArticleRules_54c6a166,
                            mid_createVerbFiniteRules_54c6a166,
                            mid_createVerbPastParticipleRules_54c6a166,
                            mid_createVerbRules_54c6a166,
                            max_mid
                        };

                        enum {
                            fid_listNounAdjectivePlural,
                            fid_listNounAdjectiveSingular,
                            fid_listNounArticle,
                            fid_listVerb,
                            fid_listVerbFinite,
                            fid_listVerbPastParticiple,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit MorphoRules(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        MorphoRules(const MorphoRules& obj) : ::java::lang::Object(obj) {}

                        ::java::util::ArrayList _get_listNounAdjectivePlural() const;
                        void _set_listNounAdjectivePlural(const ::java::util::ArrayList &) const;
                        ::java::util::ArrayList _get_listNounAdjectiveSingular() const;
                        void _set_listNounAdjectiveSingular(const ::java::util::ArrayList &) const;
                        ::java::util::ArrayList _get_listNounArticle() const;
                        void _set_listNounArticle(const ::java::util::ArrayList &) const;
                        ::java::util::ArrayList _get_listVerb() const;
                        void _set_listVerb(const ::java::util::ArrayList &) const;
                        ::java::util::ArrayList _get_listVerbFinite() const;
                        void _set_listVerbFinite(const ::java::util::ArrayList &) const;
                        ::java::util::ArrayList _get_listVerbPastParticiple() const;
                        void _set_listVerbPastParticiple(const ::java::util::ArrayList &) const;

                        MorphoRules();

                        void createNounAdjectivePluralRules() const;
                        void createNounAdjectiveSingularRules() const;
                        void createNounArticleRules() const;
                        void createVerbFiniteRules() const;
                        void createVerbPastParticipleRules() const;
                        void createVerbRules() const;
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
                namespace icemorphy {
                    extern PyTypeObject PY_TYPE(MorphoRules);

                    class t_MorphoRules {
                    public:
                        PyObject_HEAD
                        MorphoRules object;
                        static PyObject *wrap_Object(const MorphoRules&);
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
