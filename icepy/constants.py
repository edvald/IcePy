#-*- coding: utf-8 -*-

__author__="edvald"
__date__ ="$Dec 5, 2009 2:42:22 PM$"

import string
import re

BLACKTAGS       = set(['c','e','x','g']) #if a wordform's category is in this set it will not be lemmatised
CATEGORY_MAP_REVERSE  = {'n':['hk','kk','kvk'], 'l': ['lo'], 's': ['so'], 'a': ['ao'], 'f': ['fn','afturbfn','pfn'], 'g': ['gr'], 't': ['to']}
CATEGORY_MAP = {}
for category,tegund_list in CATEGORY_MAP_REVERSE.iteritems():
    for tegund in tegund_list:
        CATEGORY_MAP[tegund] = category

VOWELS        = set([u'a',u'á',u'e',u'é',u'i',u'í',u'u',u'ú',u'y',u'ý',u'o',u'ó',u'ö',u'æ'])
COMBO_VOWELS  = set([u'au',u'ei',u'ey'])
ALL_VOWELS    = VOWELS | COMBO_VOWELS
VOWELS_RE     = re.compile(r'|'.join(VOWELS),re.U)

PREFIXES = set([u'æ',u'sí',u'ó',u'ei',u'van',u'of',u'sam',u'jafn'])

LEMMA_ENDINGS = (u'öa',u'r2',u'né',u'ua',u'ea',u'za',u'oa',u'a1',u'þi',u'a2',u'éa',u'ia',u'fé',u'éi')

ENCODE_MAP = {
    u'ð':'D',
    u'ó':'O',
    u'á':'A',
    u'æ':'C',
    u'ö':'Z',
    u'í':'I',
    u'ú':'U',
    u'þ':'P',
    u'ý':'Y',
    u'é':'E',
    u'ü':'Q',
    ### RESERVED SYMBOLS """
    '(':'(',
    '|':'|',
    ')':')'
}
for letter in string.lowercase + string.digits + '/ =-."':
    ENCODE_MAP[letter] = letter
ALPHABET = u''.join(ENCODE_MAP.keys())

DECODE_MAP = dict(((v,k) for k,v in ENCODE_MAP.iteritems()))

CHAR_FREQUENCIES = [
 (u'a', 6991877),
 (u'r', 5811208),
 (u'n', 5411575),
 (u's', 4792913),
 (u'u', 4462450),
 (u'i', 4168529),
 (u't', 3857028),
 (u'l', 3808855),
 (u'g', 2554830),
 (u'e', 2532937),
 (u'k', 2323964),
 (u'\xf0', 2194688),
 (u'm', 1997686),
 (u'f', 1708307),
 (u'd', 1284033),
 (u'h', 1035381),
 (u'v', 1008902),
 (u'\xf3', 950353),
 (u'b', 930599),
 (u'j', 915954),
 (u'o', 793760),
 (u'\xe1', 758003),
 (u'p', 745965),
 (u'\xe6', 710256),
 (u'\xf6', 696716),
 (u'y', 610754),
 (u'\xed', 571671),
 (u'\xfa', 434642),
 (u'\xfe', 287019),
 (u'\xfd', 197005),
 (u'\xe9', 159309),
 (u'x', 39923),
 (u'S', 34879),
 (u'H', 27412),
 (u'B', 18671),
 (u'G', 15713),
 (u'K', 15502),
 (u'M', 13353),
 (u'E', 12302),
 (u'A', 12128),
 (u'L', 11394),
 (u'F', 11245),
 (u'V', 10781),
 (u'-', 10141),
 (u'R', 8269),
 (u'\xde', 7365),
 (u'T', 6953),
 (u'D', 6536),
 (u'J', 6168),
 (u'N', 6034),
 (u'\xc1', 5619),
 (u'I', 3882),
 (u'P', 3564),
 (u'O', 2551),
 (u'\xcd', 2492),
 (u'c', 2467),
 (u'\xd6', 1743),
 (u'\xd3', 1570),
 (u'U', 1516),
 (u'Y', 1443),
 (u'\xda', 1021),
 (u'C', 976),
 (u'z', 878),
 (u'w', 458),
 (u'.', 400),
 (u'\xc6', 390),
 (u'Z', 284),
 (u'W', 225),
 (u'X', 136),
 (u'=', 96),
 (u'\xdd', 96),
 (u'2', 48),
 (u'"', 32),
 (u' ', 16),
 (u'/', 16),
 (u'Q', 16),
 (u'q', 8),
 (u'\xfc', 8),
 (u'\xc9', 4)
]
