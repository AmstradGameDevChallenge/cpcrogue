                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module conio
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _putchar
                             12 	.globl _sprintf
                             13 	.globl _locate
                             14 	.globl _ink
                             15 	.globl _paper
                             16 	.globl _pen
                             17 	.globl _PrintAt
                             18 	.globl _PrintU8
                             19 	.globl _BlackScreen
                             20 ;--------------------------------------------------------
                             21 ; special function registers
                             22 ;--------------------------------------------------------
                             23 ;--------------------------------------------------------
                             24 ; ram data
                             25 ;--------------------------------------------------------
                             26 	.area _DATA
                             27 ;--------------------------------------------------------
                             28 ; ram data
                             29 ;--------------------------------------------------------
                             30 	.area _INITIALIZED
                             31 ;--------------------------------------------------------
                             32 ; absolute external ram data
                             33 ;--------------------------------------------------------
                             34 	.area _DABS (ABS)
                             35 ;--------------------------------------------------------
                             36 ; global & static initialisations
                             37 ;--------------------------------------------------------
                             38 	.area _HOME
                             39 	.area _GSINIT
                             40 	.area _GSFINAL
                             41 	.area _GSINIT
                             42 ;--------------------------------------------------------
                             43 ; Home
                             44 ;--------------------------------------------------------
                             45 	.area _HOME
                             46 	.area _HOME
                             47 ;--------------------------------------------------------
                             48 ; code
                             49 ;--------------------------------------------------------
                             50 	.area _CODE
                             51 ;src/conio.c:7: void locate (u8 x, u8 y)
                             52 ;	---------------------------------
                             53 ; Function locate
                             54 ; ---------------------------------
   4456                      55 _locate::
                             56 ;src/conio.c:9: putchar(US);
   4456 21 1F 00      [10]   57 	ld	hl, #0x001f
   4459 E5            [11]   58 	push	hl
   445A CD 52 4F      [17]   59 	call	_putchar
   445D F1            [10]   60 	pop	af
                             61 ;src/conio.c:10: putchar (x); putchar (y);
   445E 21 02 00      [10]   62 	ld	hl, #2+0
   4461 39            [11]   63 	add	hl, sp
   4462 4E            [ 7]   64 	ld	c, (hl)
   4463 06 00         [ 7]   65 	ld	b, #0x00
   4465 C5            [11]   66 	push	bc
   4466 CD 52 4F      [17]   67 	call	_putchar
   4469 F1            [10]   68 	pop	af
   446A 21 03 00      [10]   69 	ld	hl, #3+0
   446D 39            [11]   70 	add	hl, sp
   446E 4E            [ 7]   71 	ld	c, (hl)
   446F 06 00         [ 7]   72 	ld	b, #0x00
   4471 C5            [11]   73 	push	bc
   4472 CD 52 4F      [17]   74 	call	_putchar
   4475 F1            [10]   75 	pop	af
   4476 C9            [10]   76 	ret
                             77 ;src/conio.c:12: void ink (u8 tinta, u8 color1, u8 color2)
                             78 ;	---------------------------------
                             79 ; Function ink
                             80 ; ---------------------------------
   4477                      81 _ink::
                             82 ;src/conio.c:14: putchar (FS);
   4477 21 1C 00      [10]   83 	ld	hl, #0x001c
   447A E5            [11]   84 	push	hl
   447B CD 52 4F      [17]   85 	call	_putchar
   447E F1            [10]   86 	pop	af
                             87 ;src/conio.c:15: putchar (tinta); putchar (color1); putchar (color2);
   447F 21 02 00      [10]   88 	ld	hl, #2+0
   4482 39            [11]   89 	add	hl, sp
   4483 4E            [ 7]   90 	ld	c, (hl)
   4484 06 00         [ 7]   91 	ld	b, #0x00
   4486 C5            [11]   92 	push	bc
   4487 CD 52 4F      [17]   93 	call	_putchar
   448A F1            [10]   94 	pop	af
   448B 21 03 00      [10]   95 	ld	hl, #3+0
   448E 39            [11]   96 	add	hl, sp
   448F 4E            [ 7]   97 	ld	c, (hl)
   4490 06 00         [ 7]   98 	ld	b, #0x00
   4492 C5            [11]   99 	push	bc
   4493 CD 52 4F      [17]  100 	call	_putchar
   4496 F1            [10]  101 	pop	af
   4497 21 04 00      [10]  102 	ld	hl, #4+0
   449A 39            [11]  103 	add	hl, sp
   449B 4E            [ 7]  104 	ld	c, (hl)
   449C 06 00         [ 7]  105 	ld	b, #0x00
   449E C5            [11]  106 	push	bc
   449F CD 52 4F      [17]  107 	call	_putchar
   44A2 F1            [10]  108 	pop	af
   44A3 C9            [10]  109 	ret
                            110 ;src/conio.c:18: void paper (u8 color1)
                            111 ;	---------------------------------
                            112 ; Function paper
                            113 ; ---------------------------------
   44A4                     114 _paper::
                            115 ;src/conio.c:20: putchar (SO);
   44A4 21 0E 00      [10]  116 	ld	hl, #0x000e
   44A7 E5            [11]  117 	push	hl
   44A8 CD 52 4F      [17]  118 	call	_putchar
   44AB F1            [10]  119 	pop	af
                            120 ;src/conio.c:21: putchar (color1);
   44AC 21 02 00      [10]  121 	ld	hl, #2+0
   44AF 39            [11]  122 	add	hl, sp
   44B0 4E            [ 7]  123 	ld	c, (hl)
   44B1 06 00         [ 7]  124 	ld	b, #0x00
   44B3 C5            [11]  125 	push	bc
   44B4 CD 52 4F      [17]  126 	call	_putchar
   44B7 F1            [10]  127 	pop	af
   44B8 C9            [10]  128 	ret
                            129 ;src/conio.c:23: void pen (u8 tinta)
                            130 ;	---------------------------------
                            131 ; Function pen
                            132 ; ---------------------------------
   44B9                     133 _pen::
                            134 ;src/conio.c:25: putchar (SI);
   44B9 21 0F 00      [10]  135 	ld	hl, #0x000f
   44BC E5            [11]  136 	push	hl
   44BD CD 52 4F      [17]  137 	call	_putchar
   44C0 F1            [10]  138 	pop	af
                            139 ;src/conio.c:26: putchar (tinta);
   44C1 21 02 00      [10]  140 	ld	hl, #2+0
   44C4 39            [11]  141 	add	hl, sp
   44C5 4E            [ 7]  142 	ld	c, (hl)
   44C6 06 00         [ 7]  143 	ld	b, #0x00
   44C8 C5            [11]  144 	push	bc
   44C9 CD 52 4F      [17]  145 	call	_putchar
   44CC F1            [10]  146 	pop	af
   44CD C9            [10]  147 	ret
                            148 ;src/conio.c:31: void PrintAt (u8 x, u8 y, char text[], u8 color)
                            149 ;	---------------------------------
                            150 ; Function PrintAt
                            151 ; ---------------------------------
   44CE                     152 _PrintAt::
                            153 ;src/conio.c:35: locate (x, y);
   44CE 21 03 00      [10]  154 	ld	hl, #3+0
   44D1 39            [11]  155 	add	hl, sp
   44D2 7E            [ 7]  156 	ld	a, (hl)
   44D3 F5            [11]  157 	push	af
   44D4 33            [ 6]  158 	inc	sp
   44D5 21 03 00      [10]  159 	ld	hl, #3+0
   44D8 39            [11]  160 	add	hl, sp
   44D9 7E            [ 7]  161 	ld	a, (hl)
   44DA F5            [11]  162 	push	af
   44DB 33            [ 6]  163 	inc	sp
   44DC CD 56 44      [17]  164 	call	_locate
   44DF F1            [10]  165 	pop	af
                            166 ;src/conio.c:36: if (color != 0xff) pen (color);
   44E0 FD 21 06 00   [14]  167 	ld	iy, #6
   44E4 FD 39         [15]  168 	add	iy, sp
   44E6 FD 7E 00      [19]  169 	ld	a, 0 (iy)
   44E9 3C            [ 4]  170 	inc	a
   44EA 28 09         [12]  171 	jr	Z,00110$
   44EC FD 7E 00      [19]  172 	ld	a, 0 (iy)
   44EF F5            [11]  173 	push	af
   44F0 33            [ 6]  174 	inc	sp
   44F1 CD B9 44      [17]  175 	call	_pen
   44F4 33            [ 6]  176 	inc	sp
                            177 ;src/conio.c:37: while ( (ch=text[i++]) )
   44F5                     178 00110$:
   44F5 0E 00         [ 7]  179 	ld	c, #0x00
   44F7                     180 00103$:
   44F7 41            [ 4]  181 	ld	b, c
   44F8 0C            [ 4]  182 	inc	c
   44F9 FD 21 04 00   [14]  183 	ld	iy, #4
   44FD FD 39         [15]  184 	add	iy, sp
   44FF FD 7E 00      [19]  185 	ld	a, 0 (iy)
   4502 80            [ 4]  186 	add	a, b
   4503 5F            [ 4]  187 	ld	e, a
   4504 FD 7E 01      [19]  188 	ld	a, 1 (iy)
   4507 CE 00         [ 7]  189 	adc	a, #0x00
   4509 57            [ 4]  190 	ld	d, a
   450A 1A            [ 7]  191 	ld	a, (de)
   450B 5F            [ 4]  192 	ld	e, a
   450C B7            [ 4]  193 	or	a, a
   450D C8            [11]  194 	ret	Z
                            195 ;src/conio.c:38: putchar(ch);
   450E 16 00         [ 7]  196 	ld	d, #0x00
   4510 C5            [11]  197 	push	bc
   4511 D5            [11]  198 	push	de
   4512 CD 52 4F      [17]  199 	call	_putchar
   4515 F1            [10]  200 	pop	af
   4516 C1            [10]  201 	pop	bc
   4517 18 DE         [12]  202 	jr	00103$
                            203 ;src/conio.c:44: void PrintU8 (u8 num, u8 x, u8 y, u8 color)
                            204 ;	---------------------------------
                            205 ; Function PrintU8
                            206 ; ---------------------------------
   4519                     207 _PrintU8::
   4519 DD E5         [15]  208 	push	ix
   451B DD 21 00 00   [14]  209 	ld	ix,#0
   451F DD 39         [15]  210 	add	ix,sp
   4521 F5            [11]  211 	push	af
   4522 F5            [11]  212 	push	af
                            213 ;src/conio.c:47: sprintf (str, "%d", num);
   4523 DD 5E 04      [19]  214 	ld	e, 4 (ix)
   4526 16 00         [ 7]  215 	ld	d, #0x00
   4528 21 00 00      [10]  216 	ld	hl, #0x0000
   452B 39            [11]  217 	add	hl, sp
   452C E5            [11]  218 	push	hl
   452D D5            [11]  219 	push	de
   452E 11 51 45      [10]  220 	ld	de, #___str_0
   4531 D5            [11]  221 	push	de
   4532 E5            [11]  222 	push	hl
   4533 CD BF 4F      [17]  223 	call	_sprintf
   4536 21 06 00      [10]  224 	ld	hl, #6
   4539 39            [11]  225 	add	hl, sp
   453A F9            [ 6]  226 	ld	sp, hl
   453B C1            [10]  227 	pop	bc
                            228 ;src/conio.c:48: PrintAt (x,y, str, color);
   453C DD 7E 07      [19]  229 	ld	a, 7 (ix)
   453F F5            [11]  230 	push	af
   4540 33            [ 6]  231 	inc	sp
   4541 C5            [11]  232 	push	bc
   4542 DD 66 06      [19]  233 	ld	h, 6 (ix)
   4545 DD 6E 05      [19]  234 	ld	l, 5 (ix)
   4548 E5            [11]  235 	push	hl
   4549 CD CE 44      [17]  236 	call	_PrintAt
   454C DD F9         [10]  237 	ld	sp,ix
   454E DD E1         [14]  238 	pop	ix
   4550 C9            [10]  239 	ret
   4551                     240 ___str_0:
   4551 25 64               241 	.ascii "%d"
   4553 00                  242 	.db 0x00
                            243 ;src/conio.c:51: void BlackScreen()
                            244 ;	---------------------------------
                            245 ; Function BlackScreen
                            246 ; ---------------------------------
   4554                     247 _BlackScreen::
                            248 ;src/conio.c:53: ink (0, INK_BG,INK_BG);
   4554 21 00 00      [10]  249 	ld	hl, #0x0000
   4557 E5            [11]  250 	push	hl
   4558 AF            [ 4]  251 	xor	a, a
   4559 F5            [11]  252 	push	af
   455A 33            [ 6]  253 	inc	sp
   455B CD 77 44      [17]  254 	call	_ink
                            255 ;src/conio.c:54: ink (1, INK_BG,INK_BG);
   455E 33            [ 6]  256 	inc	sp
   455F 21 00 00      [10]  257 	ld	hl,#0x0000
   4562 E3            [19]  258 	ex	(sp),hl
   4563 3E 01         [ 7]  259 	ld	a, #0x01
   4565 F5            [11]  260 	push	af
   4566 33            [ 6]  261 	inc	sp
   4567 CD 77 44      [17]  262 	call	_ink
                            263 ;src/conio.c:55: ink (2, INK_BG,INK_BG);
   456A 33            [ 6]  264 	inc	sp
   456B 21 00 00      [10]  265 	ld	hl,#0x0000
   456E E3            [19]  266 	ex	(sp),hl
   456F 3E 02         [ 7]  267 	ld	a, #0x02
   4571 F5            [11]  268 	push	af
   4572 33            [ 6]  269 	inc	sp
   4573 CD 77 44      [17]  270 	call	_ink
                            271 ;src/conio.c:56: ink (3, INK_BG,INK_BG);
   4576 33            [ 6]  272 	inc	sp
   4577 21 00 00      [10]  273 	ld	hl,#0x0000
   457A E3            [19]  274 	ex	(sp),hl
   457B 3E 03         [ 7]  275 	ld	a, #0x03
   457D F5            [11]  276 	push	af
   457E 33            [ 6]  277 	inc	sp
   457F CD 77 44      [17]  278 	call	_ink
                            279 ;src/conio.h:9: putchar (GS);
   4582 33            [ 6]  280 	inc	sp
   4583 21 1D 00      [10]  281 	ld	hl,#0x001d
   4586 E3            [19]  282 	ex	(sp),hl
   4587 CD 52 4F      [17]  283 	call	_putchar
                            284 ;src/conio.h:10: putchar (color1); putchar (color1);
   458A 21 00 00      [10]  285 	ld	hl, #0x0000
   458D E3            [19]  286 	ex	(sp),hl
   458E CD 52 4F      [17]  287 	call	_putchar
   4591 21 00 00      [10]  288 	ld	hl, #0x0000
   4594 E3            [19]  289 	ex	(sp),hl
   4595 CD 52 4F      [17]  290 	call	_putchar
   4598 F1            [10]  291 	pop	af
                            292 ;src/conio.c:58: border (0); paper (0);
   4599 AF            [ 4]  293 	xor	a, a
   459A F5            [11]  294 	push	af
   459B 33            [ 6]  295 	inc	sp
   459C CD A4 44      [17]  296 	call	_paper
   459F 33            [ 6]  297 	inc	sp
   45A0 C9            [10]  298 	ret
                            299 	.area _CODE
                            300 	.area _INITIALIZER
                            301 	.area _CABS (ABS)
