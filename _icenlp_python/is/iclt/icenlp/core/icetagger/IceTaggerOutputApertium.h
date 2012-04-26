#ifndef is_iclt_icenlp_core_icetagger_IceTaggerOutputApertium_H
#define is_iclt_icenlp_core_icetagger_IceTaggerOutputApertium_H

#include "is/iclt/icenlp/core/icetagger/IceTaggerOutput.h"

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

                    class IceTaggerOutputApertium : public ::is::iclt::icenlp::core::icetagger::IceTaggerOutput {
                    public:
                        enum {
                            mid_init$_e0d3b7fb,
                            mid_buildOutput_12d5ebc7,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit IceTaggerOutputApertium(jobject obj) : ::is::iclt::icenlp::core::icetagger::IceTaggerOutput(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTaggerOutputApertium(const IceTaggerOutputApertium& obj) : ::is::iclt::icenlp::core::icetagger::IceTaggerOutput(obj) {}

                        IceTaggerOutputApertium(jint, const ::java::lang::String &, jboolean, jboolean, const ::java::lang::String &, jboolean);

                        ::java::lang::String buildOutput(const ::is::iclt::icenlp::core::tokenizer::IceTokenTags &, jint, jint) const;
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
                    extern PyTypeObject PY_TYPE(IceTaggerOutputApertium);

                    class t_IceTaggerOutputApertium {
                    public:
                        PyObject_HEAD
                        IceTaggerOutputApertium object;
                        static PyObject *wrap_Object(const IceTaggerOutputApertium&);
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
