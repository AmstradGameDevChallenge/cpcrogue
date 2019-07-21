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
	.globl _PrintCharacterStats
	.globl _InitializeCharacter
	.globl _cls
	.globl _pen
	.globl _paper
	.globl _border
	.globl _ink
	.globl _locate
	.globl _putchar
	.globl _printf
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
;src/main.c:50: void locate (u8 x, u8 y)
;	---------------------------------
; Function locate
; ---------------------------------
_locate::
;src/main.c:52: putchar(US);
	ld	hl, #0x001f
	push	hl
	call	_putchar
	pop	af
;src/main.c:53: putchar (x); putchar (y);
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
;src/main.c:55: void ink (u8 tinta, u8 color1, u8 color2)
;	---------------------------------
; Function ink
; ---------------------------------
_ink::
;src/main.c:57: putchar (FS);
	ld	hl, #0x001c
	push	hl
	call	_putchar
	pop	af
;src/main.c:58: putchar (tinta); putchar (color1); putchar (color2);
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
;src/main.c:60: void border (u8 color1, u8 color2)
;	---------------------------------
; Function border
; ---------------------------------
_border::
;src/main.c:62: putchar (GS);
	ld	hl, #0x001d
	push	hl
	call	_putchar
	pop	af
;src/main.c:63: putchar (color1); putchar (color2);
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
;src/main.c:66: void paper (u8 color1)
;	---------------------------------
; Function paper
; ---------------------------------
_paper::
;src/main.c:68: putchar (SO);
	ld	hl, #0x000e
	push	hl
	call	_putchar
	pop	af
;src/main.c:69: putchar (color1);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:71: void pen (u8 tinta)
;	---------------------------------
; Function pen
; ---------------------------------
_pen::
;src/main.c:73: putchar (SI);
	ld	hl, #0x000f
	push	hl
	call	_putchar
	pop	af
;src/main.c:74: putchar (tinta);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:76: void cls ()
;	---------------------------------
; Function cls
; ---------------------------------
_cls::
;src/main.c:78: putchar (FF);
	ld	hl, #0x000c
	push	hl
	call	_putchar
	pop	af
	ret
;src/main.c:83: void InitializeCharacter (struct TCharacter *c,
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
;src/main.c:86: c->_hp = hp;
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	l, c
	ld	h, b
	ld	a, 6 (ix)
	ld	(hl), a
	inc	hl
	ld	a, 7 (ix)
	ld	(hl), a
;src/main.c:87: c->_str = str;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	ld	a, 8 (ix)
	ld	(de), a
;src/main.c:88: c->_destr = destr;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	inc	de
	ld	a, 9 (ix)
	ld	(de), a
;src/main.c:89: c->_refl = refl;
	ld	hl, #0x0004
	add	hl, bc
	ld	a, 10 (ix)
	ld	(hl), a
;src/main.c:90: c->_spr = spr;
	ld	hl, #0x0009
	add	hl, bc
	ld	a, 11 (ix)
	ld	(hl), a
;src/main.c:91: c->_atk = 1.5 * c->_str + c->_destr;
	ld	hl, #0x0005
	add	hl,bc
	ld	-2 (ix), l
	ld	-1 (ix), h
	push	bc
	ld	a, 8 (ix)
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
	ld	e, 9 (ix)
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
;src/main.c:92: c->_defense = 1.5 * c->_destr + c->_refl;
	ld	hl, #0x0007
	add	hl,bc
	ld	-6 (ix), l
	ld	-5 (ix), h
	ld	a, 9 (ix)
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
	ld	c, 10 (ix)
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
;src/main.c:97: void PrintCharacterStats (struct TCharacter *c,
;	---------------------------------
; Function PrintCharacterStats
; ---------------------------------
_PrintCharacterStats::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;src/main.c:100: pen (color1);printf ("STR "); pen (color2);printf ("[%d] ", c->_str);
	ld	a, 6 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_0
	push	hl
	call	_printf
	pop	af
	ld	a, 7 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	ld	a, 4 (ix)
	ld	-2 (ix), a
	ld	a, 5 (ix)
	ld	-1 (ix), a
	pop	hl
	push	hl
	inc	hl
	inc	hl
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, #___str_1
	push	hl
	call	_printf
	pop	af
	pop	af
;src/main.c:101: pen (color1);printf ("DES "); pen (color2);printf ("[%d] ", c->_destr);
	ld	a, 6 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_2
	push	hl
	call	_printf
	pop	af
	ld	a, 7 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	pop	hl
	push	hl
	inc	hl
	inc	hl
	inc	hl
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, #___str_1
	push	hl
	call	_printf
	pop	af
	pop	af
;src/main.c:102: pen (color1);printf ("REF "); pen (color2);printf ("[%d]\r\n", c->_refl);
	ld	a, 6 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_3
	push	hl
	call	_printf
	pop	af
	ld	a, 7 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	pop	hl
	push	hl
	ld	de, #0x0004
	add	hl, de
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, #___str_4
	push	hl
	call	_printf
	pop	af
	pop	af
;src/main.c:104: pen (color1);printf ("ATK "); pen (color2);printf ("[%d] ", c->_atk);
	ld	a, 6 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_5
	push	hl
	call	_printf
	pop	af
	ld	a, 7 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	pop	hl
	push	hl
	ld	de, #0x0005
	add	hl, de
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	ld	hl, #___str_1
	push	hl
	call	_printf
	pop	af
	pop	af
;src/main.c:105: pen (color1);printf ("DEF "); pen (color2);printf("[%d] ",c->_defense);
	ld	a, 6 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_6
	push	hl
	call	_printf
	pop	af
	ld	a, 7 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	pop	hl
	push	hl
	ld	de, #0x0007
	add	hl, de
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	ld	hl, #___str_1
	push	hl
	call	_printf
	pop	af
	pop	af
;src/main.c:106: pen (color1);printf (" HP "); pen (color2);printf ("[%d]\r\n", c->_hp);
	ld	a, 6 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_7
	push	hl
	call	_printf
	pop	af
	ld	a, 7 (ix)
	push	af
	inc	sp
	call	_pen
	inc	sp
	pop	hl
	push	hl
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	ld	hl, #___str_4
	push	hl
	call	_printf
	ld	sp,ix
	pop	ix
	ret
___str_0:
	.ascii "STR "
	.db 0x00
___str_1:
	.ascii "[%d] "
	.db 0x00
___str_2:
	.ascii "DES "
	.db 0x00
___str_3:
	.ascii "REF "
	.db 0x00
___str_4:
	.ascii "[%d]"
	.db 0x0d
	.db 0x0a
	.db 0x00
___str_5:
	.ascii "ATK "
	.db 0x00
___str_6:
	.ascii "DEF "
	.db 0x00
___str_7:
	.ascii " HP "
	.db 0x00
;src/main.c:111: void main(void) {
;	---------------------------------
; Function main
; ---------------------------------
_main::
	push	ix
	ld	hl, #-20
	add	hl, sp
	ld	sp, hl
;src/main.c:117: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
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
;src/main.c:118: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
	ld	l, #0x01
	call	_cpct_setVideoMode
;src/main.c:119: border (0,0); paper (0); pen (1);
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
;src/main.c:121: locate (0,4);printf ("      )   ___    _____    )   ___      ");
	ld	hl, #0x0400
	push	hl
	call	_locate
	ld	hl, #___str_8
	ex	(sp),hl
	call	_printf
;src/main.c:122: locate (0,5);printf ("     (__/_____) (, /   ) (__/_____)    ");
	ld	hl, #0x0500
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_9
	ex	(sp),hl
	call	_printf
;src/main.c:123: locate (0,6);printf ("       /         _/__ /    /           ");
	ld	hl, #0x0600
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_10
	ex	(sp),hl
	call	_printf
;src/main.c:124: locate (0,7);printf ("      /          /        /            ");
	ld	hl, #0x0700
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_11
	ex	(sp),hl
	call	_printf
;src/main.c:125: locate (0,8);printf ("     (______) ) /        (______)      ");
	ld	hl, #0x0800
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_12
	ex	(sp),hl
	call	_printf
;src/main.c:126: locate (0,9);printf ("            _(_/_                      ");
	ld	hl, #0x0900
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_13
	ex	(sp),hl
	call	_printf
;src/main.c:127: locate (0,10);printf ("           (, /   )                    ");
	ld	hl, #0x0a00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_14
	ex	(sp),hl
	call	_printf
;src/main.c:128: locate (0,11);printf ("             /__ / ___      _          ");
	ld	hl, #0x0b00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_15
	ex	(sp),hl
	call	_printf
;src/main.c:131: locate (0,12);printf ("          ) /   \\_(_(_/(_(_(/_         ");
	ld	hl, #0x0c00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_16
	ex	(sp),hl
	call	_printf
;src/main.c:132: locate (0,13);printf ("         (_/       .-/                 ");
	ld	hl, #0x0d00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_17
	ex	(sp),hl
	call	_printf
;src/main.c:133: locate (0,14);printf ("                  (_/                  ");
	ld	hl, #0x0e00
	ex	(sp),hl
	call	_locate
	ld	hl, #___str_18
	ex	(sp),hl
	call	_printf
;src/main.c:134: locate (10, 18); pen (2); printf ("PRESS ENTER TO START");
	ld	hl, #0x120a
	ex	(sp),hl
	call	_locate
	ld	h,#0x02
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_19
	push	hl
	call	_printf
;src/main.c:135: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);
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
;src/main.c:138: while (!cpct_isKeyPressed (Key_Return)) {
00101$:
	ld	hl, #0x0402
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	NZ,00103$
;src/main.c:139: cpct_scanKeyboard ();
	call	_cpct_scanKeyboard
	jr	00101$
00103$:
;src/main.c:143: border (0,0); ink (0, 0,0); ink (1, 25,25); ink (2, 20,20);
	ld	hl, #0x0000
	push	hl
	call	_border
	ld	hl, #0x0000
	ex	(sp),hl
	xor	a, a
	push	af
	inc	sp
	call	_ink
	inc	sp
	ld	hl,#0x1919
	ex	(sp),hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_ink
	inc	sp
	ld	hl,#0x1414
	ex	(sp),hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_ink
	pop	af
	inc	sp
;src/main.c:144: paper (0); pen (2); cls ();
	xor	a, a
	push	af
	inc	sp
	call	_paper
	inc	sp
	ld	a, #0x02
	push	af
	inc	sp
	call	_pen
	inc	sp
	call	_cls
;src/main.c:147: InitializeCharacter (&player, 150, 17, 14, 12, '@');
	ld	hl, #0x000a
	add	hl, sp
	ld	c, l
	ld	b, h
	ld	e, c
	ld	d, b
	push	bc
	ld	hl, #0x400c
	push	hl
	ld	hl, #0x0e11
	push	hl
	ld	hl, #0x0096
	push	hl
	push	de
	call	_InitializeCharacter
	ld	hl, #8
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:148: InitializeCharacter (&goblin, 100, 12, 13, 11, 'g');
	ld	hl, #0x0000
	add	hl, sp
	push	hl
	pop	iy
	push	hl
	push	bc
	ld	de, #0x670b
	push	de
	ld	de, #0x0d0c
	push	de
	ld	de, #0x0064
	push	de
	push	iy
	call	_InitializeCharacter
	ld	hl, #8
	add	hl, sp
	ld	sp, hl
	pop	bc
	ld	de, #0x0201
	push	de
	push	bc
	call	_PrintCharacterStats
	pop	af
	pop	af
	pop	hl
;src/main.c:152: PrintCharacterStats (&goblin, 1,2);
	ld	bc, #0x0201
	push	bc
	push	hl
	call	_PrintCharacterStats
	pop	af
	pop	af
;src/main.c:155: while (1);
00105$:
	jr	00105$
___str_8:
	.ascii "      )   ___    _____    )   ___      "
	.db 0x00
___str_9:
	.ascii "     (__/_____) (, /   ) (__/_____)    "
	.db 0x00
___str_10:
	.ascii "       /         _/__ /    /           "
	.db 0x00
___str_11:
	.ascii "      /          /        /            "
	.db 0x00
___str_12:
	.ascii "     (______) ) /        (______)      "
	.db 0x00
___str_13:
	.ascii "            _(_/_                      "
	.db 0x00
___str_14:
	.ascii "           (, /   )                    "
	.db 0x00
___str_15:
	.ascii "             /__ / ___      _          "
	.db 0x00
___str_16:
	.ascii "          ) /   "
	.db 0x5c
	.ascii "_(_(_/(_(_(/_         "
	.db 0x00
___str_17:
	.ascii "         (_/       .-/                 "
	.db 0x00
___str_18:
	.ascii "                  (_/                  "
	.db 0x00
___str_19:
	.ascii "PRESS ENTER TO START"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
