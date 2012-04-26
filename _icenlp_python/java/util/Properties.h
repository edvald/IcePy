#ifndef java_util_Properties_H
#define java_util_Properties_H

#include "java/util/Hashtable.h"

namespace java {
    namespace util {
        class Set;
        class Enumeration;
        class InvalidPropertiesFormatException;
    }
    namespace lang {
        class Object;
        class Class;
        class String;
    }
    namespace io {
        class PrintWriter;
        class PrintStream;
        class Writer;
        class InputStream;
        class OutputStream;
        class IOException;
        class Reader;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class Properties : public ::java::util::Hashtable {
        public:
            enum {
                mid_init$_54c6a166,
                mid_getProperty_97a5258f,
                mid_getProperty_aacea7e9,
                mid_list_82fffd94,
                mid_list_1b7c898b,
                mid_load_cf2e3c10,
                mid_load_be2e4f90,
                mid_loadFromXML_be2e4f90,
                mid_propertyNames_39f88070,
                mid_save_c195c3b2,
                mid_setProperty_1a6a44ef,
                mid_store_c195c3b2,
                mid_store_2913a022,
                mid_storeToXML_c195c3b2,
                mid_storeToXML_f846429c,
                mid_stringPropertyNames_03e99967,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Properties(jobject obj) : ::java::util::Hashtable(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Properties(const Properties& obj) : ::java::util::Hashtable(obj) {}

            Properties();

            ::java::lang::String getProperty(const ::java::lang::String &) const;
            ::java::lang::String getProperty(const ::java::lang::String &, const ::java::lang::String &) const;
            void list(const ::java::io::PrintWriter &) const;
            void list(const ::java::io::PrintStream &) const;
            void load(const ::java::io::Reader &) const;
            void load(const ::java::io::InputStream &) const;
            void loadFromXML(const ::java::io::InputStream &) const;
            ::java::util::Enumeration propertyNames() const;
            void save(const ::java::io::OutputStream &, const ::java::lang::String &) const;
            ::java::lang::Object setProperty(const ::java::lang::String &, const ::java::lang::String &) const;
            void store(const ::java::io::OutputStream &, const ::java::lang::String &) const;
            void store(const ::java::io::Writer &, const ::java::lang::String &) const;
            void storeToXML(const ::java::io::OutputStream &, const ::java::lang::String &) const;
            void storeToXML(const ::java::io::OutputStream &, const ::java::lang::String &, const ::java::lang::String &) const;
            ::java::util::Set stringPropertyNames() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(Properties);

        class t_Properties {
        public:
            PyObject_HEAD
            Properties object;
            static PyObject *wrap_Object(const Properties&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
