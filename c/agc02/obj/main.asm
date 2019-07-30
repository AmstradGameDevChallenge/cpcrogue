;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _TakeDamage
	.globl _CalculateDamage
	.globl _ClearStatusLine
	.globl _PrintCharacterStats
	.globl _InitColors
	.globl _draw_map
	.globl _InitEntities
	.globl _InitializeCharacter
	.globl _PrintAt
	.globl _cls
	.globl _pen
	.globl _paper
	.globl _border
	.globl _ink
	.globl _locate
	.globl _map_create
	.globl _putchar
	.globl _sprintf
	.globl _printf
	.globl _cpct_getRandom_mxor_u8
	.globl _cpct_setVideoMode
	.globl _cpct_isKeyPressed
	.globl _cpct_scanKeyboard
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
;src/main.c:99: void map_create (struct TMap *map, u8 width, u8 height)
;	---------------------------------
; Function map_create
; ---------------------------------
_map_create::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-6
	add	hl, sp
	ld	sp, hl
;src/main.c:103: map->width = width;
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	a, 6 (ix)
	ld	(bc), a
;src/main.c:104: map->height = height;
	push	bc
	pop	iy
	inc	iy
	ld	a, 7 (ix)
	ld	0 (iy), a
;src/main.c:105: for (i=0; i!=map->height; ++i)
	ld	hl, #0x0002
	add	hl,bc
	ld	-4 (ix), l
	ld	-3 (ix), h
	ld	-6 (ix), #0x00
00107$:
	ld	e, 0 (iy)
	ld	a, -6 (ix)
	sub	a, e
	jr	Z,00102$
;src/main.c:106: for (j=0; j!=map->width; ++j)
	ld	e,-6 (ix)
	ld	d,#0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	ld	a, -4 (ix)
	add	a, l
	ld	-2 (ix), a
	ld	a, -3 (ix)
	adc	a, h
	ld	-1 (ix), a
	ld	-5 (ix), #0x00
00104$:
	ld	a, (bc)
	ld	e, a
	ld	a, -5 (ix)
	sub	a, e
	jr	Z,00108$
;src/main.c:107: map->tiles[i][j].blocked = FALSE;
	ld	a, -2 (ix)
	add	a, -5 (ix)
	ld	e, a
	ld	a, -1 (ix)
	adc	a, #0x00
	ld	d, a
	xor	a, a
	ld	(de), a
;src/main.c:106: for (j=0; j!=map->width; ++j)
	inc	-5 (ix)
	jr	00104$
00108$:
;src/main.c:105: for (i=0; i!=map->height; ++i)
	inc	-6 (ix)
	jr	00107$
00102$:
;src/main.c:110: map->tiles[12][3].blocked = TRUE;
	ld	hl, #0x00f5
	add	hl, bc
	ld	(hl), #0x01
;src/main.c:111: map->tiles[3][10].blocked = TRUE;
	ld	hl, #0x0048
	add	hl, bc
	ld	(hl), #0x01
	ld	sp, ix
	pop	ix
	ret
;src/main.c:117: void locate (u8 x, u8 y)
;	---------------------------------
; Function locate
; ---------------------------------
_locate::
;src/main.c:119: putchar(US);
	ld	hl, #0x001f
	push	hl
	call	_putchar
	pop	af
;src/main.c:120: putchar (x); putchar (y);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ld	hl, #3+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:122: void ink (u8 tinta, u8 color1, u8 color2)
;	---------------------------------
; Function ink
; ---------------------------------
_ink::
;src/main.c:124: putchar (FS);
	ld	hl, #0x001c
	push	hl
	call	_putchar
	pop	af
;src/main.c:125: putchar (tinta); putchar (color1); putchar (color2);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ld	hl, #3+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ld	hl, #4+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:127: void border (u8 color1, u8 color2)
;	---------------------------------
; Function border
; ---------------------------------
_border::
;src/main.c:129: putchar (GS);
	ld	hl, #0x001d
	push	hl
	call	_putchar
	pop	af
;src/main.c:130: putchar (color1); putchar (color2);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ld	hl, #3+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:132: void paper (u8 color1)
;	---------------------------------
; Function paper
; ---------------------------------
_paper::
;src/main.c:134: putchar (SO);
	ld	hl, #0x000e
	push	hl
	call	_putchar
	pop	af
;src/main.c:135: putchar (color1);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:137: void pen (u8 tinta)
;	---------------------------------
; Function pen
; ---------------------------------
_pen::
;src/main.c:139: putchar (SI);
	ld	hl, #0x000f
	push	hl
	call	_putchar
	pop	af
;src/main.c:140: putchar (tinta);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:142: void cls () { putchar (FF); }
;	---------------------------------
; Function cls
; ---------------------------------
_cls::
	ld	hl, #0x000c
	push	hl
	call	_putchar
	pop	af
	ret
;src/main.c:147: void PrintAt (u8 x, u8 y, char text[], u8 color)
;	---------------------------------
; Function PrintAt
; ---------------------------------
_PrintAt::
;src/main.c:149: locate (x, y);
	ld	hl, #3+0
	add	hl, sp
	ld	a, (hl)
	push	af
	inc	sp
	ld	hl, #3+0
	add	hl, sp
	ld	a, (hl)
	push	af
	inc	sp
	call	_locate
	pop	af
;src/main.c:150: if (color != 0xff) pen (color);
	ld	iy, #6
	add	iy, sp
	ld	a, 0 (iy)
	inc	a
	jr	Z,00102$
	ld	a, 0 (iy)
	push	af
	inc	sp
	call	_pen
	inc	sp
00102$:
;src/main.c:151: printf (text);
	ld	hl, #4
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	call	_printf
	pop	af
	ret
;src/main.c:156: void InitializeCharacter (struct TCharacter *c,
;	---------------------------------
; Function InitializeCharacter
; ---------------------------------
_InitializeCharacter::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-10
	add	hl, sp
	ld	sp, hl
;src/main.c:160: c->x = x; c->y = y;
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	a, 6 (ix)
	ld	(bc), a
	ld	e, c
	ld	d, b
	inc	de
	ld	a, 7 (ix)
	ld	(de), a
;src/main.c:161: strcpy (c->spr, spr);
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	push	bc
	ld	l,8 (ix)
	ld	h,9 (ix)
	xor	a, a
00103$:
	cp	a, (hl)
	ldi
	jr	NZ, 00103$
	pop	bc
;src/main.c:162: c->color = color;
	ld	hl, #0x0004
	add	hl, bc
	ld	a, 10 (ix)
	ld	(hl), a
;src/main.c:163: strcpy (c->name, name);
	ld	hl, #0x0005
	add	hl,bc
	ex	de,hl
	push	bc
	ld	l,11 (ix)
	ld	h,12 (ix)
	xor	a, a
00104$:
	cp	a, (hl)
	ldi
	jr	NZ, 00104$
	pop	bc
;src/main.c:165: c->hp = hp;
	ld	hl, #0x0014
	add	hl, bc
	ld	a, 13 (ix)
	ld	(hl), a
	inc	hl
	ld	a, 14 (ix)
	ld	(hl), a
;src/main.c:166: c->str = str;
	ld	hl, #0x0016
	add	hl, bc
	ld	a, 15 (ix)
	ld	(hl), a
;src/main.c:167: c->destr = destr;
	ld	hl, #0x0017
	add	hl, bc
	ld	a, 16 (ix)
	ld	(hl), a
;src/main.c:168: c->refl = refl;
	ld	hl, #0x0018
	add	hl, bc
	ld	a, 17 (ix)
	ld	(hl), a
;src/main.c:170: c->atk = 1.5 * c->str + c->destr;
	ld	hl, #0x0019
	add	hl,bc
	ld	-2 (ix), l
	ld	-1 (ix), h
	push	bc
	ld	a, 15 (ix)
	push	af
	inc	sp
	call	___uchar2fs
	inc	sp
	ex	de, hl
	push	hl
	push	de
	ld	hl, #0x3fc0
	push	hl
	ld	hl, #0x0000
	push	hl
	call	___fsmul
	pop	af
	pop	af
	pop	af
	pop	af
	ld	-3 (ix), d
	ld	-4 (ix), e
	ld	-5 (ix), h
	ld	-6 (ix), l
	pop	bc
	ld	e, 16 (ix)
	ld	d, #0x00
	push	bc
	push	de
	call	___sint2fs
	pop	af
	ex	de, hl
	push	hl
	push	de
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	hl
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	push	hl
	call	___fsadd
	pop	af
	pop	af
	pop	af
	pop	af
	push	de
	push	hl
	call	___fs2uint
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;src/main.c:171: c->defense = 1.5 * c->destr + c->refl;
	ld	hl, #0x001b
	add	hl,bc
	ld	-6 (ix), l
	ld	-5 (ix), h
	ld	a, 16 (ix)
	push	af
	inc	sp
	call	___uchar2fs
	inc	sp
	ex	de, hl
	push	hl
	push	de
	ld	hl, #0x3fc0
	push	hl
	ld	hl, #0x0000
	push	hl
	call	___fsmul
	pop	af
	pop	af
	pop	af
	pop	af
	ld	-7 (ix), d
	ld	-8 (ix), e
	ld	-9 (ix), h
	ld	-10 (ix), l
	ld	c, 17 (ix)
	ld	b, #0x00
	push	bc
	call	___sint2fs
	pop	af
	ex	de, hl
	push	hl
	push	de
	ld	l,-8 (ix)
	ld	h,-7 (ix)
	push	hl
	ld	l,-10 (ix)
	ld	h,-9 (ix)
	push	hl
	call	___fsadd
	pop	af
	pop	af
	pop	af
	pop	af
	push	de
	push	hl
	call	___fs2uint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
	ld	sp, ix
	pop	ix
	ret
;src/main.c:177: void InitEntities (struct TCharacter* entities[])
;	---------------------------------
; Function InitEntities
; ---------------------------------
_InitEntities::
;src/main.c:180: do {
	ld	c, #0x04
00101$:
;src/main.c:181: entities[i--] = NULL;
	ld	e, c
	dec	c
	ld	a, e
	rla
	sbc	a, a
	ld	d, a
	sla	e
	rl	d
	ld	iy, #2
	add	iy, sp
	ld	a, 0 (iy)
	add	a, e
	ld	b, a
	ld	a, 1 (iy)
	adc	a, d
	ld	h, a
	ld	l, b
	xor	a, a
	ld	(hl), a
	inc	hl
	ld	(hl), a
;src/main.c:182: } while (i != 0);
	ld	a, c
	or	a, a
	jr	NZ,00101$
;src/main.c:183: entities[0] = NULL;
	pop	bc
	pop	hl
	push	hl
	push	bc
	xor	a, a
	ld	(hl), a
	inc	hl
	ld	(hl), a
	ret
;src/main.c:188: void draw_map (struct TMap *map)
;	---------------------------------
; Function draw_map
; ---------------------------------
_draw_map::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-9
	add	hl, sp
	ld	sp, hl
;src/main.c:194: for (i=0; i!=map->height; ++i) {
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	-4 (ix), c
	ld	-3 (ix), b
	ld	de, #0x0000
00110$:
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	inc	hl
	ld	l, (hl)
	ld	-6 (ix), l
	ld	-5 (ix), #0x00
	ld	a, -6 (ix)
	sub	a, e
	jr	NZ,00136$
	ld	a, -5 (ix)
	sub	a, d
	jp	Z,00112$
00136$:
;src/main.c:195: for (j=0; j!=map->width; ++j) {
	ld	hl, #0x0002
	add	hl,bc
	ld	-6 (ix), l
	ld	-5 (ix), h
	push	de
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	pop	de
	ld	a, -6 (ix)
	add	a, l
	ld	-6 (ix), a
	ld	a, -5 (ix)
	adc	a, h
	ld	-5 (ix), a
	ld	-8 (ix), #0x00
	ld	-7 (ix), #0x00
00107$:
	ld	a, (bc)
	ld	-2 (ix), a
	ld	-1 (ix), #0x00
	ld	a, -8 (ix)
	sub	a, -2 (ix)
	jr	NZ,00137$
	ld	a, -7 (ix)
	sub	a, -1 (ix)
	jr	Z,00111$
00137$:
;src/main.c:196: is_wall = map->tiles[i][j].blocked;
	ld	a, -6 (ix)
	add	a, -8 (ix)
	ld	l, a
	ld	a, -5 (ix)
	adc	a, -7 (ix)
	ld	h, a
	ld	a, (hl)
	ld	-9 (ix), a
;src/main.c:199: PrintAt (PLAY_X+j,PLAY_Y+i, "#", PEN_TILE);
	ld	h, e
	ld	l, -8 (ix)
	inc	h
	inc	h
	inc	h
	inc	h
	inc	l
	inc	l
	inc	l
	inc	l
;src/main.c:198: if (is_wall) {
	ld	a, -9 (ix)
	or	a, a
	jr	Z,00102$
;src/main.c:199: PrintAt (PLAY_X+j,PLAY_Y+i, "#", PEN_TILE);
	ld	iy, #___str_0
	push	bc
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	push	iy
	push	hl
	inc	sp
	ld	a, l
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	de
	pop	bc
	jr	00108$
00102$:
;src/main.c:202: PrintAt (PLAY_X+j,PLAY_Y+i, ".", PEN_TILE);
	ld	iy, #___str_1
	push	bc
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	push	iy
	push	hl
	inc	sp
	ld	a, l
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	de
	pop	bc
00108$:
;src/main.c:195: for (j=0; j!=map->width; ++j) {
	inc	-8 (ix)
	jr	NZ,00107$
	inc	-7 (ix)
	jr	00107$
00111$:
;src/main.c:194: for (i=0; i!=map->height; ++i) {
	inc	de
	jp	00110$
00112$:
	ld	sp, ix
	pop	ix
	ret
___str_0:
	.ascii "#"
	.db 0x00
___str_1:
	.ascii "."
	.db 0x00
;src/main.c:223: void InitColors()
;	---------------------------------
; Function InitColors
; ---------------------------------
_InitColors::
;src/main.c:225: ink (0, 0,0);
	ld	hl, #0x0000
	push	hl
	xor	a, a
	push	af
	inc	sp
	call	_ink
;src/main.c:226: border (0,0); paper (0);
	inc	sp
	ld	hl,#0x0000
	ex	(sp),hl
	call	_border
	pop	af
	xor	a, a
	push	af
	inc	sp
	call	_paper
	inc	sp
;src/main.c:228: ink (PEN_ENTITY, INK_ENTITY, INK_ENTITY);
	ld	hl, #0x1414
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_ink
;src/main.c:229: ink (PEN_TILE, INK_LIGHT_TILE, INK_LIGHT_TILE);
	inc	sp
	ld	hl,#0x0d0d
	ex	(sp),hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_ink
;src/main.c:230: ink (PEN_EXLORED, INK_DARK_TILE, INK_DARK_TILE);
	inc	sp
	ld	hl,#0x0101
	ex	(sp),hl
	ld	a, #0x03
	push	af
	inc	sp
	call	_ink
	pop	af
	inc	sp
	ret
;src/main.c:236: void PrintCharacterStats (struct TCharacter *c, u8 y,
;	---------------------------------
; Function PrintCharacterStats
; ---------------------------------
_PrintCharacterStats::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-14
	add	hl, sp
	ld	sp, hl
;src/main.c:240: PrintAt (10,y, c->name, color1); PrintAt (21,y, c->spr, color2);
	ld	a, 4 (ix)
	ld	-2 (ix), a
	ld	a, 5 (ix)
	ld	-1 (ix), a
	ld	a, -2 (ix)
	add	a, #0x05
	ld	c, a
	ld	a, -1 (ix)
	adc	a, #0x00
	ld	b, a
	ld	a, 7 (ix)
	push	af
	inc	sp
	push	bc
	ld	d, 6 (ix)
	ld	e,#0x0a
	push	de
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	ld	c,-2 (ix)
	ld	b,-1 (ix)
	inc	bc
	inc	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	bc
	ld	d, 6 (ix)
	ld	e,#0x15
	push	de
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:241: PrintAt (1, y+1, "STR ",color1);
	ld	b, 6 (ix)
	inc	b
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	push	bc
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:242: PrintAt (10,y+1, "DES ",color1);
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_3
	push	hl
	push	bc
	inc	sp
	ld	a, #0x0a
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:243: PrintAt (20,y+1, "REF ",color1);
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_4
	push	hl
	push	bc
	inc	sp
	ld	a, #0x14
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:244: sprintf (num, "[%d] ", c->str);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0016
	add	hl, de
	ld	e, (hl)
	ld	d, #0x00
	ld	hl, #0x0000
	add	hl, sp
	ld	-4 (ix), l
	ld	-3 (ix), h
	push	bc
	push	de
	ld	de, #___str_5
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:245: PrintAt (5,y+1, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x05
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:246: sprintf (num, "[%d] ", c->destr);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0017
	add	hl, de
	ld	e, (hl)
	ld	d, #0x00
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_5
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:247: PrintAt (15,y+1, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x0f
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:248: sprintf (num, "[%d] ", c->refl);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0018
	add	hl, de
	ld	e, (hl)
	ld	d, #0x00
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_5
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:249: PrintAt (25,y+1, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x19
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:251: PrintAt (1, y+2, "ATK ", color1);
	ld	b, 6 (ix)
	inc	b
	inc	b
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_6
	push	hl
	push	bc
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:252: PrintAt (10,y+2, "DEF ", color1);
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_7
	push	hl
	push	bc
	inc	sp
	ld	a, #0x0a
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:253: PrintAt (20,y+2, " HP ", color1);
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_8
	push	hl
	push	bc
	inc	sp
	ld	a, #0x14
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:254: sprintf (num, "[%d] ", c->atk);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0019
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_5
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:255: PrintAt (5,y+2, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x05
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:256: sprintf (num, "[%d] ",c->defense);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x001b
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_5
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:257: PrintAt (15,y+2, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x0f
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:258: sprintf (num, "[%d]\r\n", c->hp);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0014
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_9
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:259: PrintAt (25,y+2, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x19
	push	af
	inc	sp
	call	_PrintAt
	ld	sp,ix
	pop	ix
	ret
___str_2:
	.ascii "STR "
	.db 0x00
___str_3:
	.ascii "DES "
	.db 0x00
___str_4:
	.ascii "REF "
	.db 0x00
___str_5:
	.ascii "[%d] "
	.db 0x00
___str_6:
	.ascii "ATK "
	.db 0x00
___str_7:
	.ascii "DEF "
	.db 0x00
___str_8:
	.ascii " HP "
	.db 0x00
___str_9:
	.ascii "[%d]"
	.db 0x0d
	.db 0x0a
	.db 0x00
;src/main.c:264: void ClearStatusLine()
;	---------------------------------
; Function ClearStatusLine
; ---------------------------------
_ClearStatusLine::
;src/main.c:267: for (row = 20; row <=23; ++row) {
	ld	b, #0x14
00102$:
;src/main.c:268: PrintAt (1,row, "                                        ", 0xff);
	push	bc
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_10
	push	hl
	push	bc
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:267: for (row = 20; row <=23; ++row) {
	inc	b
	ld	a, #0x17
	sub	a, b
	jr	NC,00102$
	ret
___str_10:
	.ascii "                                        "
	.db 0x00
;src/main.c:274: u8 CalculateDamage (struct TCharacter *c)
;	---------------------------------
; Function CalculateDamage
; ---------------------------------
_CalculateDamage::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:276: return (c->atk*c->atk)/(5*c->defense);
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	l, c
	ld	h, b
	ld	de, #0x0019
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	bc
	push	de
	push	de
	call	__mulint
	pop	af
	pop	af
	ex	de,hl
	pop	hl
	ld	bc, #0x001b
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	push	hl
	push	de
	call	__divuint
	pop	af
	pop	af
	pop	ix
	ret
;src/main.c:281: void TakeDamage (struct TCharacter *c, u8 dmg)
;	---------------------------------
; Function TakeDamage
; ---------------------------------
_TakeDamage::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:283: c->hp -= dmg;
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	hl, #0x0014
	add	hl, bc
	push	hl
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	pop	hl
	ld	e, 6 (ix)
	ld	d, #0x00
	ld	a, c
	sub	a, e
	ld	c, a
	ld	a, b
	sbc	a, d
	ld	b, a
	ld	(hl), c
	inc	hl
	ld	(hl), b
	pop	ix
	ret
;src/main.c:288: void main(void) {
;	---------------------------------
; Function main
; ---------------------------------
_main::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-345
	add	hl, sp
	ld	sp, hl
;src/main.c:303: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
	ld	hl, #0x0000
	push	hl
	xor	a, a
	push	af
	inc	sp
	call	_ink
	inc	sp
	ld	hl,#0x0000
	ex	(sp),hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_ink
	inc	sp
	ld	hl,#0x0000
	ex	(sp),hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_ink
	pop	af
	inc	sp
;src/main.c:304: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
	ld	l, #0x01
	call	_cpct_setVideoMode
;src/main.c:305: border (1,1); paper (0); pen (1);
	ld	hl, #0x0101
	push	hl
	call	_border
	pop	af
	xor	a, a
	push	af
	inc	sp
	call	_paper
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	call	_pen
	inc	sp
;src/main.c:307: PrintAt (1,5, "      )   ___    _____    )   ___      ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_11
	push	hl
	ld	hl, #0x0501
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:308: PrintAt (1,6, "     (__/_____) (, /   ) (__/_____)    ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_12
	push	hl
	ld	hl, #0x0601
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:309: PrintAt (1,7, "       /         _/__ /    /           ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_13
	push	hl
	ld	hl, #0x0701
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:310: PrintAt (1,8, "      /          /        /            ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_14
	push	hl
	ld	hl, #0x0801
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:311: PrintAt (1,9, "     (______) ) /        (______)      ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_15
	push	hl
	ld	hl, #0x0901
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:312: PrintAt (1,10, "            _(_/_                      ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_16
	push	hl
	ld	hl, #0x0a01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:313: PrintAt (1,11, "           (, /   )                    ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_17
	push	hl
	ld	hl, #0x0b01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:314: PrintAt (1,12, "             /__ / ___      _          ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_18
	push	hl
	ld	hl, #0x0c01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:317: PrintAt (1,13, "          ) /   \\_(_(_/(_(_(/_         ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_19
	push	hl
	ld	hl, #0x0d01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:318: PrintAt (1,14, "         (_/       .-/                 ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_20
	push	hl
	ld	hl, #0x0e01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:319: PrintAt (1,15, "                  (_/                  ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_21
	push	hl
	ld	hl, #0x0f01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:320: PrintAt (10, 18, "PRESS ENTER TO START", 2);
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_22
	push	hl
	ld	hl, #0x120a
	push	hl
	call	_PrintAt
	pop	af
;src/main.c:321: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);
	inc	sp
	ld	hl,#0x0303
	ex	(sp),hl
	xor	a, a
	push	af
	inc	sp
	call	_ink
	inc	sp
	ld	hl,#0x0f06
	ex	(sp),hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_ink
	inc	sp
	ld	hl,#0x1010
	ex	(sp),hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_ink
	inc	sp
	ld	hl,#0x0303
	ex	(sp),hl
	call	_border
	pop	af
;src/main.c:324: while (!cpct_isKeyPressed (Key_Return)) {
00101$:
	ld	hl, #0x0402
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	NZ,00103$
;src/main.c:325: cpct_scanKeyboard ();
	call	_cpct_scanKeyboard
	jr	00101$
00103$:
;src/main.c:329: InitColors();
	call	_InitColors
;src/main.c:331: cls();
	call	_cls
;src/main.c:335: SPR_PLAYER, PEN_ENTITY, "Player",
	ld	de, #___str_23+0
;src/main.c:334: InitializeCharacter (&player, 3, 3,
	ld	hl, #0x001d
	add	hl, sp
	ld	-5 (ix), l
	ld	-4 (ix), h
	ld	c, l
	ld	b, h
	ld	hl, #0x0c0e
	push	hl
	ld	a, #0x11
	push	af
	inc	sp
	ld	hl, #0x0096
	push	hl
	ld	hl, #___str_24
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	push	de
	ld	hl, #0x0303
	push	hl
	push	bc
	call	_InitializeCharacter
	ld	hl, #14
	add	hl, sp
	ld	sp, hl
;src/main.c:339: SPR_GOBLIN, PEN_ENTITY, "Goblin",
	ld	de, #___str_25+0
;src/main.c:338: InitializeCharacter (&goblin, 12, 3,
	ld	hl, #0x0000
	add	hl, sp
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	c, l
	ld	b, h
	ld	hl, #0x0b0d
	push	hl
	ld	a, #0x0c
	push	af
	inc	sp
	ld	hl, #0x0064
	push	hl
	ld	hl, #___str_26
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	push	de
	ld	hl, #0x030c
	push	hl
	push	bc
	call	_InitializeCharacter
	ld	hl, #14
	add	hl, sp
	ld	sp, hl
;src/main.c:348: map_create (&game_map, MAP_WIDTH, MAP_HEIGHT);
	ld	hl, #0x003a
	add	hl, sp
	ld	c, l
	ld	b, h
	push	hl
	ld	de, #0x0e14
	push	de
	push	bc
	call	_map_create
	pop	af
	pop	af
	call	_draw_map
	pop	af
;src/main.c:352: do {
00111$:
;src/main.c:353: PrintCharacterStats (&player, 1, 1, 1);
	ld	c,-5 (ix)
	ld	b,-4 (ix)
	ld	hl, #0x0101
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	push	bc
	call	_PrintCharacterStats
	pop	af
	pop	af
	inc	sp
;src/main.c:354: PrintAt (PLAY_X+player.x, PLAY_Y+player.y, player.spr, player.color);
	ld	l,-5 (ix)
	ld	h,-4 (ix)
	ld	de, #0x0004
	add	hl, de
	ld	b, (hl)
	ld	e,-5 (ix)
	ld	d,-4 (ix)
	inc	de
	inc	de
	ld	l,-5 (ix)
	ld	h,-4 (ix)
	inc	hl
	ld	c, (hl)
	inc	c
	inc	c
	inc	c
	inc	c
	ld	l,-5 (ix)
	ld	h,-4 (ix)
	ld	a, (hl)
	add	a, #0x04
	ld	-3 (ix), a
	push	bc
	inc	sp
	push	de
	ld	a, c
	push	af
	inc	sp
	ld	a, -3 (ix)
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:355: PrintAt (PLAY_X+goblin.x, PLAY_Y+goblin.y, goblin.spr, goblin.color);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0004
	add	hl, de
	ld	b, (hl)
	ld	e,-2 (ix)
	ld	d,-1 (ix)
	inc	de
	inc	de
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	inc	hl
	ld	c, (hl)
	inc	c
	inc	c
	inc	c
	inc	c
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	a, (hl)
	add	a, #0x04
	ld	-3 (ix), a
	push	bc
	inc	sp
	push	de
	ld	a, c
	push	af
	inc	sp
	ld	a, -3 (ix)
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:359: cpct_scanKeyboard();
	call	_cpct_scanKeyboard
;src/main.c:360: while (!cpct_isKeyPressed (Key_A)) {
00104$:
	ld	hl, #0x2008
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	NZ,00106$
;src/main.c:361: cpct_scanKeyboard();
	call	_cpct_scanKeyboard
	jr	00104$
00106$:
;src/main.c:364: ClearStatusLine();
	call	_ClearStatusLine
;src/main.c:366: if (cpct_isKeyPressed (Key_A)) {
	ld	hl, #0x2008
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00108$
;src/main.c:367: dmg=CalculateDamage (&player);
	ld	c,-5 (ix)
	ld	b,-4 (ix)
	push	bc
	call	_CalculateDamage
	pop	af
	ld	b, l
;src/main.c:368: TakeDamage (&goblin, dmg);
	ld	e,-2 (ix)
	ld	d,-1 (ix)
	push	bc
	push	bc
	inc	sp
	push	de
	call	_TakeDamage
	inc	sp
	ld	hl,#0x1501
	ex	(sp),hl
	call	_locate
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	pop	bc
	ld	de, #___str_27
	push	bc
	push	de
	call	_printf
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	pop	bc
	ld	c, b
	ld	b, #0x00
	push	bc
	ld	hl, #___str_28
	push	hl
	call	_printf
	pop	af
;src/main.c:371: pen (1); printf (" hit points");
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_29
	push	hl
	call	_printf
	pop	af
00108$:
;src/main.c:374: if (cpct_rand() < 64) {
	call	_cpct_getRandom_mxor_u8
	ld	a, l
	sub	a, #0x40
	jp	NC, 00111$
;src/main.c:375: dmg=CalculateDamage (&goblin);
	ld	c,-2 (ix)
	ld	b,-1 (ix)
	push	bc
	call	_CalculateDamage
	pop	af
	ld	b, l
;src/main.c:376: TakeDamage (&player, dmg);
	ld	e,-5 (ix)
	ld	d,-4 (ix)
	push	bc
	push	bc
	inc	sp
	push	de
	call	_TakeDamage
	inc	sp
	ld	hl,#0x1601
	ex	(sp),hl
	call	_locate
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_30
	push	hl
	call	_printf
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	pop	bc
	ld	c, b
	ld	b, #0x00
	push	bc
	ld	hl, #___str_28
	push	hl
	call	_printf
	pop	af
;src/main.c:379: pen (1); printf (" hit points from goblin");
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_31
	push	hl
	call	_printf
	pop	af
;src/main.c:382: } while (1);
	jp	00111$
___str_11:
	.ascii "      )   ___    _____    )   ___      "
	.db 0x00
___str_12:
	.ascii "     (__/_____) (, /   ) (__/_____)    "
	.db 0x00
___str_13:
	.ascii "       /         _/__ /    /           "
	.db 0x00
___str_14:
	.ascii "      /          /        /            "
	.db 0x00
___str_15:
	.ascii "     (______) ) /        (______)      "
	.db 0x00
___str_16:
	.ascii "            _(_/_                      "
	.db 0x00
___str_17:
	.ascii "           (, /   )                    "
	.db 0x00
___str_18:
	.ascii "             /__ / ___      _          "
	.db 0x00
___str_19:
	.ascii "          ) /   "
	.db 0x5c
	.ascii "_(_(_/(_(_(/_         "
	.db 0x00
___str_20:
	.ascii "         (_/       .-/                 "
	.db 0x00
___str_21:
	.ascii "                  (_/                  "
	.db 0x00
___str_22:
	.ascii "PRESS ENTER TO START"
	.db 0x00
___str_23:
	.ascii "@"
	.db 0x00
___str_24:
	.ascii "Player"
	.db 0x00
___str_25:
	.ascii "g"
	.db 0x00
___str_26:
	.ascii "Goblin"
	.db 0x00
___str_27:
	.ascii "goblin takes "
	.db 0x00
___str_28:
	.ascii "%d"
	.db 0x00
___str_29:
	.ascii " hit points"
	.db 0x00
___str_30:
	.ascii "you take "
	.db 0x00
___str_31:
	.ascii " hit points from goblin"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
