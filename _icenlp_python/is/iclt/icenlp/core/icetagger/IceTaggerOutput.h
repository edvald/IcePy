#ifndef is_iclt_icenlp_core_icetagger_IceTaggerOutput_H
#define is_iclt_icenlp_core_icetagger_IceTaggerOutput_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace tokenizer {
                    class IceTokenTags;
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
    namespace io {
        class IOException;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {

                    class IceTaggerOutput : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_e0d3b7fb,
                            mid_buildOutput_12d5ebc7,
                            mid_buildOutputBaseTagging_e57c73cb,
                            mid_getMappedTag_97a5258f,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTaggerOutput(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTaggerOutput(const IceTaggerOutput& obj) : ::java::lang::Object(obj) {}

                        IceTaggerOutput();
                        IceTaggerOutput(jint, const ::java::lang::String &, jboolean, jboolean, const ::java::lang::String &, jboolean);

                        ::java::lang::String buildOutput(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, jint, jint) const;
                        ::java::lang::String buildOutputBaseTagging(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &) const;
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
                namespace icetagger {
                    extern PyTypeObject PY_TYPE(IceTaggerOutput);

                    class t_IceTaggerOutput {
                    public:
                        PyObject_HEAD
                        IceTaggerOutput object;
                        static PyObject *wrap_Object(const IceTaggerOutput&);
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
