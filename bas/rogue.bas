1 '*********************************
1 ' CPC ROGUE
1 ' JUL 2019 BY ANDRES MATA
1 '*********************************

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
290 INK 0,0:INK 1,20:INK 2,18: BORDER 0
300 WHILE A$ = "": A$ = INKEY$: WEND

1 '*********************************
1 ' VARIABLES
1 '*********************************
400 DEFINT A-Z
410 HP=150:STR=17:DESTR=14:REFL=12
420 HPEN=100:STREN=12:DESTREN=13:REFLEN=11
430 ATK=1.5*STR+DESTR:DEFENSE=1.5*DESTR+REFL
440 ATKEN=1.5*STREN+DESTREN:DEFEN=1.5*DESTREN+REFLEN
450 A$="":PCH$="@":ECH$="g":BCH$=".":WCH$="#"
460 PX=2:PY=3:PPX=PX:PPY=PY:PDIRTY=1:PDX=0:PDY=0:PACT=0
470 EX=12:EY=9:PEX=EX:PEY=EY:EDIRTY=1:EDX=0:EDY=0
475 IX=0:IY=0:ICOL=0:ICH$=""

1' INITIALIZE COLORS FOR MAIN SCENE
480 GOSUB 4000:CLS

1' DRAW WORLD
490 GOSUB 1600

1 ' PLAYER ACTIONS
500 WHILE(1):A$=INKEY$
510 PPX=PX:PPY=PY:PDX=0:PDY=0:PDIRTY=0:PACT=0
530 IF A$="j" THEN PDX=-1
540 IF A$="l" THEN PDX= 1
550 IF A$="i" THEN PDY=-1
560 IF A$="k" THEN PDY= 1
570 IF PDX<>0 OR PDY<>0 THEN 580 ELSE GOTO 800
580 IF PX+PDX>=1 AND PX+PDX<=15 THEN PX=PX+PDX:PACT=1:PDIRTY=1
590 IF PY+PDY>=1 AND PY+PDY<=15 THEN PY=PY+PDY:PACT=1:PDIRTY=1

1 ' ENEMY ACTIONS
600 IF PACT=0 THEN 700 ELSE PACT=0:EDX=-1:PEX=EX:PEY=EY
610 IF EX+EDX>=1 AND EX+EDX<=15 THEN EX=EX+EDX:EDIRTY=1

1' ERASE ACTORS
700 IF PDIRTY=0 THEN 720 ELSE PDIRTY=0:IX=PPX:IY=PPY
710 ICOL=2:ICH$=BCH$:GOSUB 1400
720 IF EDIRTY=0 THEN 800 ELSE EDIRTY=0:IX=PEX:IY=PEY
730 GOSUB 1400

1' DRAW ACTORS
800 IX=PX:IY=PY:ICOL=1:ICH$=PCH$:GOSUB 1400
810 IX=EX:IY=EY:ICOL=3:ICH$=ECH$:GOSUB 1400
820 WEND

1 ' DELETE STATUS LINES
1010 FOR L=20 TO 23
1020 LOCATE 1,L:PRINT SPC(39):NEXT
1030 RETURN

1 '*********************
1 '* DRAW/ERASE ENTITY *
1 '*********************
1400 LOCATE IX, IY:PEN ICOL:PRINT ICH$
1410 RETURN

1 '***************
1 '* DRAW WORLD  *
1 '***************
1600 PEN 2:FOR Y=1 TO 15:PRINT STRING$(15,BCH$):NEXT
1700 RETURN

1 '********************
1 '*   INIT COLORS    *
1 '********************
4000 INK 0,0: INK 1, 20: INK 2, 1: INK 3, 6: BORDER 0
4010 RETURN

1 '********************
1 ' SHOW PLAYER STATS *
1 '********************
5030 BORDER 0: INK 0,0: INK 1,25: INK 2,20: INK 3,15: PAPER 0:PEN 2:CLS
5035 LOCATE 1,1
5040 PEN 1: PRINT SPC(10)"PLAYER";: PEN 2: PRINT " [@]": PRINT
5050 PEN 1:PRINT "STR ";:PEN 2:PRINT "["STR"]";:PEN 1:PRINT" DES ";:PEN 2:PRINT"["DESTR"]";:PEN 1: PRINT " REF ";:PEN 2:PRINT "["REFL"]"
5060 PEN 1:PRINT "ATK ";:PEN 2:PRINT "["ATK"]";:PEN 1:PRINT" DEF ";:PEN 2: PRINT"["DEFENSE"]";:PEN 1: PRINT "  HP ";:PEN 2:PRINT "["HP"]"

1
