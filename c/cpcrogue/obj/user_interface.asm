;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module user_interface
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl __DrawLines
	.globl __DrawLine
	.globl _DrawSingleChars
	.globl _PrintU8
	.globl _PrintAt
	.globl _pen
	.globl _ink
	.globl _locate
	.globl _putchar
	.globl _hud
	.globl _DrawHUD
	.globl _DisplayLoading
	.globl _ClearStatus
	.globl _PrintStats
	.globl _DrawLine
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
;src/user_interface.c:27: u8 DrawSingleChars ()
;	---------------------------------
; Function DrawSingleChars
; ---------------------------------
_DrawSingleChars::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
;src/user_interface.c:35: i=0;
	ld	c, #0x00
;src/user_interface.c:36: while ( (ch = hud[i++]) != 255) {
	ld	de, #_hud+0
00102$:
	ld	l, c
	inc	c
	ld	h,#0x00
	add	hl, de
	ld	b, (hl)
	ld	-1 (ix), b
	inc	b
	jr	Z,00104$
;src/user_interface.c:37: color = hud[i++];
	ld	a,c
	ld	b,a
	inc	a
	ld	-2 (ix), a
	ld	l,b
	ld	h,#0x00
	add	hl, de
	ld	b, (hl)
;src/user_interface.c:38: reps = hud[i++];
	ld	l, -2 (ix)
	ld	c, -2 (ix)
	inc	c
	ld	h,#0x00
	add	hl, de
	ld	a, (hl)
	ld	-3 (ix), a
;src/user_interface.c:39: pen(color);
	push	bc
	push	de
	push	bc
	inc	sp
	call	_pen
	inc	sp
	pop	de
	pop	bc
;src/user_interface.c:41: for (u8 n=0; n<reps; ++n) {
	ld	-4 (ix), #0x00
00106$:
	ld	a, -4 (ix)
	sub	a, -3 (ix)
	jr	NC,00102$
;src/user_interface.c:42: x=hud[i++];
	ld	a,c
	ld	b,a
	inc	a
	ld	-2 (ix), a
	ld	l,b
	ld	h,#0x00
	add	hl, de
	ld	b, (hl)
;src/user_interface.c:43: y=hud[i++];
	ld	l, -2 (ix)
	ld	c, -2 (ix)
	inc	c
	ld	h,#0x00
	add	hl, de
	ld	h, (hl)
;src/user_interface.c:44: locate (x,y);
	push	bc
	push	de
	push	hl
	inc	sp
	push	bc
	inc	sp
	call	_locate
	pop	af
	pop	de
	pop	bc
;src/user_interface.c:45: putchar (ch);
	ld	l, -1 (ix)
	ld	h, #0x00
	push	bc
	push	de
	push	hl
	call	_putchar
	pop	af
	pop	de
	pop	bc
;src/user_interface.c:41: for (u8 n=0; n<reps; ++n) {
	inc	-4 (ix)
	jr	00106$
00104$:
;src/user_interface.c:48: return i;
	ld	l, c
	ld	sp, ix
	pop	ix
	ret
_hud:
	.db #0xe9	; 233
	.db #0x02	; 2
	.db #0x08	; 8
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x1e	; 30
	.db #0x01	; 1
	.db #0x28	; 40
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x14	; 20
	.db #0x1e	; 30
	.db #0x14	; 20
	.db #0x28	; 40
	.db #0x14	; 20
	.db #0x01	; 1
	.db #0x19	; 25
	.db #0x28	; 40
	.db #0x19	; 25
	.db #0x9a	; 154
	.db #0x02	; 2
	.db #0x0c	; 12
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x0a	; 10
	.db #0x01	; 1
	.db #0x15	; 21
	.db #0x01	; 1
	.db #0x1d	; 29
	.db #0x01	; 1
	.db #0x1f	; 31
	.db #0x01	; 1
	.db #0x27	; 39
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x14	; 20
	.db #0x1d	; 29
	.db #0x14	; 20
	.db #0x1f	; 31
	.db #0x14	; 20
	.db #0x27	; 39
	.db #0x14	; 20
	.db #0x02	; 2
	.db #0x19	; 25
	.db #0x27	; 39
	.db #0x19	; 25
	.db #0x95	; 149
	.db #0x02	; 2
	.db #0x0a	; 10
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x1e	; 30
	.db #0x02	; 2
	.db #0x28	; 40
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x13	; 19
	.db #0x01	; 1
	.db #0x15	; 21
	.db #0x1e	; 30
	.db #0x13	; 19
	.db #0x28	; 40
	.db #0x13	; 19
	.db #0x28	; 40
	.db #0x15	; 21
	.db #0x01	; 1
	.db #0x18	; 24
	.db #0x28	; 40
	.db #0x18	; 24
	.db #0x9d	; 157
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x0b	; 11
	.db #0x01	; 1
	.db #0x97	; 151
	.db #0x02	; 2
	.db #0x01	; 1
	.db #0x14	; 20
	.db #0x01	; 1
	.db #0xff	; 255
	.db #0x9a	; 154
	.db #0x03	; 3
	.db #0x01	; 1
	.db #0x06	; 6
	.db #0x03	; 3
	.db #0x01	; 1
	.db #0x07	; 7
	.db #0x16	; 22
	.db #0x01	; 1
	.db #0x08	; 8
	.db #0x20	; 32
	.db #0x01	; 1
	.db #0x07	; 7
	.db #0x03	; 3
	.db #0x14	; 20
	.db #0x1a	; 26
	.db #0x20	; 32
	.db #0x14	; 20
	.db #0x07	; 7
	.db #0x03	; 3
	.db #0x19	; 25
	.db #0x24	; 36
	.db #0x95	; 149
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0x05	; 5
	.db #0x01	; 1
	.db #0x03	; 3
	.db #0x10	; 16
	.db #0x1e	; 30
	.db #0x03	; 3
	.db #0x10	; 16
	.db #0x28	; 40
	.db #0x03	; 3
	.db #0x10	; 16
	.db #0x01	; 1
	.db #0x16	; 22
	.db #0x02	; 2
	.db #0x28	; 40
	.db #0x16	; 22
	.db #0x02	; 2
	.db #0xff	; 255
;src/user_interface.c:51: void _DrawLine (u8 start, u8 other, u8 reps, u8 ch, u8 color, u8 is_hor)
;	---------------------------------
; Function _DrawLine
; ---------------------------------
__DrawLine::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;src/user_interface.c:55: pen (color);
	ld	a, 8 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
;src/user_interface.c:56: for (u8 var=start; var!= start+reps; ++var) {
	ld	a, 4 (ix)
	ld	-1 (ix), a
00106$:
	ld	c, 4 (ix)
	ld	b, #0x00
	ld	l, 6 (ix)
	ld	h, #0x00
	add	hl,bc
	ld	c, l
	ld	b, h
	ld	e, -1 (ix)
	ld	d, #0x00
	ld	a, c
	sub	a, e
	jr	NZ,00123$
	ld	a, b
	sub	a, d
	jr	Z,00108$
00123$:
;src/user_interface.c:59: y = other;
	ld	b, 5 (ix)
;src/user_interface.c:57: if (is_hor) {
	ld	a, 9 (ix)
	or	a, a
	jr	Z,00102$
;src/user_interface.c:58: x = var;
	ld	d, -1 (ix)
;src/user_interface.c:59: y = other;
	jr	00103$
00102$:
;src/user_interface.c:62: x = other;
	ld	d, b
;src/user_interface.c:63: y = var;
	ld	b, -1 (ix)
00103$:
;src/user_interface.c:65: locate (x,y);
	ld	c, d
	push	bc
	call	_locate
	pop	af
;src/user_interface.c:66: putchar (ch);
	ld	c, 7 (ix)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
;src/user_interface.c:56: for (u8 var=start; var!= start+reps; ++var) {
	inc	-1 (ix)
	jr	00106$
00108$:
	inc	sp
	pop	ix
	ret
;src/user_interface.c:69: u8 _DrawLines (u8 idx)
;	---------------------------------
; Function _DrawLines
; ---------------------------------
__DrawLines::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-6
	add	hl, sp
	ld	sp, hl
;src/user_interface.c:77: i = idx;
	ld	c, 4 (ix)
;src/user_interface.c:78: while ( (ch = hud[i++]) != 255) {
00105$:
	ld	e, c
	inc	c
	ld	hl, #_hud
	ld	d, #0x00
	add	hl, de
	ld	b, (hl)
	ld	e, b
	inc	b
	jp	Z,00107$
;src/user_interface.c:79: color = hud[i++];
	ld	b, c
	inc	c
	ld	iy, #_hud
	push	bc
	ld	c,b
	ld	b,#0x00
	add	iy, bc
	pop	bc
	ld	a, 0 (iy)
	ld	-5 (ix), a
;src/user_interface.c:80: is_hor = hud[i++];
	ld	a, c
	inc	a
	ld	-1 (ix), a
	ld	hl, #_hud
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	ld	-6 (ix), a
;src/user_interface.c:81: n_lines = hud[i++];
	ld	b, -1 (ix)
	ld	c, -1 (ix)
	inc	c
	ld	a, #<(_hud)
	add	a, b
	ld	l, a
	ld	a, #>(_hud)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	ld	-2 (ix), a
;src/user_interface.c:82: for (u8 n_line=0; n_line < n_lines; ++n_line) {
	ld	d, #0x00
00109$:
	ld	a, d
	sub	a, -2 (ix)
	jr	NC,00105$
;src/user_interface.c:83: x = hud[i++];
	ld	l, c
	inc	c
	ld	a, #<(_hud)
	add	a, l
	ld	l, a
	ld	a, #>(_hud)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	ld	-3 (ix), a
;src/user_interface.c:84: y = hud[i++];
	ld	a,c
	ld	l,a
	inc	a
	ld	-1 (ix), a
	ld	iy, #_hud
	ld	c,l
	ld	b,#0x00
	add	iy, bc
	ld	a, 0 (iy)
	ld	-4 (ix), a
;src/user_interface.c:85: reps = hud[i++];
	ld	b, -1 (ix)
	ld	c, -1 (ix)
	inc	c
	ld	a, #<(_hud)
	add	a, b
	ld	l, a
	ld	a, #>(_hud)
	adc	a, #0x00
	ld	h, a
	ld	b, (hl)
;src/user_interface.c:86: if (is_hor)
	ld	a, -6 (ix)
	or	a, a
	jr	Z,00102$
;src/user_interface.c:87: _DrawLine (x, y, reps, ch, color, is_hor);
	push	bc
	push	de
	ld	a, -6 (ix)
	push	af
	inc	sp
	ld	d, -5 (ix)
	push	de
	push	bc
	inc	sp
	ld	h, -4 (ix)
	ld	l, -3 (ix)
	push	hl
	call	__DrawLine
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
	jr	00110$
00102$:
;src/user_interface.c:89: _DrawLine (y, x, reps, ch, color, is_hor);
	push	bc
	push	de
	ld	a, -6 (ix)
	push	af
	inc	sp
	ld	d, -5 (ix)
	push	de
	push	bc
	inc	sp
	ld	h, -3 (ix)
	ld	l, -4 (ix)
	push	hl
	call	__DrawLine
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
00110$:
;src/user_interface.c:82: for (u8 n_line=0; n_line < n_lines; ++n_line) {
	inc	d
	jp	00109$
00107$:
;src/user_interface.c:92: return i;
	ld	l, c
	ld	sp, ix
	pop	ix
	ret
;src/user_interface.c:95: void DrawHUD ()
;	---------------------------------
; Function DrawHUD
; ---------------------------------
_DrawHUD::
;src/user_interface.c:99: i = DrawSingleChars ();
	call	_DrawSingleChars
	ld	b, l
;src/user_interface.c:100: i = _DrawLines (i);
	push	bc
	inc	sp
	call	__DrawLines
	inc	sp
;src/user_interface.c:101: PrintAt (12,1, "CPCRogue", PEN_BRIGHT);
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	ld	hl, #0x010c
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	ret
___str_0:
	.ascii "CPCRogue"
	.db 0x00
;src/user_interface.c:104: void DisplayLoading ()
;	---------------------------------
; Function DisplayLoading
; ---------------------------------
_DisplayLoading::
;src/user_interface.c:106: ink (1, 20, 14);
	ld	hl, #0x0e14
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_ink
	pop	af
	inc	sp
;src/user_interface.c:107: PrintAt (LOADING_X,LOADING_Y, "Loading...", 1);
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #___str_1
	push	hl
	ld	hl, #0x1502
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	ret
___str_1:
	.ascii "Loading..."
	.db 0x00
;src/user_interface.c:109: void ClearStatus (u8 start_line, u8 nlines)
;	---------------------------------
; Function ClearStatus
; ---------------------------------
_ClearStatus::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/user_interface.c:111: for (u8 n=0; n<nlines; ++n) {
	ld	c, #0x00
00103$:
	ld	a, c
	sub	a, 5 (ix)
	jr	NC,00105$
;src/user_interface.c:113: "                                      ",
	ld	de, #___str_2
;src/user_interface.c:112: PrintAt (STATUS_X, start_line+n,
	ld	a, 4 (ix)
	add	a, c
	ld	b, a
	push	bc
	ld	a, #0x03
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x02
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/user_interface.c:111: for (u8 n=0; n<nlines; ++n) {
	inc	c
	jr	00103$
00105$:
	pop	ix
	ret
___str_2:
	.ascii "                                      "
	.db 0x00
;src/user_interface.c:120: void PrintStats (TEntity *e)
;	---------------------------------
; Function PrintStats
; ---------------------------------
_PrintStats::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/user_interface.c:127: PrintAt (x,y, e->name, PEN_NORMAL); ++y;
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	hl, #0x0006
	add	hl, bc
	push	bc
	ld	a, #0x03
	push	af
	inc	sp
	push	hl
	ld	hl, #0x031f
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	ld	a, #0x03
	push	af
	inc	sp
	ld	hl, #___str_3
	push	hl
	ld	hl, #0x041f
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
	ld	hl, #0x0204
	push	hl
	ld	a, #0x22
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_4
	push	hl
	ld	hl, #0x0424
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
	ld	hl, #0x0204
	push	hl
	ld	a, #0x25
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_5
	push	hl
	ld	hl, #0x061f
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
	ld	hl, #0x0206
	push	hl
	ld	a, #0x23
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_6
	push	hl
	ld	hl, #0x071f
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
	ld	hl, #0x0207
	push	hl
	ld	a, #0x23
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_7
	push	hl
	ld	hl, #0x081f
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
	ld	hl, #0x0208
	push	hl
	ld	a, #0x23
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_8
	push	hl
	ld	hl, #0x0a1f
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
	ld	hl, #0x020a
	push	hl
	ld	a, #0x23
	push	af
	inc	sp
	push	de
	inc	sp
	call	_PrintU8
	pop	af
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	ld	hl, #___str_9
	push	hl
	ld	hl, #0x0b1f
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
	ld	hl, #0x020b
	push	hl
	ld	a, #0x23
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
	.ascii "HP:      "
	.db 0x00
___str_4:
	.ascii "/"
	.db 0x00
___str_5:
	.ascii "STR:"
	.db 0x00
___str_6:
	.ascii "DES:"
	.db 0x00
___str_7:
	.ascii "REF:"
	.db 0x00
___str_8:
	.ascii "ATK:"
	.db 0x00
___str_9:
	.ascii "DEF:"
	.db 0x00
;src/user_interface.c:140: void DrawLine (u8 coords[], u8 ch, u8 color)
;	---------------------------------
; Function DrawLine
; ---------------------------------
_DrawLine::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/user_interface.c:145: pen (color);
	ld	a, 7 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
;src/user_interface.c:146: ptr = coords;
	ld	c,4 (ix)
	ld	b,5 (ix)
;src/user_interface.c:147: while ( (x = *ptr++) != 0xff) {
00101$:
	ld	a, (bc)
	ld	e, a
	inc	bc
	ld	d, e
	inc	e
	jr	Z,00104$
;src/user_interface.c:148: y = *ptr++;
	ld	a, (bc)
	ld	h, a
	inc	bc
;src/user_interface.c:149: locate (x,y);
	push	bc
	ld	l, d
	push	hl
	call	_locate
	pop	af
	pop	bc
;src/user_interface.c:150: putchar (ch);
	ld	e, 6 (ix)
	ld	d, #0x00
	push	bc
	push	de
	call	_putchar
	pop	af
	pop	bc
	jr	00101$
00104$:
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
