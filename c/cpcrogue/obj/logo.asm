;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module logo
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ShowLogo
	.globl _PrintAt
	.globl _pen
	.globl _paper
	.globl _ink
	.globl _putchar
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
;src/logo.c:4: void ShowLogo()
;	---------------------------------
; Function ShowLogo
; ---------------------------------
_ShowLogo::
;src/logo.c:6: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
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
;src/logo.c:7: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
	ld	l, #0x01
	call	_cpct_setVideoMode
;src/conio.h:9: putchar (GS);
	ld	hl, #0x001d
	push	hl
	call	_putchar
;src/conio.h:10: putchar (color1); putchar (color1);
	ld	hl, #0x0001
	ex	(sp),hl
	call	_putchar
	ld	hl, #0x0001
	ex	(sp),hl
	call	_putchar
	pop	af
;src/logo.c:8: border (1); paper (0); pen (1);
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
;src/logo.c:10: PrintAt (1,5, "      )   ___    _____    )   ___", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	ld	hl, #0x0501
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:11: PrintAt (1,6, "     (__/_____) (, /   ) (__/_____)", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_1
	push	hl
	ld	hl, #0x0601
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:12: PrintAt (1,7, "       /         _/__ /    /", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	ld	hl, #0x0701
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:13: PrintAt (1,8, "      /          /        /", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_3
	push	hl
	ld	hl, #0x0801
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:14: PrintAt (1,9, "     (______) ) /        (______)", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_4
	push	hl
	ld	hl, #0x0901
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:15: PrintAt (1,10, "            _(_/_", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_5
	push	hl
	ld	hl, #0x0a01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:16: PrintAt (1,11, "           (, /   )", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_6
	push	hl
	ld	hl, #0x0b01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:17: PrintAt (1,12, "             /__ / ___      _", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_7
	push	hl
	ld	hl, #0x0c01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:20: PrintAt (1,13, "          ) /   \\_(_(_/(_(_(/_         ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_8
	push	hl
	ld	hl, #0x0d01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:21: PrintAt (1,14, "         (_/       .-/                 ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_9
	push	hl
	ld	hl, #0x0e01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:22: PrintAt (1,15, "                  (_/                  ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_10
	push	hl
	ld	hl, #0x0f01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/logo.c:23: PrintAt (10, 18, "PRESS ENTER TO START", 2);
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_11
	push	hl
	ld	hl, #0x120a
	push	hl
	call	_PrintAt
	pop	af
;src/logo.c:24: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3);
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
;src/conio.h:9: putchar (GS);
	inc	sp
	ld	hl,#0x001d
	ex	(sp),hl
	call	_putchar
;src/conio.h:10: putchar (color1); putchar (color1);
	ld	hl, #0x0003
	ex	(sp),hl
	call	_putchar
	ld	hl, #0x0003
	ex	(sp),hl
	call	_putchar
	pop	af
;src/logo.c:27: while (!cpct_isKeyPressed (Key_Return)) {
00101$:
	ld	hl, #0x0402
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	ret	NZ
;src/logo.c:28: cpct_scanKeyboard ();
	call	_cpct_scanKeyboard
	jr	00101$
___str_0:
	.ascii "      )   ___    _____    )   ___"
	.db 0x00
___str_1:
	.ascii "     (__/_____) (, /   ) (__/_____)"
	.db 0x00
___str_2:
	.ascii "       /         _/__ /    /"
	.db 0x00
___str_3:
	.ascii "      /          /        /"
	.db 0x00
___str_4:
	.ascii "     (______) ) /        (______)"
	.db 0x00
___str_5:
	.ascii "            _(_/_"
	.db 0x00
___str_6:
	.ascii "           (, /   )"
	.db 0x00
___str_7:
	.ascii "             /__ / ___      _"
	.db 0x00
___str_8:
	.ascii "          ) /   "
	.db 0x5c
	.ascii "_(_(_/(_(_(/_         "
	.db 0x00
___str_9:
	.ascii "         (_/       .-/                 "
	.db 0x00
___str_10:
	.ascii "                  (_/                  "
	.db 0x00
___str_11:
	.ascii "PRESS ENTER TO START"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
