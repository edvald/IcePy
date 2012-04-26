#ifndef java_util_Locale_H
#define java_util_Locale_H

#include "java/lang/Object.h"

namespace java {
    namespace util {
        class MissingResourceException;
    }
    namespace lang {
        class Class;
        class Cloneable;
        class String;
    }
    namespace io {
        class Serializable;
    }
}
template<class T> class JArray;

namespace java {
    namespace util {

        class Locale : public ::java::lang::Object {
        public:
            enum {
                mid_init$_5fdc3f48,
                mid_init$_4a264742,
                mid_init$_9c119564,
                mid_clone_846352c3,
                mid_equals_290588e2,
                mid_getAvailableLocales_59cb5b46,
                mid_getCountry_14c7b5c5,
                mid_getDefault_8bb22876,
                mid_getDisplayCountry_14c7b5c5,
                mid_getDisplayCountry_c0fb304e,
                mid_getDisplayLanguage_14c7b5c5,
                mid_getDisplayLanguage_c0fb304e,
                mid_getDisplayName_14c7b5c5,
                mid_getDisplayName_c0fb304e,
                mid_getDisplayVariant_14c7b5c5,
                mid_getDisplayVariant_c0fb304e,
                mid_getISO3Country_14c7b5c5,
                mid_getISO3Language_14c7b5c5,
                mid_getISOCountries_2e6d5245,
                mid_getISOLanguages_2e6d5245,
                mid_getLanguage_14c7b5c5,
                mid_getVariant_14c7b5c5,
                mid_hashCode_54c6a179,
                mid_setDefault_56b0e4b3,
                mid_toString_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit Locale(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            Locale(const Locale& obj) : ::java::lang::Object(obj) {}

            static Locale *CANADA;
            static Locale *CANADA_FRENCH;
            static Locale *CHINA;
            static Locale *CHINESE;
            static Locale *ENGLISH;
            static Locale *FRANCE;
            static Locale *FRENCH;
            static Locale *GERMAN;
            static Locale *GERMANY;
            static Locale *ITALIAN;
            static Locale *ITALY;
            static Locale *JAPAN;
            static Locale *JAPANESE;
            static Locale *KOREA;
            static Locale *KOREAN;
            static Locale *PRC;
            static Locale *ROOT;
            static Locale *SIMPLIFIED_CHINESE;
            static Locale *TAIWAN;
            static Locale *TRADITIONAL_CHINESE;
            static Locale *UK;
            static Locale *US;

            Locale(const ::java::lang::String &);
            Locale(const ::java::lang::String &, const ::java::lang::String &);
            Locale(const ::java::lang::String &, const ::java::lang::String &, const ::java::lang::String &);

            ::java::lang::Object clone() const;
            jboolean equals(const ::java::lang::Object &) const;
            static JArray< Locale > getAvailableLocales();
            ::java::lang::String getCountry() const;
            static Locale getDefault();
            ::java::lang::String getDisplayCountry() const;
            ::java::lang::String getDisplayCountry(const Locale &) const;
            ::java::lang::String getDisplayLanguage() const;
            ::java::lang::String getDisplayLanguage(const Locale &) const;
            ::java::lang::String getDisplayName() const;
            ::java::lang::String getDisplayName(const Locale &) const;
            ::java::lang::String getDisplayVariant() const;
            ::java::lang::String getDisplayVariant(const Locale &) const;
            ::java::lang::String getISO3Country() const;
            ::java::lang::String getISO3Language() const;
            static JArray< ::java::lang::String > getISOCountries();
            static JArray< ::java::lang::String > getISOLanguages();
            ::java::lang::String getLanguage() const;
            ::java::lang::String getVariant() const;
            jint hashCode() const;
            static void setDefault(const Locale &);
            ::java::lang::String toString() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace util {
        extern PyTypeObject PY_TYPE(Locale);

        class t_Locale {
        public:
            PyObject_HEAD
            Locale object;
            static PyObject *wrap_Object(const Locale&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
