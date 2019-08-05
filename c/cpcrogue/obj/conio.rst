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
                             19 ;--------------------------------------------------------
                             20 ; special function registers
                             21 ;--------------------------------------------------------
                             22 ;--------------------------------------------------------
                             23 ; ram data
                             24 ;--------------------------------------------------------
                             25 	.area _DATA
                             26 ;--------------------------------------------------------
                             27 ; ram data
                             28 ;--------------------------------------------------------
                             29 	.area _INITIALIZED
                             30 ;--------------------------------------------------------
                             31 ; absolute external ram data
                             32 ;--------------------------------------------------------
                             33 	.area _DABS (ABS)
                             34 ;--------------------------------------------------------
                             35 ; global & static initialisations
                             36 ;--------------------------------------------------------
                             37 	.area _HOME
                             38 	.area _GSINIT
                             39 	.area _GSFINAL
                             40 	.area _GSINIT
                             41 ;--------------------------------------------------------
                             42 ; Home
                             43 ;--------------------------------------------------------
                             44 	.area _HOME
                             45 	.area _HOME
                             46 ;--------------------------------------------------------
                             47 ; code
                             48 ;--------------------------------------------------------
                             49 	.area _CODE
                             50 ;src/conio.c:7: void locate (u8 x, u8 y)
                             51 ;	---------------------------------
                             52 ; Function locate
                             53 ; ---------------------------------
   445C                      54 _locate::
                             55 ;src/conio.c:9: putchar(US);
   445C 21 1F 00      [10]   56 	ld	hl, #0x001f
   445F E5            [11]   57 	push	hl
   4460 CD E4 4C      [17]   58 	call	_putchar
   4463 F1            [10]   59 	pop	af
                             60 ;src/conio.c:10: putchar (x); putchar (y);
   4464 21 02 00      [10]   61 	ld	hl, #2+0
   4467 39            [11]   62 	add	hl, sp
   4468 4E            [ 7]   63 	ld	c, (hl)
   4469 06 00         [ 7]   64 	ld	b, #0x00
   446B C5            [11]   65 	push	bc
   446C CD E4 4C      [17]   66 	call	_putchar
   446F F1            [10]   67 	pop	af
   4470 21 03 00      [10]   68 	ld	hl, #3+0
   4473 39            [11]   69 	add	hl, sp
   4474 4E            [ 7]   70 	ld	c, (hl)
   4475 06 00         [ 7]   71 	ld	b, #0x00
   4477 C5            [11]   72 	push	bc
   4478 CD E4 4C      [17]   73 	call	_putchar
   447B F1            [10]   74 	pop	af
   447C C9            [10]   75 	ret
                             76 ;src/conio.c:12: void ink (u8 tinta, u8 color1, u8 color2)
                             77 ;	---------------------------------
                             78 ; Function ink
                             79 ; ---------------------------------
   447D                      80 _ink::
                             81 ;src/conio.c:14: putchar (FS);
   447D 21 1C 00      [10]   82 	ld	hl, #0x001c
   4480 E5            [11]   83 	push	hl
   4481 CD E4 4C      [17]   84 	call	_putchar
   4484 F1            [10]   85 	pop	af
                             86 ;src/conio.c:15: putchar (tinta); putchar (color1); putchar (color2);
   4485 21 02 00      [10]   87 	ld	hl, #2+0
   4488 39            [11]   88 	add	hl, sp
   4489 4E            [ 7]   89 	ld	c, (hl)
   448A 06 00         [ 7]   90 	ld	b, #0x00
   448C C5            [11]   91 	push	bc
   448D CD E4 4C      [17]   92 	call	_putchar
   4490 F1            [10]   93 	pop	af
   4491 21 03 00      [10]   94 	ld	hl, #3+0
   4494 39            [11]   95 	add	hl, sp
   4495 4E            [ 7]   96 	ld	c, (hl)
   4496 06 00         [ 7]   97 	ld	b, #0x00
   4498 C5            [11]   98 	push	bc
   4499 CD E4 4C      [17]   99 	call	_putchar
   449C F1            [10]  100 	pop	af
   449D 21 04 00      [10]  101 	ld	hl, #4+0
   44A0 39            [11]  102 	add	hl, sp
   44A1 4E            [ 7]  103 	ld	c, (hl)
   44A2 06 00         [ 7]  104 	ld	b, #0x00
   44A4 C5            [11]  105 	push	bc
   44A5 CD E4 4C      [17]  106 	call	_putchar
   44A8 F1            [10]  107 	pop	af
   44A9 C9            [10]  108 	ret
                            109 ;src/conio.c:18: void paper (u8 color1)
                            110 ;	---------------------------------
                            111 ; Function paper
                            112 ; ---------------------------------
   44AA                     113 _paper::
                            114 ;src/conio.c:20: putchar (SO);
   44AA 21 0E 00      [10]  115 	ld	hl, #0x000e
   44AD E5            [11]  116 	push	hl
   44AE CD E4 4C      [17]  117 	call	_putchar
   44B1 F1            [10]  118 	pop	af
                            119 ;src/conio.c:21: putchar (color1);
   44B2 21 02 00      [10]  120 	ld	hl, #2+0
   44B5 39            [11]  121 	add	hl, sp
   44B6 4E            [ 7]  122 	ld	c, (hl)
   44B7 06 00         [ 7]  123 	ld	b, #0x00
   44B9 C5            [11]  124 	push	bc
   44BA CD E4 4C      [17]  125 	call	_putchar
   44BD F1            [10]  126 	pop	af
   44BE C9            [10]  127 	ret
                            128 ;src/conio.c:23: void pen (u8 tinta)
                            129 ;	---------------------------------
                            130 ; Function pen
                            131 ; ---------------------------------
   44BF                     132 _pen::
                            133 ;src/conio.c:25: putchar (SI);
   44BF 21 0F 00      [10]  134 	ld	hl, #0x000f
   44C2 E5            [11]  135 	push	hl
   44C3 CD E4 4C      [17]  136 	call	_putchar
   44C6 F1            [10]  137 	pop	af
                            138 ;src/conio.c:26: putchar (tinta);
   44C7 21 02 00      [10]  139 	ld	hl, #2+0
   44CA 39            [11]  140 	add	hl, sp
   44CB 4E            [ 7]  141 	ld	c, (hl)
   44CC 06 00         [ 7]  142 	ld	b, #0x00
   44CE C5            [11]  143 	push	bc
   44CF CD E4 4C      [17]  144 	call	_putchar
   44D2 F1            [10]  145 	pop	af
   44D3 C9            [10]  146 	ret
                            147 ;src/conio.c:31: void PrintAt (u8 x, u8 y, char text[], u8 color)
                            148 ;	---------------------------------
                            149 ; Function PrintAt
                            150 ; ---------------------------------
   44D4                     151 _PrintAt::
                            152 ;src/conio.c:35: locate (x, y);
   44D4 21 03 00      [10]  153 	ld	hl, #3+0
   44D7 39            [11]  154 	add	hl, sp
   44D8 7E            [ 7]  155 	ld	a, (hl)
   44D9 F5            [11]  156 	push	af
   44DA 33            [ 6]  157 	inc	sp
   44DB 21 03 00      [10]  158 	ld	hl, #3+0
   44DE 39            [11]  159 	add	hl, sp
   44DF 7E            [ 7]  160 	ld	a, (hl)
   44E0 F5            [11]  161 	push	af
   44E1 33            [ 6]  162 	inc	sp
   44E2 CD 5C 44      [17]  163 	call	_locate
   44E5 F1            [10]  164 	pop	af
                            165 ;src/conio.c:36: if (color != 0xff) pen (color);
   44E6 FD 21 06 00   [14]  166 	ld	iy, #6
   44EA FD 39         [15]  167 	add	iy, sp
   44EC FD 7E 00      [19]  168 	ld	a, 0 (iy)
   44EF 3C            [ 4]  169 	inc	a
   44F0 28 09         [12]  170 	jr	Z,00110$
   44F2 FD 7E 00      [19]  171 	ld	a, 0 (iy)
   44F5 F5            [11]  172 	push	af
   44F6 33            [ 6]  173 	inc	sp
   44F7 CD BF 44      [17]  174 	call	_pen
   44FA 33            [ 6]  175 	inc	sp
                            176 ;src/conio.c:37: while ( (ch=text[i++]) )
   44FB                     177 00110$:
   44FB 0E 00         [ 7]  178 	ld	c, #0x00
   44FD                     179 00103$:
   44FD 41            [ 4]  180 	ld	b, c
   44FE 0C            [ 4]  181 	inc	c
   44FF FD 21 04 00   [14]  182 	ld	iy, #4
   4503 FD 39         [15]  183 	add	iy, sp
   4505 FD 7E 00      [19]  184 	ld	a, 0 (iy)
   4508 80            [ 4]  185 	add	a, b
   4509 5F            [ 4]  186 	ld	e, a
   450A FD 7E 01      [19]  187 	ld	a, 1 (iy)
   450D CE 00         [ 7]  188 	adc	a, #0x00
   450F 57            [ 4]  189 	ld	d, a
   4510 1A            [ 7]  190 	ld	a, (de)
   4511 5F            [ 4]  191 	ld	e, a
   4512 B7            [ 4]  192 	or	a, a
   4513 C8            [11]  193 	ret	Z
                            194 ;src/conio.c:38: putchar(ch);
   4514 16 00         [ 7]  195 	ld	d, #0x00
   4516 C5            [11]  196 	push	bc
   4517 D5            [11]  197 	push	de
   4518 CD E4 4C      [17]  198 	call	_putchar
   451B F1            [10]  199 	pop	af
   451C C1            [10]  200 	pop	bc
   451D 18 DE         [12]  201 	jr	00103$
                            202 ;src/conio.c:44: void PrintU8 (u8 num, u8 x, u8 y, u8 color)
                            203 ;	---------------------------------
                            204 ; Function PrintU8
                            205 ; ---------------------------------
   451F                     206 _PrintU8::
   451F DD E5         [15]  207 	push	ix
   4521 DD 21 00 00   [14]  208 	ld	ix,#0
   4525 DD 39         [15]  209 	add	ix,sp
   4527 F5            [11]  210 	push	af
   4528 F5            [11]  211 	push	af
                            212 ;src/conio.c:47: sprintf (str, "%d", num);
   4529 DD 5E 04      [19]  213 	ld	e, 4 (ix)
   452C 16 00         [ 7]  214 	ld	d, #0x00
   452E 21 00 00      [10]  215 	ld	hl, #0x0000
   4531 39            [11]  216 	add	hl, sp
   4532 E5            [11]  217 	push	hl
   4533 D5            [11]  218 	push	de
   4534 11 57 45      [10]  219 	ld	de, #___str_0
   4537 D5            [11]  220 	push	de
   4538 E5            [11]  221 	push	hl
   4539 CD 56 4D      [17]  222 	call	_sprintf
   453C 21 06 00      [10]  223 	ld	hl, #6
   453F 39            [11]  224 	add	hl, sp
   4540 F9            [ 6]  225 	ld	sp, hl
   4541 C1            [10]  226 	pop	bc
                            227 ;src/conio.c:48: PrintAt (x,y, str, color);
   4542 DD 7E 07      [19]  228 	ld	a, 7 (ix)
   4545 F5            [11]  229 	push	af
   4546 33            [ 6]  230 	inc	sp
   4547 C5            [11]  231 	push	bc
   4548 DD 66 06      [19]  232 	ld	h, 6 (ix)
   454B DD 6E 05      [19]  233 	ld	l, 5 (ix)
   454E E5            [11]  234 	push	hl
   454F CD D4 44      [17]  235 	call	_PrintAt
   4552 DD F9         [10]  236 	ld	sp,ix
   4554 DD E1         [14]  237 	pop	ix
   4556 C9            [10]  238 	ret
   4557                     239 ___str_0:
   4557 25 64               240 	.ascii "%d"
   4559 00                  241 	.db 0x00
                            242 	.area _CODE
                            243 	.area _INITIALIZER
                            244 	.area _CABS (ABS)
