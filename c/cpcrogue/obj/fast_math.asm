;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module fast_math
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _manh_distance_to
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
;src/fast_math.c:4: u16 manh_distance_to (u8 x1, u8 y1, u8 x2, u8 y2)
;	---------------------------------
; Function manh_distance_to
; ---------------------------------
_manh_distance_to::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/fast_math.c:8: dx = x2 - x1;
	ld	a, 6 (ix)
	sub	a, 4 (ix)
	ld	l, a
;src/fast_math.c:9: dy = y2 - y1;
	ld	a, 7 (ix)
	sub	a, 5 (ix)
	ld	c, a
	bit	7, l
	jr	Z,00105$
	xor	a, a
	sub	a, l
	ld	l, a
00105$:
;src/fast_math.c:11: dx = abs (dx);
;src/fast_math.h:9: return value < 0 ? -value : value;
	bit	7, c
	jr	Z,00107$
	xor	a, a
	sub	a, c
	ld	c, a
00107$:
;src/fast_math.c:12: dy = abs (dy);
;src/fast_math.c:14: return (dx + dy);
	ld	a, l
	rla
	sbc	a, a
	ld	h, a
	ld	a, c
	rla
	sbc	a, a
	ld	b, a
	add	hl, bc
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
