                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module main
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _main
                             12 	.globl _InitColors
                             13 	.globl _ShowLogo
                             14 	.globl _HandleKeyboard
                             15 	.globl _MapDraw
                             16 	.globl _MapIsBlocked
                             17 	.globl _MapCreate
                             18 	.globl _EntityPrintStats
                             19 	.globl _EntityDrawEntities
                             20 	.globl _GetBlockingEntity
                             21 	.globl _EntityAttack
                             22 	.globl _EntityMove
                             23 	.globl _EntityInit
                             24 	.globl _paper
                             25 	.globl _ink
                             26 	.globl _putchar
                             27 	.globl _cpct_scanKeyboard
                             28 	.globl _cpct_waitHalts
                             29 	.globl _edy
                             30 	.globl _target
                             31 	.globl _action
                             32 	.globl _new_y
                             33 	.globl _new_x
                             34 	.globl _edx
                             35 	.globl _dy
                             36 	.globl _dx
                             37 	.globl _state
                             38 	.globl _entities
                             39 	.globl _dirty
                             40 	.globl _enemy
                             41 	.globl _player
                             42 ;--------------------------------------------------------
                             43 ; special function registers
                             44 ;--------------------------------------------------------
                             45 ;--------------------------------------------------------
                             46 ; ram data
                             47 ;--------------------------------------------------------
                             48 	.area _DATA
   5C23                      49 _player::
   5C23                      50 	.ds 33
   5C44                      51 _enemy::
   5C44                      52 	.ds 33
   5C65                      53 _dirty::
   5C65                      54 	.ds 5
   5C6A                      55 _entities::
   5C6A                      56 	.ds 10
   5C74                      57 _state::
   5C74                      58 	.ds 1
   5C75                      59 _dx::
   5C75                      60 	.ds 1
   5C76                      61 _dy::
   5C76                      62 	.ds 1
   5C77                      63 _edx::
   5C77                      64 	.ds 10
   5C81                      65 _new_x::
   5C81                      66 	.ds 1
   5C82                      67 _new_y::
   5C82                      68 	.ds 1
                             69 ;--------------------------------------------------------
                             70 ; ram data
                             71 ;--------------------------------------------------------
                             72 	.area _INITIALIZED
   5C83                      73 _action::
   5C83                      74 	.ds 1
   5C84                      75 _target::
   5C84                      76 	.ds 2
   5C86                      77 _edy::
   5C86                      78 	.ds 1
                             79 ;--------------------------------------------------------
                             80 ; absolute external ram data
                             81 ;--------------------------------------------------------
                             82 	.area _DABS (ABS)
                             83 ;--------------------------------------------------------
                             84 ; global & static initialisations
                             85 ;--------------------------------------------------------
                             86 	.area _HOME
                             87 	.area _GSINIT
                             88 	.area _GSFINAL
                             89 	.area _GSINIT
                             90 ;--------------------------------------------------------
                             91 ; Home
                             92 ;--------------------------------------------------------
                             93 	.area _HOME
                             94 	.area _HOME
                             95 ;--------------------------------------------------------
                             96 ; code
                             97 ;--------------------------------------------------------
                             98 	.area _CODE
                             99 ;src/main.c:35: void InitColors()
                            100 ;	---------------------------------
                            101 ; Function InitColors
                            102 ; ---------------------------------
   4A3F                     103 _InitColors::
                            104 ;src/main.c:37: ink (0, 0,0);
   4A3F 21 00 00      [10]  105 	ld	hl, #0x0000
   4A42 E5            [11]  106 	push	hl
   4A43 AF            [ 4]  107 	xor	a, a
   4A44 F5            [11]  108 	push	af
   4A45 33            [ 6]  109 	inc	sp
   4A46 CD 7D 44      [17]  110 	call	_ink
                            111 ;src/main.c:38: ink (PEN_ENTITY, INK_ENTITY, INK_ENTITY);
   4A49 33            [ 6]  112 	inc	sp
   4A4A 21 14 14      [10]  113 	ld	hl,#0x1414
   4A4D E3            [19]  114 	ex	(sp),hl
   4A4E 3E 01         [ 7]  115 	ld	a, #0x01
   4A50 F5            [11]  116 	push	af
   4A51 33            [ 6]  117 	inc	sp
   4A52 CD 7D 44      [17]  118 	call	_ink
                            119 ;src/main.c:39: ink (PEN_TILE, INK_LIGHT_TILE, INK_LIGHT_TILE);
   4A55 33            [ 6]  120 	inc	sp
   4A56 21 0D 0D      [10]  121 	ld	hl,#0x0d0d
   4A59 E3            [19]  122 	ex	(sp),hl
   4A5A 3E 02         [ 7]  123 	ld	a, #0x02
   4A5C F5            [11]  124 	push	af
   4A5D 33            [ 6]  125 	inc	sp
   4A5E CD 7D 44      [17]  126 	call	_ink
                            127 ;src/main.c:40: ink (PEN_EXLORED, INK_DARK_TILE, INK_DARK_TILE);
   4A61 33            [ 6]  128 	inc	sp
   4A62 21 01 01      [10]  129 	ld	hl,#0x0101
   4A65 E3            [19]  130 	ex	(sp),hl
   4A66 3E 03         [ 7]  131 	ld	a, #0x03
   4A68 F5            [11]  132 	push	af
   4A69 33            [ 6]  133 	inc	sp
   4A6A CD 7D 44      [17]  134 	call	_ink
                            135 ;src/conio.h:9: putchar (GS);
   4A6D 33            [ 6]  136 	inc	sp
   4A6E 21 1D 00      [10]  137 	ld	hl,#0x001d
   4A71 E3            [19]  138 	ex	(sp),hl
   4A72 CD E4 4C      [17]  139 	call	_putchar
                            140 ;src/conio.h:10: putchar (color1); putchar (color1);
   4A75 21 00 00      [10]  141 	ld	hl, #0x0000
   4A78 E3            [19]  142 	ex	(sp),hl
   4A79 CD E4 4C      [17]  143 	call	_putchar
   4A7C 21 00 00      [10]  144 	ld	hl, #0x0000
   4A7F E3            [19]  145 	ex	(sp),hl
   4A80 CD E4 4C      [17]  146 	call	_putchar
   4A83 F1            [10]  147 	pop	af
                            148 ;src/main.c:42: border (0); paper (0);
   4A84 AF            [ 4]  149 	xor	a, a
   4A85 F5            [11]  150 	push	af
   4A86 33            [ 6]  151 	inc	sp
   4A87 CD AA 44      [17]  152 	call	_paper
   4A8A 33            [ 6]  153 	inc	sp
   4A8B C9            [10]  154 	ret
                            155 ;src/main.c:62: void main()
                            156 ;	---------------------------------
                            157 ; Function main
                            158 ; ---------------------------------
   4A8C                     159 _main::
   4A8C DD E5         [15]  160 	push	ix
   4A8E DD 21 00 00   [14]  161 	ld	ix,#0
   4A92 DD 39         [15]  162 	add	ix,sp
   4A94 3B            [ 6]  163 	dec	sp
                            164 ;src/main.c:66: for (ei=0; ei!=5; ++ei) {
   4A95 0E 00         [ 7]  165 	ld	c, #0x00
   4A97                     166 00126$:
                            167 ;src/main.c:67: edx[ei]=1; edx[9-ei]=-1;
   4A97 21 77 5C      [10]  168 	ld	hl, #_edx
   4A9A 06 00         [ 7]  169 	ld	b, #0x00
   4A9C 09            [11]  170 	add	hl, bc
   4A9D 36 01         [10]  171 	ld	(hl), #0x01
   4A9F 3E 09         [ 7]  172 	ld	a, #0x09
   4AA1 91            [ 4]  173 	sub	a, c
   4AA2 5F            [ 4]  174 	ld	e, a
   4AA3 21 77 5C      [10]  175 	ld	hl, #_edx
   4AA6 16 00         [ 7]  176 	ld	d, #0x00
   4AA8 19            [11]  177 	add	hl, de
   4AA9 36 FF         [10]  178 	ld	(hl), #0xff
                            179 ;src/main.c:66: for (ei=0; ei!=5; ++ei) {
   4AAB 0C            [ 4]  180 	inc	c
   4AAC 79            [ 4]  181 	ld	a, c
   4AAD D6 05         [ 7]  182 	sub	a, #0x05
   4AAF 20 E6         [12]  183 	jr	NZ,00126$
                            184 ;src/main.c:70: ShowLogo();
   4AB1 DD 71 FF      [19]  185 	ld	-1 (ix), c
   4AB4 CD 0B 41      [17]  186 	call	_ShowLogo
                            187 ;src/conio.h:14: inline void cls () { putchar (FF); }
   4AB7 21 0C 00      [10]  188 	ld	hl, #0x000c
   4ABA E5            [11]  189 	push	hl
   4ABB CD E4 4C      [17]  190 	call	_putchar
   4ABE F1            [10]  191 	pop	af
                            192 ;src/main.c:73: InitColors();
   4ABF CD 3F 4A      [17]  193 	call	_InitColors
                            194 ;src/main.c:74: EntityInit (&player, 3, 3, SPR_PLAYER, PEN_ENTITY, "Thorbag", TRUE,
   4AC2 21 0E 0C      [10]  195 	ld	hl, #0x0c0e
   4AC5 E5            [11]  196 	push	hl
   4AC6 3E 11         [ 7]  197 	ld	a, #0x11
   4AC8 F5            [11]  198 	push	af
   4AC9 33            [ 6]  199 	inc	sp
   4ACA 21 14 00      [10]  200 	ld	hl, #0x0014
   4ACD E5            [11]  201 	push	hl
   4ACE 3E 01         [ 7]  202 	ld	a, #0x01
   4AD0 F5            [11]  203 	push	af
   4AD1 33            [ 6]  204 	inc	sp
   4AD2 21 C9 4C      [10]  205 	ld	hl, #___str_0
   4AD5 E5            [11]  206 	push	hl
   4AD6 21 40 01      [10]  207 	ld	hl, #0x0140
   4AD9 E5            [11]  208 	push	hl
   4ADA 21 03 03      [10]  209 	ld	hl, #0x0303
   4ADD E5            [11]  210 	push	hl
   4ADE 21 23 5C      [10]  211 	ld	hl, #_player
   4AE1 E5            [11]  212 	push	hl
   4AE2 CD 5A 45      [17]  213 	call	_EntityInit
   4AE5 21 0E 00      [10]  214 	ld	hl, #14
   4AE8 39            [11]  215 	add	hl, sp
   4AE9 F9            [ 6]  216 	ld	sp, hl
                            217 ;src/main.c:76: EntityInit (&enemy, 19, 3, SPR_GOBLIN, PEN_ENTITY, "Goblin", TRUE,
   4AEA 21 0D 0B      [10]  218 	ld	hl, #0x0b0d
   4AED E5            [11]  219 	push	hl
   4AEE 3E 0C         [ 7]  220 	ld	a, #0x0c
   4AF0 F5            [11]  221 	push	af
   4AF1 33            [ 6]  222 	inc	sp
   4AF2 21 0A 00      [10]  223 	ld	hl, #0x000a
   4AF5 E5            [11]  224 	push	hl
   4AF6 3E 01         [ 7]  225 	ld	a, #0x01
   4AF8 F5            [11]  226 	push	af
   4AF9 33            [ 6]  227 	inc	sp
   4AFA 21 D1 4C      [10]  228 	ld	hl, #___str_1
   4AFD E5            [11]  229 	push	hl
   4AFE 21 67 01      [10]  230 	ld	hl, #0x0167
   4B01 E5            [11]  231 	push	hl
   4B02 21 13 03      [10]  232 	ld	hl, #0x0313
   4B05 E5            [11]  233 	push	hl
   4B06 21 44 5C      [10]  234 	ld	hl, #_enemy
   4B09 E5            [11]  235 	push	hl
   4B0A CD 5A 45      [17]  236 	call	_EntityInit
   4B0D 21 0E 00      [10]  237 	ld	hl, #14
   4B10 39            [11]  238 	add	hl, sp
   4B11 F9            [ 6]  239 	ld	sp, hl
                            240 ;src/main.c:79: entities[0] = &player;
   4B12 21 23 5C      [10]  241 	ld	hl, #_player
   4B15 22 6A 5C      [16]  242 	ld	(_entities), hl
                            243 ;src/main.c:80: entities[1] = &enemy;
   4B18 21 44 5C      [10]  244 	ld	hl, #_enemy
   4B1B 22 6C 5C      [16]  245 	ld	((_entities + 0x0002)), hl
                            246 ;src/main.c:82: dirty[0] = FALSE;
   4B1E 21 65 5C      [10]  247 	ld	hl, #_dirty
   4B21 36 00         [10]  248 	ld	(hl), #0x00
                            249 ;src/main.c:83: dirty[1] = FALSE;
   4B23 21 66 5C      [10]  250 	ld	hl, #(_dirty + 0x0001)
   4B26 36 00         [10]  251 	ld	(hl), #0x00
                            252 ;src/main.c:85: MapCreate (MAP_WIDTH, MAP_HEIGHT);
   4B28 21 1C 14      [10]  253 	ld	hl, #0x141c
   4B2B E5            [11]  254 	push	hl
   4B2C CD 00 40      [17]  255 	call	_MapCreate
   4B2F F1            [10]  256 	pop	af
                            257 ;src/main.c:86: MapDraw ();
   4B30 CD 72 40      [17]  258 	call	_MapDraw
                            259 ;src/main.c:88: EntityPrintStats(&player);
   4B33 21 23 5C      [10]  260 	ld	hl, #_player
   4B36 E5            [11]  261 	push	hl
   4B37 CD 9E 48      [17]  262 	call	_EntityPrintStats
   4B3A F1            [10]  263 	pop	af
                            264 ;src/main.c:91: state = PLAYER_TURN;
   4B3B 21 74 5C      [10]  265 	ld	hl,#_state + 0
   4B3E 36 00         [10]  266 	ld	(hl), #0x00
                            267 ;src/main.c:92: do {
   4B40                     268 00122$:
                            269 ;src/main.c:94: EntityDrawEntities(entities, dirty);
   4B40 21 65 5C      [10]  270 	ld	hl, #_dirty
   4B43 E5            [11]  271 	push	hl
   4B44 21 6A 5C      [10]  272 	ld	hl, #_entities
   4B47 E5            [11]  273 	push	hl
   4B48 CD 41 48      [17]  274 	call	_EntityDrawEntities
   4B4B F1            [10]  275 	pop	af
   4B4C F1            [10]  276 	pop	af
                            277 ;src/main.c:97: cpct_scanKeyboard();
   4B4D CD BF 4D      [17]  278 	call	_cpct_scanKeyboard
                            279 ;src/main.c:100: dx=0; dy=0;
   4B50 21 75 5C      [10]  280 	ld	hl,#_dx + 0
   4B53 36 00         [10]  281 	ld	(hl), #0x00
   4B55 21 76 5C      [10]  282 	ld	hl,#_dy + 0
   4B58 36 00         [10]  283 	ld	(hl), #0x00
                            284 ;src/main.c:101: action = HandleKeyboard (&dx, &dy);
   4B5A 21 76 5C      [10]  285 	ld	hl, #_dy
   4B5D E5            [11]  286 	push	hl
   4B5E 21 75 5C      [10]  287 	ld	hl, #_dx
   4B61 E5            [11]  288 	push	hl
   4B62 CD E9 43      [17]  289 	call	_HandleKeyboard
   4B65 F1            [10]  290 	pop	af
   4B66 F1            [10]  291 	pop	af
   4B67 FD 21 83 5C   [14]  292 	ld	iy, #_action
   4B6B FD 75 00      [19]  293 	ld	0 (iy), l
                            294 ;src/main.c:103: new_x = player.x+dx;
   4B6E 3A 23 5C      [13]  295 	ld	a,(#_player + 0)
   4B71 21 75 5C      [10]  296 	ld	hl, #_dx
   4B74 FD 21 81 5C   [14]  297 	ld	iy, #_new_x
   4B78 86            [ 7]  298 	add	a, (hl)
   4B79 FD 77 00      [19]  299 	ld	0 (iy), a
                            300 ;src/main.c:104: new_y = player.y+dy;
   4B7C 3A 24 5C      [13]  301 	ld	a,(#_player + 1)
   4B7F 21 76 5C      [10]  302 	ld	hl, #_dy
   4B82 FD 21 82 5C   [14]  303 	ld	iy, #_new_y
   4B86 86            [ 7]  304 	add	a, (hl)
   4B87 FD 77 00      [19]  305 	ld	0 (iy), a
                            306 ;src/main.c:105: if (action == PLAYER_MOVE && state == PLAYER_TURN) {
   4B8A 3A 83 5C      [13]  307 	ld	a,(#_action + 0)
   4B8D 3D            [ 4]  308 	dec	a
   4B8E 20 77         [12]  309 	jr	NZ,00109$
   4B90 3A 74 5C      [13]  310 	ld	a,(#_state + 0)
   4B93 B7            [ 4]  311 	or	a, a
   4B94 20 71         [12]  312 	jr	NZ,00109$
                            313 ;src/main.c:106: if (!MapIsBlocked (new_x, new_y)) {
   4B96 3A 82 5C      [13]  314 	ld	a, (_new_y)
   4B99 F5            [11]  315 	push	af
   4B9A 33            [ 6]  316 	inc	sp
   4B9B 3A 81 5C      [13]  317 	ld	a, (_new_x)
   4B9E F5            [11]  318 	push	af
   4B9F 33            [ 6]  319 	inc	sp
   4BA0 CD 4F 40      [17]  320 	call	_MapIsBlocked
   4BA3 F1            [10]  321 	pop	af
   4BA4 7D            [ 4]  322 	ld	a, l
   4BA5 B7            [ 4]  323 	or	a, a
   4BA6 20 5F         [12]  324 	jr	NZ,00109$
                            325 ;src/main.c:107: if (GetBlockingEntity (entities, &target, new_x, new_y) &&
   4BA8 3A 82 5C      [13]  326 	ld	a, (_new_y)
   4BAB F5            [11]  327 	push	af
   4BAC 33            [ 6]  328 	inc	sp
   4BAD 3A 81 5C      [13]  329 	ld	a, (_new_x)
   4BB0 F5            [11]  330 	push	af
   4BB1 33            [ 6]  331 	inc	sp
   4BB2 21 84 5C      [10]  332 	ld	hl, #_target
   4BB5 E5            [11]  333 	push	hl
   4BB6 21 6A 5C      [10]  334 	ld	hl, #_entities
   4BB9 E5            [11]  335 	push	hl
   4BBA CD EF 47      [17]  336 	call	_GetBlockingEntity
   4BBD F1            [10]  337 	pop	af
   4BBE F1            [10]  338 	pop	af
   4BBF F1            [10]  339 	pop	af
   4BC0 7D            [ 4]  340 	ld	a, l
   4BC1 B7            [ 4]  341 	or	a, a
   4BC2 28 21         [12]  342 	jr	Z,00103$
                            343 ;src/main.c:108: target != &player) {
   4BC4 FD 21 84 5C   [14]  344 	ld	iy, #_target
   4BC8 FD 7E 00      [19]  345 	ld	a, 0 (iy)
   4BCB D6 23         [ 7]  346 	sub	a, #<(_player)
   4BCD 20 07         [12]  347 	jr	NZ,00187$
   4BCF FD 7E 01      [19]  348 	ld	a, 1 (iy)
   4BD2 D6 5C         [ 7]  349 	sub	a, #>(_player)
   4BD4 28 0F         [12]  350 	jr	Z,00103$
   4BD6                     351 00187$:
                            352 ;src/main.c:110: EntityAttack (&player, target);
   4BD6 2A 84 5C      [16]  353 	ld	hl, (_target)
   4BD9 E5            [11]  354 	push	hl
   4BDA 21 23 5C      [10]  355 	ld	hl, #_player
   4BDD E5            [11]  356 	push	hl
   4BDE CD 86 47      [17]  357 	call	_EntityAttack
   4BE1 F1            [10]  358 	pop	af
   4BE2 F1            [10]  359 	pop	af
   4BE3 18 18         [12]  360 	jr	00104$
   4BE5                     361 00103$:
                            362 ;src/main.c:113: dirty[0] = TRUE;
   4BE5 21 65 5C      [10]  363 	ld	hl, #_dirty
   4BE8 36 01         [10]  364 	ld	(hl), #0x01
                            365 ;src/main.c:114: EntityMove (&player, dx, dy);
   4BEA 3A 76 5C      [13]  366 	ld	a, (_dy)
   4BED F5            [11]  367 	push	af
   4BEE 33            [ 6]  368 	inc	sp
   4BEF 3A 75 5C      [13]  369 	ld	a, (_dx)
   4BF2 F5            [11]  370 	push	af
   4BF3 33            [ 6]  371 	inc	sp
   4BF4 21 23 5C      [10]  372 	ld	hl, #_player
   4BF7 E5            [11]  373 	push	hl
   4BF8 CD 87 46      [17]  374 	call	_EntityMove
   4BFB F1            [10]  375 	pop	af
   4BFC F1            [10]  376 	pop	af
   4BFD                     377 00104$:
                            378 ;src/main.c:116: cpct_waitHalts(25);
   4BFD 2E 19         [ 7]  379 	ld	l, #0x19
   4BFF CD FC 4C      [17]  380 	call	_cpct_waitHalts
                            381 ;src/main.c:117: state = ENEMY_TURN;
   4C02 21 74 5C      [10]  382 	ld	hl,#_state + 0
   4C05 36 01         [10]  383 	ld	(hl), #0x01
   4C07                     384 00109$:
                            385 ;src/main.c:120: if (state == ENEMY_TURN) {
   4C07 3A 74 5C      [13]  386 	ld	a,(#_state + 0)
   4C0A 3D            [ 4]  387 	dec	a
   4C0B C2 40 4B      [10]  388 	jp	NZ,00122$
                            389 ;src/main.c:121: cpct_waitHalts(25);
   4C0E 2E 19         [ 7]  390 	ld	l, #0x19
   4C10 CD FC 4C      [17]  391 	call	_cpct_waitHalts
                            392 ;src/main.c:123: new_x = enemy.x + edx[ei];
   4C13 21 44 5C      [10]  393 	ld	hl, #_enemy + 0
   4C16 46            [ 7]  394 	ld	b, (hl)
   4C17 3E 77         [ 7]  395 	ld	a, #<(_edx)
   4C19 DD 86 FF      [19]  396 	add	a, -1 (ix)
   4C1C 6F            [ 4]  397 	ld	l, a
   4C1D 3E 5C         [ 7]  398 	ld	a, #>(_edx)
   4C1F CE 00         [ 7]  399 	adc	a, #0x00
   4C21 67            [ 4]  400 	ld	h, a
   4C22 4E            [ 7]  401 	ld	c, (hl)
   4C23 78            [ 4]  402 	ld	a, b
   4C24 21 81 5C      [10]  403 	ld	hl, #_new_x
   4C27 81            [ 4]  404 	add	a, c
   4C28 77            [ 7]  405 	ld	(hl), a
                            406 ;src/main.c:124: new_y = enemy.y;
   4C29 3A 45 5C      [13]  407 	ld	a,(#_enemy + 1)
   4C2C 32 82 5C      [13]  408 	ld	(#_new_y + 0),a
                            409 ;src/main.c:125: if (!MapIsBlocked (new_x, new_y)) {
   4C2F 3A 82 5C      [13]  410 	ld	a, (_new_y)
   4C32 F5            [11]  411 	push	af
   4C33 33            [ 6]  412 	inc	sp
   4C34 3A 81 5C      [13]  413 	ld	a, (_new_x)
   4C37 F5            [11]  414 	push	af
   4C38 33            [ 6]  415 	inc	sp
   4C39 CD 4F 40      [17]  416 	call	_MapIsBlocked
   4C3C F1            [10]  417 	pop	af
                            418 ;src/main.c:132: EntityMove (&enemy, edx[ei++], edy);
   4C3D DD 4E FF      [19]  419 	ld	c, -1 (ix)
   4C40 0C            [ 4]  420 	inc	c
                            421 ;src/main.c:125: if (!MapIsBlocked (new_x, new_y)) {
   4C41 7D            [ 4]  422 	ld	a, l
   4C42 B7            [ 4]  423 	or	a, a
   4C43 20 6A         [12]  424 	jr	NZ,00116$
                            425 ;src/main.c:126: if (GetBlockingEntity (entities, &target, new_x, new_y) &&
   4C45 C5            [11]  426 	push	bc
   4C46 3A 82 5C      [13]  427 	ld	a, (_new_y)
   4C49 F5            [11]  428 	push	af
   4C4A 33            [ 6]  429 	inc	sp
   4C4B 3A 81 5C      [13]  430 	ld	a, (_new_x)
   4C4E F5            [11]  431 	push	af
   4C4F 33            [ 6]  432 	inc	sp
   4C50 21 84 5C      [10]  433 	ld	hl, #_target
   4C53 E5            [11]  434 	push	hl
   4C54 21 6A 5C      [10]  435 	ld	hl, #_entities
   4C57 E5            [11]  436 	push	hl
   4C58 CD EF 47      [17]  437 	call	_GetBlockingEntity
   4C5B F1            [10]  438 	pop	af
   4C5C F1            [10]  439 	pop	af
   4C5D F1            [10]  440 	pop	af
   4C5E C1            [10]  441 	pop	bc
   4C5F 7D            [ 4]  442 	ld	a, l
   4C60 B7            [ 4]  443 	or	a, a
   4C61 28 28         [12]  444 	jr	Z,00112$
                            445 ;src/main.c:127: target != &enemy) {
   4C63 FD 21 84 5C   [14]  446 	ld	iy, #_target
   4C67 FD 7E 00      [19]  447 	ld	a, 0 (iy)
   4C6A D6 44         [ 7]  448 	sub	a, #<(_enemy)
   4C6C 20 07         [12]  449 	jr	NZ,00190$
   4C6E FD 7E 01      [19]  450 	ld	a, 1 (iy)
   4C71 D6 5C         [ 7]  451 	sub	a, #>(_enemy)
   4C73 28 16         [12]  452 	jr	Z,00112$
   4C75                     453 00190$:
                            454 ;src/main.c:128: EntityAttack (&enemy, target);
   4C75 2A 84 5C      [16]  455 	ld	hl, (_target)
   4C78 E5            [11]  456 	push	hl
   4C79 21 44 5C      [10]  457 	ld	hl, #_enemy
   4C7C E5            [11]  458 	push	hl
   4C7D CD 86 47      [17]  459 	call	_EntityAttack
   4C80 F1            [10]  460 	pop	af
                            461 ;src/main.c:129: EntityPrintStats(&player);
   4C81 21 23 5C      [10]  462 	ld	hl, #_player
   4C84 E3            [19]  463 	ex	(sp),hl
   4C85 CD 9E 48      [17]  464 	call	_EntityPrintStats
   4C88 F1            [10]  465 	pop	af
   4C89 18 27         [12]  466 	jr	00117$
   4C8B                     467 00112$:
                            468 ;src/main.c:132: EntityMove (&enemy, edx[ei++], edy);
   4C8B DD 5E FF      [19]  469 	ld	e, -1 (ix)
   4C8E DD 71 FF      [19]  470 	ld	-1 (ix), c
   4C91 21 77 5C      [10]  471 	ld	hl, #_edx
   4C94 16 00         [ 7]  472 	ld	d, #0x00
   4C96 19            [11]  473 	add	hl, de
   4C97 46            [ 7]  474 	ld	b, (hl)
   4C98 11 44 5C      [10]  475 	ld	de, #_enemy
   4C9B 3A 86 5C      [13]  476 	ld	a, (_edy)
   4C9E F5            [11]  477 	push	af
   4C9F 33            [ 6]  478 	inc	sp
   4CA0 C5            [11]  479 	push	bc
   4CA1 33            [ 6]  480 	inc	sp
   4CA2 D5            [11]  481 	push	de
   4CA3 CD 87 46      [17]  482 	call	_EntityMove
   4CA6 F1            [10]  483 	pop	af
   4CA7 F1            [10]  484 	pop	af
                            485 ;src/main.c:133: dirty[1] = TRUE;
   4CA8 21 66 5C      [10]  486 	ld	hl, #(_dirty + 0x0001)
   4CAB 36 01         [10]  487 	ld	(hl), #0x01
   4CAD 18 03         [12]  488 	jr	00117$
   4CAF                     489 00116$:
                            490 ;src/main.c:136: else ++ei;
   4CAF DD 71 FF      [19]  491 	ld	-1 (ix), c
   4CB2                     492 00117$:
                            493 ;src/main.c:137: if (ei > 9) ei = 0;
   4CB2 3E 09         [ 7]  494 	ld	a, #0x09
   4CB4 DD 96 FF      [19]  495 	sub	a, -1 (ix)
   4CB7 30 04         [12]  496 	jr	NC,00119$
   4CB9 DD 36 FF 00   [19]  497 	ld	-1 (ix), #0x00
   4CBD                     498 00119$:
                            499 ;src/main.c:139: state = PLAYER_TURN;
   4CBD 21 74 5C      [10]  500 	ld	hl,#_state + 0
   4CC0 36 00         [10]  501 	ld	(hl), #0x00
                            502 ;src/main.c:141: } while (1);
   4CC2 C3 40 4B      [10]  503 	jp	00122$
   4CC5 33            [ 6]  504 	inc	sp
   4CC6 DD E1         [14]  505 	pop	ix
   4CC8 C9            [10]  506 	ret
   4CC9                     507 ___str_0:
   4CC9 54 68 6F 72 62 61   508 	.ascii "Thorbag"
        67
   4CD0 00                  509 	.db 0x00
   4CD1                     510 ___str_1:
   4CD1 47 6F 62 6C 69 6E   511 	.ascii "Goblin"
   4CD7 00                  512 	.db 0x00
                            513 	.area _CODE
                            514 	.area _INITIALIZER
   5C87                     515 __xinit__action:
   5C87 00                  516 	.db #0x00	; 0
   5C88                     517 __xinit__target:
   5C88 00 00               518 	.dw #0x0000
   5C8A                     519 __xinit__edy:
   5C8A 00                  520 	.db #0x00	;  0
                            521 	.area _CABS (ABS)
