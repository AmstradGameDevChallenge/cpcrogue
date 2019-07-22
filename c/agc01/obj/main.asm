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
	.globl _TakeDamage
	.globl _CalculateDamage
	.globl _ClearStatusLine
	.globl _PrintCharacterStats
	.globl _InitializeCharacter
	.globl _PrintAt
	.globl _cls
	.globl _pen
	.globl _paper
	.globl _border
	.globl _ink
	.globl _locate
	.globl _putchar
	.globl _sprintf
	.globl _printf
	.globl _cpct_getRandom_mxor_u8
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
;src/main.c:52: void locate (u8 x, u8 y)
;	---------------------------------
; Function locate
; ---------------------------------
_locate::
;src/main.c:54: putchar(US);
	ld	hl, #0x001f
	push	hl
	call	_putchar
	pop	af
;src/main.c:55: putchar (x); putchar (y);
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
;src/main.c:57: void ink (u8 tinta, u8 color1, u8 color2)
;	---------------------------------
; Function ink
; ---------------------------------
_ink::
;src/main.c:59: putchar (FS);
	ld	hl, #0x001c
	push	hl
	call	_putchar
	pop	af
;src/main.c:60: putchar (tinta); putchar (color1); putchar (color2);
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
;src/main.c:62: void border (u8 color1, u8 color2)
;	---------------------------------
; Function border
; ---------------------------------
_border::
;src/main.c:64: putchar (GS);
	ld	hl, #0x001d
	push	hl
	call	_putchar
	pop	af
;src/main.c:65: putchar (color1); putchar (color2);
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
;src/main.c:68: void paper (u8 color1)
;	---------------------------------
; Function paper
; ---------------------------------
_paper::
;src/main.c:70: putchar (SO);
	ld	hl, #0x000e
	push	hl
	call	_putchar
	pop	af
;src/main.c:71: putchar (color1);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:73: void pen (u8 tinta)
;	---------------------------------
; Function pen
; ---------------------------------
_pen::
;src/main.c:75: putchar (SI);
	ld	hl, #0x000f
	push	hl
	call	_putchar
	pop	af
;src/main.c:76: putchar (tinta);
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	call	_putchar
	pop	af
	ret
;src/main.c:78: void cls ()
;	---------------------------------
; Function cls
; ---------------------------------
_cls::
;src/main.c:80: putchar (FF);
	ld	hl, #0x000c
	push	hl
	call	_putchar
	pop	af
	ret
;src/main.c:85: void PrintAt (u8 x, u8 y, char text[], u8 color)
;	---------------------------------
; Function PrintAt
; ---------------------------------
_PrintAt::
;src/main.c:87: locate (x, y);
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
;src/main.c:88: if (color != 0xff) pen (color);
	ld	iy, #6
	add	iy, sp
	ld	a, 0 (iy)
	inc	a
	jr	Z,00102$
	ld	a, 0 (iy)
	push	af
	inc	sp
	call	_pen
	inc	sp
00102$:
;src/main.c:89: printf (text);
	ld	hl, #4
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	call	_printf
	pop	af
	ret
;src/main.c:94: void InitializeCharacter (struct TCharacter *c,
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
;src/main.c:98: c->_hp = hp;
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	l, c
	ld	h, b
	ld	a, 6 (ix)
	ld	(hl), a
	inc	hl
	ld	a, 7 (ix)
	ld	(hl), a
;src/main.c:99: c->_str = str;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	ld	a, 8 (ix)
	ld	(de), a
;src/main.c:100: c->_destr = destr;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	inc	de
	ld	a, 9 (ix)
	ld	(de), a
;src/main.c:101: c->_refl = refl;
	ld	hl, #0x0004
	add	hl, bc
	ld	a, 10 (ix)
	ld	(hl), a
;src/main.c:102: c->_spr[0] = spr; c->_spr[1] = '\0';
	ld	hl, #0x0009
	add	hl, bc
	ld	a, 11 (ix)
	ld	(hl), a
	ld	hl, #0x000a
	add	hl, bc
	ld	(hl), #0x00
;src/main.c:103: c->_atk = 1.5 * c->_str + c->_destr;
	ld	hl, #0x0005
	add	hl,bc
	ex	(sp), hl
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
	ld	-1 (ix), d
	ld	-2 (ix), e
	ld	-3 (ix), h
	ld	-4 (ix), l
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
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	push	hl
	ld	l,-4 (ix)
	ld	h,-3 (ix)
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
	pop	hl
	push	hl
	ld	(hl), e
	inc	hl
	ld	(hl), d
;src/main.c:104: c->_defense = 1.5 * c->_destr + c->_refl;
	ld	hl, #0x0007
	add	hl,bc
	ld	-4 (ix), l
	ld	-3 (ix), h
	push	bc
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
	ld	-5 (ix), d
	ld	-6 (ix), e
	ld	-7 (ix), h
	ld	-8 (ix), l
	pop	bc
	ld	e, 10 (ix)
	ld	d, #0x00
	push	bc
	push	de
	call	___sint2fs
	pop	af
	ex	de, hl
	push	hl
	push	de
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	push	hl
	ld	l,-8 (ix)
	ld	h,-7 (ix)
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
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;src/main.c:105: strcpy (c->name, name);
	ld	hl, #0x000b
	add	hl,bc
	ex	de,hl
	ld	l,12 (ix)
	ld	h,13 (ix)
	xor	a, a
00103$:
	cp	a, (hl)
	ldi
	jr	NZ, 00103$
	ld	sp, ix
	pop	ix
	ret
;src/main.c:110: void PrintCharacterStats (struct TCharacter *c, u8 y,
;	---------------------------------
; Function PrintCharacterStats
; ---------------------------------
_PrintCharacterStats::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-14
	add	hl, sp
	ld	sp, hl
;src/main.c:114: PrintAt (10,y, c->name, color1); PrintAt (21,y, c->_spr, color2);
	ld	a, 4 (ix)
	ld	-2 (ix), a
	ld	a, 5 (ix)
	ld	-1 (ix), a
	ld	a, -2 (ix)
	add	a, #0x0b
	ld	c, a
	ld	a, -1 (ix)
	adc	a, #0x00
	ld	b, a
	ld	a, 7 (ix)
	push	af
	inc	sp
	push	bc
	ld	d, 6 (ix)
	ld	e,#0x0a
	push	de
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	ld	a, -2 (ix)
	add	a, #0x09
	ld	c, a
	ld	a, -1 (ix)
	adc	a, #0x00
	ld	b, a
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	bc
	ld	d, 6 (ix)
	ld	e,#0x15
	push	de
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:115: PrintAt (1, y+1, "STR ",color1);
	ld	b, 6 (ix)
	inc	b
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	push	bc
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:116: PrintAt (10,y+1, "DES ",color1);
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_1
	push	hl
	push	bc
	inc	sp
	ld	a, #0x0a
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:117: PrintAt (20,y+1, "REF ",color1);
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	push	bc
	inc	sp
	ld	a, #0x14
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:118: sprintf (num, "[%d] ", c->_str);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	inc	hl
	inc	hl
	ld	e, (hl)
	ld	d, #0x00
	ld	hl, #0x0000
	add	hl, sp
	ld	-4 (ix), l
	ld	-3 (ix), h
	push	bc
	push	de
	ld	de, #___str_3
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:119: PrintAt (5,y+1, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x05
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:120: sprintf (num, "[%d] ", c->_destr);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	inc	hl
	inc	hl
	inc	hl
	ld	e, (hl)
	ld	d, #0x00
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_3
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:121: PrintAt (15,y+1, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x0f
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:122: sprintf (num, "[%d] ", c->_refl);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0004
	add	hl, de
	ld	e, (hl)
	ld	d, #0x00
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_3
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:123: PrintAt (25,y+1, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x19
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:125: PrintAt (1, y+2, "ATK ", color1);
	ld	b, 6 (ix)
	inc	b
	inc	b
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_4
	push	hl
	push	bc
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:126: PrintAt (10,y+2, "DEF ", color1);
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_5
	push	hl
	push	bc
	inc	sp
	ld	a, #0x0a
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:127: PrintAt (20,y+2, " HP ", color1);
	push	bc
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	hl, #___str_6
	push	hl
	push	bc
	inc	sp
	ld	a, #0x14
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:128: sprintf (num, "[%d] ", c->_atk);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0005
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_3
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:129: PrintAt (5,y+2, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x05
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:130: sprintf (num, "[%d] ",c->_defense);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	de, #0x0007
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_3
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:131: PrintAt (15,y+2, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x0f
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:132: sprintf (num, "[%d]\r\n", c->_hp);
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	push	bc
	push	de
	ld	de, #___str_7
	push	de
	push	hl
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:133: PrintAt (25,y+2, num, color2);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	push	bc
	inc	sp
	ld	a, #0x19
	push	af
	inc	sp
	call	_PrintAt
	ld	sp,ix
	pop	ix
	ret
___str_0:
	.ascii "STR "
	.db 0x00
___str_1:
	.ascii "DES "
	.db 0x00
___str_2:
	.ascii "REF "
	.db 0x00
___str_3:
	.ascii "[%d] "
	.db 0x00
___str_4:
	.ascii "ATK "
	.db 0x00
___str_5:
	.ascii "DEF "
	.db 0x00
___str_6:
	.ascii " HP "
	.db 0x00
___str_7:
	.ascii "[%d]"
	.db 0x0d
	.db 0x0a
	.db 0x00
;src/main.c:138: void ClearStatusLine()
;	---------------------------------
; Function ClearStatusLine
; ---------------------------------
_ClearStatusLine::
;src/main.c:141: for (row = 20; row <=23; ++row) {
	ld	b, #0x14
00102$:
;src/main.c:142: PrintAt (1,row, "                                        ", 0xff);
	push	bc
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_8
	push	hl
	push	bc
	inc	sp
	ld	a, #0x01
	push	af
	inc	sp
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
	pop	bc
;src/main.c:141: for (row = 20; row <=23; ++row) {
	inc	b
	ld	a, #0x17
	sub	a, b
	jr	NC,00102$
	ret
___str_8:
	.ascii "                                        "
	.db 0x00
;src/main.c:148: u8 CalculateDamage (struct TCharacter *c)
;	---------------------------------
; Function CalculateDamage
; ---------------------------------
_CalculateDamage::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:150: return (c->_atk*c->_atk)/(5*c->_defense);
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	l, c
	ld	h, b
	ld	de, #0x0005
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	bc
	push	de
	push	de
	call	__mulint
	pop	af
	pop	af
	ex	de,hl
	pop	hl
	ld	bc, #0x0007
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	push	hl
	push	de
	call	__divuint
	pop	af
	pop	af
	pop	ix
	ret
;src/main.c:155: void TakeDamage (struct TCharacter *c, u8 dmg)
;	---------------------------------
; Function TakeDamage
; ---------------------------------
_TakeDamage::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:157: c->_hp -= dmg;
	ld	l,4 (ix)
	ld	h,5 (ix)
	push	hl
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	pop	hl
	ld	e, 6 (ix)
	ld	d, #0x00
	ld	a, c
	sub	a, e
	ld	c, a
	ld	a, b
	sbc	a, d
	ld	b, a
	ld	(hl), c
	inc	hl
	ld	(hl), b
	pop	ix
	ret
;src/main.c:162: void main(void) {
;	---------------------------------
; Function main
; ---------------------------------
_main::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-56
	add	hl, sp
	ld	sp, hl
;src/main.c:170: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
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
;src/main.c:171: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
	ld	l, #0x01
	call	_cpct_setVideoMode
;src/main.c:172: border (1,1); paper (0); pen (1);
	ld	hl, #0x0101
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
;src/main.c:174: PrintAt (1,5, "      )   ___    _____    )   ___      ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_9
	push	hl
	ld	hl, #0x0501
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:175: PrintAt (1,6, "     (__/_____) (, /   ) (__/_____)    ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_10
	push	hl
	ld	hl, #0x0601
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:176: PrintAt (1,7, "       /         _/__ /    /           ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_11
	push	hl
	ld	hl, #0x0701
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:177: PrintAt (1,8, "      /          /        /            ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_12
	push	hl
	ld	hl, #0x0801
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:178: PrintAt (1,9, "     (______) ) /        (______)      ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_13
	push	hl
	ld	hl, #0x0901
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:179: PrintAt (1,10, "            _(_/_                      ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_14
	push	hl
	ld	hl, #0x0a01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:180: PrintAt (1,11, "           (, /   )                    ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_15
	push	hl
	ld	hl, #0x0b01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:181: PrintAt (1,12, "             /__ / ___      _          ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_16
	push	hl
	ld	hl, #0x0c01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:184: PrintAt (1,13, "          ) /   \\_(_(_/(_(_(/_         ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_17
	push	hl
	ld	hl, #0x0d01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:185: PrintAt (1,14, "         (_/       .-/                 ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_18
	push	hl
	ld	hl, #0x0e01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:186: PrintAt (1,15, "                  (_/                  ", 0xff);
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_19
	push	hl
	ld	hl, #0x0f01
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:187: PrintAt (10, 18, "PRESS ENTER TO START", 2);
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_20
	push	hl
	ld	hl, #0x120a
	push	hl
	call	_PrintAt
	pop	af
;src/main.c:188: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);
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
	inc	sp
	ld	hl,#0x0303
	ex	(sp),hl
	call	_border
	pop	af
;src/main.c:191: while (!cpct_isKeyPressed (Key_Return)) {
00101$:
	ld	hl, #0x0402
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	NZ,00103$
;src/main.c:192: cpct_scanKeyboard ();
	call	_cpct_scanKeyboard
	jr	00101$
00103$:
;src/main.c:196: border (0,0); ink (0, 0,0); ink (1, 25,25); ink (2, 20,20);
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
;src/main.c:197: paper (0); pen (2); cls ();
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
;src/main.c:200: InitializeCharacter (&player, 150, 17, 14, 12, '@', "Player");
	ld	de, #___str_21+0
	ld	hl, #0x001a
	add	hl, sp
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	c, l
	ld	b, h
	push	de
	ld	hl, #0x400c
	push	hl
	ld	hl, #0x0e11
	push	hl
	ld	hl, #0x0096
	push	hl
	push	bc
	call	_InitializeCharacter
	ld	hl, #10
	add	hl, sp
	ld	sp, hl
;src/main.c:201: InitializeCharacter (&goblin, 100, 12, 13, 11, 'g', "Goblin");
	ld	de, #___str_22+0
	ld	hl, #0x0000
	add	hl, sp
	ld	-4 (ix), l
	ld	-3 (ix), h
	ld	c, l
	ld	b, h
	push	de
	ld	hl, #0x670b
	push	hl
	ld	hl, #0x0d0c
	push	hl
	ld	hl, #0x0064
	push	hl
	push	bc
	call	_InitializeCharacter
	ld	hl, #10
	add	hl, sp
	ld	sp, hl
;src/main.c:204: do {
00111$:
;src/main.c:205: locate (1,1);
	ld	hl, #0x0101
	push	hl
	call	_locate
	pop	af
;src/main.c:207: PrintCharacterStats (&player, 1, 1,2);
	ld	c,-2 (ix)
	ld	b,-1 (ix)
	ld	hl, #0x0201
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	push	bc
	call	_PrintCharacterStats
	pop	af
	pop	af
	inc	sp
;src/main.c:208: PrintCharacterStats (&goblin, 5, 1,2);
	ld	c,-4 (ix)
	ld	b,-3 (ix)
	ld	hl, #0x0201
	push	hl
	ld	a, #0x05
	push	af
	inc	sp
	push	bc
	call	_PrintCharacterStats
	pop	af
	pop	af
	inc	sp
;src/main.c:211: PrintAt (1,20, "ACTION? ", 1);
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #___str_23
	push	hl
	ld	hl, #0x1401
	push	hl
	call	_PrintAt
	pop	af
	pop	af
	inc	sp
;src/main.c:213: cpct_scanKeyboard();
	call	_cpct_scanKeyboard
;src/main.c:214: while (!cpct_isKeyPressed (Key_A)) {
00104$:
	ld	hl, #0x2008
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	NZ,00106$
;src/main.c:215: cpct_scanKeyboard();
	call	_cpct_scanKeyboard
	jr	00104$
00106$:
;src/main.c:218: ClearStatusLine();
	call	_ClearStatusLine
;src/main.c:220: if (cpct_isKeyPressed (Key_A)) {
	ld	hl, #0x2008
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00108$
;src/main.c:221: dmg=CalculateDamage (&player);
	ld	c,-2 (ix)
	ld	b,-1 (ix)
	push	bc
	call	_CalculateDamage
	pop	af
	ld	b, l
;src/main.c:222: TakeDamage (&goblin, dmg);
	ld	e,-4 (ix)
	ld	d,-3 (ix)
	push	bc
	push	bc
	inc	sp
	push	de
	call	_TakeDamage
	inc	sp
	ld	hl,#0x1501
	ex	(sp),hl
	call	_locate
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	pop	bc
	ld	de, #___str_24
	push	bc
	push	de
	call	_printf
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	pop	bc
	ld	c, b
	ld	b, #0x00
	push	bc
	ld	hl, #___str_25
	push	hl
	call	_printf
	pop	af
;src/main.c:225: pen (1); printf (" hit points");
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_26
	push	hl
	call	_printf
	pop	af
00108$:
;src/main.c:228: if (cpct_rand() < 64) {
	call	_cpct_getRandom_mxor_u8
	ld	a, l
	sub	a, #0x40
	jp	NC, 00111$
;src/main.c:229: dmg=CalculateDamage (&goblin);
	ld	c,-4 (ix)
	ld	b,-3 (ix)
	push	bc
	call	_CalculateDamage
	pop	af
	ld	b, l
;src/main.c:230: TakeDamage (&player, dmg);
	ld	e,-2 (ix)
	ld	d,-1 (ix)
	push	bc
	push	bc
	inc	sp
	push	de
	call	_TakeDamage
	inc	sp
	ld	hl,#0x1601
	ex	(sp),hl
	call	_locate
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_27
	push	hl
	call	_printf
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	pop	bc
	ld	c, b
	ld	b, #0x00
	push	bc
	ld	hl, #___str_25
	push	hl
	call	_printf
	pop	af
;src/main.c:233: pen (1); printf (" hit points from goblin");
	ld	h,#0x01
	ex	(sp),hl
	inc	sp
	call	_pen
	inc	sp
	ld	hl, #___str_28
	push	hl
	call	_printf
	pop	af
;src/main.c:235: } while (1);
	jp	00111$
___str_9:
	.ascii "      )   ___    _____    )   ___      "
	.db 0x00
___str_10:
	.ascii "     (__/_____) (, /   ) (__/_____)    "
	.db 0x00
___str_11:
	.ascii "       /         _/__ /    /           "
	.db 0x00
___str_12:
	.ascii "      /          /        /            "
	.db 0x00
___str_13:
	.ascii "     (______) ) /        (______)      "
	.db 0x00
___str_14:
	.ascii "            _(_/_                      "
	.db 0x00
___str_15:
	.ascii "           (, /   )                    "
	.db 0x00
___str_16:
	.ascii "             /__ / ___      _          "
	.db 0x00
___str_17:
	.ascii "          ) /   "
	.db 0x5c
	.ascii "_(_(_/(_(_(/_         "
	.db 0x00
___str_18:
	.ascii "         (_/       .-/                 "
	.db 0x00
___str_19:
	.ascii "                  (_/                  "
	.db 0x00
___str_20:
	.ascii "PRESS ENTER TO START"
	.db 0x00
___str_21:
	.ascii "Player"
	.db 0x00
___str_22:
	.ascii "Goblin"
	.db 0x00
___str_23:
	.ascii "ACTION? "
	.db 0x00
___str_24:
	.ascii "goblin takes "
	.db 0x00
___str_25:
	.ascii "%d"
	.db 0x00
___str_26:
	.ascii " hit points"
	.db 0x00
___str_27:
	.ascii "you take "
	.db 0x00
___str_28:
	.ascii " hit points from goblin"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
