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
	.globl _InitColors
	.globl _TraceLine
	.globl _PrintAt
	.globl _paper
	.globl _ink
	.globl _putchar
	.globl _edy
	.globl _target
	.globl _action
	.globl _new_y
	.globl _new_x
	.globl _edx
	.globl _dy
	.globl _dx
	.globl _state
	.globl _entities
	.globl _dirty
	.globl _enemy
	.globl _player
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_player::
	.ds 33
_enemy::
	.ds 33
_dirty::
	.ds 5
_entities::
	.ds 10
_state::
	.ds 1
_dx::
	.ds 1
_dy::
	.ds 1
_edx::
	.ds 10
_new_x::
	.ds 1
_new_y::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_action::
	.ds 1
_target::
	.ds 2
_edy::
	.ds 1
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
;src/main.c:38: void InitColors()
;	---------------------------------
; Function InitColors
; ---------------------------------
_InitColors::
;src/main.c:40: ink (0, INK_BG,INK_BG);
	ld	hl, #0x0000
	push	hl
	xor	a, a
	push	af
	inc	sp
	call	_ink
;src/main.c:41: ink (1, INK_DARK, INK_DARK);
	inc	sp
	ld	hl,#0x0101
	ex	(sp),hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_ink
;src/main.c:42: ink (2, INK_BRIGHT, INK_BRIGHT);
	inc	sp
	ld	hl,#0x1414
	ex	(sp),hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_ink
;src/main.c:43: ink (3, INK_NORMAL, INK_NORMAL);
	inc	sp
	ld	hl,#0x0a0a
	ex	(sp),hl
	ld	a, #0x03
	push	af
	inc	sp
	call	_ink
;src/conio.h:9: putchar (GS);
	inc	sp
	ld	hl,#0x001d
	ex	(sp),hl
	call	_putchar
;src/conio.h:10: putchar (color1); putchar (color1);
	ld	hl, #0x0000
	ex	(sp),hl
	call	_putchar
	ld	hl, #0x0000
	ex	(sp),hl
	call	_putchar
	pop	af
;src/main.c:45: border (0); paper (0);
	xor	a, a
	push	af
	inc	sp
	call	_paper
	inc	sp
	ret
;src/main.c:65: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
	push	ix
	ld	hl, #-256
	add	hl, sp
	ld	sp, hl
;src/main.c:70: for (ei=0; ei!=5; ++ei) {
	ld	bc, #_edx+0
	ld	e, #0x00
00109$:
;src/main.c:71: edx[ei]=1; edx[9-ei]=-1;
	ld	l,e
	ld	h,#0x00
	add	hl, bc
	ld	(hl), #0x01
	ld	a, #0x09
	sub	a, e
	ld	l, a
	ld	h,#0x00
	add	hl, bc
	ld	(hl), #0xff
;src/main.c:70: for (ei=0; ei!=5; ++ei) {
	inc	e
	ld	a, e
	sub	a, #0x05
	jr	NZ,00109$
;src/conio.h:14: inline void cls () { putchar (FF); }
	ld	hl, #0x000c
	push	hl
	call	_putchar
	pop	af
;src/main.c:77: for (u8 n=0; n!= 30; ++n) {
	ld	c, #0x00
00118$:
	ld	a, c
	sub	a, #0x1e
	jr	Z,00104$
;src/main.c:78: for (u8 x=10; x!=20; ++x) {
	ld	b, #0x0a
00112$:
	ld	a, b
	sub	a, #0x14
	jr	Z,00102$
;src/main.c:79: TraceLine (15,15, x,10);//, points);
	push	bc
	ld	a, #0x0a
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	hl, #0x0f0f
	push	hl
	call	_TraceLine
	pop	af
	pop	af
	pop	bc
;src/main.c:80: TraceLine (15,15, x,20);//, points);
	push	bc
	ld	a, #0x14
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	hl, #0x0f0f
	push	hl
	call	_TraceLine
	pop	af
	pop	af
	pop	bc
;src/main.c:78: for (u8 x=10; x!=20; ++x) {
	inc	b
	jr	00112$
00102$:
;src/main.c:82: for (u8 y=10; y<=20; ++y) {
	ld	b, #0x0a
00115$:
	ld	a, #0x14
	sub	a, b
	jr	C,00119$
;src/main.c:83: TraceLine (15,15, 10,y);//, points);
	push	bc
	push	bc
	inc	sp
	ld	hl, #0x0a0f
	push	hl
	ld	a, #0x0f
	push	af
	inc	sp
	call	_TraceLine
	pop	af
	pop	af
	pop	bc
;src/main.c:84: TraceLine (15,15, 20,y);//, points);
	push	bc
	push	bc
	inc	sp
	ld	hl, #0x140f
	push	hl
	ld	a, #0x0f
	push	af
	inc	sp
	call	_TraceLine
	pop	af
	pop	af
	pop	bc
;src/main.c:82: for (u8 y=10; y<=20; ++y) {
	inc	b
	jr	00115$
00119$:
;src/main.c:77: for (u8 n=0; n!= 30; ++n) {
	inc	c
	jr	00118$
00104$:
;src/main.c:87: PrintAt(15,1, "Finished!",3);
	ld	a, #0x03
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	ld	hl, #0x010f
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:164: while (1);
00106$:
	jr	00106$
___str_0:
	.ascii "Finished!"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
__xinit__action:
	.db #0x00	; 0
__xinit__target:
	.dw #0x0000
__xinit__edy:
	.db #0x00	;  0
	.area _CABS (ABS)
