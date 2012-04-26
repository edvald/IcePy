#ifndef is_iclt_icenlp_core_iceparser_Func_QUAL_H
#define is_iclt_icenlp_core_iceparser_Func_QUAL_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class InputStream;
        class Writer;
        class IOException;
        class Reader;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace iceparser {

                    class Func_QUAL : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_cf2e3c10,
                            mid_init$_be2e4f90,
                            mid_main_4dd4540c,
                            mid_parse_5bcd5850,
                            mid_yybegin_39c7bd3c,
                            mid_yycharat_39c7bd29,
                            mid_yyclose_54c6a166,
                            mid_yylength_54c6a179,
                            mid_yylex_54c6a179,
                            mid_yypushback_39c7bd3c,
                            mid_yyreset_cf2e3c10,
                            mid_yystate_54c6a179,
                            mid_yytext_14c7b5c5,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Func_QUAL(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Func_QUAL(const Func_QUAL& obj) : ::java::lang::Object(obj) {}

                        static jint YYEOF;
                        static jint YYINITIAL;

                        Func_QUAL(const ::java::io::Reader &);
                        Func_QUAL(const ::java::io::InputStream &);

                        static void main(const JArray< ::java::lang::String > &);
                        void parse(const ::java::io::Writer &) const;
                        void yybegin(jint) const;
                        jchar yycharat(jint) const;
                        void yyclose() const;
                        jint yylength() const;
                        jint yylex() const;
                        void yypushback(jint) const;
                        void yyreset(const ::java::io::Reader &) const;
                        jint yystate() const;
                        ::java::lang::String yytext() const;
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
                namespace iceparser {
                    extern PyTypeObject PY_TYPE(Func_QUAL);

                    class t_Func_QUAL {
                    public:
                        PyObject_HEAD
                        Func_QUAL object;
                        static PyObject *wrap_Object(const Func_QUAL&);
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
