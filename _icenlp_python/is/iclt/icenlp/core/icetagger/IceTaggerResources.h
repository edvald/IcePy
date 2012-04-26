#ifndef is_iclt_icenlp_core_icetagger_IceTaggerResources_H
#define is_iclt_icenlp_core_icetagger_IceTaggerResources_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Class;
    }
    namespace io {
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {

                    class IceTaggerResources : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            max_mid
                        };

                        enum {
                            fid_isDictionary,
                            fid_isDictionaryBase,
                            fid_isEndings,
                            fid_isEndingsBase,
                            fid_isEndingsProper,
                            fid_isIdioms,
                            fid_isPrefixes,
                            fid_isTagFrequency,
                            fid_isTokenDict,
                            fid_isVerbAdverb,
                            fid_isVerbObj,
                            fid_isVerbPrep,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit IceTaggerResources(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTaggerResources(const IceTaggerResources& obj) : ::java::lang::Object(obj) {}

                        ::java::io::InputStream _get_isDictionary() const;
                        void _set_isDictionary(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isDictionaryBase() const;
                        void _set_isDictionaryBase(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isEndings() const;
                        void _set_isEndings(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isEndingsBase() const;
                        void _set_isEndingsBase(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isEndingsProper() const;
                        void _set_isEndingsProper(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isIdioms() const;
                        void _set_isIdioms(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isPrefixes() const;
                        void _set_isPrefixes(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isTagFrequency() const;
                        void _set_isTagFrequency(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isTokenDict() const;
                        void _set_isTokenDict(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isVerbAdverb() const;
                        void _set_isVerbAdverb(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isVerbObj() const;
                        void _set_isVerbObj(const ::java::io::InputStream &) const;
                        ::java::io::InputStream _get_isVerbPrep() const;
                        void _set_isVerbPrep(const ::java::io::InputStream &) const;

                        IceTaggerResources();
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
                    extern PyTypeObject PY_TYPE(IceTaggerResources);

                    class t_IceTaggerResources {
                    public:
                        PyObject_HEAD
                        IceTaggerResources object;
                        static PyObject *wrap_Object(const IceTaggerResources&);
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
