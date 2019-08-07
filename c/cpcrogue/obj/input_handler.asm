;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module input_handler
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _cpct_isKeyPressed
	.globl _HandleKeyboard
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
;src/input_handler.c:7: TAction HandleKeyboard (i8 *dx, i8 *dy)
;	---------------------------------
; Function HandleKeyboard
; ---------------------------------
_HandleKeyboard::
;src/input_handler.c:9: if (cpct_isKeyPressed (Key_I)) {  // i: UP
	ld	hl, #0x0804
	call	_cpct_isKeyPressed
	ld	c, l
;src/input_handler.c:10: *dx = 0; *dy = -1; return PLAYER_MOVE;
	pop	de
	pop	hl
	push	hl
	push	de
	ld	iy, #4
	add	iy, sp
	ld	e,0 (iy)
	ld	d,1 (iy)
;src/input_handler.c:9: if (cpct_isKeyPressed (Key_I)) {  // i: UP
	ld	a, c
	or	a, a
	jr	Z,00102$
;src/input_handler.c:10: *dx = 0; *dy = -1; return PLAYER_MOVE;
	ld	(hl), #0x00
	ld	a, #0xff
	ld	(de), a
	ld	l, #0x01
	ret
00102$:
;src/input_handler.c:12: if (cpct_isKeyPressed (Key_K)) {  // k: DOWN
	push	hl
	push	de
	ld	hl, #0x2004
	call	_cpct_isKeyPressed
	ld	a, l
	pop	de
	pop	hl
	or	a, a
	jr	Z,00104$
;src/input_handler.c:13: *dx = 0; *dy = 1; return PLAYER_MOVE;
	ld	(hl), #0x00
	ld	a, #0x01
	ld	(de), a
	ld	l, #0x01
	ret
00104$:
;src/input_handler.c:15: if (cpct_isKeyPressed (Key_J)) {  // j: LEFT
	push	hl
	push	de
	ld	hl, #0x2005
	call	_cpct_isKeyPressed
	ld	a, l
	pop	de
	pop	hl
	or	a, a
	jr	Z,00106$
;src/input_handler.c:16: *dx = -1; *dy = 0; return PLAYER_MOVE;
	ld	(hl), #0xff
	xor	a, a
	ld	(de), a
	ld	l, #0x01
	ret
00106$:
;src/input_handler.c:18: if (cpct_isKeyPressed (Key_L)) {  // l: RIGHT
	push	hl
	push	de
	ld	hl, #0x1004
	call	_cpct_isKeyPressed
	ld	a, l
	pop	de
	pop	hl
	or	a, a
	jr	Z,00108$
;src/input_handler.c:19: *dx = 1; *dy = 0; return PLAYER_MOVE;
	ld	(hl), #0x01
	xor	a, a
	ld	(de), a
	ld	l, #0x01
	ret
00108$:
;src/input_handler.c:21: if (cpct_isKeyPressed (Key_S)) {  // s: WAIT
	ld	hl, #0x1007
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00110$
;src/input_handler.c:22: return PLAYER_MOVE;
	ld	l, #0x01
	ret
00110$:
;src/input_handler.c:24: return NONE;
	ld	l, #0x00
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
