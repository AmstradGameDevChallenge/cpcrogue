                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module entity
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _EntityTakeDamage
                             12 	.globl _EntityCalculateDamage
                             13 	.globl _PrintU8
                             14 	.globl _PrintAt
                             15 	.globl _pen
                             16 	.globl _locate
                             17 	.globl _cpct_getRandom_mxor_u8
                             18 	.globl _putchar
                             19 	.globl _EntityInit
                             20 	.globl _EntityDraw
                             21 	.globl _EntityMove
                             22 	.globl _EntityAttack
                             23 	.globl _GetBlockingEntity
                             24 	.globl _EntityDrawEntities
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
                             56 ;src/entity.c:12: void EntityInit (TEntity *e, u8 x, u8 y, u8 spr, u8 color, u8 name[],
                             57 ;	---------------------------------
                             58 ; Function EntityInit
                             59 ; ---------------------------------
   45A1                      60 _EntityInit::
   45A1 DD E5         [15]   61 	push	ix
   45A3 DD 21 00 00   [14]   62 	ld	ix,#0
   45A7 DD 39         [15]   63 	add	ix,sp
   45A9 F5            [11]   64 	push	af
                             65 ;src/entity.c:15: e->x = e->px = x;  // current posX
   45AA DD 4E 04      [19]   66 	ld	c,4 (ix)
   45AD DD 46 05      [19]   67 	ld	b,5 (ix)
   45B0 59            [ 4]   68 	ld	e, c
   45B1 50            [ 4]   69 	ld	d, b
   45B2 13            [ 6]   70 	inc	de
   45B3 13            [ 6]   71 	inc	de
   45B4 DD 7E 06      [19]   72 	ld	a, 6 (ix)
   45B7 12            [ 7]   73 	ld	(de), a
   45B8 DD 7E 06      [19]   74 	ld	a, 6 (ix)
   45BB 02            [ 7]   75 	ld	(bc), a
                             76 ;src/entity.c:16: e->y = e->py = y;  // current posY
   45BC 59            [ 4]   77 	ld	e, c
   45BD 50            [ 4]   78 	ld	d, b
   45BE 13            [ 6]   79 	inc	de
   45BF 69            [ 4]   80 	ld	l, c
   45C0 60            [ 4]   81 	ld	h, b
   45C1 23            [ 6]   82 	inc	hl
   45C2 23            [ 6]   83 	inc	hl
   45C3 23            [ 6]   84 	inc	hl
   45C4 DD 7E 07      [19]   85 	ld	a, 7 (ix)
   45C7 77            [ 7]   86 	ld	(hl), a
   45C8 DD 7E 07      [19]   87 	ld	a, 7 (ix)
   45CB 12            [ 7]   88 	ld	(de), a
                             89 ;src/entity.c:17: e->spr =spr;
   45CC 21 04 00      [10]   90 	ld	hl, #0x0004
   45CF 09            [11]   91 	add	hl, bc
   45D0 DD 7E 08      [19]   92 	ld	a, 8 (ix)
   45D3 77            [ 7]   93 	ld	(hl), a
                             94 ;src/entity.c:18: e->color = color;
   45D4 21 05 00      [10]   95 	ld	hl, #0x0005
   45D7 09            [11]   96 	add	hl, bc
   45D8 DD 7E 09      [19]   97 	ld	a, 9 (ix)
   45DB 77            [ 7]   98 	ld	(hl), a
                             99 ;src/entity.c:19: strcpy (e->name, name);
   45DC 21 06 00      [10]  100 	ld	hl, #0x0006
   45DF 09            [11]  101 	add	hl,bc
   45E0 EB            [ 4]  102 	ex	de,hl
   45E1 C5            [11]  103 	push	bc
   45E2 DD 6E 0A      [19]  104 	ld	l,10 (ix)
   45E5 DD 66 0B      [19]  105 	ld	h,11 (ix)
   45E8 AF            [ 4]  106 	xor	a, a
   45E9                     107 00103$:
   45E9 BE            [ 7]  108 	cp	a, (hl)
   45EA ED A0         [16]  109 	ldi
   45EC 20 FB         [12]  110 	jr	NZ, 00103$
   45EE C1            [10]  111 	pop	bc
                            112 ;src/entity.c:20: e->blocks = blocks;
   45EF 21 15 00      [10]  113 	ld	hl, #0x0015
   45F2 09            [11]  114 	add	hl, bc
   45F3 DD 7E 0C      [19]  115 	ld	a, 12 (ix)
   45F6 77            [ 7]  116 	ld	(hl), a
                            117 ;src/entity.c:22: e->max_hp = hp;
   45F7 21 16 00      [10]  118 	ld	hl, #0x0016
   45FA 09            [11]  119 	add	hl, bc
   45FB DD 7E 0D      [19]  120 	ld	a, 13 (ix)
   45FE 77            [ 7]  121 	ld	(hl), a
   45FF 23            [ 6]  122 	inc	hl
   4600 DD 7E 0E      [19]  123 	ld	a, 14 (ix)
   4603 77            [ 7]  124 	ld	(hl), a
                            125 ;src/entity.c:23: e->hp = hp;
   4604 21 18 00      [10]  126 	ld	hl, #0x0018
   4607 09            [11]  127 	add	hl, bc
   4608 DD 7E 0D      [19]  128 	ld	a, 13 (ix)
   460B 77            [ 7]  129 	ld	(hl), a
   460C 23            [ 6]  130 	inc	hl
   460D DD 7E 0E      [19]  131 	ld	a, 14 (ix)
   4610 77            [ 7]  132 	ld	(hl), a
                            133 ;src/entity.c:24: e->str = str;
   4611 21 1A 00      [10]  134 	ld	hl, #0x001a
   4614 09            [11]  135 	add	hl, bc
   4615 DD 7E 0F      [19]  136 	ld	a, 15 (ix)
   4618 77            [ 7]  137 	ld	(hl), a
                            138 ;src/entity.c:25: e->des = destr;
   4619 21 1B 00      [10]  139 	ld	hl, #0x001b
   461C 09            [11]  140 	add	hl, bc
   461D DD 7E 10      [19]  141 	ld	a, 16 (ix)
   4620 77            [ 7]  142 	ld	(hl), a
                            143 ;src/entity.c:26: e->ref = refl;
   4621 21 1C 00      [10]  144 	ld	hl, #0x001c
   4624 09            [11]  145 	add	hl, bc
   4625 DD 7E 11      [19]  146 	ld	a, 17 (ix)
   4628 77            [ 7]  147 	ld	(hl), a
                            148 ;src/entity.c:28: e->atk = (str  + destr)>>1;
   4629 21 1D 00      [10]  149 	ld	hl, #0x001d
   462C 09            [11]  150 	add	hl, bc
   462D DD 5E 0F      [19]  151 	ld	e, 15 (ix)
   4630 16 00         [ 7]  152 	ld	d, #0x00
   4632 DD 7E 10      [19]  153 	ld	a, 16 (ix)
   4635 DD 77 FE      [19]  154 	ld	-2 (ix), a
   4638 DD 36 FF 00   [19]  155 	ld	-1 (ix), #0x00
   463C 7B            [ 4]  156 	ld	a, e
   463D DD 86 FE      [19]  157 	add	a, -2 (ix)
   4640 5F            [ 4]  158 	ld	e, a
   4641 7A            [ 4]  159 	ld	a, d
   4642 DD 8E FF      [19]  160 	adc	a, -1 (ix)
   4645 57            [ 4]  161 	ld	d, a
   4646 CB 2A         [ 8]  162 	sra	d
   4648 CB 1B         [ 8]  163 	rr	e
   464A 73            [ 7]  164 	ld	(hl), e
   464B 23            [ 6]  165 	inc	hl
   464C 72            [ 7]  166 	ld	(hl), d
                            167 ;src/entity.c:29: e->def = (destr + refl)>>1;
   464D 21 1F 00      [10]  168 	ld	hl, #0x001f
   4650 09            [11]  169 	add	hl, bc
   4651 DD 4E 11      [19]  170 	ld	c, 17 (ix)
   4654 06 00         [ 7]  171 	ld	b, #0x00
   4656 DD 7E FE      [19]  172 	ld	a, -2 (ix)
   4659 81            [ 4]  173 	add	a, c
   465A 4F            [ 4]  174 	ld	c, a
   465B DD 7E FF      [19]  175 	ld	a, -1 (ix)
   465E 88            [ 4]  176 	adc	a, b
   465F 47            [ 4]  177 	ld	b, a
   4660 CB 28         [ 8]  178 	sra	b
   4662 CB 19         [ 8]  179 	rr	c
   4664 71            [ 7]  180 	ld	(hl), c
   4665 23            [ 6]  181 	inc	hl
   4666 70            [ 7]  182 	ld	(hl), b
   4667 DD F9         [10]  183 	ld	sp, ix
   4669 DD E1         [14]  184 	pop	ix
   466B C9            [10]  185 	ret
                            186 ;src/entity.c:34: void EntityDraw (struct TEntity *e, u8 erase)
                            187 ;	---------------------------------
                            188 ; Function EntityDraw
                            189 ; ---------------------------------
   466C                     190 _EntityDraw::
   466C DD E5         [15]  191 	push	ix
   466E DD 21 00 00   [14]  192 	ld	ix,#0
   4672 DD 39         [15]  193 	add	ix,sp
   4674 3B            [ 6]  194 	dec	sp
                            195 ;src/entity.c:38: x = e->px;
   4675 DD 4E 04      [19]  196 	ld	c,4 (ix)
   4678 DD 46 05      [19]  197 	ld	b,5 (ix)
                            198 ;src/entity.c:37: if (erase) {
   467B DD 7E 06      [19]  199 	ld	a, 6 (ix)
   467E B7            [ 4]  200 	or	a, a
   467F 28 13         [12]  201 	jr	Z,00102$
                            202 ;src/entity.c:38: x = e->px;
   4681 69            [ 4]  203 	ld	l, c
   4682 60            [ 4]  204 	ld	h, b
   4683 23            [ 6]  205 	inc	hl
   4684 23            [ 6]  206 	inc	hl
   4685 5E            [ 7]  207 	ld	e, (hl)
                            208 ;src/entity.c:39: y = e->py;
   4686 69            [ 4]  209 	ld	l, c
   4687 60            [ 4]  210 	ld	h, b
   4688 23            [ 6]  211 	inc	hl
   4689 23            [ 6]  212 	inc	hl
   468A 23            [ 6]  213 	inc	hl
   468B 56            [ 7]  214 	ld	d, (hl)
                            215 ;src/entity.c:40: color = PEN_TILE;
   468C DD 36 FF 03   [19]  216 	ld	-1 (ix), #0x03
                            217 ;src/entity.c:41: spr = SPR_FLOOR;
   4690 0E 2E         [ 7]  218 	ld	c, #0x2e
   4692 18 16         [12]  219 	jr	00103$
   4694                     220 00102$:
                            221 ;src/entity.c:44: x = e->x;
   4694 0A            [ 7]  222 	ld	a, (bc)
   4695 5F            [ 4]  223 	ld	e, a
                            224 ;src/entity.c:45: y = e->y;
   4696 69            [ 4]  225 	ld	l, c
   4697 60            [ 4]  226 	ld	h, b
   4698 23            [ 6]  227 	inc	hl
   4699 56            [ 7]  228 	ld	d, (hl)
                            229 ;src/entity.c:46: color = e->color;
   469A C5            [11]  230 	push	bc
   469B FD E1         [14]  231 	pop	iy
   469D FD 7E 05      [19]  232 	ld	a, 5 (iy)
   46A0 DD 77 FF      [19]  233 	ld	-1 (ix), a
                            234 ;src/entity.c:47: spr = e->spr;
   46A3 69            [ 4]  235 	ld	l, c
   46A4 60            [ 4]  236 	ld	h, b
   46A5 01 04 00      [10]  237 	ld	bc, #0x0004
   46A8 09            [11]  238 	add	hl, bc
   46A9 4E            [ 7]  239 	ld	c, (hl)
   46AA                     240 00103$:
                            241 ;src/entity.c:49: pen (color);
   46AA C5            [11]  242 	push	bc
   46AB D5            [11]  243 	push	de
   46AC DD 7E FF      [19]  244 	ld	a, -1 (ix)
   46AF F5            [11]  245 	push	af
   46B0 33            [ 6]  246 	inc	sp
   46B1 CD B9 44      [17]  247 	call	_pen
   46B4 33            [ 6]  248 	inc	sp
   46B5 D1            [10]  249 	pop	de
   46B6 C1            [10]  250 	pop	bc
                            251 ;src/entity.c:50: locate (PLAY_X+x, PLAY_Y+y);
   46B7 14            [ 4]  252 	inc	d
   46B8 14            [ 4]  253 	inc	d
   46B9 43            [ 4]  254 	ld	b, e
   46BA 04            [ 4]  255 	inc	b
   46BB 04            [ 4]  256 	inc	b
   46BC C5            [11]  257 	push	bc
   46BD 58            [ 4]  258 	ld	e, b
   46BE D5            [11]  259 	push	de
   46BF CD 56 44      [17]  260 	call	_locate
   46C2 F1            [10]  261 	pop	af
   46C3 C1            [10]  262 	pop	bc
                            263 ;src/entity.c:51: putchar (spr);
   46C4 06 00         [ 7]  264 	ld	b, #0x00
   46C6 C5            [11]  265 	push	bc
   46C7 CD 52 4F      [17]  266 	call	_putchar
   46CA F1            [10]  267 	pop	af
   46CB 33            [ 6]  268 	inc	sp
   46CC DD E1         [14]  269 	pop	ix
   46CE C9            [10]  270 	ret
                            271 ;src/entity.c:56: void EntityMove (TEntity *e, i8 dx, i8 dy)
                            272 ;	---------------------------------
                            273 ; Function EntityMove
                            274 ; ---------------------------------
   46CF                     275 _EntityMove::
   46CF DD E5         [15]  276 	push	ix
   46D1 DD 21 00 00   [14]  277 	ld	ix,#0
   46D5 DD 39         [15]  278 	add	ix,sp
                            279 ;src/entity.c:58: e->px = e->x;     // Save old positions
   46D7 DD 5E 04      [19]  280 	ld	e,4 (ix)
   46DA DD 56 05      [19]  281 	ld	d,5 (ix)
   46DD 4B            [ 4]  282 	ld	c, e
   46DE 42            [ 4]  283 	ld	b, d
   46DF 03            [ 6]  284 	inc	bc
   46E0 03            [ 6]  285 	inc	bc
   46E1 1A            [ 7]  286 	ld	a, (de)
   46E2 02            [ 7]  287 	ld	(bc), a
                            288 ;src/entity.c:59: e->py = e->y;
   46E3 D5            [11]  289 	push	de
   46E4 FD E1         [14]  290 	pop	iy
   46E6 FD 23         [10]  291 	inc	iy
   46E8 FD 23         [10]  292 	inc	iy
   46EA FD 23         [10]  293 	inc	iy
   46EC 4B            [ 4]  294 	ld	c, e
   46ED 42            [ 4]  295 	ld	b, d
   46EE 03            [ 6]  296 	inc	bc
   46EF 0A            [ 7]  297 	ld	a, (bc)
   46F0 FD 77 00      [19]  298 	ld	0 (iy), a
                            299 ;src/entity.c:60: e->x  = e->x+dx;   // Update to new position
   46F3 1A            [ 7]  300 	ld	a, (de)
   46F4 DD 86 06      [19]  301 	add	a, 6 (ix)
   46F7 12            [ 7]  302 	ld	(de), a
                            303 ;src/entity.c:61: e->y  = e->y+dy;
   46F8 0A            [ 7]  304 	ld	a, (bc)
   46F9 DD 86 07      [19]  305 	add	a, 7 (ix)
   46FC 02            [ 7]  306 	ld	(bc), a
   46FD DD E1         [14]  307 	pop	ix
   46FF C9            [10]  308 	ret
                            309 ;src/entity.c:66: u8 EntityCalculateDamage (TEntity *e)
                            310 ;	---------------------------------
                            311 ; Function EntityCalculateDamage
                            312 ; ---------------------------------
   4700                     313 _EntityCalculateDamage::
                            314 ;src/entity.c:68: u8 dmg = e->atk >> 2;
   4700 C1            [10]  315 	pop	bc
   4701 E1            [10]  316 	pop	hl
   4702 E5            [11]  317 	push	hl
   4703 C5            [11]  318 	push	bc
   4704 11 1D 00      [10]  319 	ld	de, #0x001d
   4707 19            [11]  320 	add	hl, de
   4708 4E            [ 7]  321 	ld	c, (hl)
   4709 23            [ 6]  322 	inc	hl
   470A 46            [ 7]  323 	ld	b, (hl)
   470B CB 38         [ 8]  324 	srl	b
   470D CB 19         [ 8]  325 	rr	c
   470F CB 38         [ 8]  326 	srl	b
   4711 CB 19         [ 8]  327 	rr	c
                            328 ;src/entity.c:69: u8 r = (cpct_rand() * 7/255) - 3;
   4713 C5            [11]  329 	push	bc
   4714 CD 02 50      [17]  330 	call	_cpct_getRandom_mxor_u8
   4717 C1            [10]  331 	pop	bc
   4718 5D            [ 4]  332 	ld	e,l
   4719 16 00         [ 7]  333 	ld	d,#0x00
   471B 6B            [ 4]  334 	ld	l, e
   471C 62            [ 4]  335 	ld	h, d
   471D 29            [11]  336 	add	hl, hl
   471E 19            [11]  337 	add	hl, de
   471F 29            [11]  338 	add	hl, hl
   4720 19            [11]  339 	add	hl, de
   4721 C5            [11]  340 	push	bc
   4722 11 FF 00      [10]  341 	ld	de, #0x00ff
   4725 D5            [11]  342 	push	de
   4726 E5            [11]  343 	push	hl
   4727 CD 59 50      [17]  344 	call	__divsint
   472A F1            [10]  345 	pop	af
   472B F1            [10]  346 	pop	af
   472C C1            [10]  347 	pop	bc
   472D 7D            [ 4]  348 	ld	a, l
   472E C6 FD         [ 7]  349 	add	a, #0xfd
                            350 ;src/entity.c:70: dmg += r;
   4730 81            [ 4]  351 	add	a,c
                            352 ;src/entity.c:71: return (dmg < 127 ? dmg : dmg+3);
   4731 FE 7F         [ 7]  353 	cp	a, #0x7f
   4733 38 02         [12]  354 	jr	C,00104$
   4735 C6 03         [ 7]  355 	add	a, #0x03
   4737                     356 00104$:
   4737 6F            [ 4]  357 	ld	l, a
   4738 C9            [10]  358 	ret
                            359 ;src/entity.c:76: void EntityTakeDamage (TEntity *e, u8 dmg)
                            360 ;	---------------------------------
                            361 ; Function EntityTakeDamage
                            362 ; ---------------------------------
   4739                     363 _EntityTakeDamage::
   4739 DD E5         [15]  364 	push	ix
   473B DD 21 00 00   [14]  365 	ld	ix,#0
   473F DD 39         [15]  366 	add	ix,sp
   4741 F5            [11]  367 	push	af
                            368 ;src/entity.c:78: e->hp -= dmg;
   4742 DD 4E 04      [19]  369 	ld	c,4 (ix)
   4745 DD 46 05      [19]  370 	ld	b,5 (ix)
   4748 21 18 00      [10]  371 	ld	hl, #0x0018
   474B 09            [11]  372 	add	hl, bc
   474C E5            [11]  373 	push	hl
   474D 7E            [ 7]  374 	ld	a, (hl)
   474E DD 77 FE      [19]  375 	ld	-2 (ix), a
   4751 23            [ 6]  376 	inc	hl
   4752 7E            [ 7]  377 	ld	a, (hl)
   4753 DD 77 FF      [19]  378 	ld	-1 (ix), a
   4756 E1            [10]  379 	pop	hl
   4757 DD 5E 06      [19]  380 	ld	e, 6 (ix)
   475A 16 00         [ 7]  381 	ld	d, #0x00
   475C DD 7E FE      [19]  382 	ld	a, -2 (ix)
   475F 93            [ 4]  383 	sub	a, e
   4760 5F            [ 4]  384 	ld	e, a
   4761 DD 7E FF      [19]  385 	ld	a, -1 (ix)
   4764 9A            [ 4]  386 	sbc	a, d
   4765 57            [ 4]  387 	ld	d, a
   4766 73            [ 7]  388 	ld	(hl), e
   4767 23            [ 6]  389 	inc	hl
   4768 72            [ 7]  390 	ld	(hl), d
                            391 ;src/entity.c:79: PrintAt (STATUS_X,STATUS_Y+1, e->name, PEN_BRIGHT);
   4769 21 06 00      [10]  392 	ld	hl, #0x0006
   476C 09            [11]  393 	add	hl, bc
   476D 3E 02         [ 7]  394 	ld	a, #0x02
   476F F5            [11]  395 	push	af
   4770 33            [ 6]  396 	inc	sp
   4771 E5            [11]  397 	push	hl
   4772 21 02 16      [10]  398 	ld	hl, #0x1602
   4775 E5            [11]  399 	push	hl
   4776 CD CE 44      [17]  400 	call	_PrintAt
   4779 F1            [10]  401 	pop	af
   477A F1            [10]  402 	pop	af
   477B 33            [ 6]  403 	inc	sp
                            404 ;src/entity.c:80: PrintAt (STATUS_X+7,STATUS_Y+1, "takes     ", PEN_NORMAL);
   477C 3E 03         [ 7]  405 	ld	a, #0x03
   477E F5            [11]  406 	push	af
   477F 33            [ 6]  407 	inc	sp
   4780 21 B2 47      [10]  408 	ld	hl, #___str_0
   4783 E5            [11]  409 	push	hl
   4784 21 09 16      [10]  410 	ld	hl, #0x1609
   4787 E5            [11]  411 	push	hl
   4788 CD CE 44      [17]  412 	call	_PrintAt
   478B F1            [10]  413 	pop	af
                            414 ;src/entity.c:81: PrintU8 (dmg, STATUS_X+13,STATUS_Y+1, PEN_BRIGHT);
   478C 33            [ 6]  415 	inc	sp
   478D 21 16 02      [10]  416 	ld	hl,#0x0216
   4790 E3            [19]  417 	ex	(sp),hl
   4791 3E 0F         [ 7]  418 	ld	a, #0x0f
   4793 F5            [11]  419 	push	af
   4794 33            [ 6]  420 	inc	sp
   4795 DD 7E 06      [19]  421 	ld	a, 6 (ix)
   4798 F5            [11]  422 	push	af
   4799 33            [ 6]  423 	inc	sp
   479A CD 19 45      [17]  424 	call	_PrintU8
   479D F1            [10]  425 	pop	af
                            426 ;src/entity.c:82: PrintAt (STATUS_X+16,STATUS_Y+1, "points of damage", PEN_NORMAL);
   479E 26 03         [ 7]  427 	ld	h,#0x03
   47A0 E3            [19]  428 	ex	(sp),hl
   47A1 33            [ 6]  429 	inc	sp
   47A2 21 BD 47      [10]  430 	ld	hl, #___str_1
   47A5 E5            [11]  431 	push	hl
   47A6 21 12 16      [10]  432 	ld	hl, #0x1612
   47A9 E5            [11]  433 	push	hl
   47AA CD CE 44      [17]  434 	call	_PrintAt
   47AD DD F9         [10]  435 	ld	sp,ix
   47AF DD E1         [14]  436 	pop	ix
   47B1 C9            [10]  437 	ret
   47B2                     438 ___str_0:
   47B2 74 61 6B 65 73 20   439 	.ascii "takes     "
        20 20 20 20
   47BC 00                  440 	.db 0x00
   47BD                     441 ___str_1:
   47BD 70 6F 69 6E 74 73   442 	.ascii "points of damage"
        20 6F 66 20 64 61
        6D 61 67 65
   47CD 00                  443 	.db 0x00
                            444 ;src/entity.c:87: void EntityAttack (TEntity *e, TEntity *target)
                            445 ;	---------------------------------
                            446 ; Function EntityAttack
                            447 ; ---------------------------------
   47CE                     448 _EntityAttack::
   47CE DD E5         [15]  449 	push	ix
   47D0 DD 21 00 00   [14]  450 	ld	ix,#0
   47D4 DD 39         [15]  451 	add	ix,sp
                            452 ;src/entity.c:92: PrintAt (STATUS_X,STATUS_Y, e->name, PEN_BRIGHT);
   47D6 DD 5E 04      [19]  453 	ld	e,4 (ix)
   47D9 DD 56 05      [19]  454 	ld	d,5 (ix)
   47DC 21 06 00      [10]  455 	ld	hl, #0x0006
   47DF 19            [11]  456 	add	hl, de
   47E0 D5            [11]  457 	push	de
   47E1 3E 02         [ 7]  458 	ld	a, #0x02
   47E3 F5            [11]  459 	push	af
   47E4 33            [ 6]  460 	inc	sp
   47E5 E5            [11]  461 	push	hl
   47E6 21 02 15      [10]  462 	ld	hl, #0x1502
   47E9 E5            [11]  463 	push	hl
   47EA CD CE 44      [17]  464 	call	_PrintAt
   47ED F1            [10]  465 	pop	af
   47EE F1            [10]  466 	pop	af
   47EF 33            [ 6]  467 	inc	sp
   47F0 3E 03         [ 7]  468 	ld	a, #0x03
   47F2 F5            [11]  469 	push	af
   47F3 33            [ 6]  470 	inc	sp
   47F4 21 2F 48      [10]  471 	ld	hl, #___str_2
   47F7 E5            [11]  472 	push	hl
   47F8 21 0A 15      [10]  473 	ld	hl, #0x150a
   47FB E5            [11]  474 	push	hl
   47FC CD CE 44      [17]  475 	call	_PrintAt
   47FF F1            [10]  476 	pop	af
   4800 F1            [10]  477 	pop	af
   4801 33            [ 6]  478 	inc	sp
   4802 D1            [10]  479 	pop	de
                            480 ;src/entity.c:94: PrintAt (STATUS_X+16,STATUS_Y, target->name, PEN_BRIGHT);
   4803 DD 4E 06      [19]  481 	ld	c,6 (ix)
   4806 DD 46 07      [19]  482 	ld	b,7 (ix)
   4809 21 06 00      [10]  483 	ld	hl, #0x0006
   480C 09            [11]  484 	add	hl, bc
   480D C5            [11]  485 	push	bc
   480E D5            [11]  486 	push	de
   480F 3E 02         [ 7]  487 	ld	a, #0x02
   4811 F5            [11]  488 	push	af
   4812 33            [ 6]  489 	inc	sp
   4813 E5            [11]  490 	push	hl
   4814 21 12 15      [10]  491 	ld	hl, #0x1512
   4817 E5            [11]  492 	push	hl
   4818 CD CE 44      [17]  493 	call	_PrintAt
   481B F1            [10]  494 	pop	af
   481C F1            [10]  495 	pop	af
   481D 33            [ 6]  496 	inc	sp
   481E CD 00 47      [17]  497 	call	_EntityCalculateDamage
   4821 F1            [10]  498 	pop	af
   4822 55            [ 4]  499 	ld	d, l
   4823 C1            [10]  500 	pop	bc
                            501 ;src/entity.c:97: EntityTakeDamage (target, dmg);
   4824 D5            [11]  502 	push	de
   4825 33            [ 6]  503 	inc	sp
   4826 C5            [11]  504 	push	bc
   4827 CD 39 47      [17]  505 	call	_EntityTakeDamage
   482A F1            [10]  506 	pop	af
   482B 33            [ 6]  507 	inc	sp
   482C DD E1         [14]  508 	pop	ix
   482E C9            [10]  509 	ret
   482F                     510 ___str_2:
   482F 61 74 74 61 63 6B   511 	.ascii "attacks"
        73
   4836 00                  512 	.db 0x00
                            513 ;src/entity.c:102: u8 GetBlockingEntity (TEntity *entities[], TEntity **out_e, u8 x, u8 y)
                            514 ;	---------------------------------
                            515 ; Function GetBlockingEntity
                            516 ; ---------------------------------
   4837                     517 _GetBlockingEntity::
   4837 DD E5         [15]  518 	push	ix
   4839 DD 21 00 00   [14]  519 	ld	ix,#0
   483D DD 39         [15]  520 	add	ix,sp
   483F F5            [11]  521 	push	af
                            522 ;src/entity.c:107: while ( (e=*entities++) != NULL) {
   4840 DD 4E 04      [19]  523 	ld	c,4 (ix)
   4843 DD 46 05      [19]  524 	ld	b,5 (ix)
   4846                     525 00105$:
   4846 69            [ 4]  526 	ld	l, c
   4847 60            [ 4]  527 	ld	h, b
   4848 5E            [ 7]  528 	ld	e, (hl)
   4849 23            [ 6]  529 	inc	hl
   484A 56            [ 7]  530 	ld	d, (hl)
   484B 03            [ 6]  531 	inc	bc
   484C 03            [ 6]  532 	inc	bc
   484D 33            [ 6]  533 	inc	sp
   484E 33            [ 6]  534 	inc	sp
   484F D5            [11]  535 	push	de
   4850 7A            [ 4]  536 	ld	a, d
   4851 B3            [ 4]  537 	or	a,e
   4852 28 2E         [12]  538 	jr	Z,00107$
                            539 ;src/entity.c:108: if (e->blocks && e->x == x && e->y == y) {
   4854 E1            [10]  540 	pop	hl
   4855 E5            [11]  541 	push	hl
   4856 11 15 00      [10]  542 	ld	de, #0x0015
   4859 19            [11]  543 	add	hl, de
   485A 7E            [ 7]  544 	ld	a, (hl)
   485B B7            [ 4]  545 	or	a, a
   485C 28 E8         [12]  546 	jr	Z,00105$
   485E E1            [10]  547 	pop	hl
   485F E5            [11]  548 	push	hl
   4860 DD 7E 08      [19]  549 	ld	a,8 (ix)
   4863 96            [ 7]  550 	sub	a,(hl)
   4864 20 E0         [12]  551 	jr	NZ,00105$
   4866 E1            [10]  552 	pop	hl
   4867 E5            [11]  553 	push	hl
   4868 23            [ 6]  554 	inc	hl
   4869 DD 7E 09      [19]  555 	ld	a,9 (ix)
   486C 96            [ 7]  556 	sub	a,(hl)
   486D 20 D7         [12]  557 	jr	NZ,00105$
                            558 ;src/entity.c:109: *out_e = e;
   486F DD 4E 06      [19]  559 	ld	c,6 (ix)
   4872 DD 46 07      [19]  560 	ld	b,7 (ix)
   4875 DD 7E FE      [19]  561 	ld	a, -2 (ix)
   4878 02            [ 7]  562 	ld	(bc), a
   4879 03            [ 6]  563 	inc	bc
   487A DD 7E FF      [19]  564 	ld	a, -1 (ix)
   487D 02            [ 7]  565 	ld	(bc), a
                            566 ;src/entity.c:110: return TRUE;
   487E 2E 01         [ 7]  567 	ld	l, #0x01
   4880 18 02         [12]  568 	jr	00108$
   4882                     569 00107$:
                            570 ;src/entity.c:113: return FALSE;
   4882 2E 00         [ 7]  571 	ld	l, #0x00
   4884                     572 00108$:
   4884 DD F9         [10]  573 	ld	sp, ix
   4886 DD E1         [14]  574 	pop	ix
   4888 C9            [10]  575 	ret
                            576 ;src/entity.c:118: void EntityDrawEntities (TEntity *entities[], u8 dirty[])
                            577 ;	---------------------------------
                            578 ; Function EntityDrawEntities
                            579 ; ---------------------------------
   4889                     580 _EntityDrawEntities::
   4889 DD E5         [15]  581 	push	ix
   488B DD 21 00 00   [14]  582 	ld	ix,#0
   488F DD 39         [15]  583 	add	ix,sp
   4891 F5            [11]  584 	push	af
                            585 ;src/entity.c:122: while ( (e=entities[i]) ) {
   4892 0E 00         [ 7]  586 	ld	c, #0x00
   4894                     587 00103$:
   4894 69            [ 4]  588 	ld	l, c
   4895 26 00         [ 7]  589 	ld	h, #0x00
   4897 29            [11]  590 	add	hl, hl
   4898 EB            [ 4]  591 	ex	de,hl
   4899 DD 6E 04      [19]  592 	ld	l,4 (ix)
   489C DD 66 05      [19]  593 	ld	h,5 (ix)
   489F 19            [11]  594 	add	hl, de
   48A0 5E            [ 7]  595 	ld	e, (hl)
   48A1 23            [ 6]  596 	inc	hl
   48A2 56            [ 7]  597 	ld	d, (hl)
   48A3 33            [ 6]  598 	inc	sp
   48A4 33            [ 6]  599 	inc	sp
   48A5 D5            [11]  600 	push	de
   48A6 7A            [ 4]  601 	ld	a, d
   48A7 B3            [ 4]  602 	or	a,e
   48A8 28 37         [12]  603 	jr	Z,00106$
                            604 ;src/entity.c:123: if (dirty[i]) {
   48AA DD 6E 06      [19]  605 	ld	l,6 (ix)
   48AD DD 66 07      [19]  606 	ld	h,7 (ix)
   48B0 06 00         [ 7]  607 	ld	b, #0x00
   48B2 09            [11]  608 	add	hl, bc
   48B3 7E            [ 7]  609 	ld	a, (hl)
   48B4 B7            [ 4]  610 	or	a, a
   48B5 28 16         [12]  611 	jr	Z,00102$
                            612 ;src/entity.c:124: EntityDraw (e, TRUE);
   48B7 E5            [11]  613 	push	hl
   48B8 C5            [11]  614 	push	bc
   48B9 3E 01         [ 7]  615 	ld	a, #0x01
   48BB F5            [11]  616 	push	af
   48BC 33            [ 6]  617 	inc	sp
   48BD DD 5E FE      [19]  618 	ld	e,-2 (ix)
   48C0 DD 56 FF      [19]  619 	ld	d,-1 (ix)
   48C3 D5            [11]  620 	push	de
   48C4 CD 6C 46      [17]  621 	call	_EntityDraw
   48C7 F1            [10]  622 	pop	af
   48C8 33            [ 6]  623 	inc	sp
   48C9 C1            [10]  624 	pop	bc
   48CA E1            [10]  625 	pop	hl
                            626 ;src/entity.c:125: dirty[i] = FALSE;
   48CB 36 00         [10]  627 	ld	(hl), #0x00
   48CD                     628 00102$:
                            629 ;src/entity.c:127: EntityDraw (e, FALSE);
   48CD C5            [11]  630 	push	bc
   48CE AF            [ 4]  631 	xor	a, a
   48CF F5            [11]  632 	push	af
   48D0 33            [ 6]  633 	inc	sp
   48D1 DD 6E FE      [19]  634 	ld	l,-2 (ix)
   48D4 DD 66 FF      [19]  635 	ld	h,-1 (ix)
   48D7 E5            [11]  636 	push	hl
   48D8 CD 6C 46      [17]  637 	call	_EntityDraw
   48DB F1            [10]  638 	pop	af
   48DC 33            [ 6]  639 	inc	sp
   48DD C1            [10]  640 	pop	bc
                            641 ;src/entity.c:128: ++i;
   48DE 0C            [ 4]  642 	inc	c
   48DF 18 B3         [12]  643 	jr	00103$
   48E1                     644 00106$:
   48E1 DD F9         [10]  645 	ld	sp, ix
   48E3 DD E1         [14]  646 	pop	ix
   48E5 C9            [10]  647 	ret
                            648 	.area _CODE
                            649 	.area _INITIALIZER
                            650 	.area _CABS (ABS)
