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
	.globl _pen
	.globl _paper
	.globl _border
	.globl _ink
	.globl _locate
	.globl _putchar
	.globl _printf
	.globl _cpct_setVideoMode
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
;src/main.c:33: void locate (u8 x, u8 y)
;	---------------------------------
; Function locate
; ---------------------------------
_locate::
;src/main.c:35: putchar(US);
	ld	hl, #0x001f
	push	hl
	call	_putchar
	pop	af
;src/main.c:36: putchar (x); putchar (y);
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
;src/main.c:38: void ink (u8 tinta, u8 color1, u8 color2)
;	---------------------------------
; Function ink
; ---------------------------------
_ink::
;src/main.c:40: putchar (FS);
	ld	hl, #0x001c
	push	hl
	call	_putchar
	pop	af
;src/main.c:41: putchar (tinta); putchar (color1); putchar (color2);
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
;src/main.c:43: void border (u8 color1, u8 color2)
;	---------------------------------
; Function border
; ---------------------------------
_border::
;src/main.c:45: putchar (GS);
	ld	hl, #0x001d
	push	hl
	call	_putchar
	pop	af
;src/main.c:46: putchar (color1); putchar (color2);
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
;src/main.c:49: void paper (u8 color1)
;	---------------------------------
; Function paper
; ---------------------------------
_paper::
;src/main.c:51: putchar (SO);
	ld	hl, #0x000e
	push	hl
	call	_putchar
	pop	af
;src/main.c:52: putchar (color1);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:54: void pen (u8 tinta)
;	---------------------------------
; Function pen
; ---------------------------------
_pen::
;src/main.c:56: putchar (SI);
	ld	hl, #0x000f
	push	hl
	call	_putchar
	pop	af
;src/main.c:57: putchar (tinta);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:60: void main(void) {
;	---------------------------------
; Function main
; ---------------------------------
_main::
;src/main.c:61: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
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
;src/main.c:62: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
	ld	l, #0x01
	call	_cpct_setVideoMode
;src/main.c:63: border (0,0); paper (0); pen (1);
	ld	hl, #0x0000
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
;src/main.c:65: locate (0,4);printf ("      )   ___    _____    )   ___      \n");
	ld	hl, #0x0400
	push	hl
	call	_locate
	ld	hl, #___str_0
	ex	(sp),hl
	call	_printf
;src/main.c:66: locate (0,5);printf ("     (__/_____) (, /   ) (__/_____)    \n");
	ld	hl, #0x0500
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_1
	ex	(sp),hl
	call	_printf
;src/main.c:67: locate (0,6);printf ("       /         _/__ /    /           \n");
	ld	hl, #0x0600
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_2
	ex	(sp),hl
	call	_printf
;src/main.c:68: locate (0,7);printf ("      /          /        /            \n");
	ld	hl, #0x0700
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_3
	ex	(sp),hl
	call	_printf
;src/main.c:69: locate (0,8);printf ("     (______) ) /        (______)      \n");
	ld	hl, #0x0800
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_4
	ex	(sp),hl
	call	_printf
;src/main.c:70: locate (0,9);printf ("            _(_/_                      \n");
	ld	hl, #0x0900
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_5
	ex	(sp),hl
	call	_printf
;src/main.c:71: locate (0,10);printf ("           (, /   )                    \n");
	ld	hl, #0x0a00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_6
	ex	(sp),hl
	call	_printf
;src/main.c:72: locate (0,11);printf ("             /__ / ___      _          \n");
	ld	hl, #0x0b00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_7
	ex	(sp),hl
	call	_printf
;src/main.c:75: locate (0,12);printf ("          ) /   \\_(_(_/(_(_(/_         \n");
	ld	hl, #0x0c00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_8
	ex	(sp),hl
	call	_printf
;src/main.c:76: locate (0,13);printf ("         (_/       .-/                 \n");
	ld	hl, #0x0d00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_9
	ex	(sp),hl
	call	_printf
;src/main.c:77: locate (0,14);printf ("                  (_/                  \n");
	ld	hl, #0x0e00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_10
	ex	(sp),hl
	call	_printf
;src/main.c:78: locate (10, 18); pen (2); printf ("PRESS ENTER TO START");
	ld	hl, #0x120a
	ex	(sp),hl
	call	_locate
	ld	h,#0x02
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_11
	push	hl
	call	_printf
;src/main.c:79: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);
	ld	hl, #0x0303
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
;src/main.c:82: while (1);
00102$:
	jr	00102$
___str_0:
	.ascii "      )   ___    _____    )   ___      "
	.db 0x0a
	.db 0x00
___str_1:
	.ascii "     (__/_____) (, /   ) (__/_____)    "
	.db 0x0a
	.db 0x00
___str_2:
	.ascii "       /         _/__ /    /           "
	.db 0x0a
	.db 0x00
___str_3:
	.ascii "      /          /        /            "
	.db 0x0a
	.db 0x00
___str_4:
	.ascii "     (______) ) /        (______)      "
	.db 0x0a
	.db 0x00
___str_5:
	.ascii "            _(_/_                      "
	.db 0x0a
	.db 0x00
___str_6:
	.ascii "           (, /   )                    "
	.db 0x0a
	.db 0x00
___str_7:
	.ascii "             /__ / ___      _          "
	.db 0x0a
	.db 0x00
___str_8:
	.ascii "          ) /   "
	.db 0x5c
	.ascii "_(_(_/(_(_(/_         "
	.db 0x0a
	.db 0x00
___str_9:
	.ascii "         (_/       .-/                 "
	.db 0x0a
	.db 0x00
___str_10:
	.ascii "                  (_/                  "
	.db 0x0a
	.db 0x00
___str_11:
	.ascii "PRESS ENTER TO START"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
