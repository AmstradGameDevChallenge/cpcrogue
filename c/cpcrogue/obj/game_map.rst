                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module game_map
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _pen
                             12 	.globl _locate
                             13 	.globl _putchar
                             14 	.globl _game_map
                             15 	.globl _MapCreate
                             16 	.globl _MapIsBlocked
                             17 	.globl _MapDraw
                             18 ;--------------------------------------------------------
                             19 ; special function registers
                             20 ;--------------------------------------------------------
                             21 ;--------------------------------------------------------
                             22 ; ram data
                             23 ;--------------------------------------------------------
                             24 	.area _DATA
   5C5A                      25 _game_map::
   5C5A                      26 	.ds 506
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
                             51 ;src/game_map.c:9: void MapCreate (u8 width, u8 height)
                             52 ;	---------------------------------
                             53 ; Function MapCreate
                             54 ; ---------------------------------
   4000                      55 _MapCreate::
   4000 DD E5         [15]   56 	push	ix
   4002 DD 21 00 00   [14]   57 	ld	ix,#0
   4006 DD 39         [15]   58 	add	ix,sp
                             59 ;src/game_map.c:13: game_map.width = width;
   4008 21 5A 5C      [10]   60 	ld	hl, #_game_map
   400B DD 7E 04      [19]   61 	ld	a, 4 (ix)
   400E 77            [ 7]   62 	ld	(hl), a
                             63 ;src/game_map.c:14: game_map.height = height;
   400F 21 5B 5C      [10]   64 	ld	hl, #(_game_map + 0x0001)
   4012 DD 7E 05      [19]   65 	ld	a, 5 (ix)
   4015 77            [ 7]   66 	ld	(hl), a
                             67 ;src/game_map.c:15: for (i=0; i < height; ++i)
   4016 0E 00         [ 7]   68 	ld	c, #0x00
   4018                      69 00107$:
   4018 79            [ 4]   70 	ld	a, c
   4019 DD 96 05      [19]   71 	sub	a, 5 (ix)
   401C 30 24         [12]   72 	jr	NC,00102$
                             73 ;src/game_map.c:16: for (j=0; j < width; ++j)
   401E 06 00         [ 7]   74 	ld	b,#0x00
   4020 69            [ 4]   75 	ld	l, c
   4021 60            [ 4]   76 	ld	h, b
   4022 29            [11]   77 	add	hl, hl
   4023 09            [11]   78 	add	hl, bc
   4024 29            [11]   79 	add	hl, hl
   4025 09            [11]   80 	add	hl, bc
   4026 29            [11]   81 	add	hl, hl
   4027 29            [11]   82 	add	hl, hl
   4028 EB            [ 4]   83 	ex	de,hl
   4029 21 5C 5C      [10]   84 	ld	hl, #(_game_map + 0x0002)
   402C 19            [11]   85 	add	hl,de
   402D EB            [ 4]   86 	ex	de,hl
   402E 06 00         [ 7]   87 	ld	b, #0x00
   4030                      88 00104$:
   4030 78            [ 4]   89 	ld	a, b
   4031 DD 96 04      [19]   90 	sub	a, 4 (ix)
   4034 30 09         [12]   91 	jr	NC,00108$
                             92 ;src/game_map.c:17: game_map.tiles[i][j].blocked = FALSE;
   4036 68            [ 4]   93 	ld	l,b
   4037 26 00         [ 7]   94 	ld	h,#0x00
   4039 19            [11]   95 	add	hl, de
   403A 36 00         [10]   96 	ld	(hl), #0x00
                             97 ;src/game_map.c:16: for (j=0; j < width; ++j)
   403C 04            [ 4]   98 	inc	b
   403D 18 F1         [12]   99 	jr	00104$
   403F                     100 00108$:
                            101 ;src/game_map.c:15: for (i=0; i < height; ++i)
   403F 0C            [ 4]  102 	inc	c
   4040 18 D6         [12]  103 	jr	00107$
   4042                     104 00102$:
                            105 ;src/game_map.c:20: game_map.tiles[12][3].blocked = TRUE;
   4042 21 AF 5D      [10]  106 	ld	hl, #(_game_map + 0x0155)
   4045 36 01         [10]  107 	ld	(hl), #0x01
                            108 ;src/game_map.c:21: game_map.tiles[3][16].blocked = TRUE;
   4047 21 C0 5C      [10]  109 	ld	hl, #(_game_map + 0x0066)
   404A 36 01         [10]  110 	ld	(hl), #0x01
   404C DD E1         [14]  111 	pop	ix
   404E C9            [10]  112 	ret
                            113 ;src/game_map.c:24: u8 MapIsBlocked (u8 x, u8 y)
                            114 ;	---------------------------------
                            115 ; Function MapIsBlocked
                            116 ; ---------------------------------
   404F                     117 _MapIsBlocked::
   404F DD E5         [15]  118 	push	ix
   4051 DD 21 00 00   [14]  119 	ld	ix,#0
   4055 DD 39         [15]  120 	add	ix,sp
                            121 ;src/game_map.c:26: return game_map.tiles[y][x].blocked;
   4057 DD 4E 05      [19]  122 	ld	c,5 (ix)
   405A 06 00         [ 7]  123 	ld	b,#0x00
   405C 69            [ 4]  124 	ld	l, c
   405D 60            [ 4]  125 	ld	h, b
   405E 29            [11]  126 	add	hl, hl
   405F 09            [11]  127 	add	hl, bc
   4060 29            [11]  128 	add	hl, hl
   4061 09            [11]  129 	add	hl, bc
   4062 29            [11]  130 	add	hl, hl
   4063 29            [11]  131 	add	hl, hl
   4064 11 5C 5C      [10]  132 	ld	de, #(_game_map + 0x0002)
   4067 19            [11]  133 	add	hl, de
   4068 DD 5E 04      [19]  134 	ld	e, 4 (ix)
   406B 16 00         [ 7]  135 	ld	d,#0x00
   406D 19            [11]  136 	add	hl, de
   406E 6E            [ 7]  137 	ld	l, (hl)
   406F DD E1         [14]  138 	pop	ix
   4071 C9            [10]  139 	ret
                            140 ;src/game_map.c:29: void MapDraw ()
                            141 ;	---------------------------------
                            142 ; Function MapDraw
                            143 ; ---------------------------------
   4072                     144 _MapDraw::
   4072 DD E5         [15]  145 	push	ix
   4074 DD 21 00 00   [14]  146 	ld	ix,#0
   4078 DD 39         [15]  147 	add	ix,sp
   407A F5            [11]  148 	push	af
   407B F5            [11]  149 	push	af
   407C 3B            [ 6]  150 	dec	sp
                            151 ;src/game_map.c:36: for (i=0; i < game_map.height; ++i) {
   407D DD 36 FC 00   [19]  152 	ld	-4 (ix), #0x00
   4081                     153 00110$:
   4081 21 5B 5C      [10]  154 	ld	hl, #_game_map + 1
   4084 DD 7E FC      [19]  155 	ld	a,-4 (ix)
   4087 96            [ 7]  156 	sub	a,(hl)
   4088 30 76         [12]  157 	jr	NC,00112$
                            158 ;src/game_map.c:37: for (j=0; j < game_map.width; ++j) {
   408A DD 7E FC      [19]  159 	ld	a, -4 (ix)
   408D C6 02         [ 7]  160 	add	a, #0x02
   408F DD 77 FD      [19]  161 	ld	-3 (ix), a
   4092 01 5C 5C      [10]  162 	ld	bc, #_game_map + 2
   4095 DD 5E FC      [19]  163 	ld	e,-4 (ix)
   4098 16 00         [ 7]  164 	ld	d,#0x00
   409A 6B            [ 4]  165 	ld	l, e
   409B 62            [ 4]  166 	ld	h, d
   409C 29            [11]  167 	add	hl, hl
   409D 19            [11]  168 	add	hl, de
   409E 29            [11]  169 	add	hl, hl
   409F 19            [11]  170 	add	hl, de
   40A0 29            [11]  171 	add	hl, hl
   40A1 29            [11]  172 	add	hl, hl
   40A2 09            [11]  173 	add	hl,bc
   40A3 DD 75 FE      [19]  174 	ld	-2 (ix), l
   40A6 DD 74 FF      [19]  175 	ld	-1 (ix), h
   40A9 DD 36 FB 00   [19]  176 	ld	-5 (ix), #0x00
   40AD                     177 00107$:
   40AD 21 5A 5C      [10]  178 	ld	hl, #_game_map + 0
   40B0 4E            [ 7]  179 	ld	c, (hl)
   40B1 DD 7E FB      [19]  180 	ld	a, -5 (ix)
   40B4 91            [ 4]  181 	sub	a, c
   40B5 30 43         [12]  182 	jr	NC,00111$
                            183 ;src/game_map.c:38: locate (PLAY_X+j,PLAY_Y+i);
   40B7 DD 46 FB      [19]  184 	ld	b, -5 (ix)
   40BA 04            [ 4]  185 	inc	b
   40BB 04            [ 4]  186 	inc	b
   40BC DD 7E FD      [19]  187 	ld	a, -3 (ix)
   40BF F5            [11]  188 	push	af
   40C0 33            [ 6]  189 	inc	sp
   40C1 C5            [11]  190 	push	bc
   40C2 33            [ 6]  191 	inc	sp
   40C3 CD 56 44      [17]  192 	call	_locate
   40C6 F1            [10]  193 	pop	af
                            194 ;src/game_map.c:39: is_wall = game_map.tiles[i][j].blocked;
   40C7 DD 7E FE      [19]  195 	ld	a, -2 (ix)
   40CA DD 86 FB      [19]  196 	add	a, -5 (ix)
   40CD 6F            [ 4]  197 	ld	l, a
   40CE DD 7E FF      [19]  198 	ld	a, -1 (ix)
   40D1 CE 00         [ 7]  199 	adc	a, #0x00
   40D3 67            [ 4]  200 	ld	h, a
   40D4 4E            [ 7]  201 	ld	c, (hl)
                            202 ;src/game_map.c:40: pen (PEN_TILE);
   40D5 C5            [11]  203 	push	bc
   40D6 3E 03         [ 7]  204 	ld	a, #0x03
   40D8 F5            [11]  205 	push	af
   40D9 33            [ 6]  206 	inc	sp
   40DA CD B9 44      [17]  207 	call	_pen
   40DD 33            [ 6]  208 	inc	sp
   40DE C1            [10]  209 	pop	bc
                            210 ;src/game_map.c:41: if (is_wall) {
   40DF 79            [ 4]  211 	ld	a, c
   40E0 B7            [ 4]  212 	or	a, a
   40E1 28 0A         [12]  213 	jr	Z,00102$
                            214 ;src/game_map.c:42: putchar(SPR_WALL);
   40E3 21 23 00      [10]  215 	ld	hl, #0x0023
   40E6 E5            [11]  216 	push	hl
   40E7 CD 52 4F      [17]  217 	call	_putchar
   40EA F1            [10]  218 	pop	af
   40EB 18 08         [12]  219 	jr	00108$
   40ED                     220 00102$:
                            221 ;src/game_map.c:45: putchar (SPR_FLOOR);
   40ED 21 2E 00      [10]  222 	ld	hl, #0x002e
   40F0 E5            [11]  223 	push	hl
   40F1 CD 52 4F      [17]  224 	call	_putchar
   40F4 F1            [10]  225 	pop	af
   40F5                     226 00108$:
                            227 ;src/game_map.c:37: for (j=0; j < game_map.width; ++j) {
   40F5 DD 34 FB      [23]  228 	inc	-5 (ix)
   40F8 18 B3         [12]  229 	jr	00107$
   40FA                     230 00111$:
                            231 ;src/game_map.c:36: for (i=0; i < game_map.height; ++i) {
   40FA DD 34 FC      [23]  232 	inc	-4 (ix)
   40FD C3 81 40      [10]  233 	jp	00110$
   4100                     234 00112$:
   4100 DD F9         [10]  235 	ld	sp, ix
   4102 DD E1         [14]  236 	pop	ix
   4104 C9            [10]  237 	ret
                            238 	.area _CODE
                            239 	.area _INITIALIZER
                            240 	.area _CABS (ABS)
