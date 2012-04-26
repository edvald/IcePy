#ifndef is_iclt_icenlp_core_utils_Tag_H
#define is_iclt_icenlp_core_utils_Tag_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Character;
        class Class;
        class String;
    }
}
template<class T> class JArray;

namespace is {
    namespace iclt {
        namespace icenlp {
            namespace core {
                namespace utils {

                    class Tag : public ::java::lang::Object {
                    public:
                        enum {
                            mid_init$_54c6a166,
                            mid_init$_5fdc3f48,
                            mid_clearTagStr_54c6a166,
                            mid_getFirstLetter_ecb29eea,
                            mid_getTagStr_14c7b5c5,
                            mid_isValid_54c6a16a,
                            mid_setTagStr_5fdc3f48,
                            mid_setValid_bb0c767f,
                            mid_toString_14c7b5c5,
                            mid_interpretTag_54c6a166,
                            max_mid
                        };

                        static ::java::lang::Class *class$;
                        static jmethodID *mids$;
                        static jclass initializeClass();

                        explicit Tag(jobject obj) : ::java::lang::Object(obj) {
                            if (obj != NULL)
                                initializeClass();
                        }
                        Tag(const Tag& obj) : ::java::lang::Object(obj) {}

                        Tag();
                        Tag(const ::java::lang::String &);

                        void clearTagStr() const;
                        ::java::lang::Character getFirstLetter() const;
                        ::java::lang::String getTagStr() const;
                        jboolean isValid() const;
                        void setTagStr(const ::java::lang::String &) const;
                        void setValid(jboolean) const;
                        ::java::lang::String toString() const;
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
                namespace utils {
                    extern PyTypeObject PY_TYPE(Tag);

                    class t_Tag {
                    public:
                        PyObject_HEAD
                        Tag object;
                        static PyObject *wrap_Object(const Tag&);
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
