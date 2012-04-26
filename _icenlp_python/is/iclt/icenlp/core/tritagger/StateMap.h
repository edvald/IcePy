#ifndef is_iclt_icenlp_core_tritagger_StateMap_H
#define is_iclt_icenlp_core_tritagger_StateMap_H

#include "java/lang/Object.h"

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
                namespace tritagger {

                    class StateMap : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_getFirstTag_141401b3,
                            mid_getSecondTag_141401b3,
                            mid_getState_141401b3,
                            mid_getStateId_5fdc3f57,
                            mid_getStateId_4a26475d,
                            mid_mapTagsBigrams_b3f662e6,
                            mid_mapTagsTrigrams_b3f662e6,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit StateMap(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        StateMap(const StateMap& obj) : ::java::lang::Object(obj) {}

                        StateMap();

                        ::java::lang::String getFirstTag(jint) const;
                        ::java::lang::String getSecondTag(jint) const;
                        ::java::lang::String getState(jint) const;
                        jint getStateId(const ::java::lang::String &) const;
                        jint getStateId(const ::java::lang::String &, const ::java::lang::String &) const;
                        jint mapTagsBigrams(const ::java::util::ArrayList &) const;
                        jint mapTagsTrigrams(const ::java::util::ArrayList &) const;
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
                namespace tritagger {
                    extern PyTypeObject PY_TYPE(StateMap);

                    class t_StateMap {
                    public:
                        PyObject_HEAD
                        StateMap object;
                        static PyObject *wrap_Object(const StateMap&);
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
