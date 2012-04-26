#ifndef is_iclt_icenlp_core_lemmald_LemmaldSettings_H
#define is_iclt_icenlp_core_lemmald_LemmaldSettings_H

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
                namespace lemmald {

                    class LemmaldSettings : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_getProperty_97a5258f,
                            mid_isOn_5fdc3f44,
                            mid_setValue_f3691645,
                            mid_setValue_4a264742,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit LemmaldSettings(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        LemmaldSettings(const LemmaldSettings& obj) : ::java::lang::Object(obj) {}

                        LemmaldSettings();

                        static ::java::lang::String getProperty(const ::java::lang::String &);
                        static jboolean isOn(const ::java::lang::String &);
                        static void setValue(const ::java::lang::String &, jboolean);
                        static void setValue(const ::java::lang::String &, const ::java::lang::String &);
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
                    extern PyTypeObject PY_TYPE(LemmaldSettings);

                    class t_LemmaldSettings {
                    public:
                        PyObject_HEAD
                        LemmaldSettings object;
                        static PyObject *wrap_Object(const LemmaldSettings&);
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
