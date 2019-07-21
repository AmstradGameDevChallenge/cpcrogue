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
                             12 	.globl _PrintCharacterStats
                             13 	.globl _InitializeCharacter
                             14 	.globl _cls
                             15 	.globl _pen
                             16 	.globl _paper
                             17 	.globl _border
                             18 	.globl _ink
                             19 	.globl _locate
                             20 	.globl _putchar
                             21 	.globl _printf
                             22 	.globl _cpct_setVideoMode
                             23 	.globl _cpct_isKeyPressed
                             24 	.globl _cpct_scanKeyboard
                             25 ;--------------------------------------------------------
                             26 ; special function registers
                             27 ;--------------------------------------------------------
                             28 ;--------------------------------------------------------
                             29 ; ram data
                             30 ;--------------------------------------------------------
                             31 	.area _DATA
                             32 ;--------------------------------------------------------
                             33 ; ram data
                             34 ;--------------------------------------------------------
                             35 	.area _INITIALIZED
                             36 ;--------------------------------------------------------
                             37 ; absolute external ram data
                             38 ;--------------------------------------------------------
                             39 	.area _DABS (ABS)
                             40 ;--------------------------------------------------------
                             41 ; global & static initialisations
                             42 ;--------------------------------------------------------
                             43 	.area _HOME
                             44 	.area _GSINIT
                             45 	.area _GSFINAL
                             46 	.area _GSINIT
                             47 ;--------------------------------------------------------
                             48 ; Home
                             49 ;--------------------------------------------------------
                             50 	.area _HOME
                             51 	.area _HOME
                             52 ;--------------------------------------------------------
                             53 ; code
                             54 ;--------------------------------------------------------
                             55 	.area _CODE
                             56 ;src/main.c:50: void locate (u8 x, u8 y)
                             57 ;	---------------------------------
                             58 ; Function locate
                             59 ; ---------------------------------
   4000                      60 _locate::
                             61 ;src/main.c:52: putchar(US);
   4000 21 1F 00      [10]   62 	ld	hl, #0x001f
   4003 E5            [11]   63 	push	hl
   4004 CD 9A 46      [17]   64 	call	_putchar
   4007 F1            [10]   65 	pop	af
                             66 ;src/main.c:53: putchar (x); putchar (y);
   4008 21 02 00      [10]   67 	ld	hl, #2+0
   400B 39            [11]   68 	add	hl, sp
   400C 4E            [ 7]   69 	ld	c, (hl)
   400D 06 00         [ 7]   70 	ld	b, #0x00
   400F C5            [11]   71 	push	bc
   4010 CD 9A 46      [17]   72 	call	_putchar
   4013 F1            [10]   73 	pop	af
   4014 21 03 00      [10]   74 	ld	hl, #3+0
   4017 39            [11]   75 	add	hl, sp
   4018 4E            [ 7]   76 	ld	c, (hl)
   4019 06 00         [ 7]   77 	ld	b, #0x00
   401B C5            [11]   78 	push	bc
   401C CD 9A 46      [17]   79 	call	_putchar
   401F F1            [10]   80 	pop	af
   4020 C9            [10]   81 	ret
                             82 ;src/main.c:55: void ink (u8 tinta, u8 color1, u8 color2)
                             83 ;	---------------------------------
                             84 ; Function ink
                             85 ; ---------------------------------
   4021                      86 _ink::
                             87 ;src/main.c:57: putchar (FS);
   4021 21 1C 00      [10]   88 	ld	hl, #0x001c
   4024 E5            [11]   89 	push	hl
   4025 CD 9A 46      [17]   90 	call	_putchar
   4028 F1            [10]   91 	pop	af
                             92 ;src/main.c:58: putchar (tinta); putchar (color1); putchar (color2);
   4029 21 02 00      [10]   93 	ld	hl, #2+0
   402C 39            [11]   94 	add	hl, sp
   402D 4E            [ 7]   95 	ld	c, (hl)
   402E 06 00         [ 7]   96 	ld	b, #0x00
   4030 C5            [11]   97 	push	bc
   4031 CD 9A 46      [17]   98 	call	_putchar
   4034 F1            [10]   99 	pop	af
   4035 21 03 00      [10]  100 	ld	hl, #3+0
   4038 39            [11]  101 	add	hl, sp
   4039 4E            [ 7]  102 	ld	c, (hl)
   403A 06 00         [ 7]  103 	ld	b, #0x00
   403C C5            [11]  104 	push	bc
   403D CD 9A 46      [17]  105 	call	_putchar
   4040 F1            [10]  106 	pop	af
   4041 21 04 00      [10]  107 	ld	hl, #4+0
   4044 39            [11]  108 	add	hl, sp
   4045 4E            [ 7]  109 	ld	c, (hl)
   4046 06 00         [ 7]  110 	ld	b, #0x00
   4048 C5            [11]  111 	push	bc
   4049 CD 9A 46      [17]  112 	call	_putchar
   404C F1            [10]  113 	pop	af
   404D C9            [10]  114 	ret
                            115 ;src/main.c:60: void border (u8 color1, u8 color2)
                            116 ;	---------------------------------
                            117 ; Function border
                            118 ; ---------------------------------
   404E                     119 _border::
                            120 ;src/main.c:62: putchar (GS);
   404E 21 1D 00      [10]  121 	ld	hl, #0x001d
   4051 E5            [11]  122 	push	hl
   4052 CD 9A 46      [17]  123 	call	_putchar
   4055 F1            [10]  124 	pop	af
                            125 ;src/main.c:63: putchar (color1); putchar (color2);
   4056 21 02 00      [10]  126 	ld	hl, #2+0
   4059 39            [11]  127 	add	hl, sp
   405A 4E            [ 7]  128 	ld	c, (hl)
   405B 06 00         [ 7]  129 	ld	b, #0x00
   405D C5            [11]  130 	push	bc
   405E CD 9A 46      [17]  131 	call	_putchar
   4061 F1            [10]  132 	pop	af
   4062 21 03 00      [10]  133 	ld	hl, #3+0
   4065 39            [11]  134 	add	hl, sp
   4066 4E            [ 7]  135 	ld	c, (hl)
   4067 06 00         [ 7]  136 	ld	b, #0x00
   4069 C5            [11]  137 	push	bc
   406A CD 9A 46      [17]  138 	call	_putchar
   406D F1            [10]  139 	pop	af
   406E C9            [10]  140 	ret
                            141 ;src/main.c:66: void paper (u8 color1)
                            142 ;	---------------------------------
                            143 ; Function paper
                            144 ; ---------------------------------
   406F                     145 _paper::
                            146 ;src/main.c:68: putchar (SO);
   406F 21 0E 00      [10]  147 	ld	hl, #0x000e
   4072 E5            [11]  148 	push	hl
   4073 CD 9A 46      [17]  149 	call	_putchar
   4076 F1            [10]  150 	pop	af
                            151 ;src/main.c:69: putchar (color1);
   4077 21 02 00      [10]  152 	ld	hl, #2+0
   407A 39            [11]  153 	add	hl, sp
   407B 4E            [ 7]  154 	ld	c, (hl)
   407C 06 00         [ 7]  155 	ld	b, #0x00
   407E C5            [11]  156 	push	bc
   407F CD 9A 46      [17]  157 	call	_putchar
   4082 F1            [10]  158 	pop	af
   4083 C9            [10]  159 	ret
                            160 ;src/main.c:71: void pen (u8 tinta)
                            161 ;	---------------------------------
                            162 ; Function pen
                            163 ; ---------------------------------
   4084                     164 _pen::
                            165 ;src/main.c:73: putchar (SI);
   4084 21 0F 00      [10]  166 	ld	hl, #0x000f
   4087 E5            [11]  167 	push	hl
   4088 CD 9A 46      [17]  168 	call	_putchar
   408B F1            [10]  169 	pop	af
                            170 ;src/main.c:74: putchar (tinta);
   408C 21 02 00      [10]  171 	ld	hl, #2+0
   408F 39            [11]  172 	add	hl, sp
   4090 4E            [ 7]  173 	ld	c, (hl)
   4091 06 00         [ 7]  174 	ld	b, #0x00
   4093 C5            [11]  175 	push	bc
   4094 CD 9A 46      [17]  176 	call	_putchar
   4097 F1            [10]  177 	pop	af
   4098 C9            [10]  178 	ret
                            179 ;src/main.c:76: void cls ()
                            180 ;	---------------------------------
                            181 ; Function cls
                            182 ; ---------------------------------
   4099                     183 _cls::
                            184 ;src/main.c:78: putchar (FF);
   4099 21 0C 00      [10]  185 	ld	hl, #0x000c
   409C E5            [11]  186 	push	hl
   409D CD 9A 46      [17]  187 	call	_putchar
   40A0 F1            [10]  188 	pop	af
   40A1 C9            [10]  189 	ret
                            190 ;src/main.c:83: void InitializeCharacter (struct TCharacter *c,
                            191 ;	---------------------------------
                            192 ; Function InitializeCharacter
                            193 ; ---------------------------------
   40A2                     194 _InitializeCharacter::
   40A2 DD E5         [15]  195 	push	ix
   40A4 DD 21 00 00   [14]  196 	ld	ix,#0
   40A8 DD 39         [15]  197 	add	ix,sp
   40AA 21 F6 FF      [10]  198 	ld	hl, #-10
   40AD 39            [11]  199 	add	hl, sp
   40AE F9            [ 6]  200 	ld	sp, hl
                            201 ;src/main.c:86: c->_hp = hp;
   40AF DD 4E 04      [19]  202 	ld	c,4 (ix)
   40B2 DD 46 05      [19]  203 	ld	b,5 (ix)
   40B5 69            [ 4]  204 	ld	l, c
   40B6 60            [ 4]  205 	ld	h, b
   40B7 DD 7E 06      [19]  206 	ld	a, 6 (ix)
   40BA 77            [ 7]  207 	ld	(hl), a
   40BB 23            [ 6]  208 	inc	hl
   40BC DD 7E 07      [19]  209 	ld	a, 7 (ix)
   40BF 77            [ 7]  210 	ld	(hl), a
                            211 ;src/main.c:87: c->_str = str;
   40C0 59            [ 4]  212 	ld	e, c
   40C1 50            [ 4]  213 	ld	d, b
   40C2 13            [ 6]  214 	inc	de
   40C3 13            [ 6]  215 	inc	de
   40C4 DD 7E 08      [19]  216 	ld	a, 8 (ix)
   40C7 12            [ 7]  217 	ld	(de), a
                            218 ;src/main.c:88: c->_destr = destr;
   40C8 59            [ 4]  219 	ld	e, c
   40C9 50            [ 4]  220 	ld	d, b
   40CA 13            [ 6]  221 	inc	de
   40CB 13            [ 6]  222 	inc	de
   40CC 13            [ 6]  223 	inc	de
   40CD DD 7E 09      [19]  224 	ld	a, 9 (ix)
   40D0 12            [ 7]  225 	ld	(de), a
                            226 ;src/main.c:89: c->_refl = refl;
   40D1 21 04 00      [10]  227 	ld	hl, #0x0004
   40D4 09            [11]  228 	add	hl, bc
   40D5 DD 7E 0A      [19]  229 	ld	a, 10 (ix)
   40D8 77            [ 7]  230 	ld	(hl), a
                            231 ;src/main.c:90: c->_spr = spr;
   40D9 21 09 00      [10]  232 	ld	hl, #0x0009
   40DC 09            [11]  233 	add	hl, bc
   40DD DD 7E 0B      [19]  234 	ld	a, 11 (ix)
   40E0 77            [ 7]  235 	ld	(hl), a
                            236 ;src/main.c:91: c->_atk = 1.5 * c->_str + c->_destr;
   40E1 21 05 00      [10]  237 	ld	hl, #0x0005
   40E4 09            [11]  238 	add	hl,bc
   40E5 DD 75 FE      [19]  239 	ld	-2 (ix), l
   40E8 DD 74 FF      [19]  240 	ld	-1 (ix), h
   40EB C5            [11]  241 	push	bc
   40EC DD 7E 08      [19]  242 	ld	a, 8 (ix)
   40EF F5            [11]  243 	push	af
   40F0 33            [ 6]  244 	inc	sp
   40F1 CD 1F 5A      [17]  245 	call	___uchar2fs
   40F4 33            [ 6]  246 	inc	sp
   40F5 EB            [ 4]  247 	ex	de, hl
   40F6 E5            [11]  248 	push	hl
   40F7 D5            [11]  249 	push	de
   40F8 21 C0 3F      [10]  250 	ld	hl, #0x3fc0
   40FB E5            [11]  251 	push	hl
   40FC 21 00 00      [10]  252 	ld	hl, #0x0000
   40FF E5            [11]  253 	push	hl
   4100 CD A7 52      [17]  254 	call	___fsmul
   4103 F1            [10]  255 	pop	af
   4104 F1            [10]  256 	pop	af
   4105 F1            [10]  257 	pop	af
   4106 F1            [10]  258 	pop	af
   4107 DD 72 FD      [19]  259 	ld	-3 (ix), d
   410A DD 73 FC      [19]  260 	ld	-4 (ix), e
   410D DD 74 FB      [19]  261 	ld	-5 (ix), h
   4110 DD 75 FA      [19]  262 	ld	-6 (ix), l
   4113 C1            [10]  263 	pop	bc
   4114 DD 5E 09      [19]  264 	ld	e, 9 (ix)
   4117 16 00         [ 7]  265 	ld	d, #0x00
   4119 C5            [11]  266 	push	bc
   411A D5            [11]  267 	push	de
   411B CD D5 59      [17]  268 	call	___sint2fs
   411E F1            [10]  269 	pop	af
   411F EB            [ 4]  270 	ex	de, hl
   4120 E5            [11]  271 	push	hl
   4121 D5            [11]  272 	push	de
   4122 DD 6E FC      [19]  273 	ld	l,-4 (ix)
   4125 DD 66 FD      [19]  274 	ld	h,-3 (ix)
   4128 E5            [11]  275 	push	hl
   4129 DD 6E FA      [19]  276 	ld	l,-6 (ix)
   412C DD 66 FB      [19]  277 	ld	h,-5 (ix)
   412F E5            [11]  278 	push	hl
   4130 CD 0C 56      [17]  279 	call	___fsadd
   4133 F1            [10]  280 	pop	af
   4134 F1            [10]  281 	pop	af
   4135 F1            [10]  282 	pop	af
   4136 F1            [10]  283 	pop	af
   4137 D5            [11]  284 	push	de
   4138 E5            [11]  285 	push	hl
   4139 CD F0 59      [17]  286 	call	___fs2uint
   413C F1            [10]  287 	pop	af
   413D F1            [10]  288 	pop	af
   413E EB            [ 4]  289 	ex	de,hl
   413F C1            [10]  290 	pop	bc
   4140 DD 6E FE      [19]  291 	ld	l,-2 (ix)
   4143 DD 66 FF      [19]  292 	ld	h,-1 (ix)
   4146 73            [ 7]  293 	ld	(hl), e
   4147 23            [ 6]  294 	inc	hl
   4148 72            [ 7]  295 	ld	(hl), d
                            296 ;src/main.c:92: c->_defense = 1.5 * c->_destr + c->_refl;
   4149 21 07 00      [10]  297 	ld	hl, #0x0007
   414C 09            [11]  298 	add	hl,bc
   414D DD 75 FA      [19]  299 	ld	-6 (ix), l
   4150 DD 74 FB      [19]  300 	ld	-5 (ix), h
   4153 DD 7E 09      [19]  301 	ld	a, 9 (ix)
   4156 F5            [11]  302 	push	af
   4157 33            [ 6]  303 	inc	sp
   4158 CD 1F 5A      [17]  304 	call	___uchar2fs
   415B 33            [ 6]  305 	inc	sp
   415C EB            [ 4]  306 	ex	de, hl
   415D E5            [11]  307 	push	hl
   415E D5            [11]  308 	push	de
   415F 21 C0 3F      [10]  309 	ld	hl, #0x3fc0
   4162 E5            [11]  310 	push	hl
   4163 21 00 00      [10]  311 	ld	hl, #0x0000
   4166 E5            [11]  312 	push	hl
   4167 CD A7 52      [17]  313 	call	___fsmul
   416A F1            [10]  314 	pop	af
   416B F1            [10]  315 	pop	af
   416C F1            [10]  316 	pop	af
   416D F1            [10]  317 	pop	af
   416E DD 72 F9      [19]  318 	ld	-7 (ix), d
   4171 DD 73 F8      [19]  319 	ld	-8 (ix), e
   4174 DD 74 F7      [19]  320 	ld	-9 (ix), h
   4177 DD 75 F6      [19]  321 	ld	-10 (ix), l
   417A DD 4E 0A      [19]  322 	ld	c, 10 (ix)
   417D 06 00         [ 7]  323 	ld	b, #0x00
   417F C5            [11]  324 	push	bc
   4180 CD D5 59      [17]  325 	call	___sint2fs
   4183 F1            [10]  326 	pop	af
   4184 EB            [ 4]  327 	ex	de, hl
   4185 E5            [11]  328 	push	hl
   4186 D5            [11]  329 	push	de
   4187 DD 6E F8      [19]  330 	ld	l,-8 (ix)
   418A DD 66 F9      [19]  331 	ld	h,-7 (ix)
   418D E5            [11]  332 	push	hl
   418E DD 6E F6      [19]  333 	ld	l,-10 (ix)
   4191 DD 66 F7      [19]  334 	ld	h,-9 (ix)
   4194 E5            [11]  335 	push	hl
   4195 CD 0C 56      [17]  336 	call	___fsadd
   4198 F1            [10]  337 	pop	af
   4199 F1            [10]  338 	pop	af
   419A F1            [10]  339 	pop	af
   419B F1            [10]  340 	pop	af
   419C D5            [11]  341 	push	de
   419D E5            [11]  342 	push	hl
   419E CD F0 59      [17]  343 	call	___fs2uint
   41A1 F1            [10]  344 	pop	af
   41A2 F1            [10]  345 	pop	af
   41A3 4D            [ 4]  346 	ld	c, l
   41A4 44            [ 4]  347 	ld	b, h
   41A5 DD 6E FA      [19]  348 	ld	l,-6 (ix)
   41A8 DD 66 FB      [19]  349 	ld	h,-5 (ix)
   41AB 71            [ 7]  350 	ld	(hl), c
   41AC 23            [ 6]  351 	inc	hl
   41AD 70            [ 7]  352 	ld	(hl), b
   41AE DD F9         [10]  353 	ld	sp, ix
   41B0 DD E1         [14]  354 	pop	ix
   41B2 C9            [10]  355 	ret
                            356 ;src/main.c:97: void PrintCharacterStats (struct TCharacter *c,
                            357 ;	---------------------------------
                            358 ; Function PrintCharacterStats
                            359 ; ---------------------------------
   41B3                     360 _PrintCharacterStats::
   41B3 DD E5         [15]  361 	push	ix
   41B5 DD 21 00 00   [14]  362 	ld	ix,#0
   41B9 DD 39         [15]  363 	add	ix,sp
   41BB F5            [11]  364 	push	af
                            365 ;src/main.c:100: pen (color1);printf ("STR "); pen (color2);printf ("[%d] ", c->_str);
   41BC DD 7E 06      [19]  366 	ld	a, 6 (ix)
   41BF F5            [11]  367 	push	af
   41C0 33            [ 6]  368 	inc	sp
   41C1 CD 84 40      [17]  369 	call	_pen
   41C4 33            [ 6]  370 	inc	sp
   41C5 21 D2 42      [10]  371 	ld	hl, #___str_0
   41C8 E5            [11]  372 	push	hl
   41C9 CD ED 46      [17]  373 	call	_printf
   41CC F1            [10]  374 	pop	af
   41CD DD 7E 07      [19]  375 	ld	a, 7 (ix)
   41D0 F5            [11]  376 	push	af
   41D1 33            [ 6]  377 	inc	sp
   41D2 CD 84 40      [17]  378 	call	_pen
   41D5 33            [ 6]  379 	inc	sp
   41D6 DD 7E 04      [19]  380 	ld	a, 4 (ix)
   41D9 DD 77 FE      [19]  381 	ld	-2 (ix), a
   41DC DD 7E 05      [19]  382 	ld	a, 5 (ix)
   41DF DD 77 FF      [19]  383 	ld	-1 (ix), a
   41E2 E1            [10]  384 	pop	hl
   41E3 E5            [11]  385 	push	hl
   41E4 23            [ 6]  386 	inc	hl
   41E5 23            [ 6]  387 	inc	hl
   41E6 4E            [ 7]  388 	ld	c, (hl)
   41E7 06 00         [ 7]  389 	ld	b, #0x00
   41E9 C5            [11]  390 	push	bc
   41EA 21 D7 42      [10]  391 	ld	hl, #___str_1
   41ED E5            [11]  392 	push	hl
   41EE CD ED 46      [17]  393 	call	_printf
   41F1 F1            [10]  394 	pop	af
   41F2 F1            [10]  395 	pop	af
                            396 ;src/main.c:101: pen (color1);printf ("DES "); pen (color2);printf ("[%d] ", c->_destr);
   41F3 DD 7E 06      [19]  397 	ld	a, 6 (ix)
   41F6 F5            [11]  398 	push	af
   41F7 33            [ 6]  399 	inc	sp
   41F8 CD 84 40      [17]  400 	call	_pen
   41FB 33            [ 6]  401 	inc	sp
   41FC 21 DD 42      [10]  402 	ld	hl, #___str_2
   41FF E5            [11]  403 	push	hl
   4200 CD ED 46      [17]  404 	call	_printf
   4203 F1            [10]  405 	pop	af
   4204 DD 7E 07      [19]  406 	ld	a, 7 (ix)
   4207 F5            [11]  407 	push	af
   4208 33            [ 6]  408 	inc	sp
   4209 CD 84 40      [17]  409 	call	_pen
   420C 33            [ 6]  410 	inc	sp
   420D E1            [10]  411 	pop	hl
   420E E5            [11]  412 	push	hl
   420F 23            [ 6]  413 	inc	hl
   4210 23            [ 6]  414 	inc	hl
   4211 23            [ 6]  415 	inc	hl
   4212 4E            [ 7]  416 	ld	c, (hl)
   4213 06 00         [ 7]  417 	ld	b, #0x00
   4215 C5            [11]  418 	push	bc
   4216 21 D7 42      [10]  419 	ld	hl, #___str_1
   4219 E5            [11]  420 	push	hl
   421A CD ED 46      [17]  421 	call	_printf
   421D F1            [10]  422 	pop	af
   421E F1            [10]  423 	pop	af
                            424 ;src/main.c:102: pen (color1);printf ("REF "); pen (color2);printf ("[%d]\r\n", c->_refl);
   421F DD 7E 06      [19]  425 	ld	a, 6 (ix)
   4222 F5            [11]  426 	push	af
   4223 33            [ 6]  427 	inc	sp
   4224 CD 84 40      [17]  428 	call	_pen
   4227 33            [ 6]  429 	inc	sp
   4228 21 E2 42      [10]  430 	ld	hl, #___str_3
   422B E5            [11]  431 	push	hl
   422C CD ED 46      [17]  432 	call	_printf
   422F F1            [10]  433 	pop	af
   4230 DD 7E 07      [19]  434 	ld	a, 7 (ix)
   4233 F5            [11]  435 	push	af
   4234 33            [ 6]  436 	inc	sp
   4235 CD 84 40      [17]  437 	call	_pen
   4238 33            [ 6]  438 	inc	sp
   4239 E1            [10]  439 	pop	hl
   423A E5            [11]  440 	push	hl
   423B 11 04 00      [10]  441 	ld	de, #0x0004
   423E 19            [11]  442 	add	hl, de
   423F 4E            [ 7]  443 	ld	c, (hl)
   4240 06 00         [ 7]  444 	ld	b, #0x00
   4242 C5            [11]  445 	push	bc
   4243 21 E7 42      [10]  446 	ld	hl, #___str_4
   4246 E5            [11]  447 	push	hl
   4247 CD ED 46      [17]  448 	call	_printf
   424A F1            [10]  449 	pop	af
   424B F1            [10]  450 	pop	af
                            451 ;src/main.c:104: pen (color1);printf ("ATK "); pen (color2);printf ("[%d] ", c->_atk);
   424C DD 7E 06      [19]  452 	ld	a, 6 (ix)
   424F F5            [11]  453 	push	af
   4250 33            [ 6]  454 	inc	sp
   4251 CD 84 40      [17]  455 	call	_pen
   4254 33            [ 6]  456 	inc	sp
   4255 21 EE 42      [10]  457 	ld	hl, #___str_5
   4258 E5            [11]  458 	push	hl
   4259 CD ED 46      [17]  459 	call	_printf
   425C F1            [10]  460 	pop	af
   425D DD 7E 07      [19]  461 	ld	a, 7 (ix)
   4260 F5            [11]  462 	push	af
   4261 33            [ 6]  463 	inc	sp
   4262 CD 84 40      [17]  464 	call	_pen
   4265 33            [ 6]  465 	inc	sp
   4266 E1            [10]  466 	pop	hl
   4267 E5            [11]  467 	push	hl
   4268 11 05 00      [10]  468 	ld	de, #0x0005
   426B 19            [11]  469 	add	hl, de
   426C 4E            [ 7]  470 	ld	c, (hl)
   426D 23            [ 6]  471 	inc	hl
   426E 46            [ 7]  472 	ld	b, (hl)
   426F C5            [11]  473 	push	bc
   4270 21 D7 42      [10]  474 	ld	hl, #___str_1
   4273 E5            [11]  475 	push	hl
   4274 CD ED 46      [17]  476 	call	_printf
   4277 F1            [10]  477 	pop	af
   4278 F1            [10]  478 	pop	af
                            479 ;src/main.c:105: pen (color1);printf ("DEF "); pen (color2);printf("[%d] ",c->_defense);
   4279 DD 7E 06      [19]  480 	ld	a, 6 (ix)
   427C F5            [11]  481 	push	af
   427D 33            [ 6]  482 	inc	sp
   427E CD 84 40      [17]  483 	call	_pen
   4281 33            [ 6]  484 	inc	sp
   4282 21 F3 42      [10]  485 	ld	hl, #___str_6
   4285 E5            [11]  486 	push	hl
   4286 CD ED 46      [17]  487 	call	_printf
   4289 F1            [10]  488 	pop	af
   428A DD 7E 07      [19]  489 	ld	a, 7 (ix)
   428D F5            [11]  490 	push	af
   428E 33            [ 6]  491 	inc	sp
   428F CD 84 40      [17]  492 	call	_pen
   4292 33            [ 6]  493 	inc	sp
   4293 E1            [10]  494 	pop	hl
   4294 E5            [11]  495 	push	hl
   4295 11 07 00      [10]  496 	ld	de, #0x0007
   4298 19            [11]  497 	add	hl, de
   4299 4E            [ 7]  498 	ld	c, (hl)
   429A 23            [ 6]  499 	inc	hl
   429B 46            [ 7]  500 	ld	b, (hl)
   429C C5            [11]  501 	push	bc
   429D 21 D7 42      [10]  502 	ld	hl, #___str_1
   42A0 E5            [11]  503 	push	hl
   42A1 CD ED 46      [17]  504 	call	_printf
   42A4 F1            [10]  505 	pop	af
   42A5 F1            [10]  506 	pop	af
                            507 ;src/main.c:106: pen (color1);printf (" HP "); pen (color2);printf ("[%d]\r\n", c->_hp);
   42A6 DD 7E 06      [19]  508 	ld	a, 6 (ix)
   42A9 F5            [11]  509 	push	af
   42AA 33            [ 6]  510 	inc	sp
   42AB CD 84 40      [17]  511 	call	_pen
   42AE 33            [ 6]  512 	inc	sp
   42AF 21 F8 42      [10]  513 	ld	hl, #___str_7
   42B2 E5            [11]  514 	push	hl
   42B3 CD ED 46      [17]  515 	call	_printf
   42B6 F1            [10]  516 	pop	af
   42B7 DD 7E 07      [19]  517 	ld	a, 7 (ix)
   42BA F5            [11]  518 	push	af
   42BB 33            [ 6]  519 	inc	sp
   42BC CD 84 40      [17]  520 	call	_pen
   42BF 33            [ 6]  521 	inc	sp
   42C0 E1            [10]  522 	pop	hl
   42C1 E5            [11]  523 	push	hl
   42C2 4E            [ 7]  524 	ld	c, (hl)
   42C3 23            [ 6]  525 	inc	hl
   42C4 46            [ 7]  526 	ld	b, (hl)
   42C5 C5            [11]  527 	push	bc
   42C6 21 E7 42      [10]  528 	ld	hl, #___str_4
   42C9 E5            [11]  529 	push	hl
   42CA CD ED 46      [17]  530 	call	_printf
   42CD DD F9         [10]  531 	ld	sp,ix
   42CF DD E1         [14]  532 	pop	ix
   42D1 C9            [10]  533 	ret
   42D2                     534 ___str_0:
   42D2 53 54 52 20         535 	.ascii "STR "
   42D6 00                  536 	.db 0x00
   42D7                     537 ___str_1:
   42D7 5B 25 64 5D 20      538 	.ascii "[%d] "
   42DC 00                  539 	.db 0x00
   42DD                     540 ___str_2:
   42DD 44 45 53 20         541 	.ascii "DES "
   42E1 00                  542 	.db 0x00
   42E2                     543 ___str_3:
   42E2 52 45 46 20         544 	.ascii "REF "
   42E6 00                  545 	.db 0x00
   42E7                     546 ___str_4:
   42E7 5B 25 64 5D         547 	.ascii "[%d]"
   42EB 0D                  548 	.db 0x0d
   42EC 0A                  549 	.db 0x0a
   42ED 00                  550 	.db 0x00
   42EE                     551 ___str_5:
   42EE 41 54 4B 20         552 	.ascii "ATK "
   42F2 00                  553 	.db 0x00
   42F3                     554 ___str_6:
   42F3 44 45 46 20         555 	.ascii "DEF "
   42F7 00                  556 	.db 0x00
   42F8                     557 ___str_7:
   42F8 20 48 50 20         558 	.ascii " HP "
   42FC 00                  559 	.db 0x00
                            560 ;src/main.c:111: void main(void) {
                            561 ;	---------------------------------
                            562 ; Function main
                            563 ; ---------------------------------
   42FD                     564 _main::
   42FD DD E5         [15]  565 	push	ix
   42FF 21 EC FF      [10]  566 	ld	hl, #-20
   4302 39            [11]  567 	add	hl, sp
   4303 F9            [ 6]  568 	ld	sp, hl
                            569 ;src/main.c:117: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
   4304 21 00 00      [10]  570 	ld	hl, #0x0000
   4307 E5            [11]  571 	push	hl
   4308 AF            [ 4]  572 	xor	a, a
   4309 F5            [11]  573 	push	af
   430A 33            [ 6]  574 	inc	sp
   430B CD 21 40      [17]  575 	call	_ink
   430E 33            [ 6]  576 	inc	sp
   430F 21 00 00      [10]  577 	ld	hl,#0x0000
   4312 E3            [19]  578 	ex	(sp),hl
   4313 3E 01         [ 7]  579 	ld	a, #0x01
   4315 F5            [11]  580 	push	af
   4316 33            [ 6]  581 	inc	sp
   4317 CD 21 40      [17]  582 	call	_ink
   431A 33            [ 6]  583 	inc	sp
   431B 21 00 00      [10]  584 	ld	hl,#0x0000
   431E E3            [19]  585 	ex	(sp),hl
   431F 3E 02         [ 7]  586 	ld	a, #0x02
   4321 F5            [11]  587 	push	af
   4322 33            [ 6]  588 	inc	sp
   4323 CD 21 40      [17]  589 	call	_ink
   4326 F1            [10]  590 	pop	af
   4327 33            [ 6]  591 	inc	sp
                            592 ;src/main.c:118: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
   4328 2E 01         [ 7]  593 	ld	l, #0x01
   432A CD B2 46      [17]  594 	call	_cpct_setVideoMode
                            595 ;src/main.c:119: border (0,0); paper (0); pen (1);
   432D 21 00 00      [10]  596 	ld	hl, #0x0000
   4330 E5            [11]  597 	push	hl
   4331 CD 4E 40      [17]  598 	call	_border
   4334 F1            [10]  599 	pop	af
   4335 AF            [ 4]  600 	xor	a, a
   4336 F5            [11]  601 	push	af
   4337 33            [ 6]  602 	inc	sp
   4338 CD 6F 40      [17]  603 	call	_paper
   433B 33            [ 6]  604 	inc	sp
   433C 3E 01         [ 7]  605 	ld	a, #0x01
   433E F5            [11]  606 	push	af
   433F 33            [ 6]  607 	inc	sp
   4340 CD 84 40      [17]  608 	call	_pen
   4343 33            [ 6]  609 	inc	sp
                            610 ;src/main.c:121: locate (0,4);printf ("      )   ___    _____    )   ___      ");
   4344 21 00 04      [10]  611 	ld	hl, #0x0400
   4347 E5            [11]  612 	push	hl
   4348 CD 00 40      [17]  613 	call	_locate
   434B 21 C1 44      [10]  614 	ld	hl, #___str_8
   434E E3            [19]  615 	ex	(sp),hl
   434F CD ED 46      [17]  616 	call	_printf
                            617 ;src/main.c:122: locate (0,5);printf ("     (__/_____) (, /   ) (__/_____)    ");
   4352 21 00 05      [10]  618 	ld	hl, #0x0500
   4355 E3            [19]  619 	ex	(sp),hl
   4356 CD 00 40      [17]  620 	call	_locate
   4359 21 E9 44      [10]  621 	ld	hl, #___str_9
   435C E3            [19]  622 	ex	(sp),hl
   435D CD ED 46      [17]  623 	call	_printf
                            624 ;src/main.c:123: locate (0,6);printf ("       /         _/__ /    /           ");
   4360 21 00 06      [10]  625 	ld	hl, #0x0600
   4363 E3            [19]  626 	ex	(sp),hl
   4364 CD 00 40      [17]  627 	call	_locate
   4367 21 11 45      [10]  628 	ld	hl, #___str_10
   436A E3            [19]  629 	ex	(sp),hl
   436B CD ED 46      [17]  630 	call	_printf
                            631 ;src/main.c:124: locate (0,7);printf ("      /          /        /            ");
   436E 21 00 07      [10]  632 	ld	hl, #0x0700
   4371 E3            [19]  633 	ex	(sp),hl
   4372 CD 00 40      [17]  634 	call	_locate
   4375 21 39 45      [10]  635 	ld	hl, #___str_11
   4378 E3            [19]  636 	ex	(sp),hl
   4379 CD ED 46      [17]  637 	call	_printf
                            638 ;src/main.c:125: locate (0,8);printf ("     (______) ) /        (______)      ");
   437C 21 00 08      [10]  639 	ld	hl, #0x0800
   437F E3            [19]  640 	ex	(sp),hl
   4380 CD 00 40      [17]  641 	call	_locate
   4383 21 61 45      [10]  642 	ld	hl, #___str_12
   4386 E3            [19]  643 	ex	(sp),hl
   4387 CD ED 46      [17]  644 	call	_printf
                            645 ;src/main.c:126: locate (0,9);printf ("            _(_/_                      ");
   438A 21 00 09      [10]  646 	ld	hl, #0x0900
   438D E3            [19]  647 	ex	(sp),hl
   438E CD 00 40      [17]  648 	call	_locate
   4391 21 89 45      [10]  649 	ld	hl, #___str_13
   4394 E3            [19]  650 	ex	(sp),hl
   4395 CD ED 46      [17]  651 	call	_printf
                            652 ;src/main.c:127: locate (0,10);printf ("           (, /   )                    ");
   4398 21 00 0A      [10]  653 	ld	hl, #0x0a00
   439B E3            [19]  654 	ex	(sp),hl
   439C CD 00 40      [17]  655 	call	_locate
   439F 21 B1 45      [10]  656 	ld	hl, #___str_14
   43A2 E3            [19]  657 	ex	(sp),hl
   43A3 CD ED 46      [17]  658 	call	_printf
                            659 ;src/main.c:128: locate (0,11);printf ("             /__ / ___      _          ");
   43A6 21 00 0B      [10]  660 	ld	hl, #0x0b00
   43A9 E3            [19]  661 	ex	(sp),hl
   43AA CD 00 40      [17]  662 	call	_locate
   43AD 21 D9 45      [10]  663 	ld	hl, #___str_15
   43B0 E3            [19]  664 	ex	(sp),hl
   43B1 CD ED 46      [17]  665 	call	_printf
                            666 ;src/main.c:131: locate (0,12);printf ("          ) /   \\_(_(_/(_(_(/_         ");
   43B4 21 00 0C      [10]  667 	ld	hl, #0x0c00
   43B7 E3            [19]  668 	ex	(sp),hl
   43B8 CD 00 40      [17]  669 	call	_locate
   43BB 21 01 46      [10]  670 	ld	hl, #___str_16
   43BE E3            [19]  671 	ex	(sp),hl
   43BF CD ED 46      [17]  672 	call	_printf
                            673 ;src/main.c:132: locate (0,13);printf ("         (_/       .-/                 ");
   43C2 21 00 0D      [10]  674 	ld	hl, #0x0d00
   43C5 E3            [19]  675 	ex	(sp),hl
   43C6 CD 00 40      [17]  676 	call	_locate
   43C9 21 29 46      [10]  677 	ld	hl, #___str_17
   43CC E3            [19]  678 	ex	(sp),hl
   43CD CD ED 46      [17]  679 	call	_printf
                            680 ;src/main.c:133: locate (0,14);printf ("                  (_/                  ");
   43D0 21 00 0E      [10]  681 	ld	hl, #0x0e00
   43D3 E3            [19]  682 	ex	(sp),hl
   43D4 CD 00 40      [17]  683 	call	_locate
   43D7 21 51 46      [10]  684 	ld	hl, #___str_18
   43DA E3            [19]  685 	ex	(sp),hl
   43DB CD ED 46      [17]  686 	call	_printf
                            687 ;src/main.c:134: locate (10, 18); pen (2); printf ("PRESS ENTER TO START");
   43DE 21 0A 12      [10]  688 	ld	hl, #0x120a
   43E1 E3            [19]  689 	ex	(sp),hl
   43E2 CD 00 40      [17]  690 	call	_locate
   43E5 26 02         [ 7]  691 	ld	h,#0x02
   43E7 E3            [19]  692 	ex	(sp),hl
   43E8 33            [ 6]  693 	inc	sp
   43E9 CD 84 40      [17]  694 	call	_pen
   43EC 33            [ 6]  695 	inc	sp
   43ED 21 79 46      [10]  696 	ld	hl, #___str_19
   43F0 E5            [11]  697 	push	hl
   43F1 CD ED 46      [17]  698 	call	_printf
                            699 ;src/main.c:135: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);
   43F4 21 03 03      [10]  700 	ld	hl, #0x0303
   43F7 E3            [19]  701 	ex	(sp),hl
   43F8 AF            [ 4]  702 	xor	a, a
   43F9 F5            [11]  703 	push	af
   43FA 33            [ 6]  704 	inc	sp
   43FB CD 21 40      [17]  705 	call	_ink
   43FE 33            [ 6]  706 	inc	sp
   43FF 21 06 0F      [10]  707 	ld	hl,#0x0f06
   4402 E3            [19]  708 	ex	(sp),hl
   4403 3E 01         [ 7]  709 	ld	a, #0x01
   4405 F5            [11]  710 	push	af
   4406 33            [ 6]  711 	inc	sp
   4407 CD 21 40      [17]  712 	call	_ink
   440A 33            [ 6]  713 	inc	sp
   440B 21 10 10      [10]  714 	ld	hl,#0x1010
   440E E3            [19]  715 	ex	(sp),hl
   440F 3E 02         [ 7]  716 	ld	a, #0x02
   4411 F5            [11]  717 	push	af
   4412 33            [ 6]  718 	inc	sp
   4413 CD 21 40      [17]  719 	call	_ink
   4416 33            [ 6]  720 	inc	sp
   4417 21 03 03      [10]  721 	ld	hl,#0x0303
   441A E3            [19]  722 	ex	(sp),hl
   441B CD 4E 40      [17]  723 	call	_border
   441E F1            [10]  724 	pop	af
                            725 ;src/main.c:138: while (!cpct_isKeyPressed (Key_Return)) {
   441F                     726 00101$:
   441F 21 02 04      [10]  727 	ld	hl, #0x0402
   4422 CD 8E 46      [17]  728 	call	_cpct_isKeyPressed
   4425 7D            [ 4]  729 	ld	a, l
   4426 B7            [ 4]  730 	or	a, a
   4427 20 05         [12]  731 	jr	NZ,00103$
                            732 ;src/main.c:139: cpct_scanKeyboard ();
   4429 CD 0B 47      [17]  733 	call	_cpct_scanKeyboard
   442C 18 F1         [12]  734 	jr	00101$
   442E                     735 00103$:
                            736 ;src/main.c:143: border (0,0); ink (0, 0,0); ink (1, 25,25); ink (2, 20,20);
   442E 21 00 00      [10]  737 	ld	hl, #0x0000
   4431 E5            [11]  738 	push	hl
   4432 CD 4E 40      [17]  739 	call	_border
   4435 21 00 00      [10]  740 	ld	hl, #0x0000
   4438 E3            [19]  741 	ex	(sp),hl
   4439 AF            [ 4]  742 	xor	a, a
   443A F5            [11]  743 	push	af
   443B 33            [ 6]  744 	inc	sp
   443C CD 21 40      [17]  745 	call	_ink
   443F 33            [ 6]  746 	inc	sp
   4440 21 19 19      [10]  747 	ld	hl,#0x1919
   4443 E3            [19]  748 	ex	(sp),hl
   4444 3E 01         [ 7]  749 	ld	a, #0x01
   4446 F5            [11]  750 	push	af
   4447 33            [ 6]  751 	inc	sp
   4448 CD 21 40      [17]  752 	call	_ink
   444B 33            [ 6]  753 	inc	sp
   444C 21 14 14      [10]  754 	ld	hl,#0x1414
   444F E3            [19]  755 	ex	(sp),hl
   4450 3E 02         [ 7]  756 	ld	a, #0x02
   4452 F5            [11]  757 	push	af
   4453 33            [ 6]  758 	inc	sp
   4454 CD 21 40      [17]  759 	call	_ink
   4457 F1            [10]  760 	pop	af
   4458 33            [ 6]  761 	inc	sp
                            762 ;src/main.c:144: paper (0); pen (2); cls ();
   4459 AF            [ 4]  763 	xor	a, a
   445A F5            [11]  764 	push	af
   445B 33            [ 6]  765 	inc	sp
   445C CD 6F 40      [17]  766 	call	_paper
   445F 33            [ 6]  767 	inc	sp
   4460 3E 02         [ 7]  768 	ld	a, #0x02
   4462 F5            [11]  769 	push	af
   4463 33            [ 6]  770 	inc	sp
   4464 CD 84 40      [17]  771 	call	_pen
   4467 33            [ 6]  772 	inc	sp
   4468 CD 99 40      [17]  773 	call	_cls
                            774 ;src/main.c:147: InitializeCharacter (&player, 150, 17, 14, 12, '@');
   446B 21 0A 00      [10]  775 	ld	hl, #0x000a
   446E 39            [11]  776 	add	hl, sp
   446F 4D            [ 4]  777 	ld	c, l
   4470 44            [ 4]  778 	ld	b, h
   4471 59            [ 4]  779 	ld	e, c
   4472 50            [ 4]  780 	ld	d, b
   4473 C5            [11]  781 	push	bc
   4474 21 0C 40      [10]  782 	ld	hl, #0x400c
   4477 E5            [11]  783 	push	hl
   4478 21 11 0E      [10]  784 	ld	hl, #0x0e11
   447B E5            [11]  785 	push	hl
   447C 21 96 00      [10]  786 	ld	hl, #0x0096
   447F E5            [11]  787 	push	hl
   4480 D5            [11]  788 	push	de
   4481 CD A2 40      [17]  789 	call	_InitializeCharacter
   4484 21 08 00      [10]  790 	ld	hl, #8
   4487 39            [11]  791 	add	hl, sp
   4488 F9            [ 6]  792 	ld	sp, hl
   4489 C1            [10]  793 	pop	bc
                            794 ;src/main.c:148: InitializeCharacter (&goblin, 100, 12, 13, 11, 'g');
   448A 21 00 00      [10]  795 	ld	hl, #0x0000
   448D 39            [11]  796 	add	hl, sp
   448E E5            [11]  797 	push	hl
   448F FD E1         [14]  798 	pop	iy
   4491 E5            [11]  799 	push	hl
   4492 C5            [11]  800 	push	bc
   4493 11 0B 67      [10]  801 	ld	de, #0x670b
   4496 D5            [11]  802 	push	de
   4497 11 0C 0D      [10]  803 	ld	de, #0x0d0c
   449A D5            [11]  804 	push	de
   449B 11 64 00      [10]  805 	ld	de, #0x0064
   449E D5            [11]  806 	push	de
   449F FD E5         [15]  807 	push	iy
   44A1 CD A2 40      [17]  808 	call	_InitializeCharacter
   44A4 21 08 00      [10]  809 	ld	hl, #8
   44A7 39            [11]  810 	add	hl, sp
   44A8 F9            [ 6]  811 	ld	sp, hl
   44A9 C1            [10]  812 	pop	bc
   44AA 11 01 02      [10]  813 	ld	de, #0x0201
   44AD D5            [11]  814 	push	de
   44AE C5            [11]  815 	push	bc
   44AF CD B3 41      [17]  816 	call	_PrintCharacterStats
   44B2 F1            [10]  817 	pop	af
   44B3 F1            [10]  818 	pop	af
   44B4 E1            [10]  819 	pop	hl
                            820 ;src/main.c:152: PrintCharacterStats (&goblin, 1,2);
   44B5 01 01 02      [10]  821 	ld	bc, #0x0201
   44B8 C5            [11]  822 	push	bc
   44B9 E5            [11]  823 	push	hl
   44BA CD B3 41      [17]  824 	call	_PrintCharacterStats
   44BD F1            [10]  825 	pop	af
   44BE F1            [10]  826 	pop	af
                            827 ;src/main.c:155: while (1);
   44BF                     828 00105$:
   44BF 18 FE         [12]  829 	jr	00105$
   44C1                     830 ___str_8:
   44C1 20 20 20 20 20 20   831 	.ascii "      )   ___    _____    )   ___      "
        29 20 20 20 5F 5F
        5F 20 20 20 20 5F
        5F 5F 5F 5F 20 20
        20 20 29 20 20 20
        5F 5F 5F 20 20 20
        20 20 20
   44E8 00                  832 	.db 0x00
   44E9                     833 ___str_9:
   44E9 20 20 20 20 20 28   834 	.ascii "     (__/_____) (, /   ) (__/_____)    "
        5F 5F 2F 5F 5F 5F
        5F 5F 29 20 28 2C
        20 2F 20 20 20 29
        20 28 5F 5F 2F 5F
        5F 5F 5F 5F 29 20
        20 20 20
   4510 00                  835 	.db 0x00
   4511                     836 ___str_10:
   4511 20 20 20 20 20 20   837 	.ascii "       /         _/__ /    /           "
        20 2F 20 20 20 20
        20 20 20 20 20 5F
        2F 5F 5F 20 2F 20
        20 20 20 2F 20 20
        20 20 20 20 20 20
        20 20 20
   4538 00                  838 	.db 0x00
   4539                     839 ___str_11:
   4539 20 20 20 20 20 20   840 	.ascii "      /          /        /            "
        2F 20 20 20 20 20
        20 20 20 20 20 2F
        20 20 20 20 20 20
        20 20 2F 20 20 20
        20 20 20 20 20 20
        20 20 20
   4560 00                  841 	.db 0x00
   4561                     842 ___str_12:
   4561 20 20 20 20 20 28   843 	.ascii "     (______) ) /        (______)      "
        5F 5F 5F 5F 5F 5F
        29 20 29 20 2F 20
        20 20 20 20 20 20
        20 28 5F 5F 5F 5F
        5F 5F 29 20 20 20
        20 20 20
   4588 00                  844 	.db 0x00
   4589                     845 ___str_13:
   4589 20 20 20 20 20 20   846 	.ascii "            _(_/_                      "
        20 20 20 20 20 20
        5F 28 5F 2F 5F 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   45B0 00                  847 	.db 0x00
   45B1                     848 ___str_14:
   45B1 20 20 20 20 20 20   849 	.ascii "           (, /   )                    "
        20 20 20 20 20 28
        2C 20 2F 20 20 20
        29 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   45D8 00                  850 	.db 0x00
   45D9                     851 ___str_15:
   45D9 20 20 20 20 20 20   852 	.ascii "             /__ / ___      _          "
        20 20 20 20 20 20
        20 2F 5F 5F 20 2F
        20 5F 5F 5F 20 20
        20 20 20 20 5F 20
        20 20 20 20 20 20
        20 20 20
   4600 00                  853 	.db 0x00
   4601                     854 ___str_16:
   4601 20 20 20 20 20 20   855 	.ascii "          ) /   "
        20 20 20 20 29 20
        2F 20 20 20
   4611 5C                  856 	.db 0x5c
   4612 5F 28 5F 28 5F 2F   857 	.ascii "_(_(_/(_(_(/_         "
        28 5F 28 5F 28 2F
        5F 20 20 20 20 20
        20 20 20 20
   4628 00                  858 	.db 0x00
   4629                     859 ___str_17:
   4629 20 20 20 20 20 20   860 	.ascii "         (_/       .-/                 "
        20 20 20 28 5F 2F
        20 20 20 20 20 20
        20 2E 2D 2F 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   4650 00                  861 	.db 0x00
   4651                     862 ___str_18:
   4651 20 20 20 20 20 20   863 	.ascii "                  (_/                  "
        20 20 20 20 20 20
        20 20 20 20 20 20
        28 5F 2F 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   4678 00                  864 	.db 0x00
   4679                     865 ___str_19:
   4679 50 52 45 53 53 20   866 	.ascii "PRESS ENTER TO START"
        45 4E 54 45 52 20
        54 4F 20 53 54 41
        52 54
   468D 00                  867 	.db 0x00
                            868 	.area _CODE
                            869 	.area _INITIALIZER
                            870 	.area _CABS (ABS)
