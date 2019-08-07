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
                             13 	.globl _TraceLine
                             14 	.globl _PrintAt
                             15 	.globl _paper
                             16 	.globl _ink
                             17 	.globl _putchar
                             18 	.globl _edy
                             19 	.globl _target
                             20 	.globl _action
                             21 	.globl _new_y
                             22 	.globl _new_x
                             23 	.globl _edx
                             24 	.globl _dy
                             25 	.globl _dx
                             26 	.globl _state
                             27 	.globl _entities
                             28 	.globl _dirty
                             29 	.globl _enemy
                             30 	.globl _player
                             31 ;--------------------------------------------------------
                             32 ; special function registers
                             33 ;--------------------------------------------------------
                             34 ;--------------------------------------------------------
                             35 ; ram data
                             36 ;--------------------------------------------------------
                             37 	.area _DATA
   5E54                      38 _player::
   5E54                      39 	.ds 33
   5E75                      40 _enemy::
   5E75                      41 	.ds 33
   5E96                      42 _dirty::
   5E96                      43 	.ds 5
   5E9B                      44 _entities::
   5E9B                      45 	.ds 10
   5EA5                      46 _state::
   5EA5                      47 	.ds 1
   5EA6                      48 _dx::
   5EA6                      49 	.ds 1
   5EA7                      50 _dy::
   5EA7                      51 	.ds 1
   5EA8                      52 _edx::
   5EA8                      53 	.ds 10
   5EB2                      54 _new_x::
   5EB2                      55 	.ds 1
   5EB3                      56 _new_y::
   5EB3                      57 	.ds 1
                             58 ;--------------------------------------------------------
                             59 ; ram data
                             60 ;--------------------------------------------------------
                             61 	.area _INITIALIZED
   5EB4                      62 _action::
   5EB4                      63 	.ds 1
   5EB5                      64 _target::
   5EB5                      65 	.ds 2
   5EB7                      66 _edy::
   5EB7                      67 	.ds 1
                             68 ;--------------------------------------------------------
                             69 ; absolute external ram data
                             70 ;--------------------------------------------------------
                             71 	.area _DABS (ABS)
                             72 ;--------------------------------------------------------
                             73 ; global & static initialisations
                             74 ;--------------------------------------------------------
                             75 	.area _HOME
                             76 	.area _GSINIT
                             77 	.area _GSFINAL
                             78 	.area _GSINIT
                             79 ;--------------------------------------------------------
                             80 ; Home
                             81 ;--------------------------------------------------------
                             82 	.area _HOME
                             83 	.area _HOME
                             84 ;--------------------------------------------------------
                             85 ; code
                             86 ;--------------------------------------------------------
                             87 	.area _CODE
                             88 ;src/main.c:38: void InitColors()
                             89 ;	---------------------------------
                             90 ; Function InitColors
                             91 ; ---------------------------------
   4916                      92 _InitColors::
                             93 ;src/main.c:40: ink (0, INK_BG,INK_BG);
   4916 21 00 00      [10]   94 	ld	hl, #0x0000
   4919 E5            [11]   95 	push	hl
   491A AF            [ 4]   96 	xor	a, a
   491B F5            [11]   97 	push	af
   491C 33            [ 6]   98 	inc	sp
   491D CD 77 44      [17]   99 	call	_ink
                            100 ;src/main.c:41: ink (1, INK_DARK, INK_DARK);
   4920 33            [ 6]  101 	inc	sp
   4921 21 01 01      [10]  102 	ld	hl,#0x0101
   4924 E3            [19]  103 	ex	(sp),hl
   4925 3E 01         [ 7]  104 	ld	a, #0x01
   4927 F5            [11]  105 	push	af
   4928 33            [ 6]  106 	inc	sp
   4929 CD 77 44      [17]  107 	call	_ink
                            108 ;src/main.c:42: ink (2, INK_BRIGHT, INK_BRIGHT);
   492C 33            [ 6]  109 	inc	sp
   492D 21 14 14      [10]  110 	ld	hl,#0x1414
   4930 E3            [19]  111 	ex	(sp),hl
   4931 3E 02         [ 7]  112 	ld	a, #0x02
   4933 F5            [11]  113 	push	af
   4934 33            [ 6]  114 	inc	sp
   4935 CD 77 44      [17]  115 	call	_ink
                            116 ;src/main.c:43: ink (3, INK_NORMAL, INK_NORMAL);
   4938 33            [ 6]  117 	inc	sp
   4939 21 0A 0A      [10]  118 	ld	hl,#0x0a0a
   493C E3            [19]  119 	ex	(sp),hl
   493D 3E 03         [ 7]  120 	ld	a, #0x03
   493F F5            [11]  121 	push	af
   4940 33            [ 6]  122 	inc	sp
   4941 CD 77 44      [17]  123 	call	_ink
                            124 ;src/conio.h:9: putchar (GS);
   4944 33            [ 6]  125 	inc	sp
   4945 21 1D 00      [10]  126 	ld	hl,#0x001d
   4948 E3            [19]  127 	ex	(sp),hl
   4949 CD 52 4F      [17]  128 	call	_putchar
                            129 ;src/conio.h:10: putchar (color1); putchar (color1);
   494C 21 00 00      [10]  130 	ld	hl, #0x0000
   494F E3            [19]  131 	ex	(sp),hl
   4950 CD 52 4F      [17]  132 	call	_putchar
   4953 21 00 00      [10]  133 	ld	hl, #0x0000
   4956 E3            [19]  134 	ex	(sp),hl
   4957 CD 52 4F      [17]  135 	call	_putchar
   495A F1            [10]  136 	pop	af
                            137 ;src/main.c:45: border (0); paper (0);
   495B AF            [ 4]  138 	xor	a, a
   495C F5            [11]  139 	push	af
   495D 33            [ 6]  140 	inc	sp
   495E CD A4 44      [17]  141 	call	_paper
   4961 33            [ 6]  142 	inc	sp
   4962 C9            [10]  143 	ret
                            144 ;src/main.c:65: void main()
                            145 ;	---------------------------------
                            146 ; Function main
                            147 ; ---------------------------------
   4963                     148 _main::
   4963 DD E5         [15]  149 	push	ix
   4965 21 00 FF      [10]  150 	ld	hl, #-256
   4968 39            [11]  151 	add	hl, sp
   4969 F9            [ 6]  152 	ld	sp, hl
                            153 ;src/main.c:70: for (ei=0; ei!=5; ++ei) {
   496A 01 A8 5E      [10]  154 	ld	bc, #_edx+0
   496D 1E 00         [ 7]  155 	ld	e, #0x00
   496F                     156 00109$:
                            157 ;src/main.c:71: edx[ei]=1; edx[9-ei]=-1;
   496F 6B            [ 4]  158 	ld	l,e
   4970 26 00         [ 7]  159 	ld	h,#0x00
   4972 09            [11]  160 	add	hl, bc
   4973 36 01         [10]  161 	ld	(hl), #0x01
   4975 3E 09         [ 7]  162 	ld	a, #0x09
   4977 93            [ 4]  163 	sub	a, e
   4978 6F            [ 4]  164 	ld	l, a
   4979 26 00         [ 7]  165 	ld	h,#0x00
   497B 09            [11]  166 	add	hl, bc
   497C 36 FF         [10]  167 	ld	(hl), #0xff
                            168 ;src/main.c:70: for (ei=0; ei!=5; ++ei) {
   497E 1C            [ 4]  169 	inc	e
   497F 7B            [ 4]  170 	ld	a, e
   4980 D6 05         [ 7]  171 	sub	a, #0x05
   4982 20 EB         [12]  172 	jr	NZ,00109$
                            173 ;src/conio.h:14: inline void cls () { putchar (FF); }
   4984 21 0C 00      [10]  174 	ld	hl, #0x000c
   4987 E5            [11]  175 	push	hl
   4988 CD 52 4F      [17]  176 	call	_putchar
   498B F1            [10]  177 	pop	af
                            178 ;src/main.c:77: for (u8 n=0; n!= 30; ++n) {
   498C 0E 00         [ 7]  179 	ld	c, #0x00
   498E                     180 00118$:
   498E 79            [ 4]  181 	ld	a, c
   498F D6 1E         [ 7]  182 	sub	a, #0x1e
   4991 28 5B         [12]  183 	jr	Z,00104$
                            184 ;src/main.c:78: for (u8 x=10; x!=20; ++x) {
   4993 06 0A         [ 7]  185 	ld	b, #0x0a
   4995                     186 00112$:
   4995 78            [ 4]  187 	ld	a, b
   4996 D6 14         [ 7]  188 	sub	a, #0x14
   4998 28 25         [12]  189 	jr	Z,00102$
                            190 ;src/main.c:79: TraceLine (15,15, x,10);//, points);
   499A C5            [11]  191 	push	bc
   499B 3E 0A         [ 7]  192 	ld	a, #0x0a
   499D F5            [11]  193 	push	af
   499E 33            [ 6]  194 	inc	sp
   499F C5            [11]  195 	push	bc
   49A0 33            [ 6]  196 	inc	sp
   49A1 21 0F 0F      [10]  197 	ld	hl, #0x0f0f
   49A4 E5            [11]  198 	push	hl
   49A5 CD 9A 4E      [17]  199 	call	_TraceLine
   49A8 F1            [10]  200 	pop	af
   49A9 F1            [10]  201 	pop	af
   49AA C1            [10]  202 	pop	bc
                            203 ;src/main.c:80: TraceLine (15,15, x,20);//, points);
   49AB C5            [11]  204 	push	bc
   49AC 3E 14         [ 7]  205 	ld	a, #0x14
   49AE F5            [11]  206 	push	af
   49AF 33            [ 6]  207 	inc	sp
   49B0 C5            [11]  208 	push	bc
   49B1 33            [ 6]  209 	inc	sp
   49B2 21 0F 0F      [10]  210 	ld	hl, #0x0f0f
   49B5 E5            [11]  211 	push	hl
   49B6 CD 9A 4E      [17]  212 	call	_TraceLine
   49B9 F1            [10]  213 	pop	af
   49BA F1            [10]  214 	pop	af
   49BB C1            [10]  215 	pop	bc
                            216 ;src/main.c:78: for (u8 x=10; x!=20; ++x) {
   49BC 04            [ 4]  217 	inc	b
   49BD 18 D6         [12]  218 	jr	00112$
   49BF                     219 00102$:
                            220 ;src/main.c:82: for (u8 y=10; y<=20; ++y) {
   49BF 06 0A         [ 7]  221 	ld	b, #0x0a
   49C1                     222 00115$:
   49C1 3E 14         [ 7]  223 	ld	a, #0x14
   49C3 90            [ 4]  224 	sub	a, b
   49C4 38 25         [12]  225 	jr	C,00119$
                            226 ;src/main.c:83: TraceLine (15,15, 10,y);//, points);
   49C6 C5            [11]  227 	push	bc
   49C7 C5            [11]  228 	push	bc
   49C8 33            [ 6]  229 	inc	sp
   49C9 21 0F 0A      [10]  230 	ld	hl, #0x0a0f
   49CC E5            [11]  231 	push	hl
   49CD 3E 0F         [ 7]  232 	ld	a, #0x0f
   49CF F5            [11]  233 	push	af
   49D0 33            [ 6]  234 	inc	sp
   49D1 CD 9A 4E      [17]  235 	call	_TraceLine
   49D4 F1            [10]  236 	pop	af
   49D5 F1            [10]  237 	pop	af
   49D6 C1            [10]  238 	pop	bc
                            239 ;src/main.c:84: TraceLine (15,15, 20,y);//, points);
   49D7 C5            [11]  240 	push	bc
   49D8 C5            [11]  241 	push	bc
   49D9 33            [ 6]  242 	inc	sp
   49DA 21 0F 14      [10]  243 	ld	hl, #0x140f
   49DD E5            [11]  244 	push	hl
   49DE 3E 0F         [ 7]  245 	ld	a, #0x0f
   49E0 F5            [11]  246 	push	af
   49E1 33            [ 6]  247 	inc	sp
   49E2 CD 9A 4E      [17]  248 	call	_TraceLine
   49E5 F1            [10]  249 	pop	af
   49E6 F1            [10]  250 	pop	af
   49E7 C1            [10]  251 	pop	bc
                            252 ;src/main.c:82: for (u8 y=10; y<=20; ++y) {
   49E8 04            [ 4]  253 	inc	b
   49E9 18 D6         [12]  254 	jr	00115$
   49EB                     255 00119$:
                            256 ;src/main.c:77: for (u8 n=0; n!= 30; ++n) {
   49EB 0C            [ 4]  257 	inc	c
   49EC 18 A0         [12]  258 	jr	00118$
   49EE                     259 00104$:
                            260 ;src/main.c:87: PrintAt(15,1, "Finished!",3);
   49EE 3E 03         [ 7]  261 	ld	a, #0x03
   49F0 F5            [11]  262 	push	af
   49F1 33            [ 6]  263 	inc	sp
   49F2 21 02 4A      [10]  264 	ld	hl, #___str_0
   49F5 E5            [11]  265 	push	hl
   49F6 21 0F 01      [10]  266 	ld	hl, #0x010f
   49F9 E5            [11]  267 	push	hl
   49FA CD CE 44      [17]  268 	call	_PrintAt
   49FD F1            [10]  269 	pop	af
   49FE F1            [10]  270 	pop	af
   49FF 33            [ 6]  271 	inc	sp
                            272 ;src/main.c:164: while (1);
   4A00                     273 00106$:
   4A00 18 FE         [12]  274 	jr	00106$
   4A02                     275 ___str_0:
   4A02 46 69 6E 69 73 68   276 	.ascii "Finished!"
        65 64 21
   4A0B 00                  277 	.db 0x00
                            278 	.area _CODE
                            279 	.area _INITIALIZER
   5EB8                     280 __xinit__action:
   5EB8 00                  281 	.db #0x00	; 0
   5EB9                     282 __xinit__target:
   5EB9 00 00               283 	.dw #0x0000
   5EBB                     284 __xinit__edy:
   5EBB 00                  285 	.db #0x00	;  0
                            286 	.area _CABS (ABS)
