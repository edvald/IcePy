#ifndef is_iclt_icenlp_core_lemmald_Tester_H
#define is_iclt_icenlp_core_lemmald_Tester_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace lemmald {
                    class Lemmald;
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
                namespace lemmald {

                    class Tester : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_945fe657,
                            mid_runLemmatizerTest_5fdc3f48,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Tester(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Tester(const Tester& obj) : ::java::lang::Object(obj) {}

                        Tester(const ::is::iclt::icenlp::core::lemmald::Lemmald &);

                        void runLemmatizerTest(const ::java::lang::String &) const;
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
                    extern PyTypeObject PY_TYPE(Tester);

                    class t_Tester {
                    public:
                        PyObject_HEAD
                        Tester object;
                        static PyObject *wrap_Object(const Tester&);
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
