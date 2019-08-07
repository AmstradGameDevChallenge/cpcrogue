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
   4105                      55 _ShowLogo::
                             56 ;src/logo.c:6: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
   4105 21 00 00      [10]   57 	ld	hl, #0x0000
   4108 E5            [11]   58 	push	hl
   4109 AF            [ 4]   59 	xor	a, a
   410A F5            [11]   60 	push	af
   410B 33            [ 6]   61 	inc	sp
   410C CD 77 44      [17]   62 	call	_ink
   410F 33            [ 6]   63 	inc	sp
   4110 21 00 00      [10]   64 	ld	hl,#0x0000
   4113 E3            [19]   65 	ex	(sp),hl
   4114 3E 01         [ 7]   66 	ld	a, #0x01
   4116 F5            [11]   67 	push	af
   4117 33            [ 6]   68 	inc	sp
   4118 CD 77 44      [17]   69 	call	_ink
   411B 33            [ 6]   70 	inc	sp
   411C 21 00 00      [10]   71 	ld	hl,#0x0000
   411F E3            [19]   72 	ex	(sp),hl
   4120 3E 02         [ 7]   73 	ld	a, #0x02
   4122 F5            [11]   74 	push	af
   4123 33            [ 6]   75 	inc	sp
   4124 CD 77 44      [17]   76 	call	_ink
   4127 F1            [10]   77 	pop	af
   4128 33            [ 6]   78 	inc	sp
                             79 ;src/logo.c:7: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
   4129 2E 01         [ 7]   80 	ld	l, #0x01
   412B CD F4 4F      [17]   81 	call	_cpct_setVideoMode
                             82 ;src/conio.h:9: putchar (GS);
   412E 21 1D 00      [10]   83 	ld	hl, #0x001d
   4131 E5            [11]   84 	push	hl
   4132 CD 52 4F      [17]   85 	call	_putchar
                             86 ;src/conio.h:10: putchar (color1); putchar (color1);
   4135 21 01 00      [10]   87 	ld	hl, #0x0001
   4138 E3            [19]   88 	ex	(sp),hl
   4139 CD 52 4F      [17]   89 	call	_putchar
   413C 21 01 00      [10]   90 	ld	hl, #0x0001
   413F E3            [19]   91 	ex	(sp),hl
   4140 CD 52 4F      [17]   92 	call	_putchar
   4143 F1            [10]   93 	pop	af
                             94 ;src/logo.c:8: border (1); paper (0); pen (1);
   4144 AF            [ 4]   95 	xor	a, a
   4145 F5            [11]   96 	push	af
   4146 33            [ 6]   97 	inc	sp
   4147 CD A4 44      [17]   98 	call	_paper
   414A 33            [ 6]   99 	inc	sp
   414B 3E 01         [ 7]  100 	ld	a, #0x01
   414D F5            [11]  101 	push	af
   414E 33            [ 6]  102 	inc	sp
   414F CD B9 44      [17]  103 	call	_pen
   4152 33            [ 6]  104 	inc	sp
                            105 ;src/logo.c:10: PrintAt (1,5, "      )   ___    _____    )   ___", 0xff);
   4153 3E FF         [ 7]  106 	ld	a, #0xff
   4155 F5            [11]  107 	push	af
   4156 33            [ 6]  108 	inc	sp
   4157 21 71 42      [10]  109 	ld	hl, #___str_0
   415A E5            [11]  110 	push	hl
   415B 21 01 05      [10]  111 	ld	hl, #0x0501
   415E E5            [11]  112 	push	hl
   415F CD CE 44      [17]  113 	call	_PrintAt
   4162 F1            [10]  114 	pop	af
   4163 F1            [10]  115 	pop	af
   4164 33            [ 6]  116 	inc	sp
                            117 ;src/logo.c:11: PrintAt (1,6, "     (__/_____) (, /   ) (__/_____)", 0xff);
   4165 3E FF         [ 7]  118 	ld	a, #0xff
   4167 F5            [11]  119 	push	af
   4168 33            [ 6]  120 	inc	sp
   4169 21 93 42      [10]  121 	ld	hl, #___str_1
   416C E5            [11]  122 	push	hl
   416D 21 01 06      [10]  123 	ld	hl, #0x0601
   4170 E5            [11]  124 	push	hl
   4171 CD CE 44      [17]  125 	call	_PrintAt
   4174 F1            [10]  126 	pop	af
   4175 F1            [10]  127 	pop	af
   4176 33            [ 6]  128 	inc	sp
                            129 ;src/logo.c:12: PrintAt (1,7, "       /         _/__ /    /", 0xff);
   4177 3E FF         [ 7]  130 	ld	a, #0xff
   4179 F5            [11]  131 	push	af
   417A 33            [ 6]  132 	inc	sp
   417B 21 B7 42      [10]  133 	ld	hl, #___str_2
   417E E5            [11]  134 	push	hl
   417F 21 01 07      [10]  135 	ld	hl, #0x0701
   4182 E5            [11]  136 	push	hl
   4183 CD CE 44      [17]  137 	call	_PrintAt
   4186 F1            [10]  138 	pop	af
   4187 F1            [10]  139 	pop	af
   4188 33            [ 6]  140 	inc	sp
                            141 ;src/logo.c:13: PrintAt (1,8, "      /          /        /", 0xff);
   4189 3E FF         [ 7]  142 	ld	a, #0xff
   418B F5            [11]  143 	push	af
   418C 33            [ 6]  144 	inc	sp
   418D 21 D4 42      [10]  145 	ld	hl, #___str_3
   4190 E5            [11]  146 	push	hl
   4191 21 01 08      [10]  147 	ld	hl, #0x0801
   4194 E5            [11]  148 	push	hl
   4195 CD CE 44      [17]  149 	call	_PrintAt
   4198 F1            [10]  150 	pop	af
   4199 F1            [10]  151 	pop	af
   419A 33            [ 6]  152 	inc	sp
                            153 ;src/logo.c:14: PrintAt (1,9, "     (______) ) /        (______)", 0xff);
   419B 3E FF         [ 7]  154 	ld	a, #0xff
   419D F5            [11]  155 	push	af
   419E 33            [ 6]  156 	inc	sp
   419F 21 F0 42      [10]  157 	ld	hl, #___str_4
   41A2 E5            [11]  158 	push	hl
   41A3 21 01 09      [10]  159 	ld	hl, #0x0901
   41A6 E5            [11]  160 	push	hl
   41A7 CD CE 44      [17]  161 	call	_PrintAt
   41AA F1            [10]  162 	pop	af
   41AB F1            [10]  163 	pop	af
   41AC 33            [ 6]  164 	inc	sp
                            165 ;src/logo.c:15: PrintAt (1,10, "            _(_/_", 0xff);
   41AD 3E FF         [ 7]  166 	ld	a, #0xff
   41AF F5            [11]  167 	push	af
   41B0 33            [ 6]  168 	inc	sp
   41B1 21 12 43      [10]  169 	ld	hl, #___str_5
   41B4 E5            [11]  170 	push	hl
   41B5 21 01 0A      [10]  171 	ld	hl, #0x0a01
   41B8 E5            [11]  172 	push	hl
   41B9 CD CE 44      [17]  173 	call	_PrintAt
   41BC F1            [10]  174 	pop	af
   41BD F1            [10]  175 	pop	af
   41BE 33            [ 6]  176 	inc	sp
                            177 ;src/logo.c:16: PrintAt (1,11, "           (, /   )", 0xff);
   41BF 3E FF         [ 7]  178 	ld	a, #0xff
   41C1 F5            [11]  179 	push	af
   41C2 33            [ 6]  180 	inc	sp
   41C3 21 24 43      [10]  181 	ld	hl, #___str_6
   41C6 E5            [11]  182 	push	hl
   41C7 21 01 0B      [10]  183 	ld	hl, #0x0b01
   41CA E5            [11]  184 	push	hl
   41CB CD CE 44      [17]  185 	call	_PrintAt
   41CE F1            [10]  186 	pop	af
   41CF F1            [10]  187 	pop	af
   41D0 33            [ 6]  188 	inc	sp
                            189 ;src/logo.c:17: PrintAt (1,12, "             /__ / ___      _", 0xff);
   41D1 3E FF         [ 7]  190 	ld	a, #0xff
   41D3 F5            [11]  191 	push	af
   41D4 33            [ 6]  192 	inc	sp
   41D5 21 38 43      [10]  193 	ld	hl, #___str_7
   41D8 E5            [11]  194 	push	hl
   41D9 21 01 0C      [10]  195 	ld	hl, #0x0c01
   41DC E5            [11]  196 	push	hl
   41DD CD CE 44      [17]  197 	call	_PrintAt
   41E0 F1            [10]  198 	pop	af
   41E1 F1            [10]  199 	pop	af
   41E2 33            [ 6]  200 	inc	sp
                            201 ;src/logo.c:20: PrintAt (1,13, "          ) /   \\_(_(_/(_(_(/_         ", 0xff);
   41E3 3E FF         [ 7]  202 	ld	a, #0xff
   41E5 F5            [11]  203 	push	af
   41E6 33            [ 6]  204 	inc	sp
   41E7 21 56 43      [10]  205 	ld	hl, #___str_8
   41EA E5            [11]  206 	push	hl
   41EB 21 01 0D      [10]  207 	ld	hl, #0x0d01
   41EE E5            [11]  208 	push	hl
   41EF CD CE 44      [17]  209 	call	_PrintAt
   41F2 F1            [10]  210 	pop	af
   41F3 F1            [10]  211 	pop	af
   41F4 33            [ 6]  212 	inc	sp
                            213 ;src/logo.c:21: PrintAt (1,14, "         (_/       .-/                 ", 0xff);
   41F5 3E FF         [ 7]  214 	ld	a, #0xff
   41F7 F5            [11]  215 	push	af
   41F8 33            [ 6]  216 	inc	sp
   41F9 21 7E 43      [10]  217 	ld	hl, #___str_9
   41FC E5            [11]  218 	push	hl
   41FD 21 01 0E      [10]  219 	ld	hl, #0x0e01
   4200 E5            [11]  220 	push	hl
   4201 CD CE 44      [17]  221 	call	_PrintAt
   4204 F1            [10]  222 	pop	af
   4205 F1            [10]  223 	pop	af
   4206 33            [ 6]  224 	inc	sp
                            225 ;src/logo.c:22: PrintAt (1,15, "                  (_/                  ", 0xff);
   4207 3E FF         [ 7]  226 	ld	a, #0xff
   4209 F5            [11]  227 	push	af
   420A 33            [ 6]  228 	inc	sp
   420B 21 A6 43      [10]  229 	ld	hl, #___str_10
   420E E5            [11]  230 	push	hl
   420F 21 01 0F      [10]  231 	ld	hl, #0x0f01
   4212 E5            [11]  232 	push	hl
   4213 CD CE 44      [17]  233 	call	_PrintAt
   4216 F1            [10]  234 	pop	af
   4217 F1            [10]  235 	pop	af
   4218 33            [ 6]  236 	inc	sp
                            237 ;src/logo.c:23: PrintAt (10, 18, "PRESS ENTER TO START", 2);
   4219 3E 02         [ 7]  238 	ld	a, #0x02
   421B F5            [11]  239 	push	af
   421C 33            [ 6]  240 	inc	sp
   421D 21 CE 43      [10]  241 	ld	hl, #___str_11
   4220 E5            [11]  242 	push	hl
   4221 21 0A 12      [10]  243 	ld	hl, #0x120a
   4224 E5            [11]  244 	push	hl
   4225 CD CE 44      [17]  245 	call	_PrintAt
   4228 F1            [10]  246 	pop	af
                            247 ;src/logo.c:24: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3);
   4229 33            [ 6]  248 	inc	sp
   422A 21 03 03      [10]  249 	ld	hl,#0x0303
   422D E3            [19]  250 	ex	(sp),hl
   422E AF            [ 4]  251 	xor	a, a
   422F F5            [11]  252 	push	af
   4230 33            [ 6]  253 	inc	sp
   4231 CD 77 44      [17]  254 	call	_ink
   4234 33            [ 6]  255 	inc	sp
   4235 21 06 0F      [10]  256 	ld	hl,#0x0f06
   4238 E3            [19]  257 	ex	(sp),hl
   4239 3E 01         [ 7]  258 	ld	a, #0x01
   423B F5            [11]  259 	push	af
   423C 33            [ 6]  260 	inc	sp
   423D CD 77 44      [17]  261 	call	_ink
   4240 33            [ 6]  262 	inc	sp
   4241 21 10 10      [10]  263 	ld	hl,#0x1010
   4244 E3            [19]  264 	ex	(sp),hl
   4245 3E 02         [ 7]  265 	ld	a, #0x02
   4247 F5            [11]  266 	push	af
   4248 33            [ 6]  267 	inc	sp
   4249 CD 77 44      [17]  268 	call	_ink
                            269 ;src/conio.h:9: putchar (GS);
   424C 33            [ 6]  270 	inc	sp
   424D 21 1D 00      [10]  271 	ld	hl,#0x001d
   4250 E3            [19]  272 	ex	(sp),hl
   4251 CD 52 4F      [17]  273 	call	_putchar
                            274 ;src/conio.h:10: putchar (color1); putchar (color1);
   4254 21 03 00      [10]  275 	ld	hl, #0x0003
   4257 E3            [19]  276 	ex	(sp),hl
   4258 CD 52 4F      [17]  277 	call	_putchar
   425B 21 03 00      [10]  278 	ld	hl, #0x0003
   425E E3            [19]  279 	ex	(sp),hl
   425F CD 52 4F      [17]  280 	call	_putchar
   4262 F1            [10]  281 	pop	af
                            282 ;src/logo.c:27: while (!cpct_isKeyPressed (Key_Return)) {
   4263                     283 00101$:
   4263 21 02 04      [10]  284 	ld	hl, #0x0402
   4266 CD 46 4F      [17]  285 	call	_cpct_isKeyPressed
   4269 7D            [ 4]  286 	ld	a, l
   426A B7            [ 4]  287 	or	a, a
   426B C0            [11]  288 	ret	NZ
                            289 ;src/logo.c:28: cpct_scanKeyboard ();
   426C CD 28 50      [17]  290 	call	_cpct_scanKeyboard
   426F 18 F2         [12]  291 	jr	00101$
   4271                     292 ___str_0:
   4271 20 20 20 20 20 20   293 	.ascii "      )   ___    _____    )   ___"
        29 20 20 20 5F 5F
        5F 20 20 20 20 5F
        5F 5F 5F 5F 20 20
        20 20 29 20 20 20
        5F 5F 5F
   4292 00                  294 	.db 0x00
   4293                     295 ___str_1:
   4293 20 20 20 20 20 28   296 	.ascii "     (__/_____) (, /   ) (__/_____)"
        5F 5F 2F 5F 5F 5F
        5F 5F 29 20 28 2C
        20 2F 20 20 20 29
        20 28 5F 5F 2F 5F
        5F 5F 5F 5F 29
   42B6 00                  297 	.db 0x00
   42B7                     298 ___str_2:
   42B7 20 20 20 20 20 20   299 	.ascii "       /         _/__ /    /"
        20 2F 20 20 20 20
        20 20 20 20 20 5F
        2F 5F 5F 20 2F 20
        20 20 20 2F
   42D3 00                  300 	.db 0x00
   42D4                     301 ___str_3:
   42D4 20 20 20 20 20 20   302 	.ascii "      /          /        /"
        2F 20 20 20 20 20
        20 20 20 20 20 2F
        20 20 20 20 20 20
        20 20 2F
   42EF 00                  303 	.db 0x00
   42F0                     304 ___str_4:
   42F0 20 20 20 20 20 28   305 	.ascii "     (______) ) /        (______)"
        5F 5F 5F 5F 5F 5F
        29 20 29 20 2F 20
        20 20 20 20 20 20
        20 28 5F 5F 5F 5F
        5F 5F 29
   4311 00                  306 	.db 0x00
   4312                     307 ___str_5:
   4312 20 20 20 20 20 20   308 	.ascii "            _(_/_"
        20 20 20 20 20 20
        5F 28 5F 2F 5F
   4323 00                  309 	.db 0x00
   4324                     310 ___str_6:
   4324 20 20 20 20 20 20   311 	.ascii "           (, /   )"
        20 20 20 20 20 28
        2C 20 2F 20 20 20
        29
   4337 00                  312 	.db 0x00
   4338                     313 ___str_7:
   4338 20 20 20 20 20 20   314 	.ascii "             /__ / ___      _"
        20 20 20 20 20 20
        20 2F 5F 5F 20 2F
        20 5F 5F 5F 20 20
        20 20 20 20 5F
   4355 00                  315 	.db 0x00
   4356                     316 ___str_8:
   4356 20 20 20 20 20 20   317 	.ascii "          ) /   "
        20 20 20 20 29 20
        2F 20 20 20
   4366 5C                  318 	.db 0x5c
   4367 5F 28 5F 28 5F 2F   319 	.ascii "_(_(_/(_(_(/_         "
        28 5F 28 5F 28 2F
        5F 20 20 20 20 20
        20 20 20 20
   437D 00                  320 	.db 0x00
   437E                     321 ___str_9:
   437E 20 20 20 20 20 20   322 	.ascii "         (_/       .-/                 "
        20 20 20 28 5F 2F
        20 20 20 20 20 20
        20 2E 2D 2F 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   43A5 00                  323 	.db 0x00
   43A6                     324 ___str_10:
   43A6 20 20 20 20 20 20   325 	.ascii "                  (_/                  "
        20 20 20 20 20 20
        20 20 20 20 20 20
        28 5F 2F 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   43CD 00                  326 	.db 0x00
   43CE                     327 ___str_11:
   43CE 50 52 45 53 53 20   328 	.ascii "PRESS ENTER TO START"
        45 4E 54 45 52 20
        54 4F 20 53 54 41
        52 54
   43E2 00                  329 	.db 0x00
                            330 	.area _CODE
                            331 	.area _INITIALIZER
                            332 	.area _CABS (ABS)
