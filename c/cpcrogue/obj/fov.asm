;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module fov
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _TraceLine
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
;src/fov.c:5: void TraceLine (u8 x1, u8 y1, u8 x2, u8 y2) //, u8 *coords)
;	---------------------------------
; Function TraceLine
; ---------------------------------
_TraceLine::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
;src/fov.c:12: dx = x2-x1;
	ld	a, 6 (ix)
	sub	a, 4 (ix)
	ld	e, a
;src/fov.c:13: dy = y2-y1;
	ld	a, 7 (ix)
	sub	a, 5 (ix)
	ld	l, a
;src/fov.c:14: sx = sign (dx);
	ld	c, e
;src/fast_math.h:13: return value < 0 ? -1 : 1;
	bit	7, c
	jr	Z,00117$
	ld	c, #0xff
	jr	00118$
00117$:
	ld	c, #0x01
00118$:
;src/fov.c:14: sx = sign (dx);
;src/fov.c:15: sy = sign (dy);
	ld	b, l
;src/fast_math.h:13: return value < 0 ? -1 : 1;
	bit	7, b
	jr	Z,00119$
	ld	a, #0xff
	jr	00120$
00119$:
	ld	a, #0x01
00120$:
;src/fov.c:15: sy = sign (dy);
	ld	-3 (ix), a
;src/fov.c:16: dx = abs (dx);
	ld	b, e
;src/fast_math.h:9: return value < 0 ? -value : value;
	bit	7, b
	jr	Z,00121$
	xor	a, a
	sub	a, e
	ld	e, a
00121$:
;src/fov.c:16: dx = abs (dx);
;src/fov.c:17: dy = abs (dy);
	ld	b, l
;src/fast_math.h:9: return value < 0 ? -value : value;
	bit	7, b
	jr	Z,00123$
	xor	a, a
	sub	a, l
	ld	l, a
00123$:
;src/fov.c:17: dy = abs (dy);
	ld	b, l
;src/fov.c:18: error = dx-dy;
	ld	a, e
	sub	a, l
	ld	d, a
;src/fov.c:21: while(1) {
00109$:
;src/fov.c:26: if (x1==x2 && y1==y2) {
	ld	a, 4 (ix)
	sub	a, 6 (ix)
	jr	NZ,00102$
	ld	a, 5 (ix)
	sub	a, 7 (ix)
	jr	Z,00115$
;src/fov.c:28: break;
00102$:
;src/fov.c:31: error2 = error << 1;
	ld	a, d
	add	a, a
	ld	-4 (ix), a
;src/fov.c:32: if (error2 > -dx) {
	ld	l, e
	ld	h, #0x00
	xor	a, a
	sub	a, l
	ld	-2 (ix), a
	ld	a, #0x00
	sbc	a, h
	ld	-1 (ix), a
	ld	l, -4 (ix)
	ld	a, -4 (ix)
	rla
	sbc	a, a
	ld	h, a
	ld	a, -2 (ix)
	sub	a, l
	ld	a, -1 (ix)
	sbc	a, h
	jp	PO, 00160$
	xor	a, #0x80
00160$:
	jp	P, 00105$
;src/fov.c:33: error -= dy;
	ld	l, b
	ld	a, d
	sub	a, l
	ld	d, a
;src/fov.c:34: x1 += sx;
	ld	l, 4 (ix)
	add	hl, bc
	ld	4 (ix), l
00105$:
;src/fov.c:36: if (error2 < (i8)dx) {
	ld	l, e
	ld	a, -4 (ix)
	sub	a, l
	jp	PO, 00161$
	xor	a, #0x80
00161$:
	jp	P, 00109$
;src/fov.c:37: error += dx;
	ld	a, d
	add	a, l
	ld	d, a
;src/fov.c:38: y1 += sy;
	ld	a, 5 (ix)
	add	a, -3 (ix)
	ld	5 (ix), a
	jr	00109$
00115$:
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
