#!/usr/bin/env python
#-*- coding: utf-8 -*-

from ConfigParser import SafeConfigParser
import shutil
import sys
import distribute_setup
distribute_setup.use_setuptools()

import os
from setuptools import setup, Extension

__author__ = 'edvald'

path = os.path.dirname( os.path.realpath( __file__ ) )

cfg = SafeConfigParser()
cfg.read(['icepy.cfg'])
corpus_path = cfg.get('data', 'bin_corpus_path') or '.'
corpus_path = os.path.abspath(os.path.join(path, corpus_path))

if not os.path.exists(corpus_path):
    print "*" * 60
    print u"""Please specify a valid path in icepy.cfg to the BÍN corpus data file (available from http://bin.arnastofnun.is/gogn/).
The file should be in the SH CSV format (SHsnid.csv, SHsnid.csv.zip or SHsnid.csv.gz)

Note: Reading a zipped file directly is currently only supported in Python 2.6+! For older versions of Python you must
extract the Zip file manually."""
    print "*" * 60
    sys.exit(1)

# copy corpus to data directory
print "Copying corpus file..."
shutil.copyfile(corpus_path, os.path.join(path,'icepy','data',os.path.basename(corpus_path)))

try:
    import jcc
except ImportError:
    print "*" * 60
    print "Warning: JCC has not been installed!"
    print "You need to install JCC (http://lucene.apache.org/pylucene/jcc/index.html) " \
          "and re-run this script for the icenlp_python wrapper to work."
    print "*" * 60
    ext_modules = []
else:
    # read the java headers path from icepy.cfg
    java_include_path = cfg.get('build','java_include_path')

    # guess the include path if on OSX
    if not java_include_path and sys.platform=='darwin':
        java_include_path = '/System/Library/Frameworks/JavaVM.framework/Headers'

    if not java_include_path:
        print "Please set the path to Java/JDK header files in icepy.cfg!"
        sys.exit(1)

    ext_modules = [Extension(
        '_icenlp_python',
        ['_icenlp_python/__init__.cpp', '_icenlp_python/__wrap__.cpp', '_icenlp_python/icenlp_python.cpp'],
        include_dirs=[
            '_icenlp_python',
            os.path.join(os.path.dirname(jcc.__file__), 'sources'),
            java_include_path
        ],
        extra_compile_args=['-DPYTHON','-D_jcc_shared','-D_java_generics']
    )]

setup(
    name='IcePy',
    version='0.5',
    description='IcePy - Icelandic NLP tools for Python',
    author='Jon Edvald',
    author_email='edvald@gmail.com',
    url='https://github.com/edvald/IcePy',
    packages=['icepy', 'icenlp_python'],
    package_dir={'icepy': 'icepy', 'icenlp_python': 'icenlp_python'},
    package_data={'icepy': ['data/*', 'COPYING', 'COPYING.LESSER'], 'icenlp_python': ['*.jar']},
    ext_modules=ext_modules,
    install_requires=['PyYAML', 'BitVector>=1.5.1'],
    extras_require={'_icenlp_python': ['JCC>=2.9']},
    zip_safe=False
)

