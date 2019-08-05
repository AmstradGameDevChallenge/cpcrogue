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
	.globl _ShowLogo
	.globl _HandleKeyboard
	.globl _MapDraw
	.globl _MapIsBlocked
	.globl _MapCreate
	.globl _EntityPrintStats
	.globl _EntityDrawEntities
	.globl _GetBlockingEntity
	.globl _EntityAttack
	.globl _EntityMove
	.globl _EntityInit
	.globl _paper
	.globl _ink
	.globl _putchar
	.globl _cpct_scanKeyboard
	.globl _cpct_waitHalts
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
;src/main.c:35: void InitColors()
;	---------------------------------
; Function InitColors
; ---------------------------------
_InitColors::
;src/main.c:37: ink (0, 0,0);
	ld	hl, #0x0000
	push	hl
	xor	a, a
	push	af
	inc	sp
	call	_ink
;src/main.c:38: ink (PEN_ENTITY, INK_ENTITY, INK_ENTITY);
	inc	sp
	ld	hl,#0x1414
	ex	(sp),hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_ink
;src/main.c:39: ink (PEN_TILE, INK_LIGHT_TILE, INK_LIGHT_TILE);
	inc	sp
	ld	hl,#0x0d0d
	ex	(sp),hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_ink
;src/main.c:40: ink (PEN_EXLORED, INK_DARK_TILE, INK_DARK_TILE);
	inc	sp
	ld	hl,#0x0101
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
;src/main.c:42: border (0); paper (0);
	xor	a, a
	push	af
	inc	sp
	call	_paper
	inc	sp
	ret
;src/main.c:62: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;src/main.c:66: for (ei=0; ei!=5; ++ei) {
	ld	c, #0x00
00126$:
;src/main.c:67: edx[ei]=1; edx[9-ei]=-1;
	ld	hl, #_edx
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
	ld	a, #0x09
	sub	a, c
	ld	e, a
	ld	hl, #_edx
	ld	d, #0x00
	add	hl, de
	ld	(hl), #0xff
;src/main.c:66: for (ei=0; ei!=5; ++ei) {
	inc	c
	ld	a, c
	sub	a, #0x05
	jr	NZ,00126$
;src/main.c:70: ShowLogo();
	ld	-1 (ix), c
	call	_ShowLogo
;src/conio.h:14: inline void cls () { putchar (FF); }
	ld	hl, #0x000c
	push	hl
	call	_putchar
	pop	af
;src/main.c:73: InitColors();
	call	_InitColors
;src/main.c:74: EntityInit (&player, 3, 3, SPR_PLAYER, PEN_ENTITY, "Thorbag", TRUE,
	ld	hl, #0x0c0e
	push	hl
	ld	a, #0x11
	push	af
	inc	sp
	ld	hl, #0x0014
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	ld	hl, #0x0140
	push	hl
	ld	hl, #0x0303
	push	hl
	ld	hl, #_player
	push	hl
	call	_EntityInit
	ld	hl, #14
	add	hl, sp
	ld	sp, hl
;src/main.c:76: EntityInit (&enemy, 19, 3, SPR_GOBLIN, PEN_ENTITY, "Goblin", TRUE,
	ld	hl, #0x0b0d
	push	hl
	ld	a, #0x0c
	push	af
	inc	sp
	ld	hl, #0x000a
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #___str_1
	push	hl
	ld	hl, #0x0167
	push	hl
	ld	hl, #0x0313
	push	hl
	ld	hl, #_enemy
	push	hl
	call	_EntityInit
	ld	hl, #14
	add	hl, sp
	ld	sp, hl
;src/main.c:79: entities[0] = &player;
	ld	hl, #_player
	ld	(_entities), hl
;src/main.c:80: entities[1] = &enemy;
	ld	hl, #_enemy
	ld	((_entities + 0x0002)), hl
;src/main.c:82: dirty[0] = FALSE;
	ld	hl, #_dirty
	ld	(hl), #0x00
;src/main.c:83: dirty[1] = FALSE;
	ld	hl, #(_dirty + 0x0001)
	ld	(hl), #0x00
;src/main.c:85: MapCreate (MAP_WIDTH, MAP_HEIGHT);
	ld	hl, #0x141c
	push	hl
	call	_MapCreate
	pop	af
;src/main.c:86: MapDraw ();
	call	_MapDraw
;src/main.c:88: EntityPrintStats(&player);
	ld	hl, #_player
	push	hl
	call	_EntityPrintStats
	pop	af
;src/main.c:91: state = PLAYER_TURN;
	ld	hl,#_state + 0
	ld	(hl), #0x00
;src/main.c:92: do {
00122$:
;src/main.c:94: EntityDrawEntities(entities, dirty);
	ld	hl, #_dirty
	push	hl
	ld	hl, #_entities
	push	hl
	call	_EntityDrawEntities
	pop	af
	pop	af
;src/main.c:97: cpct_scanKeyboard();
	call	_cpct_scanKeyboard
;src/main.c:100: dx=0; dy=0;
	ld	hl,#_dx + 0
	ld	(hl), #0x00
	ld	hl,#_dy + 0
	ld	(hl), #0x00
;src/main.c:101: action = HandleKeyboard (&dx, &dy);
	ld	hl, #_dy
	push	hl
	ld	hl, #_dx
	push	hl
	call	_HandleKeyboard
	pop	af
	pop	af
	ld	iy, #_action
	ld	0 (iy), l
;src/main.c:103: new_x = player.x+dx;
	ld	a,(#_player + 0)
	ld	hl, #_dx
	ld	iy, #_new_x
	add	a, (hl)
	ld	0 (iy), a
;src/main.c:104: new_y = player.y+dy;
	ld	a,(#_player + 1)
	ld	hl, #_dy
	ld	iy, #_new_y
	add	a, (hl)
	ld	0 (iy), a
;src/main.c:105: if (action == PLAYER_MOVE && state == PLAYER_TURN) {
	ld	a,(#_action + 0)
	dec	a
	jr	NZ,00109$
	ld	a,(#_state + 0)
	or	a, a
	jr	NZ,00109$
;src/main.c:106: if (!MapIsBlocked (new_x, new_y)) {
	ld	a, (_new_y)
	push	af
	inc	sp
	ld	a, (_new_x)
	push	af
	inc	sp
	call	_MapIsBlocked
	pop	af
	ld	a, l
	or	a, a
	jr	NZ,00109$
;src/main.c:107: if (GetBlockingEntity (entities, &target, new_x, new_y) &&
	ld	a, (_new_y)
	push	af
	inc	sp
	ld	a, (_new_x)
	push	af
	inc	sp
	ld	hl, #_target
	push	hl
	ld	hl, #_entities
	push	hl
	call	_GetBlockingEntity
	pop	af
	pop	af
	pop	af
	ld	a, l
	or	a, a
	jr	Z,00103$
;src/main.c:108: target != &player) {
	ld	iy, #_target
	ld	a, 0 (iy)
	sub	a, #<(_player)
	jr	NZ,00187$
	ld	a, 1 (iy)
	sub	a, #>(_player)
	jr	Z,00103$
00187$:
;src/main.c:110: EntityAttack (&player, target);
	ld	hl, (_target)
	push	hl
	ld	hl, #_player
	push	hl
	call	_EntityAttack
	pop	af
	pop	af
	jr	00104$
00103$:
;src/main.c:113: dirty[0] = TRUE;
	ld	hl, #_dirty
	ld	(hl), #0x01
;src/main.c:114: EntityMove (&player, dx, dy);
	ld	a, (_dy)
	push	af
	inc	sp
	ld	a, (_dx)
	push	af
	inc	sp
	ld	hl, #_player
	push	hl
	call	_EntityMove
	pop	af
	pop	af
00104$:
;src/main.c:116: cpct_waitHalts(25);
	ld	l, #0x19
	call	_cpct_waitHalts
;src/main.c:117: state = ENEMY_TURN;
	ld	hl,#_state + 0
	ld	(hl), #0x01
00109$:
;src/main.c:120: if (state == ENEMY_TURN) {
	ld	a,(#_state + 0)
	dec	a
	jp	NZ,00122$
;src/main.c:121: cpct_waitHalts(25);
	ld	l, #0x19
	call	_cpct_waitHalts
;src/main.c:123: new_x = enemy.x + edx[ei];
	ld	hl, #_enemy + 0
	ld	b, (hl)
	ld	a, #<(_edx)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_edx)
	adc	a, #0x00
	ld	h, a
	ld	c, (hl)
	ld	a, b
	ld	hl, #_new_x
	add	a, c
	ld	(hl), a
;src/main.c:124: new_y = enemy.y;
	ld	a,(#_enemy + 1)
	ld	(#_new_y + 0),a
;src/main.c:125: if (!MapIsBlocked (new_x, new_y)) {
	ld	a, (_new_y)
	push	af
	inc	sp
	ld	a, (_new_x)
	push	af
	inc	sp
	call	_MapIsBlocked
	pop	af
;src/main.c:132: EntityMove (&enemy, edx[ei++], edy);
	ld	c, -1 (ix)
	inc	c
;src/main.c:125: if (!MapIsBlocked (new_x, new_y)) {
	ld	a, l
	or	a, a
	jr	NZ,00116$
;src/main.c:126: if (GetBlockingEntity (entities, &target, new_x, new_y) &&
	push	bc
	ld	a, (_new_y)
	push	af
	inc	sp
	ld	a, (_new_x)
	push	af
	inc	sp
	ld	hl, #_target
	push	hl
	ld	hl, #_entities
	push	hl
	call	_GetBlockingEntity
	pop	af
	pop	af
	pop	af
	pop	bc
	ld	a, l
	or	a, a
	jr	Z,00112$
;src/main.c:127: target != &enemy) {
	ld	iy, #_target
	ld	a, 0 (iy)
	sub	a, #<(_enemy)
	jr	NZ,00190$
	ld	a, 1 (iy)
	sub	a, #>(_enemy)
	jr	Z,00112$
00190$:
;src/main.c:128: EntityAttack (&enemy, target);
	ld	hl, (_target)
	push	hl
	ld	hl, #_enemy
	push	hl
	call	_EntityAttack
	pop	af
;src/main.c:129: EntityPrintStats(&player);
	ld	hl, #_player
	ex	(sp),hl
	call	_EntityPrintStats
	pop	af
	jr	00117$
00112$:
;src/main.c:132: EntityMove (&enemy, edx[ei++], edy);
	ld	e, -1 (ix)
	ld	-1 (ix), c
	ld	hl, #_edx
	ld	d, #0x00
	add	hl, de
	ld	b, (hl)
	ld	de, #_enemy
	ld	a, (_edy)
	push	af
	inc	sp
	push	bc
	inc	sp
	push	de
	call	_EntityMove
	pop	af
	pop	af
;src/main.c:133: dirty[1] = TRUE;
	ld	hl, #(_dirty + 0x0001)
	ld	(hl), #0x01
	jr	00117$
00116$:
;src/main.c:136: else ++ei;
	ld	-1 (ix), c
00117$:
;src/main.c:137: if (ei > 9) ei = 0;
	ld	a, #0x09
	sub	a, -1 (ix)
	jr	NC,00119$
	ld	-1 (ix), #0x00
00119$:
;src/main.c:139: state = PLAYER_TURN;
	ld	hl,#_state + 0
	ld	(hl), #0x00
;src/main.c:141: } while (1);
	jp	00122$
	inc	sp
	pop	ix
	ret
___str_0:
	.ascii "Thorbag"
	.db 0x00
___str_1:
	.ascii "Goblin"
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
