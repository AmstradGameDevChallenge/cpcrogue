;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module game_map
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _pen
	.globl _locate
	.globl _putchar
	.globl _game_map
	.globl _MapCreate
	.globl _MapIsBlocked
	.globl _MapDraw
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_game_map::
	.ds 506
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
;src/game_map.c:9: void MapCreate (u8 width, u8 height)
;	---------------------------------
; Function MapCreate
; ---------------------------------
_MapCreate::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/game_map.c:13: game_map.width = width;
	ld	hl, #_game_map
	ld	a, 4 (ix)
	ld	(hl), a
;src/game_map.c:14: game_map.height = height;
	ld	hl, #(_game_map + 0x0001)
	ld	a, 5 (ix)
	ld	(hl), a
;src/game_map.c:15: for (i=0; i < height; ++i)
	ld	c, #0x00
00107$:
	ld	a, c
	sub	a, 5 (ix)
	jr	NC,00102$
;src/game_map.c:16: for (j=0; j < width; ++j)
	ld	b,#0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	ex	de,hl
	ld	hl, #(_game_map + 0x0002)
	add	hl,de
	ex	de,hl
	ld	b, #0x00
00104$:
	ld	a, b
	sub	a, 4 (ix)
	jr	NC,00108$
;src/game_map.c:17: game_map.tiles[i][j].blocked = FALSE;
	ld	l,b
	ld	h,#0x00
	add	hl, de
	ld	(hl), #0x00
;src/game_map.c:16: for (j=0; j < width; ++j)
	inc	b
	jr	00104$
00108$:
;src/game_map.c:15: for (i=0; i < height; ++i)
	inc	c
	jr	00107$
00102$:
;src/game_map.c:20: game_map.tiles[12][3].blocked = TRUE;
	ld	hl, #(_game_map + 0x0155)
	ld	(hl), #0x01
;src/game_map.c:21: game_map.tiles[3][16].blocked = TRUE;
	ld	hl, #(_game_map + 0x0066)
	ld	(hl), #0x01
	pop	ix
	ret
;src/game_map.c:24: u8 MapIsBlocked (u8 x, u8 y)
;	---------------------------------
; Function MapIsBlocked
; ---------------------------------
_MapIsBlocked::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/game_map.c:26: return game_map.tiles[y][x].blocked;
	ld	c,5 (ix)
	ld	b,#0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	ld	de, #(_game_map + 0x0002)
	add	hl, de
	ld	e, 4 (ix)
	ld	d,#0x00
	add	hl, de
	ld	l, (hl)
	pop	ix
	ret
;src/game_map.c:29: void MapDraw ()
;	---------------------------------
; Function MapDraw
; ---------------------------------
_MapDraw::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
	dec	sp
;src/game_map.c:36: for (i=0; i < game_map.height; ++i) {
	ld	-4 (ix), #0x00
00110$:
	ld	hl, #_game_map + 1
	ld	a,-4 (ix)
	sub	a,(hl)
	jr	NC,00112$
;src/game_map.c:37: for (j=0; j < game_map.width; ++j) {
	ld	a, -4 (ix)
	add	a, #0x02
	ld	-3 (ix), a
	ld	bc, #_game_map + 2
	ld	e,-4 (ix)
	ld	d,#0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl,bc
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	-5 (ix), #0x00
00107$:
	ld	hl, #_game_map + 0
	ld	c, (hl)
	ld	a, -5 (ix)
	sub	a, c
	jr	NC,00111$
;src/game_map.c:38: locate (PLAY_X+j,PLAY_Y+i);
	ld	b, -5 (ix)
	inc	b
	inc	b
	ld	a, -3 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_locate
	pop	af
;src/game_map.c:39: is_wall = game_map.tiles[i][j].blocked;
	ld	a, -2 (ix)
	add	a, -5 (ix)
	ld	l, a
	ld	a, -1 (ix)
	adc	a, #0x00
	ld	h, a
	ld	c, (hl)
;src/game_map.c:40: pen (PEN_TILE);
	push	bc
	ld	a, #0x03
	push	af
	inc	sp
	call	_pen
	inc	sp
	pop	bc
;src/game_map.c:41: if (is_wall) {
	ld	a, c
	or	a, a
	jr	Z,00102$
;src/game_map.c:42: putchar(SPR_WALL);
	ld	hl, #0x0023
	push	hl
	call	_putchar
	pop	af
	jr	00108$
00102$:
;src/game_map.c:45: putchar (SPR_FLOOR);
	ld	hl, #0x002e
	push	hl
	call	_putchar
	pop	af
00108$:
;src/game_map.c:37: for (j=0; j < game_map.width; ++j) {
	inc	-5 (ix)
	jr	00107$
00111$:
;src/game_map.c:36: for (i=0; i < game_map.height; ++i) {
	inc	-4 (ix)
	jp	00110$
00112$:
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
