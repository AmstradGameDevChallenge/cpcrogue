new
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
run
