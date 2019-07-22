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
                             16 	.globl _InitializeCharacter
                             17 	.globl _PrintAt
                             18 	.globl _cls
                             19 	.globl _pen
                             20 	.globl _paper
                             21 	.globl _border
                             22 	.globl _ink
                             23 	.globl _locate
                             24 	.globl _putchar
                             25 	.globl _sprintf
                             26 	.globl _printf
                             27 	.globl _cpct_getRandom_mxor_u8
                             28 	.globl _cpct_setVideoMode
                             29 	.globl _cpct_isKeyPressed
                             30 	.globl _cpct_scanKeyboard
                             31 ;--------------------------------------------------------
                             32 ; special function registers
                             33 ;--------------------------------------------------------
                             34 ;--------------------------------------------------------
                             35 ; ram data
                             36 ;--------------------------------------------------------
                             37 	.area _DATA
                             38 ;--------------------------------------------------------
                             39 ; ram data
                             40 ;--------------------------------------------------------
                             41 	.area _INITIALIZED
                             42 ;--------------------------------------------------------
                             43 ; absolute external ram data
                             44 ;--------------------------------------------------------
                             45 	.area _DABS (ABS)
                             46 ;--------------------------------------------------------
                             47 ; global & static initialisations
                             48 ;--------------------------------------------------------
                             49 	.area _HOME
                             50 	.area _GSINIT
                             51 	.area _GSFINAL
                             52 	.area _GSINIT
                             53 ;--------------------------------------------------------
                             54 ; Home
                             55 ;--------------------------------------------------------
                             56 	.area _HOME
                             57 	.area _HOME
                             58 ;--------------------------------------------------------
                             59 ; code
                             60 ;--------------------------------------------------------
                             61 	.area _CODE
                             62 ;src/main.c:52: void locate (u8 x, u8 y)
                             63 ;	---------------------------------
                             64 ; Function locate
                             65 ; ---------------------------------
   4000                      66 _locate::
                             67 ;src/main.c:54: putchar(US);
   4000 21 1F 00      [10]   68 	ld	hl, #0x001f
   4003 E5            [11]   69 	push	hl
   4004 CD 87 4A      [17]   70 	call	_putchar
   4007 F1            [10]   71 	pop	af
                             72 ;src/main.c:55: putchar (x); putchar (y);
   4008 21 02 00      [10]   73 	ld	hl, #2+0
   400B 39            [11]   74 	add	hl, sp
   400C 4E            [ 7]   75 	ld	c, (hl)
   400D 06 00         [ 7]   76 	ld	b, #0x00
   400F C5            [11]   77 	push	bc
   4010 CD 87 4A      [17]   78 	call	_putchar
   4013 F1            [10]   79 	pop	af
   4014 21 03 00      [10]   80 	ld	hl, #3+0
   4017 39            [11]   81 	add	hl, sp
   4018 4E            [ 7]   82 	ld	c, (hl)
   4019 06 00         [ 7]   83 	ld	b, #0x00
   401B C5            [11]   84 	push	bc
   401C CD 87 4A      [17]   85 	call	_putchar
   401F F1            [10]   86 	pop	af
   4020 C9            [10]   87 	ret
                             88 ;src/main.c:57: void ink (u8 tinta, u8 color1, u8 color2)
                             89 ;	---------------------------------
                             90 ; Function ink
                             91 ; ---------------------------------
   4021                      92 _ink::
                             93 ;src/main.c:59: putchar (FS);
   4021 21 1C 00      [10]   94 	ld	hl, #0x001c
   4024 E5            [11]   95 	push	hl
   4025 CD 87 4A      [17]   96 	call	_putchar
   4028 F1            [10]   97 	pop	af
                             98 ;src/main.c:60: putchar (tinta); putchar (color1); putchar (color2);
   4029 21 02 00      [10]   99 	ld	hl, #2+0
   402C 39            [11]  100 	add	hl, sp
   402D 4E            [ 7]  101 	ld	c, (hl)
   402E 06 00         [ 7]  102 	ld	b, #0x00
   4030 C5            [11]  103 	push	bc
   4031 CD 87 4A      [17]  104 	call	_putchar
   4034 F1            [10]  105 	pop	af
   4035 21 03 00      [10]  106 	ld	hl, #3+0
   4038 39            [11]  107 	add	hl, sp
   4039 4E            [ 7]  108 	ld	c, (hl)
   403A 06 00         [ 7]  109 	ld	b, #0x00
   403C C5            [11]  110 	push	bc
   403D CD 87 4A      [17]  111 	call	_putchar
   4040 F1            [10]  112 	pop	af
   4041 21 04 00      [10]  113 	ld	hl, #4+0
   4044 39            [11]  114 	add	hl, sp
   4045 4E            [ 7]  115 	ld	c, (hl)
   4046 06 00         [ 7]  116 	ld	b, #0x00
   4048 C5            [11]  117 	push	bc
   4049 CD 87 4A      [17]  118 	call	_putchar
   404C F1            [10]  119 	pop	af
   404D C9            [10]  120 	ret
                            121 ;src/main.c:62: void border (u8 color1, u8 color2)
                            122 ;	---------------------------------
                            123 ; Function border
                            124 ; ---------------------------------
   404E                     125 _border::
                            126 ;src/main.c:64: putchar (GS);
   404E 21 1D 00      [10]  127 	ld	hl, #0x001d
   4051 E5            [11]  128 	push	hl
   4052 CD 87 4A      [17]  129 	call	_putchar
   4055 F1            [10]  130 	pop	af
                            131 ;src/main.c:65: putchar (color1); putchar (color2);
   4056 21 02 00      [10]  132 	ld	hl, #2+0
   4059 39            [11]  133 	add	hl, sp
   405A 4E            [ 7]  134 	ld	c, (hl)
   405B 06 00         [ 7]  135 	ld	b, #0x00
   405D C5            [11]  136 	push	bc
   405E CD 87 4A      [17]  137 	call	_putchar
   4061 F1            [10]  138 	pop	af
   4062 21 03 00      [10]  139 	ld	hl, #3+0
   4065 39            [11]  140 	add	hl, sp
   4066 4E            [ 7]  141 	ld	c, (hl)
   4067 06 00         [ 7]  142 	ld	b, #0x00
   4069 C5            [11]  143 	push	bc
   406A CD 87 4A      [17]  144 	call	_putchar
   406D F1            [10]  145 	pop	af
   406E C9            [10]  146 	ret
                            147 ;src/main.c:68: void paper (u8 color1)
                            148 ;	---------------------------------
                            149 ; Function paper
                            150 ; ---------------------------------
   406F                     151 _paper::
                            152 ;src/main.c:70: putchar (SO);
   406F 21 0E 00      [10]  153 	ld	hl, #0x000e
   4072 E5            [11]  154 	push	hl
   4073 CD 87 4A      [17]  155 	call	_putchar
   4076 F1            [10]  156 	pop	af
                            157 ;src/main.c:71: putchar (color1);
   4077 21 02 00      [10]  158 	ld	hl, #2+0
   407A 39            [11]  159 	add	hl, sp
   407B 4E            [ 7]  160 	ld	c, (hl)
   407C 06 00         [ 7]  161 	ld	b, #0x00
   407E C5            [11]  162 	push	bc
   407F CD 87 4A      [17]  163 	call	_putchar
   4082 F1            [10]  164 	pop	af
   4083 C9            [10]  165 	ret
                            166 ;src/main.c:73: void pen (u8 tinta)
                            167 ;	---------------------------------
                            168 ; Function pen
                            169 ; ---------------------------------
   4084                     170 _pen::
                            171 ;src/main.c:75: putchar (SI);
   4084 21 0F 00      [10]  172 	ld	hl, #0x000f
   4087 E5            [11]  173 	push	hl
   4088 CD 87 4A      [17]  174 	call	_putchar
   408B F1            [10]  175 	pop	af
                            176 ;src/main.c:76: putchar (tinta);
   408C 21 02 00      [10]  177 	ld	hl, #2+0
   408F 39            [11]  178 	add	hl, sp
   4090 4E            [ 7]  179 	ld	c, (hl)
   4091 06 00         [ 7]  180 	ld	b, #0x00
   4093 C5            [11]  181 	push	bc
   4094 CD 87 4A      [17]  182 	call	_putchar
   4097 F1            [10]  183 	pop	af
   4098 C9            [10]  184 	ret
                            185 ;src/main.c:78: void cls ()
                            186 ;	---------------------------------
                            187 ; Function cls
                            188 ; ---------------------------------
   4099                     189 _cls::
                            190 ;src/main.c:80: putchar (FF);
   4099 21 0C 00      [10]  191 	ld	hl, #0x000c
   409C E5            [11]  192 	push	hl
   409D CD 87 4A      [17]  193 	call	_putchar
   40A0 F1            [10]  194 	pop	af
   40A1 C9            [10]  195 	ret
                            196 ;src/main.c:85: void PrintAt (u8 x, u8 y, char text[], u8 color)
                            197 ;	---------------------------------
                            198 ; Function PrintAt
                            199 ; ---------------------------------
   40A2                     200 _PrintAt::
                            201 ;src/main.c:87: locate (x, y);
   40A2 21 03 00      [10]  202 	ld	hl, #3+0
   40A5 39            [11]  203 	add	hl, sp
   40A6 7E            [ 7]  204 	ld	a, (hl)
   40A7 F5            [11]  205 	push	af
   40A8 33            [ 6]  206 	inc	sp
   40A9 21 03 00      [10]  207 	ld	hl, #3+0
   40AC 39            [11]  208 	add	hl, sp
   40AD 7E            [ 7]  209 	ld	a, (hl)
   40AE F5            [11]  210 	push	af
   40AF 33            [ 6]  211 	inc	sp
   40B0 CD 00 40      [17]  212 	call	_locate
   40B3 F1            [10]  213 	pop	af
                            214 ;src/main.c:88: if (color != 0xff) pen (color);
   40B4 FD 21 06 00   [14]  215 	ld	iy, #6
   40B8 FD 39         [15]  216 	add	iy, sp
   40BA FD 7E 00      [19]  217 	ld	a, 0 (iy)
   40BD 3C            [ 4]  218 	inc	a
   40BE 28 09         [12]  219 	jr	Z,00102$
   40C0 FD 7E 00      [19]  220 	ld	a, 0 (iy)
   40C3 F5            [11]  221 	push	af
   40C4 33            [ 6]  222 	inc	sp
   40C5 CD 84 40      [17]  223 	call	_pen
   40C8 33            [ 6]  224 	inc	sp
   40C9                     225 00102$:
                            226 ;src/main.c:89: printf (text);
   40C9 21 04 00      [10]  227 	ld	hl, #4
   40CC 39            [11]  228 	add	hl, sp
   40CD 4E            [ 7]  229 	ld	c, (hl)
   40CE 23            [ 6]  230 	inc	hl
   40CF 46            [ 7]  231 	ld	b, (hl)
   40D0 C5            [11]  232 	push	bc
   40D1 CD 7E 4B      [17]  233 	call	_printf
   40D4 F1            [10]  234 	pop	af
   40D5 C9            [10]  235 	ret
                            236 ;src/main.c:94: void InitializeCharacter (struct TCharacter *c,
                            237 ;	---------------------------------
                            238 ; Function InitializeCharacter
                            239 ; ---------------------------------
   40D6                     240 _InitializeCharacter::
   40D6 DD E5         [15]  241 	push	ix
   40D8 DD 21 00 00   [14]  242 	ld	ix,#0
   40DC DD 39         [15]  243 	add	ix,sp
   40DE 21 F6 FF      [10]  244 	ld	hl, #-10
   40E1 39            [11]  245 	add	hl, sp
   40E2 F9            [ 6]  246 	ld	sp, hl
                            247 ;src/main.c:98: c->_hp = hp;
   40E3 DD 4E 04      [19]  248 	ld	c,4 (ix)
   40E6 DD 46 05      [19]  249 	ld	b,5 (ix)
   40E9 69            [ 4]  250 	ld	l, c
   40EA 60            [ 4]  251 	ld	h, b
   40EB DD 7E 06      [19]  252 	ld	a, 6 (ix)
   40EE 77            [ 7]  253 	ld	(hl), a
   40EF 23            [ 6]  254 	inc	hl
   40F0 DD 7E 07      [19]  255 	ld	a, 7 (ix)
   40F3 77            [ 7]  256 	ld	(hl), a
                            257 ;src/main.c:99: c->_str = str;
   40F4 59            [ 4]  258 	ld	e, c
   40F5 50            [ 4]  259 	ld	d, b
   40F6 13            [ 6]  260 	inc	de
   40F7 13            [ 6]  261 	inc	de
   40F8 DD 7E 08      [19]  262 	ld	a, 8 (ix)
   40FB 12            [ 7]  263 	ld	(de), a
                            264 ;src/main.c:100: c->_destr = destr;
   40FC 59            [ 4]  265 	ld	e, c
   40FD 50            [ 4]  266 	ld	d, b
   40FE 13            [ 6]  267 	inc	de
   40FF 13            [ 6]  268 	inc	de
   4100 13            [ 6]  269 	inc	de
   4101 DD 7E 09      [19]  270 	ld	a, 9 (ix)
   4104 12            [ 7]  271 	ld	(de), a
                            272 ;src/main.c:101: c->_refl = refl;
   4105 21 04 00      [10]  273 	ld	hl, #0x0004
   4108 09            [11]  274 	add	hl, bc
   4109 DD 7E 0A      [19]  275 	ld	a, 10 (ix)
   410C 77            [ 7]  276 	ld	(hl), a
                            277 ;src/main.c:102: c->_spr[0] = spr; c->_spr[1] = '\0';
   410D 21 09 00      [10]  278 	ld	hl, #0x0009
   4110 09            [11]  279 	add	hl, bc
   4111 DD 7E 0B      [19]  280 	ld	a, 11 (ix)
   4114 77            [ 7]  281 	ld	(hl), a
   4115 21 0A 00      [10]  282 	ld	hl, #0x000a
   4118 09            [11]  283 	add	hl, bc
   4119 36 00         [10]  284 	ld	(hl), #0x00
                            285 ;src/main.c:103: c->_atk = 1.5 * c->_str + c->_destr;
   411B 21 05 00      [10]  286 	ld	hl, #0x0005
   411E 09            [11]  287 	add	hl,bc
   411F E3            [19]  288 	ex	(sp), hl
   4120 C5            [11]  289 	push	bc
   4121 DD 7E 08      [19]  290 	ld	a, 8 (ix)
   4124 F5            [11]  291 	push	af
   4125 33            [ 6]  292 	inc	sp
   4126 CD E2 5E      [17]  293 	call	___uchar2fs
   4129 33            [ 6]  294 	inc	sp
   412A EB            [ 4]  295 	ex	de, hl
   412B E5            [11]  296 	push	hl
   412C D5            [11]  297 	push	de
   412D 21 C0 3F      [10]  298 	ld	hl, #0x3fc0
   4130 E5            [11]  299 	push	hl
   4131 21 00 00      [10]  300 	ld	hl, #0x0000
   4134 E5            [11]  301 	push	hl
   4135 CD 6A 57      [17]  302 	call	___fsmul
   4138 F1            [10]  303 	pop	af
   4139 F1            [10]  304 	pop	af
   413A F1            [10]  305 	pop	af
   413B F1            [10]  306 	pop	af
   413C DD 72 FF      [19]  307 	ld	-1 (ix), d
   413F DD 73 FE      [19]  308 	ld	-2 (ix), e
   4142 DD 74 FD      [19]  309 	ld	-3 (ix), h
   4145 DD 75 FC      [19]  310 	ld	-4 (ix), l
   4148 C1            [10]  311 	pop	bc
   4149 DD 5E 09      [19]  312 	ld	e, 9 (ix)
   414C 16 00         [ 7]  313 	ld	d, #0x00
   414E C5            [11]  314 	push	bc
   414F D5            [11]  315 	push	de
   4150 CD 98 5E      [17]  316 	call	___sint2fs
   4153 F1            [10]  317 	pop	af
   4154 EB            [ 4]  318 	ex	de, hl
   4155 E5            [11]  319 	push	hl
   4156 D5            [11]  320 	push	de
   4157 DD 6E FE      [19]  321 	ld	l,-2 (ix)
   415A DD 66 FF      [19]  322 	ld	h,-1 (ix)
   415D E5            [11]  323 	push	hl
   415E DD 6E FC      [19]  324 	ld	l,-4 (ix)
   4161 DD 66 FD      [19]  325 	ld	h,-3 (ix)
   4164 E5            [11]  326 	push	hl
   4165 CD CF 5A      [17]  327 	call	___fsadd
   4168 F1            [10]  328 	pop	af
   4169 F1            [10]  329 	pop	af
   416A F1            [10]  330 	pop	af
   416B F1            [10]  331 	pop	af
   416C D5            [11]  332 	push	de
   416D E5            [11]  333 	push	hl
   416E CD B3 5E      [17]  334 	call	___fs2uint
   4171 F1            [10]  335 	pop	af
   4172 F1            [10]  336 	pop	af
   4173 EB            [ 4]  337 	ex	de,hl
   4174 C1            [10]  338 	pop	bc
   4175 E1            [10]  339 	pop	hl
   4176 E5            [11]  340 	push	hl
   4177 73            [ 7]  341 	ld	(hl), e
   4178 23            [ 6]  342 	inc	hl
   4179 72            [ 7]  343 	ld	(hl), d
                            344 ;src/main.c:104: c->_defense = 1.5 * c->_destr + c->_refl;
   417A 21 07 00      [10]  345 	ld	hl, #0x0007
   417D 09            [11]  346 	add	hl,bc
   417E DD 75 FC      [19]  347 	ld	-4 (ix), l
   4181 DD 74 FD      [19]  348 	ld	-3 (ix), h
   4184 C5            [11]  349 	push	bc
   4185 DD 7E 09      [19]  350 	ld	a, 9 (ix)
   4188 F5            [11]  351 	push	af
   4189 33            [ 6]  352 	inc	sp
   418A CD E2 5E      [17]  353 	call	___uchar2fs
   418D 33            [ 6]  354 	inc	sp
   418E EB            [ 4]  355 	ex	de, hl
   418F E5            [11]  356 	push	hl
   4190 D5            [11]  357 	push	de
   4191 21 C0 3F      [10]  358 	ld	hl, #0x3fc0
   4194 E5            [11]  359 	push	hl
   4195 21 00 00      [10]  360 	ld	hl, #0x0000
   4198 E5            [11]  361 	push	hl
   4199 CD 6A 57      [17]  362 	call	___fsmul
   419C F1            [10]  363 	pop	af
   419D F1            [10]  364 	pop	af
   419E F1            [10]  365 	pop	af
   419F F1            [10]  366 	pop	af
   41A0 DD 72 FB      [19]  367 	ld	-5 (ix), d
   41A3 DD 73 FA      [19]  368 	ld	-6 (ix), e
   41A6 DD 74 F9      [19]  369 	ld	-7 (ix), h
   41A9 DD 75 F8      [19]  370 	ld	-8 (ix), l
   41AC C1            [10]  371 	pop	bc
   41AD DD 5E 0A      [19]  372 	ld	e, 10 (ix)
   41B0 16 00         [ 7]  373 	ld	d, #0x00
   41B2 C5            [11]  374 	push	bc
   41B3 D5            [11]  375 	push	de
   41B4 CD 98 5E      [17]  376 	call	___sint2fs
   41B7 F1            [10]  377 	pop	af
   41B8 EB            [ 4]  378 	ex	de, hl
   41B9 E5            [11]  379 	push	hl
   41BA D5            [11]  380 	push	de
   41BB DD 6E FA      [19]  381 	ld	l,-6 (ix)
   41BE DD 66 FB      [19]  382 	ld	h,-5 (ix)
   41C1 E5            [11]  383 	push	hl
   41C2 DD 6E F8      [19]  384 	ld	l,-8 (ix)
   41C5 DD 66 F9      [19]  385 	ld	h,-7 (ix)
   41C8 E5            [11]  386 	push	hl
   41C9 CD CF 5A      [17]  387 	call	___fsadd
   41CC F1            [10]  388 	pop	af
   41CD F1            [10]  389 	pop	af
   41CE F1            [10]  390 	pop	af
   41CF F1            [10]  391 	pop	af
   41D0 D5            [11]  392 	push	de
   41D1 E5            [11]  393 	push	hl
   41D2 CD B3 5E      [17]  394 	call	___fs2uint
   41D5 F1            [10]  395 	pop	af
   41D6 F1            [10]  396 	pop	af
   41D7 EB            [ 4]  397 	ex	de,hl
   41D8 C1            [10]  398 	pop	bc
   41D9 DD 6E FC      [19]  399 	ld	l,-4 (ix)
   41DC DD 66 FD      [19]  400 	ld	h,-3 (ix)
   41DF 73            [ 7]  401 	ld	(hl), e
   41E0 23            [ 6]  402 	inc	hl
   41E1 72            [ 7]  403 	ld	(hl), d
                            404 ;src/main.c:105: strcpy (c->name, name);
   41E2 21 0B 00      [10]  405 	ld	hl, #0x000b
   41E5 09            [11]  406 	add	hl,bc
   41E6 EB            [ 4]  407 	ex	de,hl
   41E7 DD 6E 0C      [19]  408 	ld	l,12 (ix)
   41EA DD 66 0D      [19]  409 	ld	h,13 (ix)
   41ED AF            [ 4]  410 	xor	a, a
   41EE                     411 00103$:
   41EE BE            [ 7]  412 	cp	a, (hl)
   41EF ED A0         [16]  413 	ldi
   41F1 20 FB         [12]  414 	jr	NZ, 00103$
   41F3 DD F9         [10]  415 	ld	sp, ix
   41F5 DD E1         [14]  416 	pop	ix
   41F7 C9            [10]  417 	ret
                            418 ;src/main.c:110: void PrintCharacterStats (struct TCharacter *c, u8 y,
                            419 ;	---------------------------------
                            420 ; Function PrintCharacterStats
                            421 ; ---------------------------------
   41F8                     422 _PrintCharacterStats::
   41F8 DD E5         [15]  423 	push	ix
   41FA DD 21 00 00   [14]  424 	ld	ix,#0
   41FE DD 39         [15]  425 	add	ix,sp
   4200 21 F2 FF      [10]  426 	ld	hl, #-14
   4203 39            [11]  427 	add	hl, sp
   4204 F9            [ 6]  428 	ld	sp, hl
                            429 ;src/main.c:114: PrintAt (10,y, c->name, color1); PrintAt (21,y, c->_spr, color2);
   4205 DD 7E 04      [19]  430 	ld	a, 4 (ix)
   4208 DD 77 FE      [19]  431 	ld	-2 (ix), a
   420B DD 7E 05      [19]  432 	ld	a, 5 (ix)
   420E DD 77 FF      [19]  433 	ld	-1 (ix), a
   4211 DD 7E FE      [19]  434 	ld	a, -2 (ix)
   4214 C6 0B         [ 7]  435 	add	a, #0x0b
   4216 4F            [ 4]  436 	ld	c, a
   4217 DD 7E FF      [19]  437 	ld	a, -1 (ix)
   421A CE 00         [ 7]  438 	adc	a, #0x00
   421C 47            [ 4]  439 	ld	b, a
   421D DD 7E 07      [19]  440 	ld	a, 7 (ix)
   4220 F5            [11]  441 	push	af
   4221 33            [ 6]  442 	inc	sp
   4222 C5            [11]  443 	push	bc
   4223 DD 56 06      [19]  444 	ld	d, 6 (ix)
   4226 1E 0A         [ 7]  445 	ld	e,#0x0a
   4228 D5            [11]  446 	push	de
   4229 CD A2 40      [17]  447 	call	_PrintAt
   422C F1            [10]  448 	pop	af
   422D F1            [10]  449 	pop	af
   422E 33            [ 6]  450 	inc	sp
   422F DD 7E FE      [19]  451 	ld	a, -2 (ix)
   4232 C6 09         [ 7]  452 	add	a, #0x09
   4234 4F            [ 4]  453 	ld	c, a
   4235 DD 7E FF      [19]  454 	ld	a, -1 (ix)
   4238 CE 00         [ 7]  455 	adc	a, #0x00
   423A 47            [ 4]  456 	ld	b, a
   423B DD 7E 08      [19]  457 	ld	a, 8 (ix)
   423E F5            [11]  458 	push	af
   423F 33            [ 6]  459 	inc	sp
   4240 C5            [11]  460 	push	bc
   4241 DD 56 06      [19]  461 	ld	d, 6 (ix)
   4244 1E 15         [ 7]  462 	ld	e,#0x15
   4246 D5            [11]  463 	push	de
   4247 CD A2 40      [17]  464 	call	_PrintAt
   424A F1            [10]  465 	pop	af
   424B F1            [10]  466 	pop	af
   424C 33            [ 6]  467 	inc	sp
                            468 ;src/main.c:115: PrintAt (1, y+1, "STR ",color1);
   424D DD 46 06      [19]  469 	ld	b, 6 (ix)
   4250 04            [ 4]  470 	inc	b
   4251 C5            [11]  471 	push	bc
   4252 DD 7E 07      [19]  472 	ld	a, 7 (ix)
   4255 F5            [11]  473 	push	af
   4256 33            [ 6]  474 	inc	sp
   4257 21 49 44      [10]  475 	ld	hl, #___str_0
   425A E5            [11]  476 	push	hl
   425B C5            [11]  477 	push	bc
   425C 33            [ 6]  478 	inc	sp
   425D 3E 01         [ 7]  479 	ld	a, #0x01
   425F F5            [11]  480 	push	af
   4260 33            [ 6]  481 	inc	sp
   4261 CD A2 40      [17]  482 	call	_PrintAt
   4264 F1            [10]  483 	pop	af
   4265 F1            [10]  484 	pop	af
   4266 33            [ 6]  485 	inc	sp
   4267 C1            [10]  486 	pop	bc
                            487 ;src/main.c:116: PrintAt (10,y+1, "DES ",color1);
   4268 C5            [11]  488 	push	bc
   4269 DD 7E 07      [19]  489 	ld	a, 7 (ix)
   426C F5            [11]  490 	push	af
   426D 33            [ 6]  491 	inc	sp
   426E 21 4E 44      [10]  492 	ld	hl, #___str_1
   4271 E5            [11]  493 	push	hl
   4272 C5            [11]  494 	push	bc
   4273 33            [ 6]  495 	inc	sp
   4274 3E 0A         [ 7]  496 	ld	a, #0x0a
   4276 F5            [11]  497 	push	af
   4277 33            [ 6]  498 	inc	sp
   4278 CD A2 40      [17]  499 	call	_PrintAt
   427B F1            [10]  500 	pop	af
   427C F1            [10]  501 	pop	af
   427D 33            [ 6]  502 	inc	sp
   427E C1            [10]  503 	pop	bc
                            504 ;src/main.c:117: PrintAt (20,y+1, "REF ",color1);
   427F C5            [11]  505 	push	bc
   4280 DD 7E 07      [19]  506 	ld	a, 7 (ix)
   4283 F5            [11]  507 	push	af
   4284 33            [ 6]  508 	inc	sp
   4285 21 53 44      [10]  509 	ld	hl, #___str_2
   4288 E5            [11]  510 	push	hl
   4289 C5            [11]  511 	push	bc
   428A 33            [ 6]  512 	inc	sp
   428B 3E 14         [ 7]  513 	ld	a, #0x14
   428D F5            [11]  514 	push	af
   428E 33            [ 6]  515 	inc	sp
   428F CD A2 40      [17]  516 	call	_PrintAt
   4292 F1            [10]  517 	pop	af
   4293 F1            [10]  518 	pop	af
   4294 33            [ 6]  519 	inc	sp
   4295 C1            [10]  520 	pop	bc
                            521 ;src/main.c:118: sprintf (num, "[%d] ", c->_str);
   4296 DD 6E FE      [19]  522 	ld	l,-2 (ix)
   4299 DD 66 FF      [19]  523 	ld	h,-1 (ix)
   429C 23            [ 6]  524 	inc	hl
   429D 23            [ 6]  525 	inc	hl
   429E 5E            [ 7]  526 	ld	e, (hl)
   429F 16 00         [ 7]  527 	ld	d, #0x00
   42A1 21 00 00      [10]  528 	ld	hl, #0x0000
   42A4 39            [11]  529 	add	hl, sp
   42A5 DD 75 FC      [19]  530 	ld	-4 (ix), l
   42A8 DD 74 FD      [19]  531 	ld	-3 (ix), h
   42AB C5            [11]  532 	push	bc
   42AC D5            [11]  533 	push	de
   42AD 11 58 44      [10]  534 	ld	de, #___str_3
   42B0 D5            [11]  535 	push	de
   42B1 E5            [11]  536 	push	hl
   42B2 CD 0E 4B      [17]  537 	call	_sprintf
   42B5 21 06 00      [10]  538 	ld	hl, #6
   42B8 39            [11]  539 	add	hl, sp
   42B9 F9            [ 6]  540 	ld	sp, hl
   42BA C1            [10]  541 	pop	bc
                            542 ;src/main.c:119: PrintAt (5,y+1, num, color2);
   42BB DD 5E FC      [19]  543 	ld	e,-4 (ix)
   42BE DD 56 FD      [19]  544 	ld	d,-3 (ix)
   42C1 C5            [11]  545 	push	bc
   42C2 DD 7E 08      [19]  546 	ld	a, 8 (ix)
   42C5 F5            [11]  547 	push	af
   42C6 33            [ 6]  548 	inc	sp
   42C7 D5            [11]  549 	push	de
   42C8 C5            [11]  550 	push	bc
   42C9 33            [ 6]  551 	inc	sp
   42CA 3E 05         [ 7]  552 	ld	a, #0x05
   42CC F5            [11]  553 	push	af
   42CD 33            [ 6]  554 	inc	sp
   42CE CD A2 40      [17]  555 	call	_PrintAt
   42D1 F1            [10]  556 	pop	af
   42D2 F1            [10]  557 	pop	af
   42D3 33            [ 6]  558 	inc	sp
   42D4 C1            [10]  559 	pop	bc
                            560 ;src/main.c:120: sprintf (num, "[%d] ", c->_destr);
   42D5 DD 6E FE      [19]  561 	ld	l,-2 (ix)
   42D8 DD 66 FF      [19]  562 	ld	h,-1 (ix)
   42DB 23            [ 6]  563 	inc	hl
   42DC 23            [ 6]  564 	inc	hl
   42DD 23            [ 6]  565 	inc	hl
   42DE 5E            [ 7]  566 	ld	e, (hl)
   42DF 16 00         [ 7]  567 	ld	d, #0x00
   42E1 DD 6E FC      [19]  568 	ld	l,-4 (ix)
   42E4 DD 66 FD      [19]  569 	ld	h,-3 (ix)
   42E7 C5            [11]  570 	push	bc
   42E8 D5            [11]  571 	push	de
   42E9 11 58 44      [10]  572 	ld	de, #___str_3
   42EC D5            [11]  573 	push	de
   42ED E5            [11]  574 	push	hl
   42EE CD 0E 4B      [17]  575 	call	_sprintf
   42F1 21 06 00      [10]  576 	ld	hl, #6
   42F4 39            [11]  577 	add	hl, sp
   42F5 F9            [ 6]  578 	ld	sp, hl
   42F6 C1            [10]  579 	pop	bc
                            580 ;src/main.c:121: PrintAt (15,y+1, num, color2);
   42F7 DD 5E FC      [19]  581 	ld	e,-4 (ix)
   42FA DD 56 FD      [19]  582 	ld	d,-3 (ix)
   42FD C5            [11]  583 	push	bc
   42FE DD 7E 08      [19]  584 	ld	a, 8 (ix)
   4301 F5            [11]  585 	push	af
   4302 33            [ 6]  586 	inc	sp
   4303 D5            [11]  587 	push	de
   4304 C5            [11]  588 	push	bc
   4305 33            [ 6]  589 	inc	sp
   4306 3E 0F         [ 7]  590 	ld	a, #0x0f
   4308 F5            [11]  591 	push	af
   4309 33            [ 6]  592 	inc	sp
   430A CD A2 40      [17]  593 	call	_PrintAt
   430D F1            [10]  594 	pop	af
   430E F1            [10]  595 	pop	af
   430F 33            [ 6]  596 	inc	sp
   4310 C1            [10]  597 	pop	bc
                            598 ;src/main.c:122: sprintf (num, "[%d] ", c->_refl);
   4311 DD 6E FE      [19]  599 	ld	l,-2 (ix)
   4314 DD 66 FF      [19]  600 	ld	h,-1 (ix)
   4317 11 04 00      [10]  601 	ld	de, #0x0004
   431A 19            [11]  602 	add	hl, de
   431B 5E            [ 7]  603 	ld	e, (hl)
   431C 16 00         [ 7]  604 	ld	d, #0x00
   431E DD 6E FC      [19]  605 	ld	l,-4 (ix)
   4321 DD 66 FD      [19]  606 	ld	h,-3 (ix)
   4324 C5            [11]  607 	push	bc
   4325 D5            [11]  608 	push	de
   4326 11 58 44      [10]  609 	ld	de, #___str_3
   4329 D5            [11]  610 	push	de
   432A E5            [11]  611 	push	hl
   432B CD 0E 4B      [17]  612 	call	_sprintf
   432E 21 06 00      [10]  613 	ld	hl, #6
   4331 39            [11]  614 	add	hl, sp
   4332 F9            [ 6]  615 	ld	sp, hl
   4333 C1            [10]  616 	pop	bc
                            617 ;src/main.c:123: PrintAt (25,y+1, num, color2);
   4334 DD 5E FC      [19]  618 	ld	e,-4 (ix)
   4337 DD 56 FD      [19]  619 	ld	d,-3 (ix)
   433A DD 7E 08      [19]  620 	ld	a, 8 (ix)
   433D F5            [11]  621 	push	af
   433E 33            [ 6]  622 	inc	sp
   433F D5            [11]  623 	push	de
   4340 C5            [11]  624 	push	bc
   4341 33            [ 6]  625 	inc	sp
   4342 3E 19         [ 7]  626 	ld	a, #0x19
   4344 F5            [11]  627 	push	af
   4345 33            [ 6]  628 	inc	sp
   4346 CD A2 40      [17]  629 	call	_PrintAt
   4349 F1            [10]  630 	pop	af
   434A F1            [10]  631 	pop	af
   434B 33            [ 6]  632 	inc	sp
                            633 ;src/main.c:125: PrintAt (1, y+2, "ATK ", color1);
   434C DD 46 06      [19]  634 	ld	b, 6 (ix)
   434F 04            [ 4]  635 	inc	b
   4350 04            [ 4]  636 	inc	b
   4351 C5            [11]  637 	push	bc
   4352 DD 7E 07      [19]  638 	ld	a, 7 (ix)
   4355 F5            [11]  639 	push	af
   4356 33            [ 6]  640 	inc	sp
   4357 21 5E 44      [10]  641 	ld	hl, #___str_4
   435A E5            [11]  642 	push	hl
   435B C5            [11]  643 	push	bc
   435C 33            [ 6]  644 	inc	sp
   435D 3E 01         [ 7]  645 	ld	a, #0x01
   435F F5            [11]  646 	push	af
   4360 33            [ 6]  647 	inc	sp
   4361 CD A2 40      [17]  648 	call	_PrintAt
   4364 F1            [10]  649 	pop	af
   4365 F1            [10]  650 	pop	af
   4366 33            [ 6]  651 	inc	sp
   4367 C1            [10]  652 	pop	bc
                            653 ;src/main.c:126: PrintAt (10,y+2, "DEF ", color1);
   4368 C5            [11]  654 	push	bc
   4369 DD 7E 07      [19]  655 	ld	a, 7 (ix)
   436C F5            [11]  656 	push	af
   436D 33            [ 6]  657 	inc	sp
   436E 21 63 44      [10]  658 	ld	hl, #___str_5
   4371 E5            [11]  659 	push	hl
   4372 C5            [11]  660 	push	bc
   4373 33            [ 6]  661 	inc	sp
   4374 3E 0A         [ 7]  662 	ld	a, #0x0a
   4376 F5            [11]  663 	push	af
   4377 33            [ 6]  664 	inc	sp
   4378 CD A2 40      [17]  665 	call	_PrintAt
   437B F1            [10]  666 	pop	af
   437C F1            [10]  667 	pop	af
   437D 33            [ 6]  668 	inc	sp
   437E C1            [10]  669 	pop	bc
                            670 ;src/main.c:127: PrintAt (20,y+2, " HP ", color1);
   437F C5            [11]  671 	push	bc
   4380 DD 7E 07      [19]  672 	ld	a, 7 (ix)
   4383 F5            [11]  673 	push	af
   4384 33            [ 6]  674 	inc	sp
   4385 21 68 44      [10]  675 	ld	hl, #___str_6
   4388 E5            [11]  676 	push	hl
   4389 C5            [11]  677 	push	bc
   438A 33            [ 6]  678 	inc	sp
   438B 3E 14         [ 7]  679 	ld	a, #0x14
   438D F5            [11]  680 	push	af
   438E 33            [ 6]  681 	inc	sp
   438F CD A2 40      [17]  682 	call	_PrintAt
   4392 F1            [10]  683 	pop	af
   4393 F1            [10]  684 	pop	af
   4394 33            [ 6]  685 	inc	sp
   4395 C1            [10]  686 	pop	bc
                            687 ;src/main.c:128: sprintf (num, "[%d] ", c->_atk);
   4396 DD 6E FE      [19]  688 	ld	l,-2 (ix)
   4399 DD 66 FF      [19]  689 	ld	h,-1 (ix)
   439C 11 05 00      [10]  690 	ld	de, #0x0005
   439F 19            [11]  691 	add	hl, de
   43A0 5E            [ 7]  692 	ld	e, (hl)
   43A1 23            [ 6]  693 	inc	hl
   43A2 56            [ 7]  694 	ld	d, (hl)
   43A3 DD 6E FC      [19]  695 	ld	l,-4 (ix)
   43A6 DD 66 FD      [19]  696 	ld	h,-3 (ix)
   43A9 C5            [11]  697 	push	bc
   43AA D5            [11]  698 	push	de
   43AB 11 58 44      [10]  699 	ld	de, #___str_3
   43AE D5            [11]  700 	push	de
   43AF E5            [11]  701 	push	hl
   43B0 CD 0E 4B      [17]  702 	call	_sprintf
   43B3 21 06 00      [10]  703 	ld	hl, #6
   43B6 39            [11]  704 	add	hl, sp
   43B7 F9            [ 6]  705 	ld	sp, hl
   43B8 C1            [10]  706 	pop	bc
                            707 ;src/main.c:129: PrintAt (5,y+2, num, color2);
   43B9 DD 5E FC      [19]  708 	ld	e,-4 (ix)
   43BC DD 56 FD      [19]  709 	ld	d,-3 (ix)
   43BF C5            [11]  710 	push	bc
   43C0 DD 7E 08      [19]  711 	ld	a, 8 (ix)
   43C3 F5            [11]  712 	push	af
   43C4 33            [ 6]  713 	inc	sp
   43C5 D5            [11]  714 	push	de
   43C6 C5            [11]  715 	push	bc
   43C7 33            [ 6]  716 	inc	sp
   43C8 3E 05         [ 7]  717 	ld	a, #0x05
   43CA F5            [11]  718 	push	af
   43CB 33            [ 6]  719 	inc	sp
   43CC CD A2 40      [17]  720 	call	_PrintAt
   43CF F1            [10]  721 	pop	af
   43D0 F1            [10]  722 	pop	af
   43D1 33            [ 6]  723 	inc	sp
   43D2 C1            [10]  724 	pop	bc
                            725 ;src/main.c:130: sprintf (num, "[%d] ",c->_defense);
   43D3 DD 6E FE      [19]  726 	ld	l,-2 (ix)
   43D6 DD 66 FF      [19]  727 	ld	h,-1 (ix)
   43D9 11 07 00      [10]  728 	ld	de, #0x0007
   43DC 19            [11]  729 	add	hl, de
   43DD 5E            [ 7]  730 	ld	e, (hl)
   43DE 23            [ 6]  731 	inc	hl
   43DF 56            [ 7]  732 	ld	d, (hl)
   43E0 DD 6E FC      [19]  733 	ld	l,-4 (ix)
   43E3 DD 66 FD      [19]  734 	ld	h,-3 (ix)
   43E6 C5            [11]  735 	push	bc
   43E7 D5            [11]  736 	push	de
   43E8 11 58 44      [10]  737 	ld	de, #___str_3
   43EB D5            [11]  738 	push	de
   43EC E5            [11]  739 	push	hl
   43ED CD 0E 4B      [17]  740 	call	_sprintf
   43F0 21 06 00      [10]  741 	ld	hl, #6
   43F3 39            [11]  742 	add	hl, sp
   43F4 F9            [ 6]  743 	ld	sp, hl
   43F5 C1            [10]  744 	pop	bc
                            745 ;src/main.c:131: PrintAt (15,y+2, num, color2);
   43F6 DD 5E FC      [19]  746 	ld	e,-4 (ix)
   43F9 DD 56 FD      [19]  747 	ld	d,-3 (ix)
   43FC C5            [11]  748 	push	bc
   43FD DD 7E 08      [19]  749 	ld	a, 8 (ix)
   4400 F5            [11]  750 	push	af
   4401 33            [ 6]  751 	inc	sp
   4402 D5            [11]  752 	push	de
   4403 C5            [11]  753 	push	bc
   4404 33            [ 6]  754 	inc	sp
   4405 3E 0F         [ 7]  755 	ld	a, #0x0f
   4407 F5            [11]  756 	push	af
   4408 33            [ 6]  757 	inc	sp
   4409 CD A2 40      [17]  758 	call	_PrintAt
   440C F1            [10]  759 	pop	af
   440D F1            [10]  760 	pop	af
   440E 33            [ 6]  761 	inc	sp
   440F C1            [10]  762 	pop	bc
                            763 ;src/main.c:132: sprintf (num, "[%d]\r\n", c->_hp);
   4410 DD 6E FE      [19]  764 	ld	l,-2 (ix)
   4413 DD 66 FF      [19]  765 	ld	h,-1 (ix)
   4416 5E            [ 7]  766 	ld	e, (hl)
   4417 23            [ 6]  767 	inc	hl
   4418 56            [ 7]  768 	ld	d, (hl)
   4419 DD 6E FC      [19]  769 	ld	l,-4 (ix)
   441C DD 66 FD      [19]  770 	ld	h,-3 (ix)
   441F C5            [11]  771 	push	bc
   4420 D5            [11]  772 	push	de
   4421 11 6D 44      [10]  773 	ld	de, #___str_7
   4424 D5            [11]  774 	push	de
   4425 E5            [11]  775 	push	hl
   4426 CD 0E 4B      [17]  776 	call	_sprintf
   4429 21 06 00      [10]  777 	ld	hl, #6
   442C 39            [11]  778 	add	hl, sp
   442D F9            [ 6]  779 	ld	sp, hl
   442E C1            [10]  780 	pop	bc
                            781 ;src/main.c:133: PrintAt (25,y+2, num, color2);
   442F DD 5E FC      [19]  782 	ld	e,-4 (ix)
   4432 DD 56 FD      [19]  783 	ld	d,-3 (ix)
   4435 DD 7E 08      [19]  784 	ld	a, 8 (ix)
   4438 F5            [11]  785 	push	af
   4439 33            [ 6]  786 	inc	sp
   443A D5            [11]  787 	push	de
   443B C5            [11]  788 	push	bc
   443C 33            [ 6]  789 	inc	sp
   443D 3E 19         [ 7]  790 	ld	a, #0x19
   443F F5            [11]  791 	push	af
   4440 33            [ 6]  792 	inc	sp
   4441 CD A2 40      [17]  793 	call	_PrintAt
   4444 DD F9         [10]  794 	ld	sp,ix
   4446 DD E1         [14]  795 	pop	ix
   4448 C9            [10]  796 	ret
   4449                     797 ___str_0:
   4449 53 54 52 20         798 	.ascii "STR "
   444D 00                  799 	.db 0x00
   444E                     800 ___str_1:
   444E 44 45 53 20         801 	.ascii "DES "
   4452 00                  802 	.db 0x00
   4453                     803 ___str_2:
   4453 52 45 46 20         804 	.ascii "REF "
   4457 00                  805 	.db 0x00
   4458                     806 ___str_3:
   4458 5B 25 64 5D 20      807 	.ascii "[%d] "
   445D 00                  808 	.db 0x00
   445E                     809 ___str_4:
   445E 41 54 4B 20         810 	.ascii "ATK "
   4462 00                  811 	.db 0x00
   4463                     812 ___str_5:
   4463 44 45 46 20         813 	.ascii "DEF "
   4467 00                  814 	.db 0x00
   4468                     815 ___str_6:
   4468 20 48 50 20         816 	.ascii " HP "
   446C 00                  817 	.db 0x00
   446D                     818 ___str_7:
   446D 5B 25 64 5D         819 	.ascii "[%d]"
   4471 0D                  820 	.db 0x0d
   4472 0A                  821 	.db 0x0a
   4473 00                  822 	.db 0x00
                            823 ;src/main.c:138: void ClearStatusLine()
                            824 ;	---------------------------------
                            825 ; Function ClearStatusLine
                            826 ; ---------------------------------
   4474                     827 _ClearStatusLine::
                            828 ;src/main.c:141: for (row = 20; row <=23; ++row) {
   4474 06 14         [ 7]  829 	ld	b, #0x14
   4476                     830 00102$:
                            831 ;src/main.c:142: PrintAt (1,row, "                                        ", 0xff);
   4476 C5            [11]  832 	push	bc
   4477 3E FF         [ 7]  833 	ld	a, #0xff
   4479 F5            [11]  834 	push	af
   447A 33            [ 6]  835 	inc	sp
   447B 21 93 44      [10]  836 	ld	hl, #___str_8
   447E E5            [11]  837 	push	hl
   447F C5            [11]  838 	push	bc
   4480 33            [ 6]  839 	inc	sp
   4481 3E 01         [ 7]  840 	ld	a, #0x01
   4483 F5            [11]  841 	push	af
   4484 33            [ 6]  842 	inc	sp
   4485 CD A2 40      [17]  843 	call	_PrintAt
   4488 F1            [10]  844 	pop	af
   4489 F1            [10]  845 	pop	af
   448A 33            [ 6]  846 	inc	sp
   448B C1            [10]  847 	pop	bc
                            848 ;src/main.c:141: for (row = 20; row <=23; ++row) {
   448C 04            [ 4]  849 	inc	b
   448D 3E 17         [ 7]  850 	ld	a, #0x17
   448F 90            [ 4]  851 	sub	a, b
   4490 30 E4         [12]  852 	jr	NC,00102$
   4492 C9            [10]  853 	ret
   4493                     854 ___str_8:
   4493 20 20 20 20 20 20   855 	.ascii "                                        "
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20
   44BB 00                  856 	.db 0x00
                            857 ;src/main.c:148: u8 CalculateDamage (struct TCharacter *c)
                            858 ;	---------------------------------
                            859 ; Function CalculateDamage
                            860 ; ---------------------------------
   44BC                     861 _CalculateDamage::
   44BC DD E5         [15]  862 	push	ix
   44BE DD 21 00 00   [14]  863 	ld	ix,#0
   44C2 DD 39         [15]  864 	add	ix,sp
                            865 ;src/main.c:150: return (c->_atk*c->_atk)/(5*c->_defense);
   44C4 DD 4E 04      [19]  866 	ld	c,4 (ix)
   44C7 DD 46 05      [19]  867 	ld	b,5 (ix)
   44CA 69            [ 4]  868 	ld	l, c
   44CB 60            [ 4]  869 	ld	h, b
   44CC 11 05 00      [10]  870 	ld	de, #0x0005
   44CF 19            [11]  871 	add	hl, de
   44D0 5E            [ 7]  872 	ld	e, (hl)
   44D1 23            [ 6]  873 	inc	hl
   44D2 56            [ 7]  874 	ld	d, (hl)
   44D3 C5            [11]  875 	push	bc
   44D4 D5            [11]  876 	push	de
   44D5 D5            [11]  877 	push	de
   44D6 CD 9F 4A      [17]  878 	call	__mulint
   44D9 F1            [10]  879 	pop	af
   44DA F1            [10]  880 	pop	af
   44DB EB            [ 4]  881 	ex	de,hl
   44DC E1            [10]  882 	pop	hl
   44DD 01 07 00      [10]  883 	ld	bc, #0x0007
   44E0 09            [11]  884 	add	hl, bc
   44E1 4E            [ 7]  885 	ld	c, (hl)
   44E2 23            [ 6]  886 	inc	hl
   44E3 46            [ 7]  887 	ld	b, (hl)
   44E4 69            [ 4]  888 	ld	l, c
   44E5 60            [ 4]  889 	ld	h, b
   44E6 29            [11]  890 	add	hl, hl
   44E7 29            [11]  891 	add	hl, hl
   44E8 09            [11]  892 	add	hl, bc
   44E9 E5            [11]  893 	push	hl
   44EA D5            [11]  894 	push	de
   44EB CD 3A 4A      [17]  895 	call	__divuint
   44EE F1            [10]  896 	pop	af
   44EF F1            [10]  897 	pop	af
   44F0 DD E1         [14]  898 	pop	ix
   44F2 C9            [10]  899 	ret
                            900 ;src/main.c:155: void TakeDamage (struct TCharacter *c, u8 dmg)
                            901 ;	---------------------------------
                            902 ; Function TakeDamage
                            903 ; ---------------------------------
   44F3                     904 _TakeDamage::
   44F3 DD E5         [15]  905 	push	ix
   44F5 DD 21 00 00   [14]  906 	ld	ix,#0
   44F9 DD 39         [15]  907 	add	ix,sp
                            908 ;src/main.c:157: c->_hp -= dmg;
   44FB DD 6E 04      [19]  909 	ld	l,4 (ix)
   44FE DD 66 05      [19]  910 	ld	h,5 (ix)
   4501 E5            [11]  911 	push	hl
   4502 4E            [ 7]  912 	ld	c, (hl)
   4503 23            [ 6]  913 	inc	hl
   4504 46            [ 7]  914 	ld	b, (hl)
   4505 E1            [10]  915 	pop	hl
   4506 DD 5E 06      [19]  916 	ld	e, 6 (ix)
   4509 16 00         [ 7]  917 	ld	d, #0x00
   450B 79            [ 4]  918 	ld	a, c
   450C 93            [ 4]  919 	sub	a, e
   450D 4F            [ 4]  920 	ld	c, a
   450E 78            [ 4]  921 	ld	a, b
   450F 9A            [ 4]  922 	sbc	a, d
   4510 47            [ 4]  923 	ld	b, a
   4511 71            [ 7]  924 	ld	(hl), c
   4512 23            [ 6]  925 	inc	hl
   4513 70            [ 7]  926 	ld	(hl), b
   4514 DD E1         [14]  927 	pop	ix
   4516 C9            [10]  928 	ret
                            929 ;src/main.c:162: void main(void) {
                            930 ;	---------------------------------
                            931 ; Function main
                            932 ; ---------------------------------
   4517                     933 _main::
   4517 DD E5         [15]  934 	push	ix
   4519 DD 21 00 00   [14]  935 	ld	ix,#0
   451D DD 39         [15]  936 	add	ix,sp
   451F 21 C8 FF      [10]  937 	ld	hl, #-56
   4522 39            [11]  938 	add	hl, sp
   4523 F9            [ 6]  939 	ld	sp, hl
                            940 ;src/main.c:170: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
   4524 21 00 00      [10]  941 	ld	hl, #0x0000
   4527 E5            [11]  942 	push	hl
   4528 AF            [ 4]  943 	xor	a, a
   4529 F5            [11]  944 	push	af
   452A 33            [ 6]  945 	inc	sp
   452B CD 21 40      [17]  946 	call	_ink
   452E 33            [ 6]  947 	inc	sp
   452F 21 00 00      [10]  948 	ld	hl,#0x0000
   4532 E3            [19]  949 	ex	(sp),hl
   4533 3E 01         [ 7]  950 	ld	a, #0x01
   4535 F5            [11]  951 	push	af
   4536 33            [ 6]  952 	inc	sp
   4537 CD 21 40      [17]  953 	call	_ink
   453A 33            [ 6]  954 	inc	sp
   453B 21 00 00      [10]  955 	ld	hl,#0x0000
   453E E3            [19]  956 	ex	(sp),hl
   453F 3E 02         [ 7]  957 	ld	a, #0x02
   4541 F5            [11]  958 	push	af
   4542 33            [ 6]  959 	inc	sp
   4543 CD 21 40      [17]  960 	call	_ink
   4546 F1            [10]  961 	pop	af
   4547 33            [ 6]  962 	inc	sp
                            963 ;src/main.c:171: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
   4548 2E 01         [ 7]  964 	ld	l, #0x01
   454A CD 43 4B      [17]  965 	call	_cpct_setVideoMode
                            966 ;src/main.c:172: border (1,1); paper (0); pen (1);
   454D 21 01 01      [10]  967 	ld	hl, #0x0101
   4550 E5            [11]  968 	push	hl
   4551 CD 4E 40      [17]  969 	call	_border
   4554 F1            [10]  970 	pop	af
   4555 AF            [ 4]  971 	xor	a, a
   4556 F5            [11]  972 	push	af
   4557 33            [ 6]  973 	inc	sp
   4558 CD 6F 40      [17]  974 	call	_paper
   455B 33            [ 6]  975 	inc	sp
   455C 3E 01         [ 7]  976 	ld	a, #0x01
   455E F5            [11]  977 	push	af
   455F 33            [ 6]  978 	inc	sp
   4560 CD 84 40      [17]  979 	call	_pen
   4563 33            [ 6]  980 	inc	sp
                            981 ;src/main.c:174: PrintAt (1,5, "      )   ___    _____    )   ___      ", 0xff);
   4564 3E FF         [ 7]  982 	ld	a, #0xff
   4566 F5            [11]  983 	push	af
   4567 33            [ 6]  984 	inc	sp
   4568 21 17 48      [10]  985 	ld	hl, #___str_9
   456B E5            [11]  986 	push	hl
   456C 21 01 05      [10]  987 	ld	hl, #0x0501
   456F E5            [11]  988 	push	hl
   4570 CD A2 40      [17]  989 	call	_PrintAt
   4573 F1            [10]  990 	pop	af
   4574 F1            [10]  991 	pop	af
   4575 33            [ 6]  992 	inc	sp
                            993 ;src/main.c:175: PrintAt (1,6, "     (__/_____) (, /   ) (__/_____)    ", 0xff);
   4576 3E FF         [ 7]  994 	ld	a, #0xff
   4578 F5            [11]  995 	push	af
   4579 33            [ 6]  996 	inc	sp
   457A 21 3F 48      [10]  997 	ld	hl, #___str_10
   457D E5            [11]  998 	push	hl
   457E 21 01 06      [10]  999 	ld	hl, #0x0601
   4581 E5            [11] 1000 	push	hl
   4582 CD A2 40      [17] 1001 	call	_PrintAt
   4585 F1            [10] 1002 	pop	af
   4586 F1            [10] 1003 	pop	af
   4587 33            [ 6] 1004 	inc	sp
                           1005 ;src/main.c:176: PrintAt (1,7, "       /         _/__ /    /           ", 0xff);
   4588 3E FF         [ 7] 1006 	ld	a, #0xff
   458A F5            [11] 1007 	push	af
   458B 33            [ 6] 1008 	inc	sp
   458C 21 67 48      [10] 1009 	ld	hl, #___str_11
   458F E5            [11] 1010 	push	hl
   4590 21 01 07      [10] 1011 	ld	hl, #0x0701
   4593 E5            [11] 1012 	push	hl
   4594 CD A2 40      [17] 1013 	call	_PrintAt
   4597 F1            [10] 1014 	pop	af
   4598 F1            [10] 1015 	pop	af
   4599 33            [ 6] 1016 	inc	sp
                           1017 ;src/main.c:177: PrintAt (1,8, "      /          /        /            ", 0xff);
   459A 3E FF         [ 7] 1018 	ld	a, #0xff
   459C F5            [11] 1019 	push	af
   459D 33            [ 6] 1020 	inc	sp
   459E 21 8F 48      [10] 1021 	ld	hl, #___str_12
   45A1 E5            [11] 1022 	push	hl
   45A2 21 01 08      [10] 1023 	ld	hl, #0x0801
   45A5 E5            [11] 1024 	push	hl
   45A6 CD A2 40      [17] 1025 	call	_PrintAt
   45A9 F1            [10] 1026 	pop	af
   45AA F1            [10] 1027 	pop	af
   45AB 33            [ 6] 1028 	inc	sp
                           1029 ;src/main.c:178: PrintAt (1,9, "     (______) ) /        (______)      ", 0xff);
   45AC 3E FF         [ 7] 1030 	ld	a, #0xff
   45AE F5            [11] 1031 	push	af
   45AF 33            [ 6] 1032 	inc	sp
   45B0 21 B7 48      [10] 1033 	ld	hl, #___str_13
   45B3 E5            [11] 1034 	push	hl
   45B4 21 01 09      [10] 1035 	ld	hl, #0x0901
   45B7 E5            [11] 1036 	push	hl
   45B8 CD A2 40      [17] 1037 	call	_PrintAt
   45BB F1            [10] 1038 	pop	af
   45BC F1            [10] 1039 	pop	af
   45BD 33            [ 6] 1040 	inc	sp
                           1041 ;src/main.c:179: PrintAt (1,10, "            _(_/_                      ", 0xff);
   45BE 3E FF         [ 7] 1042 	ld	a, #0xff
   45C0 F5            [11] 1043 	push	af
   45C1 33            [ 6] 1044 	inc	sp
   45C2 21 DF 48      [10] 1045 	ld	hl, #___str_14
   45C5 E5            [11] 1046 	push	hl
   45C6 21 01 0A      [10] 1047 	ld	hl, #0x0a01
   45C9 E5            [11] 1048 	push	hl
   45CA CD A2 40      [17] 1049 	call	_PrintAt
   45CD F1            [10] 1050 	pop	af
   45CE F1            [10] 1051 	pop	af
   45CF 33            [ 6] 1052 	inc	sp
                           1053 ;src/main.c:180: PrintAt (1,11, "           (, /   )                    ", 0xff);
   45D0 3E FF         [ 7] 1054 	ld	a, #0xff
   45D2 F5            [11] 1055 	push	af
   45D3 33            [ 6] 1056 	inc	sp
   45D4 21 07 49      [10] 1057 	ld	hl, #___str_15
   45D7 E5            [11] 1058 	push	hl
   45D8 21 01 0B      [10] 1059 	ld	hl, #0x0b01
   45DB E5            [11] 1060 	push	hl
   45DC CD A2 40      [17] 1061 	call	_PrintAt
   45DF F1            [10] 1062 	pop	af
   45E0 F1            [10] 1063 	pop	af
   45E1 33            [ 6] 1064 	inc	sp
                           1065 ;src/main.c:181: PrintAt (1,12, "             /__ / ___      _          ", 0xff);
   45E2 3E FF         [ 7] 1066 	ld	a, #0xff
   45E4 F5            [11] 1067 	push	af
   45E5 33            [ 6] 1068 	inc	sp
   45E6 21 2F 49      [10] 1069 	ld	hl, #___str_16
   45E9 E5            [11] 1070 	push	hl
   45EA 21 01 0C      [10] 1071 	ld	hl, #0x0c01
   45ED E5            [11] 1072 	push	hl
   45EE CD A2 40      [17] 1073 	call	_PrintAt
   45F1 F1            [10] 1074 	pop	af
   45F2 F1            [10] 1075 	pop	af
   45F3 33            [ 6] 1076 	inc	sp
                           1077 ;src/main.c:184: PrintAt (1,13, "          ) /   \\_(_(_/(_(_(/_         ", 0xff);
   45F4 3E FF         [ 7] 1078 	ld	a, #0xff
   45F6 F5            [11] 1079 	push	af
   45F7 33            [ 6] 1080 	inc	sp
   45F8 21 57 49      [10] 1081 	ld	hl, #___str_17
   45FB E5            [11] 1082 	push	hl
   45FC 21 01 0D      [10] 1083 	ld	hl, #0x0d01
   45FF E5            [11] 1084 	push	hl
   4600 CD A2 40      [17] 1085 	call	_PrintAt
   4603 F1            [10] 1086 	pop	af
   4604 F1            [10] 1087 	pop	af
   4605 33            [ 6] 1088 	inc	sp
                           1089 ;src/main.c:185: PrintAt (1,14, "         (_/       .-/                 ", 0xff);
   4606 3E FF         [ 7] 1090 	ld	a, #0xff
   4608 F5            [11] 1091 	push	af
   4609 33            [ 6] 1092 	inc	sp
   460A 21 7F 49      [10] 1093 	ld	hl, #___str_18
   460D E5            [11] 1094 	push	hl
   460E 21 01 0E      [10] 1095 	ld	hl, #0x0e01
   4611 E5            [11] 1096 	push	hl
   4612 CD A2 40      [17] 1097 	call	_PrintAt
   4615 F1            [10] 1098 	pop	af
   4616 F1            [10] 1099 	pop	af
   4617 33            [ 6] 1100 	inc	sp
                           1101 ;src/main.c:186: PrintAt (1,15, "                  (_/                  ", 0xff);
   4618 3E FF         [ 7] 1102 	ld	a, #0xff
   461A F5            [11] 1103 	push	af
   461B 33            [ 6] 1104 	inc	sp
   461C 21 A7 49      [10] 1105 	ld	hl, #___str_19
   461F E5            [11] 1106 	push	hl
   4620 21 01 0F      [10] 1107 	ld	hl, #0x0f01
   4623 E5            [11] 1108 	push	hl
   4624 CD A2 40      [17] 1109 	call	_PrintAt
   4627 F1            [10] 1110 	pop	af
   4628 F1            [10] 1111 	pop	af
   4629 33            [ 6] 1112 	inc	sp
                           1113 ;src/main.c:187: PrintAt (10, 18, "PRESS ENTER TO START", 2);
   462A 3E 02         [ 7] 1114 	ld	a, #0x02
   462C F5            [11] 1115 	push	af
   462D 33            [ 6] 1116 	inc	sp
   462E 21 CF 49      [10] 1117 	ld	hl, #___str_20
   4631 E5            [11] 1118 	push	hl
   4632 21 0A 12      [10] 1119 	ld	hl, #0x120a
   4635 E5            [11] 1120 	push	hl
   4636 CD A2 40      [17] 1121 	call	_PrintAt
   4639 F1            [10] 1122 	pop	af
                           1123 ;src/main.c:188: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);
   463A 33            [ 6] 1124 	inc	sp
   463B 21 03 03      [10] 1125 	ld	hl,#0x0303
   463E E3            [19] 1126 	ex	(sp),hl
   463F AF            [ 4] 1127 	xor	a, a
   4640 F5            [11] 1128 	push	af
   4641 33            [ 6] 1129 	inc	sp
   4642 CD 21 40      [17] 1130 	call	_ink
   4645 33            [ 6] 1131 	inc	sp
   4646 21 06 0F      [10] 1132 	ld	hl,#0x0f06
   4649 E3            [19] 1133 	ex	(sp),hl
   464A 3E 01         [ 7] 1134 	ld	a, #0x01
   464C F5            [11] 1135 	push	af
   464D 33            [ 6] 1136 	inc	sp
   464E CD 21 40      [17] 1137 	call	_ink
   4651 33            [ 6] 1138 	inc	sp
   4652 21 10 10      [10] 1139 	ld	hl,#0x1010
   4655 E3            [19] 1140 	ex	(sp),hl
   4656 3E 02         [ 7] 1141 	ld	a, #0x02
   4658 F5            [11] 1142 	push	af
   4659 33            [ 6] 1143 	inc	sp
   465A CD 21 40      [17] 1144 	call	_ink
   465D 33            [ 6] 1145 	inc	sp
   465E 21 03 03      [10] 1146 	ld	hl,#0x0303
   4661 E3            [19] 1147 	ex	(sp),hl
   4662 CD 4E 40      [17] 1148 	call	_border
   4665 F1            [10] 1149 	pop	af
                           1150 ;src/main.c:191: while (!cpct_isKeyPressed (Key_Return)) {
   4666                    1151 00101$:
   4666 21 02 04      [10] 1152 	ld	hl, #0x0402
   4669 CD 7B 4A      [17] 1153 	call	_cpct_isKeyPressed
   466C 7D            [ 4] 1154 	ld	a, l
   466D B7            [ 4] 1155 	or	a, a
   466E 20 05         [12] 1156 	jr	NZ,00103$
                           1157 ;src/main.c:192: cpct_scanKeyboard ();
   4670 CD C1 4B      [17] 1158 	call	_cpct_scanKeyboard
   4673 18 F1         [12] 1159 	jr	00101$
   4675                    1160 00103$:
                           1161 ;src/main.c:196: border (0,0); ink (0, 0,0); ink (1, 25,25); ink (2, 20,20);
   4675 21 00 00      [10] 1162 	ld	hl, #0x0000
   4678 E5            [11] 1163 	push	hl
   4679 CD 4E 40      [17] 1164 	call	_border
   467C 21 00 00      [10] 1165 	ld	hl, #0x0000
   467F E3            [19] 1166 	ex	(sp),hl
   4680 AF            [ 4] 1167 	xor	a, a
   4681 F5            [11] 1168 	push	af
   4682 33            [ 6] 1169 	inc	sp
   4683 CD 21 40      [17] 1170 	call	_ink
   4686 33            [ 6] 1171 	inc	sp
   4687 21 19 19      [10] 1172 	ld	hl,#0x1919
   468A E3            [19] 1173 	ex	(sp),hl
   468B 3E 01         [ 7] 1174 	ld	a, #0x01
   468D F5            [11] 1175 	push	af
   468E 33            [ 6] 1176 	inc	sp
   468F CD 21 40      [17] 1177 	call	_ink
   4692 33            [ 6] 1178 	inc	sp
   4693 21 14 14      [10] 1179 	ld	hl,#0x1414
   4696 E3            [19] 1180 	ex	(sp),hl
   4697 3E 02         [ 7] 1181 	ld	a, #0x02
   4699 F5            [11] 1182 	push	af
   469A 33            [ 6] 1183 	inc	sp
   469B CD 21 40      [17] 1184 	call	_ink
   469E F1            [10] 1185 	pop	af
   469F 33            [ 6] 1186 	inc	sp
                           1187 ;src/main.c:197: paper (0); pen (2); cls ();
   46A0 AF            [ 4] 1188 	xor	a, a
   46A1 F5            [11] 1189 	push	af
   46A2 33            [ 6] 1190 	inc	sp
   46A3 CD 6F 40      [17] 1191 	call	_paper
   46A6 33            [ 6] 1192 	inc	sp
   46A7 3E 02         [ 7] 1193 	ld	a, #0x02
   46A9 F5            [11] 1194 	push	af
   46AA 33            [ 6] 1195 	inc	sp
   46AB CD 84 40      [17] 1196 	call	_pen
   46AE 33            [ 6] 1197 	inc	sp
   46AF CD 99 40      [17] 1198 	call	_cls
                           1199 ;src/main.c:200: InitializeCharacter (&player, 150, 17, 14, 12, '@', "Player");
   46B2 11 E4 49      [10] 1200 	ld	de, #___str_21+0
   46B5 21 1A 00      [10] 1201 	ld	hl, #0x001a
   46B8 39            [11] 1202 	add	hl, sp
   46B9 DD 75 FE      [19] 1203 	ld	-2 (ix), l
   46BC DD 74 FF      [19] 1204 	ld	-1 (ix), h
   46BF 4D            [ 4] 1205 	ld	c, l
   46C0 44            [ 4] 1206 	ld	b, h
   46C1 D5            [11] 1207 	push	de
   46C2 21 0C 40      [10] 1208 	ld	hl, #0x400c
   46C5 E5            [11] 1209 	push	hl
   46C6 21 11 0E      [10] 1210 	ld	hl, #0x0e11
   46C9 E5            [11] 1211 	push	hl
   46CA 21 96 00      [10] 1212 	ld	hl, #0x0096
   46CD E5            [11] 1213 	push	hl
   46CE C5            [11] 1214 	push	bc
   46CF CD D6 40      [17] 1215 	call	_InitializeCharacter
   46D2 21 0A 00      [10] 1216 	ld	hl, #10
   46D5 39            [11] 1217 	add	hl, sp
   46D6 F9            [ 6] 1218 	ld	sp, hl
                           1219 ;src/main.c:201: InitializeCharacter (&goblin, 100, 12, 13, 11, 'g', "Goblin");
   46D7 11 EB 49      [10] 1220 	ld	de, #___str_22+0
   46DA 21 00 00      [10] 1221 	ld	hl, #0x0000
   46DD 39            [11] 1222 	add	hl, sp
   46DE DD 75 FC      [19] 1223 	ld	-4 (ix), l
   46E1 DD 74 FD      [19] 1224 	ld	-3 (ix), h
   46E4 4D            [ 4] 1225 	ld	c, l
   46E5 44            [ 4] 1226 	ld	b, h
   46E6 D5            [11] 1227 	push	de
   46E7 21 0B 67      [10] 1228 	ld	hl, #0x670b
   46EA E5            [11] 1229 	push	hl
   46EB 21 0C 0D      [10] 1230 	ld	hl, #0x0d0c
   46EE E5            [11] 1231 	push	hl
   46EF 21 64 00      [10] 1232 	ld	hl, #0x0064
   46F2 E5            [11] 1233 	push	hl
   46F3 C5            [11] 1234 	push	bc
   46F4 CD D6 40      [17] 1235 	call	_InitializeCharacter
   46F7 21 0A 00      [10] 1236 	ld	hl, #10
   46FA 39            [11] 1237 	add	hl, sp
   46FB F9            [ 6] 1238 	ld	sp, hl
                           1239 ;src/main.c:204: do {
   46FC                    1240 00111$:
                           1241 ;src/main.c:205: locate (1,1);
   46FC 21 01 01      [10] 1242 	ld	hl, #0x0101
   46FF E5            [11] 1243 	push	hl
   4700 CD 00 40      [17] 1244 	call	_locate
   4703 F1            [10] 1245 	pop	af
                           1246 ;src/main.c:207: PrintCharacterStats (&player, 1, 1,2);
   4704 DD 4E FE      [19] 1247 	ld	c,-2 (ix)
   4707 DD 46 FF      [19] 1248 	ld	b,-1 (ix)
   470A 21 01 02      [10] 1249 	ld	hl, #0x0201
   470D E5            [11] 1250 	push	hl
   470E 3E 01         [ 7] 1251 	ld	a, #0x01
   4710 F5            [11] 1252 	push	af
   4711 33            [ 6] 1253 	inc	sp
   4712 C5            [11] 1254 	push	bc
   4713 CD F8 41      [17] 1255 	call	_PrintCharacterStats
   4716 F1            [10] 1256 	pop	af
   4717 F1            [10] 1257 	pop	af
   4718 33            [ 6] 1258 	inc	sp
                           1259 ;src/main.c:208: PrintCharacterStats (&goblin, 5, 1,2);
   4719 DD 4E FC      [19] 1260 	ld	c,-4 (ix)
   471C DD 46 FD      [19] 1261 	ld	b,-3 (ix)
   471F 21 01 02      [10] 1262 	ld	hl, #0x0201
   4722 E5            [11] 1263 	push	hl
   4723 3E 05         [ 7] 1264 	ld	a, #0x05
   4725 F5            [11] 1265 	push	af
   4726 33            [ 6] 1266 	inc	sp
   4727 C5            [11] 1267 	push	bc
   4728 CD F8 41      [17] 1268 	call	_PrintCharacterStats
   472B F1            [10] 1269 	pop	af
   472C F1            [10] 1270 	pop	af
   472D 33            [ 6] 1271 	inc	sp
                           1272 ;src/main.c:211: PrintAt (1,20, "ACTION? ", 1);
   472E 3E 01         [ 7] 1273 	ld	a, #0x01
   4730 F5            [11] 1274 	push	af
   4731 33            [ 6] 1275 	inc	sp
   4732 21 F2 49      [10] 1276 	ld	hl, #___str_23
   4735 E5            [11] 1277 	push	hl
   4736 21 01 14      [10] 1278 	ld	hl, #0x1401
   4739 E5            [11] 1279 	push	hl
   473A CD A2 40      [17] 1280 	call	_PrintAt
   473D F1            [10] 1281 	pop	af
   473E F1            [10] 1282 	pop	af
   473F 33            [ 6] 1283 	inc	sp
                           1284 ;src/main.c:213: cpct_scanKeyboard();
   4740 CD C1 4B      [17] 1285 	call	_cpct_scanKeyboard
                           1286 ;src/main.c:214: while (!cpct_isKeyPressed (Key_A)) {
   4743                    1287 00104$:
   4743 21 08 20      [10] 1288 	ld	hl, #0x2008
   4746 CD 7B 4A      [17] 1289 	call	_cpct_isKeyPressed
   4749 7D            [ 4] 1290 	ld	a, l
   474A B7            [ 4] 1291 	or	a, a
   474B 20 05         [12] 1292 	jr	NZ,00106$
                           1293 ;src/main.c:215: cpct_scanKeyboard();
   474D CD C1 4B      [17] 1294 	call	_cpct_scanKeyboard
   4750 18 F1         [12] 1295 	jr	00104$
   4752                    1296 00106$:
                           1297 ;src/main.c:218: ClearStatusLine();
   4752 CD 74 44      [17] 1298 	call	_ClearStatusLine
                           1299 ;src/main.c:220: if (cpct_isKeyPressed (Key_A)) {
   4755 21 08 20      [10] 1300 	ld	hl, #0x2008
   4758 CD 7B 4A      [17] 1301 	call	_cpct_isKeyPressed
   475B 7D            [ 4] 1302 	ld	a, l
   475C B7            [ 4] 1303 	or	a, a
   475D 28 57         [12] 1304 	jr	Z,00108$
                           1305 ;src/main.c:221: dmg=CalculateDamage (&player);
   475F DD 4E FE      [19] 1306 	ld	c,-2 (ix)
   4762 DD 46 FF      [19] 1307 	ld	b,-1 (ix)
   4765 C5            [11] 1308 	push	bc
   4766 CD BC 44      [17] 1309 	call	_CalculateDamage
   4769 F1            [10] 1310 	pop	af
   476A 45            [ 4] 1311 	ld	b, l
                           1312 ;src/main.c:222: TakeDamage (&goblin, dmg);
   476B DD 5E FC      [19] 1313 	ld	e,-4 (ix)
   476E DD 56 FD      [19] 1314 	ld	d,-3 (ix)
   4771 C5            [11] 1315 	push	bc
   4772 C5            [11] 1316 	push	bc
   4773 33            [ 6] 1317 	inc	sp
   4774 D5            [11] 1318 	push	de
   4775 CD F3 44      [17] 1319 	call	_TakeDamage
   4778 33            [ 6] 1320 	inc	sp
   4779 21 01 15      [10] 1321 	ld	hl,#0x1501
   477C E3            [19] 1322 	ex	(sp),hl
   477D CD 00 40      [17] 1323 	call	_locate
   4780 26 01         [ 7] 1324 	ld	h,#0x01
   4782 E3            [19] 1325 	ex	(sp),hl
   4783 33            [ 6] 1326 	inc	sp
   4784 CD 84 40      [17] 1327 	call	_pen
   4787 33            [ 6] 1328 	inc	sp
   4788 C1            [10] 1329 	pop	bc
   4789 11 FB 49      [10] 1330 	ld	de, #___str_24
   478C C5            [11] 1331 	push	bc
   478D D5            [11] 1332 	push	de
   478E CD 7E 4B      [17] 1333 	call	_printf
   4791 26 03         [ 7] 1334 	ld	h,#0x03
   4793 E3            [19] 1335 	ex	(sp),hl
   4794 33            [ 6] 1336 	inc	sp
   4795 CD 84 40      [17] 1337 	call	_pen
   4798 33            [ 6] 1338 	inc	sp
   4799 C1            [10] 1339 	pop	bc
   479A 48            [ 4] 1340 	ld	c, b
   479B 06 00         [ 7] 1341 	ld	b, #0x00
   479D C5            [11] 1342 	push	bc
   479E 21 09 4A      [10] 1343 	ld	hl, #___str_25
   47A1 E5            [11] 1344 	push	hl
   47A2 CD 7E 4B      [17] 1345 	call	_printf
   47A5 F1            [10] 1346 	pop	af
                           1347 ;src/main.c:225: pen (1); printf (" hit points");
   47A6 26 01         [ 7] 1348 	ld	h,#0x01
   47A8 E3            [19] 1349 	ex	(sp),hl
   47A9 33            [ 6] 1350 	inc	sp
   47AA CD 84 40      [17] 1351 	call	_pen
   47AD 33            [ 6] 1352 	inc	sp
   47AE 21 0C 4A      [10] 1353 	ld	hl, #___str_26
   47B1 E5            [11] 1354 	push	hl
   47B2 CD 7E 4B      [17] 1355 	call	_printf
   47B5 F1            [10] 1356 	pop	af
   47B6                    1357 00108$:
                           1358 ;src/main.c:228: if (cpct_rand() < 64) {
   47B6 CD 9B 4B      [17] 1359 	call	_cpct_getRandom_mxor_u8
   47B9 7D            [ 4] 1360 	ld	a, l
   47BA D6 40         [ 7] 1361 	sub	a, #0x40
   47BC D2 FC 46      [10] 1362 	jp	NC, 00111$
                           1363 ;src/main.c:229: dmg=CalculateDamage (&goblin);
   47BF DD 4E FC      [19] 1364 	ld	c,-4 (ix)
   47C2 DD 46 FD      [19] 1365 	ld	b,-3 (ix)
   47C5 C5            [11] 1366 	push	bc
   47C6 CD BC 44      [17] 1367 	call	_CalculateDamage
   47C9 F1            [10] 1368 	pop	af
   47CA 45            [ 4] 1369 	ld	b, l
                           1370 ;src/main.c:230: TakeDamage (&player, dmg);
   47CB DD 5E FE      [19] 1371 	ld	e,-2 (ix)
   47CE DD 56 FF      [19] 1372 	ld	d,-1 (ix)
   47D1 C5            [11] 1373 	push	bc
   47D2 C5            [11] 1374 	push	bc
   47D3 33            [ 6] 1375 	inc	sp
   47D4 D5            [11] 1376 	push	de
   47D5 CD F3 44      [17] 1377 	call	_TakeDamage
   47D8 33            [ 6] 1378 	inc	sp
   47D9 21 01 16      [10] 1379 	ld	hl,#0x1601
   47DC E3            [19] 1380 	ex	(sp),hl
   47DD CD 00 40      [17] 1381 	call	_locate
   47E0 26 01         [ 7] 1382 	ld	h,#0x01
   47E2 E3            [19] 1383 	ex	(sp),hl
   47E3 33            [ 6] 1384 	inc	sp
   47E4 CD 84 40      [17] 1385 	call	_pen
   47E7 33            [ 6] 1386 	inc	sp
   47E8 21 18 4A      [10] 1387 	ld	hl, #___str_27
   47EB E5            [11] 1388 	push	hl
   47EC CD 7E 4B      [17] 1389 	call	_printf
   47EF 26 03         [ 7] 1390 	ld	h,#0x03
   47F1 E3            [19] 1391 	ex	(sp),hl
   47F2 33            [ 6] 1392 	inc	sp
   47F3 CD 84 40      [17] 1393 	call	_pen
   47F6 33            [ 6] 1394 	inc	sp
   47F7 C1            [10] 1395 	pop	bc
   47F8 48            [ 4] 1396 	ld	c, b
   47F9 06 00         [ 7] 1397 	ld	b, #0x00
   47FB C5            [11] 1398 	push	bc
   47FC 21 09 4A      [10] 1399 	ld	hl, #___str_25
   47FF E5            [11] 1400 	push	hl
   4800 CD 7E 4B      [17] 1401 	call	_printf
   4803 F1            [10] 1402 	pop	af
                           1403 ;src/main.c:233: pen (1); printf (" hit points from goblin");
   4804 26 01         [ 7] 1404 	ld	h,#0x01
   4806 E3            [19] 1405 	ex	(sp),hl
   4807 33            [ 6] 1406 	inc	sp
   4808 CD 84 40      [17] 1407 	call	_pen
   480B 33            [ 6] 1408 	inc	sp
   480C 21 22 4A      [10] 1409 	ld	hl, #___str_28
   480F E5            [11] 1410 	push	hl
   4810 CD 7E 4B      [17] 1411 	call	_printf
   4813 F1            [10] 1412 	pop	af
                           1413 ;src/main.c:235: } while (1);
   4814 C3 FC 46      [10] 1414 	jp	00111$
   4817                    1415 ___str_9:
   4817 20 20 20 20 20 20  1416 	.ascii "      )   ___    _____    )   ___      "
        29 20 20 20 5F 5F
        5F 20 20 20 20 5F
        5F 5F 5F 5F 20 20
        20 20 29 20 20 20
        5F 5F 5F 20 20 20
        20 20 20
   483E 00                 1417 	.db 0x00
   483F                    1418 ___str_10:
   483F 20 20 20 20 20 28  1419 	.ascii "     (__/_____) (, /   ) (__/_____)    "
        5F 5F 2F 5F 5F 5F
        5F 5F 29 20 28 2C
        20 2F 20 20 20 29
        20 28 5F 5F 2F 5F
        5F 5F 5F 5F 29 20
        20 20 20
   4866 00                 1420 	.db 0x00
   4867                    1421 ___str_11:
   4867 20 20 20 20 20 20  1422 	.ascii "       /         _/__ /    /           "
        20 2F 20 20 20 20
        20 20 20 20 20 5F
        2F 5F 5F 20 2F 20
        20 20 20 2F 20 20
        20 20 20 20 20 20
        20 20 20
   488E 00                 1423 	.db 0x00
   488F                    1424 ___str_12:
   488F 20 20 20 20 20 20  1425 	.ascii "      /          /        /            "
        2F 20 20 20 20 20
        20 20 20 20 20 2F
        20 20 20 20 20 20
        20 20 2F 20 20 20
        20 20 20 20 20 20
        20 20 20
   48B6 00                 1426 	.db 0x00
   48B7                    1427 ___str_13:
   48B7 20 20 20 20 20 28  1428 	.ascii "     (______) ) /        (______)      "
        5F 5F 5F 5F 5F 5F
        29 20 29 20 2F 20
        20 20 20 20 20 20
        20 28 5F 5F 5F 5F
        5F 5F 29 20 20 20
        20 20 20
   48DE 00                 1429 	.db 0x00
   48DF                    1430 ___str_14:
   48DF 20 20 20 20 20 20  1431 	.ascii "            _(_/_                      "
        20 20 20 20 20 20
        5F 28 5F 2F 5F 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   4906 00                 1432 	.db 0x00
   4907                    1433 ___str_15:
   4907 20 20 20 20 20 20  1434 	.ascii "           (, /   )                    "
        20 20 20 20 20 28
        2C 20 2F 20 20 20
        29 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   492E 00                 1435 	.db 0x00
   492F                    1436 ___str_16:
   492F 20 20 20 20 20 20  1437 	.ascii "             /__ / ___      _          "
        20 20 20 20 20 20
        20 2F 5F 5F 20 2F
        20 5F 5F 5F 20 20
        20 20 20 20 5F 20
        20 20 20 20 20 20
        20 20 20
   4956 00                 1438 	.db 0x00
   4957                    1439 ___str_17:
   4957 20 20 20 20 20 20  1440 	.ascii "          ) /   "
        20 20 20 20 29 20
        2F 20 20 20
   4967 5C                 1441 	.db 0x5c
   4968 5F 28 5F 28 5F 2F  1442 	.ascii "_(_(_/(_(_(/_         "
        28 5F 28 5F 28 2F
        5F 20 20 20 20 20
        20 20 20 20
   497E 00                 1443 	.db 0x00
   497F                    1444 ___str_18:
   497F 20 20 20 20 20 20  1445 	.ascii "         (_/       .-/                 "
        20 20 20 28 5F 2F
        20 20 20 20 20 20
        20 2E 2D 2F 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   49A6 00                 1446 	.db 0x00
   49A7                    1447 ___str_19:
   49A7 20 20 20 20 20 20  1448 	.ascii "                  (_/                  "
        20 20 20 20 20 20
        20 20 20 20 20 20
        28 5F 2F 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   49CE 00                 1449 	.db 0x00
   49CF                    1450 ___str_20:
   49CF 50 52 45 53 53 20  1451 	.ascii "PRESS ENTER TO START"
        45 4E 54 45 52 20
        54 4F 20 53 54 41
        52 54
   49E3 00                 1452 	.db 0x00
   49E4                    1453 ___str_21:
   49E4 50 6C 61 79 65 72  1454 	.ascii "Player"
   49EA 00                 1455 	.db 0x00
   49EB                    1456 ___str_22:
   49EB 47 6F 62 6C 69 6E  1457 	.ascii "Goblin"
   49F1 00                 1458 	.db 0x00
   49F2                    1459 ___str_23:
   49F2 41 43 54 49 4F 4E  1460 	.ascii "ACTION? "
        3F 20
   49FA 00                 1461 	.db 0x00
   49FB                    1462 ___str_24:
   49FB 67 6F 62 6C 69 6E  1463 	.ascii "goblin takes "
        20 74 61 6B 65 73
        20
   4A08 00                 1464 	.db 0x00
   4A09                    1465 ___str_25:
   4A09 25 64              1466 	.ascii "%d"
   4A0B 00                 1467 	.db 0x00
   4A0C                    1468 ___str_26:
   4A0C 20 68 69 74 20 70  1469 	.ascii " hit points"
        6F 69 6E 74 73
   4A17 00                 1470 	.db 0x00
   4A18                    1471 ___str_27:
   4A18 79 6F 75 20 74 61  1472 	.ascii "you take "
        6B 65 20
   4A21 00                 1473 	.db 0x00
   4A22                    1474 ___str_28:
   4A22 20 68 69 74 20 70  1475 	.ascii " hit points from goblin"
        6F 69 6E 74 73 20
        66 72 6F 6D 20 67
        6F 62 6C 69 6E
   4A39 00                 1476 	.db 0x00
                           1477 	.area _CODE
                           1478 	.area _INITIALIZER
                           1479 	.area _CABS (ABS)
