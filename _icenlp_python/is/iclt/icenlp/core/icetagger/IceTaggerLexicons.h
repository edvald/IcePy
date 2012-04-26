#ifndef is_iclt_icenlp_core_icetagger_IceTaggerLexicons_H
#define is_iclt_icenlp_core_icetagger_IceTaggerLexicons_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {
                    class IceTaggerResources;
                }
                namespace icemorphy {
                    class IceMorphyLexicons;
                }
                namespace utils {
                    class Idioms;
                    class Lexicon;
                }
            }
        }
    }
}
namespace java {
    namespace lang {
        class String;
        class NullPointerException;
        class Class;
    }
    namespace io {
        class IOException;
        class InputStream;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace icetagger {

                    class IceTaggerLexicons : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_5fdc3f48,
                            mid_init$_ed492aad,
                            mid_init$_e879ad94,
                            mid_init$_d5b020e4,
                            max_mid
                        };

                        enum {
                            fid_dictPathTagger,
                            fid_idioms,
                            fid_morphyLexicons,
                            fid_verbAdverb,
                            fid_verbObj,
                            fid_verbPrep,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit IceTaggerLexicons(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceTaggerLexicons(const IceTaggerLexicons& obj) : ::java::lang::Object(obj) {}

                        static ::java::lang::String *idiomsDictionary;
                        static ::java::lang::String *verbAdverbDictionary;
                        static ::java::lang::String *verbObjDictionary;
                        static ::java::lang::String *verbPrepDictionary;

                        ::java::lang::String _get_dictPathTagger() const;
                        void _set_dictPathTagger(const ::java::lang::String &) const;
                        ::is::iclt::icenlp::core::utils::Idioms _get_idioms() const;
                        void _set_idioms(const ::is::iclt::icenlp::core::utils::Idioms &) const;
                        ::is::iclt::icenlp::core::icemorphy::IceMorphyLexicons _get_morphyLexicons() const;
                        void _set_morphyLexicons(const ::is::iclt::icenlp::core::icemorphy::IceMorphyLexicons &) const;
                        ::is::iclt::icenlp::core::utils::Lexicon _get_verbAdverb() const;
                        void _set_verbAdverb(const ::is::iclt::icenlp::core::utils::Lexicon &) const;
                        ::is::iclt::icenlp::core::utils::Lexicon _get_verbObj() const;
                        void _set_verbObj(const ::is::iclt::icenlp::core::utils::Lexicon &) const;
                        ::is::iclt::icenlp::core::utils::Lexicon _get_verbPrep() const;
                        void _set_verbPrep(const ::is::iclt::icenlp::core::utils::Lexicon &) const;

                        IceTaggerLexicons(const ::java::lang::String &);
                        IceTaggerLexicons(const ::is::iclt::icenlp::core::icetagger::IceTaggerResources &);
                        IceTaggerLexicons(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &);
                        IceTaggerLexicons(const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &);
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
                    extern PyTypeObject PY_TYPE(IceTaggerLexicons);

                    class t_IceTaggerLexicons {
                    public:
                        PyObject_HEAD
                        IceTaggerLexicons object;
                        static PyObject *wrap_Object(const IceTaggerLexicons&);
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
