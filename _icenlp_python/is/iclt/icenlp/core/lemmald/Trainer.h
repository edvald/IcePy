#ifndef is_iclt_icenlp_core_lemmald_Trainer_H
#define is_iclt_icenlp_core_lemmald_Trainer_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {
                    class LemmaWord;
                }
            }
        }
    }
}
namespace java {
    namespace util {
        class ArrayList;
        class Hashtable;
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
                namespace lemmald {

                    class Trainer : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_createRules_c996b0ca,
                            mid_createRules_1e41fe25,
                            mid_createRules_eb58b49e,
                            mid_loadTrainingData_e5d0f376,
                            mid_loadTrainingData_e2a42533,
                            mid_trainLemmatizer_4a264742,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Trainer(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Trainer(const Trainer& obj) : ::java::lang::Object(obj) {}

                        Trainer();

                        static ::java::util::Hashtable createRules(const ::is::iclt::icenlp::core::lemmald::LemmaWord &);
                        static ::java::util::Hashtable createRules(const ::is::iclt::icenlp::core::lemmald::LemmaWord &, jboolean);
                        static ::java::util::Hashtable createRules(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, jboolean);
                        static ::java::util::ArrayList loadTrainingData(const ::java::lang::String &);
                        static ::java::util::ArrayList loadTrainingData(const ::java::lang::String &, jboolean);
                        void trainLemmatizer(const ::java::lang::String &, const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(Trainer);

                    class t_Trainer {
                    public:
                        PyObject_HEAD
                        Trainer object;
                        static PyObject *wrap_Object(const Trainer&);
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
