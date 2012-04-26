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

LOOKUP_TEST = [
    (u'vildarpunktarnir','n'),
    (u'evrópusambandið','n'),
    (u'sjálfstæðisflokkurinn','n'),
    (u'sjálfstæðisflokknum','n'),
    (u'vitleysingur','n'),
    (u'úranauðgun','n'),
    (u'steikarpanna','n'),
    (u'hrossapanna','n'),
    (u'hestur','n'),
    (u'bíómiðanna','n'),
    (u'reiðhjólafrelsarinn','n'),
    (u'háskólafólkið','n'),
    (u'gervigrasvelli','n'),
    (u'skólager','n'),
    (u'skólagerinn','n'),
    (u'ópera','n'),
    (u'gráðostur','n'),
    (u'klaufaostakökur','n'),
    (u'ógeðsleg','l'),
    (u'skemmtileg','l'),
    (u'gleðilegum','l'),
    (u'völlur','n'),
    (u'vallar','n'),
    (u'velli','n'),
    (u'vellinum','n'),
    (u'hestamannaþrjótsógeðin','n'),
    (u'flugumferðarstjóri','n'),
    (u'mannapar','n'),
    (u'símalandi','s'),
    (u'malandi','s'),
    (u'símat','n'),
    (u'símati','n'),
    (u'símaatinu','n'),
    (u'alveg','a'),
    (u'einmitt','a'),
    (u'alveg',None),
    (u'einmitt',None),
    (u'bíómiði','n'),
    (u'oddsson','n'),
    (u'oddssyni','n'),
    (u'veisluþjónustunni','n'),
    (u'veisluþjónustan','n'),
    (u'rosalega',None),
    (u'rosalega','a'),
    (u'rosalega','l'),
    (u'eðvaldssyni','n'),
    (u'jafnvitlaus','a'),
    (u'jafnvitlaus','l'),
    (u'aiowevawepoinawe o2305 41',None),
    (u'23ö0v2Cf2',None),
    (u'------------------------------------','t'),
    (u'aðaðaðaðaðaðaðaðaðaðaðaðaðaðaðaðaðaðaðað','s'),
    (u'--a','t'),
    (u'--að','t'),
    (u'a--','t'),
    (u'að--','t'),
    #(u'að---------------------------------------------------','t'),
    (u'--','t'),
    (u'----------------','t'),
    (u'þinginu','n')
]