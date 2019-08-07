                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module user_interface
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl __DrawLines
                             12 	.globl __DrawLine
                             13 	.globl _DrawSingleChars
                             14 	.globl _PrintU8
                             15 	.globl _PrintAt
                             16 	.globl _pen
                             17 	.globl _ink
                             18 	.globl _locate
                             19 	.globl _putchar
                             20 	.globl _hud
                             21 	.globl _DrawHUD
                             22 	.globl _DisplayLoading
                             23 	.globl _ClearStatus
                             24 	.globl _PrintStats
                             25 	.globl _DrawLine
                             26 ;--------------------------------------------------------
                             27 ; special function registers
                             28 ;--------------------------------------------------------
                             29 ;--------------------------------------------------------
                             30 ; ram data
                             31 ;--------------------------------------------------------
                             32 	.area _DATA
                             33 ;--------------------------------------------------------
                             34 ; ram data
                             35 ;--------------------------------------------------------
                             36 	.area _INITIALIZED
                             37 ;--------------------------------------------------------
                             38 ; absolute external ram data
                             39 ;--------------------------------------------------------
                             40 	.area _DABS (ABS)
                             41 ;--------------------------------------------------------
                             42 ; global & static initialisations
                             43 ;--------------------------------------------------------
                             44 	.area _HOME
                             45 	.area _GSINIT
                             46 	.area _GSFINAL
                             47 	.area _GSINIT
                             48 ;--------------------------------------------------------
                             49 ; Home
                             50 ;--------------------------------------------------------
                             51 	.area _HOME
                             52 	.area _HOME
                             53 ;--------------------------------------------------------
                             54 ; code
                             55 ;--------------------------------------------------------
                             56 	.area _CODE
                             57 ;src/user_interface.c:27: u8 DrawSingleChars ()
                             58 ;	---------------------------------
                             59 ; Function DrawSingleChars
                             60 ; ---------------------------------
   4A0C                      61 _DrawSingleChars::
   4A0C DD E5         [15]   62 	push	ix
   4A0E DD 21 00 00   [14]   63 	ld	ix,#0
   4A12 DD 39         [15]   64 	add	ix,sp
   4A14 F5            [11]   65 	push	af
   4A15 F5            [11]   66 	push	af
                             67 ;src/user_interface.c:35: i=0;
   4A16 0E 00         [ 7]   68 	ld	c, #0x00
                             69 ;src/user_interface.c:36: while ( (ch = hud[i++]) != 255) {
   4A18 11 91 4A      [10]   70 	ld	de, #_hud+0
   4A1B                      71 00102$:
   4A1B 69            [ 4]   72 	ld	l, c
   4A1C 0C            [ 4]   73 	inc	c
   4A1D 26 00         [ 7]   74 	ld	h,#0x00
   4A1F 19            [11]   75 	add	hl, de
   4A20 46            [ 7]   76 	ld	b, (hl)
   4A21 DD 70 FF      [19]   77 	ld	-1 (ix), b
   4A24 04            [ 4]   78 	inc	b
   4A25 28 64         [12]   79 	jr	Z,00104$
                             80 ;src/user_interface.c:37: color = hud[i++];
   4A27 79            [ 4]   81 	ld	a,c
   4A28 47            [ 4]   82 	ld	b,a
   4A29 3C            [ 4]   83 	inc	a
   4A2A DD 77 FE      [19]   84 	ld	-2 (ix), a
   4A2D 68            [ 4]   85 	ld	l,b
   4A2E 26 00         [ 7]   86 	ld	h,#0x00
   4A30 19            [11]   87 	add	hl, de
   4A31 46            [ 7]   88 	ld	b, (hl)
                             89 ;src/user_interface.c:38: reps = hud[i++];
   4A32 DD 6E FE      [19]   90 	ld	l, -2 (ix)
   4A35 DD 4E FE      [19]   91 	ld	c, -2 (ix)
   4A38 0C            [ 4]   92 	inc	c
   4A39 26 00         [ 7]   93 	ld	h,#0x00
   4A3B 19            [11]   94 	add	hl, de
   4A3C 7E            [ 7]   95 	ld	a, (hl)
   4A3D DD 77 FD      [19]   96 	ld	-3 (ix), a
                             97 ;src/user_interface.c:39: pen(color);
   4A40 C5            [11]   98 	push	bc
   4A41 D5            [11]   99 	push	de
   4A42 C5            [11]  100 	push	bc
   4A43 33            [ 6]  101 	inc	sp
   4A44 CD B9 44      [17]  102 	call	_pen
   4A47 33            [ 6]  103 	inc	sp
   4A48 D1            [10]  104 	pop	de
   4A49 C1            [10]  105 	pop	bc
                            106 ;src/user_interface.c:41: for (u8 n=0; n<reps; ++n) {
   4A4A DD 36 FC 00   [19]  107 	ld	-4 (ix), #0x00
   4A4E                     108 00106$:
   4A4E DD 7E FC      [19]  109 	ld	a, -4 (ix)
   4A51 DD 96 FD      [19]  110 	sub	a, -3 (ix)
   4A54 30 C5         [12]  111 	jr	NC,00102$
                            112 ;src/user_interface.c:42: x=hud[i++];
   4A56 79            [ 4]  113 	ld	a,c
   4A57 47            [ 4]  114 	ld	b,a
   4A58 3C            [ 4]  115 	inc	a
   4A59 DD 77 FE      [19]  116 	ld	-2 (ix), a
   4A5C 68            [ 4]  117 	ld	l,b
   4A5D 26 00         [ 7]  118 	ld	h,#0x00
   4A5F 19            [11]  119 	add	hl, de
   4A60 46            [ 7]  120 	ld	b, (hl)
                            121 ;src/user_interface.c:43: y=hud[i++];
   4A61 DD 6E FE      [19]  122 	ld	l, -2 (ix)
   4A64 DD 4E FE      [19]  123 	ld	c, -2 (ix)
   4A67 0C            [ 4]  124 	inc	c
   4A68 26 00         [ 7]  125 	ld	h,#0x00
   4A6A 19            [11]  126 	add	hl, de
   4A6B 66            [ 7]  127 	ld	h, (hl)
                            128 ;src/user_interface.c:44: locate (x,y);
   4A6C C5            [11]  129 	push	bc
   4A6D D5            [11]  130 	push	de
   4A6E E5            [11]  131 	push	hl
   4A6F 33            [ 6]  132 	inc	sp
   4A70 C5            [11]  133 	push	bc
   4A71 33            [ 6]  134 	inc	sp
   4A72 CD 56 44      [17]  135 	call	_locate
   4A75 F1            [10]  136 	pop	af
   4A76 D1            [10]  137 	pop	de
   4A77 C1            [10]  138 	pop	bc
                            139 ;src/user_interface.c:45: putchar (ch);
   4A78 DD 6E FF      [19]  140 	ld	l, -1 (ix)
   4A7B 26 00         [ 7]  141 	ld	h, #0x00
   4A7D C5            [11]  142 	push	bc
   4A7E D5            [11]  143 	push	de
   4A7F E5            [11]  144 	push	hl
   4A80 CD 52 4F      [17]  145 	call	_putchar
   4A83 F1            [10]  146 	pop	af
   4A84 D1            [10]  147 	pop	de
   4A85 C1            [10]  148 	pop	bc
                            149 ;src/user_interface.c:41: for (u8 n=0; n<reps; ++n) {
   4A86 DD 34 FC      [23]  150 	inc	-4 (ix)
   4A89 18 C3         [12]  151 	jr	00106$
   4A8B                     152 00104$:
                            153 ;src/user_interface.c:48: return i;
   4A8B 69            [ 4]  154 	ld	l, c
   4A8C DD F9         [10]  155 	ld	sp, ix
   4A8E DD E1         [14]  156 	pop	ix
   4A90 C9            [10]  157 	ret
   4A91                     158 _hud:
   4A91 E9                  159 	.db #0xe9	; 233
   4A92 02                  160 	.db #0x02	; 2
   4A93 08                  161 	.db #0x08	; 8
   4A94 01                  162 	.db #0x01	; 1
   4A95 01                  163 	.db #0x01	; 1
   4A96 1E                  164 	.db #0x1e	; 30
   4A97 01                  165 	.db #0x01	; 1
   4A98 28                  166 	.db #0x28	; 40
   4A99 01                  167 	.db #0x01	; 1
   4A9A 01                  168 	.db #0x01	; 1
   4A9B 14                  169 	.db #0x14	; 20
   4A9C 1E                  170 	.db #0x1e	; 30
   4A9D 14                  171 	.db #0x14	; 20
   4A9E 28                  172 	.db #0x28	; 40
   4A9F 14                  173 	.db #0x14	; 20
   4AA0 01                  174 	.db #0x01	; 1
   4AA1 19                  175 	.db #0x19	; 25
   4AA2 28                  176 	.db #0x28	; 40
   4AA3 19                  177 	.db #0x19	; 25
   4AA4 9A                  178 	.db #0x9a	; 154
   4AA5 02                  179 	.db #0x02	; 2
   4AA6 0C                  180 	.db #0x0c	; 12
   4AA7 02                  181 	.db #0x02	; 2
   4AA8 01                  182 	.db #0x01	; 1
   4AA9 0A                  183 	.db #0x0a	; 10
   4AAA 01                  184 	.db #0x01	; 1
   4AAB 15                  185 	.db #0x15	; 21
   4AAC 01                  186 	.db #0x01	; 1
   4AAD 1D                  187 	.db #0x1d	; 29
   4AAE 01                  188 	.db #0x01	; 1
   4AAF 1F                  189 	.db #0x1f	; 31
   4AB0 01                  190 	.db #0x01	; 1
   4AB1 27                  191 	.db #0x27	; 39
   4AB2 01                  192 	.db #0x01	; 1
   4AB3 02                  193 	.db #0x02	; 2
   4AB4 14                  194 	.db #0x14	; 20
   4AB5 1D                  195 	.db #0x1d	; 29
   4AB6 14                  196 	.db #0x14	; 20
   4AB7 1F                  197 	.db #0x1f	; 31
   4AB8 14                  198 	.db #0x14	; 20
   4AB9 27                  199 	.db #0x27	; 39
   4ABA 14                  200 	.db #0x14	; 20
   4ABB 02                  201 	.db #0x02	; 2
   4ABC 19                  202 	.db #0x19	; 25
   4ABD 27                  203 	.db #0x27	; 39
   4ABE 19                  204 	.db #0x19	; 25
   4ABF 95                  205 	.db #0x95	; 149
   4AC0 02                  206 	.db #0x02	; 2
   4AC1 0A                  207 	.db #0x0a	; 10
   4AC2 01                  208 	.db #0x01	; 1
   4AC3 02                  209 	.db #0x02	; 2
   4AC4 1E                  210 	.db #0x1e	; 30
   4AC5 02                  211 	.db #0x02	; 2
   4AC6 28                  212 	.db #0x28	; 40
   4AC7 02                  213 	.db #0x02	; 2
   4AC8 01                  214 	.db #0x01	; 1
   4AC9 13                  215 	.db #0x13	; 19
   4ACA 01                  216 	.db #0x01	; 1
   4ACB 15                  217 	.db #0x15	; 21
   4ACC 1E                  218 	.db #0x1e	; 30
   4ACD 13                  219 	.db #0x13	; 19
   4ACE 28                  220 	.db #0x28	; 40
   4ACF 13                  221 	.db #0x13	; 19
   4AD0 28                  222 	.db #0x28	; 40
   4AD1 15                  223 	.db #0x15	; 21
   4AD2 01                  224 	.db #0x01	; 1
   4AD3 18                  225 	.db #0x18	; 24
   4AD4 28                  226 	.db #0x28	; 40
   4AD5 18                  227 	.db #0x18	; 24
   4AD6 9D                  228 	.db #0x9d	; 157
   4AD7 02                  229 	.db #0x02	; 2
   4AD8 01                  230 	.db #0x01	; 1
   4AD9 0B                  231 	.db #0x0b	; 11
   4ADA 01                  232 	.db #0x01	; 1
   4ADB 97                  233 	.db #0x97	; 151
   4ADC 02                  234 	.db #0x02	; 2
   4ADD 01                  235 	.db #0x01	; 1
   4ADE 14                  236 	.db #0x14	; 20
   4ADF 01                  237 	.db #0x01	; 1
   4AE0 FF                  238 	.db #0xff	; 255
   4AE1 9A                  239 	.db #0x9a	; 154
   4AE2 03                  240 	.db #0x03	; 3
   4AE3 01                  241 	.db #0x01	; 1
   4AE4 06                  242 	.db #0x06	; 6
   4AE5 03                  243 	.db #0x03	; 3
   4AE6 01                  244 	.db #0x01	; 1
   4AE7 07                  245 	.db #0x07	; 7
   4AE8 16                  246 	.db #0x16	; 22
   4AE9 01                  247 	.db #0x01	; 1
   4AEA 08                  248 	.db #0x08	; 8
   4AEB 20                  249 	.db #0x20	; 32
   4AEC 01                  250 	.db #0x01	; 1
   4AED 07                  251 	.db #0x07	; 7
   4AEE 03                  252 	.db #0x03	; 3
   4AEF 14                  253 	.db #0x14	; 20
   4AF0 1A                  254 	.db #0x1a	; 26
   4AF1 20                  255 	.db #0x20	; 32
   4AF2 14                  256 	.db #0x14	; 20
   4AF3 07                  257 	.db #0x07	; 7
   4AF4 03                  258 	.db #0x03	; 3
   4AF5 19                  259 	.db #0x19	; 25
   4AF6 24                  260 	.db #0x24	; 36
   4AF7 95                  261 	.db #0x95	; 149
   4AF8 03                  262 	.db #0x03	; 3
   4AF9 00                  263 	.db #0x00	; 0
   4AFA 05                  264 	.db #0x05	; 5
   4AFB 01                  265 	.db #0x01	; 1
   4AFC 03                  266 	.db #0x03	; 3
   4AFD 10                  267 	.db #0x10	; 16
   4AFE 1E                  268 	.db #0x1e	; 30
   4AFF 03                  269 	.db #0x03	; 3
   4B00 10                  270 	.db #0x10	; 16
   4B01 28                  271 	.db #0x28	; 40
   4B02 03                  272 	.db #0x03	; 3
   4B03 10                  273 	.db #0x10	; 16
   4B04 01                  274 	.db #0x01	; 1
   4B05 16                  275 	.db #0x16	; 22
   4B06 02                  276 	.db #0x02	; 2
   4B07 28                  277 	.db #0x28	; 40
   4B08 16                  278 	.db #0x16	; 22
   4B09 02                  279 	.db #0x02	; 2
   4B0A FF                  280 	.db #0xff	; 255
                            281 ;src/user_interface.c:51: void _DrawLine (u8 start, u8 other, u8 reps, u8 ch, u8 color, u8 is_hor)
                            282 ;	---------------------------------
                            283 ; Function _DrawLine
                            284 ; ---------------------------------
   4B0B                     285 __DrawLine::
   4B0B DD E5         [15]  286 	push	ix
   4B0D DD 21 00 00   [14]  287 	ld	ix,#0
   4B11 DD 39         [15]  288 	add	ix,sp
   4B13 3B            [ 6]  289 	dec	sp
                            290 ;src/user_interface.c:55: pen (color);
   4B14 DD 7E 08      [19]  291 	ld	a, 8 (ix)
   4B17 F5            [11]  292 	push	af
   4B18 33            [ 6]  293 	inc	sp
   4B19 CD B9 44      [17]  294 	call	_pen
   4B1C 33            [ 6]  295 	inc	sp
                            296 ;src/user_interface.c:56: for (u8 var=start; var!= start+reps; ++var) {
   4B1D DD 7E 04      [19]  297 	ld	a, 4 (ix)
   4B20 DD 77 FF      [19]  298 	ld	-1 (ix), a
   4B23                     299 00106$:
   4B23 DD 4E 04      [19]  300 	ld	c, 4 (ix)
   4B26 06 00         [ 7]  301 	ld	b, #0x00
   4B28 DD 6E 06      [19]  302 	ld	l, 6 (ix)
   4B2B 26 00         [ 7]  303 	ld	h, #0x00
   4B2D 09            [11]  304 	add	hl,bc
   4B2E 4D            [ 4]  305 	ld	c, l
   4B2F 44            [ 4]  306 	ld	b, h
   4B30 DD 5E FF      [19]  307 	ld	e, -1 (ix)
   4B33 16 00         [ 7]  308 	ld	d, #0x00
   4B35 79            [ 4]  309 	ld	a, c
   4B36 93            [ 4]  310 	sub	a, e
   4B37 20 04         [12]  311 	jr	NZ,00123$
   4B39 78            [ 4]  312 	ld	a, b
   4B3A 92            [ 4]  313 	sub	a, d
   4B3B 28 27         [12]  314 	jr	Z,00108$
   4B3D                     315 00123$:
                            316 ;src/user_interface.c:59: y = other;
   4B3D DD 46 05      [19]  317 	ld	b, 5 (ix)
                            318 ;src/user_interface.c:57: if (is_hor) {
   4B40 DD 7E 09      [19]  319 	ld	a, 9 (ix)
   4B43 B7            [ 4]  320 	or	a, a
   4B44 28 05         [12]  321 	jr	Z,00102$
                            322 ;src/user_interface.c:58: x = var;
   4B46 DD 56 FF      [19]  323 	ld	d, -1 (ix)
                            324 ;src/user_interface.c:59: y = other;
   4B49 18 04         [12]  325 	jr	00103$
   4B4B                     326 00102$:
                            327 ;src/user_interface.c:62: x = other;
   4B4B 50            [ 4]  328 	ld	d, b
                            329 ;src/user_interface.c:63: y = var;
   4B4C DD 46 FF      [19]  330 	ld	b, -1 (ix)
   4B4F                     331 00103$:
                            332 ;src/user_interface.c:65: locate (x,y);
   4B4F 4A            [ 4]  333 	ld	c, d
   4B50 C5            [11]  334 	push	bc
   4B51 CD 56 44      [17]  335 	call	_locate
   4B54 F1            [10]  336 	pop	af
                            337 ;src/user_interface.c:66: putchar (ch);
   4B55 DD 4E 07      [19]  338 	ld	c, 7 (ix)
   4B58 06 00         [ 7]  339 	ld	b, #0x00
   4B5A C5            [11]  340 	push	bc
   4B5B CD 52 4F      [17]  341 	call	_putchar
   4B5E F1            [10]  342 	pop	af
                            343 ;src/user_interface.c:56: for (u8 var=start; var!= start+reps; ++var) {
   4B5F DD 34 FF      [23]  344 	inc	-1 (ix)
   4B62 18 BF         [12]  345 	jr	00106$
   4B64                     346 00108$:
   4B64 33            [ 6]  347 	inc	sp
   4B65 DD E1         [14]  348 	pop	ix
   4B67 C9            [10]  349 	ret
                            350 ;src/user_interface.c:69: u8 _DrawLines (u8 idx)
                            351 ;	---------------------------------
                            352 ; Function _DrawLines
                            353 ; ---------------------------------
   4B68                     354 __DrawLines::
   4B68 DD E5         [15]  355 	push	ix
   4B6A DD 21 00 00   [14]  356 	ld	ix,#0
   4B6E DD 39         [15]  357 	add	ix,sp
   4B70 21 FA FF      [10]  358 	ld	hl, #-6
   4B73 39            [11]  359 	add	hl, sp
   4B74 F9            [ 6]  360 	ld	sp, hl
                            361 ;src/user_interface.c:77: i = idx;
   4B75 DD 4E 04      [19]  362 	ld	c, 4 (ix)
                            363 ;src/user_interface.c:78: while ( (ch = hud[i++]) != 255) {
   4B78                     364 00105$:
   4B78 59            [ 4]  365 	ld	e, c
   4B79 0C            [ 4]  366 	inc	c
   4B7A 21 91 4A      [10]  367 	ld	hl, #_hud
   4B7D 16 00         [ 7]  368 	ld	d, #0x00
   4B7F 19            [11]  369 	add	hl, de
   4B80 46            [ 7]  370 	ld	b, (hl)
   4B81 58            [ 4]  371 	ld	e, b
   4B82 04            [ 4]  372 	inc	b
   4B83 CA 41 4C      [10]  373 	jp	Z,00107$
                            374 ;src/user_interface.c:79: color = hud[i++];
   4B86 41            [ 4]  375 	ld	b, c
   4B87 0C            [ 4]  376 	inc	c
   4B88 FD 21 91 4A   [14]  377 	ld	iy, #_hud
   4B8C C5            [11]  378 	push	bc
   4B8D 48            [ 4]  379 	ld	c,b
   4B8E 06 00         [ 7]  380 	ld	b,#0x00
   4B90 FD 09         [15]  381 	add	iy, bc
   4B92 C1            [10]  382 	pop	bc
   4B93 FD 7E 00      [19]  383 	ld	a, 0 (iy)
   4B96 DD 77 FB      [19]  384 	ld	-5 (ix), a
                            385 ;src/user_interface.c:80: is_hor = hud[i++];
   4B99 79            [ 4]  386 	ld	a, c
   4B9A 3C            [ 4]  387 	inc	a
   4B9B DD 77 FF      [19]  388 	ld	-1 (ix), a
   4B9E 21 91 4A      [10]  389 	ld	hl, #_hud
   4BA1 06 00         [ 7]  390 	ld	b, #0x00
   4BA3 09            [11]  391 	add	hl, bc
   4BA4 7E            [ 7]  392 	ld	a, (hl)
   4BA5 DD 77 FA      [19]  393 	ld	-6 (ix), a
                            394 ;src/user_interface.c:81: n_lines = hud[i++];
   4BA8 DD 46 FF      [19]  395 	ld	b, -1 (ix)
   4BAB DD 4E FF      [19]  396 	ld	c, -1 (ix)
   4BAE 0C            [ 4]  397 	inc	c
   4BAF 3E 91         [ 7]  398 	ld	a, #<(_hud)
   4BB1 80            [ 4]  399 	add	a, b
   4BB2 6F            [ 4]  400 	ld	l, a
   4BB3 3E 4A         [ 7]  401 	ld	a, #>(_hud)
   4BB5 CE 00         [ 7]  402 	adc	a, #0x00
   4BB7 67            [ 4]  403 	ld	h, a
   4BB8 7E            [ 7]  404 	ld	a, (hl)
   4BB9 DD 77 FE      [19]  405 	ld	-2 (ix), a
                            406 ;src/user_interface.c:82: for (u8 n_line=0; n_line < n_lines; ++n_line) {
   4BBC 16 00         [ 7]  407 	ld	d, #0x00
   4BBE                     408 00109$:
   4BBE 7A            [ 4]  409 	ld	a, d
   4BBF DD 96 FE      [19]  410 	sub	a, -2 (ix)
   4BC2 30 B4         [12]  411 	jr	NC,00105$
                            412 ;src/user_interface.c:83: x = hud[i++];
   4BC4 69            [ 4]  413 	ld	l, c
   4BC5 0C            [ 4]  414 	inc	c
   4BC6 3E 91         [ 7]  415 	ld	a, #<(_hud)
   4BC8 85            [ 4]  416 	add	a, l
   4BC9 6F            [ 4]  417 	ld	l, a
   4BCA 3E 4A         [ 7]  418 	ld	a, #>(_hud)
   4BCC CE 00         [ 7]  419 	adc	a, #0x00
   4BCE 67            [ 4]  420 	ld	h, a
   4BCF 7E            [ 7]  421 	ld	a, (hl)
   4BD0 DD 77 FD      [19]  422 	ld	-3 (ix), a
                            423 ;src/user_interface.c:84: y = hud[i++];
   4BD3 79            [ 4]  424 	ld	a,c
   4BD4 6F            [ 4]  425 	ld	l,a
   4BD5 3C            [ 4]  426 	inc	a
   4BD6 DD 77 FF      [19]  427 	ld	-1 (ix), a
   4BD9 FD 21 91 4A   [14]  428 	ld	iy, #_hud
   4BDD 4D            [ 4]  429 	ld	c,l
   4BDE 06 00         [ 7]  430 	ld	b,#0x00
   4BE0 FD 09         [15]  431 	add	iy, bc
   4BE2 FD 7E 00      [19]  432 	ld	a, 0 (iy)
   4BE5 DD 77 FC      [19]  433 	ld	-4 (ix), a
                            434 ;src/user_interface.c:85: reps = hud[i++];
   4BE8 DD 46 FF      [19]  435 	ld	b, -1 (ix)
   4BEB DD 4E FF      [19]  436 	ld	c, -1 (ix)
   4BEE 0C            [ 4]  437 	inc	c
   4BEF 3E 91         [ 7]  438 	ld	a, #<(_hud)
   4BF1 80            [ 4]  439 	add	a, b
   4BF2 6F            [ 4]  440 	ld	l, a
   4BF3 3E 4A         [ 7]  441 	ld	a, #>(_hud)
   4BF5 CE 00         [ 7]  442 	adc	a, #0x00
   4BF7 67            [ 4]  443 	ld	h, a
   4BF8 46            [ 7]  444 	ld	b, (hl)
                            445 ;src/user_interface.c:86: if (is_hor)
   4BF9 DD 7E FA      [19]  446 	ld	a, -6 (ix)
   4BFC B7            [ 4]  447 	or	a, a
   4BFD 28 20         [12]  448 	jr	Z,00102$
                            449 ;src/user_interface.c:87: _DrawLine (x, y, reps, ch, color, is_hor);
   4BFF C5            [11]  450 	push	bc
   4C00 D5            [11]  451 	push	de
   4C01 DD 7E FA      [19]  452 	ld	a, -6 (ix)
   4C04 F5            [11]  453 	push	af
   4C05 33            [ 6]  454 	inc	sp
   4C06 DD 56 FB      [19]  455 	ld	d, -5 (ix)
   4C09 D5            [11]  456 	push	de
   4C0A C5            [11]  457 	push	bc
   4C0B 33            [ 6]  458 	inc	sp
   4C0C DD 66 FC      [19]  459 	ld	h, -4 (ix)
   4C0F DD 6E FD      [19]  460 	ld	l, -3 (ix)
   4C12 E5            [11]  461 	push	hl
   4C13 CD 0B 4B      [17]  462 	call	__DrawLine
   4C16 21 06 00      [10]  463 	ld	hl, #6
   4C19 39            [11]  464 	add	hl, sp
   4C1A F9            [ 6]  465 	ld	sp, hl
   4C1B D1            [10]  466 	pop	de
   4C1C C1            [10]  467 	pop	bc
   4C1D 18 1E         [12]  468 	jr	00110$
   4C1F                     469 00102$:
                            470 ;src/user_interface.c:89: _DrawLine (y, x, reps, ch, color, is_hor);
   4C1F C5            [11]  471 	push	bc
   4C20 D5            [11]  472 	push	de
   4C21 DD 7E FA      [19]  473 	ld	a, -6 (ix)
   4C24 F5            [11]  474 	push	af
   4C25 33            [ 6]  475 	inc	sp
   4C26 DD 56 FB      [19]  476 	ld	d, -5 (ix)
   4C29 D5            [11]  477 	push	de
   4C2A C5            [11]  478 	push	bc
   4C2B 33            [ 6]  479 	inc	sp
   4C2C DD 66 FD      [19]  480 	ld	h, -3 (ix)
   4C2F DD 6E FC      [19]  481 	ld	l, -4 (ix)
   4C32 E5            [11]  482 	push	hl
   4C33 CD 0B 4B      [17]  483 	call	__DrawLine
   4C36 21 06 00      [10]  484 	ld	hl, #6
   4C39 39            [11]  485 	add	hl, sp
   4C3A F9            [ 6]  486 	ld	sp, hl
   4C3B D1            [10]  487 	pop	de
   4C3C C1            [10]  488 	pop	bc
   4C3D                     489 00110$:
                            490 ;src/user_interface.c:82: for (u8 n_line=0; n_line < n_lines; ++n_line) {
   4C3D 14            [ 4]  491 	inc	d
   4C3E C3 BE 4B      [10]  492 	jp	00109$
   4C41                     493 00107$:
                            494 ;src/user_interface.c:92: return i;
   4C41 69            [ 4]  495 	ld	l, c
   4C42 DD F9         [10]  496 	ld	sp, ix
   4C44 DD E1         [14]  497 	pop	ix
   4C46 C9            [10]  498 	ret
                            499 ;src/user_interface.c:95: void DrawHUD ()
                            500 ;	---------------------------------
                            501 ; Function DrawHUD
                            502 ; ---------------------------------
   4C47                     503 _DrawHUD::
                            504 ;src/user_interface.c:99: i = DrawSingleChars ();
   4C47 CD 0C 4A      [17]  505 	call	_DrawSingleChars
   4C4A 45            [ 4]  506 	ld	b, l
                            507 ;src/user_interface.c:100: i = _DrawLines (i);
   4C4B C5            [11]  508 	push	bc
   4C4C 33            [ 6]  509 	inc	sp
   4C4D CD 68 4B      [17]  510 	call	__DrawLines
   4C50 33            [ 6]  511 	inc	sp
                            512 ;src/user_interface.c:101: PrintAt (12,1, "CPCRogue", PEN_BRIGHT);
   4C51 3E 02         [ 7]  513 	ld	a, #0x02
   4C53 F5            [11]  514 	push	af
   4C54 33            [ 6]  515 	inc	sp
   4C55 21 64 4C      [10]  516 	ld	hl, #___str_0
   4C58 E5            [11]  517 	push	hl
   4C59 21 0C 01      [10]  518 	ld	hl, #0x010c
   4C5C E5            [11]  519 	push	hl
   4C5D CD CE 44      [17]  520 	call	_PrintAt
   4C60 F1            [10]  521 	pop	af
   4C61 F1            [10]  522 	pop	af
   4C62 33            [ 6]  523 	inc	sp
   4C63 C9            [10]  524 	ret
   4C64                     525 ___str_0:
   4C64 43 50 43 52 6F 67   526 	.ascii "CPCRogue"
        75 65
   4C6C 00                  527 	.db 0x00
                            528 ;src/user_interface.c:104: void DisplayLoading ()
                            529 ;	---------------------------------
                            530 ; Function DisplayLoading
                            531 ; ---------------------------------
   4C6D                     532 _DisplayLoading::
                            533 ;src/user_interface.c:106: ink (1, 20, 14);
   4C6D 21 14 0E      [10]  534 	ld	hl, #0x0e14
   4C70 E5            [11]  535 	push	hl
   4C71 3E 01         [ 7]  536 	ld	a, #0x01
   4C73 F5            [11]  537 	push	af
   4C74 33            [ 6]  538 	inc	sp
   4C75 CD 77 44      [17]  539 	call	_ink
   4C78 F1            [10]  540 	pop	af
   4C79 33            [ 6]  541 	inc	sp
                            542 ;src/user_interface.c:107: PrintAt (LOADING_X,LOADING_Y, "Loading...", 1);
   4C7A 3E 01         [ 7]  543 	ld	a, #0x01
   4C7C F5            [11]  544 	push	af
   4C7D 33            [ 6]  545 	inc	sp
   4C7E 21 8D 4C      [10]  546 	ld	hl, #___str_1
   4C81 E5            [11]  547 	push	hl
   4C82 21 02 15      [10]  548 	ld	hl, #0x1502
   4C85 E5            [11]  549 	push	hl
   4C86 CD CE 44      [17]  550 	call	_PrintAt
   4C89 F1            [10]  551 	pop	af
   4C8A F1            [10]  552 	pop	af
   4C8B 33            [ 6]  553 	inc	sp
   4C8C C9            [10]  554 	ret
   4C8D                     555 ___str_1:
   4C8D 4C 6F 61 64 69 6E   556 	.ascii "Loading..."
        67 2E 2E 2E
   4C97 00                  557 	.db 0x00
                            558 ;src/user_interface.c:109: void ClearStatus (u8 start_line, u8 nlines)
                            559 ;	---------------------------------
                            560 ; Function ClearStatus
                            561 ; ---------------------------------
   4C98                     562 _ClearStatus::
   4C98 DD E5         [15]  563 	push	ix
   4C9A DD 21 00 00   [14]  564 	ld	ix,#0
   4C9E DD 39         [15]  565 	add	ix,sp
                            566 ;src/user_interface.c:111: for (u8 n=0; n<nlines; ++n) {
   4CA0 0E 00         [ 7]  567 	ld	c, #0x00
   4CA2                     568 00103$:
   4CA2 79            [ 4]  569 	ld	a, c
   4CA3 DD 96 05      [19]  570 	sub	a, 5 (ix)
   4CA6 30 1E         [12]  571 	jr	NC,00105$
                            572 ;src/user_interface.c:113: "                                      ",
   4CA8 11 C9 4C      [10]  573 	ld	de, #___str_2
                            574 ;src/user_interface.c:112: PrintAt (STATUS_X, start_line+n,
   4CAB DD 7E 04      [19]  575 	ld	a, 4 (ix)
   4CAE 81            [ 4]  576 	add	a, c
   4CAF 47            [ 4]  577 	ld	b, a
   4CB0 C5            [11]  578 	push	bc
   4CB1 3E 03         [ 7]  579 	ld	a, #0x03
   4CB3 F5            [11]  580 	push	af
   4CB4 33            [ 6]  581 	inc	sp
   4CB5 D5            [11]  582 	push	de
   4CB6 C5            [11]  583 	push	bc
   4CB7 33            [ 6]  584 	inc	sp
   4CB8 3E 02         [ 7]  585 	ld	a, #0x02
   4CBA F5            [11]  586 	push	af
   4CBB 33            [ 6]  587 	inc	sp
   4CBC CD CE 44      [17]  588 	call	_PrintAt
   4CBF F1            [10]  589 	pop	af
   4CC0 F1            [10]  590 	pop	af
   4CC1 33            [ 6]  591 	inc	sp
   4CC2 C1            [10]  592 	pop	bc
                            593 ;src/user_interface.c:111: for (u8 n=0; n<nlines; ++n) {
   4CC3 0C            [ 4]  594 	inc	c
   4CC4 18 DC         [12]  595 	jr	00103$
   4CC6                     596 00105$:
   4CC6 DD E1         [14]  597 	pop	ix
   4CC8 C9            [10]  598 	ret
   4CC9                     599 ___str_2:
   4CC9 20 20 20 20 20 20   600 	.ascii "                                      "
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20
   4CEF 00                  601 	.db 0x00
                            602 ;src/user_interface.c:120: void PrintStats (TEntity *e)
                            603 ;	---------------------------------
                            604 ; Function PrintStats
                            605 ; ---------------------------------
   4CF0                     606 _PrintStats::
   4CF0 DD E5         [15]  607 	push	ix
   4CF2 DD 21 00 00   [14]  608 	ld	ix,#0
   4CF6 DD 39         [15]  609 	add	ix,sp
                            610 ;src/user_interface.c:127: PrintAt (x,y, e->name, PEN_NORMAL); ++y;
   4CF8 DD 4E 04      [19]  611 	ld	c,4 (ix)
   4CFB DD 46 05      [19]  612 	ld	b,5 (ix)
   4CFE 21 06 00      [10]  613 	ld	hl, #0x0006
   4D01 09            [11]  614 	add	hl, bc
   4D02 C5            [11]  615 	push	bc
   4D03 3E 03         [ 7]  616 	ld	a, #0x03
   4D05 F5            [11]  617 	push	af
   4D06 33            [ 6]  618 	inc	sp
   4D07 E5            [11]  619 	push	hl
   4D08 21 1F 03      [10]  620 	ld	hl, #0x031f
   4D0B E5            [11]  621 	push	hl
   4D0C CD CE 44      [17]  622 	call	_PrintAt
   4D0F F1            [10]  623 	pop	af
   4D10 F1            [10]  624 	pop	af
   4D11 33            [ 6]  625 	inc	sp
   4D12 3E 03         [ 7]  626 	ld	a, #0x03
   4D14 F5            [11]  627 	push	af
   4D15 33            [ 6]  628 	inc	sp
   4D16 21 3B 4E      [10]  629 	ld	hl, #___str_3
   4D19 E5            [11]  630 	push	hl
   4D1A 21 1F 04      [10]  631 	ld	hl, #0x041f
   4D1D E5            [11]  632 	push	hl
   4D1E CD CE 44      [17]  633 	call	_PrintAt
   4D21 F1            [10]  634 	pop	af
   4D22 F1            [10]  635 	pop	af
   4D23 33            [ 6]  636 	inc	sp
   4D24 C1            [10]  637 	pop	bc
   4D25 69            [ 4]  638 	ld	l, c
   4D26 60            [ 4]  639 	ld	h, b
   4D27 11 18 00      [10]  640 	ld	de, #0x0018
   4D2A 19            [11]  641 	add	hl, de
   4D2B 5E            [ 7]  642 	ld	e, (hl)
   4D2C 23            [ 6]  643 	inc	hl
   4D2D 56            [ 7]  644 	ld	d, (hl)
   4D2E 53            [ 4]  645 	ld	d, e
   4D2F C5            [11]  646 	push	bc
   4D30 21 04 02      [10]  647 	ld	hl, #0x0204
   4D33 E5            [11]  648 	push	hl
   4D34 3E 22         [ 7]  649 	ld	a, #0x22
   4D36 F5            [11]  650 	push	af
   4D37 33            [ 6]  651 	inc	sp
   4D38 D5            [11]  652 	push	de
   4D39 33            [ 6]  653 	inc	sp
   4D3A CD 19 45      [17]  654 	call	_PrintU8
   4D3D F1            [10]  655 	pop	af
   4D3E 26 03         [ 7]  656 	ld	h,#0x03
   4D40 E3            [19]  657 	ex	(sp),hl
   4D41 33            [ 6]  658 	inc	sp
   4D42 21 45 4E      [10]  659 	ld	hl, #___str_4
   4D45 E5            [11]  660 	push	hl
   4D46 21 24 04      [10]  661 	ld	hl, #0x0424
   4D49 E5            [11]  662 	push	hl
   4D4A CD CE 44      [17]  663 	call	_PrintAt
   4D4D F1            [10]  664 	pop	af
   4D4E F1            [10]  665 	pop	af
   4D4F 33            [ 6]  666 	inc	sp
   4D50 C1            [10]  667 	pop	bc
   4D51 69            [ 4]  668 	ld	l, c
   4D52 60            [ 4]  669 	ld	h, b
   4D53 11 16 00      [10]  670 	ld	de, #0x0016
   4D56 19            [11]  671 	add	hl, de
   4D57 5E            [ 7]  672 	ld	e, (hl)
   4D58 23            [ 6]  673 	inc	hl
   4D59 56            [ 7]  674 	ld	d, (hl)
   4D5A 53            [ 4]  675 	ld	d, e
   4D5B C5            [11]  676 	push	bc
   4D5C 21 04 02      [10]  677 	ld	hl, #0x0204
   4D5F E5            [11]  678 	push	hl
   4D60 3E 25         [ 7]  679 	ld	a, #0x25
   4D62 F5            [11]  680 	push	af
   4D63 33            [ 6]  681 	inc	sp
   4D64 D5            [11]  682 	push	de
   4D65 33            [ 6]  683 	inc	sp
   4D66 CD 19 45      [17]  684 	call	_PrintU8
   4D69 F1            [10]  685 	pop	af
   4D6A 26 03         [ 7]  686 	ld	h,#0x03
   4D6C E3            [19]  687 	ex	(sp),hl
   4D6D 33            [ 6]  688 	inc	sp
   4D6E 21 47 4E      [10]  689 	ld	hl, #___str_5
   4D71 E5            [11]  690 	push	hl
   4D72 21 1F 06      [10]  691 	ld	hl, #0x061f
   4D75 E5            [11]  692 	push	hl
   4D76 CD CE 44      [17]  693 	call	_PrintAt
   4D79 F1            [10]  694 	pop	af
   4D7A F1            [10]  695 	pop	af
   4D7B 33            [ 6]  696 	inc	sp
   4D7C C1            [10]  697 	pop	bc
   4D7D C5            [11]  698 	push	bc
   4D7E FD E1         [14]  699 	pop	iy
   4D80 FD 56 1A      [19]  700 	ld	d, 26 (iy)
   4D83 C5            [11]  701 	push	bc
   4D84 21 06 02      [10]  702 	ld	hl, #0x0206
   4D87 E5            [11]  703 	push	hl
   4D88 3E 23         [ 7]  704 	ld	a, #0x23
   4D8A F5            [11]  705 	push	af
   4D8B 33            [ 6]  706 	inc	sp
   4D8C D5            [11]  707 	push	de
   4D8D 33            [ 6]  708 	inc	sp
   4D8E CD 19 45      [17]  709 	call	_PrintU8
   4D91 F1            [10]  710 	pop	af
   4D92 26 03         [ 7]  711 	ld	h,#0x03
   4D94 E3            [19]  712 	ex	(sp),hl
   4D95 33            [ 6]  713 	inc	sp
   4D96 21 4C 4E      [10]  714 	ld	hl, #___str_6
   4D99 E5            [11]  715 	push	hl
   4D9A 21 1F 07      [10]  716 	ld	hl, #0x071f
   4D9D E5            [11]  717 	push	hl
   4D9E CD CE 44      [17]  718 	call	_PrintAt
   4DA1 F1            [10]  719 	pop	af
   4DA2 F1            [10]  720 	pop	af
   4DA3 33            [ 6]  721 	inc	sp
   4DA4 C1            [10]  722 	pop	bc
   4DA5 C5            [11]  723 	push	bc
   4DA6 FD E1         [14]  724 	pop	iy
   4DA8 FD 56 1B      [19]  725 	ld	d, 27 (iy)
   4DAB C5            [11]  726 	push	bc
   4DAC 21 07 02      [10]  727 	ld	hl, #0x0207
   4DAF E5            [11]  728 	push	hl
   4DB0 3E 23         [ 7]  729 	ld	a, #0x23
   4DB2 F5            [11]  730 	push	af
   4DB3 33            [ 6]  731 	inc	sp
   4DB4 D5            [11]  732 	push	de
   4DB5 33            [ 6]  733 	inc	sp
   4DB6 CD 19 45      [17]  734 	call	_PrintU8
   4DB9 F1            [10]  735 	pop	af
   4DBA 26 03         [ 7]  736 	ld	h,#0x03
   4DBC E3            [19]  737 	ex	(sp),hl
   4DBD 33            [ 6]  738 	inc	sp
   4DBE 21 51 4E      [10]  739 	ld	hl, #___str_7
   4DC1 E5            [11]  740 	push	hl
   4DC2 21 1F 08      [10]  741 	ld	hl, #0x081f
   4DC5 E5            [11]  742 	push	hl
   4DC6 CD CE 44      [17]  743 	call	_PrintAt
   4DC9 F1            [10]  744 	pop	af
   4DCA F1            [10]  745 	pop	af
   4DCB 33            [ 6]  746 	inc	sp
   4DCC C1            [10]  747 	pop	bc
   4DCD C5            [11]  748 	push	bc
   4DCE FD E1         [14]  749 	pop	iy
   4DD0 FD 56 1C      [19]  750 	ld	d, 28 (iy)
   4DD3 C5            [11]  751 	push	bc
   4DD4 21 08 02      [10]  752 	ld	hl, #0x0208
   4DD7 E5            [11]  753 	push	hl
   4DD8 3E 23         [ 7]  754 	ld	a, #0x23
   4DDA F5            [11]  755 	push	af
   4DDB 33            [ 6]  756 	inc	sp
   4DDC D5            [11]  757 	push	de
   4DDD 33            [ 6]  758 	inc	sp
   4DDE CD 19 45      [17]  759 	call	_PrintU8
   4DE1 F1            [10]  760 	pop	af
   4DE2 26 03         [ 7]  761 	ld	h,#0x03
   4DE4 E3            [19]  762 	ex	(sp),hl
   4DE5 33            [ 6]  763 	inc	sp
   4DE6 21 56 4E      [10]  764 	ld	hl, #___str_8
   4DE9 E5            [11]  765 	push	hl
   4DEA 21 1F 0A      [10]  766 	ld	hl, #0x0a1f
   4DED E5            [11]  767 	push	hl
   4DEE CD CE 44      [17]  768 	call	_PrintAt
   4DF1 F1            [10]  769 	pop	af
   4DF2 F1            [10]  770 	pop	af
   4DF3 33            [ 6]  771 	inc	sp
   4DF4 C1            [10]  772 	pop	bc
   4DF5 69            [ 4]  773 	ld	l, c
   4DF6 60            [ 4]  774 	ld	h, b
   4DF7 11 1D 00      [10]  775 	ld	de, #0x001d
   4DFA 19            [11]  776 	add	hl, de
   4DFB 5E            [ 7]  777 	ld	e, (hl)
   4DFC 23            [ 6]  778 	inc	hl
   4DFD 56            [ 7]  779 	ld	d, (hl)
   4DFE 53            [ 4]  780 	ld	d, e
   4DFF C5            [11]  781 	push	bc
   4E00 21 0A 02      [10]  782 	ld	hl, #0x020a
   4E03 E5            [11]  783 	push	hl
   4E04 3E 23         [ 7]  784 	ld	a, #0x23
   4E06 F5            [11]  785 	push	af
   4E07 33            [ 6]  786 	inc	sp
   4E08 D5            [11]  787 	push	de
   4E09 33            [ 6]  788 	inc	sp
   4E0A CD 19 45      [17]  789 	call	_PrintU8
   4E0D F1            [10]  790 	pop	af
   4E0E 26 03         [ 7]  791 	ld	h,#0x03
   4E10 E3            [19]  792 	ex	(sp),hl
   4E11 33            [ 6]  793 	inc	sp
   4E12 21 5B 4E      [10]  794 	ld	hl, #___str_9
   4E15 E5            [11]  795 	push	hl
   4E16 21 1F 0B      [10]  796 	ld	hl, #0x0b1f
   4E19 E5            [11]  797 	push	hl
   4E1A CD CE 44      [17]  798 	call	_PrintAt
   4E1D F1            [10]  799 	pop	af
   4E1E F1            [10]  800 	pop	af
   4E1F 33            [ 6]  801 	inc	sp
   4E20 E1            [10]  802 	pop	hl
   4E21 11 1F 00      [10]  803 	ld	de, #0x001f
   4E24 19            [11]  804 	add	hl, de
   4E25 4E            [ 7]  805 	ld	c, (hl)
   4E26 23            [ 6]  806 	inc	hl
   4E27 46            [ 7]  807 	ld	b, (hl)
   4E28 41            [ 4]  808 	ld	b, c
   4E29 21 0B 02      [10]  809 	ld	hl, #0x020b
   4E2C E5            [11]  810 	push	hl
   4E2D 3E 23         [ 7]  811 	ld	a, #0x23
   4E2F F5            [11]  812 	push	af
   4E30 33            [ 6]  813 	inc	sp
   4E31 C5            [11]  814 	push	bc
   4E32 33            [ 6]  815 	inc	sp
   4E33 CD 19 45      [17]  816 	call	_PrintU8
   4E36 F1            [10]  817 	pop	af
   4E37 F1            [10]  818 	pop	af
   4E38 DD E1         [14]  819 	pop	ix
   4E3A C9            [10]  820 	ret
   4E3B                     821 ___str_3:
   4E3B 48 50 3A 20 20 20   822 	.ascii "HP:      "
        20 20 20
   4E44 00                  823 	.db 0x00
   4E45                     824 ___str_4:
   4E45 2F                  825 	.ascii "/"
   4E46 00                  826 	.db 0x00
   4E47                     827 ___str_5:
   4E47 53 54 52 3A         828 	.ascii "STR:"
   4E4B 00                  829 	.db 0x00
   4E4C                     830 ___str_6:
   4E4C 44 45 53 3A         831 	.ascii "DES:"
   4E50 00                  832 	.db 0x00
   4E51                     833 ___str_7:
   4E51 52 45 46 3A         834 	.ascii "REF:"
   4E55 00                  835 	.db 0x00
   4E56                     836 ___str_8:
   4E56 41 54 4B 3A         837 	.ascii "ATK:"
   4E5A 00                  838 	.db 0x00
   4E5B                     839 ___str_9:
   4E5B 44 45 46 3A         840 	.ascii "DEF:"
   4E5F 00                  841 	.db 0x00
                            842 ;src/user_interface.c:140: void DrawLine (u8 coords[], u8 ch, u8 color)
                            843 ;	---------------------------------
                            844 ; Function DrawLine
                            845 ; ---------------------------------
   4E60                     846 _DrawLine::
   4E60 DD E5         [15]  847 	push	ix
   4E62 DD 21 00 00   [14]  848 	ld	ix,#0
   4E66 DD 39         [15]  849 	add	ix,sp
                            850 ;src/user_interface.c:145: pen (color);
   4E68 DD 7E 07      [19]  851 	ld	a, 7 (ix)
   4E6B F5            [11]  852 	push	af
   4E6C 33            [ 6]  853 	inc	sp
   4E6D CD B9 44      [17]  854 	call	_pen
   4E70 33            [ 6]  855 	inc	sp
                            856 ;src/user_interface.c:146: ptr = coords;
   4E71 DD 4E 04      [19]  857 	ld	c,4 (ix)
   4E74 DD 46 05      [19]  858 	ld	b,5 (ix)
                            859 ;src/user_interface.c:147: while ( (x = *ptr++) != 0xff) {
   4E77                     860 00101$:
   4E77 0A            [ 7]  861 	ld	a, (bc)
   4E78 5F            [ 4]  862 	ld	e, a
   4E79 03            [ 6]  863 	inc	bc
   4E7A 53            [ 4]  864 	ld	d, e
   4E7B 1C            [ 4]  865 	inc	e
   4E7C 28 19         [12]  866 	jr	Z,00104$
                            867 ;src/user_interface.c:148: y = *ptr++;
   4E7E 0A            [ 7]  868 	ld	a, (bc)
   4E7F 67            [ 4]  869 	ld	h, a
   4E80 03            [ 6]  870 	inc	bc
                            871 ;src/user_interface.c:149: locate (x,y);
   4E81 C5            [11]  872 	push	bc
   4E82 6A            [ 4]  873 	ld	l, d
   4E83 E5            [11]  874 	push	hl
   4E84 CD 56 44      [17]  875 	call	_locate
   4E87 F1            [10]  876 	pop	af
   4E88 C1            [10]  877 	pop	bc
                            878 ;src/user_interface.c:150: putchar (ch);
   4E89 DD 5E 06      [19]  879 	ld	e, 6 (ix)
   4E8C 16 00         [ 7]  880 	ld	d, #0x00
   4E8E C5            [11]  881 	push	bc
   4E8F D5            [11]  882 	push	de
   4E90 CD 52 4F      [17]  883 	call	_putchar
   4E93 F1            [10]  884 	pop	af
   4E94 C1            [10]  885 	pop	bc
   4E95 18 E0         [12]  886 	jr	00101$
   4E97                     887 00104$:
   4E97 DD E1         [14]  888 	pop	ix
   4E99 C9            [10]  889 	ret
                            890 	.area _CODE
                            891 	.area _INITIALIZER
                            892 	.area _CABS (ABS)
