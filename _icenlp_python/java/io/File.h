#ifndef java_io_File_H
#define java_io_File_H

#include "java/lang/Object.h"

namespace java {
    namespace lang {
        class Comparable;
        class Class;
        class String;
    }
    namespace io {
        class FileFilter;
        class FilenameFilter;
        class IOException;
        class Serializable;
    }
}
template<class T> class JArray;

namespace java {
    namespace io {

        class File : public ::java::lang::Object {
        public:
            enum {
                mid_init$_5fdc3f48,
                mid_init$_4a264742,
                mid_init$_b8789389,
                mid_canExecute_54c6a16a,
                mid_canRead_54c6a16a,
                mid_canWrite_54c6a16a,
                mid_compareTo_290588f1,
                mid_compareTo_c3dacf48,
                mid_createNewFile_54c6a16a,
                mid_createTempFile_c112cd9a,
                mid_createTempFile_a168e209,
                mid_delete_54c6a16a,
                mid_deleteOnExit_54c6a166,
                mid_equals_290588e2,
                mid_exists_54c6a16a,
                mid_getAbsoluteFile_a8eb7bbe,
                mid_getAbsolutePath_14c7b5c5,
                mid_getCanonicalFile_a8eb7bbe,
                mid_getCanonicalPath_14c7b5c5,
                mid_getFreeSpace_54c6a17a,
                mid_getName_14c7b5c5,
                mid_getParent_14c7b5c5,
                mid_getParentFile_a8eb7bbe,
                mid_getPath_14c7b5c5,
                mid_getTotalSpace_54c6a17a,
                mid_getUsableSpace_54c6a17a,
                mid_hashCode_54c6a179,
                mid_isAbsolute_54c6a16a,
                mid_isDirectory_54c6a16a,
                mid_isFile_54c6a16a,
                mid_isHidden_54c6a16a,
                mid_lastModified_54c6a17a,
                mid_length_54c6a17a,
                mid_list_2e6d5245,
                mid_list_4f9187f3,
                mid_listFiles_5e6eeba2,
                mid_listFiles_3e6357e7,
                mid_listFiles_e6205e68,
                mid_listRoots_5e6eeba2,
                mid_mkdir_54c6a16a,
                mid_mkdirs_54c6a16a,
                mid_renameTo_c3dacf5b,
                mid_setExecutable_bb0c7673,
                mid_setExecutable_46f2e2c8,
                mid_setLastModified_0ee6df23,
                mid_setReadOnly_54c6a16a,
                mid_setReadable_bb0c7673,
                mid_setReadable_46f2e2c8,
                mid_setWritable_bb0c7673,
                mid_setWritable_46f2e2c8,
                mid_toString_14c7b5c5,
                max_mid
            };

            static ::java::lang::Class *class$;
            static jmethodID *mids$;
            static jclass initializeClass();

            explicit File(jobject obj) : ::java::lang::Object(obj) {
                if (obj != NULL)
                    initializeClass();
            }
            File(const File& obj) : ::java::lang::Object(obj) {}

            static ::java::lang::String *pathSeparator;
            static jchar pathSeparatorChar;
            static ::java::lang::String *separator;
            static jchar separatorChar;

            File(const ::java::lang::String &);
            File(const ::java::lang::String &, const ::java::lang::String &);
            File(const File &, const ::java::lang::String &);

            jboolean canExecute() const;
            jboolean canRead() const;
            jboolean canWrite() const;
            jint compareTo(const ::java::lang::Object &) const;
            jint compareTo(const File &) const;
            jboolean createNewFile() const;
            static File createTempFile(const ::java::lang::String &, const ::java::lang::String &);
            static File createTempFile(const ::java::lang::String &, const ::java::lang::String &, const File &);
            jboolean delete$() const;
            void deleteOnExit() const;
            jboolean equals(const ::java::lang::Object &) const;
            jboolean exists() const;
            File getAbsoluteFile() const;
            ::java::lang::String getAbsolutePath() const;
            File getCanonicalFile() const;
            ::java::lang::String getCanonicalPath() const;
            jlong getFreeSpace() const;
            ::java::lang::String getName() const;
            ::java::lang::String getParent() const;
            File getParentFile() const;
            ::java::lang::String getPath() const;
            jlong getTotalSpace() const;
            jlong getUsableSpace() const;
            jint hashCode() const;
            jboolean isAbsolute() const;
            jboolean isDirectory() const;
            jboolean isFile() const;
            jboolean isHidden() const;
            jlong lastModified() const;
            jlong length() const;
            JArray< ::java::lang::String > list() const;
            JArray< ::java::lang::String > list(const ::java::io::FilenameFilter &) const;
            JArray< File > listFiles() const;
            JArray< File > listFiles(const ::java::io::FileFilter &) const;
            JArray< File > listFiles(const ::java::io::FilenameFilter &) const;
            static JArray< File > listRoots();
            jboolean mkdir() const;
            jboolean mkdirs() const;
            jboolean renameTo(const File &) const;
            jboolean setExecutable(jboolean) const;
            jboolean setExecutable(jboolean, jboolean) const;
            jboolean setLastModified(jlong) const;
            jboolean setReadOnly() const;
            jboolean setReadable(jboolean) const;
            jboolean setReadable(jboolean, jboolean) const;
            jboolean setWritable(jboolean) const;
            jboolean setWritable(jboolean, jboolean) const;
            ::java::lang::String toString() const;
        };
    }
}

#include <Python.h>

namespace java {
    namespace io {
        extern PyTypeObject PY_TYPE(File);

        class t_File {
        public:
            PyObject_HEAD
            File object;
            static PyObject *wrap_Object(const File&);
            static PyObject *wrap_jobject(const jobject&);
            static void install(PyObject *module);
            static void initialize(PyObject *module);
        };
    }
}

#endif
