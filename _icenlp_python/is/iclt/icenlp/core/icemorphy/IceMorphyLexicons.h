#ifndef is_iclt_icenlp_core_icemorphy_IceMorphyLexicons_H
#define is_iclt_icenlp_core_icemorphy_IceMorphyLexicons_H

#include "java/lang/Object.h"

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {
                    class WordList;
                    class Trie;
                    class Lexicon;
                }
                namespace icetagger {
                    class IceFrequency;
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
                namespace icemorphy {

                    class IceMorphyLexicons : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_5fdc3f48,
                            mid_init$_c465e1dc,
                            mid_init$_a2a4aeec,
                            max_mid
                        };

                        enum {
                            fid_baseDict,
                            fid_dict,
                            fid_dictPathTagger,
                            fid_endings,
                            fid_endingsBase,
                            fid_endingsProper,
                            fid_prefixes,
                            fid_tagFrequency,
                            max_fid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jfieldID *fids$;
                        static jclass initializeClass();

                        explicit IceMorphyLexicons(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        IceMorphyLexicons(const IceMorphyLexicons& obj) : ::java::lang::Object(obj) {}

                        static ::java::lang::String *dictionary;
                        static ::java::lang::String *dictionaryBase;
                        static ::java::lang::String *endingsBaseDictionary;
                        static ::java::lang::String *endingsDictionary;
                        static ::java::lang::String *endingsProperDictionary;
                        static ::java::lang::String *prefixesDictionary;
                        static ::java::lang::String *tagFrequencyFile;

                        ::is::iclt::icenlp::core::utils::Lexicon _get_baseDict() const;
                        void _set_baseDict(const ::is::iclt::icenlp::core::utils::Lexicon &) const;
                        ::is::iclt::icenlp::core::utils::Lexicon _get_dict() const;
                        void _set_dict(const ::is::iclt::icenlp::core::utils::Lexicon &) const;
                        ::java::lang::String _get_dictPathTagger() const;
                        void _set_dictPathTagger(const ::java::lang::String &) const;
                        ::is::iclt::icenlp::core::utils::Trie _get_endings() const;
                        void _set_endings(const ::is::iclt::icenlp::core::utils::Trie &) const;
                        ::is::iclt::icenlp::core::utils::Trie _get_endingsBase() const;
                        void _set_endingsBase(const ::is::iclt::icenlp::core::utils::Trie &) const;
                        ::is::iclt::icenlp::core::utils::Trie _get_endingsProper() const;
                        void _set_endingsProper(const ::is::iclt::icenlp::core::utils::Trie &) const;
                        ::is::iclt::icenlp::core::utils::WordList _get_prefixes() const;
                        void _set_prefixes(const ::is::iclt::icenlp::core::utils::WordList &) const;
                        ::is::iclt::icenlp::core::icetagger::IceFrequency _get_tagFrequency() const;
                        void _set_tagFrequency(const ::is::iclt::icenlp::core::icetagger::IceFrequency &) const;

                        IceMorphyLexicons(const ::java::lang::String &);
                        IceMorphyLexicons(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &);
                        IceMorphyLexicons(const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &, const ::java::io::InputStream &);
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
                namespace icemorphy {
                    extern PyTypeObject PY_TYPE(IceMorphyLexicons);

                    class t_IceMorphyLexicons {
                    public:
                        PyObject_HEAD
                        IceMorphyLexicons object;
                        static PyObject *wrap_Object(const IceMorphyLexicons&);
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
