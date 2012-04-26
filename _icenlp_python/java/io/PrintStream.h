#ifndef java_io_PrintStream_H
#define java_io_PrintStream_H

#include "java/io/FilterOutputStream.h"

namespace java {
    namespace lang {
        class String;
        class Appendable;
        class Object;
        class Class;
        class CharSequence;
    }
    namespace util {
        class Locale;
    }
    namespace io {
        class UnsupportedEncodingException;
        class OutputStream;
        class File;
        class FileNotFoundException;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class PrintStream : public ::java::io::FilterOutputStream {
        public:
            enum {
                mid_init$_5fdc3f48,
                mid_init$_c3dacf57,
                mid_init$_82d865f8,
                mid_init$_a0fd6605,
                mid_init$_4a264742,
                mid_init$_b8789389,
                mid_init$_edbcee1f,
                mid_append_df4c2e82,
                mid_append_40d6dba2,
                mid_append_1e7d47f6,
                mid_checkError_54c6a16a,
                mid_close_54c6a166,
                mid_flush_54c6a166,
                mid_format_3f655b78,
                mid_format_a8a140d3,
                mid_print_5d1c7645,
                mid_print_87fd545a,
                mid_print_700e23d6,
                mid_print_bb0c767f,
                mid_print_39c7bd3c,
                mid_print_5fdc3f48,
                mid_print_290588ee,
                mid_print_06298cab,
                mid_print_0ee6df2f,
                mid_printf_3f655b78,
                mid_printf_a8a140d3,
                mid_println_54c6a166,
                mid_println_39c7bd3c,
                mid_println_5fdc3f48,
                mid_println_0ee6df2f,
                mid_println_bb0c767f,
                mid_println_06298cab,
                mid_println_5d1c7645,
                mid_println_700e23d6,
                mid_println_290588ee,
                mid_println_87fd545a,
                mid_write_39c7bd3c,
                mid_write_86f4435f,
                mid_setError_54c6a166,
                mid_clearError_54c6a166,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit PrintStream(jobject obj) : ::java::io::FilterOutputStream(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            PrintStream(const PrintStream& obj) : ::java::io::FilterOutputStream(obj) {}

            PrintStream(const ::java::lang::String &);
            PrintStream(const ::java::io::File &);
            PrintStream(const ::java::io::OutputStream &);
            PrintStream(const ::java::io::OutputStream &, jboolean);
            PrintStream(const ::java::lang::String &, const ::java::lang::String &);
            PrintStream(const ::java::io::File &, const ::java::lang::String &);
            PrintStream(const ::java::io::OutputStream &, jboolean, const ::java::lang::String &);

            PrintStream append(const ::java::lang::CharSequence &) const;
            PrintStream append(jchar) const;
            PrintStream append(const ::java::lang::CharSequence &, jint, jint) const;
            jboolean checkError() const;
            void close() const;
            void flush() const;
            PrintStream format(const ::java::lang::String &, const JArray< ::java::lang::Object > &) const;
            PrintStream format(const ::java::util::Locale &, const ::java::lang::String &, const JArray< ::java::lang::Object > &) const;
            void print(jdouble) const;
            void print(jchar) const;
            void print(const JArray< jchar > &) const;
            void print(jboolean) const;
            void print(jint) const;
            void print(const ::java::lang::String &) const;
            void print(const ::java::lang::Object &) const;
            void print(jfloat) const;
            void print(jlong) const;
            PrintStream printf(const ::java::lang::String &, const JArray< ::java::lang::Object > &) const;
            PrintStream printf(const ::java::util::Locale &, const ::java::lang::String &, const JArray< ::java::lang::Object > &) const;
            void println() const;
            void println(jint) const;
            void println(const ::java::lang::String &) const;
            void println(jlong) const;
            void println(jboolean) const;
            void println(jfloat) const;
            void println(jdouble) const;
            void println(const JArray< jchar > &) const;
            void println(const ::java::lang::Object &) const;
            void println(jchar) const;
            void write(jint) const;
            void write(const JArray< jbyte > &, jint, jint) const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(PrintStream);

        class t_PrintStream {
        public:
            PyObject_HEAD
            PrintStream object;
            static PyObject *wrap_Object(const PrintStream&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
