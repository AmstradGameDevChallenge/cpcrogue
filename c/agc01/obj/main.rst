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
                             12 	.globl _pen
                             13 	.globl _paper
                             14 	.globl _border
                             15 	.globl _ink
                             16 	.globl _locate
                             17 	.globl _putchar
                             18 	.globl _printf
                             19 	.globl _cpct_setVideoMode
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
                             51 ;src/main.c:33: void locate (u8 x, u8 y)
                             52 ;	---------------------------------
                             53 ; Function locate
                             54 ; ---------------------------------
   4000                      55 _locate::
                             56 ;src/main.c:35: putchar(US);
   4000 21 1F 00      [10]   57 	ld	hl, #0x001f
   4003 E5            [11]   58 	push	hl
   4004 CD 8E 43      [17]   59 	call	_putchar
   4007 F1            [10]   60 	pop	af
                             61 ;src/main.c:36: putchar (x); putchar (y);
   4008 21 02 00      [10]   62 	ld	hl, #2+0
   400B 39            [11]   63 	add	hl, sp
   400C 4E            [ 7]   64 	ld	c, (hl)
   400D 06 00         [ 7]   65 	ld	b, #0x00
   400F C5            [11]   66 	push	bc
   4010 CD 8E 43      [17]   67 	call	_putchar
   4013 F1            [10]   68 	pop	af
   4014 21 03 00      [10]   69 	ld	hl, #3+0
   4017 39            [11]   70 	add	hl, sp
   4018 4E            [ 7]   71 	ld	c, (hl)
   4019 06 00         [ 7]   72 	ld	b, #0x00
   401B C5            [11]   73 	push	bc
   401C CD 8E 43      [17]   74 	call	_putchar
   401F F1            [10]   75 	pop	af
   4020 C9            [10]   76 	ret
                             77 ;src/main.c:38: void ink (u8 tinta, u8 color1, u8 color2)
                             78 ;	---------------------------------
                             79 ; Function ink
                             80 ; ---------------------------------
   4021                      81 _ink::
                             82 ;src/main.c:40: putchar (FS);
   4021 21 1C 00      [10]   83 	ld	hl, #0x001c
   4024 E5            [11]   84 	push	hl
   4025 CD 8E 43      [17]   85 	call	_putchar
   4028 F1            [10]   86 	pop	af
                             87 ;src/main.c:41: putchar (tinta); putchar (color1); putchar (color2);
   4029 21 02 00      [10]   88 	ld	hl, #2+0
   402C 39            [11]   89 	add	hl, sp
   402D 4E            [ 7]   90 	ld	c, (hl)
   402E 06 00         [ 7]   91 	ld	b, #0x00
   4030 C5            [11]   92 	push	bc
   4031 CD 8E 43      [17]   93 	call	_putchar
   4034 F1            [10]   94 	pop	af
   4035 21 03 00      [10]   95 	ld	hl, #3+0
   4038 39            [11]   96 	add	hl, sp
   4039 4E            [ 7]   97 	ld	c, (hl)
   403A 06 00         [ 7]   98 	ld	b, #0x00
   403C C5            [11]   99 	push	bc
   403D CD 8E 43      [17]  100 	call	_putchar
   4040 F1            [10]  101 	pop	af
   4041 21 04 00      [10]  102 	ld	hl, #4+0
   4044 39            [11]  103 	add	hl, sp
   4045 4E            [ 7]  104 	ld	c, (hl)
   4046 06 00         [ 7]  105 	ld	b, #0x00
   4048 C5            [11]  106 	push	bc
   4049 CD 8E 43      [17]  107 	call	_putchar
   404C F1            [10]  108 	pop	af
   404D C9            [10]  109 	ret
                            110 ;src/main.c:43: void border (u8 color1, u8 color2)
                            111 ;	---------------------------------
                            112 ; Function border
                            113 ; ---------------------------------
   404E                     114 _border::
                            115 ;src/main.c:45: putchar (GS);
   404E 21 1D 00      [10]  116 	ld	hl, #0x001d
   4051 E5            [11]  117 	push	hl
   4052 CD 8E 43      [17]  118 	call	_putchar
   4055 F1            [10]  119 	pop	af
                            120 ;src/main.c:46: putchar (color1); putchar (color2);
   4056 21 02 00      [10]  121 	ld	hl, #2+0
   4059 39            [11]  122 	add	hl, sp
   405A 4E            [ 7]  123 	ld	c, (hl)
   405B 06 00         [ 7]  124 	ld	b, #0x00
   405D C5            [11]  125 	push	bc
   405E CD 8E 43      [17]  126 	call	_putchar
   4061 F1            [10]  127 	pop	af
   4062 21 03 00      [10]  128 	ld	hl, #3+0
   4065 39            [11]  129 	add	hl, sp
   4066 4E            [ 7]  130 	ld	c, (hl)
   4067 06 00         [ 7]  131 	ld	b, #0x00
   4069 C5            [11]  132 	push	bc
   406A CD 8E 43      [17]  133 	call	_putchar
   406D F1            [10]  134 	pop	af
   406E C9            [10]  135 	ret
                            136 ;src/main.c:49: void paper (u8 color1)
                            137 ;	---------------------------------
                            138 ; Function paper
                            139 ; ---------------------------------
   406F                     140 _paper::
                            141 ;src/main.c:51: putchar (SO);
   406F 21 0E 00      [10]  142 	ld	hl, #0x000e
   4072 E5            [11]  143 	push	hl
   4073 CD 8E 43      [17]  144 	call	_putchar
   4076 F1            [10]  145 	pop	af
                            146 ;src/main.c:52: putchar (color1);
   4077 21 02 00      [10]  147 	ld	hl, #2+0
   407A 39            [11]  148 	add	hl, sp
   407B 4E            [ 7]  149 	ld	c, (hl)
   407C 06 00         [ 7]  150 	ld	b, #0x00
   407E C5            [11]  151 	push	bc
   407F CD 8E 43      [17]  152 	call	_putchar
   4082 F1            [10]  153 	pop	af
   4083 C9            [10]  154 	ret
                            155 ;src/main.c:54: void pen (u8 tinta)
                            156 ;	---------------------------------
                            157 ; Function pen
                            158 ; ---------------------------------
   4084                     159 _pen::
                            160 ;src/main.c:56: putchar (SI);
   4084 21 0F 00      [10]  161 	ld	hl, #0x000f
   4087 E5            [11]  162 	push	hl
   4088 CD 8E 43      [17]  163 	call	_putchar
   408B F1            [10]  164 	pop	af
                            165 ;src/main.c:57: putchar (tinta);
   408C 21 02 00      [10]  166 	ld	hl, #2+0
   408F 39            [11]  167 	add	hl, sp
   4090 4E            [ 7]  168 	ld	c, (hl)
   4091 06 00         [ 7]  169 	ld	b, #0x00
   4093 C5            [11]  170 	push	bc
   4094 CD 8E 43      [17]  171 	call	_putchar
   4097 F1            [10]  172 	pop	af
   4098 C9            [10]  173 	ret
                            174 ;src/main.c:60: void main(void) {
                            175 ;	---------------------------------
                            176 ; Function main
                            177 ; ---------------------------------
   4099                     178 _main::
                            179 ;src/main.c:61: ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
   4099 21 00 00      [10]  180 	ld	hl, #0x0000
   409C E5            [11]  181 	push	hl
   409D AF            [ 4]  182 	xor	a, a
   409E F5            [11]  183 	push	af
   409F 33            [ 6]  184 	inc	sp
   40A0 CD 21 40      [17]  185 	call	_ink
   40A3 33            [ 6]  186 	inc	sp
   40A4 21 00 00      [10]  187 	ld	hl,#0x0000
   40A7 E3            [19]  188 	ex	(sp),hl
   40A8 3E 01         [ 7]  189 	ld	a, #0x01
   40AA F5            [11]  190 	push	af
   40AB 33            [ 6]  191 	inc	sp
   40AC CD 21 40      [17]  192 	call	_ink
   40AF 33            [ 6]  193 	inc	sp
   40B0 21 00 00      [10]  194 	ld	hl,#0x0000
   40B3 E3            [19]  195 	ex	(sp),hl
   40B4 3E 02         [ 7]  196 	ld	a, #0x02
   40B6 F5            [11]  197 	push	af
   40B7 33            [ 6]  198 	inc	sp
   40B8 CD 21 40      [17]  199 	call	_ink
   40BB F1            [10]  200 	pop	af
   40BC 33            [ 6]  201 	inc	sp
                            202 ;src/main.c:62: cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
   40BD 2E 01         [ 7]  203 	ld	l, #0x01
   40BF CD 9C 43      [17]  204 	call	_cpct_setVideoMode
                            205 ;src/main.c:63: border (0,0); paper (0); pen (1);
   40C2 21 00 00      [10]  206 	ld	hl, #0x0000
   40C5 E5            [11]  207 	push	hl
   40C6 CD 4E 40      [17]  208 	call	_border
   40C9 F1            [10]  209 	pop	af
   40CA AF            [ 4]  210 	xor	a, a
   40CB F5            [11]  211 	push	af
   40CC 33            [ 6]  212 	inc	sp
   40CD CD 6F 40      [17]  213 	call	_paper
   40D0 33            [ 6]  214 	inc	sp
   40D1 3E 01         [ 7]  215 	ld	a, #0x01
   40D3 F5            [11]  216 	push	af
   40D4 33            [ 6]  217 	inc	sp
   40D5 CD 84 40      [17]  218 	call	_pen
   40D8 33            [ 6]  219 	inc	sp
                            220 ;src/main.c:65: locate (0,4);printf ("      )   ___    _____    )   ___      \n");
   40D9 21 00 04      [10]  221 	ld	hl, #0x0400
   40DC E5            [11]  222 	push	hl
   40DD CD 00 40      [17]  223 	call	_locate
   40E0 21 B6 41      [10]  224 	ld	hl, #___str_0
   40E3 E3            [19]  225 	ex	(sp),hl
   40E4 CD D7 43      [17]  226 	call	_printf
                            227 ;src/main.c:66: locate (0,5);printf ("     (__/_____) (, /   ) (__/_____)    \n");
   40E7 21 00 05      [10]  228 	ld	hl, #0x0500
   40EA E3            [19]  229 	ex	(sp),hl
   40EB CD 00 40      [17]  230 	call	_locate
   40EE 21 DF 41      [10]  231 	ld	hl, #___str_1
   40F1 E3            [19]  232 	ex	(sp),hl
   40F2 CD D7 43      [17]  233 	call	_printf
                            234 ;src/main.c:67: locate (0,6);printf ("       /         _/__ /    /           \n");
   40F5 21 00 06      [10]  235 	ld	hl, #0x0600
   40F8 E3            [19]  236 	ex	(sp),hl
   40F9 CD 00 40      [17]  237 	call	_locate
   40FC 21 08 42      [10]  238 	ld	hl, #___str_2
   40FF E3            [19]  239 	ex	(sp),hl
   4100 CD D7 43      [17]  240 	call	_printf
                            241 ;src/main.c:68: locate (0,7);printf ("      /          /        /            \n");
   4103 21 00 07      [10]  242 	ld	hl, #0x0700
   4106 E3            [19]  243 	ex	(sp),hl
   4107 CD 00 40      [17]  244 	call	_locate
   410A 21 31 42      [10]  245 	ld	hl, #___str_3
   410D E3            [19]  246 	ex	(sp),hl
   410E CD D7 43      [17]  247 	call	_printf
                            248 ;src/main.c:69: locate (0,8);printf ("     (______) ) /        (______)      \n");
   4111 21 00 08      [10]  249 	ld	hl, #0x0800
   4114 E3            [19]  250 	ex	(sp),hl
   4115 CD 00 40      [17]  251 	call	_locate
   4118 21 5A 42      [10]  252 	ld	hl, #___str_4
   411B E3            [19]  253 	ex	(sp),hl
   411C CD D7 43      [17]  254 	call	_printf
                            255 ;src/main.c:70: locate (0,9);printf ("            _(_/_                      \n");
   411F 21 00 09      [10]  256 	ld	hl, #0x0900
   4122 E3            [19]  257 	ex	(sp),hl
   4123 CD 00 40      [17]  258 	call	_locate
   4126 21 83 42      [10]  259 	ld	hl, #___str_5
   4129 E3            [19]  260 	ex	(sp),hl
   412A CD D7 43      [17]  261 	call	_printf
                            262 ;src/main.c:71: locate (0,10);printf ("           (, /   )                    \n");
   412D 21 00 0A      [10]  263 	ld	hl, #0x0a00
   4130 E3            [19]  264 	ex	(sp),hl
   4131 CD 00 40      [17]  265 	call	_locate
   4134 21 AC 42      [10]  266 	ld	hl, #___str_6
   4137 E3            [19]  267 	ex	(sp),hl
   4138 CD D7 43      [17]  268 	call	_printf
                            269 ;src/main.c:72: locate (0,11);printf ("             /__ / ___      _          \n");
   413B 21 00 0B      [10]  270 	ld	hl, #0x0b00
   413E E3            [19]  271 	ex	(sp),hl
   413F CD 00 40      [17]  272 	call	_locate
   4142 21 D5 42      [10]  273 	ld	hl, #___str_7
   4145 E3            [19]  274 	ex	(sp),hl
   4146 CD D7 43      [17]  275 	call	_printf
                            276 ;src/main.c:75: locate (0,12);printf ("          ) /   \\_(_(_/(_(_(/_         \n");
   4149 21 00 0C      [10]  277 	ld	hl, #0x0c00
   414C E3            [19]  278 	ex	(sp),hl
   414D CD 00 40      [17]  279 	call	_locate
   4150 21 FE 42      [10]  280 	ld	hl, #___str_8
   4153 E3            [19]  281 	ex	(sp),hl
   4154 CD D7 43      [17]  282 	call	_printf
                            283 ;src/main.c:76: locate (0,13);printf ("         (_/       .-/                 \n");
   4157 21 00 0D      [10]  284 	ld	hl, #0x0d00
   415A E3            [19]  285 	ex	(sp),hl
   415B CD 00 40      [17]  286 	call	_locate
   415E 21 27 43      [10]  287 	ld	hl, #___str_9
   4161 E3            [19]  288 	ex	(sp),hl
   4162 CD D7 43      [17]  289 	call	_printf
                            290 ;src/main.c:77: locate (0,14);printf ("                  (_/                  \n");
   4165 21 00 0E      [10]  291 	ld	hl, #0x0e00
   4168 E3            [19]  292 	ex	(sp),hl
   4169 CD 00 40      [17]  293 	call	_locate
   416C 21 50 43      [10]  294 	ld	hl, #___str_10
   416F E3            [19]  295 	ex	(sp),hl
   4170 CD D7 43      [17]  296 	call	_printf
                            297 ;src/main.c:78: locate (10, 18); pen (2); printf ("PRESS ENTER TO START");
   4173 21 0A 12      [10]  298 	ld	hl, #0x120a
   4176 E3            [19]  299 	ex	(sp),hl
   4177 CD 00 40      [17]  300 	call	_locate
   417A 26 02         [ 7]  301 	ld	h,#0x02
   417C E3            [19]  302 	ex	(sp),hl
   417D 33            [ 6]  303 	inc	sp
   417E CD 84 40      [17]  304 	call	_pen
   4181 33            [ 6]  305 	inc	sp
   4182 21 79 43      [10]  306 	ld	hl, #___str_11
   4185 E5            [11]  307 	push	hl
   4186 CD D7 43      [17]  308 	call	_printf
                            309 ;src/main.c:79: ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);
   4189 21 03 03      [10]  310 	ld	hl, #0x0303
   418C E3            [19]  311 	ex	(sp),hl
   418D AF            [ 4]  312 	xor	a, a
   418E F5            [11]  313 	push	af
   418F 33            [ 6]  314 	inc	sp
   4190 CD 21 40      [17]  315 	call	_ink
   4193 33            [ 6]  316 	inc	sp
   4194 21 06 0F      [10]  317 	ld	hl,#0x0f06
   4197 E3            [19]  318 	ex	(sp),hl
   4198 3E 01         [ 7]  319 	ld	a, #0x01
   419A F5            [11]  320 	push	af
   419B 33            [ 6]  321 	inc	sp
   419C CD 21 40      [17]  322 	call	_ink
   419F 33            [ 6]  323 	inc	sp
   41A0 21 10 10      [10]  324 	ld	hl,#0x1010
   41A3 E3            [19]  325 	ex	(sp),hl
   41A4 3E 02         [ 7]  326 	ld	a, #0x02
   41A6 F5            [11]  327 	push	af
   41A7 33            [ 6]  328 	inc	sp
   41A8 CD 21 40      [17]  329 	call	_ink
   41AB 33            [ 6]  330 	inc	sp
   41AC 21 03 03      [10]  331 	ld	hl,#0x0303
   41AF E3            [19]  332 	ex	(sp),hl
   41B0 CD 4E 40      [17]  333 	call	_border
   41B3 F1            [10]  334 	pop	af
                            335 ;src/main.c:82: while (1);
   41B4                     336 00102$:
   41B4 18 FE         [12]  337 	jr	00102$
   41B6                     338 ___str_0:
   41B6 20 20 20 20 20 20   339 	.ascii "      )   ___    _____    )   ___      "
        29 20 20 20 5F 5F
        5F 20 20 20 20 5F
        5F 5F 5F 5F 20 20
        20 20 29 20 20 20
        5F 5F 5F 20 20 20
        20 20 20
   41DD 0A                  340 	.db 0x0a
   41DE 00                  341 	.db 0x00
   41DF                     342 ___str_1:
   41DF 20 20 20 20 20 28   343 	.ascii "     (__/_____) (, /   ) (__/_____)    "
        5F 5F 2F 5F 5F 5F
        5F 5F 29 20 28 2C
        20 2F 20 20 20 29
        20 28 5F 5F 2F 5F
        5F 5F 5F 5F 29 20
        20 20 20
   4206 0A                  344 	.db 0x0a
   4207 00                  345 	.db 0x00
   4208                     346 ___str_2:
   4208 20 20 20 20 20 20   347 	.ascii "       /         _/__ /    /           "
        20 2F 20 20 20 20
        20 20 20 20 20 5F
        2F 5F 5F 20 2F 20
        20 20 20 2F 20 20
        20 20 20 20 20 20
        20 20 20
   422F 0A                  348 	.db 0x0a
   4230 00                  349 	.db 0x00
   4231                     350 ___str_3:
   4231 20 20 20 20 20 20   351 	.ascii "      /          /        /            "
        2F 20 20 20 20 20
        20 20 20 20 20 2F
        20 20 20 20 20 20
        20 20 2F 20 20 20
        20 20 20 20 20 20
        20 20 20
   4258 0A                  352 	.db 0x0a
   4259 00                  353 	.db 0x00
   425A                     354 ___str_4:
   425A 20 20 20 20 20 28   355 	.ascii "     (______) ) /        (______)      "
        5F 5F 5F 5F 5F 5F
        29 20 29 20 2F 20
        20 20 20 20 20 20
        20 28 5F 5F 5F 5F
        5F 5F 29 20 20 20
        20 20 20
   4281 0A                  356 	.db 0x0a
   4282 00                  357 	.db 0x00
   4283                     358 ___str_5:
   4283 20 20 20 20 20 20   359 	.ascii "            _(_/_                      "
        20 20 20 20 20 20
        5F 28 5F 2F 5F 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   42AA 0A                  360 	.db 0x0a
   42AB 00                  361 	.db 0x00
   42AC                     362 ___str_6:
   42AC 20 20 20 20 20 20   363 	.ascii "           (, /   )                    "
        20 20 20 20 20 28
        2C 20 2F 20 20 20
        29 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   42D3 0A                  364 	.db 0x0a
   42D4 00                  365 	.db 0x00
   42D5                     366 ___str_7:
   42D5 20 20 20 20 20 20   367 	.ascii "             /__ / ___      _          "
        20 20 20 20 20 20
        20 2F 5F 5F 20 2F
        20 5F 5F 5F 20 20
        20 20 20 20 5F 20
        20 20 20 20 20 20
        20 20 20
   42FC 0A                  368 	.db 0x0a
   42FD 00                  369 	.db 0x00
   42FE                     370 ___str_8:
   42FE 20 20 20 20 20 20   371 	.ascii "          ) /   "
        20 20 20 20 29 20
        2F 20 20 20
   430E 5C                  372 	.db 0x5c
   430F 5F 28 5F 28 5F 2F   373 	.ascii "_(_(_/(_(_(/_         "
        28 5F 28 5F 28 2F
        5F 20 20 20 20 20
        20 20 20 20
   4325 0A                  374 	.db 0x0a
   4326 00                  375 	.db 0x00
   4327                     376 ___str_9:
   4327 20 20 20 20 20 20   377 	.ascii "         (_/       .-/                 "
        20 20 20 28 5F 2F
        20 20 20 20 20 20
        20 2E 2D 2F 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   434E 0A                  378 	.db 0x0a
   434F 00                  379 	.db 0x00
   4350                     380 ___str_10:
   4350 20 20 20 20 20 20   381 	.ascii "                  (_/                  "
        20 20 20 20 20 20
        20 20 20 20 20 20
        28 5F 2F 20 20 20
        20 20 20 20 20 20
        20 20 20 20 20 20
        20 20 20
   4377 0A                  382 	.db 0x0a
   4378 00                  383 	.db 0x00
   4379                     384 ___str_11:
   4379 50 52 45 53 53 20   385 	.ascii "PRESS ENTER TO START"
        45 4E 54 45 52 20
        54 4F 20 53 54 41
        52 54
   438D 00                  386 	.db 0x00
                            387 	.area _CODE
                            388 	.area _INITIALIZER
                            389 	.area _CABS (ABS)
