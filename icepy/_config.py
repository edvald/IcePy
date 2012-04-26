#-*- coding: utf-8 -*-

"""
This file is a part of the IcePy natural language processing toolkit.
IcePy is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

IcePy is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with IcePy. If not,  see <http://www.gnu.org/licenses/>.

Contact information:
Jón Eðvald Vignisson, CTO, CLARA Ltd.
jon.edvald@clara.is
"""

import os.path

BIN_FILENAME = 'SHsnid.csv.gz'
OTB_FILENAME = 'otb.lex'
OTB_TAGMAP_FILENAME = 'otb.dict'

BASE_PATH = os.path.dirname( os.path.realpath( __file__ ) )
JVM_PATH  = "/usr/lib/jvm/java-6-openjdk/jre/lib/amd64/server/libjvm.so"
