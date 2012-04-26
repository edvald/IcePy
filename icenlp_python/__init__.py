import os, sys

if sys.platform == 'win32':
    import jcc, _icenlp_python
else:
    import _icenlp_python

__dir__ = os.path.abspath(os.path.dirname(__file__))
_javadir = os.path.join(__dir__, 'java')

class JavaError(Exception):
    def getJavaException(self):
        return self.args[0]
    def __str__(self):
        writer = StringWriter()
        self.getJavaException().printStackTrace(PrintWriter(writer))
        return "\n".join((super(JavaError, self).__str__(), "    Java stacktrace:", str(writer)))

class InvalidArgsError(Exception):
    pass

_icenlp_python._set_exception_types(JavaError, InvalidArgsError)
CLASSPATH = os.pathsep.join([
    os.path.join(_javadir, 'icenlp', "IceNLPCore.jar"),
    os.path.join(_javadir, 'commons-io', 'commons-io-2.3.jar'),
    os.path.join(_javadir, 'segment', 'commons-cli-1.2.jar'),
    os.path.join(_javadir, 'segment', 'segment-1.3.8.jar')
])
_icenlp_python.CLASSPATH = CLASSPATH
_icenlp_python._set_function_self(_icenlp_python.initVM, _icenlp_python)

from _icenlp_python import *
