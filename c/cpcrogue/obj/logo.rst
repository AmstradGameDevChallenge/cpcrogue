                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module logo
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _ShowLogo
                             12 	.globl _PrintAt
                             13 	.globl _pen
                             14 	.globl _paper
                             15 	.globl _ink
                             16 	.globl _putchar
                             17 	.globl _cpct_setVideoMode
                             18 	.globl _cpct_isKeyPressed
                             19 	.globl _cpct_scanKeyboard
                             20 ;--------------------------------------------------------
                             21 ; special function registers
                             22 ;--------------------------------------------------------
                             23 ;--------------------------------------------------------
                             24 ; ram data
                             25 ;--------------------------------------------------------
                             26 	.area _DATA
                             27 ;--------------------------------------------------------
                             28 ; ram data
                             29 ;--------------------------------------------------------
                             30 	.area _INITIALIZED
                             31 ;--------------------------------------------------------
                             32 ; absolute external ram data
                             33 ;--------------------------------------------------------
                             34 	.area _DABS (ABS)
                             35 ;--------------------------------------------------------
                             36 ; global & static initialisations
                             37 ;--------------------------------------------------------
                             38 	.area _HOME
                             39 	.area _GSINIT
                             40 	.area _GSFINAL
                             41 	.area _GSINIT
                             42 ;--------------------------------------------------------
                             43 ; Home
                             44 ;--------------------------------------------------------
                             45 	.area _HOME
                             46 	.area _HOME
                             47 ;--------------------------------------------------------
                             48 ; code
                             49 ;--------------------------------------------------------
                             50 	.area _CODE
                             51 ;src/logo.c:4: void ShowLogo()
                             52 ;	---------------------------------
                             53 ; Function ShowLogo
                             54 ; ---------------------------------
   410B                      55 _ShowLogo::
                             56 ;src/logo.c:6: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
   410B 21 00 00      [10]   57 	ld	hl, #0x0000
   410E E5            [11]   58 	push	hl
   410F AF            [ 4]   59 	xor	a, a
   4110 F5            [11]   60 	push	af
   4111 33            [ 6]   61 	inc	sp
   4112 CD 7D 44      [17]   62 	call	_ink
   4115 33            [ 6]   63 	inc	sp
   4116 21 00 00      [10]   64 	ld	hl,#0x0000
   4119 E3            [19]   65 	ex	(sp),hl
   411A 3E 01         [ 7]   66 	ld	a, #0x01
   411C F5            [11]   67 	push	af
   411D 33            [ 6]   68 	inc	sp
   411E CD 7D 44      [17]   69 	call	_ink
   4121 33            [ 6]   70 	inc	sp
   4122 21 00 00      [10]   71 	ld	hl,#0x0000
   4125 E3            [19]   72 	ex	(sp),hl
   4126 3E 02         [ 7]   73 	ld	a, #0x02
   4128 F5            [11]   74 	push	af
   4129 33            [ 6]   75 	inc	sp
   412A CD 7D 44      [17]   76 	call	_ink
   412D F1            [10]   77 	pop	af
   412E 33            [ 6]   78 	inc	sp
                             79 ;src/logo.c:7: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
   412F 2E 01         [ 7]   80 	ld	l, #0x01
   4131 CD 8B 4D      [17]   81 	call	_cpct_setVideoMode
                             82 ;src/conio.h:9: putchar (GS);
   4134 21 1D 00      [10]   83 	ld	hl, #0x001d
   4137 E5            [11]   84 	push	hl
   4138 CD E4 4C      [17]   85 	call	_putchar
                             86 ;src/conio.h:10: putchar (color1); putchar (color1);
   413B 21 01 00      [10]   87 	ld	hl, #0x0001
   413E E3            [19]   88 	ex	(sp),hl
   413F CD E4 4C      [17]   89 	call	_putchar
   4142 21 01 00      [10]   90 	ld	hl, #0x0001
   4145 E3            [19]   91 	ex	(sp),hl
   4146 CD E4 4C      [17]   92 	call	_putchar
   4149 F1            [10]   93 	pop	af
                             94 ;src/logo.c:8: border (1); paper (0); pen (1);
   414A AF            [ 4]   95 	xor	a, a
   414B F5            [11]   96 	push	af
   414C 33            [ 6]   97 	inc	sp
   414D CD AA 44      [17]   98 	call	_paper
   4150 33            [ 6]   99 	inc	sp
   4151 3E 01         [ 7]  100 	ld	a, #0x01
   4153 F5            [11]  101 	push	af
   4154 33            [ 6]  102 	inc	sp
   4155 CD BF 44      [17]  103 	call	_pen
   4158 33            [ 6]  104 	inc	sp
                            105 ;src/logo.c:10: PrintAt (1,5, "      )   ___    _____    )   ___", 0xff);
   4159 3E FF         [ 7]  106 	ld	a, #0xff
   415B F5            [11]  107 	push	af
   415C 33            [ 6]  108 	inc	sp
   415D 21 77 42      [10]  109 	ld	hl, #___str_0
   4160 E5            [11]  110 	push	hl
   4161 21 01 05      [10]  111 	ld	hl, #0x0501
   4164 E5            [11]  112 	push	hl
   4165 CD D4 44      [17]  113 	call	_PrintAt
   4168 F1            [10]  114 	pop	af
   4169 F1            [10]  115 	pop	af
   416A 33            [ 6]  116 	inc	sp
                            117 ;src/logo.c:11: PrintAt (1,6, "     (__/_____) (, /   ) (__/_____)", 0xff);
   416B 3E FF         [ 7]  118 	ld	a, #0xff
   416D F5            [11]  119 	push	af
   416E 33            [ 6]  120 	inc	sp
   416F 21 99 42      [10]  121 	ld	hl, #___str_1
   4172 E5            [11]  122 	push	hl
   4173 21 01 06      [10]  123 	ld	hl, #0x0601
   4176 E5            [11]  124 	push	hl
   4177 CD D4 44      [17]  125 	call	_PrintAt
   417A F1            [10]  126 	pop	af
   417B F1            [10]  127 	pop	af
   417C 33            [ 6]  128 	inc	sp
                            129 ;src/logo.c:12: PrintAt (1,7, "       /         _/__ /    /", 0xff);
   417D 3E FF         [ 7]  130 	ld	a, #0xff
   417F F5            [11]  131 	push	af
   4180 33            [ 6]  132 	inc	sp
   4181 21 BD 42      [10]  133 	ld	hl, #___str_2
   4184 E5            [11]  134 	push	hl
   4185 21 01 07      [10]  135 	ld	hl, #0x0701
   4188 E5            [11]  136 	push	hl
   4189 CD D4 44      [17]  137 	call	_PrintAt
   418C F1            [10]  138 	pop	af
   418D F1            [10]  139 	pop	af
   418E 33            [ 6]  140 	inc	sp
                            141 ;src/logo.c:13: PrintAt (1,8, "      /          /        /", 0xff);
   418F 3E FF         [ 7]  142 	ld	a, #0xff
   4191 F5            [11]  143 	push	af
   4192 33            [ 6]  144 	inc	sp
   4193 21 DA 42      [10]  145 	ld	hl, #___str_3
   4196 E5            [11]  146 	push	hl
   4197 21 01 08      [10]  147 	ld	hl, #0x0801
   419A E5            [11]  148 	push	hl
   419B CD D4 44      [17]  149 	call	_PrintAt
   419E F1            [10]  150 	pop	af
   419F F1            [10]  151 	pop	af
   41A0 33            [ 6]  152 	inc	sp
                            153 ;src/logo.c:14: PrintAt (1,9, "     (______) ) /        (______)", 0xff);
   41A1 3E FF         [ 7]  154 	ld	a, #0xff
   41A3 F5            [11]  155 	push	af
   41A4 33            [ 6]  156 	inc	sp
   41A5 21 F6 42      [10]  157 	ld	hl, #___str_4
   41A8 E5            [11]  158 	push	hl
   41A9 21 01 09      [10]  159 	ld	hl, #0x0901
   41AC E5            [11]  160 	push	hl
   41AD CD D4 44      [17]  161 	call	_PrintAt
   41B0 F1            [10]  162 	pop	af
   41B1 F1            [10]  163 	pop	af
   41B2 33            [ 6]  164 	inc	sp
                            165 ;src/logo.c:15: PrintAt (1,10, "            _(_/_", 0xff);
   41B3 3E FF         [ 7]  166 	ld	a, #0xff
   41B5 F5            [11]  167 	push	af
   41B6 33            [ 6]  168 	inc	sp
   41B7 21 18 43      [10]  169 	ld	hl, #___str_5
   41BA E5            [11]  170 	push	hl
   41BB 21 01 0A      [10]  171 	ld	hl, #0x0a01
   41BE E5            [11]  172 	push	hl
   41BF CD D4 44      [17]  173 	call	_PrintAt
   41C2 F1            [10]  174 	pop	af
   41C3 F1            [10]  175 	pop	af
   41C4 33            [ 6]  176 	inc	sp
                            177 ;src/logo.c:16: PrintAt (1,11, "           (, /   )", 0xff);
   41C5 3E FF         [ 7]  178 	ld	a, #0xff
   41C7 F5            [11]  179 	push	af
   41C8 33            [ 6]  180 	inc	sp
   41C9 21 2A 43      [10]  181 	ld	hl, #___str_6
   41CC E5            [11]  182 	push	hl
   41CD 21 01 0B      [10]  183 	ld	hl, #0x0b01
   41D0 E5            [11]  184 	push	hl
   41D1 CD D4 44      [17]  185 	call	_PrintAt
   41D4 F1            [10]  186 	pop	af
   41D5 F1            [10]  187 	pop	af
   41D6 33            [ 6]  188 	inc	sp
                            189 ;src/logo.c:17: PrintAt (1,12, "             /__ / ___      _", 0xff);
   41D7 3E FF         [ 7]  190 	ld	a, #0xff
   41D9 F5            [11]  191 	push	af
   41DA 33            [ 6]  192 	inc	sp
   41DB 21 3E 43      [10]  193 	ld	hl, #___str_7
   41DE E5            [11]  194 	push	hl
   41DF 21 01 0C      [10]  195 	ld	hl, #0x0c01
   41E2 E5            [11]  196 	push	hl
   41E3 CD D4 44      [17]  197 	call	_PrintAt
   41E6 F1            [10]  198 	pop	af
   41E7 F1            [10]  199 	pop	af
   41E8 33            [ 6]  200 	inc	sp
                            201 ;src/logo.c:20: PrintAt (1,13, "          ) /   \\_(_(_/(_(_(/_         ", 0xff);
   41E9 3E FF         [ 7]  202 	ld	a, #0xff
   41EB F5            [11]  203 	push	af
   41EC 33            [ 6]  204 	inc	sp
   41ED 21 5C 43      [10]  205 	ld	hl, #___str_8
   41F0 E5            [11]  206 	push	hl
   41F1 21 01 0D      [10]  207 	ld	hl, #0x0d01
   41F4 E5            [11]  208 	push	hl
   41F5 CD D4 44      [17]  209 	call	_PrintAt
   41F8 F1            [10]  210 	pop	af
   41F9 F1            [10]  211 	pop	af
   41FA 33            [ 6]  212 	inc	sp
                            213 ;src/logo.c:21: PrintAt (1,14, "         (_/       .-/                 ", 0xff);
   41FB 3E FF         [ 7]  214 	ld	a, #0xff
   41FD F5            [11]  215 	push	af
   41FE 33            [ 6]  216 	inc	sp
   41FF 21 84 43      [10]  217 	ld	hl, #___str_9
   4202 E5            [11]  218 	push	hl
   4203 21 01 0E      [10]  219 	ld	hl, #0x0e01
   4206 E5            [11]  220 	push	hl
   4207 CD D4 44      [17]  221 	call	_PrintAt
   420A F1            [10]  222 	pop	af
   420B F1            [10]  223 	pop	af
   420C 33            [ 6]  224 	inc	sp
                            225 ;src/logo.c:22: PrintAt (1,15, "                  (_/                  ", 0xff);
   420D 3E FF         [ 7]  226 	ld	a, #0xff
   420F F5            [11]  227 	push	af
   4210 33            [ 6]  228 	inc	sp
   4211 21 AC 43      [10]  229 	ld	hl, #___str_10
   4214 E5            [11]  230 	push	hl
   4215 21 01 0F      [10]  231 	ld	hl, #0x0f01
   4218 E5            [11]  232 	push	hl
   4219 CD D4 44      [17]  233 	call	_PrintAt
   421C F1            [10]  234 	pop	af
   421D F1            [10]  235 	pop	af
   421E 33            [ 6]  236 	inc	sp
                            237 ;src/logo.c:23: PrintAt (10, 18, "PRESS ENTER TO START", 2);
   421F 3E 02         [ 7]  238 	ld	a, #0x02
   4221 F5            [11]  239 	push	af
   4222 33            [ 6]  240 	inc	sp
   4223 21 D4 43      [10]  241 	ld	hl, #___str_11
   4226 E5            [11]  242 	push	hl
   4227 21 0A 12      [10]  243 	ld	hl, #0x120a
   422A E5            [11]  244 	push	hl
   422B CD D4 44      [17]  245 	call	_PrintAt
   422E F1            [10]  246 	pop	af
                            247 ;src/logo.c:24: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3);
   422F 33            [ 6]  248 	inc	sp
   4230 21 03 03      [10]  249 	ld	hl,#0x0303
   4233 E3            [19]  250 	ex	(sp),hl
   4234 AF            [ 4]  251 	xor	a, a
   4235 F5            [11]  252 	push	af
   4236 33            [ 6]  253 	inc	sp
   4237 CD 7D 44      [17]  254 	call	_ink
   423A 33            [ 6]  255 	inc	sp
   423B 21 06 0F      [10]  256 	ld	hl,#0x0f06
   423E E3            [19]  257 	ex	(sp),hl
   423F 3E 01         [ 7]  258 	ld	a, #0x01
   4241 F5            [11]  259 	push	af
   4242 33            [ 6]  260 	inc	sp
   4243 CD 7D 44      [17]  261 	call	_ink
   4246 33            [ 6]  262 	inc	sp
   4247 21 10 10      [10]  263 	ld	hl,#0x1010
   424A E3            [19]  264 	ex	(sp),hl
   424B 3E 02         [ 7]  265 	ld	a, #0x02
   424D F5            [11]  266 	push	af
   424E 33            [ 6]  267 	inc	sp
   424F CD 7D 44      [17]  268 	call	_ink
                            269 ;src/conio.h:9: putchar (GS);
   4252 33            [ 6]  270 	inc	sp
   4253 21 1D 00      [10]  271 	ld	hl,#0x001d
   4256 E3            [19]  272 	ex	(sp),hl
   4257 CD E4 4C      [17]  273 	call	_putchar
                            274 ;src/conio.h:10: putchar (color1); putchar (color1);
   425A 21 03 00      [10]  275 	ld	hl, #0x0003
   425D E3            [19]  276 	ex	(sp),hl
   425E CD E4 4C      [17]  277 	call	_putchar
   4261 21 03 00      [10]  278 	ld	hl, #0x0003
   4264 E3            [19]  279 	ex	(sp),hl
   4265 CD E4 4C      [17]  280 	call	_putchar
   4268 F1            [10]  281 	pop	af
                            282 ;src/logo.c:27: while (!cpct_isKeyPressed (Key_Return)) {
   4269                     283 00101$:
   4269 21 02 04      [10]  284 	ld	hl, #0x0402
   426C CD D8 4C      [17]  285 	call	_cpct_isKeyPressed
   426F 7D            [ 4]  286 	ld	a, l
   4270 B7            [ 4]  287 	or	a, a
   4271 C0            [11]  288 	ret	NZ
                            289 ;src/logo.c:28: cpct_scanKeyboard ();
   4272 CD BF 4D      [17]  290 	call	_cpct_scanKeyboard
   4275 18 F2         [12]  291 	jr	00101$
   4277                     292 ___str_0:
   4277 20 20 20 20 20 20   293 	.ascii "      )   ___    _____    )   ___"
        29 20 20 20 5F 5F
        5F 20 20 20 20 5F
        5F 5F 5F 5F 20 20
        20 20 29 20 20 20
        5F 5F 5F
   4298 00                  294 	.db 0x00
   4299                     295 ___str_1:
   4299 20 20 20 20 20 28   296 	.ascii "     (__/_____) (, /   ) (__/_____)"
        5F 5F 2F 5F 5F 5F
        5F 5F 29 20 28 2C
        20 2F 20 20 20 29
        20 28 5F 5F 2F 5F
        5F 5F 5F 5F 29
   42BC 00                  297 	.db 0x00
   42BD                     298 ___str_2:
   42BD 20 20 20 20 20 20   299 	.ascii "       /         _/__ /    /"
        20 2F 20 20 20 20
        20 20 20 20 20 5F
        2F 5F 5F 20 2F 20
        20 20 20 2F
   42D9 00                  300 	.db 0x00
   42DA                     301 ___str_3:
   42DA 20 20 20 20 20 20   302 	.ascii "      /          /        /"
        2F 20 20 20 20 20
        20 20 20 20 20 2F
        20 20 20 20 20 20
        20 20 2F
   42F5 00                  303 	.db 0x00
   42F6                     304 ___str_4:
   42F6 20 20 20 20 20 28   305 	.ascii "     (______) ) /        (______)"
        5F 5F 5F 5F 5F 5F
        29 20 29 20 2F 20
        20 20 20 20 20 20
        20 28 5F 5F 5F 5F
        5F 5F 29
   4317 00                  306 	.db 0x00
   4318                     307 ___str_5:
   4318 20 20 20 20 20 20   308 	.ascii "            _(_/_"
        20 20 20 20 20 20
        5F 28 5F 2F 5F
   4329 00                  309 	.db 0x00
   432A                     310 ___str_6:
   432A 20 20 20 20 20 20   311 	.ascii "           (, /   )"
        20 20 20 20 20 28
        2C 20 2F 20 20 20
        29
   433D 00                  312 	.db 0x00
   433E                     313 ___str_7:
   433E 20 20 20 20 20 20   314 	.ascii "             /__ / ___      _"
        20 20 20 20 20 20
        20 2F 5F 5F 20 2F
        20 5F 5F 5F 20 20
        20 20 20 20 5F
   435B 00                  315 	.db 0x00
   435C                     316 ___str_8:
   435C 20 20 20 20 20 20   317 	.ascii "          ) /   "
        20 20 20 20 29 20
        2F 20 20 20
   436C 5C                  318 	.db 0x5c
   436D 5F 28 5F 28 5F 2F   319 	.ascii "_(_(_/(_(_(/_         "
        28 5F 28 5F 28 2F
        5F 20 20 20 20 20
        20 20 20 20
   4383 00                  320 	.db 0x00
   4384                     321 ___str_9:
   4384 20 20 20 20 20 20   322 	.ascii "         (_/       .-/                 "
        20 20 20 28 5F 2F
        20 20 20 20 20 20
        20 2E 2D 2F 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   43AB 00                  323 	.db 0x00
   43AC                     324 ___str_10:
   43AC 20 20 20 20 20 20   325 	.ascii "                  (_/                  "
        20 20 20 20 20 20
        20 20 20 20 20 20
        28 5F 2F 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   43D3 00                  326 	.db 0x00
   43D4                     327 ___str_11:
   43D4 50 52 45 53 53 20   328 	.ascii "PRESS ENTER TO START"
        45 4E 54 45 52 20
        54 4F 20 53 54 41
        52 54
   43E8 00                  329 	.db 0x00
                            330 	.area _CODE
                            331 	.area _INITIALIZER
                            332 	.area _CABS (ABS)
