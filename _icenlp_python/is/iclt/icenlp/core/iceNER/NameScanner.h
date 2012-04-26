#ifndef is_iclt_icenlp_core_iceNER_NameScanner_H
#define is_iclt_icenlp_core_iceNER_NameScanner_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace io {
        class InputStream;
        class IOException;
        class Reader;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace iceNER {

                    class NameScanner : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_be2e4f90,
                            mid_init$_cf2e3c10,
                            mid_main_4dd4540c,
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

                        explicit NameScanner(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        NameScanner(const NameScanner& obj) : ::java::lang::Object(obj) {}

                        static jint YYEOF;
                        static jint YYINITIAL;

                        NameScanner(const ::java::io::InputStream &);
                        NameScanner(const ::java::io::Reader &);

                        static void main(const JArray< ::java::lang::String > &);
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
                namespace iceNER {
                    extern PyTypeObject PY_TYPE(NameScanner);

                    class t_NameScanner {
                    public:
                        PyObject_HEAD
                        NameScanner object;
                        static PyObject *wrap_Object(const NameScanner&);
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
