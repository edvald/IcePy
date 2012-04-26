#ifndef is_iclt_icenlp_core_lemmald_RuleDatabase_H
#define is_iclt_icenlp_core_lemmald_RuleDatabase_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {
                    class LemmaRule;
                }
            }
        }
    }
}
namespace java {
    namespace util {
        class HashSet;
    }
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {

                    class RuleDatabase : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_getLemmaRules_dacecad9,
                            mid_loadRules_be2e4f90,
                            mid_loadRules_5fdc3f48,
                            mid_ruleIdExists_5fdc3f44,
                            mid_wordExists_4a26474e,
                            mid_wordFormExists_5fdc3f44,
                            mid_wordFormExistsLoose_5fdc3f44,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit RuleDatabase(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        RuleDatabase(const RuleDatabase& obj) : ::java::lang::Object(obj) {}

                        RuleDatabase();

                        static ::java::util::HashSet getLemmaRules(const ::java::lang::String &);
                        static void loadRules(const ::java::io::InputStream &);
                        static void loadRules(const ::java::lang::String &);
                        static jboolean ruleIdExists(const ::java::lang::String &);
                        static jboolean wordExists(const ::java::lang::String &, const ::java::lang::String &);
                        static jboolean wordFormExists(const ::java::lang::String &);
                        static jboolean wordFormExistsLoose(const ::java::lang::String &);
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
                namespace lemmald {
                    extern PyTypeObject PY_TYPE(RuleDatabase);

                    class t_RuleDatabase {
                    public:
                        PyObject_HEAD
                        RuleDatabase object;
                        static PyObject *wrap_Object(const RuleDatabase&);
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
