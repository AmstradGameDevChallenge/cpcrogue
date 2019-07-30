                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module main
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _main
                             12 	.globl _TakeDamage
                             13 	.globl _CalculateDamage
                             14 	.globl _ClearStatusLine
                             15 	.globl _PrintCharacterStats
                             16 	.globl _InitColors
                             17 	.globl _draw_map
                             18 	.globl _InitEntities
                             19 	.globl _InitializeCharacter
                             20 	.globl _PrintAt
                             21 	.globl _cls
                             22 	.globl _pen
                             23 	.globl _paper
                             24 	.globl _border
                             25 	.globl _ink
                             26 	.globl _locate
                             27 	.globl _map_create
                             28 	.globl _putchar
                             29 	.globl _sprintf
                             30 	.globl _printf
                             31 	.globl _cpct_getRandom_mxor_u8
                             32 	.globl _cpct_setVideoMode
                             33 	.globl _cpct_isKeyPressed
                             34 	.globl _cpct_scanKeyboard
                             35 ;--------------------------------------------------------
                             36 ; special function registers
                             37 ;--------------------------------------------------------
                             38 ;--------------------------------------------------------
                             39 ; ram data
                             40 ;--------------------------------------------------------
                             41 	.area _DATA
                             42 ;--------------------------------------------------------
                             43 ; ram data
                             44 ;--------------------------------------------------------
                             45 	.area _INITIALIZED
                             46 ;--------------------------------------------------------
                             47 ; absolute external ram data
                             48 ;--------------------------------------------------------
                             49 	.area _DABS (ABS)
                             50 ;--------------------------------------------------------
                             51 ; global & static initialisations
                             52 ;--------------------------------------------------------
                             53 	.area _HOME
                             54 	.area _GSINIT
                             55 	.area _GSFINAL
                             56 	.area _GSINIT
                             57 ;--------------------------------------------------------
                             58 ; Home
                             59 ;--------------------------------------------------------
                             60 	.area _HOME
                             61 	.area _HOME
                             62 ;--------------------------------------------------------
                             63 ; code
                             64 ;--------------------------------------------------------
                             65 	.area _CODE
                             66 ;src/main.c:99: void map_create (struct TMap *map, u8 width, u8 height)
                             67 ;	---------------------------------
                             68 ; Function map_create
                             69 ; ---------------------------------
   4000                      70 _map_create::
   4000 DD E5         [15]   71 	push	ix
   4002 DD 21 00 00   [14]   72 	ld	ix,#0
   4006 DD 39         [15]   73 	add	ix,sp
   4008 21 FA FF      [10]   74 	ld	hl, #-6
   400B 39            [11]   75 	add	hl, sp
   400C F9            [ 6]   76 	ld	sp, hl
                             77 ;src/main.c:103: map->width = width;
   400D DD 4E 04      [19]   78 	ld	c,4 (ix)
   4010 DD 46 05      [19]   79 	ld	b,5 (ix)
   4013 DD 7E 06      [19]   80 	ld	a, 6 (ix)
   4016 02            [ 7]   81 	ld	(bc), a
                             82 ;src/main.c:104: map->height = height;
   4017 C5            [11]   83 	push	bc
   4018 FD E1         [14]   84 	pop	iy
   401A FD 23         [10]   85 	inc	iy
   401C DD 7E 07      [19]   86 	ld	a, 7 (ix)
   401F FD 77 00      [19]   87 	ld	0 (iy), a
                             88 ;src/main.c:105: for (i=0; i!=map->height; ++i)
   4022 21 02 00      [10]   89 	ld	hl, #0x0002
   4025 09            [11]   90 	add	hl,bc
   4026 DD 75 FC      [19]   91 	ld	-4 (ix), l
   4029 DD 74 FD      [19]   92 	ld	-3 (ix), h
   402C DD 36 FA 00   [19]   93 	ld	-6 (ix), #0x00
   4030                      94 00107$:
   4030 FD 5E 00      [19]   95 	ld	e, 0 (iy)
   4033 DD 7E FA      [19]   96 	ld	a, -6 (ix)
   4036 93            [ 4]   97 	sub	a, e
   4037 28 3F         [12]   98 	jr	Z,00102$
                             99 ;src/main.c:106: for (j=0; j!=map->width; ++j)
   4039 DD 5E FA      [19]  100 	ld	e,-6 (ix)
   403C 16 00         [ 7]  101 	ld	d,#0x00
   403E 6B            [ 4]  102 	ld	l, e
   403F 62            [ 4]  103 	ld	h, d
   4040 29            [11]  104 	add	hl, hl
   4041 29            [11]  105 	add	hl, hl
   4042 19            [11]  106 	add	hl, de
   4043 29            [11]  107 	add	hl, hl
   4044 29            [11]  108 	add	hl, hl
   4045 DD 7E FC      [19]  109 	ld	a, -4 (ix)
   4048 85            [ 4]  110 	add	a, l
   4049 DD 77 FE      [19]  111 	ld	-2 (ix), a
   404C DD 7E FD      [19]  112 	ld	a, -3 (ix)
   404F 8C            [ 4]  113 	adc	a, h
   4050 DD 77 FF      [19]  114 	ld	-1 (ix), a
   4053 DD 36 FB 00   [19]  115 	ld	-5 (ix), #0x00
   4057                     116 00104$:
   4057 0A            [ 7]  117 	ld	a, (bc)
   4058 5F            [ 4]  118 	ld	e, a
   4059 DD 7E FB      [19]  119 	ld	a, -5 (ix)
   405C 93            [ 4]  120 	sub	a, e
   405D 28 14         [12]  121 	jr	Z,00108$
                            122 ;src/main.c:107: map->tiles[i][j].blocked = FALSE;
   405F DD 7E FE      [19]  123 	ld	a, -2 (ix)
   4062 DD 86 FB      [19]  124 	add	a, -5 (ix)
   4065 5F            [ 4]  125 	ld	e, a
   4066 DD 7E FF      [19]  126 	ld	a, -1 (ix)
   4069 CE 00         [ 7]  127 	adc	a, #0x00
   406B 57            [ 4]  128 	ld	d, a
   406C AF            [ 4]  129 	xor	a, a
   406D 12            [ 7]  130 	ld	(de), a
                            131 ;src/main.c:106: for (j=0; j!=map->width; ++j)
   406E DD 34 FB      [23]  132 	inc	-5 (ix)
   4071 18 E4         [12]  133 	jr	00104$
   4073                     134 00108$:
                            135 ;src/main.c:105: for (i=0; i!=map->height; ++i)
   4073 DD 34 FA      [23]  136 	inc	-6 (ix)
   4076 18 B8         [12]  137 	jr	00107$
   4078                     138 00102$:
                            139 ;src/main.c:110: map->tiles[12][3].blocked = TRUE;
   4078 21 F5 00      [10]  140 	ld	hl, #0x00f5
   407B 09            [11]  141 	add	hl, bc
   407C 36 01         [10]  142 	ld	(hl), #0x01
                            143 ;src/main.c:111: map->tiles[3][10].blocked = TRUE;
   407E 21 48 00      [10]  144 	ld	hl, #0x0048
   4081 09            [11]  145 	add	hl, bc
   4082 36 01         [10]  146 	ld	(hl), #0x01
   4084 DD F9         [10]  147 	ld	sp, ix
   4086 DD E1         [14]  148 	pop	ix
   4088 C9            [10]  149 	ret
                            150 ;src/main.c:117: void locate (u8 x, u8 y)
                            151 ;	---------------------------------
                            152 ; Function locate
                            153 ; ---------------------------------
   4089                     154 _locate::
                            155 ;src/main.c:119: putchar(US);
   4089 21 1F 00      [10]  156 	ld	hl, #0x001f
   408C E5            [11]  157 	push	hl
   408D CD C7 4C      [17]  158 	call	_putchar
   4090 F1            [10]  159 	pop	af
                            160 ;src/main.c:120: putchar (x); putchar (y);
   4091 21 02 00      [10]  161 	ld	hl, #2+0
   4094 39            [11]  162 	add	hl, sp
   4095 4E            [ 7]  163 	ld	c, (hl)
   4096 06 00         [ 7]  164 	ld	b, #0x00
   4098 C5            [11]  165 	push	bc
   4099 CD C7 4C      [17]  166 	call	_putchar
   409C F1            [10]  167 	pop	af
   409D 21 03 00      [10]  168 	ld	hl, #3+0
   40A0 39            [11]  169 	add	hl, sp
   40A1 4E            [ 7]  170 	ld	c, (hl)
   40A2 06 00         [ 7]  171 	ld	b, #0x00
   40A4 C5            [11]  172 	push	bc
   40A5 CD C7 4C      [17]  173 	call	_putchar
   40A8 F1            [10]  174 	pop	af
   40A9 C9            [10]  175 	ret
                            176 ;src/main.c:122: void ink (u8 tinta, u8 color1, u8 color2)
                            177 ;	---------------------------------
                            178 ; Function ink
                            179 ; ---------------------------------
   40AA                     180 _ink::
                            181 ;src/main.c:124: putchar (FS);
   40AA 21 1C 00      [10]  182 	ld	hl, #0x001c
   40AD E5            [11]  183 	push	hl
   40AE CD C7 4C      [17]  184 	call	_putchar
   40B1 F1            [10]  185 	pop	af
                            186 ;src/main.c:125: putchar (tinta); putchar (color1); putchar (color2);
   40B2 21 02 00      [10]  187 	ld	hl, #2+0
   40B5 39            [11]  188 	add	hl, sp
   40B6 4E            [ 7]  189 	ld	c, (hl)
   40B7 06 00         [ 7]  190 	ld	b, #0x00
   40B9 C5            [11]  191 	push	bc
   40BA CD C7 4C      [17]  192 	call	_putchar
   40BD F1            [10]  193 	pop	af
   40BE 21 03 00      [10]  194 	ld	hl, #3+0
   40C1 39            [11]  195 	add	hl, sp
   40C2 4E            [ 7]  196 	ld	c, (hl)
   40C3 06 00         [ 7]  197 	ld	b, #0x00
   40C5 C5            [11]  198 	push	bc
   40C6 CD C7 4C      [17]  199 	call	_putchar
   40C9 F1            [10]  200 	pop	af
   40CA 21 04 00      [10]  201 	ld	hl, #4+0
   40CD 39            [11]  202 	add	hl, sp
   40CE 4E            [ 7]  203 	ld	c, (hl)
   40CF 06 00         [ 7]  204 	ld	b, #0x00
   40D1 C5            [11]  205 	push	bc
   40D2 CD C7 4C      [17]  206 	call	_putchar
   40D5 F1            [10]  207 	pop	af
   40D6 C9            [10]  208 	ret
                            209 ;src/main.c:127: void border (u8 color1, u8 color2)
                            210 ;	---------------------------------
                            211 ; Function border
                            212 ; ---------------------------------
   40D7                     213 _border::
                            214 ;src/main.c:129: putchar (GS);
   40D7 21 1D 00      [10]  215 	ld	hl, #0x001d
   40DA E5            [11]  216 	push	hl
   40DB CD C7 4C      [17]  217 	call	_putchar
   40DE F1            [10]  218 	pop	af
                            219 ;src/main.c:130: putchar (color1); putchar (color2);
   40DF 21 02 00      [10]  220 	ld	hl, #2+0
   40E2 39            [11]  221 	add	hl, sp
   40E3 4E            [ 7]  222 	ld	c, (hl)
   40E4 06 00         [ 7]  223 	ld	b, #0x00
   40E6 C5            [11]  224 	push	bc
   40E7 CD C7 4C      [17]  225 	call	_putchar
   40EA F1            [10]  226 	pop	af
   40EB 21 03 00      [10]  227 	ld	hl, #3+0
   40EE 39            [11]  228 	add	hl, sp
   40EF 4E            [ 7]  229 	ld	c, (hl)
   40F0 06 00         [ 7]  230 	ld	b, #0x00
   40F2 C5            [11]  231 	push	bc
   40F3 CD C7 4C      [17]  232 	call	_putchar
   40F6 F1            [10]  233 	pop	af
   40F7 C9            [10]  234 	ret
                            235 ;src/main.c:132: void paper (u8 color1)
                            236 ;	---------------------------------
                            237 ; Function paper
                            238 ; ---------------------------------
   40F8                     239 _paper::
                            240 ;src/main.c:134: putchar (SO);
   40F8 21 0E 00      [10]  241 	ld	hl, #0x000e
   40FB E5            [11]  242 	push	hl
   40FC CD C7 4C      [17]  243 	call	_putchar
   40FF F1            [10]  244 	pop	af
                            245 ;src/main.c:135: putchar (color1);
   4100 21 02 00      [10]  246 	ld	hl, #2+0
   4103 39            [11]  247 	add	hl, sp
   4104 4E            [ 7]  248 	ld	c, (hl)
   4105 06 00         [ 7]  249 	ld	b, #0x00
   4107 C5            [11]  250 	push	bc
   4108 CD C7 4C      [17]  251 	call	_putchar
   410B F1            [10]  252 	pop	af
   410C C9            [10]  253 	ret
                            254 ;src/main.c:137: void pen (u8 tinta)
                            255 ;	---------------------------------
                            256 ; Function pen
                            257 ; ---------------------------------
   410D                     258 _pen::
                            259 ;src/main.c:139: putchar (SI);
   410D 21 0F 00      [10]  260 	ld	hl, #0x000f
   4110 E5            [11]  261 	push	hl
   4111 CD C7 4C      [17]  262 	call	_putchar
   4114 F1            [10]  263 	pop	af
                            264 ;src/main.c:140: putchar (tinta);
   4115 21 02 00      [10]  265 	ld	hl, #2+0
   4118 39            [11]  266 	add	hl, sp
   4119 4E            [ 7]  267 	ld	c, (hl)
   411A 06 00         [ 7]  268 	ld	b, #0x00
   411C C5            [11]  269 	push	bc
   411D CD C7 4C      [17]  270 	call	_putchar
   4120 F1            [10]  271 	pop	af
   4121 C9            [10]  272 	ret
                            273 ;src/main.c:142: void cls () { putchar (FF); }
                            274 ;	---------------------------------
                            275 ; Function cls
                            276 ; ---------------------------------
   4122                     277 _cls::
   4122 21 0C 00      [10]  278 	ld	hl, #0x000c
   4125 E5            [11]  279 	push	hl
   4126 CD C7 4C      [17]  280 	call	_putchar
   4129 F1            [10]  281 	pop	af
   412A C9            [10]  282 	ret
                            283 ;src/main.c:147: void PrintAt (u8 x, u8 y, char text[], u8 color)
                            284 ;	---------------------------------
                            285 ; Function PrintAt
                            286 ; ---------------------------------
   412B                     287 _PrintAt::
                            288 ;src/main.c:149: locate (x, y);
   412B 21 03 00      [10]  289 	ld	hl, #3+0
   412E 39            [11]  290 	add	hl, sp
   412F 7E            [ 7]  291 	ld	a, (hl)
   4130 F5            [11]  292 	push	af
   4131 33            [ 6]  293 	inc	sp
   4132 21 03 00      [10]  294 	ld	hl, #3+0
   4135 39            [11]  295 	add	hl, sp
   4136 7E            [ 7]  296 	ld	a, (hl)
   4137 F5            [11]  297 	push	af
   4138 33            [ 6]  298 	inc	sp
   4139 CD 89 40      [17]  299 	call	_locate
   413C F1            [10]  300 	pop	af
                            301 ;src/main.c:150: if (color != 0xff) pen (color);
   413D FD 21 06 00   [14]  302 	ld	iy, #6
   4141 FD 39         [15]  303 	add	iy, sp
   4143 FD 7E 00      [19]  304 	ld	a, 0 (iy)
   4146 3C            [ 4]  305 	inc	a
   4147 28 09         [12]  306 	jr	Z,00102$
   4149 FD 7E 00      [19]  307 	ld	a, 0 (iy)
   414C F5            [11]  308 	push	af
   414D 33            [ 6]  309 	inc	sp
   414E CD 0D 41      [17]  310 	call	_pen
   4151 33            [ 6]  311 	inc	sp
   4152                     312 00102$:
                            313 ;src/main.c:151: printf (text);
   4152 21 04 00      [10]  314 	ld	hl, #4
   4155 39            [11]  315 	add	hl, sp
   4156 4E            [ 7]  316 	ld	c, (hl)
   4157 23            [ 6]  317 	inc	hl
   4158 46            [ 7]  318 	ld	b, (hl)
   4159 C5            [11]  319 	push	bc
   415A CD BE 4D      [17]  320 	call	_printf
   415D F1            [10]  321 	pop	af
   415E C9            [10]  322 	ret
                            323 ;src/main.c:156: void InitializeCharacter (struct TCharacter *c,
                            324 ;	---------------------------------
                            325 ; Function InitializeCharacter
                            326 ; ---------------------------------
   415F                     327 _InitializeCharacter::
   415F DD E5         [15]  328 	push	ix
   4161 DD 21 00 00   [14]  329 	ld	ix,#0
   4165 DD 39         [15]  330 	add	ix,sp
   4167 21 F6 FF      [10]  331 	ld	hl, #-10
   416A 39            [11]  332 	add	hl, sp
   416B F9            [ 6]  333 	ld	sp, hl
                            334 ;src/main.c:160: c->x = x; c->y = y;
   416C DD 4E 04      [19]  335 	ld	c,4 (ix)
   416F DD 46 05      [19]  336 	ld	b,5 (ix)
   4172 DD 7E 06      [19]  337 	ld	a, 6 (ix)
   4175 02            [ 7]  338 	ld	(bc), a
   4176 59            [ 4]  339 	ld	e, c
   4177 50            [ 4]  340 	ld	d, b
   4178 13            [ 6]  341 	inc	de
   4179 DD 7E 07      [19]  342 	ld	a, 7 (ix)
   417C 12            [ 7]  343 	ld	(de), a
                            344 ;src/main.c:161: strcpy (c->spr, spr);
   417D 59            [ 4]  345 	ld	e, c
   417E 50            [ 4]  346 	ld	d, b
   417F 13            [ 6]  347 	inc	de
   4180 13            [ 6]  348 	inc	de
   4181 C5            [11]  349 	push	bc
   4182 DD 6E 08      [19]  350 	ld	l,8 (ix)
   4185 DD 66 09      [19]  351 	ld	h,9 (ix)
   4188 AF            [ 4]  352 	xor	a, a
   4189                     353 00103$:
   4189 BE            [ 7]  354 	cp	a, (hl)
   418A ED A0         [16]  355 	ldi
   418C 20 FB         [12]  356 	jr	NZ, 00103$
   418E C1            [10]  357 	pop	bc
                            358 ;src/main.c:162: c->color = color;
   418F 21 04 00      [10]  359 	ld	hl, #0x0004
   4192 09            [11]  360 	add	hl, bc
   4193 DD 7E 0A      [19]  361 	ld	a, 10 (ix)
   4196 77            [ 7]  362 	ld	(hl), a
                            363 ;src/main.c:163: strcpy (c->name, name);
   4197 21 05 00      [10]  364 	ld	hl, #0x0005
   419A 09            [11]  365 	add	hl,bc
   419B EB            [ 4]  366 	ex	de,hl
   419C C5            [11]  367 	push	bc
   419D DD 6E 0B      [19]  368 	ld	l,11 (ix)
   41A0 DD 66 0C      [19]  369 	ld	h,12 (ix)
   41A3 AF            [ 4]  370 	xor	a, a
   41A4                     371 00104$:
   41A4 BE            [ 7]  372 	cp	a, (hl)
   41A5 ED A0         [16]  373 	ldi
   41A7 20 FB         [12]  374 	jr	NZ, 00104$
   41A9 C1            [10]  375 	pop	bc
                            376 ;src/main.c:165: c->hp = hp;
   41AA 21 14 00      [10]  377 	ld	hl, #0x0014
   41AD 09            [11]  378 	add	hl, bc
   41AE DD 7E 0D      [19]  379 	ld	a, 13 (ix)
   41B1 77            [ 7]  380 	ld	(hl), a
   41B2 23            [ 6]  381 	inc	hl
   41B3 DD 7E 0E      [19]  382 	ld	a, 14 (ix)
   41B6 77            [ 7]  383 	ld	(hl), a
                            384 ;src/main.c:166: c->str = str;
   41B7 21 16 00      [10]  385 	ld	hl, #0x0016
   41BA 09            [11]  386 	add	hl, bc
   41BB DD 7E 0F      [19]  387 	ld	a, 15 (ix)
   41BE 77            [ 7]  388 	ld	(hl), a
                            389 ;src/main.c:167: c->destr = destr;
   41BF 21 17 00      [10]  390 	ld	hl, #0x0017
   41C2 09            [11]  391 	add	hl, bc
   41C3 DD 7E 10      [19]  392 	ld	a, 16 (ix)
   41C6 77            [ 7]  393 	ld	(hl), a
                            394 ;src/main.c:168: c->refl = refl;
   41C7 21 18 00      [10]  395 	ld	hl, #0x0018
   41CA 09            [11]  396 	add	hl, bc
   41CB DD 7E 11      [19]  397 	ld	a, 17 (ix)
   41CE 77            [ 7]  398 	ld	(hl), a
                            399 ;src/main.c:170: c->atk = 1.5 * c->str + c->destr;
   41CF 21 19 00      [10]  400 	ld	hl, #0x0019
   41D2 09            [11]  401 	add	hl,bc
   41D3 DD 75 FE      [19]  402 	ld	-2 (ix), l
   41D6 DD 74 FF      [19]  403 	ld	-1 (ix), h
   41D9 C5            [11]  404 	push	bc
   41DA DD 7E 0F      [19]  405 	ld	a, 15 (ix)
   41DD F5            [11]  406 	push	af
   41DE 33            [ 6]  407 	inc	sp
   41DF CD 22 61      [17]  408 	call	___uchar2fs
   41E2 33            [ 6]  409 	inc	sp
   41E3 EB            [ 4]  410 	ex	de, hl
   41E4 E5            [11]  411 	push	hl
   41E5 D5            [11]  412 	push	de
   41E6 21 C0 3F      [10]  413 	ld	hl, #0x3fc0
   41E9 E5            [11]  414 	push	hl
   41EA 21 00 00      [10]  415 	ld	hl, #0x0000
   41ED E5            [11]  416 	push	hl
   41EE CD AA 59      [17]  417 	call	___fsmul
   41F1 F1            [10]  418 	pop	af
   41F2 F1            [10]  419 	pop	af
   41F3 F1            [10]  420 	pop	af
   41F4 F1            [10]  421 	pop	af
   41F5 DD 72 FD      [19]  422 	ld	-3 (ix), d
   41F8 DD 73 FC      [19]  423 	ld	-4 (ix), e
   41FB DD 74 FB      [19]  424 	ld	-5 (ix), h
   41FE DD 75 FA      [19]  425 	ld	-6 (ix), l
   4201 C1            [10]  426 	pop	bc
   4202 DD 5E 10      [19]  427 	ld	e, 16 (ix)
   4205 16 00         [ 7]  428 	ld	d, #0x00
   4207 C5            [11]  429 	push	bc
   4208 D5            [11]  430 	push	de
   4209 CD D8 60      [17]  431 	call	___sint2fs
   420C F1            [10]  432 	pop	af
   420D EB            [ 4]  433 	ex	de, hl
   420E E5            [11]  434 	push	hl
   420F D5            [11]  435 	push	de
   4210 DD 6E FC      [19]  436 	ld	l,-4 (ix)
   4213 DD 66 FD      [19]  437 	ld	h,-3 (ix)
   4216 E5            [11]  438 	push	hl
   4217 DD 6E FA      [19]  439 	ld	l,-6 (ix)
   421A DD 66 FB      [19]  440 	ld	h,-5 (ix)
   421D E5            [11]  441 	push	hl
   421E CD 0F 5D      [17]  442 	call	___fsadd
   4221 F1            [10]  443 	pop	af
   4222 F1            [10]  444 	pop	af
   4223 F1            [10]  445 	pop	af
   4224 F1            [10]  446 	pop	af
   4225 D5            [11]  447 	push	de
   4226 E5            [11]  448 	push	hl
   4227 CD F3 60      [17]  449 	call	___fs2uint
   422A F1            [10]  450 	pop	af
   422B F1            [10]  451 	pop	af
   422C EB            [ 4]  452 	ex	de,hl
   422D C1            [10]  453 	pop	bc
   422E DD 6E FE      [19]  454 	ld	l,-2 (ix)
   4231 DD 66 FF      [19]  455 	ld	h,-1 (ix)
   4234 73            [ 7]  456 	ld	(hl), e
   4235 23            [ 6]  457 	inc	hl
   4236 72            [ 7]  458 	ld	(hl), d
                            459 ;src/main.c:171: c->defense = 1.5 * c->destr + c->refl;
   4237 21 1B 00      [10]  460 	ld	hl, #0x001b
   423A 09            [11]  461 	add	hl,bc
   423B DD 75 FA      [19]  462 	ld	-6 (ix), l
   423E DD 74 FB      [19]  463 	ld	-5 (ix), h
   4241 DD 7E 10      [19]  464 	ld	a, 16 (ix)
   4244 F5            [11]  465 	push	af
   4245 33            [ 6]  466 	inc	sp
   4246 CD 22 61      [17]  467 	call	___uchar2fs
   4249 33            [ 6]  468 	inc	sp
   424A EB            [ 4]  469 	ex	de, hl
   424B E5            [11]  470 	push	hl
   424C D5            [11]  471 	push	de
   424D 21 C0 3F      [10]  472 	ld	hl, #0x3fc0
   4250 E5            [11]  473 	push	hl
   4251 21 00 00      [10]  474 	ld	hl, #0x0000
   4254 E5            [11]  475 	push	hl
   4255 CD AA 59      [17]  476 	call	___fsmul
   4258 F1            [10]  477 	pop	af
   4259 F1            [10]  478 	pop	af
   425A F1            [10]  479 	pop	af
   425B F1            [10]  480 	pop	af
   425C DD 72 F9      [19]  481 	ld	-7 (ix), d
   425F DD 73 F8      [19]  482 	ld	-8 (ix), e
   4262 DD 74 F7      [19]  483 	ld	-9 (ix), h
   4265 DD 75 F6      [19]  484 	ld	-10 (ix), l
   4268 DD 4E 11      [19]  485 	ld	c, 17 (ix)
   426B 06 00         [ 7]  486 	ld	b, #0x00
   426D C5            [11]  487 	push	bc
   426E CD D8 60      [17]  488 	call	___sint2fs
   4271 F1            [10]  489 	pop	af
   4272 EB            [ 4]  490 	ex	de, hl
   4273 E5            [11]  491 	push	hl
   4274 D5            [11]  492 	push	de
   4275 DD 6E F8      [19]  493 	ld	l,-8 (ix)
   4278 DD 66 F9      [19]  494 	ld	h,-7 (ix)
   427B E5            [11]  495 	push	hl
   427C DD 6E F6      [19]  496 	ld	l,-10 (ix)
   427F DD 66 F7      [19]  497 	ld	h,-9 (ix)
   4282 E5            [11]  498 	push	hl
   4283 CD 0F 5D      [17]  499 	call	___fsadd
   4286 F1            [10]  500 	pop	af
   4287 F1            [10]  501 	pop	af
   4288 F1            [10]  502 	pop	af
   4289 F1            [10]  503 	pop	af
   428A D5            [11]  504 	push	de
   428B E5            [11]  505 	push	hl
   428C CD F3 60      [17]  506 	call	___fs2uint
   428F F1            [10]  507 	pop	af
   4290 F1            [10]  508 	pop	af
   4291 4D            [ 4]  509 	ld	c, l
   4292 44            [ 4]  510 	ld	b, h
   4293 DD 6E FA      [19]  511 	ld	l,-6 (ix)
   4296 DD 66 FB      [19]  512 	ld	h,-5 (ix)
   4299 71            [ 7]  513 	ld	(hl), c
   429A 23            [ 6]  514 	inc	hl
   429B 70            [ 7]  515 	ld	(hl), b
   429C DD F9         [10]  516 	ld	sp, ix
   429E DD E1         [14]  517 	pop	ix
   42A0 C9            [10]  518 	ret
                            519 ;src/main.c:177: void InitEntities (struct TCharacter* entities[])
                            520 ;	---------------------------------
                            521 ; Function InitEntities
                            522 ; ---------------------------------
   42A1                     523 _InitEntities::
                            524 ;src/main.c:180: do {
   42A1 0E 04         [ 7]  525 	ld	c, #0x04
   42A3                     526 00101$:
                            527 ;src/main.c:181: entities[i--] = NULL;
   42A3 59            [ 4]  528 	ld	e, c
   42A4 0D            [ 4]  529 	dec	c
   42A5 7B            [ 4]  530 	ld	a, e
   42A6 17            [ 4]  531 	rla
   42A7 9F            [ 4]  532 	sbc	a, a
   42A8 57            [ 4]  533 	ld	d, a
   42A9 CB 23         [ 8]  534 	sla	e
   42AB CB 12         [ 8]  535 	rl	d
   42AD FD 21 02 00   [14]  536 	ld	iy, #2
   42B1 FD 39         [15]  537 	add	iy, sp
   42B3 FD 7E 00      [19]  538 	ld	a, 0 (iy)
   42B6 83            [ 4]  539 	add	a, e
   42B7 47            [ 4]  540 	ld	b, a
   42B8 FD 7E 01      [19]  541 	ld	a, 1 (iy)
   42BB 8A            [ 4]  542 	adc	a, d
   42BC 67            [ 4]  543 	ld	h, a
   42BD 68            [ 4]  544 	ld	l, b
   42BE AF            [ 4]  545 	xor	a, a
   42BF 77            [ 7]  546 	ld	(hl), a
   42C0 23            [ 6]  547 	inc	hl
   42C1 77            [ 7]  548 	ld	(hl), a
                            549 ;src/main.c:182: } while (i != 0);
   42C2 79            [ 4]  550 	ld	a, c
   42C3 B7            [ 4]  551 	or	a, a
   42C4 20 DD         [12]  552 	jr	NZ,00101$
                            553 ;src/main.c:183: entities[0] = NULL;
   42C6 C1            [10]  554 	pop	bc
   42C7 E1            [10]  555 	pop	hl
   42C8 E5            [11]  556 	push	hl
   42C9 C5            [11]  557 	push	bc
   42CA AF            [ 4]  558 	xor	a, a
   42CB 77            [ 7]  559 	ld	(hl), a
   42CC 23            [ 6]  560 	inc	hl
   42CD 77            [ 7]  561 	ld	(hl), a
   42CE C9            [10]  562 	ret
                            563 ;src/main.c:188: void draw_map (struct TMap *map)
                            564 ;	---------------------------------
                            565 ; Function draw_map
                            566 ; ---------------------------------
   42CF                     567 _draw_map::
   42CF DD E5         [15]  568 	push	ix
   42D1 DD 21 00 00   [14]  569 	ld	ix,#0
   42D5 DD 39         [15]  570 	add	ix,sp
   42D7 21 F7 FF      [10]  571 	ld	hl, #-9
   42DA 39            [11]  572 	add	hl, sp
   42DB F9            [ 6]  573 	ld	sp, hl
                            574 ;src/main.c:194: for (i=0; i!=map->height; ++i) {
   42DC DD 4E 04      [19]  575 	ld	c,4 (ix)
   42DF DD 46 05      [19]  576 	ld	b,5 (ix)
   42E2 DD 71 FC      [19]  577 	ld	-4 (ix), c
   42E5 DD 70 FD      [19]  578 	ld	-3 (ix), b
   42E8 11 00 00      [10]  579 	ld	de, #0x0000
   42EB                     580 00110$:
   42EB DD 6E FC      [19]  581 	ld	l,-4 (ix)
   42EE DD 66 FD      [19]  582 	ld	h,-3 (ix)
   42F1 23            [ 6]  583 	inc	hl
   42F2 6E            [ 7]  584 	ld	l, (hl)
   42F3 DD 75 FA      [19]  585 	ld	-6 (ix), l
   42F6 DD 36 FB 00   [19]  586 	ld	-5 (ix), #0x00
   42FA DD 7E FA      [19]  587 	ld	a, -6 (ix)
   42FD 93            [ 4]  588 	sub	a, e
   42FE 20 07         [12]  589 	jr	NZ,00136$
   4300 DD 7E FB      [19]  590 	ld	a, -5 (ix)
   4303 92            [ 4]  591 	sub	a, d
   4304 CA AE 43      [10]  592 	jp	Z,00112$
   4307                     593 00136$:
                            594 ;src/main.c:195: for (j=0; j!=map->width; ++j) {
   4307 21 02 00      [10]  595 	ld	hl, #0x0002
   430A 09            [11]  596 	add	hl,bc
   430B DD 75 FA      [19]  597 	ld	-6 (ix), l
   430E DD 74 FB      [19]  598 	ld	-5 (ix), h
   4311 D5            [11]  599 	push	de
   4312 6B            [ 4]  600 	ld	l, e
   4313 62            [ 4]  601 	ld	h, d
   4314 29            [11]  602 	add	hl, hl
   4315 29            [11]  603 	add	hl, hl
   4316 19            [11]  604 	add	hl, de
   4317 29            [11]  605 	add	hl, hl
   4318 29            [11]  606 	add	hl, hl
   4319 D1            [10]  607 	pop	de
   431A DD 7E FA      [19]  608 	ld	a, -6 (ix)
   431D 85            [ 4]  609 	add	a, l
   431E DD 77 FA      [19]  610 	ld	-6 (ix), a
   4321 DD 7E FB      [19]  611 	ld	a, -5 (ix)
   4324 8C            [ 4]  612 	adc	a, h
   4325 DD 77 FB      [19]  613 	ld	-5 (ix), a
   4328 DD 36 F8 00   [19]  614 	ld	-8 (ix), #0x00
   432C DD 36 F9 00   [19]  615 	ld	-7 (ix), #0x00
   4330                     616 00107$:
   4330 0A            [ 7]  617 	ld	a, (bc)
   4331 DD 77 FE      [19]  618 	ld	-2 (ix), a
   4334 DD 36 FF 00   [19]  619 	ld	-1 (ix), #0x00
   4338 DD 7E F8      [19]  620 	ld	a, -8 (ix)
   433B DD 96 FE      [19]  621 	sub	a, -2 (ix)
   433E 20 08         [12]  622 	jr	NZ,00137$
   4340 DD 7E F9      [19]  623 	ld	a, -7 (ix)
   4343 DD 96 FF      [19]  624 	sub	a, -1 (ix)
   4346 28 62         [12]  625 	jr	Z,00111$
   4348                     626 00137$:
                            627 ;src/main.c:196: is_wall = map->tiles[i][j].blocked;
   4348 DD 7E FA      [19]  628 	ld	a, -6 (ix)
   434B DD 86 F8      [19]  629 	add	a, -8 (ix)
   434E 6F            [ 4]  630 	ld	l, a
   434F DD 7E FB      [19]  631 	ld	a, -5 (ix)
   4352 DD 8E F9      [19]  632 	adc	a, -7 (ix)
   4355 67            [ 4]  633 	ld	h, a
   4356 7E            [ 7]  634 	ld	a, (hl)
   4357 DD 77 F7      [19]  635 	ld	-9 (ix), a
                            636 ;src/main.c:199: PrintAt (PLAY_X+j,PLAY_Y+i, "#", PEN_TILE);
   435A 63            [ 4]  637 	ld	h, e
   435B DD 6E F8      [19]  638 	ld	l, -8 (ix)
   435E 24            [ 4]  639 	inc	h
   435F 24            [ 4]  640 	inc	h
   4360 24            [ 4]  641 	inc	h
   4361 24            [ 4]  642 	inc	h
   4362 2C            [ 4]  643 	inc	l
   4363 2C            [ 4]  644 	inc	l
   4364 2C            [ 4]  645 	inc	l
   4365 2C            [ 4]  646 	inc	l
                            647 ;src/main.c:198: if (is_wall) {
   4366 DD 7E F7      [19]  648 	ld	a, -9 (ix)
   4369 B7            [ 4]  649 	or	a, a
   436A 28 1B         [12]  650 	jr	Z,00102$
                            651 ;src/main.c:199: PrintAt (PLAY_X+j,PLAY_Y+i, "#", PEN_TILE);
   436C FD 21 B3 43   [14]  652 	ld	iy, #___str_0
   4370 C5            [11]  653 	push	bc
   4371 D5            [11]  654 	push	de
   4372 3E 02         [ 7]  655 	ld	a, #0x02
   4374 F5            [11]  656 	push	af
   4375 33            [ 6]  657 	inc	sp
   4376 FD E5         [15]  658 	push	iy
   4378 E5            [11]  659 	push	hl
   4379 33            [ 6]  660 	inc	sp
   437A 7D            [ 4]  661 	ld	a, l
   437B F5            [11]  662 	push	af
   437C 33            [ 6]  663 	inc	sp
   437D CD 2B 41      [17]  664 	call	_PrintAt
   4380 F1            [10]  665 	pop	af
   4381 F1            [10]  666 	pop	af
   4382 33            [ 6]  667 	inc	sp
   4383 D1            [10]  668 	pop	de
   4384 C1            [10]  669 	pop	bc
   4385 18 19         [12]  670 	jr	00108$
   4387                     671 00102$:
                            672 ;src/main.c:202: PrintAt (PLAY_X+j,PLAY_Y+i, ".", PEN_TILE);
   4387 FD 21 B5 43   [14]  673 	ld	iy, #___str_1
   438B C5            [11]  674 	push	bc
   438C D5            [11]  675 	push	de
   438D 3E 02         [ 7]  676 	ld	a, #0x02
   438F F5            [11]  677 	push	af
   4390 33            [ 6]  678 	inc	sp
   4391 FD E5         [15]  679 	push	iy
   4393 E5            [11]  680 	push	hl
   4394 33            [ 6]  681 	inc	sp
   4395 7D            [ 4]  682 	ld	a, l
   4396 F5            [11]  683 	push	af
   4397 33            [ 6]  684 	inc	sp
   4398 CD 2B 41      [17]  685 	call	_PrintAt
   439B F1            [10]  686 	pop	af
   439C F1            [10]  687 	pop	af
   439D 33            [ 6]  688 	inc	sp
   439E D1            [10]  689 	pop	de
   439F C1            [10]  690 	pop	bc
   43A0                     691 00108$:
                            692 ;src/main.c:195: for (j=0; j!=map->width; ++j) {
   43A0 DD 34 F8      [23]  693 	inc	-8 (ix)
   43A3 20 8B         [12]  694 	jr	NZ,00107$
   43A5 DD 34 F9      [23]  695 	inc	-7 (ix)
   43A8 18 86         [12]  696 	jr	00107$
   43AA                     697 00111$:
                            698 ;src/main.c:194: for (i=0; i!=map->height; ++i) {
   43AA 13            [ 6]  699 	inc	de
   43AB C3 EB 42      [10]  700 	jp	00110$
   43AE                     701 00112$:
   43AE DD F9         [10]  702 	ld	sp, ix
   43B0 DD E1         [14]  703 	pop	ix
   43B2 C9            [10]  704 	ret
   43B3                     705 ___str_0:
   43B3 23                  706 	.ascii "#"
   43B4 00                  707 	.db 0x00
   43B5                     708 ___str_1:
   43B5 2E                  709 	.ascii "."
   43B6 00                  710 	.db 0x00
                            711 ;src/main.c:223: void InitColors()
                            712 ;	---------------------------------
                            713 ; Function InitColors
                            714 ; ---------------------------------
   43B7                     715 _InitColors::
                            716 ;src/main.c:225: ink (0, 0,0);
   43B7 21 00 00      [10]  717 	ld	hl, #0x0000
   43BA E5            [11]  718 	push	hl
   43BB AF            [ 4]  719 	xor	a, a
   43BC F5            [11]  720 	push	af
   43BD 33            [ 6]  721 	inc	sp
   43BE CD AA 40      [17]  722 	call	_ink
                            723 ;src/main.c:226: border (0,0); paper (0);
   43C1 33            [ 6]  724 	inc	sp
   43C2 21 00 00      [10]  725 	ld	hl,#0x0000
   43C5 E3            [19]  726 	ex	(sp),hl
   43C6 CD D7 40      [17]  727 	call	_border
   43C9 F1            [10]  728 	pop	af
   43CA AF            [ 4]  729 	xor	a, a
   43CB F5            [11]  730 	push	af
   43CC 33            [ 6]  731 	inc	sp
   43CD CD F8 40      [17]  732 	call	_paper
   43D0 33            [ 6]  733 	inc	sp
                            734 ;src/main.c:228: ink (PEN_ENTITY, INK_ENTITY, INK_ENTITY);
   43D1 21 14 14      [10]  735 	ld	hl, #0x1414
   43D4 E5            [11]  736 	push	hl
   43D5 3E 01         [ 7]  737 	ld	a, #0x01
   43D7 F5            [11]  738 	push	af
   43D8 33            [ 6]  739 	inc	sp
   43D9 CD AA 40      [17]  740 	call	_ink
                            741 ;src/main.c:229: ink (PEN_TILE, INK_LIGHT_TILE, INK_LIGHT_TILE);
   43DC 33            [ 6]  742 	inc	sp
   43DD 21 0D 0D      [10]  743 	ld	hl,#0x0d0d
   43E0 E3            [19]  744 	ex	(sp),hl
   43E1 3E 02         [ 7]  745 	ld	a, #0x02
   43E3 F5            [11]  746 	push	af
   43E4 33            [ 6]  747 	inc	sp
   43E5 CD AA 40      [17]  748 	call	_ink
                            749 ;src/main.c:230: ink (PEN_EXLORED, INK_DARK_TILE, INK_DARK_TILE);
   43E8 33            [ 6]  750 	inc	sp
   43E9 21 01 01      [10]  751 	ld	hl,#0x0101
   43EC E3            [19]  752 	ex	(sp),hl
   43ED 3E 03         [ 7]  753 	ld	a, #0x03
   43EF F5            [11]  754 	push	af
   43F0 33            [ 6]  755 	inc	sp
   43F1 CD AA 40      [17]  756 	call	_ink
   43F4 F1            [10]  757 	pop	af
   43F5 33            [ 6]  758 	inc	sp
   43F6 C9            [10]  759 	ret
                            760 ;src/main.c:236: void PrintCharacterStats (struct TCharacter *c, u8 y,
                            761 ;	---------------------------------
                            762 ; Function PrintCharacterStats
                            763 ; ---------------------------------
   43F7                     764 _PrintCharacterStats::
   43F7 DD E5         [15]  765 	push	ix
   43F9 DD 21 00 00   [14]  766 	ld	ix,#0
   43FD DD 39         [15]  767 	add	ix,sp
   43FF 21 F2 FF      [10]  768 	ld	hl, #-14
   4402 39            [11]  769 	add	hl, sp
   4403 F9            [ 6]  770 	ld	sp, hl
                            771 ;src/main.c:240: PrintAt (10,y, c->name, color1); PrintAt (21,y, c->spr, color2);
   4404 DD 7E 04      [19]  772 	ld	a, 4 (ix)
   4407 DD 77 FE      [19]  773 	ld	-2 (ix), a
   440A DD 7E 05      [19]  774 	ld	a, 5 (ix)
   440D DD 77 FF      [19]  775 	ld	-1 (ix), a
   4410 DD 7E FE      [19]  776 	ld	a, -2 (ix)
   4413 C6 05         [ 7]  777 	add	a, #0x05
   4415 4F            [ 4]  778 	ld	c, a
   4416 DD 7E FF      [19]  779 	ld	a, -1 (ix)
   4419 CE 00         [ 7]  780 	adc	a, #0x00
   441B 47            [ 4]  781 	ld	b, a
   441C DD 7E 07      [19]  782 	ld	a, 7 (ix)
   441F F5            [11]  783 	push	af
   4420 33            [ 6]  784 	inc	sp
   4421 C5            [11]  785 	push	bc
   4422 DD 56 06      [19]  786 	ld	d, 6 (ix)
   4425 1E 0A         [ 7]  787 	ld	e,#0x0a
   4427 D5            [11]  788 	push	de
   4428 CD 2B 41      [17]  789 	call	_PrintAt
   442B F1            [10]  790 	pop	af
   442C F1            [10]  791 	pop	af
   442D 33            [ 6]  792 	inc	sp
   442E DD 4E FE      [19]  793 	ld	c,-2 (ix)
   4431 DD 46 FF      [19]  794 	ld	b,-1 (ix)
   4434 03            [ 6]  795 	inc	bc
   4435 03            [ 6]  796 	inc	bc
   4436 DD 7E 08      [19]  797 	ld	a, 8 (ix)
   4439 F5            [11]  798 	push	af
   443A 33            [ 6]  799 	inc	sp
   443B C5            [11]  800 	push	bc
   443C DD 56 06      [19]  801 	ld	d, 6 (ix)
   443F 1E 15         [ 7]  802 	ld	e,#0x15
   4441 D5            [11]  803 	push	de
   4442 CD 2B 41      [17]  804 	call	_PrintAt
   4445 F1            [10]  805 	pop	af
   4446 F1            [10]  806 	pop	af
   4447 33            [ 6]  807 	inc	sp
                            808 ;src/main.c:241: PrintAt (1, y+1, "STR ",color1);
   4448 DD 46 06      [19]  809 	ld	b, 6 (ix)
   444B 04            [ 4]  810 	inc	b
   444C C5            [11]  811 	push	bc
   444D DD 7E 07      [19]  812 	ld	a, 7 (ix)
   4450 F5            [11]  813 	push	af
   4451 33            [ 6]  814 	inc	sp
   4452 21 4B 46      [10]  815 	ld	hl, #___str_2
   4455 E5            [11]  816 	push	hl
   4456 C5            [11]  817 	push	bc
   4457 33            [ 6]  818 	inc	sp
   4458 3E 01         [ 7]  819 	ld	a, #0x01
   445A F5            [11]  820 	push	af
   445B 33            [ 6]  821 	inc	sp
   445C CD 2B 41      [17]  822 	call	_PrintAt
   445F F1            [10]  823 	pop	af
   4460 F1            [10]  824 	pop	af
   4461 33            [ 6]  825 	inc	sp
   4462 C1            [10]  826 	pop	bc
                            827 ;src/main.c:242: PrintAt (10,y+1, "DES ",color1);
   4463 C5            [11]  828 	push	bc
   4464 DD 7E 07      [19]  829 	ld	a, 7 (ix)
   4467 F5            [11]  830 	push	af
   4468 33            [ 6]  831 	inc	sp
   4469 21 50 46      [10]  832 	ld	hl, #___str_3
   446C E5            [11]  833 	push	hl
   446D C5            [11]  834 	push	bc
   446E 33            [ 6]  835 	inc	sp
   446F 3E 0A         [ 7]  836 	ld	a, #0x0a
   4471 F5            [11]  837 	push	af
   4472 33            [ 6]  838 	inc	sp
   4473 CD 2B 41      [17]  839 	call	_PrintAt
   4476 F1            [10]  840 	pop	af
   4477 F1            [10]  841 	pop	af
   4478 33            [ 6]  842 	inc	sp
   4479 C1            [10]  843 	pop	bc
                            844 ;src/main.c:243: PrintAt (20,y+1, "REF ",color1);
   447A C5            [11]  845 	push	bc
   447B DD 7E 07      [19]  846 	ld	a, 7 (ix)
   447E F5            [11]  847 	push	af
   447F 33            [ 6]  848 	inc	sp
   4480 21 55 46      [10]  849 	ld	hl, #___str_4
   4483 E5            [11]  850 	push	hl
   4484 C5            [11]  851 	push	bc
   4485 33            [ 6]  852 	inc	sp
   4486 3E 14         [ 7]  853 	ld	a, #0x14
   4488 F5            [11]  854 	push	af
   4489 33            [ 6]  855 	inc	sp
   448A CD 2B 41      [17]  856 	call	_PrintAt
   448D F1            [10]  857 	pop	af
   448E F1            [10]  858 	pop	af
   448F 33            [ 6]  859 	inc	sp
   4490 C1            [10]  860 	pop	bc
                            861 ;src/main.c:244: sprintf (num, "[%d] ", c->str);
   4491 DD 6E FE      [19]  862 	ld	l,-2 (ix)
   4494 DD 66 FF      [19]  863 	ld	h,-1 (ix)
   4497 11 16 00      [10]  864 	ld	de, #0x0016
   449A 19            [11]  865 	add	hl, de
   449B 5E            [ 7]  866 	ld	e, (hl)
   449C 16 00         [ 7]  867 	ld	d, #0x00
   449E 21 00 00      [10]  868 	ld	hl, #0x0000
   44A1 39            [11]  869 	add	hl, sp
   44A2 DD 75 FC      [19]  870 	ld	-4 (ix), l
   44A5 DD 74 FD      [19]  871 	ld	-3 (ix), h
   44A8 C5            [11]  872 	push	bc
   44A9 D5            [11]  873 	push	de
   44AA 11 5A 46      [10]  874 	ld	de, #___str_5
   44AD D5            [11]  875 	push	de
   44AE E5            [11]  876 	push	hl
   44AF CD 4E 4D      [17]  877 	call	_sprintf
   44B2 21 06 00      [10]  878 	ld	hl, #6
   44B5 39            [11]  879 	add	hl, sp
   44B6 F9            [ 6]  880 	ld	sp, hl
   44B7 C1            [10]  881 	pop	bc
                            882 ;src/main.c:245: PrintAt (5,y+1, num, color2);
   44B8 DD 5E FC      [19]  883 	ld	e,-4 (ix)
   44BB DD 56 FD      [19]  884 	ld	d,-3 (ix)
   44BE C5            [11]  885 	push	bc
   44BF DD 7E 08      [19]  886 	ld	a, 8 (ix)
   44C2 F5            [11]  887 	push	af
   44C3 33            [ 6]  888 	inc	sp
   44C4 D5            [11]  889 	push	de
   44C5 C5            [11]  890 	push	bc
   44C6 33            [ 6]  891 	inc	sp
   44C7 3E 05         [ 7]  892 	ld	a, #0x05
   44C9 F5            [11]  893 	push	af
   44CA 33            [ 6]  894 	inc	sp
   44CB CD 2B 41      [17]  895 	call	_PrintAt
   44CE F1            [10]  896 	pop	af
   44CF F1            [10]  897 	pop	af
   44D0 33            [ 6]  898 	inc	sp
   44D1 C1            [10]  899 	pop	bc
                            900 ;src/main.c:246: sprintf (num, "[%d] ", c->destr);
   44D2 DD 6E FE      [19]  901 	ld	l,-2 (ix)
   44D5 DD 66 FF      [19]  902 	ld	h,-1 (ix)
   44D8 11 17 00      [10]  903 	ld	de, #0x0017
   44DB 19            [11]  904 	add	hl, de
   44DC 5E            [ 7]  905 	ld	e, (hl)
   44DD 16 00         [ 7]  906 	ld	d, #0x00
   44DF DD 6E FC      [19]  907 	ld	l,-4 (ix)
   44E2 DD 66 FD      [19]  908 	ld	h,-3 (ix)
   44E5 C5            [11]  909 	push	bc
   44E6 D5            [11]  910 	push	de
   44E7 11 5A 46      [10]  911 	ld	de, #___str_5
   44EA D5            [11]  912 	push	de
   44EB E5            [11]  913 	push	hl
   44EC CD 4E 4D      [17]  914 	call	_sprintf
   44EF 21 06 00      [10]  915 	ld	hl, #6
   44F2 39            [11]  916 	add	hl, sp
   44F3 F9            [ 6]  917 	ld	sp, hl
   44F4 C1            [10]  918 	pop	bc
                            919 ;src/main.c:247: PrintAt (15,y+1, num, color2);
   44F5 DD 5E FC      [19]  920 	ld	e,-4 (ix)
   44F8 DD 56 FD      [19]  921 	ld	d,-3 (ix)
   44FB C5            [11]  922 	push	bc
   44FC DD 7E 08      [19]  923 	ld	a, 8 (ix)
   44FF F5            [11]  924 	push	af
   4500 33            [ 6]  925 	inc	sp
   4501 D5            [11]  926 	push	de
   4502 C5            [11]  927 	push	bc
   4503 33            [ 6]  928 	inc	sp
   4504 3E 0F         [ 7]  929 	ld	a, #0x0f
   4506 F5            [11]  930 	push	af
   4507 33            [ 6]  931 	inc	sp
   4508 CD 2B 41      [17]  932 	call	_PrintAt
   450B F1            [10]  933 	pop	af
   450C F1            [10]  934 	pop	af
   450D 33            [ 6]  935 	inc	sp
   450E C1            [10]  936 	pop	bc
                            937 ;src/main.c:248: sprintf (num, "[%d] ", c->refl);
   450F DD 6E FE      [19]  938 	ld	l,-2 (ix)
   4512 DD 66 FF      [19]  939 	ld	h,-1 (ix)
   4515 11 18 00      [10]  940 	ld	de, #0x0018
   4518 19            [11]  941 	add	hl, de
   4519 5E            [ 7]  942 	ld	e, (hl)
   451A 16 00         [ 7]  943 	ld	d, #0x00
   451C DD 6E FC      [19]  944 	ld	l,-4 (ix)
   451F DD 66 FD      [19]  945 	ld	h,-3 (ix)
   4522 C5            [11]  946 	push	bc
   4523 D5            [11]  947 	push	de
   4524 11 5A 46      [10]  948 	ld	de, #___str_5
   4527 D5            [11]  949 	push	de
   4528 E5            [11]  950 	push	hl
   4529 CD 4E 4D      [17]  951 	call	_sprintf
   452C 21 06 00      [10]  952 	ld	hl, #6
   452F 39            [11]  953 	add	hl, sp
   4530 F9            [ 6]  954 	ld	sp, hl
   4531 C1            [10]  955 	pop	bc
                            956 ;src/main.c:249: PrintAt (25,y+1, num, color2);
   4532 DD 5E FC      [19]  957 	ld	e,-4 (ix)
   4535 DD 56 FD      [19]  958 	ld	d,-3 (ix)
   4538 DD 7E 08      [19]  959 	ld	a, 8 (ix)
   453B F5            [11]  960 	push	af
   453C 33            [ 6]  961 	inc	sp
   453D D5            [11]  962 	push	de
   453E C5            [11]  963 	push	bc
   453F 33            [ 6]  964 	inc	sp
   4540 3E 19         [ 7]  965 	ld	a, #0x19
   4542 F5            [11]  966 	push	af
   4543 33            [ 6]  967 	inc	sp
   4544 CD 2B 41      [17]  968 	call	_PrintAt
   4547 F1            [10]  969 	pop	af
   4548 F1            [10]  970 	pop	af
   4549 33            [ 6]  971 	inc	sp
                            972 ;src/main.c:251: PrintAt (1, y+2, "ATK ", color1);
   454A DD 46 06      [19]  973 	ld	b, 6 (ix)
   454D 04            [ 4]  974 	inc	b
   454E 04            [ 4]  975 	inc	b
   454F C5            [11]  976 	push	bc
   4550 DD 7E 07      [19]  977 	ld	a, 7 (ix)
   4553 F5            [11]  978 	push	af
   4554 33            [ 6]  979 	inc	sp
   4555 21 60 46      [10]  980 	ld	hl, #___str_6
   4558 E5            [11]  981 	push	hl
   4559 C5            [11]  982 	push	bc
   455A 33            [ 6]  983 	inc	sp
   455B 3E 01         [ 7]  984 	ld	a, #0x01
   455D F5            [11]  985 	push	af
   455E 33            [ 6]  986 	inc	sp
   455F CD 2B 41      [17]  987 	call	_PrintAt
   4562 F1            [10]  988 	pop	af
   4563 F1            [10]  989 	pop	af
   4564 33            [ 6]  990 	inc	sp
   4565 C1            [10]  991 	pop	bc
                            992 ;src/main.c:252: PrintAt (10,y+2, "DEF ", color1);
   4566 C5            [11]  993 	push	bc
   4567 DD 7E 07      [19]  994 	ld	a, 7 (ix)
   456A F5            [11]  995 	push	af
   456B 33            [ 6]  996 	inc	sp
   456C 21 65 46      [10]  997 	ld	hl, #___str_7
   456F E5            [11]  998 	push	hl
   4570 C5            [11]  999 	push	bc
   4571 33            [ 6] 1000 	inc	sp
   4572 3E 0A         [ 7] 1001 	ld	a, #0x0a
   4574 F5            [11] 1002 	push	af
   4575 33            [ 6] 1003 	inc	sp
   4576 CD 2B 41      [17] 1004 	call	_PrintAt
   4579 F1            [10] 1005 	pop	af
   457A F1            [10] 1006 	pop	af
   457B 33            [ 6] 1007 	inc	sp
   457C C1            [10] 1008 	pop	bc
                           1009 ;src/main.c:253: PrintAt (20,y+2, " HP ", color1);
   457D C5            [11] 1010 	push	bc
   457E DD 7E 07      [19] 1011 	ld	a, 7 (ix)
   4581 F5            [11] 1012 	push	af
   4582 33            [ 6] 1013 	inc	sp
   4583 21 6A 46      [10] 1014 	ld	hl, #___str_8
   4586 E5            [11] 1015 	push	hl
   4587 C5            [11] 1016 	push	bc
   4588 33            [ 6] 1017 	inc	sp
   4589 3E 14         [ 7] 1018 	ld	a, #0x14
   458B F5            [11] 1019 	push	af
   458C 33            [ 6] 1020 	inc	sp
   458D CD 2B 41      [17] 1021 	call	_PrintAt
   4590 F1            [10] 1022 	pop	af
   4591 F1            [10] 1023 	pop	af
   4592 33            [ 6] 1024 	inc	sp
   4593 C1            [10] 1025 	pop	bc
                           1026 ;src/main.c:254: sprintf (num, "[%d] ", c->atk);
   4594 DD 6E FE      [19] 1027 	ld	l,-2 (ix)
   4597 DD 66 FF      [19] 1028 	ld	h,-1 (ix)
   459A 11 19 00      [10] 1029 	ld	de, #0x0019
   459D 19            [11] 1030 	add	hl, de
   459E 5E            [ 7] 1031 	ld	e, (hl)
   459F 23            [ 6] 1032 	inc	hl
   45A0 56            [ 7] 1033 	ld	d, (hl)
   45A1 DD 6E FC      [19] 1034 	ld	l,-4 (ix)
   45A4 DD 66 FD      [19] 1035 	ld	h,-3 (ix)
   45A7 C5            [11] 1036 	push	bc
   45A8 D5            [11] 1037 	push	de
   45A9 11 5A 46      [10] 1038 	ld	de, #___str_5
   45AC D5            [11] 1039 	push	de
   45AD E5            [11] 1040 	push	hl
   45AE CD 4E 4D      [17] 1041 	call	_sprintf
   45B1 21 06 00      [10] 1042 	ld	hl, #6
   45B4 39            [11] 1043 	add	hl, sp
   45B5 F9            [ 6] 1044 	ld	sp, hl
   45B6 C1            [10] 1045 	pop	bc
                           1046 ;src/main.c:255: PrintAt (5,y+2, num, color2);
   45B7 DD 5E FC      [19] 1047 	ld	e,-4 (ix)
   45BA DD 56 FD      [19] 1048 	ld	d,-3 (ix)
   45BD C5            [11] 1049 	push	bc
   45BE DD 7E 08      [19] 1050 	ld	a, 8 (ix)
   45C1 F5            [11] 1051 	push	af
   45C2 33            [ 6] 1052 	inc	sp
   45C3 D5            [11] 1053 	push	de
   45C4 C5            [11] 1054 	push	bc
   45C5 33            [ 6] 1055 	inc	sp
   45C6 3E 05         [ 7] 1056 	ld	a, #0x05
   45C8 F5            [11] 1057 	push	af
   45C9 33            [ 6] 1058 	inc	sp
   45CA CD 2B 41      [17] 1059 	call	_PrintAt
   45CD F1            [10] 1060 	pop	af
   45CE F1            [10] 1061 	pop	af
   45CF 33            [ 6] 1062 	inc	sp
   45D0 C1            [10] 1063 	pop	bc
                           1064 ;src/main.c:256: sprintf (num, "[%d] ",c->defense);
   45D1 DD 6E FE      [19] 1065 	ld	l,-2 (ix)
   45D4 DD 66 FF      [19] 1066 	ld	h,-1 (ix)
   45D7 11 1B 00      [10] 1067 	ld	de, #0x001b
   45DA 19            [11] 1068 	add	hl, de
   45DB 5E            [ 7] 1069 	ld	e, (hl)
   45DC 23            [ 6] 1070 	inc	hl
   45DD 56            [ 7] 1071 	ld	d, (hl)
   45DE DD 6E FC      [19] 1072 	ld	l,-4 (ix)
   45E1 DD 66 FD      [19] 1073 	ld	h,-3 (ix)
   45E4 C5            [11] 1074 	push	bc
   45E5 D5            [11] 1075 	push	de
   45E6 11 5A 46      [10] 1076 	ld	de, #___str_5
   45E9 D5            [11] 1077 	push	de
   45EA E5            [11] 1078 	push	hl
   45EB CD 4E 4D      [17] 1079 	call	_sprintf
   45EE 21 06 00      [10] 1080 	ld	hl, #6
   45F1 39            [11] 1081 	add	hl, sp
   45F2 F9            [ 6] 1082 	ld	sp, hl
   45F3 C1            [10] 1083 	pop	bc
                           1084 ;src/main.c:257: PrintAt (15,y+2, num, color2);
   45F4 DD 5E FC      [19] 1085 	ld	e,-4 (ix)
   45F7 DD 56 FD      [19] 1086 	ld	d,-3 (ix)
   45FA C5            [11] 1087 	push	bc
   45FB DD 7E 08      [19] 1088 	ld	a, 8 (ix)
   45FE F5            [11] 1089 	push	af
   45FF 33            [ 6] 1090 	inc	sp
   4600 D5            [11] 1091 	push	de
   4601 C5            [11] 1092 	push	bc
   4602 33            [ 6] 1093 	inc	sp
   4603 3E 0F         [ 7] 1094 	ld	a, #0x0f
   4605 F5            [11] 1095 	push	af
   4606 33            [ 6] 1096 	inc	sp
   4607 CD 2B 41      [17] 1097 	call	_PrintAt
   460A F1            [10] 1098 	pop	af
   460B F1            [10] 1099 	pop	af
   460C 33            [ 6] 1100 	inc	sp
   460D C1            [10] 1101 	pop	bc
                           1102 ;src/main.c:258: sprintf (num, "[%d]\r\n", c->hp);
   460E DD 6E FE      [19] 1103 	ld	l,-2 (ix)
   4611 DD 66 FF      [19] 1104 	ld	h,-1 (ix)
   4614 11 14 00      [10] 1105 	ld	de, #0x0014
   4617 19            [11] 1106 	add	hl, de
   4618 5E            [ 7] 1107 	ld	e, (hl)
   4619 23            [ 6] 1108 	inc	hl
   461A 56            [ 7] 1109 	ld	d, (hl)
   461B DD 6E FC      [19] 1110 	ld	l,-4 (ix)
   461E DD 66 FD      [19] 1111 	ld	h,-3 (ix)
   4621 C5            [11] 1112 	push	bc
   4622 D5            [11] 1113 	push	de
   4623 11 6F 46      [10] 1114 	ld	de, #___str_9
   4626 D5            [11] 1115 	push	de
   4627 E5            [11] 1116 	push	hl
   4628 CD 4E 4D      [17] 1117 	call	_sprintf
   462B 21 06 00      [10] 1118 	ld	hl, #6
   462E 39            [11] 1119 	add	hl, sp
   462F F9            [ 6] 1120 	ld	sp, hl
   4630 C1            [10] 1121 	pop	bc
                           1122 ;src/main.c:259: PrintAt (25,y+2, num, color2);
   4631 DD 5E FC      [19] 1123 	ld	e,-4 (ix)
   4634 DD 56 FD      [19] 1124 	ld	d,-3 (ix)
   4637 DD 7E 08      [19] 1125 	ld	a, 8 (ix)
   463A F5            [11] 1126 	push	af
   463B 33            [ 6] 1127 	inc	sp
   463C D5            [11] 1128 	push	de
   463D C5            [11] 1129 	push	bc
   463E 33            [ 6] 1130 	inc	sp
   463F 3E 19         [ 7] 1131 	ld	a, #0x19
   4641 F5            [11] 1132 	push	af
   4642 33            [ 6] 1133 	inc	sp
   4643 CD 2B 41      [17] 1134 	call	_PrintAt
   4646 DD F9         [10] 1135 	ld	sp,ix
   4648 DD E1         [14] 1136 	pop	ix
   464A C9            [10] 1137 	ret
   464B                    1138 ___str_2:
   464B 53 54 52 20        1139 	.ascii "STR "
   464F 00                 1140 	.db 0x00
   4650                    1141 ___str_3:
   4650 44 45 53 20        1142 	.ascii "DES "
   4654 00                 1143 	.db 0x00
   4655                    1144 ___str_4:
   4655 52 45 46 20        1145 	.ascii "REF "
   4659 00                 1146 	.db 0x00
   465A                    1147 ___str_5:
   465A 5B 25 64 5D 20     1148 	.ascii "[%d] "
   465F 00                 1149 	.db 0x00
   4660                    1150 ___str_6:
   4660 41 54 4B 20        1151 	.ascii "ATK "
   4664 00                 1152 	.db 0x00
   4665                    1153 ___str_7:
   4665 44 45 46 20        1154 	.ascii "DEF "
   4669 00                 1155 	.db 0x00
   466A                    1156 ___str_8:
   466A 20 48 50 20        1157 	.ascii " HP "
   466E 00                 1158 	.db 0x00
   466F                    1159 ___str_9:
   466F 5B 25 64 5D        1160 	.ascii "[%d]"
   4673 0D                 1161 	.db 0x0d
   4674 0A                 1162 	.db 0x0a
   4675 00                 1163 	.db 0x00
                           1164 ;src/main.c:264: void ClearStatusLine()
                           1165 ;	---------------------------------
                           1166 ; Function ClearStatusLine
                           1167 ; ---------------------------------
   4676                    1168 _ClearStatusLine::
                           1169 ;src/main.c:267: for (row = 20; row <=23; ++row) {
   4676 06 14         [ 7] 1170 	ld	b, #0x14
   4678                    1171 00102$:
                           1172 ;src/main.c:268: PrintAt (1,row, "                                        ", 0xff);
   4678 C5            [11] 1173 	push	bc
   4679 3E FF         [ 7] 1174 	ld	a, #0xff
   467B F5            [11] 1175 	push	af
   467C 33            [ 6] 1176 	inc	sp
   467D 21 95 46      [10] 1177 	ld	hl, #___str_10
   4680 E5            [11] 1178 	push	hl
   4681 C5            [11] 1179 	push	bc
   4682 33            [ 6] 1180 	inc	sp
   4683 3E 01         [ 7] 1181 	ld	a, #0x01
   4685 F5            [11] 1182 	push	af
   4686 33            [ 6] 1183 	inc	sp
   4687 CD 2B 41      [17] 1184 	call	_PrintAt
   468A F1            [10] 1185 	pop	af
   468B F1            [10] 1186 	pop	af
   468C 33            [ 6] 1187 	inc	sp
   468D C1            [10] 1188 	pop	bc
                           1189 ;src/main.c:267: for (row = 20; row <=23; ++row) {
   468E 04            [ 4] 1190 	inc	b
   468F 3E 17         [ 7] 1191 	ld	a, #0x17
   4691 90            [ 4] 1192 	sub	a, b
   4692 30 E4         [12] 1193 	jr	NC,00102$
   4694 C9            [10] 1194 	ret
   4695                    1195 ___str_10:
   4695 20 20 20 20 20 20  1196 	.ascii "                                        "
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20
   46BD 00                 1197 	.db 0x00
                           1198 ;src/main.c:274: u8 CalculateDamage (struct TCharacter *c)
                           1199 ;	---------------------------------
                           1200 ; Function CalculateDamage
                           1201 ; ---------------------------------
   46BE                    1202 _CalculateDamage::
   46BE DD E5         [15] 1203 	push	ix
   46C0 DD 21 00 00   [14] 1204 	ld	ix,#0
   46C4 DD 39         [15] 1205 	add	ix,sp
                           1206 ;src/main.c:276: return (c->atk*c->atk)/(5*c->defense);
   46C6 DD 4E 04      [19] 1207 	ld	c,4 (ix)
   46C9 DD 46 05      [19] 1208 	ld	b,5 (ix)
   46CC 69            [ 4] 1209 	ld	l, c
   46CD 60            [ 4] 1210 	ld	h, b
   46CE 11 19 00      [10] 1211 	ld	de, #0x0019
   46D1 19            [11] 1212 	add	hl, de
   46D2 5E            [ 7] 1213 	ld	e, (hl)
   46D3 23            [ 6] 1214 	inc	hl
   46D4 56            [ 7] 1215 	ld	d, (hl)
   46D5 C5            [11] 1216 	push	bc
   46D6 D5            [11] 1217 	push	de
   46D7 D5            [11] 1218 	push	de
   46D8 CD DF 4C      [17] 1219 	call	__mulint
   46DB F1            [10] 1220 	pop	af
   46DC F1            [10] 1221 	pop	af
   46DD EB            [ 4] 1222 	ex	de,hl
   46DE E1            [10] 1223 	pop	hl
   46DF 01 1B 00      [10] 1224 	ld	bc, #0x001b
   46E2 09            [11] 1225 	add	hl, bc
   46E3 4E            [ 7] 1226 	ld	c, (hl)
   46E4 23            [ 6] 1227 	inc	hl
   46E5 46            [ 7] 1228 	ld	b, (hl)
   46E6 69            [ 4] 1229 	ld	l, c
   46E7 60            [ 4] 1230 	ld	h, b
   46E8 29            [11] 1231 	add	hl, hl
   46E9 29            [11] 1232 	add	hl, hl
   46EA 09            [11] 1233 	add	hl, bc
   46EB E5            [11] 1234 	push	hl
   46EC D5            [11] 1235 	push	de
   46ED CD 7A 4C      [17] 1236 	call	__divuint
   46F0 F1            [10] 1237 	pop	af
   46F1 F1            [10] 1238 	pop	af
   46F2 DD E1         [14] 1239 	pop	ix
   46F4 C9            [10] 1240 	ret
                           1241 ;src/main.c:281: void TakeDamage (struct TCharacter *c, u8 dmg)
                           1242 ;	---------------------------------
                           1243 ; Function TakeDamage
                           1244 ; ---------------------------------
   46F5                    1245 _TakeDamage::
   46F5 DD E5         [15] 1246 	push	ix
   46F7 DD 21 00 00   [14] 1247 	ld	ix,#0
   46FB DD 39         [15] 1248 	add	ix,sp
                           1249 ;src/main.c:283: c->hp -= dmg;
   46FD DD 4E 04      [19] 1250 	ld	c,4 (ix)
   4700 DD 46 05      [19] 1251 	ld	b,5 (ix)
   4703 21 14 00      [10] 1252 	ld	hl, #0x0014
   4706 09            [11] 1253 	add	hl, bc
   4707 E5            [11] 1254 	push	hl
   4708 4E            [ 7] 1255 	ld	c, (hl)
   4709 23            [ 6] 1256 	inc	hl
   470A 46            [ 7] 1257 	ld	b, (hl)
   470B E1            [10] 1258 	pop	hl
   470C DD 5E 06      [19] 1259 	ld	e, 6 (ix)
   470F 16 00         [ 7] 1260 	ld	d, #0x00
   4711 79            [ 4] 1261 	ld	a, c
   4712 93            [ 4] 1262 	sub	a, e
   4713 4F            [ 4] 1263 	ld	c, a
   4714 78            [ 4] 1264 	ld	a, b
   4715 9A            [ 4] 1265 	sbc	a, d
   4716 47            [ 4] 1266 	ld	b, a
   4717 71            [ 7] 1267 	ld	(hl), c
   4718 23            [ 6] 1268 	inc	hl
   4719 70            [ 7] 1269 	ld	(hl), b
   471A DD E1         [14] 1270 	pop	ix
   471C C9            [10] 1271 	ret
                           1272 ;src/main.c:288: void main(void) {
                           1273 ;	---------------------------------
                           1274 ; Function main
                           1275 ; ---------------------------------
   471D                    1276 _main::
   471D DD E5         [15] 1277 	push	ix
   471F DD 21 00 00   [14] 1278 	ld	ix,#0
   4723 DD 39         [15] 1279 	add	ix,sp
   4725 21 A7 FE      [10] 1280 	ld	hl, #-345
   4728 39            [11] 1281 	add	hl, sp
   4729 F9            [ 6] 1282 	ld	sp, hl
                           1283 ;src/main.c:303: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
   472A 21 00 00      [10] 1284 	ld	hl, #0x0000
   472D E5            [11] 1285 	push	hl
   472E AF            [ 4] 1286 	xor	a, a
   472F F5            [11] 1287 	push	af
   4730 33            [ 6] 1288 	inc	sp
   4731 CD AA 40      [17] 1289 	call	_ink
   4734 33            [ 6] 1290 	inc	sp
   4735 21 00 00      [10] 1291 	ld	hl,#0x0000
   4738 E3            [19] 1292 	ex	(sp),hl
   4739 3E 01         [ 7] 1293 	ld	a, #0x01
   473B F5            [11] 1294 	push	af
   473C 33            [ 6] 1295 	inc	sp
   473D CD AA 40      [17] 1296 	call	_ink
   4740 33            [ 6] 1297 	inc	sp
   4741 21 00 00      [10] 1298 	ld	hl,#0x0000
   4744 E3            [19] 1299 	ex	(sp),hl
   4745 3E 02         [ 7] 1300 	ld	a, #0x02
   4747 F5            [11] 1301 	push	af
   4748 33            [ 6] 1302 	inc	sp
   4749 CD AA 40      [17] 1303 	call	_ink
   474C F1            [10] 1304 	pop	af
   474D 33            [ 6] 1305 	inc	sp
                           1306 ;src/main.c:304: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
   474E 2E 01         [ 7] 1307 	ld	l, #0x01
   4750 CD 83 4D      [17] 1308 	call	_cpct_setVideoMode
                           1309 ;src/main.c:305: border (1,1); paper (0); pen (1);
   4753 21 01 01      [10] 1310 	ld	hl, #0x0101
   4756 E5            [11] 1311 	push	hl
   4757 CD D7 40      [17] 1312 	call	_border
   475A F1            [10] 1313 	pop	af
   475B AF            [ 4] 1314 	xor	a, a
   475C F5            [11] 1315 	push	af
   475D 33            [ 6] 1316 	inc	sp
   475E CD F8 40      [17] 1317 	call	_paper
   4761 33            [ 6] 1318 	inc	sp
   4762 3E 01         [ 7] 1319 	ld	a, #0x01
   4764 F5            [11] 1320 	push	af
   4765 33            [ 6] 1321 	inc	sp
   4766 CD 0D 41      [17] 1322 	call	_pen
   4769 33            [ 6] 1323 	inc	sp
                           1324 ;src/main.c:307: PrintAt (1,5, "      )   ___    _____    )   ___      ", 0xff);
   476A 3E FF         [ 7] 1325 	ld	a, #0xff
   476C F5            [11] 1326 	push	af
   476D 33            [ 6] 1327 	inc	sp
   476E 21 5C 4A      [10] 1328 	ld	hl, #___str_11
   4771 E5            [11] 1329 	push	hl
   4772 21 01 05      [10] 1330 	ld	hl, #0x0501
   4775 E5            [11] 1331 	push	hl
   4776 CD 2B 41      [17] 1332 	call	_PrintAt
   4779 F1            [10] 1333 	pop	af
   477A F1            [10] 1334 	pop	af
   477B 33            [ 6] 1335 	inc	sp
                           1336 ;src/main.c:308: PrintAt (1,6, "     (__/_____) (, /   ) (__/_____)    ", 0xff);
   477C 3E FF         [ 7] 1337 	ld	a, #0xff
   477E F5            [11] 1338 	push	af
   477F 33            [ 6] 1339 	inc	sp
   4780 21 84 4A      [10] 1340 	ld	hl, #___str_12
   4783 E5            [11] 1341 	push	hl
   4784 21 01 06      [10] 1342 	ld	hl, #0x0601
   4787 E5            [11] 1343 	push	hl
   4788 CD 2B 41      [17] 1344 	call	_PrintAt
   478B F1            [10] 1345 	pop	af
   478C F1            [10] 1346 	pop	af
   478D 33            [ 6] 1347 	inc	sp
                           1348 ;src/main.c:309: PrintAt (1,7, "       /         _/__ /    /           ", 0xff);
   478E 3E FF         [ 7] 1349 	ld	a, #0xff
   4790 F5            [11] 1350 	push	af
   4791 33            [ 6] 1351 	inc	sp
   4792 21 AC 4A      [10] 1352 	ld	hl, #___str_13
   4795 E5            [11] 1353 	push	hl
   4796 21 01 07      [10] 1354 	ld	hl, #0x0701
   4799 E5            [11] 1355 	push	hl
   479A CD 2B 41      [17] 1356 	call	_PrintAt
   479D F1            [10] 1357 	pop	af
   479E F1            [10] 1358 	pop	af
   479F 33            [ 6] 1359 	inc	sp
                           1360 ;src/main.c:310: PrintAt (1,8, "      /          /        /            ", 0xff);
   47A0 3E FF         [ 7] 1361 	ld	a, #0xff
   47A2 F5            [11] 1362 	push	af
   47A3 33            [ 6] 1363 	inc	sp
   47A4 21 D4 4A      [10] 1364 	ld	hl, #___str_14
   47A7 E5            [11] 1365 	push	hl
   47A8 21 01 08      [10] 1366 	ld	hl, #0x0801
   47AB E5            [11] 1367 	push	hl
   47AC CD 2B 41      [17] 1368 	call	_PrintAt
   47AF F1            [10] 1369 	pop	af
   47B0 F1            [10] 1370 	pop	af
   47B1 33            [ 6] 1371 	inc	sp
                           1372 ;src/main.c:311: PrintAt (1,9, "     (______) ) /        (______)      ", 0xff);
   47B2 3E FF         [ 7] 1373 	ld	a, #0xff
   47B4 F5            [11] 1374 	push	af
   47B5 33            [ 6] 1375 	inc	sp
   47B6 21 FC 4A      [10] 1376 	ld	hl, #___str_15
   47B9 E5            [11] 1377 	push	hl
   47BA 21 01 09      [10] 1378 	ld	hl, #0x0901
   47BD E5            [11] 1379 	push	hl
   47BE CD 2B 41      [17] 1380 	call	_PrintAt
   47C1 F1            [10] 1381 	pop	af
   47C2 F1            [10] 1382 	pop	af
   47C3 33            [ 6] 1383 	inc	sp
                           1384 ;src/main.c:312: PrintAt (1,10, "            _(_/_                      ", 0xff);
   47C4 3E FF         [ 7] 1385 	ld	a, #0xff
   47C6 F5            [11] 1386 	push	af
   47C7 33            [ 6] 1387 	inc	sp
   47C8 21 24 4B      [10] 1388 	ld	hl, #___str_16
   47CB E5            [11] 1389 	push	hl
   47CC 21 01 0A      [10] 1390 	ld	hl, #0x0a01
   47CF E5            [11] 1391 	push	hl
   47D0 CD 2B 41      [17] 1392 	call	_PrintAt
   47D3 F1            [10] 1393 	pop	af
   47D4 F1            [10] 1394 	pop	af
   47D5 33            [ 6] 1395 	inc	sp
                           1396 ;src/main.c:313: PrintAt (1,11, "           (, /   )                    ", 0xff);
   47D6 3E FF         [ 7] 1397 	ld	a, #0xff
   47D8 F5            [11] 1398 	push	af
   47D9 33            [ 6] 1399 	inc	sp
   47DA 21 4C 4B      [10] 1400 	ld	hl, #___str_17
   47DD E5            [11] 1401 	push	hl
   47DE 21 01 0B      [10] 1402 	ld	hl, #0x0b01
   47E1 E5            [11] 1403 	push	hl
   47E2 CD 2B 41      [17] 1404 	call	_PrintAt
   47E5 F1            [10] 1405 	pop	af
   47E6 F1            [10] 1406 	pop	af
   47E7 33            [ 6] 1407 	inc	sp
                           1408 ;src/main.c:314: PrintAt (1,12, "             /__ / ___      _          ", 0xff);
   47E8 3E FF         [ 7] 1409 	ld	a, #0xff
   47EA F5            [11] 1410 	push	af
   47EB 33            [ 6] 1411 	inc	sp
   47EC 21 74 4B      [10] 1412 	ld	hl, #___str_18
   47EF E5            [11] 1413 	push	hl
   47F0 21 01 0C      [10] 1414 	ld	hl, #0x0c01
   47F3 E5            [11] 1415 	push	hl
   47F4 CD 2B 41      [17] 1416 	call	_PrintAt
   47F7 F1            [10] 1417 	pop	af
   47F8 F1            [10] 1418 	pop	af
   47F9 33            [ 6] 1419 	inc	sp
                           1420 ;src/main.c:317: PrintAt (1,13, "          ) /   \\_(_(_/(_(_(/_         ", 0xff);
   47FA 3E FF         [ 7] 1421 	ld	a, #0xff
   47FC F5            [11] 1422 	push	af
   47FD 33            [ 6] 1423 	inc	sp
   47FE 21 9C 4B      [10] 1424 	ld	hl, #___str_19
   4801 E5            [11] 1425 	push	hl
   4802 21 01 0D      [10] 1426 	ld	hl, #0x0d01
   4805 E5            [11] 1427 	push	hl
   4806 CD 2B 41      [17] 1428 	call	_PrintAt
   4809 F1            [10] 1429 	pop	af
   480A F1            [10] 1430 	pop	af
   480B 33            [ 6] 1431 	inc	sp
                           1432 ;src/main.c:318: PrintAt (1,14, "         (_/       .-/                 ", 0xff);
   480C 3E FF         [ 7] 1433 	ld	a, #0xff
   480E F5            [11] 1434 	push	af
   480F 33            [ 6] 1435 	inc	sp
   4810 21 C4 4B      [10] 1436 	ld	hl, #___str_20
   4813 E5            [11] 1437 	push	hl
   4814 21 01 0E      [10] 1438 	ld	hl, #0x0e01
   4817 E5            [11] 1439 	push	hl
   4818 CD 2B 41      [17] 1440 	call	_PrintAt
   481B F1            [10] 1441 	pop	af
   481C F1            [10] 1442 	pop	af
   481D 33            [ 6] 1443 	inc	sp
                           1444 ;src/main.c:319: PrintAt (1,15, "                  (_/                  ", 0xff);
   481E 3E FF         [ 7] 1445 	ld	a, #0xff
   4820 F5            [11] 1446 	push	af
   4821 33            [ 6] 1447 	inc	sp
   4822 21 EC 4B      [10] 1448 	ld	hl, #___str_21
   4825 E5            [11] 1449 	push	hl
   4826 21 01 0F      [10] 1450 	ld	hl, #0x0f01
   4829 E5            [11] 1451 	push	hl
   482A CD 2B 41      [17] 1452 	call	_PrintAt
   482D F1            [10] 1453 	pop	af
   482E F1            [10] 1454 	pop	af
   482F 33            [ 6] 1455 	inc	sp
                           1456 ;src/main.c:320: PrintAt (10, 18, "PRESS ENTER TO START", 2);
   4830 3E 02         [ 7] 1457 	ld	a, #0x02
   4832 F5            [11] 1458 	push	af
   4833 33            [ 6] 1459 	inc	sp
   4834 21 14 4C      [10] 1460 	ld	hl, #___str_22
   4837 E5            [11] 1461 	push	hl
   4838 21 0A 12      [10] 1462 	ld	hl, #0x120a
   483B E5            [11] 1463 	push	hl
   483C CD 2B 41      [17] 1464 	call	_PrintAt
   483F F1            [10] 1465 	pop	af
                           1466 ;src/main.c:321: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);
   4840 33            [ 6] 1467 	inc	sp
   4841 21 03 03      [10] 1468 	ld	hl,#0x0303
   4844 E3            [19] 1469 	ex	(sp),hl
   4845 AF            [ 4] 1470 	xor	a, a
   4846 F5            [11] 1471 	push	af
   4847 33            [ 6] 1472 	inc	sp
   4848 CD AA 40      [17] 1473 	call	_ink
   484B 33            [ 6] 1474 	inc	sp
   484C 21 06 0F      [10] 1475 	ld	hl,#0x0f06
   484F E3            [19] 1476 	ex	(sp),hl
   4850 3E 01         [ 7] 1477 	ld	a, #0x01
   4852 F5            [11] 1478 	push	af
   4853 33            [ 6] 1479 	inc	sp
   4854 CD AA 40      [17] 1480 	call	_ink
   4857 33            [ 6] 1481 	inc	sp
   4858 21 10 10      [10] 1482 	ld	hl,#0x1010
   485B E3            [19] 1483 	ex	(sp),hl
   485C 3E 02         [ 7] 1484 	ld	a, #0x02
   485E F5            [11] 1485 	push	af
   485F 33            [ 6] 1486 	inc	sp
   4860 CD AA 40      [17] 1487 	call	_ink
   4863 33            [ 6] 1488 	inc	sp
   4864 21 03 03      [10] 1489 	ld	hl,#0x0303
   4867 E3            [19] 1490 	ex	(sp),hl
   4868 CD D7 40      [17] 1491 	call	_border
   486B F1            [10] 1492 	pop	af
                           1493 ;src/main.c:324: while (!cpct_isKeyPressed (Key_Return)) {
   486C                    1494 00101$:
   486C 21 02 04      [10] 1495 	ld	hl, #0x0402
   486F CD BB 4C      [17] 1496 	call	_cpct_isKeyPressed
   4872 7D            [ 4] 1497 	ld	a, l
   4873 B7            [ 4] 1498 	or	a, a
   4874 20 05         [12] 1499 	jr	NZ,00103$
                           1500 ;src/main.c:325: cpct_scanKeyboard ();
   4876 CD 01 4E      [17] 1501 	call	_cpct_scanKeyboard
   4879 18 F1         [12] 1502 	jr	00101$
   487B                    1503 00103$:
                           1504 ;src/main.c:329: InitColors();
   487B CD B7 43      [17] 1505 	call	_InitColors
                           1506 ;src/main.c:331: cls();
   487E CD 22 41      [17] 1507 	call	_cls
                           1508 ;src/main.c:335: SPR_PLAYER, PEN_ENTITY, "Player",
   4881 11 29 4C      [10] 1509 	ld	de, #___str_23+0
                           1510 ;src/main.c:334: InitializeCharacter (&player, 3, 3,
   4884 21 1D 00      [10] 1511 	ld	hl, #0x001d
   4887 39            [11] 1512 	add	hl, sp
   4888 DD 75 FB      [19] 1513 	ld	-5 (ix), l
   488B DD 74 FC      [19] 1514 	ld	-4 (ix), h
   488E 4D            [ 4] 1515 	ld	c, l
   488F 44            [ 4] 1516 	ld	b, h
   4890 21 0E 0C      [10] 1517 	ld	hl, #0x0c0e
   4893 E5            [11] 1518 	push	hl
   4894 3E 11         [ 7] 1519 	ld	a, #0x11
   4896 F5            [11] 1520 	push	af
   4897 33            [ 6] 1521 	inc	sp
   4898 21 96 00      [10] 1522 	ld	hl, #0x0096
   489B E5            [11] 1523 	push	hl
   489C 21 2B 4C      [10] 1524 	ld	hl, #___str_24
   489F E5            [11] 1525 	push	hl
   48A0 3E 01         [ 7] 1526 	ld	a, #0x01
   48A2 F5            [11] 1527 	push	af
   48A3 33            [ 6] 1528 	inc	sp
   48A4 D5            [11] 1529 	push	de
   48A5 21 03 03      [10] 1530 	ld	hl, #0x0303
   48A8 E5            [11] 1531 	push	hl
   48A9 C5            [11] 1532 	push	bc
   48AA CD 5F 41      [17] 1533 	call	_InitializeCharacter
   48AD 21 0E 00      [10] 1534 	ld	hl, #14
   48B0 39            [11] 1535 	add	hl, sp
   48B1 F9            [ 6] 1536 	ld	sp, hl
                           1537 ;src/main.c:339: SPR_GOBLIN, PEN_ENTITY, "Goblin",
   48B2 11 32 4C      [10] 1538 	ld	de, #___str_25+0
                           1539 ;src/main.c:338: InitializeCharacter (&goblin, 12, 3,
   48B5 21 00 00      [10] 1540 	ld	hl, #0x0000
   48B8 39            [11] 1541 	add	hl, sp
   48B9 DD 75 FE      [19] 1542 	ld	-2 (ix), l
   48BC DD 74 FF      [19] 1543 	ld	-1 (ix), h
   48BF 4D            [ 4] 1544 	ld	c, l
   48C0 44            [ 4] 1545 	ld	b, h
   48C1 21 0D 0B      [10] 1546 	ld	hl, #0x0b0d
   48C4 E5            [11] 1547 	push	hl
   48C5 3E 0C         [ 7] 1548 	ld	a, #0x0c
   48C7 F5            [11] 1549 	push	af
   48C8 33            [ 6] 1550 	inc	sp
   48C9 21 64 00      [10] 1551 	ld	hl, #0x0064
   48CC E5            [11] 1552 	push	hl
   48CD 21 34 4C      [10] 1553 	ld	hl, #___str_26
   48D0 E5            [11] 1554 	push	hl
   48D1 3E 01         [ 7] 1555 	ld	a, #0x01
   48D3 F5            [11] 1556 	push	af
   48D4 33            [ 6] 1557 	inc	sp
   48D5 D5            [11] 1558 	push	de
   48D6 21 0C 03      [10] 1559 	ld	hl, #0x030c
   48D9 E5            [11] 1560 	push	hl
   48DA C5            [11] 1561 	push	bc
   48DB CD 5F 41      [17] 1562 	call	_InitializeCharacter
   48DE 21 0E 00      [10] 1563 	ld	hl, #14
   48E1 39            [11] 1564 	add	hl, sp
   48E2 F9            [ 6] 1565 	ld	sp, hl
                           1566 ;src/main.c:348: map_create (&game_map, MAP_WIDTH, MAP_HEIGHT);
   48E3 21 3A 00      [10] 1567 	ld	hl, #0x003a
   48E6 39            [11] 1568 	add	hl, sp
   48E7 4D            [ 4] 1569 	ld	c, l
   48E8 44            [ 4] 1570 	ld	b, h
   48E9 E5            [11] 1571 	push	hl
   48EA 11 14 0E      [10] 1572 	ld	de, #0x0e14
   48ED D5            [11] 1573 	push	de
   48EE C5            [11] 1574 	push	bc
   48EF CD 00 40      [17] 1575 	call	_map_create
   48F2 F1            [10] 1576 	pop	af
   48F3 F1            [10] 1577 	pop	af
   48F4 CD CF 42      [17] 1578 	call	_draw_map
   48F7 F1            [10] 1579 	pop	af
                           1580 ;src/main.c:352: do {
   48F8                    1581 00111$:
                           1582 ;src/main.c:353: PrintCharacterStats (&player, 1, 1, 1);
   48F8 DD 4E FB      [19] 1583 	ld	c,-5 (ix)
   48FB DD 46 FC      [19] 1584 	ld	b,-4 (ix)
   48FE 21 01 01      [10] 1585 	ld	hl, #0x0101
   4901 E5            [11] 1586 	push	hl
   4902 3E 01         [ 7] 1587 	ld	a, #0x01
   4904 F5            [11] 1588 	push	af
   4905 33            [ 6] 1589 	inc	sp
   4906 C5            [11] 1590 	push	bc
   4907 CD F7 43      [17] 1591 	call	_PrintCharacterStats
   490A F1            [10] 1592 	pop	af
   490B F1            [10] 1593 	pop	af
   490C 33            [ 6] 1594 	inc	sp
                           1595 ;src/main.c:354: PrintAt (PLAY_X+player.x, PLAY_Y+player.y, player.spr, player.color);
   490D DD 6E FB      [19] 1596 	ld	l,-5 (ix)
   4910 DD 66 FC      [19] 1597 	ld	h,-4 (ix)
   4913 11 04 00      [10] 1598 	ld	de, #0x0004
   4916 19            [11] 1599 	add	hl, de
   4917 46            [ 7] 1600 	ld	b, (hl)
   4918 DD 5E FB      [19] 1601 	ld	e,-5 (ix)
   491B DD 56 FC      [19] 1602 	ld	d,-4 (ix)
   491E 13            [ 6] 1603 	inc	de
   491F 13            [ 6] 1604 	inc	de
   4920 DD 6E FB      [19] 1605 	ld	l,-5 (ix)
   4923 DD 66 FC      [19] 1606 	ld	h,-4 (ix)
   4926 23            [ 6] 1607 	inc	hl
   4927 4E            [ 7] 1608 	ld	c, (hl)
   4928 0C            [ 4] 1609 	inc	c
   4929 0C            [ 4] 1610 	inc	c
   492A 0C            [ 4] 1611 	inc	c
   492B 0C            [ 4] 1612 	inc	c
   492C DD 6E FB      [19] 1613 	ld	l,-5 (ix)
   492F DD 66 FC      [19] 1614 	ld	h,-4 (ix)
   4932 7E            [ 7] 1615 	ld	a, (hl)
   4933 C6 04         [ 7] 1616 	add	a, #0x04
   4935 DD 77 FD      [19] 1617 	ld	-3 (ix), a
   4938 C5            [11] 1618 	push	bc
   4939 33            [ 6] 1619 	inc	sp
   493A D5            [11] 1620 	push	de
   493B 79            [ 4] 1621 	ld	a, c
   493C F5            [11] 1622 	push	af
   493D 33            [ 6] 1623 	inc	sp
   493E DD 7E FD      [19] 1624 	ld	a, -3 (ix)
   4941 F5            [11] 1625 	push	af
   4942 33            [ 6] 1626 	inc	sp
   4943 CD 2B 41      [17] 1627 	call	_PrintAt
   4946 F1            [10] 1628 	pop	af
   4947 F1            [10] 1629 	pop	af
   4948 33            [ 6] 1630 	inc	sp
                           1631 ;src/main.c:355: PrintAt (PLAY_X+goblin.x, PLAY_Y+goblin.y, goblin.spr, goblin.color);
   4949 DD 6E FE      [19] 1632 	ld	l,-2 (ix)
   494C DD 66 FF      [19] 1633 	ld	h,-1 (ix)
   494F 11 04 00      [10] 1634 	ld	de, #0x0004
   4952 19            [11] 1635 	add	hl, de
   4953 46            [ 7] 1636 	ld	b, (hl)
   4954 DD 5E FE      [19] 1637 	ld	e,-2 (ix)
   4957 DD 56 FF      [19] 1638 	ld	d,-1 (ix)
   495A 13            [ 6] 1639 	inc	de
   495B 13            [ 6] 1640 	inc	de
   495C DD 6E FE      [19] 1641 	ld	l,-2 (ix)
   495F DD 66 FF      [19] 1642 	ld	h,-1 (ix)
   4962 23            [ 6] 1643 	inc	hl
   4963 4E            [ 7] 1644 	ld	c, (hl)
   4964 0C            [ 4] 1645 	inc	c
   4965 0C            [ 4] 1646 	inc	c
   4966 0C            [ 4] 1647 	inc	c
   4967 0C            [ 4] 1648 	inc	c
   4968 DD 6E FE      [19] 1649 	ld	l,-2 (ix)
   496B DD 66 FF      [19] 1650 	ld	h,-1 (ix)
   496E 7E            [ 7] 1651 	ld	a, (hl)
   496F C6 04         [ 7] 1652 	add	a, #0x04
   4971 DD 77 FD      [19] 1653 	ld	-3 (ix), a
   4974 C5            [11] 1654 	push	bc
   4975 33            [ 6] 1655 	inc	sp
   4976 D5            [11] 1656 	push	de
   4977 79            [ 4] 1657 	ld	a, c
   4978 F5            [11] 1658 	push	af
   4979 33            [ 6] 1659 	inc	sp
   497A DD 7E FD      [19] 1660 	ld	a, -3 (ix)
   497D F5            [11] 1661 	push	af
   497E 33            [ 6] 1662 	inc	sp
   497F CD 2B 41      [17] 1663 	call	_PrintAt
   4982 F1            [10] 1664 	pop	af
   4983 F1            [10] 1665 	pop	af
   4984 33            [ 6] 1666 	inc	sp
                           1667 ;src/main.c:359: cpct_scanKeyboard();
   4985 CD 01 4E      [17] 1668 	call	_cpct_scanKeyboard
                           1669 ;src/main.c:360: while (!cpct_isKeyPressed (Key_A)) {
   4988                    1670 00104$:
   4988 21 08 20      [10] 1671 	ld	hl, #0x2008
   498B CD BB 4C      [17] 1672 	call	_cpct_isKeyPressed
   498E 7D            [ 4] 1673 	ld	a, l
   498F B7            [ 4] 1674 	or	a, a
   4990 20 05         [12] 1675 	jr	NZ,00106$
                           1676 ;src/main.c:361: cpct_scanKeyboard();
   4992 CD 01 4E      [17] 1677 	call	_cpct_scanKeyboard
   4995 18 F1         [12] 1678 	jr	00104$
   4997                    1679 00106$:
                           1680 ;src/main.c:364: ClearStatusLine();
   4997 CD 76 46      [17] 1681 	call	_ClearStatusLine
                           1682 ;src/main.c:366: if (cpct_isKeyPressed (Key_A)) {
   499A 21 08 20      [10] 1683 	ld	hl, #0x2008
   499D CD BB 4C      [17] 1684 	call	_cpct_isKeyPressed
   49A0 7D            [ 4] 1685 	ld	a, l
   49A1 B7            [ 4] 1686 	or	a, a
   49A2 28 57         [12] 1687 	jr	Z,00108$
                           1688 ;src/main.c:367: dmg=CalculateDamage (&player);
   49A4 DD 4E FB      [19] 1689 	ld	c,-5 (ix)
   49A7 DD 46 FC      [19] 1690 	ld	b,-4 (ix)
   49AA C5            [11] 1691 	push	bc
   49AB CD BE 46      [17] 1692 	call	_CalculateDamage
   49AE F1            [10] 1693 	pop	af
   49AF 45            [ 4] 1694 	ld	b, l
                           1695 ;src/main.c:368: TakeDamage (&goblin, dmg);
   49B0 DD 5E FE      [19] 1696 	ld	e,-2 (ix)
   49B3 DD 56 FF      [19] 1697 	ld	d,-1 (ix)
   49B6 C5            [11] 1698 	push	bc
   49B7 C5            [11] 1699 	push	bc
   49B8 33            [ 6] 1700 	inc	sp
   49B9 D5            [11] 1701 	push	de
   49BA CD F5 46      [17] 1702 	call	_TakeDamage
   49BD 33            [ 6] 1703 	inc	sp
   49BE 21 01 15      [10] 1704 	ld	hl,#0x1501
   49C1 E3            [19] 1705 	ex	(sp),hl
   49C2 CD 89 40      [17] 1706 	call	_locate
   49C5 26 01         [ 7] 1707 	ld	h,#0x01
   49C7 E3            [19] 1708 	ex	(sp),hl
   49C8 33            [ 6] 1709 	inc	sp
   49C9 CD 0D 41      [17] 1710 	call	_pen
   49CC 33            [ 6] 1711 	inc	sp
   49CD C1            [10] 1712 	pop	bc
   49CE 11 3B 4C      [10] 1713 	ld	de, #___str_27
   49D1 C5            [11] 1714 	push	bc
   49D2 D5            [11] 1715 	push	de
   49D3 CD BE 4D      [17] 1716 	call	_printf
   49D6 26 03         [ 7] 1717 	ld	h,#0x03
   49D8 E3            [19] 1718 	ex	(sp),hl
   49D9 33            [ 6] 1719 	inc	sp
   49DA CD 0D 41      [17] 1720 	call	_pen
   49DD 33            [ 6] 1721 	inc	sp
   49DE C1            [10] 1722 	pop	bc
   49DF 48            [ 4] 1723 	ld	c, b
   49E0 06 00         [ 7] 1724 	ld	b, #0x00
   49E2 C5            [11] 1725 	push	bc
   49E3 21 49 4C      [10] 1726 	ld	hl, #___str_28
   49E6 E5            [11] 1727 	push	hl
   49E7 CD BE 4D      [17] 1728 	call	_printf
   49EA F1            [10] 1729 	pop	af
                           1730 ;src/main.c:371: pen (1); printf (" hit points");
   49EB 26 01         [ 7] 1731 	ld	h,#0x01
   49ED E3            [19] 1732 	ex	(sp),hl
   49EE 33            [ 6] 1733 	inc	sp
   49EF CD 0D 41      [17] 1734 	call	_pen
   49F2 33            [ 6] 1735 	inc	sp
   49F3 21 4C 4C      [10] 1736 	ld	hl, #___str_29
   49F6 E5            [11] 1737 	push	hl
   49F7 CD BE 4D      [17] 1738 	call	_printf
   49FA F1            [10] 1739 	pop	af
   49FB                    1740 00108$:
                           1741 ;src/main.c:374: if (cpct_rand() < 64) {
   49FB CD DB 4D      [17] 1742 	call	_cpct_getRandom_mxor_u8
   49FE 7D            [ 4] 1743 	ld	a, l
   49FF D6 40         [ 7] 1744 	sub	a, #0x40
   4A01 D2 F8 48      [10] 1745 	jp	NC, 00111$
                           1746 ;src/main.c:375: dmg=CalculateDamage (&goblin);
   4A04 DD 4E FE      [19] 1747 	ld	c,-2 (ix)
   4A07 DD 46 FF      [19] 1748 	ld	b,-1 (ix)
   4A0A C5            [11] 1749 	push	bc
   4A0B CD BE 46      [17] 1750 	call	_CalculateDamage
   4A0E F1            [10] 1751 	pop	af
   4A0F 45            [ 4] 1752 	ld	b, l
                           1753 ;src/main.c:376: TakeDamage (&player, dmg);
   4A10 DD 5E FB      [19] 1754 	ld	e,-5 (ix)
   4A13 DD 56 FC      [19] 1755 	ld	d,-4 (ix)
   4A16 C5            [11] 1756 	push	bc
   4A17 C5            [11] 1757 	push	bc
   4A18 33            [ 6] 1758 	inc	sp
   4A19 D5            [11] 1759 	push	de
   4A1A CD F5 46      [17] 1760 	call	_TakeDamage
   4A1D 33            [ 6] 1761 	inc	sp
   4A1E 21 01 16      [10] 1762 	ld	hl,#0x1601
   4A21 E3            [19] 1763 	ex	(sp),hl
   4A22 CD 89 40      [17] 1764 	call	_locate
   4A25 26 01         [ 7] 1765 	ld	h,#0x01
   4A27 E3            [19] 1766 	ex	(sp),hl
   4A28 33            [ 6] 1767 	inc	sp
   4A29 CD 0D 41      [17] 1768 	call	_pen
   4A2C 33            [ 6] 1769 	inc	sp
   4A2D 21 58 4C      [10] 1770 	ld	hl, #___str_30
   4A30 E5            [11] 1771 	push	hl
   4A31 CD BE 4D      [17] 1772 	call	_printf
   4A34 26 03         [ 7] 1773 	ld	h,#0x03
   4A36 E3            [19] 1774 	ex	(sp),hl
   4A37 33            [ 6] 1775 	inc	sp
   4A38 CD 0D 41      [17] 1776 	call	_pen
   4A3B 33            [ 6] 1777 	inc	sp
   4A3C C1            [10] 1778 	pop	bc
   4A3D 48            [ 4] 1779 	ld	c, b
   4A3E 06 00         [ 7] 1780 	ld	b, #0x00
   4A40 C5            [11] 1781 	push	bc
   4A41 21 49 4C      [10] 1782 	ld	hl, #___str_28
   4A44 E5            [11] 1783 	push	hl
   4A45 CD BE 4D      [17] 1784 	call	_printf
   4A48 F1            [10] 1785 	pop	af
                           1786 ;src/main.c:379: pen (1); printf (" hit points from goblin");
   4A49 26 01         [ 7] 1787 	ld	h,#0x01
   4A4B E3            [19] 1788 	ex	(sp),hl
   4A4C 33            [ 6] 1789 	inc	sp
   4A4D CD 0D 41      [17] 1790 	call	_pen
   4A50 33            [ 6] 1791 	inc	sp
   4A51 21 62 4C      [10] 1792 	ld	hl, #___str_31
   4A54 E5            [11] 1793 	push	hl
   4A55 CD BE 4D      [17] 1794 	call	_printf
   4A58 F1            [10] 1795 	pop	af
                           1796 ;src/main.c:382: } while (1);
   4A59 C3 F8 48      [10] 1797 	jp	00111$
   4A5C                    1798 ___str_11:
   4A5C 20 20 20 20 20 20  1799 	.ascii "      )   ___    _____    )   ___      "
        29 20 20 20 5F 5F
        5F 20 20 20 20 5F
        5F 5F 5F 5F 20 20
        20 20 29 20 20 20
        5F 5F 5F 20 20 20
        20 20 20
   4A83 00                 1800 	.db 0x00
   4A84                    1801 ___str_12:
   4A84 20 20 20 20 20 28  1802 	.ascii "     (__/_____) (, /   ) (__/_____)    "
        5F 5F 2F 5F 5F 5F
        5F 5F 29 20 28 2C
        20 2F 20 20 20 29
        20 28 5F 5F 2F 5F
        5F 5F 5F 5F 29 20
        20 20 20
   4AAB 00                 1803 	.db 0x00
   4AAC                    1804 ___str_13:
   4AAC 20 20 20 20 20 20  1805 	.ascii "       /         _/__ /    /           "
        20 2F 20 20 20 20
        20 20 20 20 20 5F
        2F 5F 5F 20 2F 20
        20 20 20 2F 20 20
        20 20 20 20 20 20
        20 20 20
   4AD3 00                 1806 	.db 0x00
   4AD4                    1807 ___str_14:
   4AD4 20 20 20 20 20 20  1808 	.ascii "      /          /        /            "
        2F 20 20 20 20 20
        20 20 20 20 20 2F
        20 20 20 20 20 20
        20 20 2F 20 20 20
        20 20 20 20 20 20
        20 20 20
   4AFB 00                 1809 	.db 0x00
   4AFC                    1810 ___str_15:
   4AFC 20 20 20 20 20 28  1811 	.ascii "     (______) ) /        (______)      "
        5F 5F 5F 5F 5F 5F
        29 20 29 20 2F 20
        20 20 20 20 20 20
        20 28 5F 5F 5F 5F
        5F 5F 29 20 20 20
        20 20 20
   4B23 00                 1812 	.db 0x00
   4B24                    1813 ___str_16:
   4B24 20 20 20 20 20 20  1814 	.ascii "            _(_/_                      "
        20 20 20 20 20 20
        5F 28 5F 2F 5F 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   4B4B 00                 1815 	.db 0x00
   4B4C                    1816 ___str_17:
   4B4C 20 20 20 20 20 20  1817 	.ascii "           (, /   )                    "
        20 20 20 20 20 28
        2C 20 2F 20 20 20
        29 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   4B73 00                 1818 	.db 0x00
   4B74                    1819 ___str_18:
   4B74 20 20 20 20 20 20  1820 	.ascii "             /__ / ___      _          "
        20 20 20 20 20 20
        20 2F 5F 5F 20 2F
        20 5F 5F 5F 20 20
        20 20 20 20 5F 20
        20 20 20 20 20 20
        20 20 20
   4B9B 00                 1821 	.db 0x00
   4B9C                    1822 ___str_19:
   4B9C 20 20 20 20 20 20  1823 	.ascii "          ) /   "
        20 20 20 20 29 20
        2F 20 20 20
   4BAC 5C                 1824 	.db 0x5c
   4BAD 5F 28 5F 28 5F 2F  1825 	.ascii "_(_(_/(_(_(/_         "
        28 5F 28 5F 28 2F
        5F 20 20 20 20 20
        20 20 20 20
   4BC3 00                 1826 	.db 0x00
   4BC4                    1827 ___str_20:
   4BC4 20 20 20 20 20 20  1828 	.ascii "         (_/       .-/                 "
        20 20 20 28 5F 2F
        20 20 20 20 20 20
        20 2E 2D 2F 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   4BEB 00                 1829 	.db 0x00
   4BEC                    1830 ___str_21:
   4BEC 20 20 20 20 20 20  1831 	.ascii "                  (_/                  "
        20 20 20 20 20 20
        20 20 20 20 20 20
        28 5F 2F 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   4C13 00                 1832 	.db 0x00
   4C14                    1833 ___str_22:
   4C14 50 52 45 53 53 20  1834 	.ascii "PRESS ENTER TO START"
        45 4E 54 45 52 20
        54 4F 20 53 54 41
        52 54
   4C28 00                 1835 	.db 0x00
   4C29                    1836 ___str_23:
   4C29 40                 1837 	.ascii "@"
   4C2A 00                 1838 	.db 0x00
   4C2B                    1839 ___str_24:
   4C2B 50 6C 61 79 65 72  1840 	.ascii "Player"
   4C31 00                 1841 	.db 0x00
   4C32                    1842 ___str_25:
   4C32 67                 1843 	.ascii "g"
   4C33 00                 1844 	.db 0x00
   4C34                    1845 ___str_26:
   4C34 47 6F 62 6C 69 6E  1846 	.ascii "Goblin"
   4C3A 00                 1847 	.db 0x00
   4C3B                    1848 ___str_27:
   4C3B 67 6F 62 6C 69 6E  1849 	.ascii "goblin takes "
        20 74 61 6B 65 73
        20
   4C48 00                 1850 	.db 0x00
   4C49                    1851 ___str_28:
   4C49 25 64              1852 	.ascii "%d"
   4C4B 00                 1853 	.db 0x00
   4C4C                    1854 ___str_29:
   4C4C 20 68 69 74 20 70  1855 	.ascii " hit points"
        6F 69 6E 74 73
   4C57 00                 1856 	.db 0x00
   4C58                    1857 ___str_30:
   4C58 79 6F 75 20 74 61  1858 	.ascii "you take "
        6B 65 20
   4C61 00                 1859 	.db 0x00
   4C62                    1860 ___str_31:
   4C62 20 68 69 74 20 70  1861 	.ascii " hit points from goblin"
        6F 69 6E 74 73 20
        66 72 6F 6D 20 67
        6F 62 6C 69 6E
   4C79 00                 1862 	.db 0x00
                           1863 	.area _CODE
                           1864 	.area _INITIALIZER
                           1865 	.area _CABS (ABS)
