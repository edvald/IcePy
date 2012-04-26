#ifndef is_iclt_icenlp_facade_IceParserFacade_H
#define is_iclt_icenlp_facade_IceParserFacade_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class IOException;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {

                class IceParserFacade : public ::java::lang::Object {
                public:
                    enum {
                        mid_init$_54c6a166,
                        mid_main_4dd4540c,
                        mid_parse_97a5258f,
                        mid_parse_edaaade4,
                        mid_parse_3568370d,
                        max_mid
                    };

                    static ::java::lang::Class *class$;
                    static jmethodID *mids$;
                    static jclass initializeClass();

                    explicit IceParserFacade(jobject obj) : ::java::lang::Object(obj) {
                        if (obj != NULL)
                            initializeClass();
                    }
                    IceParserFacade(const IceParserFacade& obj) : ::java::lang::Object(obj) {}

                    IceParserFacade();

                    static void main(const JArray< ::java::lang::String > &);
                    ::java::lang::String parse(const ::java::lang::String &) const;
                    ::java::lang::String parse(const ::java::lang::String &, jboolean) const;
                    ::java::lang::String parse(const ::java::lang::String &, jboolean, jboolean) const;
                };
            }
        }
    }
}

#include <Python.h>

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace facade {
                extern PyTypeObject PY_TYPE(IceParserFacade);

                class t_IceParserFacade {
                public:
                    PyObject_HEAD
                    IceParserFacade object;
                    static PyObject *wrap_Object(const IceParserFacade&);
                    static PyObject *wrap_jobject(const jobject&);
                    static void install(PyObject *module);
                    static void initialize(PyObject *module);
                };
            }
        }
    }
}

#endif
