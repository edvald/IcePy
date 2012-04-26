#-*- coding: utf-8 -*-
"""
This module contains functions for extracting elements from Icelandic texts, such as entities.

---

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

import icenlp
from morph import Morph

class Extractor(object):
    def __init__(self, morph=None):
        self.morph  = morph or Morph()

    def extract_entities(self, text, group_lexemes=True):
        chunk    = []
        entities = []
        for space,word,tag in icenlp.tag_and_iterate(text):
            if tag[0]==u'n' and tag[-1] in (u's',u'ö',u'm'):
                chunk.append((word,tag))
                continue
            if chunk: entities.append(chunk)
            chunk = []

        if group_lexemes:
            groups = self.morph.group_lexemes(entities)
            #print groups
            entities = groups.values()

        return entities

if __name__=="__main__":
    extractor = Extractor()

    text = u"""
        Leikarar við Borgarleikhúsið ætla að lesa skýrslu Rannsóknarnefndar Alþingis um bankahrunið, í heild sinni. Búist er við að lesturinn taki þrjá til fimm sólarhringa.

Skýrsla Rannsóknarnefndar Alþingis um aðdraganda og orsakir bankahrunsins, kemur út á mánudaginn. Skýrslunnar er beðið með mikilli eftirvæntingu og útgáfu hennar hefur tvisvar sinnum verið frestað vegna þess að umfang hennar varð meira en höfundarnir bjuggust við.

Skýrslan verður gerð öllum aðgengileg á sama tíma á netinu og má búast við að mikið verði lesið þann daginn og næstu daga. Á Nýja sviði Borgarleikhússins verður skýrslan lesin dag og nótt - frá upphafi til enda. Lesturinn hefst um leið og skýrslan kemur út. Leikarar Borgarleikhússins skipta með sér vöktum í tvo til fjóra klukkutíma í senn og lesa tveir leikarar á hverri vakt.

Magnús Geir Þórðarson, leikhússtjóri Borgarleikhússins segir að í leikhúsinu sé skýrslan talin það miklvæg að full ástæða sé til að bera hana á borð fyrir almenning. Hann segir ekki ætlunina að leggja mat á skýrsluna eða túlka hana á nokkurn hátt. Það verði því lítið um dramatísk tilþrif við lesturinn. Skýrslan er rúmar tvö þúsund blaðsíður, það eru um tíu kíló af pappír. Það er því ekkert áhlaupaverk að lesa hana frá upphafi til enda.


Bergur Þór Ingólfsson leikari við Borgarleikhúsið segir að það geti tekið allt að fimm sólarhringa að lesa skýrsluna. Leikarar muni skipta lestrinum bróðurlega á milli sín. Hann segir mjög mikilvægt að skýrslan verði lesin upp eins og hún leggur sig.

Öllum er velkomið að hlýða á lestur leikaranna á Nýja sviðinu. Hann verður líka sendur út á vefsíðu Borgarleikhússins.
    """

    text = u"""
    Bör Börsson og ríkisréttur
Hagfræðingar hafa fullyrt að allar bankakreppur séu í raun eins, bara misstórar. Útlánabólur enda í vanskilum og þá er leitað til ríkissjóðs um aðstoð, stundum leynilega eins og gerðist í frægri bankakreppu.

                                              ***
Hér í Noregi hefur aftur og aftur verið dregið fram að sú af fyrri bankakreppum, sem líkist núverandi kreppu mest, hafi orðið árið 1923.

Þá var tæknin önnur og allt gekk hægar fyrir sig en það sem gerist var alveg það sama. Útlánabóla endaði í hruni – og endaði í að forsætisráðherra landsins var dreginn fyrir ríkisrétt

Þessi kreppa kom í kjölfar mikils vaxtar í efnahag landins í kjölfar stríðsins. Slakað var á hömlum og margir nýir bankar urðu til.

Skáldið Johan Falberget gerði þessa bólu ódauðlega í sögunni um Bör Börsson yngri, stærsta son Olderdalsins - þótt hann væri bara lítill sveitakaupmaður. Háðsádeilan um Bör Börsson kom út árið 1920 þegar bólan var í hámarki.


En Bör Börsson var ekki einn síns liðs meðal stærstu sona í dölum landins. Margir stórir synir tóku stór lán og það myndaðist viðskiptahalli og svo vanskil. Þessi sama kreppa leiddi íslenska ríkið einnig nær því í þrot - og sömuleiðis norska ríkið.

Af vanskilum á lánum leiddi orðrómur um að bankarnir væru að fara á hausinn. Það myndaðist hætta á svokölluðu ”bank run” eða áhlaupi innlánseigenda á bankana. Allri gætu reynt að taka út sína peninga samtímis.



Vorið 1923 er ástandið orðið alvarlegt. Síðar hefur komið í ljós að seðlabankinn, sem einn sá um eftirlit, fékk rangar upplýsingar um stöðu bankana. Hún var mun verri en bankamenn létu uppi. Þeir fölsuðu bókhaldið.



Fjármálaráðherra var Abraham Berge, kennari að mennt, og kominn á efri ár. Um miðjan maí þetta ár kemur bankastjóri Handelsbankans á hans fund og biður um leynilegt neyðarlán. Bankinn sé kominn í þrot.

Berge er ljóst að neitun getur þýtt að allir bankanir hrynji samtímis.



23. maí deyr forsætisráðherrann skyndilega. Stjórnin er forystulaus en fjármálaráðherrann situr á leyndamáli, sem getur skipt sköpum fyrir þjóðina. Einn helsti banki landsins er gjaldþrota en bara hann og nokkrir menn í bankanum vita það.



30. maí tekur Abraham Berge við forsætisráðuneytinu og er áfram fjármálaráðherra. Daginn eftir veitir hann bankanum leynilega neyðarlánið og ákvörðunin er ekki skráð í gerðarbækur ríkisstjórnarinnar. Svo líða nokkrir mánuðir en í janúar 1924 er bankinn enn á ný kominn í þrot og nú er ný neyðaraðstoð lögð fyrir þingið og samþykk enda búið að setja flesta bankana undir opinbera stjórn.



En Berge forsætis- og fjármálaráðherra segir enn ekki frá leyniláninu.

Og enn líður til vors og nú er ríkissjóður að fara í þrot. Berge leggur til að sett verði upp áfengiseinkasala ríkisins, áfengisbann aflétt, og þannig aflað tekna fyrir ríkissjóð í neyð. Áður var búið að leggja á sykurskatt til að afla tekna.



Stjórnin féll á tillögunni um áfengið og nýir ráðherrar uppgötva leynilánið. Það er ákveðið að draga Abraham Berge fyrir ríkisrétt, sem þá var skipaður þingmönnum og hæstaréttardómurum. Nú er rétturinn óháður þinginu en hefur aldrei, hvorki fyrr né síðar, verið beitt í líku máli. Rétturinn deildi um málið í þrjú ár en sýknaði að lokum hinn aldna Berge því málið væri þá fyrnt. Einnig að ráðherra hefði gengið gott eitt til þrátt fyrir stjórnarskrárbrot og þrátt fyrir að kunnáttuleysi hans um fjármál hefði leitt til gjaldeyriskreppu, atvinnuleysis og landflótta til Ameríku.

Spegillinn 9. apríl 2010
    """

    print "Entities:"
    for e in extractor.extract_entities(text):
        print ' '.join([word for word,tag in e[0]])