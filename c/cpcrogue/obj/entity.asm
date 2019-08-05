;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module entity
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _EntityTakeDamage
	.globl _EntityCalculateDamage
	.globl _PrintU8
	.globl _PrintAt
	.globl _pen
	.globl _locate
	.globl _cpct_getRandom_mxor_u8
	.globl _putchar
	.globl _EntityInit
	.globl _EntityDraw
	.globl _EntityMove
	.globl _EntityAttack
	.globl _GetBlockingEntity
	.globl _EntityDrawEntities
	.globl _EntityPrintStats
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/entity.c:12: void EntityInit (TEntity *e, u8 x, u8 y, u8 spr, u8 color, u8 name[],
;	---------------------------------
; Function EntityInit
; ---------------------------------
_EntityInit::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;src/entity.c:15: e->x = e->px = x;  // current posX
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	ld	a, 6 (ix)
	ld	(de), a
	ld	a, 6 (ix)
	ld	(bc), a
;src/entity.c:16: e->y = e->py = y;  // current posY
	ld	e, c
	ld	d, b
	inc	de
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	inc	hl
	ld	a, 7 (ix)
	ld	(hl), a
	ld	a, 7 (ix)
	ld	(de), a
;src/entity.c:17: e->spr =spr;
	ld	hl, #0x0004
	add	hl, bc
	ld	a, 8 (ix)
	ld	(hl), a
;src/entity.c:18: e->color = color;
	ld	hl, #0x0005
	add	hl, bc
	ld	a, 9 (ix)
	ld	(hl), a
;src/entity.c:19: strcpy (e->name, name);
	ld	hl, #0x0006
	add	hl,bc
	ex	de,hl
	push	bc
	ld	l,10 (ix)
	ld	h,11 (ix)
	xor	a, a
00103$:
	cp	a, (hl)
	ldi
	jr	NZ, 00103$
	pop	bc
;src/entity.c:20: e->blocks = blocks;
	ld	hl, #0x0015
	add	hl, bc
	ld	a, 12 (ix)
	ld	(hl), a
;src/entity.c:22: e->max_hp = hp;
	ld	hl, #0x0016
	add	hl, bc
	ld	a, 13 (ix)
	ld	(hl), a
	inc	hl
	ld	a, 14 (ix)
	ld	(hl), a
;src/entity.c:23: e->hp = hp;
	ld	hl, #0x0018
	add	hl, bc
	ld	a, 13 (ix)
	ld	(hl), a
	inc	hl
	ld	a, 14 (ix)
	ld	(hl), a
;src/entity.c:24: e->str = str;
	ld	hl, #0x001a
	add	hl, bc
	ld	a, 15 (ix)
	ld	(hl), a
;src/entity.c:25: e->des = destr;
	ld	hl, #0x001b
	add	hl, bc
	ld	a, 16 (ix)
	ld	(hl), a
;src/entity.c:26: e->ref = refl;
	ld	hl, #0x001c
	add	hl, bc
	ld	a, 17 (ix)
	ld	(hl), a
;src/entity.c:28: e->atk = (str  + destr)>>1;
	ld	hl, #0x001d
	add	hl, bc
	ld	e, 15 (ix)
	ld	d, #0x00
	ld	a, 16 (ix)
	ld	-2 (ix), a
	ld	-1 (ix), #0x00
	ld	a, e
	add	a, -2 (ix)
	ld	e, a
	ld	a, d
	adc	a, -1 (ix)
	ld	d, a
	sra	d
	rr	e
	ld	(hl), e
	inc	hl
	ld	(hl), d
;src/entity.c:29: e->def = (destr + refl)>>1;
	ld	hl, #0x001f
	add	hl, bc
	ld	c, 17 (ix)
	ld	b, #0x00
	ld	a, -2 (ix)
	add	a, c
	ld	c, a
	ld	a, -1 (ix)
	adc	a, b
	ld	b, a
	sra	b
	rr	c
	ld	(hl), c
	inc	hl
	ld	(hl), b
	ld	sp, ix
	pop	ix
	ret
;src/entity.c:34: void EntityDraw (struct TEntity *e, u8 erase)
;	---------------------------------
; Function EntityDraw
; ---------------------------------
_EntityDraw::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;src/entity.c:38: x = e->px;
	ld	c,4 (ix)
	ld	b,5 (ix)
;src/entity.c:37: if (erase) {
	ld	a, 6 (ix)
	or	a, a
	jr	Z,00102$
;src/entity.c:38: x = e->px;
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	ld	e, (hl)
;src/entity.c:39: y = e->py;
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	inc	hl
	ld	d, (hl)
;src/entity.c:40: color = PEN_TILE;
	ld	-1 (ix), #0x02
;src/entity.c:41: spr = SPR_FLOOR;
	ld	c, #0x2e
	jr	00103$
00102$:
;src/entity.c:44: x = e->x;
	ld	a, (bc)
	ld	e, a
;src/entity.c:45: y = e->y;
	ld	l, c
	ld	h, b
	inc	hl
	ld	d, (hl)
;src/entity.c:46: color = e->color;
	push	bc
	pop	iy
	ld	a, 5 (iy)
	ld	-1 (ix), a
;src/entity.c:47: spr = e->spr;
	ld	l, c
	ld	h, b
	ld	bc, #0x0004
	add	hl, bc
	ld	c, (hl)
00103$:
;src/entity.c:49: pen (color);
	push	bc
	push	de
	ld	a, -1 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	pop	de
	pop	bc
;src/entity.c:50: locate (PLAY_X+x, PLAY_Y+y);
	inc	d
	inc	d
	ld	b, e
	inc	b
	push	bc
	ld	e, b
	push	de
	call	_locate
	pop	af
	pop	bc
;src/entity.c:51: putchar (spr);
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	inc	sp
	pop	ix
	ret
;src/entity.c:56: void EntityMove (TEntity *e, i8 dx, i8 dy)
;	---------------------------------
; Function EntityMove
; ---------------------------------
_EntityMove::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/entity.c:58: e->px = e->x;     // Save old positions
	ld	e,4 (ix)
	ld	d,5 (ix)
	ld	c, e
	ld	b, d
	inc	bc
	inc	bc
	ld	a, (de)
	ld	(bc), a
;src/entity.c:59: e->py = e->y;
	push	de
	pop	iy
	inc	iy
	inc	iy
	inc	iy
	ld	c, e
	ld	b, d
	inc	bc
	ld	a, (bc)
	ld	0 (iy), a
;src/entity.c:60: e->x  = e->x+dx;   // Update to new position
	ld	a, (de)
	add	a, 6 (ix)
	ld	(de), a
;src/entity.c:61: e->y  = e->y+dy;
	ld	a, (bc)
	add	a, 7 (ix)
	ld	(bc), a
	pop	ix
	ret
;src/entity.c:66: u8 EntityCalculateDamage (TEntity *e)
;	---------------------------------
; Function EntityCalculateDamage
; ---------------------------------
_EntityCalculateDamage::
;src/entity.c:68: u8 dmg = e->atk >> 2;
	pop	bc
	pop	hl
	push	hl
	push	bc
	ld	de, #0x001d
	add	hl, de
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	srl	b
	rr	c
	srl	b
	rr	c
;src/entity.c:69: u8 r = (cpct_rand() * 7/255) - 3;
	push	bc
	call	_cpct_getRandom_mxor_u8
	pop	bc
	ld	e,l
	ld	d,#0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	push	bc
	ld	de, #0x00ff
	push	de
	push	hl
	call	__divsint
	pop	af
	pop	af
	pop	bc
	ld	a, l
	add	a, #0xfd
;src/entity.c:70: dmg += r;
	add	a,c
;src/entity.c:71: return (dmg < 127 ? dmg : dmg+3);
	cp	a, #0x7f
	jr	C,00104$
	add	a, #0x03
00104$:
	ld	l, a
	ret
;src/entity.c:76: void EntityTakeDamage (TEntity *e, u8 dmg)
;	---------------------------------
; Function EntityTakeDamage
; ---------------------------------
_EntityTakeDamage::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;src/entity.c:78: e->hp -= dmg;
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	hl, #0x0018
	add	hl, bc
	push	hl
	ld	a, (hl)
	ld	-2 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-1 (ix), a
	pop	hl
	ld	e, 6 (ix)
	ld	d, #0x00
	ld	a, -2 (ix)
	sub	a, e
	ld	e, a
	ld	a, -1 (ix)
	sbc	a, d
	ld	d, a
	ld	(hl), e
	inc	hl
	ld	(hl), d
;src/entity.c:79: PrintAt (1,23, e->name, 1);
	ld	hl, #0x0006
	add	hl, bc
	ld	a, #0x01
	push	af
	inc	sp
	push	hl
	ld	hl, #0x1701
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/entity.c:80: PrintAt (8,23, "takes     ", 2);
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	ld	hl, #0x1708
	push	hl
	call	_PrintAt
	pop	af
;src/entity.c:81: PrintU8 (dmg, 14,23, 1);
	inc	sp
	ld	hl,#0x0117
	ex	(sp),hl
	ld	a, #0x0e
	push	af
	inc	sp
	ld	a, 6 (ix)
	push	af
	inc	sp
	call	_PrintU8
	pop	af
;src/entity.c:82: PrintAt (17,23, "points of damage", 2);
	ld	h,#0x02
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_1
	push	hl
	ld	hl, #0x1711
	push	hl
	call	_PrintAt
	ld	sp,ix
	pop	ix
	ret
___str_0:
	.ascii "takes     "
	.db 0x00
___str_1:
	.ascii "points of damage"
	.db 0x00
;src/entity.c:87: void EntityAttack (TEntity *e, TEntity *target)
;	---------------------------------
; Function EntityAttack
; ---------------------------------
_EntityAttack::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/entity.c:91: PrintAt (1,22, e->name, 1);
	ld	e,4 (ix)
	ld	d,5 (ix)
	ld	hl, #0x0006
	add	hl, de
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	push	hl
	ld	hl, #0x1601
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	ld	hl, #0x160a
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	de
;src/entity.c:93: PrintAt (23,22, target->name, 1);
	ld	c,6 (ix)
	ld	b,7 (ix)
	ld	hl, #0x0006
	add	hl, bc
	push	bc
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	push	hl
	ld	hl, #0x1617
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	call	_EntityCalculateDamage
	pop	af
	ld	d, l
	pop	bc
;src/entity.c:96: EntityTakeDamage (target, dmg);
	push	de
	inc	sp
	push	bc
	call	_EntityTakeDamage
	pop	af
	inc	sp
	pop	ix
	ret
___str_2:
	.ascii "attacks"
	.db 0x00
;src/entity.c:101: u8 GetBlockingEntity (TEntity *entities[], TEntity **out_e, u8 x, u8 y)
;	---------------------------------
; Function GetBlockingEntity
; ---------------------------------
_GetBlockingEntity::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;src/entity.c:106: while ( (e=*entities++) != NULL) {
	ld	c,4 (ix)
	ld	b,5 (ix)
00105$:
	ld	l, c
	ld	h, b
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	inc	bc
	inc	bc
	inc	sp
	inc	sp
	push	de
	ld	a, d
	or	a,e
	jr	Z,00107$
;src/entity.c:107: if (e->blocks && e->x == x && e->y == y) {
	pop	hl
	push	hl
	ld	de, #0x0015
	add	hl, de
	ld	a, (hl)
	or	a, a
	jr	Z,00105$
	pop	hl
	push	hl
	ld	a,8 (ix)
	sub	a,(hl)
	jr	NZ,00105$
	pop	hl
	push	hl
	inc	hl
	ld	a,9 (ix)
	sub	a,(hl)
	jr	NZ,00105$
;src/entity.c:108: *out_e = e;
	ld	c,6 (ix)
	ld	b,7 (ix)
	ld	a, -2 (ix)
	ld	(bc), a
	inc	bc
	ld	a, -1 (ix)
	ld	(bc), a
;src/entity.c:109: return TRUE;
	ld	l, #0x01
	jr	00108$
00107$:
;src/entity.c:112: return FALSE;
	ld	l, #0x00
00108$:
	ld	sp, ix
	pop	ix
	ret
;src/entity.c:117: void EntityDrawEntities (TEntity *entities[], u8 dirty[])
;	---------------------------------
; Function EntityDrawEntities
; ---------------------------------
_EntityDrawEntities::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;src/entity.c:121: while ( (e=entities[i]) ) {
	ld	c, #0x00
00103$:
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	ex	de,hl
	ld	l,4 (ix)
	ld	h,5 (ix)
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	inc	sp
	inc	sp
	push	de
	ld	a, d
	or	a,e
	jr	Z,00106$
;src/entity.c:122: if (dirty[i]) {
	ld	l,6 (ix)
	ld	h,7 (ix)
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	or	a, a
	jr	Z,00102$
;src/entity.c:123: EntityDraw (e, TRUE);
	push	hl
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	ld	e,-2 (ix)
	ld	d,-1 (ix)
	push	de
	call	_EntityDraw
	pop	af
	inc	sp
	pop	bc
	pop	hl
;src/entity.c:124: dirty[i] = FALSE;
	ld	(hl), #0x00
00102$:
;src/entity.c:126: EntityDraw (e, FALSE);
	push	bc
	xor	a, a
	push	af
	inc	sp
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	push	hl
	call	_EntityDraw
	pop	af
	inc	sp
	pop	bc
;src/entity.c:127: ++i;
	inc	c
	jr	00103$
00106$:
	ld	sp, ix
	pop	ix
	ret
;src/entity.c:133: void EntityPrintStats (TEntity *e)
;	---------------------------------
; Function EntityPrintStats
; ---------------------------------
_EntityPrintStats::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/entity.c:141: PrintAt (1,1, "i:UP, k:DN, j:LT, l:RT, s:WAIT", pen2);
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_3
	push	hl
	ld	hl, #0x0101
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/entity.c:142: PrintAt (x,y, e->name, pen1); ++y;
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	hl, #0x0006
	add	hl, bc
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	push	hl
	ld	hl, #0x041e
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #___str_4
	push	hl
	ld	hl, #0x051e
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
	ld	l, c
	ld	h, b
	ld	de, #0x0018
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	d, e
	push	bc
	ld	hl, #0x0205
	push	hl
	ld	a, #0x21
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_5
	push	hl
	ld	hl, #0x0523
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
	ld	l, c
	ld	h, b
	ld	de, #0x0016
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	d, e
	push	bc
	ld	hl, #0x0205
	push	hl
	ld	a, #0x24
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_6
	push	hl
	ld	hl, #0x071e
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
	push	bc
	pop	iy
	ld	d, 26 (iy)
	push	bc
	ld	hl, #0x0207
	push	hl
	ld	a, #0x22
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_7
	push	hl
	ld	hl, #0x081e
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
	push	bc
	pop	iy
	ld	d, 27 (iy)
	push	bc
	ld	hl, #0x0208
	push	hl
	ld	a, #0x22
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_8
	push	hl
	ld	hl, #0x091e
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
	push	bc
	pop	iy
	ld	d, 28 (iy)
	push	bc
	ld	hl, #0x0209
	push	hl
	ld	a, #0x22
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_9
	push	hl
	ld	hl, #0x0b1e
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
	ld	l, c
	ld	h, b
	ld	de, #0x001d
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	d, e
	push	bc
	ld	hl, #0x020b
	push	hl
	ld	a, #0x22
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_10
	push	hl
	ld	hl, #0x0c1e
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	hl
	ld	de, #0x001f
	add	hl, de
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	b, c
	ld	hl, #0x020c
	push	hl
	ld	a, #0x22
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_PrintU8
	pop	af
	pop	af
	pop	ix
	ret
___str_3:
	.ascii "i:UP, k:DN, j:LT, l:RT, s:WAIT"
	.db 0x00
___str_4:
	.ascii "HP:      "
	.db 0x00
___str_5:
	.ascii "/"
	.db 0x00
___str_6:
	.ascii "STR:"
	.db 0x00
___str_7:
	.ascii "DES:"
	.db 0x00
___str_8:
	.ascii "REF:"
	.db 0x00
___str_9:
	.ascii "ATK:"
	.db 0x00
___str_10:
	.ascii "DEF:"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
