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
                             25 	.globl _EntityPrintStats
                             26 ;--------------------------------------------------------
                             27 ; special function registers
                             28 ;--------------------------------------------------------
                             29 ;--------------------------------------------------------
                             30 ; ram data
                             31 ;--------------------------------------------------------
                             32 	.area _DATA
                             33 ;--------------------------------------------------------
                             34 ; ram data
                             35 ;--------------------------------------------------------
                             36 	.area _INITIALIZED
                             37 ;--------------------------------------------------------
                             38 ; absolute external ram data
                             39 ;--------------------------------------------------------
                             40 	.area _DABS (ABS)
                             41 ;--------------------------------------------------------
                             42 ; global & static initialisations
                             43 ;--------------------------------------------------------
                             44 	.area _HOME
                             45 	.area _GSINIT
                             46 	.area _GSFINAL
                             47 	.area _GSINIT
                             48 ;--------------------------------------------------------
                             49 ; Home
                             50 ;--------------------------------------------------------
                             51 	.area _HOME
                             52 	.area _HOME
                             53 ;--------------------------------------------------------
                             54 ; code
                             55 ;--------------------------------------------------------
                             56 	.area _CODE
                             57 ;src/entity.c:12: void EntityInit (TEntity *e, u8 x, u8 y, u8 spr, u8 color, u8 name[],
                             58 ;	---------------------------------
                             59 ; Function EntityInit
                             60 ; ---------------------------------
   455A                      61 _EntityInit::
   455A DD E5         [15]   62 	push	ix
   455C DD 21 00 00   [14]   63 	ld	ix,#0
   4560 DD 39         [15]   64 	add	ix,sp
   4562 F5            [11]   65 	push	af
                             66 ;src/entity.c:15: e->x = e->px = x;  // current posX
   4563 DD 4E 04      [19]   67 	ld	c,4 (ix)
   4566 DD 46 05      [19]   68 	ld	b,5 (ix)
   4569 59            [ 4]   69 	ld	e, c
   456A 50            [ 4]   70 	ld	d, b
   456B 13            [ 6]   71 	inc	de
   456C 13            [ 6]   72 	inc	de
   456D DD 7E 06      [19]   73 	ld	a, 6 (ix)
   4570 12            [ 7]   74 	ld	(de), a
   4571 DD 7E 06      [19]   75 	ld	a, 6 (ix)
   4574 02            [ 7]   76 	ld	(bc), a
                             77 ;src/entity.c:16: e->y = e->py = y;  // current posY
   4575 59            [ 4]   78 	ld	e, c
   4576 50            [ 4]   79 	ld	d, b
   4577 13            [ 6]   80 	inc	de
   4578 69            [ 4]   81 	ld	l, c
   4579 60            [ 4]   82 	ld	h, b
   457A 23            [ 6]   83 	inc	hl
   457B 23            [ 6]   84 	inc	hl
   457C 23            [ 6]   85 	inc	hl
   457D DD 7E 07      [19]   86 	ld	a, 7 (ix)
   4580 77            [ 7]   87 	ld	(hl), a
   4581 DD 7E 07      [19]   88 	ld	a, 7 (ix)
   4584 12            [ 7]   89 	ld	(de), a
                             90 ;src/entity.c:17: e->spr =spr;
   4585 21 04 00      [10]   91 	ld	hl, #0x0004
   4588 09            [11]   92 	add	hl, bc
   4589 DD 7E 08      [19]   93 	ld	a, 8 (ix)
   458C 77            [ 7]   94 	ld	(hl), a
                             95 ;src/entity.c:18: e->color = color;
   458D 21 05 00      [10]   96 	ld	hl, #0x0005
   4590 09            [11]   97 	add	hl, bc
   4591 DD 7E 09      [19]   98 	ld	a, 9 (ix)
   4594 77            [ 7]   99 	ld	(hl), a
                            100 ;src/entity.c:19: strcpy (e->name, name);
   4595 21 06 00      [10]  101 	ld	hl, #0x0006
   4598 09            [11]  102 	add	hl,bc
   4599 EB            [ 4]  103 	ex	de,hl
   459A C5            [11]  104 	push	bc
   459B DD 6E 0A      [19]  105 	ld	l,10 (ix)
   459E DD 66 0B      [19]  106 	ld	h,11 (ix)
   45A1 AF            [ 4]  107 	xor	a, a
   45A2                     108 00103$:
   45A2 BE            [ 7]  109 	cp	a, (hl)
   45A3 ED A0         [16]  110 	ldi
   45A5 20 FB         [12]  111 	jr	NZ, 00103$
   45A7 C1            [10]  112 	pop	bc
                            113 ;src/entity.c:20: e->blocks = blocks;
   45A8 21 15 00      [10]  114 	ld	hl, #0x0015
   45AB 09            [11]  115 	add	hl, bc
   45AC DD 7E 0C      [19]  116 	ld	a, 12 (ix)
   45AF 77            [ 7]  117 	ld	(hl), a
                            118 ;src/entity.c:22: e->max_hp = hp;
   45B0 21 16 00      [10]  119 	ld	hl, #0x0016
   45B3 09            [11]  120 	add	hl, bc
   45B4 DD 7E 0D      [19]  121 	ld	a, 13 (ix)
   45B7 77            [ 7]  122 	ld	(hl), a
   45B8 23            [ 6]  123 	inc	hl
   45B9 DD 7E 0E      [19]  124 	ld	a, 14 (ix)
   45BC 77            [ 7]  125 	ld	(hl), a
                            126 ;src/entity.c:23: e->hp = hp;
   45BD 21 18 00      [10]  127 	ld	hl, #0x0018
   45C0 09            [11]  128 	add	hl, bc
   45C1 DD 7E 0D      [19]  129 	ld	a, 13 (ix)
   45C4 77            [ 7]  130 	ld	(hl), a
   45C5 23            [ 6]  131 	inc	hl
   45C6 DD 7E 0E      [19]  132 	ld	a, 14 (ix)
   45C9 77            [ 7]  133 	ld	(hl), a
                            134 ;src/entity.c:24: e->str = str;
   45CA 21 1A 00      [10]  135 	ld	hl, #0x001a
   45CD 09            [11]  136 	add	hl, bc
   45CE DD 7E 0F      [19]  137 	ld	a, 15 (ix)
   45D1 77            [ 7]  138 	ld	(hl), a
                            139 ;src/entity.c:25: e->des = destr;
   45D2 21 1B 00      [10]  140 	ld	hl, #0x001b
   45D5 09            [11]  141 	add	hl, bc
   45D6 DD 7E 10      [19]  142 	ld	a, 16 (ix)
   45D9 77            [ 7]  143 	ld	(hl), a
                            144 ;src/entity.c:26: e->ref = refl;
   45DA 21 1C 00      [10]  145 	ld	hl, #0x001c
   45DD 09            [11]  146 	add	hl, bc
   45DE DD 7E 11      [19]  147 	ld	a, 17 (ix)
   45E1 77            [ 7]  148 	ld	(hl), a
                            149 ;src/entity.c:28: e->atk = (str  + destr)>>1;
   45E2 21 1D 00      [10]  150 	ld	hl, #0x001d
   45E5 09            [11]  151 	add	hl, bc
   45E6 DD 5E 0F      [19]  152 	ld	e, 15 (ix)
   45E9 16 00         [ 7]  153 	ld	d, #0x00
   45EB DD 7E 10      [19]  154 	ld	a, 16 (ix)
   45EE DD 77 FE      [19]  155 	ld	-2 (ix), a
   45F1 DD 36 FF 00   [19]  156 	ld	-1 (ix), #0x00
   45F5 7B            [ 4]  157 	ld	a, e
   45F6 DD 86 FE      [19]  158 	add	a, -2 (ix)
   45F9 5F            [ 4]  159 	ld	e, a
   45FA 7A            [ 4]  160 	ld	a, d
   45FB DD 8E FF      [19]  161 	adc	a, -1 (ix)
   45FE 57            [ 4]  162 	ld	d, a
   45FF CB 2A         [ 8]  163 	sra	d
   4601 CB 1B         [ 8]  164 	rr	e
   4603 73            [ 7]  165 	ld	(hl), e
   4604 23            [ 6]  166 	inc	hl
   4605 72            [ 7]  167 	ld	(hl), d
                            168 ;src/entity.c:29: e->def = (destr + refl)>>1;
   4606 21 1F 00      [10]  169 	ld	hl, #0x001f
   4609 09            [11]  170 	add	hl, bc
   460A DD 4E 11      [19]  171 	ld	c, 17 (ix)
   460D 06 00         [ 7]  172 	ld	b, #0x00
   460F DD 7E FE      [19]  173 	ld	a, -2 (ix)
   4612 81            [ 4]  174 	add	a, c
   4613 4F            [ 4]  175 	ld	c, a
   4614 DD 7E FF      [19]  176 	ld	a, -1 (ix)
   4617 88            [ 4]  177 	adc	a, b
   4618 47            [ 4]  178 	ld	b, a
   4619 CB 28         [ 8]  179 	sra	b
   461B CB 19         [ 8]  180 	rr	c
   461D 71            [ 7]  181 	ld	(hl), c
   461E 23            [ 6]  182 	inc	hl
   461F 70            [ 7]  183 	ld	(hl), b
   4620 DD F9         [10]  184 	ld	sp, ix
   4622 DD E1         [14]  185 	pop	ix
   4624 C9            [10]  186 	ret
                            187 ;src/entity.c:34: void EntityDraw (struct TEntity *e, u8 erase)
                            188 ;	---------------------------------
                            189 ; Function EntityDraw
                            190 ; ---------------------------------
   4625                     191 _EntityDraw::
   4625 DD E5         [15]  192 	push	ix
   4627 DD 21 00 00   [14]  193 	ld	ix,#0
   462B DD 39         [15]  194 	add	ix,sp
   462D 3B            [ 6]  195 	dec	sp
                            196 ;src/entity.c:38: x = e->px;
   462E DD 4E 04      [19]  197 	ld	c,4 (ix)
   4631 DD 46 05      [19]  198 	ld	b,5 (ix)
                            199 ;src/entity.c:37: if (erase) {
   4634 DD 7E 06      [19]  200 	ld	a, 6 (ix)
   4637 B7            [ 4]  201 	or	a, a
   4638 28 13         [12]  202 	jr	Z,00102$
                            203 ;src/entity.c:38: x = e->px;
   463A 69            [ 4]  204 	ld	l, c
   463B 60            [ 4]  205 	ld	h, b
   463C 23            [ 6]  206 	inc	hl
   463D 23            [ 6]  207 	inc	hl
   463E 5E            [ 7]  208 	ld	e, (hl)
                            209 ;src/entity.c:39: y = e->py;
   463F 69            [ 4]  210 	ld	l, c
   4640 60            [ 4]  211 	ld	h, b
   4641 23            [ 6]  212 	inc	hl
   4642 23            [ 6]  213 	inc	hl
   4643 23            [ 6]  214 	inc	hl
   4644 56            [ 7]  215 	ld	d, (hl)
                            216 ;src/entity.c:40: color = PEN_TILE;
   4645 DD 36 FF 02   [19]  217 	ld	-1 (ix), #0x02
                            218 ;src/entity.c:41: spr = SPR_FLOOR;
   4649 0E 2E         [ 7]  219 	ld	c, #0x2e
   464B 18 16         [12]  220 	jr	00103$
   464D                     221 00102$:
                            222 ;src/entity.c:44: x = e->x;
   464D 0A            [ 7]  223 	ld	a, (bc)
   464E 5F            [ 4]  224 	ld	e, a
                            225 ;src/entity.c:45: y = e->y;
   464F 69            [ 4]  226 	ld	l, c
   4650 60            [ 4]  227 	ld	h, b
   4651 23            [ 6]  228 	inc	hl
   4652 56            [ 7]  229 	ld	d, (hl)
                            230 ;src/entity.c:46: color = e->color;
   4653 C5            [11]  231 	push	bc
   4654 FD E1         [14]  232 	pop	iy
   4656 FD 7E 05      [19]  233 	ld	a, 5 (iy)
   4659 DD 77 FF      [19]  234 	ld	-1 (ix), a
                            235 ;src/entity.c:47: spr = e->spr;
   465C 69            [ 4]  236 	ld	l, c
   465D 60            [ 4]  237 	ld	h, b
   465E 01 04 00      [10]  238 	ld	bc, #0x0004
   4661 09            [11]  239 	add	hl, bc
   4662 4E            [ 7]  240 	ld	c, (hl)
   4663                     241 00103$:
                            242 ;src/entity.c:49: pen (color);
   4663 C5            [11]  243 	push	bc
   4664 D5            [11]  244 	push	de
   4665 DD 7E FF      [19]  245 	ld	a, -1 (ix)
   4668 F5            [11]  246 	push	af
   4669 33            [ 6]  247 	inc	sp
   466A CD BF 44      [17]  248 	call	_pen
   466D 33            [ 6]  249 	inc	sp
   466E D1            [10]  250 	pop	de
   466F C1            [10]  251 	pop	bc
                            252 ;src/entity.c:50: locate (PLAY_X+x, PLAY_Y+y);
   4670 14            [ 4]  253 	inc	d
   4671 14            [ 4]  254 	inc	d
   4672 43            [ 4]  255 	ld	b, e
   4673 04            [ 4]  256 	inc	b
   4674 C5            [11]  257 	push	bc
   4675 58            [ 4]  258 	ld	e, b
   4676 D5            [11]  259 	push	de
   4677 CD 5C 44      [17]  260 	call	_locate
   467A F1            [10]  261 	pop	af
   467B C1            [10]  262 	pop	bc
                            263 ;src/entity.c:51: putchar (spr);
   467C 06 00         [ 7]  264 	ld	b, #0x00
   467E C5            [11]  265 	push	bc
   467F CD E4 4C      [17]  266 	call	_putchar
   4682 F1            [10]  267 	pop	af
   4683 33            [ 6]  268 	inc	sp
   4684 DD E1         [14]  269 	pop	ix
   4686 C9            [10]  270 	ret
                            271 ;src/entity.c:56: void EntityMove (TEntity *e, i8 dx, i8 dy)
                            272 ;	---------------------------------
                            273 ; Function EntityMove
                            274 ; ---------------------------------
   4687                     275 _EntityMove::
   4687 DD E5         [15]  276 	push	ix
   4689 DD 21 00 00   [14]  277 	ld	ix,#0
   468D DD 39         [15]  278 	add	ix,sp
                            279 ;src/entity.c:58: e->px = e->x;     // Save old positions
   468F DD 5E 04      [19]  280 	ld	e,4 (ix)
   4692 DD 56 05      [19]  281 	ld	d,5 (ix)
   4695 4B            [ 4]  282 	ld	c, e
   4696 42            [ 4]  283 	ld	b, d
   4697 03            [ 6]  284 	inc	bc
   4698 03            [ 6]  285 	inc	bc
   4699 1A            [ 7]  286 	ld	a, (de)
   469A 02            [ 7]  287 	ld	(bc), a
                            288 ;src/entity.c:59: e->py = e->y;
   469B D5            [11]  289 	push	de
   469C FD E1         [14]  290 	pop	iy
   469E FD 23         [10]  291 	inc	iy
   46A0 FD 23         [10]  292 	inc	iy
   46A2 FD 23         [10]  293 	inc	iy
   46A4 4B            [ 4]  294 	ld	c, e
   46A5 42            [ 4]  295 	ld	b, d
   46A6 03            [ 6]  296 	inc	bc
   46A7 0A            [ 7]  297 	ld	a, (bc)
   46A8 FD 77 00      [19]  298 	ld	0 (iy), a
                            299 ;src/entity.c:60: e->x  = e->x+dx;   // Update to new position
   46AB 1A            [ 7]  300 	ld	a, (de)
   46AC DD 86 06      [19]  301 	add	a, 6 (ix)
   46AF 12            [ 7]  302 	ld	(de), a
                            303 ;src/entity.c:61: e->y  = e->y+dy;
   46B0 0A            [ 7]  304 	ld	a, (bc)
   46B1 DD 86 07      [19]  305 	add	a, 7 (ix)
   46B4 02            [ 7]  306 	ld	(bc), a
   46B5 DD E1         [14]  307 	pop	ix
   46B7 C9            [10]  308 	ret
                            309 ;src/entity.c:66: u8 EntityCalculateDamage (TEntity *e)
                            310 ;	---------------------------------
                            311 ; Function EntityCalculateDamage
                            312 ; ---------------------------------
   46B8                     313 _EntityCalculateDamage::
                            314 ;src/entity.c:68: u8 dmg = e->atk >> 2;
   46B8 C1            [10]  315 	pop	bc
   46B9 E1            [10]  316 	pop	hl
   46BA E5            [11]  317 	push	hl
   46BB C5            [11]  318 	push	bc
   46BC 11 1D 00      [10]  319 	ld	de, #0x001d
   46BF 19            [11]  320 	add	hl, de
   46C0 4E            [ 7]  321 	ld	c, (hl)
   46C1 23            [ 6]  322 	inc	hl
   46C2 46            [ 7]  323 	ld	b, (hl)
   46C3 CB 38         [ 8]  324 	srl	b
   46C5 CB 19         [ 8]  325 	rr	c
   46C7 CB 38         [ 8]  326 	srl	b
   46C9 CB 19         [ 8]  327 	rr	c
                            328 ;src/entity.c:69: u8 r = (cpct_rand() * 7/255) - 3;
   46CB C5            [11]  329 	push	bc
   46CC CD 99 4D      [17]  330 	call	_cpct_getRandom_mxor_u8
   46CF C1            [10]  331 	pop	bc
   46D0 5D            [ 4]  332 	ld	e,l
   46D1 16 00         [ 7]  333 	ld	d,#0x00
   46D3 6B            [ 4]  334 	ld	l, e
   46D4 62            [ 4]  335 	ld	h, d
   46D5 29            [11]  336 	add	hl, hl
   46D6 19            [11]  337 	add	hl, de
   46D7 29            [11]  338 	add	hl, hl
   46D8 19            [11]  339 	add	hl, de
   46D9 C5            [11]  340 	push	bc
   46DA 11 FF 00      [10]  341 	ld	de, #0x00ff
   46DD D5            [11]  342 	push	de
   46DE E5            [11]  343 	push	hl
   46DF CD F0 4D      [17]  344 	call	__divsint
   46E2 F1            [10]  345 	pop	af
   46E3 F1            [10]  346 	pop	af
   46E4 C1            [10]  347 	pop	bc
   46E5 7D            [ 4]  348 	ld	a, l
   46E6 C6 FD         [ 7]  349 	add	a, #0xfd
                            350 ;src/entity.c:70: dmg += r;
   46E8 81            [ 4]  351 	add	a,c
                            352 ;src/entity.c:71: return (dmg < 127 ? dmg : dmg+3);
   46E9 FE 7F         [ 7]  353 	cp	a, #0x7f
   46EB 38 02         [12]  354 	jr	C,00104$
   46ED C6 03         [ 7]  355 	add	a, #0x03
   46EF                     356 00104$:
   46EF 6F            [ 4]  357 	ld	l, a
   46F0 C9            [10]  358 	ret
                            359 ;src/entity.c:76: void EntityTakeDamage (TEntity *e, u8 dmg)
                            360 ;	---------------------------------
                            361 ; Function EntityTakeDamage
                            362 ; ---------------------------------
   46F1                     363 _EntityTakeDamage::
   46F1 DD E5         [15]  364 	push	ix
   46F3 DD 21 00 00   [14]  365 	ld	ix,#0
   46F7 DD 39         [15]  366 	add	ix,sp
   46F9 F5            [11]  367 	push	af
                            368 ;src/entity.c:78: e->hp -= dmg;
   46FA DD 4E 04      [19]  369 	ld	c,4 (ix)
   46FD DD 46 05      [19]  370 	ld	b,5 (ix)
   4700 21 18 00      [10]  371 	ld	hl, #0x0018
   4703 09            [11]  372 	add	hl, bc
   4704 E5            [11]  373 	push	hl
   4705 7E            [ 7]  374 	ld	a, (hl)
   4706 DD 77 FE      [19]  375 	ld	-2 (ix), a
   4709 23            [ 6]  376 	inc	hl
   470A 7E            [ 7]  377 	ld	a, (hl)
   470B DD 77 FF      [19]  378 	ld	-1 (ix), a
   470E E1            [10]  379 	pop	hl
   470F DD 5E 06      [19]  380 	ld	e, 6 (ix)
   4712 16 00         [ 7]  381 	ld	d, #0x00
   4714 DD 7E FE      [19]  382 	ld	a, -2 (ix)
   4717 93            [ 4]  383 	sub	a, e
   4718 5F            [ 4]  384 	ld	e, a
   4719 DD 7E FF      [19]  385 	ld	a, -1 (ix)
   471C 9A            [ 4]  386 	sbc	a, d
   471D 57            [ 4]  387 	ld	d, a
   471E 73            [ 7]  388 	ld	(hl), e
   471F 23            [ 6]  389 	inc	hl
   4720 72            [ 7]  390 	ld	(hl), d
                            391 ;src/entity.c:79: PrintAt (1,23, e->name, 1);
   4721 21 06 00      [10]  392 	ld	hl, #0x0006
   4724 09            [11]  393 	add	hl, bc
   4725 3E 01         [ 7]  394 	ld	a, #0x01
   4727 F5            [11]  395 	push	af
   4728 33            [ 6]  396 	inc	sp
   4729 E5            [11]  397 	push	hl
   472A 21 01 17      [10]  398 	ld	hl, #0x1701
   472D E5            [11]  399 	push	hl
   472E CD D4 44      [17]  400 	call	_PrintAt
   4731 F1            [10]  401 	pop	af
   4732 F1            [10]  402 	pop	af
   4733 33            [ 6]  403 	inc	sp
                            404 ;src/entity.c:80: PrintAt (8,23, "takes     ", 2);
   4734 3E 02         [ 7]  405 	ld	a, #0x02
   4736 F5            [11]  406 	push	af
   4737 33            [ 6]  407 	inc	sp
   4738 21 6A 47      [10]  408 	ld	hl, #___str_0
   473B E5            [11]  409 	push	hl
   473C 21 08 17      [10]  410 	ld	hl, #0x1708
   473F E5            [11]  411 	push	hl
   4740 CD D4 44      [17]  412 	call	_PrintAt
   4743 F1            [10]  413 	pop	af
                            414 ;src/entity.c:81: PrintU8 (dmg, 14,23, 1);
   4744 33            [ 6]  415 	inc	sp
   4745 21 17 01      [10]  416 	ld	hl,#0x0117
   4748 E3            [19]  417 	ex	(sp),hl
   4749 3E 0E         [ 7]  418 	ld	a, #0x0e
   474B F5            [11]  419 	push	af
   474C 33            [ 6]  420 	inc	sp
   474D DD 7E 06      [19]  421 	ld	a, 6 (ix)
   4750 F5            [11]  422 	push	af
   4751 33            [ 6]  423 	inc	sp
   4752 CD 1F 45      [17]  424 	call	_PrintU8
   4755 F1            [10]  425 	pop	af
                            426 ;src/entity.c:82: PrintAt (17,23, "points of damage", 2);
   4756 26 02         [ 7]  427 	ld	h,#0x02
   4758 E3            [19]  428 	ex	(sp),hl
   4759 33            [ 6]  429 	inc	sp
   475A 21 75 47      [10]  430 	ld	hl, #___str_1
   475D E5            [11]  431 	push	hl
   475E 21 11 17      [10]  432 	ld	hl, #0x1711
   4761 E5            [11]  433 	push	hl
   4762 CD D4 44      [17]  434 	call	_PrintAt
   4765 DD F9         [10]  435 	ld	sp,ix
   4767 DD E1         [14]  436 	pop	ix
   4769 C9            [10]  437 	ret
   476A                     438 ___str_0:
   476A 74 61 6B 65 73 20   439 	.ascii "takes     "
        20 20 20 20
   4774 00                  440 	.db 0x00
   4775                     441 ___str_1:
   4775 70 6F 69 6E 74 73   442 	.ascii "points of damage"
        20 6F 66 20 64 61
        6D 61 67 65
   4785 00                  443 	.db 0x00
                            444 ;src/entity.c:87: void EntityAttack (TEntity *e, TEntity *target)
                            445 ;	---------------------------------
                            446 ; Function EntityAttack
                            447 ; ---------------------------------
   4786                     448 _EntityAttack::
   4786 DD E5         [15]  449 	push	ix
   4788 DD 21 00 00   [14]  450 	ld	ix,#0
   478C DD 39         [15]  451 	add	ix,sp
                            452 ;src/entity.c:91: PrintAt (1,22, e->name, 1);
   478E DD 5E 04      [19]  453 	ld	e,4 (ix)
   4791 DD 56 05      [19]  454 	ld	d,5 (ix)
   4794 21 06 00      [10]  455 	ld	hl, #0x0006
   4797 19            [11]  456 	add	hl, de
   4798 D5            [11]  457 	push	de
   4799 3E 01         [ 7]  458 	ld	a, #0x01
   479B F5            [11]  459 	push	af
   479C 33            [ 6]  460 	inc	sp
   479D E5            [11]  461 	push	hl
   479E 21 01 16      [10]  462 	ld	hl, #0x1601
   47A1 E5            [11]  463 	push	hl
   47A2 CD D4 44      [17]  464 	call	_PrintAt
   47A5 F1            [10]  465 	pop	af
   47A6 F1            [10]  466 	pop	af
   47A7 33            [ 6]  467 	inc	sp
   47A8 3E 02         [ 7]  468 	ld	a, #0x02
   47AA F5            [11]  469 	push	af
   47AB 33            [ 6]  470 	inc	sp
   47AC 21 E7 47      [10]  471 	ld	hl, #___str_2
   47AF E5            [11]  472 	push	hl
   47B0 21 0A 16      [10]  473 	ld	hl, #0x160a
   47B3 E5            [11]  474 	push	hl
   47B4 CD D4 44      [17]  475 	call	_PrintAt
   47B7 F1            [10]  476 	pop	af
   47B8 F1            [10]  477 	pop	af
   47B9 33            [ 6]  478 	inc	sp
   47BA D1            [10]  479 	pop	de
                            480 ;src/entity.c:93: PrintAt (23,22, target->name, 1);
   47BB DD 4E 06      [19]  481 	ld	c,6 (ix)
   47BE DD 46 07      [19]  482 	ld	b,7 (ix)
   47C1 21 06 00      [10]  483 	ld	hl, #0x0006
   47C4 09            [11]  484 	add	hl, bc
   47C5 C5            [11]  485 	push	bc
   47C6 D5            [11]  486 	push	de
   47C7 3E 01         [ 7]  487 	ld	a, #0x01
   47C9 F5            [11]  488 	push	af
   47CA 33            [ 6]  489 	inc	sp
   47CB E5            [11]  490 	push	hl
   47CC 21 17 16      [10]  491 	ld	hl, #0x1617
   47CF E5            [11]  492 	push	hl
   47D0 CD D4 44      [17]  493 	call	_PrintAt
   47D3 F1            [10]  494 	pop	af
   47D4 F1            [10]  495 	pop	af
   47D5 33            [ 6]  496 	inc	sp
   47D6 CD B8 46      [17]  497 	call	_EntityCalculateDamage
   47D9 F1            [10]  498 	pop	af
   47DA 55            [ 4]  499 	ld	d, l
   47DB C1            [10]  500 	pop	bc
                            501 ;src/entity.c:96: EntityTakeDamage (target, dmg);
   47DC D5            [11]  502 	push	de
   47DD 33            [ 6]  503 	inc	sp
   47DE C5            [11]  504 	push	bc
   47DF CD F1 46      [17]  505 	call	_EntityTakeDamage
   47E2 F1            [10]  506 	pop	af
   47E3 33            [ 6]  507 	inc	sp
   47E4 DD E1         [14]  508 	pop	ix
   47E6 C9            [10]  509 	ret
   47E7                     510 ___str_2:
   47E7 61 74 74 61 63 6B   511 	.ascii "attacks"
        73
   47EE 00                  512 	.db 0x00
                            513 ;src/entity.c:101: u8 GetBlockingEntity (TEntity *entities[], TEntity **out_e, u8 x, u8 y)
                            514 ;	---------------------------------
                            515 ; Function GetBlockingEntity
                            516 ; ---------------------------------
   47EF                     517 _GetBlockingEntity::
   47EF DD E5         [15]  518 	push	ix
   47F1 DD 21 00 00   [14]  519 	ld	ix,#0
   47F5 DD 39         [15]  520 	add	ix,sp
   47F7 F5            [11]  521 	push	af
                            522 ;src/entity.c:106: while ( (e=*entities++) != NULL) {
   47F8 DD 4E 04      [19]  523 	ld	c,4 (ix)
   47FB DD 46 05      [19]  524 	ld	b,5 (ix)
   47FE                     525 00105$:
   47FE 69            [ 4]  526 	ld	l, c
   47FF 60            [ 4]  527 	ld	h, b
   4800 5E            [ 7]  528 	ld	e, (hl)
   4801 23            [ 6]  529 	inc	hl
   4802 56            [ 7]  530 	ld	d, (hl)
   4803 03            [ 6]  531 	inc	bc
   4804 03            [ 6]  532 	inc	bc
   4805 33            [ 6]  533 	inc	sp
   4806 33            [ 6]  534 	inc	sp
   4807 D5            [11]  535 	push	de
   4808 7A            [ 4]  536 	ld	a, d
   4809 B3            [ 4]  537 	or	a,e
   480A 28 2E         [12]  538 	jr	Z,00107$
                            539 ;src/entity.c:107: if (e->blocks && e->x == x && e->y == y) {
   480C E1            [10]  540 	pop	hl
   480D E5            [11]  541 	push	hl
   480E 11 15 00      [10]  542 	ld	de, #0x0015
   4811 19            [11]  543 	add	hl, de
   4812 7E            [ 7]  544 	ld	a, (hl)
   4813 B7            [ 4]  545 	or	a, a
   4814 28 E8         [12]  546 	jr	Z,00105$
   4816 E1            [10]  547 	pop	hl
   4817 E5            [11]  548 	push	hl
   4818 DD 7E 08      [19]  549 	ld	a,8 (ix)
   481B 96            [ 7]  550 	sub	a,(hl)
   481C 20 E0         [12]  551 	jr	NZ,00105$
   481E E1            [10]  552 	pop	hl
   481F E5            [11]  553 	push	hl
   4820 23            [ 6]  554 	inc	hl
   4821 DD 7E 09      [19]  555 	ld	a,9 (ix)
   4824 96            [ 7]  556 	sub	a,(hl)
   4825 20 D7         [12]  557 	jr	NZ,00105$
                            558 ;src/entity.c:108: *out_e = e;
   4827 DD 4E 06      [19]  559 	ld	c,6 (ix)
   482A DD 46 07      [19]  560 	ld	b,7 (ix)
   482D DD 7E FE      [19]  561 	ld	a, -2 (ix)
   4830 02            [ 7]  562 	ld	(bc), a
   4831 03            [ 6]  563 	inc	bc
   4832 DD 7E FF      [19]  564 	ld	a, -1 (ix)
   4835 02            [ 7]  565 	ld	(bc), a
                            566 ;src/entity.c:109: return TRUE;
   4836 2E 01         [ 7]  567 	ld	l, #0x01
   4838 18 02         [12]  568 	jr	00108$
   483A                     569 00107$:
                            570 ;src/entity.c:112: return FALSE;
   483A 2E 00         [ 7]  571 	ld	l, #0x00
   483C                     572 00108$:
   483C DD F9         [10]  573 	ld	sp, ix
   483E DD E1         [14]  574 	pop	ix
   4840 C9            [10]  575 	ret
                            576 ;src/entity.c:117: void EntityDrawEntities (TEntity *entities[], u8 dirty[])
                            577 ;	---------------------------------
                            578 ; Function EntityDrawEntities
                            579 ; ---------------------------------
   4841                     580 _EntityDrawEntities::
   4841 DD E5         [15]  581 	push	ix
   4843 DD 21 00 00   [14]  582 	ld	ix,#0
   4847 DD 39         [15]  583 	add	ix,sp
   4849 F5            [11]  584 	push	af
                            585 ;src/entity.c:121: while ( (e=entities[i]) ) {
   484A 0E 00         [ 7]  586 	ld	c, #0x00
   484C                     587 00103$:
   484C 69            [ 4]  588 	ld	l, c
   484D 26 00         [ 7]  589 	ld	h, #0x00
   484F 29            [11]  590 	add	hl, hl
   4850 EB            [ 4]  591 	ex	de,hl
   4851 DD 6E 04      [19]  592 	ld	l,4 (ix)
   4854 DD 66 05      [19]  593 	ld	h,5 (ix)
   4857 19            [11]  594 	add	hl, de
   4858 5E            [ 7]  595 	ld	e, (hl)
   4859 23            [ 6]  596 	inc	hl
   485A 56            [ 7]  597 	ld	d, (hl)
   485B 33            [ 6]  598 	inc	sp
   485C 33            [ 6]  599 	inc	sp
   485D D5            [11]  600 	push	de
   485E 7A            [ 4]  601 	ld	a, d
   485F B3            [ 4]  602 	or	a,e
   4860 28 37         [12]  603 	jr	Z,00106$
                            604 ;src/entity.c:122: if (dirty[i]) {
   4862 DD 6E 06      [19]  605 	ld	l,6 (ix)
   4865 DD 66 07      [19]  606 	ld	h,7 (ix)
   4868 06 00         [ 7]  607 	ld	b, #0x00
   486A 09            [11]  608 	add	hl, bc
   486B 7E            [ 7]  609 	ld	a, (hl)
   486C B7            [ 4]  610 	or	a, a
   486D 28 16         [12]  611 	jr	Z,00102$
                            612 ;src/entity.c:123: EntityDraw (e, TRUE);
   486F E5            [11]  613 	push	hl
   4870 C5            [11]  614 	push	bc
   4871 3E 01         [ 7]  615 	ld	a, #0x01
   4873 F5            [11]  616 	push	af
   4874 33            [ 6]  617 	inc	sp
   4875 DD 5E FE      [19]  618 	ld	e,-2 (ix)
   4878 DD 56 FF      [19]  619 	ld	d,-1 (ix)
   487B D5            [11]  620 	push	de
   487C CD 25 46      [17]  621 	call	_EntityDraw
   487F F1            [10]  622 	pop	af
   4880 33            [ 6]  623 	inc	sp
   4881 C1            [10]  624 	pop	bc
   4882 E1            [10]  625 	pop	hl
                            626 ;src/entity.c:124: dirty[i] = FALSE;
   4883 36 00         [10]  627 	ld	(hl), #0x00
   4885                     628 00102$:
                            629 ;src/entity.c:126: EntityDraw (e, FALSE);
   4885 C5            [11]  630 	push	bc
   4886 AF            [ 4]  631 	xor	a, a
   4887 F5            [11]  632 	push	af
   4888 33            [ 6]  633 	inc	sp
   4889 DD 6E FE      [19]  634 	ld	l,-2 (ix)
   488C DD 66 FF      [19]  635 	ld	h,-1 (ix)
   488F E5            [11]  636 	push	hl
   4890 CD 25 46      [17]  637 	call	_EntityDraw
   4893 F1            [10]  638 	pop	af
   4894 33            [ 6]  639 	inc	sp
   4895 C1            [10]  640 	pop	bc
                            641 ;src/entity.c:127: ++i;
   4896 0C            [ 4]  642 	inc	c
   4897 18 B3         [12]  643 	jr	00103$
   4899                     644 00106$:
   4899 DD F9         [10]  645 	ld	sp, ix
   489B DD E1         [14]  646 	pop	ix
   489D C9            [10]  647 	ret
                            648 ;src/entity.c:133: void EntityPrintStats (TEntity *e)
                            649 ;	---------------------------------
                            650 ; Function EntityPrintStats
                            651 ; ---------------------------------
   489E                     652 _EntityPrintStats::
   489E DD E5         [15]  653 	push	ix
   48A0 DD 21 00 00   [14]  654 	ld	ix,#0
   48A4 DD 39         [15]  655 	add	ix,sp
                            656 ;src/entity.c:141: PrintAt (1,1, "i:UP, k:DN, j:LT, l:RT, s:WAIT", pen2);
   48A6 3E 02         [ 7]  657 	ld	a, #0x02
   48A8 F5            [11]  658 	push	af
   48A9 33            [ 6]  659 	inc	sp
   48AA 21 FB 49      [10]  660 	ld	hl, #___str_3
   48AD E5            [11]  661 	push	hl
   48AE 21 01 01      [10]  662 	ld	hl, #0x0101
   48B1 E5            [11]  663 	push	hl
   48B2 CD D4 44      [17]  664 	call	_PrintAt
   48B5 F1            [10]  665 	pop	af
   48B6 F1            [10]  666 	pop	af
   48B7 33            [ 6]  667 	inc	sp
                            668 ;src/entity.c:142: PrintAt (x,y, e->name, pen1); ++y;
   48B8 DD 4E 04      [19]  669 	ld	c,4 (ix)
   48BB DD 46 05      [19]  670 	ld	b,5 (ix)
   48BE 21 06 00      [10]  671 	ld	hl, #0x0006
   48C1 09            [11]  672 	add	hl, bc
   48C2 C5            [11]  673 	push	bc
   48C3 3E 01         [ 7]  674 	ld	a, #0x01
   48C5 F5            [11]  675 	push	af
   48C6 33            [ 6]  676 	inc	sp
   48C7 E5            [11]  677 	push	hl
   48C8 21 1E 04      [10]  678 	ld	hl, #0x041e
   48CB E5            [11]  679 	push	hl
   48CC CD D4 44      [17]  680 	call	_PrintAt
   48CF F1            [10]  681 	pop	af
   48D0 F1            [10]  682 	pop	af
   48D1 33            [ 6]  683 	inc	sp
   48D2 3E 01         [ 7]  684 	ld	a, #0x01
   48D4 F5            [11]  685 	push	af
   48D5 33            [ 6]  686 	inc	sp
   48D6 21 1A 4A      [10]  687 	ld	hl, #___str_4
   48D9 E5            [11]  688 	push	hl
   48DA 21 1E 05      [10]  689 	ld	hl, #0x051e
   48DD E5            [11]  690 	push	hl
   48DE CD D4 44      [17]  691 	call	_PrintAt
   48E1 F1            [10]  692 	pop	af
   48E2 F1            [10]  693 	pop	af
   48E3 33            [ 6]  694 	inc	sp
   48E4 C1            [10]  695 	pop	bc
   48E5 69            [ 4]  696 	ld	l, c
   48E6 60            [ 4]  697 	ld	h, b
   48E7 11 18 00      [10]  698 	ld	de, #0x0018
   48EA 19            [11]  699 	add	hl, de
   48EB 5E            [ 7]  700 	ld	e, (hl)
   48EC 23            [ 6]  701 	inc	hl
   48ED 56            [ 7]  702 	ld	d, (hl)
   48EE 53            [ 4]  703 	ld	d, e
   48EF C5            [11]  704 	push	bc
   48F0 21 05 02      [10]  705 	ld	hl, #0x0205
   48F3 E5            [11]  706 	push	hl
   48F4 3E 21         [ 7]  707 	ld	a, #0x21
   48F6 F5            [11]  708 	push	af
   48F7 33            [ 6]  709 	inc	sp
   48F8 D5            [11]  710 	push	de
   48F9 33            [ 6]  711 	inc	sp
   48FA CD 1F 45      [17]  712 	call	_PrintU8
   48FD F1            [10]  713 	pop	af
   48FE 26 01         [ 7]  714 	ld	h,#0x01
   4900 E3            [19]  715 	ex	(sp),hl
   4901 33            [ 6]  716 	inc	sp
   4902 21 24 4A      [10]  717 	ld	hl, #___str_5
   4905 E5            [11]  718 	push	hl
   4906 21 23 05      [10]  719 	ld	hl, #0x0523
   4909 E5            [11]  720 	push	hl
   490A CD D4 44      [17]  721 	call	_PrintAt
   490D F1            [10]  722 	pop	af
   490E F1            [10]  723 	pop	af
   490F 33            [ 6]  724 	inc	sp
   4910 C1            [10]  725 	pop	bc
   4911 69            [ 4]  726 	ld	l, c
   4912 60            [ 4]  727 	ld	h, b
   4913 11 16 00      [10]  728 	ld	de, #0x0016
   4916 19            [11]  729 	add	hl, de
   4917 5E            [ 7]  730 	ld	e, (hl)
   4918 23            [ 6]  731 	inc	hl
   4919 56            [ 7]  732 	ld	d, (hl)
   491A 53            [ 4]  733 	ld	d, e
   491B C5            [11]  734 	push	bc
   491C 21 05 02      [10]  735 	ld	hl, #0x0205
   491F E5            [11]  736 	push	hl
   4920 3E 24         [ 7]  737 	ld	a, #0x24
   4922 F5            [11]  738 	push	af
   4923 33            [ 6]  739 	inc	sp
   4924 D5            [11]  740 	push	de
   4925 33            [ 6]  741 	inc	sp
   4926 CD 1F 45      [17]  742 	call	_PrintU8
   4929 F1            [10]  743 	pop	af
   492A 26 01         [ 7]  744 	ld	h,#0x01
   492C E3            [19]  745 	ex	(sp),hl
   492D 33            [ 6]  746 	inc	sp
   492E 21 26 4A      [10]  747 	ld	hl, #___str_6
   4931 E5            [11]  748 	push	hl
   4932 21 1E 07      [10]  749 	ld	hl, #0x071e
   4935 E5            [11]  750 	push	hl
   4936 CD D4 44      [17]  751 	call	_PrintAt
   4939 F1            [10]  752 	pop	af
   493A F1            [10]  753 	pop	af
   493B 33            [ 6]  754 	inc	sp
   493C C1            [10]  755 	pop	bc
   493D C5            [11]  756 	push	bc
   493E FD E1         [14]  757 	pop	iy
   4940 FD 56 1A      [19]  758 	ld	d, 26 (iy)
   4943 C5            [11]  759 	push	bc
   4944 21 07 02      [10]  760 	ld	hl, #0x0207
   4947 E5            [11]  761 	push	hl
   4948 3E 22         [ 7]  762 	ld	a, #0x22
   494A F5            [11]  763 	push	af
   494B 33            [ 6]  764 	inc	sp
   494C D5            [11]  765 	push	de
   494D 33            [ 6]  766 	inc	sp
   494E CD 1F 45      [17]  767 	call	_PrintU8
   4951 F1            [10]  768 	pop	af
   4952 26 01         [ 7]  769 	ld	h,#0x01
   4954 E3            [19]  770 	ex	(sp),hl
   4955 33            [ 6]  771 	inc	sp
   4956 21 2B 4A      [10]  772 	ld	hl, #___str_7
   4959 E5            [11]  773 	push	hl
   495A 21 1E 08      [10]  774 	ld	hl, #0x081e
   495D E5            [11]  775 	push	hl
   495E CD D4 44      [17]  776 	call	_PrintAt
   4961 F1            [10]  777 	pop	af
   4962 F1            [10]  778 	pop	af
   4963 33            [ 6]  779 	inc	sp
   4964 C1            [10]  780 	pop	bc
   4965 C5            [11]  781 	push	bc
   4966 FD E1         [14]  782 	pop	iy
   4968 FD 56 1B      [19]  783 	ld	d, 27 (iy)
   496B C5            [11]  784 	push	bc
   496C 21 08 02      [10]  785 	ld	hl, #0x0208
   496F E5            [11]  786 	push	hl
   4970 3E 22         [ 7]  787 	ld	a, #0x22
   4972 F5            [11]  788 	push	af
   4973 33            [ 6]  789 	inc	sp
   4974 D5            [11]  790 	push	de
   4975 33            [ 6]  791 	inc	sp
   4976 CD 1F 45      [17]  792 	call	_PrintU8
   4979 F1            [10]  793 	pop	af
   497A 26 01         [ 7]  794 	ld	h,#0x01
   497C E3            [19]  795 	ex	(sp),hl
   497D 33            [ 6]  796 	inc	sp
   497E 21 30 4A      [10]  797 	ld	hl, #___str_8
   4981 E5            [11]  798 	push	hl
   4982 21 1E 09      [10]  799 	ld	hl, #0x091e
   4985 E5            [11]  800 	push	hl
   4986 CD D4 44      [17]  801 	call	_PrintAt
   4989 F1            [10]  802 	pop	af
   498A F1            [10]  803 	pop	af
   498B 33            [ 6]  804 	inc	sp
   498C C1            [10]  805 	pop	bc
   498D C5            [11]  806 	push	bc
   498E FD E1         [14]  807 	pop	iy
   4990 FD 56 1C      [19]  808 	ld	d, 28 (iy)
   4993 C5            [11]  809 	push	bc
   4994 21 09 02      [10]  810 	ld	hl, #0x0209
   4997 E5            [11]  811 	push	hl
   4998 3E 22         [ 7]  812 	ld	a, #0x22
   499A F5            [11]  813 	push	af
   499B 33            [ 6]  814 	inc	sp
   499C D5            [11]  815 	push	de
   499D 33            [ 6]  816 	inc	sp
   499E CD 1F 45      [17]  817 	call	_PrintU8
   49A1 F1            [10]  818 	pop	af
   49A2 26 01         [ 7]  819 	ld	h,#0x01
   49A4 E3            [19]  820 	ex	(sp),hl
   49A5 33            [ 6]  821 	inc	sp
   49A6 21 35 4A      [10]  822 	ld	hl, #___str_9
   49A9 E5            [11]  823 	push	hl
   49AA 21 1E 0B      [10]  824 	ld	hl, #0x0b1e
   49AD E5            [11]  825 	push	hl
   49AE CD D4 44      [17]  826 	call	_PrintAt
   49B1 F1            [10]  827 	pop	af
   49B2 F1            [10]  828 	pop	af
   49B3 33            [ 6]  829 	inc	sp
   49B4 C1            [10]  830 	pop	bc
   49B5 69            [ 4]  831 	ld	l, c
   49B6 60            [ 4]  832 	ld	h, b
   49B7 11 1D 00      [10]  833 	ld	de, #0x001d
   49BA 19            [11]  834 	add	hl, de
   49BB 5E            [ 7]  835 	ld	e, (hl)
   49BC 23            [ 6]  836 	inc	hl
   49BD 56            [ 7]  837 	ld	d, (hl)
   49BE 53            [ 4]  838 	ld	d, e
   49BF C5            [11]  839 	push	bc
   49C0 21 0B 02      [10]  840 	ld	hl, #0x020b
   49C3 E5            [11]  841 	push	hl
   49C4 3E 22         [ 7]  842 	ld	a, #0x22
   49C6 F5            [11]  843 	push	af
   49C7 33            [ 6]  844 	inc	sp
   49C8 D5            [11]  845 	push	de
   49C9 33            [ 6]  846 	inc	sp
   49CA CD 1F 45      [17]  847 	call	_PrintU8
   49CD F1            [10]  848 	pop	af
   49CE 26 01         [ 7]  849 	ld	h,#0x01
   49D0 E3            [19]  850 	ex	(sp),hl
   49D1 33            [ 6]  851 	inc	sp
   49D2 21 3A 4A      [10]  852 	ld	hl, #___str_10
   49D5 E5            [11]  853 	push	hl
   49D6 21 1E 0C      [10]  854 	ld	hl, #0x0c1e
   49D9 E5            [11]  855 	push	hl
   49DA CD D4 44      [17]  856 	call	_PrintAt
   49DD F1            [10]  857 	pop	af
   49DE F1            [10]  858 	pop	af
   49DF 33            [ 6]  859 	inc	sp
   49E0 E1            [10]  860 	pop	hl
   49E1 11 1F 00      [10]  861 	ld	de, #0x001f
   49E4 19            [11]  862 	add	hl, de
   49E5 4E            [ 7]  863 	ld	c, (hl)
   49E6 23            [ 6]  864 	inc	hl
   49E7 46            [ 7]  865 	ld	b, (hl)
   49E8 41            [ 4]  866 	ld	b, c
   49E9 21 0C 02      [10]  867 	ld	hl, #0x020c
   49EC E5            [11]  868 	push	hl
   49ED 3E 22         [ 7]  869 	ld	a, #0x22
   49EF F5            [11]  870 	push	af
   49F0 33            [ 6]  871 	inc	sp
   49F1 C5            [11]  872 	push	bc
   49F2 33            [ 6]  873 	inc	sp
   49F3 CD 1F 45      [17]  874 	call	_PrintU8
   49F6 F1            [10]  875 	pop	af
   49F7 F1            [10]  876 	pop	af
   49F8 DD E1         [14]  877 	pop	ix
   49FA C9            [10]  878 	ret
   49FB                     879 ___str_3:
   49FB 69 3A 55 50 2C 20   880 	.ascii "i:UP, k:DN, j:LT, l:RT, s:WAIT"
        6B 3A 44 4E 2C 20
        6A 3A 4C 54 2C 20
        6C 3A 52 54 2C 20
        73 3A 57 41 49 54
   4A19 00                  881 	.db 0x00
   4A1A                     882 ___str_4:
   4A1A 48 50 3A 20 20 20   883 	.ascii "HP:      "
        20 20 20
   4A23 00                  884 	.db 0x00
   4A24                     885 ___str_5:
   4A24 2F                  886 	.ascii "/"
   4A25 00                  887 	.db 0x00
   4A26                     888 ___str_6:
   4A26 53 54 52 3A         889 	.ascii "STR:"
   4A2A 00                  890 	.db 0x00
   4A2B                     891 ___str_7:
   4A2B 44 45 53 3A         892 	.ascii "DES:"
   4A2F 00                  893 	.db 0x00
   4A30                     894 ___str_8:
   4A30 52 45 46 3A         895 	.ascii "REF:"
   4A34 00                  896 	.db 0x00
   4A35                     897 ___str_9:
   4A35 41 54 4B 3A         898 	.ascii "ATK:"
   4A39 00                  899 	.db 0x00
   4A3A                     900 ___str_10:
   4A3A 44 45 46 3A         901 	.ascii "DEF:"
   4A3E 00                  902 	.db 0x00
                            903 	.area _CODE
                            904 	.area _INITIALIZER
                            905 	.area _CABS (ABS)
