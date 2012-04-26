#ifndef is_iclt_icenlp_core_tokenizer_SrxSegmentizer_H
#define is_iclt_icenlp_core_tokenizer_SrxSegmentizer_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
        class String;
    }
    namespace util {
        class List;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {

                    class SrxSegmentizer : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_5fdc3f48,
                            mid_getInstance_5a565ae2,
                            mid_main_4dd4540c,
                            mid_newInstance_5a565ae2,
                            mid_runStdin_54c6a166,
                            mid_runTextFiles_4a264742,
                            mid_sentencePerLine_97a5258f,
                            mid_setSingleLineBreaksMarksParagraph_bb0c767f,
                            mid_singleLineBreaksMarksPara_54c6a16a,
                            mid_terminate_54c6a166,
                            mid_tokenize_0feb8f08,
                            mid_finalize_54c6a166,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit SrxSegmentizer(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        SrxSegmentizer(const SrxSegmentizer& obj) : ::java::lang::Object(obj) {}

                        SrxSegmentizer(const ::java::lang::String &);

                        static SrxSegmentizer getInstance();
                        static void main(const JArray< ::java::lang::String > &);
                        static SrxSegmentizer newInstance();
                        void runStdin() const;
                        void runTextFiles(const ::java::lang::String &, const ::java::lang::String &) const;
                        ::java::lang::String sentencePerLine(const ::java::lang::String &) const;
                        void setSingleLineBreaksMarksParagraph(jboolean) const;
                        jboolean singleLineBreaksMarksPara() const;
                        static void terminate();
                        ::java::util::List tokenize(const ::java::lang::String &) const;
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
                namespace tokenizer {
                    extern PyTypeObject PY_TYPE(SrxSegmentizer);

                    class t_SrxSegmentizer {
                    public:
                        PyObject_HEAD
                        SrxSegmentizer object;
                        static PyObject *wrap_Object(const SrxSegmentizer&);
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
