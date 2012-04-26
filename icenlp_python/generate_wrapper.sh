#!/bin/sh
python2.7 -m jcc \
    --package java.lang \
    --package java.util \
    --package java.io \
    --package org.apache.commons.io \
    --jar java/icenlp/IceNLPCore.jar \
    --classpath java/commons-io/commons-io-2.3.jar \
    --classpath java/segment/commons-cli-1.2.jar \
    --classpath java/segment/segment-1.3.8.jar \
    --python icenlp_python \
    --shared --build

llvm-gcc-4.2 -fno-strict-aliasing -fno-common -dynamic -g -Os -pipe -fno-common -fno-strict-aliasing -fwrapv -mno-fused-madd -DENABLE_DTRACE -DMACOSX -DNDEBUG -Wall -Wstrict-prototypes -Wshorten-64-to-32 -DNDEBUG -g -fwrapv -Os -Wall -Wstrict-prototypes -DENABLE_DTRACE -arch i386 -arch x86_64 -pipe
    -DPYTHON -DJCC_VER="2.9" -D_jcc_shared -D_java_generics
    -I/System/Library/Frameworks/JavaVM.framework/Headers
    -Ibuild/_icenlp_python
    -I/Library/Python/2.7/site-packages/JCC-2.9-py2.7-macosx-10.7-intel.egg/jcc/sources
    -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7
    -c build/_icenlp_python/__init__.cpp -o build/temp.macosx-10.7-intel-2.7/build/_icenlp_python/__init__.o -fno-strict-aliasing -Wno-write-strings
llvm-gcc-4.2 -fno-strict-aliasing -fno-common -dynamic -g -Os -pipe -fno-common -fno-strict-aliasing -fwrapv -mno-fused-madd -DENABLE_DTRACE -DMACOSX -DNDEBUG -Wall -Wstrict-prototypes -Wshorten-64-to-32 -DNDEBUG -g -fwrapv -Os -Wall -Wstrict-prototypes -DENABLE_DTRACE -arch i386 -arch x86_64 -pipe -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7 -c _icenlp_python/__init__.cpp -o build/temp.macosx-10.7-intel-2.7/_icenlp_python/__init__.o

llvm-gcc-4.2 -fno-strict-aliasing -fno-common -dynamic -g -Os -pipe -fno-common -fno-strict-aliasing -fwrapv -mno-fused-madd -DENABLE_DTRACE -DMACOSX -DNDEBUG -Wall -Wstrict-prototypes -Wshorten-64-to-32 -DNDEBUG -g -fwrapv -Os -Wall -Wstrict-prototypes -DENABLE_DTRACE -arch i386 -arch x86_64 -pipe -DPYTHON -DJCC_VER="2.9" -D_jcc_shared -D_java_generics -I/System/Library/Frameworks/JavaVM.framework/Headers -Ibuild/_icenlp_python -I/Library/Python/2.7/site-packages/JCC-2.9-py2.7-macosx-10.7-intel.egg/jcc/sources -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7 -c build/_icenlp_python/__wrap__.cpp -o build/temp.macosx-10.7-intel-2.7/build/_icenlp_python/__wrap__.o -fno-strict-aliasing -Wno-write-strings