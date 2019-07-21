100 '*********************************
110 ' CPC ROGUE
120 ' Jul 2019 by Andres Mata
120 '*********************************
130 INK 0,0: INK 1,0: INK 2,0
140 MODE 1:BORDER 0: PAPER 0: PEN 1: LOCATE 1, 5
150 PRINT"      )   ___    _____    )   ___      "
160 PRINT"     (__/_____) (, /   ) (__/_____)    "
170 PRINT"       /         _/__ /    /           "
180 PRINT"      /          /        /            "
190 PRINT"     (______) ) /        (______)      "
200 PRINT"            _(_/_                      "
210 PRINT"           (, /   )                    "
220 PRINT"             /__ / ___      _          "
230 PRINT"          ) /   \_(_(_/(_(_(/_         "
240 PRINT"         (_/       .-/                 "
250 PRINT"                  (_/                  "
280 LOCATE 10, 18:PEN 2:PRINT "PRESS ENTER TO START"
290 INK 0,3:INK 1,6,15:INK 2,16: BORDER 3
300 WHILE A$ = "": A$ = INKEY$: WEND
400 '*********************************
410 ' VARIABLES
420 '*********************************
430 DEFINT a-z
440 hp=150:str=17:destr=14:refl=12
450 hpen=100:stren=12:destren=13:reflen=11
460 atk=1.5*str+destr:defense=1.5*destr+refl
470 atken=1.5*stren+destren:defen=1.5*destren+reflen
500 '*********************************
510 ' SHOW STATS
520 '*********************************
530 BORDER 0: INK 0,0: INK 1,25: INK 2,20: PAPER 0:PEN 2:CLS
535 ' SHOW PLAYER STATS
540 PEN 1: PRINT SPC(10)"PLAYER";: PEN 2: PRINT " [@]": PRINT
550 PEN 1:PRINT "FUE ";:PEN 2:PRINT "["str"]";:PEN 1:PRINT" DES ";:PEN 2:PRINT"["destr"]";:PEN 1: PRINT " REF ";:PEN 2:PRINT "["refl"]"
560 PEN 1:PRINT "ATK ";:PEN 2:PRINT "["atk"]";:PEN 1:PRINT" DEF ";:PEN 2: PRINT"["defense"]";:PEN 1: PRINT "  HP ";:PEN 2:PRINT "["hp"]"
565 ' SHOW ENEMY STATS
570 PRINT
580 PEN 1: PRINT SPC(10)"GOBLIN";:PEN 2: PRINT " [g]": PRINT
590 PEN 1:PRINT "FUE ";:PEN 2:PRINT "["stren"]";:PEN 1:PRINT" DES ";:PEN 2:PRINT"["destren"]";:PEN 1: PRINT " REF ";:PEN 2:PRINT "["reflen"]"
600 PEN 1:PRINT "ATK ";:PEN 2:PRINT "["atken"]";:PEN 1:PRINT" DEF ";:PEN 2: PRINT"["defen"]";:PEN 1: PRINT "  HP ";:PEN 2:PRINT "["hpen"]"
