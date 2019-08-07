                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module fov
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _TraceLine
                             12 ;--------------------------------------------------------
                             13 ; special function registers
                             14 ;--------------------------------------------------------
                             15 ;--------------------------------------------------------
                             16 ; ram data
                             17 ;--------------------------------------------------------
                             18 	.area _DATA
                             19 ;--------------------------------------------------------
                             20 ; ram data
                             21 ;--------------------------------------------------------
                             22 	.area _INITIALIZED
                             23 ;--------------------------------------------------------
                             24 ; absolute external ram data
                             25 ;--------------------------------------------------------
                             26 	.area _DABS (ABS)
                             27 ;--------------------------------------------------------
                             28 ; global & static initialisations
                             29 ;--------------------------------------------------------
                             30 	.area _HOME
                             31 	.area _GSINIT
                             32 	.area _GSFINAL
                             33 	.area _GSINIT
                             34 ;--------------------------------------------------------
                             35 ; Home
                             36 ;--------------------------------------------------------
                             37 	.area _HOME
                             38 	.area _HOME
                             39 ;--------------------------------------------------------
                             40 ; code
                             41 ;--------------------------------------------------------
                             42 	.area _CODE
                             43 ;src/fov.c:5: void TraceLine (u8 x1, u8 y1, u8 x2, u8 y2) //, u8 *coords)
                             44 ;	---------------------------------
                             45 ; Function TraceLine
                             46 ; ---------------------------------
   4E9A                      47 _TraceLine::
   4E9A DD E5         [15]   48 	push	ix
   4E9C DD 21 00 00   [14]   49 	ld	ix,#0
   4EA0 DD 39         [15]   50 	add	ix,sp
   4EA2 F5            [11]   51 	push	af
   4EA3 F5            [11]   52 	push	af
                             53 ;src/fov.c:12: dx = x2-x1;
   4EA4 DD 7E 06      [19]   54 	ld	a, 6 (ix)
   4EA7 DD 96 04      [19]   55 	sub	a, 4 (ix)
   4EAA 5F            [ 4]   56 	ld	e, a
                             57 ;src/fov.c:13: dy = y2-y1;
   4EAB DD 7E 07      [19]   58 	ld	a, 7 (ix)
   4EAE DD 96 05      [19]   59 	sub	a, 5 (ix)
   4EB1 6F            [ 4]   60 	ld	l, a
                             61 ;src/fov.c:14: sx = sign (dx);
   4EB2 4B            [ 4]   62 	ld	c, e
                             63 ;src/fast_math.h:13: return value < 0 ? -1 : 1;
   4EB3 CB 79         [ 8]   64 	bit	7, c
   4EB5 28 04         [12]   65 	jr	Z,00117$
   4EB7 0E FF         [ 7]   66 	ld	c, #0xff
   4EB9 18 02         [12]   67 	jr	00118$
   4EBB                      68 00117$:
   4EBB 0E 01         [ 7]   69 	ld	c, #0x01
   4EBD                      70 00118$:
                             71 ;src/fov.c:14: sx = sign (dx);
                             72 ;src/fov.c:15: sy = sign (dy);
   4EBD 45            [ 4]   73 	ld	b, l
                             74 ;src/fast_math.h:13: return value < 0 ? -1 : 1;
   4EBE CB 78         [ 8]   75 	bit	7, b
   4EC0 28 04         [12]   76 	jr	Z,00119$
   4EC2 3E FF         [ 7]   77 	ld	a, #0xff
   4EC4 18 02         [12]   78 	jr	00120$
   4EC6                      79 00119$:
   4EC6 3E 01         [ 7]   80 	ld	a, #0x01
   4EC8                      81 00120$:
                             82 ;src/fov.c:15: sy = sign (dy);
   4EC8 DD 77 FD      [19]   83 	ld	-3 (ix), a
                             84 ;src/fov.c:16: dx = abs (dx);
   4ECB 43            [ 4]   85 	ld	b, e
                             86 ;src/fast_math.h:9: return value < 0 ? -value : value;
   4ECC CB 78         [ 8]   87 	bit	7, b
   4ECE 28 03         [12]   88 	jr	Z,00121$
   4ED0 AF            [ 4]   89 	xor	a, a
   4ED1 93            [ 4]   90 	sub	a, e
   4ED2 5F            [ 4]   91 	ld	e, a
   4ED3                      92 00121$:
                             93 ;src/fov.c:16: dx = abs (dx);
                             94 ;src/fov.c:17: dy = abs (dy);
   4ED3 45            [ 4]   95 	ld	b, l
                             96 ;src/fast_math.h:9: return value < 0 ? -value : value;
   4ED4 CB 78         [ 8]   97 	bit	7, b
   4ED6 28 03         [12]   98 	jr	Z,00123$
   4ED8 AF            [ 4]   99 	xor	a, a
   4ED9 95            [ 4]  100 	sub	a, l
   4EDA 6F            [ 4]  101 	ld	l, a
   4EDB                     102 00123$:
                            103 ;src/fov.c:17: dy = abs (dy);
   4EDB 45            [ 4]  104 	ld	b, l
                            105 ;src/fov.c:18: error = dx-dy;
   4EDC 7B            [ 4]  106 	ld	a, e
   4EDD 95            [ 4]  107 	sub	a, l
   4EDE 57            [ 4]  108 	ld	d, a
                            109 ;src/fov.c:21: while(1) {
   4EDF                     110 00109$:
                            111 ;src/fov.c:26: if (x1==x2 && y1==y2) {
   4EDF DD 7E 04      [19]  112 	ld	a, 4 (ix)
   4EE2 DD 96 06      [19]  113 	sub	a, 6 (ix)
   4EE5 20 08         [12]  114 	jr	NZ,00102$
   4EE7 DD 7E 05      [19]  115 	ld	a, 5 (ix)
   4EEA DD 96 07      [19]  116 	sub	a, 7 (ix)
   4EED 28 52         [12]  117 	jr	Z,00115$
                            118 ;src/fov.c:28: break;
   4EEF                     119 00102$:
                            120 ;src/fov.c:31: error2 = error << 1;
   4EEF 7A            [ 4]  121 	ld	a, d
   4EF0 87            [ 4]  122 	add	a, a
   4EF1 DD 77 FC      [19]  123 	ld	-4 (ix), a
                            124 ;src/fov.c:32: if (error2 > -dx) {
   4EF4 6B            [ 4]  125 	ld	l, e
   4EF5 26 00         [ 7]  126 	ld	h, #0x00
   4EF7 AF            [ 4]  127 	xor	a, a
   4EF8 95            [ 4]  128 	sub	a, l
   4EF9 DD 77 FE      [19]  129 	ld	-2 (ix), a
   4EFC 3E 00         [ 7]  130 	ld	a, #0x00
   4EFE 9C            [ 4]  131 	sbc	a, h
   4EFF DD 77 FF      [19]  132 	ld	-1 (ix), a
   4F02 DD 6E FC      [19]  133 	ld	l, -4 (ix)
   4F05 DD 7E FC      [19]  134 	ld	a, -4 (ix)
   4F08 17            [ 4]  135 	rla
   4F09 9F            [ 4]  136 	sbc	a, a
   4F0A 67            [ 4]  137 	ld	h, a
   4F0B DD 7E FE      [19]  138 	ld	a, -2 (ix)
   4F0E 95            [ 4]  139 	sub	a, l
   4F0F DD 7E FF      [19]  140 	ld	a, -1 (ix)
   4F12 9C            [ 4]  141 	sbc	a, h
   4F13 E2 18 4F      [10]  142 	jp	PO, 00160$
   4F16 EE 80         [ 7]  143 	xor	a, #0x80
   4F18                     144 00160$:
   4F18 F2 26 4F      [10]  145 	jp	P, 00105$
                            146 ;src/fov.c:33: error -= dy;
   4F1B 68            [ 4]  147 	ld	l, b
   4F1C 7A            [ 4]  148 	ld	a, d
   4F1D 95            [ 4]  149 	sub	a, l
   4F1E 57            [ 4]  150 	ld	d, a
                            151 ;src/fov.c:34: x1 += sx;
   4F1F DD 6E 04      [19]  152 	ld	l, 4 (ix)
   4F22 09            [11]  153 	add	hl, bc
   4F23 DD 75 04      [19]  154 	ld	4 (ix), l
   4F26                     155 00105$:
                            156 ;src/fov.c:36: if (error2 < (i8)dx) {
   4F26 6B            [ 4]  157 	ld	l, e
   4F27 DD 7E FC      [19]  158 	ld	a, -4 (ix)
   4F2A 95            [ 4]  159 	sub	a, l
   4F2B E2 30 4F      [10]  160 	jp	PO, 00161$
   4F2E EE 80         [ 7]  161 	xor	a, #0x80
   4F30                     162 00161$:
   4F30 F2 DF 4E      [10]  163 	jp	P, 00109$
                            164 ;src/fov.c:37: error += dx;
   4F33 7A            [ 4]  165 	ld	a, d
   4F34 85            [ 4]  166 	add	a, l
   4F35 57            [ 4]  167 	ld	d, a
                            168 ;src/fov.c:38: y1 += sy;
   4F36 DD 7E 05      [19]  169 	ld	a, 5 (ix)
   4F39 DD 86 FD      [19]  170 	add	a, -3 (ix)
   4F3C DD 77 05      [19]  171 	ld	5 (ix), a
   4F3F 18 9E         [12]  172 	jr	00109$
   4F41                     173 00115$:
   4F41 DD F9         [10]  174 	ld	sp, ix
   4F43 DD E1         [14]  175 	pop	ix
   4F45 C9            [10]  176 	ret
                            177 	.area _CODE
                            178 	.area _INITIALIZER
                            179 	.area _CABS (ABS)
