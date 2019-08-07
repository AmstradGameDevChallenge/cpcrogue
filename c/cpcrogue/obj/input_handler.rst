                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module input_handler
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _cpct_isKeyPressed
                             12 	.globl _HandleKeyboard
                             13 ;--------------------------------------------------------
                             14 ; special function registers
                             15 ;--------------------------------------------------------
                             16 ;--------------------------------------------------------
                             17 ; ram data
                             18 ;--------------------------------------------------------
                             19 	.area _DATA
                             20 ;--------------------------------------------------------
                             21 ; ram data
                             22 ;--------------------------------------------------------
                             23 	.area _INITIALIZED
                             24 ;--------------------------------------------------------
                             25 ; absolute external ram data
                             26 ;--------------------------------------------------------
                             27 	.area _DABS (ABS)
                             28 ;--------------------------------------------------------
                             29 ; global & static initialisations
                             30 ;--------------------------------------------------------
                             31 	.area _HOME
                             32 	.area _GSINIT
                             33 	.area _GSFINAL
                             34 	.area _GSINIT
                             35 ;--------------------------------------------------------
                             36 ; Home
                             37 ;--------------------------------------------------------
                             38 	.area _HOME
                             39 	.area _HOME
                             40 ;--------------------------------------------------------
                             41 ; code
                             42 ;--------------------------------------------------------
                             43 	.area _CODE
                             44 ;src/input_handler.c:7: TAction HandleKeyboard (i8 *dx, i8 *dy)
                             45 ;	---------------------------------
                             46 ; Function HandleKeyboard
                             47 ; ---------------------------------
   43E3                      48 _HandleKeyboard::
                             49 ;src/input_handler.c:9: if (cpct_isKeyPressed (Key_I)) {  // i: UP
   43E3 21 04 08      [10]   50 	ld	hl, #0x0804
   43E6 CD 46 4F      [17]   51 	call	_cpct_isKeyPressed
   43E9 4D            [ 4]   52 	ld	c, l
                             53 ;src/input_handler.c:10: *dx = 0; *dy = -1; return PLAYER_MOVE;
   43EA D1            [10]   54 	pop	de
   43EB E1            [10]   55 	pop	hl
   43EC E5            [11]   56 	push	hl
   43ED D5            [11]   57 	push	de
   43EE FD 21 04 00   [14]   58 	ld	iy, #4
   43F2 FD 39         [15]   59 	add	iy, sp
   43F4 FD 5E 00      [19]   60 	ld	e,0 (iy)
   43F7 FD 56 01      [19]   61 	ld	d,1 (iy)
                             62 ;src/input_handler.c:9: if (cpct_isKeyPressed (Key_I)) {  // i: UP
   43FA 79            [ 4]   63 	ld	a, c
   43FB B7            [ 4]   64 	or	a, a
   43FC 28 08         [12]   65 	jr	Z,00102$
                             66 ;src/input_handler.c:10: *dx = 0; *dy = -1; return PLAYER_MOVE;
   43FE 36 00         [10]   67 	ld	(hl), #0x00
   4400 3E FF         [ 7]   68 	ld	a, #0xff
   4402 12            [ 7]   69 	ld	(de), a
   4403 2E 01         [ 7]   70 	ld	l, #0x01
   4405 C9            [10]   71 	ret
   4406                      72 00102$:
                             73 ;src/input_handler.c:12: if (cpct_isKeyPressed (Key_K)) {  // k: DOWN
   4406 E5            [11]   74 	push	hl
   4407 D5            [11]   75 	push	de
   4408 21 04 20      [10]   76 	ld	hl, #0x2004
   440B CD 46 4F      [17]   77 	call	_cpct_isKeyPressed
   440E 7D            [ 4]   78 	ld	a, l
   440F D1            [10]   79 	pop	de
   4410 E1            [10]   80 	pop	hl
   4411 B7            [ 4]   81 	or	a, a
   4412 28 08         [12]   82 	jr	Z,00104$
                             83 ;src/input_handler.c:13: *dx = 0; *dy = 1; return PLAYER_MOVE;
   4414 36 00         [10]   84 	ld	(hl), #0x00
   4416 3E 01         [ 7]   85 	ld	a, #0x01
   4418 12            [ 7]   86 	ld	(de), a
   4419 2E 01         [ 7]   87 	ld	l, #0x01
   441B C9            [10]   88 	ret
   441C                      89 00104$:
                             90 ;src/input_handler.c:15: if (cpct_isKeyPressed (Key_J)) {  // j: LEFT
   441C E5            [11]   91 	push	hl
   441D D5            [11]   92 	push	de
   441E 21 05 20      [10]   93 	ld	hl, #0x2005
   4421 CD 46 4F      [17]   94 	call	_cpct_isKeyPressed
   4424 7D            [ 4]   95 	ld	a, l
   4425 D1            [10]   96 	pop	de
   4426 E1            [10]   97 	pop	hl
   4427 B7            [ 4]   98 	or	a, a
   4428 28 07         [12]   99 	jr	Z,00106$
                            100 ;src/input_handler.c:16: *dx = -1; *dy = 0; return PLAYER_MOVE;
   442A 36 FF         [10]  101 	ld	(hl), #0xff
   442C AF            [ 4]  102 	xor	a, a
   442D 12            [ 7]  103 	ld	(de), a
   442E 2E 01         [ 7]  104 	ld	l, #0x01
   4430 C9            [10]  105 	ret
   4431                     106 00106$:
                            107 ;src/input_handler.c:18: if (cpct_isKeyPressed (Key_L)) {  // l: RIGHT
   4431 E5            [11]  108 	push	hl
   4432 D5            [11]  109 	push	de
   4433 21 04 10      [10]  110 	ld	hl, #0x1004
   4436 CD 46 4F      [17]  111 	call	_cpct_isKeyPressed
   4439 7D            [ 4]  112 	ld	a, l
   443A D1            [10]  113 	pop	de
   443B E1            [10]  114 	pop	hl
   443C B7            [ 4]  115 	or	a, a
   443D 28 07         [12]  116 	jr	Z,00108$
                            117 ;src/input_handler.c:19: *dx = 1; *dy = 0; return PLAYER_MOVE;
   443F 36 01         [10]  118 	ld	(hl), #0x01
   4441 AF            [ 4]  119 	xor	a, a
   4442 12            [ 7]  120 	ld	(de), a
   4443 2E 01         [ 7]  121 	ld	l, #0x01
   4445 C9            [10]  122 	ret
   4446                     123 00108$:
                            124 ;src/input_handler.c:21: if (cpct_isKeyPressed (Key_S)) {  // s: WAIT
   4446 21 07 10      [10]  125 	ld	hl, #0x1007
   4449 CD 46 4F      [17]  126 	call	_cpct_isKeyPressed
   444C 7D            [ 4]  127 	ld	a, l
   444D B7            [ 4]  128 	or	a, a
   444E 28 03         [12]  129 	jr	Z,00110$
                            130 ;src/input_handler.c:22: return PLAYER_MOVE;
   4450 2E 01         [ 7]  131 	ld	l, #0x01
   4452 C9            [10]  132 	ret
   4453                     133 00110$:
                            134 ;src/input_handler.c:24: return NONE;
   4453 2E 00         [ 7]  135 	ld	l, #0x00
   4455 C9            [10]  136 	ret
                            137 	.area _CODE
                            138 	.area _INITIALIZER
                            139 	.area _CABS (ABS)
