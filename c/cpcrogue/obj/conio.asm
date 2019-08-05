;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module conio
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _putchar
	.globl _sprintf
	.globl _locate
	.globl _ink
	.globl _paper
	.globl _pen
	.globl _PrintAt
	.globl _PrintU8
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
;src/conio.c:7: void locate (u8 x, u8 y)
;	---------------------------------
; Function locate
; ---------------------------------
_locate::
;src/conio.c:9: putchar(US);
	ld	hl, #0x001f
	push	hl
	call	_putchar
	pop	af
;src/conio.c:10: putchar (x); putchar (y);
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
;src/conio.c:12: void ink (u8 tinta, u8 color1, u8 color2)
;	---------------------------------
; Function ink
; ---------------------------------
_ink::
;src/conio.c:14: putchar (FS);
	ld	hl, #0x001c
	push	hl
	call	_putchar
	pop	af
;src/conio.c:15: putchar (tinta); putchar (color1); putchar (color2);
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
;src/conio.c:18: void paper (u8 color1)
;	---------------------------------
; Function paper
; ---------------------------------
_paper::
;src/conio.c:20: putchar (SO);
	ld	hl, #0x000e
	push	hl
	call	_putchar
	pop	af
;src/conio.c:21: putchar (color1);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/conio.c:23: void pen (u8 tinta)
;	---------------------------------
; Function pen
; ---------------------------------
_pen::
;src/conio.c:25: putchar (SI);
	ld	hl, #0x000f
	push	hl
	call	_putchar
	pop	af
;src/conio.c:26: putchar (tinta);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/conio.c:31: void PrintAt (u8 x, u8 y, char text[], u8 color)
;	---------------------------------
; Function PrintAt
; ---------------------------------
_PrintAt::
;src/conio.c:35: locate (x, y);
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
;src/conio.c:36: if (color != 0xff) pen (color);
	ld	iy, #6
	add	iy, sp
	ld	a, 0 (iy)
	inc	a
	jr	Z,00110$
	ld	a, 0 (iy)
	push	af
	inc	sp
	call	_pen
	inc	sp
;src/conio.c:37: while ( (ch=text[i++]) )
00110$:
	ld	c, #0x00
00103$:
	ld	b, c
	inc	c
	ld	iy, #4
	add	iy, sp
	ld	a, 0 (iy)
	add	a, b
	ld	e, a
	ld	a, 1 (iy)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	e, a
	or	a, a
	ret	Z
;src/conio.c:38: putchar(ch);
	ld	d, #0x00
	push	bc
	push	de
	call	_putchar
	pop	af
	pop	bc
	jr	00103$
;src/conio.c:44: void PrintU8 (u8 num, u8 x, u8 y, u8 color)
;	---------------------------------
; Function PrintU8
; ---------------------------------
_PrintU8::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
;src/conio.c:47: sprintf (str, "%d", num);
	ld	e, 4 (ix)
	ld	d, #0x00
	ld	hl, #0x0000
	add	hl, sp
	push	hl
	push	de
	ld	de, #___str_0
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/conio.c:48: PrintAt (x,y, str, color);
	ld	a, 7 (ix)
	push	af
	inc	sp
	push	bc
	ld	h, 6 (ix)
	ld	l, 5 (ix)
	push	hl
	call	_PrintAt
	ld	sp,ix
	pop	ix
	ret
___str_0:
	.ascii "%d"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
