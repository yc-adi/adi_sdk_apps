
register_test_1_1.elf:     file format elf32-littlearm


Disassembly of section .text:

00000000 <__Vectors>:
       0:	00 00 0c 00 65 09 00 00 2f 0a 00 00 29 0a 00 00     ....e.../...)...
      10:	2f 0a 00 00 2f 0a 00 00 2f 0a 00 00 2f 0a 00 00     /.../.../.../...
	...
      2c:	2f 0a 00 00 2f 0a 00 00 00 00 00 00 2f 0a 00 00     /.../......./...
      3c:	2f 0a 00 00 2f 0a 00 00 2f 0a 00 00 2f 0a 00 00     /.../.../.../...
      4c:	2f 0a 00 00 2f 0a 00 00 2f 0a 00 00 2f 0a 00 00     /.../.../.../...
      5c:	2f 0a 00 00 2f 0a 00 00 2f 0a 00 00 00 00 00 00     /.../.../.......
	...

000007c0 <deregister_tm_clones>:
     7c0:	4803      	ldr	r0, [pc, #12]	; (7d0 <deregister_tm_clones+0x10>)
     7c2:	4b04      	ldr	r3, [pc, #16]	; (7d4 <deregister_tm_clones+0x14>)
     7c4:	4283      	cmp	r3, r0
     7c6:	d002      	beq.n	7ce <deregister_tm_clones+0xe>
     7c8:	4b03      	ldr	r3, [pc, #12]	; (7d8 <deregister_tm_clones+0x18>)
     7ca:	b103      	cbz	r3, 7ce <deregister_tm_clones+0xe>
     7cc:	4718      	bx	r3
     7ce:	4770      	bx	lr
     7d0:	000a0190 	.word	0x000a0190
     7d4:	000a0190 	.word	0x000a0190
     7d8:	00000000 	.word	0x00000000

000007dc <register_tm_clones>:
     7dc:	4b06      	ldr	r3, [pc, #24]	; (7f8 <register_tm_clones+0x1c>)
     7de:	4907      	ldr	r1, [pc, #28]	; (7fc <register_tm_clones+0x20>)
     7e0:	1ac9      	subs	r1, r1, r3
     7e2:	1089      	asrs	r1, r1, #2
     7e4:	bf48      	it	mi
     7e6:	3101      	addmi	r1, #1
     7e8:	1049      	asrs	r1, r1, #1
     7ea:	d003      	beq.n	7f4 <register_tm_clones+0x18>
     7ec:	4b04      	ldr	r3, [pc, #16]	; (800 <register_tm_clones+0x24>)
     7ee:	b10b      	cbz	r3, 7f4 <register_tm_clones+0x18>
     7f0:	4801      	ldr	r0, [pc, #4]	; (7f8 <register_tm_clones+0x1c>)
     7f2:	4718      	bx	r3
     7f4:	4770      	bx	lr
     7f6:	bf00      	nop
     7f8:	000a0190 	.word	0x000a0190
     7fc:	000a0190 	.word	0x000a0190
     800:	00000000 	.word	0x00000000

00000804 <__do_global_dtors_aux>:
     804:	b510      	push	{r4, lr}
     806:	4c06      	ldr	r4, [pc, #24]	; (820 <__do_global_dtors_aux+0x1c>)
     808:	7823      	ldrb	r3, [r4, #0]
     80a:	b943      	cbnz	r3, 81e <__do_global_dtors_aux+0x1a>
     80c:	f7ff ffd8 	bl	7c0 <deregister_tm_clones>
     810:	4b04      	ldr	r3, [pc, #16]	; (824 <__do_global_dtors_aux+0x20>)
     812:	b113      	cbz	r3, 81a <__do_global_dtors_aux+0x16>
     814:	4804      	ldr	r0, [pc, #16]	; (828 <__do_global_dtors_aux+0x24>)
     816:	f3af 8000 	nop.w
     81a:	2301      	movs	r3, #1
     81c:	7023      	strb	r3, [r4, #0]
     81e:	bd10      	pop	{r4, pc}
     820:	000a0190 	.word	0x000a0190
     824:	00000000 	.word	0x00000000
     828:	00001ab8 	.word	0x00001ab8

0000082c <frame_dummy>:
     82c:	b508      	push	{r3, lr}
     82e:	4b05      	ldr	r3, [pc, #20]	; (844 <frame_dummy+0x18>)
     830:	b11b      	cbz	r3, 83a <frame_dummy+0xe>
     832:	4905      	ldr	r1, [pc, #20]	; (848 <frame_dummy+0x1c>)
     834:	4805      	ldr	r0, [pc, #20]	; (84c <frame_dummy+0x20>)
     836:	f3af 8000 	nop.w
     83a:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
     83e:	f7ff bfcd 	b.w	7dc <register_tm_clones>
     842:	bf00      	nop
     844:	00000000 	.word	0x00000000
     848:	000a0194 	.word	0x000a0194
     84c:	00001ab8 	.word	0x00001ab8

00000850 <_stack_init>:
     850:	2a00      	cmp	r2, #0
     852:	d001      	beq.n	858 <_stack_init+0x8>
     854:	f502 7a80 	add.w	sl, r2, #256	; 0x100
     858:	4770      	bx	lr
     85a:	bf00      	nop

0000085c <_mainCRTStartup>:
     85c:	2016      	movs	r0, #22
     85e:	a131      	add	r1, pc, #196	; (adr r1, 924 <_mainCRTStartup+0xc8>)
     860:	beab      	bkpt	0x00ab
     862:	4830      	ldr	r0, [pc, #192]	; (924 <_mainCRTStartup+0xc8>)
     864:	6841      	ldr	r1, [r0, #4]
     866:	2900      	cmp	r1, #0
     868:	d001      	beq.n	86e <_mainCRTStartup+0x12>
     86a:	4a36      	ldr	r2, [pc, #216]	; (944 <_mainCRTStartup+0xe8>)
     86c:	6011      	str	r1, [r2, #0]
     86e:	6801      	ldr	r1, [r0, #0]
     870:	2900      	cmp	r1, #0
     872:	d101      	bne.n	878 <_mainCRTStartup+0x1c>
     874:	4932      	ldr	r1, [pc, #200]	; (940 <_mainCRTStartup+0xe4>)
     876:	6001      	str	r1, [r0, #0]
     878:	6881      	ldr	r1, [r0, #8]
     87a:	68c2      	ldr	r2, [r0, #12]
     87c:	4b2a      	ldr	r3, [pc, #168]	; (928 <_mainCRTStartup+0xcc>)
     87e:	2900      	cmp	r1, #0
     880:	d000      	beq.n	884 <_mainCRTStartup+0x28>
     882:	460b      	mov	r3, r1
     884:	469d      	mov	sp, r3
     886:	f7ff ffe3 	bl	850 <_stack_init>
     88a:	2100      	movs	r1, #0
     88c:	468b      	mov	fp, r1
     88e:	460f      	mov	r7, r1
     890:	4826      	ldr	r0, [pc, #152]	; (92c <_mainCRTStartup+0xd0>)
     892:	4a27      	ldr	r2, [pc, #156]	; (930 <_mainCRTStartup+0xd4>)
     894:	1a12      	subs	r2, r2, r0
     896:	f000 f92f 	bl	af8 <memset>
     89a:	f000 ffbd 	bl	1818 <initialise_monitor_handles>
     89e:	2015      	movs	r0, #21
     8a0:	4926      	ldr	r1, [pc, #152]	; (93c <_mainCRTStartup+0xe0>)
     8a2:	beab      	bkpt	0x00ab
     8a4:	4925      	ldr	r1, [pc, #148]	; (93c <_mainCRTStartup+0xe0>)
     8a6:	6809      	ldr	r1, [r1, #0]
     8a8:	2000      	movs	r0, #0
     8aa:	b401      	push	{r0}
     8ac:	780b      	ldrb	r3, [r1, #0]
     8ae:	3101      	adds	r1, #1
     8b0:	2b00      	cmp	r3, #0
     8b2:	d015      	beq.n	8e0 <_mainCRTStartup+0x84>
     8b4:	2b20      	cmp	r3, #32
     8b6:	d0f9      	beq.n	8ac <_mainCRTStartup+0x50>
     8b8:	2b22      	cmp	r3, #34	; 0x22
     8ba:	d001      	beq.n	8c0 <_mainCRTStartup+0x64>
     8bc:	2b27      	cmp	r3, #39	; 0x27
     8be:	d101      	bne.n	8c4 <_mainCRTStartup+0x68>
     8c0:	001a      	movs	r2, r3
     8c2:	e001      	b.n	8c8 <_mainCRTStartup+0x6c>
     8c4:	2220      	movs	r2, #32
     8c6:	3901      	subs	r1, #1
     8c8:	b402      	push	{r1}
     8ca:	3001      	adds	r0, #1
     8cc:	780b      	ldrb	r3, [r1, #0]
     8ce:	3101      	adds	r1, #1
     8d0:	2b00      	cmp	r3, #0
     8d2:	d005      	beq.n	8e0 <_mainCRTStartup+0x84>
     8d4:	429a      	cmp	r2, r3
     8d6:	d1f9      	bne.n	8cc <_mainCRTStartup+0x70>
     8d8:	2200      	movs	r2, #0
     8da:	1e4b      	subs	r3, r1, #1
     8dc:	701a      	strb	r2, [r3, #0]
     8de:	e7e5      	b.n	8ac <_mainCRTStartup+0x50>
     8e0:	4669      	mov	r1, sp
     8e2:	0002      	movs	r2, r0
     8e4:	0092      	lsls	r2, r2, #2
     8e6:	446a      	add	r2, sp
     8e8:	466b      	mov	r3, sp
     8ea:	429a      	cmp	r2, r3
     8ec:	d906      	bls.n	8fc <_mainCRTStartup+0xa0>
     8ee:	3a04      	subs	r2, #4
     8f0:	6814      	ldr	r4, [r2, #0]
     8f2:	681d      	ldr	r5, [r3, #0]
     8f4:	6015      	str	r5, [r2, #0]
     8f6:	601c      	str	r4, [r3, #0]
     8f8:	3304      	adds	r3, #4
     8fa:	e7f6      	b.n	8ea <_mainCRTStartup+0x8e>
     8fc:	466c      	mov	r4, sp
     8fe:	2507      	movs	r5, #7
     900:	43ac      	bics	r4, r5
     902:	46a5      	mov	sp, r4
     904:	0004      	movs	r4, r0
     906:	000d      	movs	r5, r1
     908:	480a      	ldr	r0, [pc, #40]	; (934 <_mainCRTStartup+0xd8>)
     90a:	2800      	cmp	r0, #0
     90c:	d002      	beq.n	914 <_mainCRTStartup+0xb8>
     90e:	480a      	ldr	r0, [pc, #40]	; (938 <_mainCRTStartup+0xdc>)
     910:	f3af 8000 	nop.w
     914:	f000 f8cc 	bl	ab0 <__libc_init_array>
     918:	0020      	movs	r0, r4
     91a:	0029      	movs	r1, r5
     91c:	f000 f814 	bl	948 <main>
     920:	f000 f8b4 	bl	a8c <exit>
     924:	000a0000 	.word	0x000a0000
     928:	000c0000 	.word	0x000c0000
     92c:	000a0190 	.word	0x000a0190
     930:	000a03ac 	.word	0x000a03ac
	...
     93c:	000a0110 	.word	0x000a0110
     940:	000a03b0 	.word	0x000a03b0
     944:	000a017c 	.word	0x000a017c

00000948 <main>:
     948:	b480      	push	{r7}
     94a:	b083      	sub	sp, #12
     94c:	af00      	add	r7, sp, #0
     94e:	4b04      	ldr	r3, [pc, #16]	; (960 <main+0x18>)
     950:	f04f 3255 	mov.w	r2, #1431655765	; 0x55555555
     954:	601a      	str	r2, [r3, #0]
     956:	4b02      	ldr	r3, [pc, #8]	; (960 <main+0x18>)
     958:	681b      	ldr	r3, [r3, #0]
     95a:	607b      	str	r3, [r7, #4]
     95c:	e7fe      	b.n	95c <main+0x14>
     95e:	bf00      	nop
     960:	000bffe4 	.word	0x000bffe4

00000964 <Reset_Handler>:
     964:	b580      	push	{r7, lr}
     966:	b088      	sub	sp, #32
     968:	af00      	add	r7, sp, #0
     96a:	4b29      	ldr	r3, [pc, #164]	; (a10 <Reset_Handler+0xac>)
     96c:	607b      	str	r3, [r7, #4]
     96e:	687b      	ldr	r3, [r7, #4]
     970:	f383 8809 	msr	PSP, r3
     974:	bf00      	nop
     976:	4b27      	ldr	r3, [pc, #156]	; (a14 <Reset_Handler+0xb0>)
     978:	60bb      	str	r3, [r7, #8]
     97a:	68bb      	ldr	r3, [r7, #8]
     97c:	f383 880a 	msr	MSPLIM, r3
     980:	bf00      	nop
     982:	4b24      	ldr	r3, [pc, #144]	; (a14 <Reset_Handler+0xb0>)
     984:	60fb      	str	r3, [r7, #12]
     986:	68fb      	ldr	r3, [r7, #12]
     988:	f383 880b 	msr	PSPLIM, r3
     98c:	bf00      	nop
     98e:	f000 f85f 	bl	a50 <SystemInit>
     992:	4b21      	ldr	r3, [pc, #132]	; (a18 <Reset_Handler+0xb4>)
     994:	61fb      	str	r3, [r7, #28]
     996:	e019      	b.n	9cc <Reset_Handler+0x68>
     998:	2300      	movs	r3, #0
     99a:	61bb      	str	r3, [r7, #24]
     99c:	e00e      	b.n	9bc <Reset_Handler+0x58>
     99e:	69fb      	ldr	r3, [r7, #28]
     9a0:	681a      	ldr	r2, [r3, #0]
     9a2:	69bb      	ldr	r3, [r7, #24]
     9a4:	009b      	lsls	r3, r3, #2
     9a6:	441a      	add	r2, r3
     9a8:	69fb      	ldr	r3, [r7, #28]
     9aa:	6859      	ldr	r1, [r3, #4]
     9ac:	69bb      	ldr	r3, [r7, #24]
     9ae:	009b      	lsls	r3, r3, #2
     9b0:	440b      	add	r3, r1
     9b2:	6812      	ldr	r2, [r2, #0]
     9b4:	601a      	str	r2, [r3, #0]
     9b6:	69bb      	ldr	r3, [r7, #24]
     9b8:	3301      	adds	r3, #1
     9ba:	61bb      	str	r3, [r7, #24]
     9bc:	69fb      	ldr	r3, [r7, #28]
     9be:	689b      	ldr	r3, [r3, #8]
     9c0:	69ba      	ldr	r2, [r7, #24]
     9c2:	429a      	cmp	r2, r3
     9c4:	d3eb      	bcc.n	99e <Reset_Handler+0x3a>
     9c6:	69fb      	ldr	r3, [r7, #28]
     9c8:	330c      	adds	r3, #12
     9ca:	61fb      	str	r3, [r7, #28]
     9cc:	69fb      	ldr	r3, [r7, #28]
     9ce:	4a13      	ldr	r2, [pc, #76]	; (a1c <Reset_Handler+0xb8>)
     9d0:	4293      	cmp	r3, r2
     9d2:	d3e1      	bcc.n	998 <Reset_Handler+0x34>
     9d4:	4b12      	ldr	r3, [pc, #72]	; (a20 <Reset_Handler+0xbc>)
     9d6:	617b      	str	r3, [r7, #20]
     9d8:	e014      	b.n	a04 <Reset_Handler+0xa0>
     9da:	2300      	movs	r3, #0
     9dc:	613b      	str	r3, [r7, #16]
     9de:	e009      	b.n	9f4 <Reset_Handler+0x90>
     9e0:	697b      	ldr	r3, [r7, #20]
     9e2:	681a      	ldr	r2, [r3, #0]
     9e4:	693b      	ldr	r3, [r7, #16]
     9e6:	009b      	lsls	r3, r3, #2
     9e8:	4413      	add	r3, r2
     9ea:	2200      	movs	r2, #0
     9ec:	601a      	str	r2, [r3, #0]
     9ee:	693b      	ldr	r3, [r7, #16]
     9f0:	3301      	adds	r3, #1
     9f2:	613b      	str	r3, [r7, #16]
     9f4:	697b      	ldr	r3, [r7, #20]
     9f6:	685b      	ldr	r3, [r3, #4]
     9f8:	693a      	ldr	r2, [r7, #16]
     9fa:	429a      	cmp	r2, r3
     9fc:	d3f0      	bcc.n	9e0 <Reset_Handler+0x7c>
     9fe:	697b      	ldr	r3, [r7, #20]
     a00:	3308      	adds	r3, #8
     a02:	617b      	str	r3, [r7, #20]
     a04:	697b      	ldr	r3, [r7, #20]
     a06:	4a07      	ldr	r2, [pc, #28]	; (a24 <Reset_Handler+0xc0>)
     a08:	4293      	cmp	r3, r2
     a0a:	d3e6      	bcc.n	9da <Reset_Handler+0x76>
     a0c:	f7ff ff26 	bl	85c <_mainCRTStartup>
     a10:	000c0000 	.word	0x000c0000
     a14:	000bfc00 	.word	0x000bfc00
     a18:	00001a28 	.word	0x00001a28
     a1c:	00001a34 	.word	0x00001a34
     a20:	00001a34 	.word	0x00001a34
     a24:	00001a3c 	.word	0x00001a3c

00000a28 <HardFault_Handler>:
     a28:	b480      	push	{r7}
     a2a:	af00      	add	r7, sp, #0
     a2c:	e7fe      	b.n	a2c <HardFault_Handler+0x4>

00000a2e <Default_Handler>:
     a2e:	b480      	push	{r7}
     a30:	af00      	add	r7, sp, #0
     a32:	e7fe      	b.n	a32 <Default_Handler+0x4>

00000a34 <SystemCoreClockUpdate>:
     a34:	b480      	push	{r7}
     a36:	af00      	add	r7, sp, #0
     a38:	4b03      	ldr	r3, [pc, #12]	; (a48 <SystemCoreClockUpdate+0x14>)
     a3a:	4a04      	ldr	r2, [pc, #16]	; (a4c <SystemCoreClockUpdate+0x18>)
     a3c:	601a      	str	r2, [r3, #0]
     a3e:	bf00      	nop
     a40:	46bd      	mov	sp, r7
     a42:	f85d 7b04 	ldr.w	r7, [sp], #4
     a46:	4770      	bx	lr
     a48:	000a0118 	.word	0x000a0118
     a4c:	017d7840 	.word	0x017d7840

00000a50 <SystemInit>:
     a50:	b480      	push	{r7}
     a52:	af00      	add	r7, sp, #0
     a54:	4b09      	ldr	r3, [pc, #36]	; (a7c <SystemInit+0x2c>)
     a56:	4a0a      	ldr	r2, [pc, #40]	; (a80 <SystemInit+0x30>)
     a58:	609a      	str	r2, [r3, #8]
     a5a:	4b08      	ldr	r3, [pc, #32]	; (a7c <SystemInit+0x2c>)
     a5c:	f8d3 3088 	ldr.w	r3, [r3, #136]	; 0x88
     a60:	4a06      	ldr	r2, [pc, #24]	; (a7c <SystemInit+0x2c>)
     a62:	f443 0370 	orr.w	r3, r3, #15728640	; 0xf00000
     a66:	f8c2 3088 	str.w	r3, [r2, #136]	; 0x88
     a6a:	4b06      	ldr	r3, [pc, #24]	; (a84 <SystemInit+0x34>)
     a6c:	4a06      	ldr	r2, [pc, #24]	; (a88 <SystemInit+0x38>)
     a6e:	601a      	str	r2, [r3, #0]
     a70:	bf00      	nop
     a72:	46bd      	mov	sp, r7
     a74:	f85d 7b04 	ldr.w	r7, [sp], #4
     a78:	4770      	bx	lr
     a7a:	bf00      	nop
     a7c:	e000ed00 	.word	0xe000ed00
     a80:	00000000 	.word	0x00000000
     a84:	000a0118 	.word	0x000a0118
     a88:	017d7840 	.word	0x017d7840

00000a8c <exit>:
     a8c:	b508      	push	{r3, lr}
     a8e:	4b06      	ldr	r3, [pc, #24]	; (aa8 <exit+0x1c>)
     a90:	4604      	mov	r4, r0
     a92:	b113      	cbz	r3, a9a <exit+0xe>
     a94:	2100      	movs	r1, #0
     a96:	f3af 8000 	nop.w
     a9a:	4b04      	ldr	r3, [pc, #16]	; (aac <exit+0x20>)
     a9c:	681b      	ldr	r3, [r3, #0]
     a9e:	b103      	cbz	r3, aa2 <exit+0x16>
     aa0:	4798      	blx	r3
     aa2:	4620      	mov	r0, r4
     aa4:	f000 fc36 	bl	1314 <_exit>
     aa8:	00000000 	.word	0x00000000
     aac:	000a02e4 	.word	0x000a02e4

00000ab0 <__libc_init_array>:
     ab0:	b570      	push	{r4, r5, r6, lr}
     ab2:	4d0d      	ldr	r5, [pc, #52]	; (ae8 <__libc_init_array+0x38>)
     ab4:	2600      	movs	r6, #0
     ab6:	4c0d      	ldr	r4, [pc, #52]	; (aec <__libc_init_array+0x3c>)
     ab8:	1b64      	subs	r4, r4, r5
     aba:	10a4      	asrs	r4, r4, #2
     abc:	42a6      	cmp	r6, r4
     abe:	d109      	bne.n	ad4 <__libc_init_array+0x24>
     ac0:	4d0b      	ldr	r5, [pc, #44]	; (af0 <__libc_init_array+0x40>)
     ac2:	2600      	movs	r6, #0
     ac4:	4c0b      	ldr	r4, [pc, #44]	; (af4 <__libc_init_array+0x44>)
     ac6:	f000 ffb9 	bl	1a3c <_init>
     aca:	1b64      	subs	r4, r4, r5
     acc:	10a4      	asrs	r4, r4, #2
     ace:	42a6      	cmp	r6, r4
     ad0:	d105      	bne.n	ade <__libc_init_array+0x2e>
     ad2:	bd70      	pop	{r4, r5, r6, pc}
     ad4:	f855 3b04 	ldr.w	r3, [r5], #4
     ad8:	3601      	adds	r6, #1
     ada:	4798      	blx	r3
     adc:	e7ee      	b.n	abc <__libc_init_array+0xc>
     ade:	f855 3b04 	ldr.w	r3, [r5], #4
     ae2:	3601      	adds	r6, #1
     ae4:	4798      	blx	r3
     ae6:	e7f2      	b.n	ace <__libc_init_array+0x1e>
     ae8:	000a0188 	.word	0x000a0188
     aec:	000a0188 	.word	0x000a0188
     af0:	000a0188 	.word	0x000a0188
     af4:	000a018c 	.word	0x000a018c

00000af8 <memset>:
     af8:	4402      	add	r2, r0
     afa:	4603      	mov	r3, r0
     afc:	4293      	cmp	r3, r2
     afe:	d100      	bne.n	b02 <memset+0xa>
     b00:	4770      	bx	lr
     b02:	f803 1b01 	strb.w	r1, [r3], #1
     b06:	e7f9      	b.n	afc <memset+0x4>

00000b08 <std>:
     b08:	2300      	movs	r3, #0
     b0a:	b510      	push	{r4, lr}
     b0c:	4604      	mov	r4, r0
     b0e:	6083      	str	r3, [r0, #8]
     b10:	8181      	strh	r1, [r0, #12]
     b12:	4619      	mov	r1, r3
     b14:	6643      	str	r3, [r0, #100]	; 0x64
     b16:	81c2      	strh	r2, [r0, #14]
     b18:	2208      	movs	r2, #8
     b1a:	6183      	str	r3, [r0, #24]
     b1c:	e9c0 3300 	strd	r3, r3, [r0]
     b20:	e9c0 3304 	strd	r3, r3, [r0, #16]
     b24:	305c      	adds	r0, #92	; 0x5c
     b26:	f7ff ffe7 	bl	af8 <memset>
     b2a:	4b0d      	ldr	r3, [pc, #52]	; (b60 <std+0x58>)
     b2c:	6224      	str	r4, [r4, #32]
     b2e:	6263      	str	r3, [r4, #36]	; 0x24
     b30:	4b0c      	ldr	r3, [pc, #48]	; (b64 <std+0x5c>)
     b32:	62a3      	str	r3, [r4, #40]	; 0x28
     b34:	4b0c      	ldr	r3, [pc, #48]	; (b68 <std+0x60>)
     b36:	62e3      	str	r3, [r4, #44]	; 0x2c
     b38:	4b0c      	ldr	r3, [pc, #48]	; (b6c <std+0x64>)
     b3a:	6323      	str	r3, [r4, #48]	; 0x30
     b3c:	4b0c      	ldr	r3, [pc, #48]	; (b70 <std+0x68>)
     b3e:	429c      	cmp	r4, r3
     b40:	d006      	beq.n	b50 <std+0x48>
     b42:	f103 0268 	add.w	r2, r3, #104	; 0x68
     b46:	4294      	cmp	r4, r2
     b48:	d002      	beq.n	b50 <std+0x48>
     b4a:	33d0      	adds	r3, #208	; 0xd0
     b4c:	429c      	cmp	r4, r3
     b4e:	d105      	bne.n	b5c <std+0x54>
     b50:	f104 0058 	add.w	r0, r4, #88	; 0x58
     b54:	e8bd 4010 	ldmia.w	sp!, {r4, lr}
     b58:	f000 b99b 	b.w	e92 <__retarget_lock_init_recursive>
     b5c:	bd10      	pop	{r4, pc}
     b5e:	bf00      	nop
     b60:	00000d5d 	.word	0x00000d5d
     b64:	00000d83 	.word	0x00000d83
     b68:	00000dbb 	.word	0x00000dbb
     b6c:	00000ddf 	.word	0x00000ddf
     b70:	000a01ac 	.word	0x000a01ac

00000b74 <stdio_exit_handler>:
     b74:	4a02      	ldr	r2, [pc, #8]	; (b80 <stdio_exit_handler+0xc>)
     b76:	4903      	ldr	r1, [pc, #12]	; (b84 <stdio_exit_handler+0x10>)
     b78:	4803      	ldr	r0, [pc, #12]	; (b88 <stdio_exit_handler+0x14>)
     b7a:	f000 b959 	b.w	e30 <_fwalk_sglue>
     b7e:	bf00      	nop
     b80:	000a0120 	.word	0x000a0120
     b84:	00000fb1 	.word	0x00000fb1
     b88:	000a0130 	.word	0x000a0130

00000b8c <cleanup_stdio>:
     b8c:	6841      	ldr	r1, [r0, #4]
     b8e:	4b0c      	ldr	r3, [pc, #48]	; (bc0 <cleanup_stdio+0x34>)
     b90:	4299      	cmp	r1, r3
     b92:	b510      	push	{r4, lr}
     b94:	4604      	mov	r4, r0
     b96:	d001      	beq.n	b9c <cleanup_stdio+0x10>
     b98:	f000 fa0a 	bl	fb0 <_fflush_r>
     b9c:	68a1      	ldr	r1, [r4, #8]
     b9e:	4b09      	ldr	r3, [pc, #36]	; (bc4 <cleanup_stdio+0x38>)
     ba0:	4299      	cmp	r1, r3
     ba2:	d002      	beq.n	baa <cleanup_stdio+0x1e>
     ba4:	4620      	mov	r0, r4
     ba6:	f000 fa03 	bl	fb0 <_fflush_r>
     baa:	68e1      	ldr	r1, [r4, #12]
     bac:	4b06      	ldr	r3, [pc, #24]	; (bc8 <cleanup_stdio+0x3c>)
     bae:	4299      	cmp	r1, r3
     bb0:	d004      	beq.n	bbc <cleanup_stdio+0x30>
     bb2:	4620      	mov	r0, r4
     bb4:	e8bd 4010 	ldmia.w	sp!, {r4, lr}
     bb8:	f000 b9fa 	b.w	fb0 <_fflush_r>
     bbc:	bd10      	pop	{r4, pc}
     bbe:	bf00      	nop
     bc0:	000a01ac 	.word	0x000a01ac
     bc4:	000a0214 	.word	0x000a0214
     bc8:	000a027c 	.word	0x000a027c

00000bcc <__fp_lock>:
     bcc:	b508      	push	{r3, lr}
     bce:	6e4b      	ldr	r3, [r1, #100]	; 0x64
     bd0:	07da      	lsls	r2, r3, #31
     bd2:	d405      	bmi.n	be0 <__fp_lock+0x14>
     bd4:	898b      	ldrh	r3, [r1, #12]
     bd6:	059b      	lsls	r3, r3, #22
     bd8:	d402      	bmi.n	be0 <__fp_lock+0x14>
     bda:	6d88      	ldr	r0, [r1, #88]	; 0x58
     bdc:	f000 f95d 	bl	e9a <__retarget_lock_acquire_recursive>
     be0:	2000      	movs	r0, #0
     be2:	bd08      	pop	{r3, pc}

00000be4 <__fp_unlock>:
     be4:	b508      	push	{r3, lr}
     be6:	6e4b      	ldr	r3, [r1, #100]	; 0x64
     be8:	07da      	lsls	r2, r3, #31
     bea:	d405      	bmi.n	bf8 <__fp_unlock+0x14>
     bec:	898b      	ldrh	r3, [r1, #12]
     bee:	059b      	lsls	r3, r3, #22
     bf0:	d402      	bmi.n	bf8 <__fp_unlock+0x14>
     bf2:	6d88      	ldr	r0, [r1, #88]	; 0x58
     bf4:	f000 f957 	bl	ea6 <__retarget_lock_release_recursive>
     bf8:	2000      	movs	r0, #0
     bfa:	bd08      	pop	{r3, pc}

00000bfc <global_stdio_init.part.0>:
     bfc:	b510      	push	{r4, lr}
     bfe:	4b0b      	ldr	r3, [pc, #44]	; (c2c <__HEAP_SIZE+0x2c>)
     c00:	2104      	movs	r1, #4
     c02:	4c0b      	ldr	r4, [pc, #44]	; (c30 <__HEAP_SIZE+0x30>)
     c04:	4a0b      	ldr	r2, [pc, #44]	; (c34 <__HEAP_SIZE+0x34>)
     c06:	4620      	mov	r0, r4
     c08:	601a      	str	r2, [r3, #0]
     c0a:	2200      	movs	r2, #0
     c0c:	f7ff ff7c 	bl	b08 <std>
     c10:	f104 0068 	add.w	r0, r4, #104	; 0x68
     c14:	2201      	movs	r2, #1
     c16:	2109      	movs	r1, #9
     c18:	f7ff ff76 	bl	b08 <std>
     c1c:	f104 00d0 	add.w	r0, r4, #208	; 0xd0
     c20:	2202      	movs	r2, #2
     c22:	2112      	movs	r1, #18
     c24:	e8bd 4010 	ldmia.w	sp!, {r4, lr}
     c28:	f7ff bf6e 	b.w	b08 <std>
     c2c:	000a02e4 	.word	0x000a02e4
     c30:	000a01ac 	.word	0x000a01ac
     c34:	00000b75 	.word	0x00000b75

00000c38 <__sfp_lock_acquire>:
     c38:	4801      	ldr	r0, [pc, #4]	; (c40 <__sfp_lock_acquire+0x8>)
     c3a:	f000 b92e 	b.w	e9a <__retarget_lock_acquire_recursive>
     c3e:	bf00      	nop
     c40:	000a02ef 	.word	0x000a02ef

00000c44 <__sfp_lock_release>:
     c44:	4801      	ldr	r0, [pc, #4]	; (c4c <__sfp_lock_release+0x8>)
     c46:	f000 b92e 	b.w	ea6 <__retarget_lock_release_recursive>
     c4a:	bf00      	nop
     c4c:	000a02ef 	.word	0x000a02ef

00000c50 <__sfp>:
     c50:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
     c52:	4607      	mov	r7, r0
     c54:	f7ff fff0 	bl	c38 <__sfp_lock_acquire>
     c58:	4b23      	ldr	r3, [pc, #140]	; (ce8 <__sfp+0x98>)
     c5a:	681b      	ldr	r3, [r3, #0]
     c5c:	b90b      	cbnz	r3, c62 <__sfp+0x12>
     c5e:	f7ff ffcd 	bl	bfc <global_stdio_init.part.0>
     c62:	4e22      	ldr	r6, [pc, #136]	; (cec <__sfp+0x9c>)
     c64:	e9d6 3401 	ldrd	r3, r4, [r6, #4]
     c68:	3b01      	subs	r3, #1
     c6a:	d50f      	bpl.n	c8c <__sfp+0x3c>
     c6c:	6835      	ldr	r5, [r6, #0]
     c6e:	2d00      	cmp	r5, #0
     c70:	d138      	bne.n	ce4 <__sfp+0x94>
     c72:	f44f 71d6 	mov.w	r1, #428	; 0x1ac
     c76:	4638      	mov	r0, r7
     c78:	f000 f9f8 	bl	106c <_malloc_r>
     c7c:	4604      	mov	r4, r0
     c7e:	bb28      	cbnz	r0, ccc <__sfp+0x7c>
     c80:	6030      	str	r0, [r6, #0]
     c82:	f7ff ffdf 	bl	c44 <__sfp_lock_release>
     c86:	230c      	movs	r3, #12
     c88:	603b      	str	r3, [r7, #0]
     c8a:	e01b      	b.n	cc4 <__sfp+0x74>
     c8c:	f9b4 500c 	ldrsh.w	r5, [r4, #12]
     c90:	b9d5      	cbnz	r5, cc8 <__sfp+0x78>
     c92:	4b17      	ldr	r3, [pc, #92]	; (cf0 <__sfp+0xa0>)
     c94:	f104 0058 	add.w	r0, r4, #88	; 0x58
     c98:	6665      	str	r5, [r4, #100]	; 0x64
     c9a:	60e3      	str	r3, [r4, #12]
     c9c:	f000 f8f9 	bl	e92 <__retarget_lock_init_recursive>
     ca0:	f7ff ffd0 	bl	c44 <__sfp_lock_release>
     ca4:	2208      	movs	r2, #8
     ca6:	4629      	mov	r1, r5
     ca8:	f104 005c 	add.w	r0, r4, #92	; 0x5c
     cac:	6025      	str	r5, [r4, #0]
     cae:	61a5      	str	r5, [r4, #24]
     cb0:	e9c4 5501 	strd	r5, r5, [r4, #4]
     cb4:	e9c4 5504 	strd	r5, r5, [r4, #16]
     cb8:	f7ff ff1e 	bl	af8 <memset>
     cbc:	e9c4 550d 	strd	r5, r5, [r4, #52]	; 0x34
     cc0:	e9c4 5512 	strd	r5, r5, [r4, #72]	; 0x48
     cc4:	4620      	mov	r0, r4
     cc6:	bdf8      	pop	{r3, r4, r5, r6, r7, pc}
     cc8:	3468      	adds	r4, #104	; 0x68
     cca:	e7cd      	b.n	c68 <__sfp+0x18>
     ccc:	2304      	movs	r3, #4
     cce:	6005      	str	r5, [r0, #0]
     cd0:	300c      	adds	r0, #12
     cd2:	f44f 72d0 	mov.w	r2, #416	; 0x1a0
     cd6:	f840 3c08 	str.w	r3, [r0, #-8]
     cda:	4629      	mov	r1, r5
     cdc:	60a0      	str	r0, [r4, #8]
     cde:	f7ff ff0b 	bl	af8 <memset>
     ce2:	6034      	str	r4, [r6, #0]
     ce4:	6836      	ldr	r6, [r6, #0]
     ce6:	e7bd      	b.n	c64 <__sfp+0x14>
     ce8:	000a02e4 	.word	0x000a02e4
     cec:	000a0120 	.word	0x000a0120
     cf0:	ffff0001 	.word	0xffff0001

00000cf4 <__sinit>:
     cf4:	b510      	push	{r4, lr}
     cf6:	4604      	mov	r4, r0
     cf8:	f7ff ff9e 	bl	c38 <__sfp_lock_acquire>
     cfc:	6a23      	ldr	r3, [r4, #32]
     cfe:	b11b      	cbz	r3, d08 <__sinit+0x14>
     d00:	e8bd 4010 	ldmia.w	sp!, {r4, lr}
     d04:	f7ff bf9e 	b.w	c44 <__sfp_lock_release>
     d08:	4b04      	ldr	r3, [pc, #16]	; (d1c <__sinit+0x28>)
     d0a:	6223      	str	r3, [r4, #32]
     d0c:	4b04      	ldr	r3, [pc, #16]	; (d20 <__sinit+0x2c>)
     d0e:	681b      	ldr	r3, [r3, #0]
     d10:	2b00      	cmp	r3, #0
     d12:	d1f5      	bne.n	d00 <__sinit+0xc>
     d14:	f7ff ff72 	bl	bfc <global_stdio_init.part.0>
     d18:	e7f2      	b.n	d00 <__sinit+0xc>
     d1a:	bf00      	nop
     d1c:	00000b8d 	.word	0x00000b8d
     d20:	000a02e4 	.word	0x000a02e4

00000d24 <__fp_lock_all>:
     d24:	b508      	push	{r3, lr}
     d26:	f7ff ff87 	bl	c38 <__sfp_lock_acquire>
     d2a:	4a03      	ldr	r2, [pc, #12]	; (d38 <__fp_lock_all+0x14>)
     d2c:	4903      	ldr	r1, [pc, #12]	; (d3c <__fp_lock_all+0x18>)
     d2e:	2000      	movs	r0, #0
     d30:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
     d34:	f000 b87c 	b.w	e30 <_fwalk_sglue>
     d38:	000a0120 	.word	0x000a0120
     d3c:	00000bcd 	.word	0x00000bcd

00000d40 <__fp_unlock_all>:
     d40:	b508      	push	{r3, lr}
     d42:	4a04      	ldr	r2, [pc, #16]	; (d54 <__fp_unlock_all+0x14>)
     d44:	2000      	movs	r0, #0
     d46:	4904      	ldr	r1, [pc, #16]	; (d58 <__fp_unlock_all+0x18>)
     d48:	f000 f872 	bl	e30 <_fwalk_sglue>
     d4c:	e8bd 4008 	ldmia.w	sp!, {r3, lr}
     d50:	f7ff bf78 	b.w	c44 <__sfp_lock_release>
     d54:	000a0120 	.word	0x000a0120
     d58:	00000be5 	.word	0x00000be5

00000d5c <__sread>:
     d5c:	b510      	push	{r4, lr}
     d5e:	460c      	mov	r4, r1
     d60:	f9b1 100e 	ldrsh.w	r1, [r1, #14]
     d64:	f000 f852 	bl	e0c <_read_r>
     d68:	2800      	cmp	r0, #0
     d6a:	bfab      	itete	ge
     d6c:	6d63      	ldrge	r3, [r4, #84]	; 0x54
     d6e:	89a3      	ldrhlt	r3, [r4, #12]
     d70:	181b      	addge	r3, r3, r0
     d72:	f423 5380 	biclt.w	r3, r3, #4096	; 0x1000
     d76:	bfac      	ite	ge
     d78:	6563      	strge	r3, [r4, #84]	; 0x54
     d7a:	81a3      	strhlt	r3, [r4, #12]
     d7c:	bd10      	pop	{r4, pc}

00000d7e <__seofread>:
     d7e:	2000      	movs	r0, #0
     d80:	4770      	bx	lr

00000d82 <__swrite>:
     d82:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
     d86:	461f      	mov	r7, r3
     d88:	898b      	ldrh	r3, [r1, #12]
     d8a:	4605      	mov	r5, r0
     d8c:	460c      	mov	r4, r1
     d8e:	05db      	lsls	r3, r3, #23
     d90:	4616      	mov	r6, r2
     d92:	d505      	bpl.n	da0 <__swrite+0x1e>
     d94:	2302      	movs	r3, #2
     d96:	2200      	movs	r2, #0
     d98:	f9b1 100e 	ldrsh.w	r1, [r1, #14]
     d9c:	f000 f824 	bl	de8 <_lseek_r>
     da0:	89a3      	ldrh	r3, [r4, #12]
     da2:	4632      	mov	r2, r6
     da4:	f9b4 100e 	ldrsh.w	r1, [r4, #14]
     da8:	4628      	mov	r0, r5
     daa:	f423 5380 	bic.w	r3, r3, #4096	; 0x1000
     dae:	81a3      	strh	r3, [r4, #12]
     db0:	463b      	mov	r3, r7
     db2:	e8bd 41f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, lr}
     db6:	f000 b859 	b.w	e6c <_write_r>

00000dba <__sseek>:
     dba:	b510      	push	{r4, lr}
     dbc:	460c      	mov	r4, r1
     dbe:	f9b1 100e 	ldrsh.w	r1, [r1, #14]
     dc2:	f000 f811 	bl	de8 <_lseek_r>
     dc6:	1c43      	adds	r3, r0, #1
     dc8:	89a3      	ldrh	r3, [r4, #12]
     dca:	bf15      	itete	ne
     dcc:	6560      	strne	r0, [r4, #84]	; 0x54
     dce:	f423 5380 	biceq.w	r3, r3, #4096	; 0x1000
     dd2:	f443 5380 	orrne.w	r3, r3, #4096	; 0x1000
     dd6:	81a3      	strheq	r3, [r4, #12]
     dd8:	bf18      	it	ne
     dda:	81a3      	strhne	r3, [r4, #12]
     ddc:	bd10      	pop	{r4, pc}

00000dde <__sclose>:
     dde:	f9b1 100e 	ldrsh.w	r1, [r1, #14]
     de2:	f000 b9c3 	b.w	116c <_close_r>
	...

00000de8 <_lseek_r>:
     de8:	b538      	push	{r3, r4, r5, lr}
     dea:	4604      	mov	r4, r0
     dec:	4d06      	ldr	r5, [pc, #24]	; (e08 <_lseek_r+0x20>)
     dee:	4608      	mov	r0, r1
     df0:	4611      	mov	r1, r2
     df2:	2200      	movs	r2, #0
     df4:	602a      	str	r2, [r5, #0]
     df6:	461a      	mov	r2, r3
     df8:	f000 fb49 	bl	148e <_lseek>
     dfc:	1c43      	adds	r3, r0, #1
     dfe:	d102      	bne.n	e06 <_lseek_r+0x1e>
     e00:	682b      	ldr	r3, [r5, #0]
     e02:	b103      	cbz	r3, e06 <_lseek_r+0x1e>
     e04:	6023      	str	r3, [r4, #0]
     e06:	bd38      	pop	{r3, r4, r5, pc}
     e08:	000a02f8 	.word	0x000a02f8

00000e0c <_read_r>:
     e0c:	b538      	push	{r3, r4, r5, lr}
     e0e:	4604      	mov	r4, r0
     e10:	4d06      	ldr	r5, [pc, #24]	; (e2c <_read_r+0x20>)
     e12:	4608      	mov	r0, r1
     e14:	4611      	mov	r1, r2
     e16:	2200      	movs	r2, #0
     e18:	602a      	str	r2, [r5, #0]
     e1a:	461a      	mov	r2, r3
     e1c:	f000 fae1 	bl	13e2 <_read>
     e20:	1c43      	adds	r3, r0, #1
     e22:	d102      	bne.n	e2a <_read_r+0x1e>
     e24:	682b      	ldr	r3, [r5, #0]
     e26:	b103      	cbz	r3, e2a <_read_r+0x1e>
     e28:	6023      	str	r3, [r4, #0]
     e2a:	bd38      	pop	{r3, r4, r5, pc}
     e2c:	000a02f8 	.word	0x000a02f8

00000e30 <_fwalk_sglue>:
     e30:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
     e34:	4607      	mov	r7, r0
     e36:	4688      	mov	r8, r1
     e38:	4614      	mov	r4, r2
     e3a:	2600      	movs	r6, #0
     e3c:	e9d4 9501 	ldrd	r9, r5, [r4, #4]
     e40:	f1b9 0901 	subs.w	r9, r9, #1
     e44:	d505      	bpl.n	e52 <_fwalk_sglue+0x22>
     e46:	6824      	ldr	r4, [r4, #0]
     e48:	2c00      	cmp	r4, #0
     e4a:	d1f7      	bne.n	e3c <_fwalk_sglue+0xc>
     e4c:	4630      	mov	r0, r6
     e4e:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
     e52:	89ab      	ldrh	r3, [r5, #12]
     e54:	2b01      	cmp	r3, #1
     e56:	d907      	bls.n	e68 <_fwalk_sglue+0x38>
     e58:	f9b5 300e 	ldrsh.w	r3, [r5, #14]
     e5c:	3301      	adds	r3, #1
     e5e:	d003      	beq.n	e68 <_fwalk_sglue+0x38>
     e60:	4629      	mov	r1, r5
     e62:	4638      	mov	r0, r7
     e64:	47c0      	blx	r8
     e66:	4306      	orrs	r6, r0
     e68:	3568      	adds	r5, #104	; 0x68
     e6a:	e7e9      	b.n	e40 <_fwalk_sglue+0x10>

00000e6c <_write_r>:
     e6c:	b538      	push	{r3, r4, r5, lr}
     e6e:	4604      	mov	r4, r0
     e70:	4d06      	ldr	r5, [pc, #24]	; (e8c <_write_r+0x20>)
     e72:	4608      	mov	r0, r1
     e74:	4611      	mov	r1, r2
     e76:	2200      	movs	r2, #0
     e78:	602a      	str	r2, [r5, #0]
     e7a:	461a      	mov	r2, r3
     e7c:	f000 fb19 	bl	14b2 <_write>
     e80:	1c43      	adds	r3, r0, #1
     e82:	d102      	bne.n	e8a <_write_r+0x1e>
     e84:	682b      	ldr	r3, [r5, #0]
     e86:	b103      	cbz	r3, e8a <_write_r+0x1e>
     e88:	6023      	str	r3, [r4, #0]
     e8a:	bd38      	pop	{r3, r4, r5, pc}
     e8c:	000a02f8 	.word	0x000a02f8

00000e90 <__retarget_lock_init>:
     e90:	4770      	bx	lr

00000e92 <__retarget_lock_init_recursive>:
     e92:	4770      	bx	lr

00000e94 <__retarget_lock_close>:
     e94:	4770      	bx	lr

00000e96 <__retarget_lock_close_recursive>:
     e96:	4770      	bx	lr

00000e98 <__retarget_lock_acquire>:
     e98:	4770      	bx	lr

00000e9a <__retarget_lock_acquire_recursive>:
     e9a:	4770      	bx	lr

00000e9c <__retarget_lock_try_acquire>:
     e9c:	2001      	movs	r0, #1
     e9e:	4770      	bx	lr

00000ea0 <__retarget_lock_try_acquire_recursive>:
     ea0:	2001      	movs	r0, #1
     ea2:	4770      	bx	lr

00000ea4 <__retarget_lock_release>:
     ea4:	4770      	bx	lr

00000ea6 <__retarget_lock_release_recursive>:
     ea6:	4770      	bx	lr

00000ea8 <__sflush_r>:
     ea8:	f9b1 200c 	ldrsh.w	r2, [r1, #12]
     eac:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
     eb0:	0716      	lsls	r6, r2, #28
     eb2:	4605      	mov	r5, r0
     eb4:	460c      	mov	r4, r1
     eb6:	d454      	bmi.n	f62 <__sflush_r+0xba>
     eb8:	684b      	ldr	r3, [r1, #4]
     eba:	2b00      	cmp	r3, #0
     ebc:	dc02      	bgt.n	ec4 <__sflush_r+0x1c>
     ebe:	6c0b      	ldr	r3, [r1, #64]	; 0x40
     ec0:	2b00      	cmp	r3, #0
     ec2:	dd48      	ble.n	f56 <__sflush_r+0xae>
     ec4:	6ae6      	ldr	r6, [r4, #44]	; 0x2c
     ec6:	2e00      	cmp	r6, #0
     ec8:	d045      	beq.n	f56 <__sflush_r+0xae>
     eca:	2300      	movs	r3, #0
     ecc:	f412 5280 	ands.w	r2, r2, #4096	; 0x1000
     ed0:	682f      	ldr	r7, [r5, #0]
     ed2:	6a21      	ldr	r1, [r4, #32]
     ed4:	602b      	str	r3, [r5, #0]
     ed6:	d030      	beq.n	f3a <__sflush_r+0x92>
     ed8:	6d62      	ldr	r2, [r4, #84]	; 0x54
     eda:	89a3      	ldrh	r3, [r4, #12]
     edc:	0759      	lsls	r1, r3, #29
     ede:	d505      	bpl.n	eec <__sflush_r+0x44>
     ee0:	6863      	ldr	r3, [r4, #4]
     ee2:	1ad2      	subs	r2, r2, r3
     ee4:	6b63      	ldr	r3, [r4, #52]	; 0x34
     ee6:	b10b      	cbz	r3, eec <__sflush_r+0x44>
     ee8:	6c23      	ldr	r3, [r4, #64]	; 0x40
     eea:	1ad2      	subs	r2, r2, r3
     eec:	2300      	movs	r3, #0
     eee:	6ae6      	ldr	r6, [r4, #44]	; 0x2c
     ef0:	6a21      	ldr	r1, [r4, #32]
     ef2:	4628      	mov	r0, r5
     ef4:	47b0      	blx	r6
     ef6:	1c43      	adds	r3, r0, #1
     ef8:	89a3      	ldrh	r3, [r4, #12]
     efa:	d106      	bne.n	f0a <__sflush_r+0x62>
     efc:	6829      	ldr	r1, [r5, #0]
     efe:	291d      	cmp	r1, #29
     f00:	d82b      	bhi.n	f5a <__sflush_r+0xb2>
     f02:	4a2a      	ldr	r2, [pc, #168]	; (fac <__sflush_r+0x104>)
     f04:	40ca      	lsrs	r2, r1
     f06:	07d6      	lsls	r6, r2, #31
     f08:	d527      	bpl.n	f5a <__sflush_r+0xb2>
     f0a:	2200      	movs	r2, #0
     f0c:	04d9      	lsls	r1, r3, #19
     f0e:	6062      	str	r2, [r4, #4]
     f10:	6922      	ldr	r2, [r4, #16]
     f12:	6022      	str	r2, [r4, #0]
     f14:	d504      	bpl.n	f20 <__sflush_r+0x78>
     f16:	1c42      	adds	r2, r0, #1
     f18:	d101      	bne.n	f1e <__sflush_r+0x76>
     f1a:	682b      	ldr	r3, [r5, #0]
     f1c:	b903      	cbnz	r3, f20 <__sflush_r+0x78>
     f1e:	6560      	str	r0, [r4, #84]	; 0x54
     f20:	6b61      	ldr	r1, [r4, #52]	; 0x34
     f22:	602f      	str	r7, [r5, #0]
     f24:	b1b9      	cbz	r1, f56 <__sflush_r+0xae>
     f26:	f104 0344 	add.w	r3, r4, #68	; 0x44
     f2a:	4299      	cmp	r1, r3
     f2c:	d002      	beq.n	f34 <__sflush_r+0x8c>
     f2e:	4628      	mov	r0, r5
     f30:	f000 f9a6 	bl	1280 <_free_r>
     f34:	2300      	movs	r3, #0
     f36:	6363      	str	r3, [r4, #52]	; 0x34
     f38:	e00d      	b.n	f56 <__sflush_r+0xae>
     f3a:	2301      	movs	r3, #1
     f3c:	4628      	mov	r0, r5
     f3e:	47b0      	blx	r6
     f40:	4602      	mov	r2, r0
     f42:	1c50      	adds	r0, r2, #1
     f44:	d1c9      	bne.n	eda <__sflush_r+0x32>
     f46:	682b      	ldr	r3, [r5, #0]
     f48:	2b00      	cmp	r3, #0
     f4a:	d0c6      	beq.n	eda <__sflush_r+0x32>
     f4c:	2b1d      	cmp	r3, #29
     f4e:	d001      	beq.n	f54 <__sflush_r+0xac>
     f50:	2b16      	cmp	r3, #22
     f52:	d11d      	bne.n	f90 <__sflush_r+0xe8>
     f54:	602f      	str	r7, [r5, #0]
     f56:	2000      	movs	r0, #0
     f58:	e021      	b.n	f9e <__sflush_r+0xf6>
     f5a:	f043 0340 	orr.w	r3, r3, #64	; 0x40
     f5e:	b21b      	sxth	r3, r3
     f60:	e01a      	b.n	f98 <__sflush_r+0xf0>
     f62:	690f      	ldr	r7, [r1, #16]
     f64:	2f00      	cmp	r7, #0
     f66:	d0f6      	beq.n	f56 <__sflush_r+0xae>
     f68:	0793      	lsls	r3, r2, #30
     f6a:	680e      	ldr	r6, [r1, #0]
     f6c:	600f      	str	r7, [r1, #0]
     f6e:	bf0c      	ite	eq
     f70:	694b      	ldreq	r3, [r1, #20]
     f72:	2300      	movne	r3, #0
     f74:	eba6 0807 	sub.w	r8, r6, r7
     f78:	608b      	str	r3, [r1, #8]
     f7a:	f1b8 0f00 	cmp.w	r8, #0
     f7e:	ddea      	ble.n	f56 <__sflush_r+0xae>
     f80:	4643      	mov	r3, r8
     f82:	463a      	mov	r2, r7
     f84:	6a21      	ldr	r1, [r4, #32]
     f86:	4628      	mov	r0, r5
     f88:	6aa6      	ldr	r6, [r4, #40]	; 0x28
     f8a:	47b0      	blx	r6
     f8c:	2800      	cmp	r0, #0
     f8e:	dc08      	bgt.n	fa2 <__sflush_r+0xfa>
     f90:	f9b4 300c 	ldrsh.w	r3, [r4, #12]
     f94:	f043 0340 	orr.w	r3, r3, #64	; 0x40
     f98:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
     f9c:	81a3      	strh	r3, [r4, #12]
     f9e:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
     fa2:	4407      	add	r7, r0
     fa4:	eba8 0800 	sub.w	r8, r8, r0
     fa8:	e7e7      	b.n	f7a <__sflush_r+0xd2>
     faa:	bf00      	nop
     fac:	20400001 	.word	0x20400001

00000fb0 <_fflush_r>:
     fb0:	b538      	push	{r3, r4, r5, lr}
     fb2:	690b      	ldr	r3, [r1, #16]
     fb4:	4605      	mov	r5, r0
     fb6:	460c      	mov	r4, r1
     fb8:	b913      	cbnz	r3, fc0 <_fflush_r+0x10>
     fba:	2500      	movs	r5, #0
     fbc:	4628      	mov	r0, r5
     fbe:	bd38      	pop	{r3, r4, r5, pc}
     fc0:	b118      	cbz	r0, fca <_fflush_r+0x1a>
     fc2:	6a03      	ldr	r3, [r0, #32]
     fc4:	b90b      	cbnz	r3, fca <_fflush_r+0x1a>
     fc6:	f7ff fe95 	bl	cf4 <__sinit>
     fca:	f9b4 300c 	ldrsh.w	r3, [r4, #12]
     fce:	2b00      	cmp	r3, #0
     fd0:	d0f3      	beq.n	fba <_fflush_r+0xa>
     fd2:	6e62      	ldr	r2, [r4, #100]	; 0x64
     fd4:	07d0      	lsls	r0, r2, #31
     fd6:	d404      	bmi.n	fe2 <_fflush_r+0x32>
     fd8:	0599      	lsls	r1, r3, #22
     fda:	d402      	bmi.n	fe2 <_fflush_r+0x32>
     fdc:	6da0      	ldr	r0, [r4, #88]	; 0x58
     fde:	f7ff ff5c 	bl	e9a <__retarget_lock_acquire_recursive>
     fe2:	4628      	mov	r0, r5
     fe4:	4621      	mov	r1, r4
     fe6:	f7ff ff5f 	bl	ea8 <__sflush_r>
     fea:	6e63      	ldr	r3, [r4, #100]	; 0x64
     fec:	4605      	mov	r5, r0
     fee:	07da      	lsls	r2, r3, #31
     ff0:	d4e4      	bmi.n	fbc <_fflush_r+0xc>
     ff2:	89a3      	ldrh	r3, [r4, #12]
     ff4:	059b      	lsls	r3, r3, #22
     ff6:	d4e1      	bmi.n	fbc <_fflush_r+0xc>
     ff8:	6da0      	ldr	r0, [r4, #88]	; 0x58
     ffa:	f7ff ff54 	bl	ea6 <__retarget_lock_release_recursive>
     ffe:	e7dd      	b.n	fbc <_fflush_r+0xc>

00001000 <fflush>:
    1000:	4601      	mov	r1, r0
    1002:	b920      	cbnz	r0, 100e <fflush+0xe>
    1004:	4a04      	ldr	r2, [pc, #16]	; (1018 <fflush+0x18>)
    1006:	4905      	ldr	r1, [pc, #20]	; (101c <fflush+0x1c>)
    1008:	4805      	ldr	r0, [pc, #20]	; (1020 <fflush+0x20>)
    100a:	f7ff bf11 	b.w	e30 <_fwalk_sglue>
    100e:	4b05      	ldr	r3, [pc, #20]	; (1024 <fflush+0x24>)
    1010:	6818      	ldr	r0, [r3, #0]
    1012:	f7ff bfcd 	b.w	fb0 <_fflush_r>
    1016:	bf00      	nop
    1018:	000a0120 	.word	0x000a0120
    101c:	00000fb1 	.word	0x00000fb1
    1020:	000a0130 	.word	0x000a0130
    1024:	000a012c 	.word	0x000a012c

00001028 <sbrk_aligned>:
    1028:	b570      	push	{r4, r5, r6, lr}
    102a:	4e0f      	ldr	r6, [pc, #60]	; (1068 <sbrk_aligned+0x40>)
    102c:	460c      	mov	r4, r1
    102e:	4605      	mov	r5, r0
    1030:	6831      	ldr	r1, [r6, #0]
    1032:	b911      	cbnz	r1, 103a <sbrk_aligned+0x12>
    1034:	f000 f914 	bl	1260 <_sbrk_r>
    1038:	6030      	str	r0, [r6, #0]
    103a:	4621      	mov	r1, r4
    103c:	4628      	mov	r0, r5
    103e:	f000 f90f 	bl	1260 <_sbrk_r>
    1042:	1c43      	adds	r3, r0, #1
    1044:	d103      	bne.n	104e <sbrk_aligned+0x26>
    1046:	f04f 34ff 	mov.w	r4, #4294967295	; 0xffffffff
    104a:	4620      	mov	r0, r4
    104c:	bd70      	pop	{r4, r5, r6, pc}
    104e:	1cc4      	adds	r4, r0, #3
    1050:	f024 0403 	bic.w	r4, r4, #3
    1054:	42a0      	cmp	r0, r4
    1056:	d0f8      	beq.n	104a <sbrk_aligned+0x22>
    1058:	1a21      	subs	r1, r4, r0
    105a:	4628      	mov	r0, r5
    105c:	f000 f900 	bl	1260 <_sbrk_r>
    1060:	3001      	adds	r0, #1
    1062:	d1f2      	bne.n	104a <sbrk_aligned+0x22>
    1064:	e7ef      	b.n	1046 <sbrk_aligned+0x1e>
    1066:	bf00      	nop
    1068:	000a02f0 	.word	0x000a02f0

0000106c <_malloc_r>:
    106c:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    1070:	1ccd      	adds	r5, r1, #3
    1072:	4606      	mov	r6, r0
    1074:	f025 0503 	bic.w	r5, r5, #3
    1078:	3508      	adds	r5, #8
    107a:	2d0c      	cmp	r5, #12
    107c:	bf38      	it	cc
    107e:	250c      	movcc	r5, #12
    1080:	2d00      	cmp	r5, #0
    1082:	db01      	blt.n	1088 <_malloc_r+0x1c>
    1084:	42a9      	cmp	r1, r5
    1086:	d904      	bls.n	1092 <_malloc_r+0x26>
    1088:	230c      	movs	r3, #12
    108a:	6033      	str	r3, [r6, #0]
    108c:	2000      	movs	r0, #0
    108e:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    1092:	f8df 80d4 	ldr.w	r8, [pc, #212]	; 1168 <_malloc_r+0xfc>
    1096:	f000 f8d7 	bl	1248 <__malloc_lock>
    109a:	f8d8 3000 	ldr.w	r3, [r8]
    109e:	461c      	mov	r4, r3
    10a0:	bb44      	cbnz	r4, 10f4 <_malloc_r+0x88>
    10a2:	4629      	mov	r1, r5
    10a4:	4630      	mov	r0, r6
    10a6:	f7ff ffbf 	bl	1028 <sbrk_aligned>
    10aa:	1c43      	adds	r3, r0, #1
    10ac:	4604      	mov	r4, r0
    10ae:	d158      	bne.n	1162 <_malloc_r+0xf6>
    10b0:	f8d8 4000 	ldr.w	r4, [r8]
    10b4:	4627      	mov	r7, r4
    10b6:	2f00      	cmp	r7, #0
    10b8:	d143      	bne.n	1142 <_malloc_r+0xd6>
    10ba:	2c00      	cmp	r4, #0
    10bc:	d04b      	beq.n	1156 <_malloc_r+0xea>
    10be:	6823      	ldr	r3, [r4, #0]
    10c0:	4639      	mov	r1, r7
    10c2:	4630      	mov	r0, r6
    10c4:	eb04 0903 	add.w	r9, r4, r3
    10c8:	f000 f8ca 	bl	1260 <_sbrk_r>
    10cc:	4581      	cmp	r9, r0
    10ce:	d142      	bne.n	1156 <_malloc_r+0xea>
    10d0:	6821      	ldr	r1, [r4, #0]
    10d2:	4630      	mov	r0, r6
    10d4:	1a6d      	subs	r5, r5, r1
    10d6:	4629      	mov	r1, r5
    10d8:	f7ff ffa6 	bl	1028 <sbrk_aligned>
    10dc:	3001      	adds	r0, #1
    10de:	d03a      	beq.n	1156 <_malloc_r+0xea>
    10e0:	6823      	ldr	r3, [r4, #0]
    10e2:	442b      	add	r3, r5
    10e4:	6023      	str	r3, [r4, #0]
    10e6:	f8d8 3000 	ldr.w	r3, [r8]
    10ea:	685a      	ldr	r2, [r3, #4]
    10ec:	bb62      	cbnz	r2, 1148 <_malloc_r+0xdc>
    10ee:	f8c8 7000 	str.w	r7, [r8]
    10f2:	e00f      	b.n	1114 <_malloc_r+0xa8>
    10f4:	6822      	ldr	r2, [r4, #0]
    10f6:	1b52      	subs	r2, r2, r5
    10f8:	d420      	bmi.n	113c <_malloc_r+0xd0>
    10fa:	2a0b      	cmp	r2, #11
    10fc:	d917      	bls.n	112e <_malloc_r+0xc2>
    10fe:	1961      	adds	r1, r4, r5
    1100:	42a3      	cmp	r3, r4
    1102:	6025      	str	r5, [r4, #0]
    1104:	bf18      	it	ne
    1106:	6059      	strne	r1, [r3, #4]
    1108:	6863      	ldr	r3, [r4, #4]
    110a:	bf08      	it	eq
    110c:	f8c8 1000 	streq.w	r1, [r8]
    1110:	5162      	str	r2, [r4, r5]
    1112:	604b      	str	r3, [r1, #4]
    1114:	4630      	mov	r0, r6
    1116:	f000 f89d 	bl	1254 <__malloc_unlock>
    111a:	f104 000b 	add.w	r0, r4, #11
    111e:	1d23      	adds	r3, r4, #4
    1120:	f020 0007 	bic.w	r0, r0, #7
    1124:	1ac2      	subs	r2, r0, r3
    1126:	bf1c      	itt	ne
    1128:	1a1b      	subne	r3, r3, r0
    112a:	50a3      	strne	r3, [r4, r2]
    112c:	e7af      	b.n	108e <_malloc_r+0x22>
    112e:	6862      	ldr	r2, [r4, #4]
    1130:	42a3      	cmp	r3, r4
    1132:	bf0c      	ite	eq
    1134:	f8c8 2000 	streq.w	r2, [r8]
    1138:	605a      	strne	r2, [r3, #4]
    113a:	e7eb      	b.n	1114 <_malloc_r+0xa8>
    113c:	4623      	mov	r3, r4
    113e:	6864      	ldr	r4, [r4, #4]
    1140:	e7ae      	b.n	10a0 <_malloc_r+0x34>
    1142:	463c      	mov	r4, r7
    1144:	687f      	ldr	r7, [r7, #4]
    1146:	e7b6      	b.n	10b6 <_malloc_r+0x4a>
    1148:	461a      	mov	r2, r3
    114a:	685b      	ldr	r3, [r3, #4]
    114c:	42a3      	cmp	r3, r4
    114e:	d1fb      	bne.n	1148 <_malloc_r+0xdc>
    1150:	2300      	movs	r3, #0
    1152:	6053      	str	r3, [r2, #4]
    1154:	e7de      	b.n	1114 <_malloc_r+0xa8>
    1156:	230c      	movs	r3, #12
    1158:	4630      	mov	r0, r6
    115a:	6033      	str	r3, [r6, #0]
    115c:	f000 f87a 	bl	1254 <__malloc_unlock>
    1160:	e794      	b.n	108c <_malloc_r+0x20>
    1162:	6005      	str	r5, [r0, #0]
    1164:	e7d6      	b.n	1114 <_malloc_r+0xa8>
    1166:	bf00      	nop
    1168:	000a02f4 	.word	0x000a02f4

0000116c <_close_r>:
    116c:	b538      	push	{r3, r4, r5, lr}
    116e:	2300      	movs	r3, #0
    1170:	4d05      	ldr	r5, [pc, #20]	; (1188 <_close_r+0x1c>)
    1172:	4604      	mov	r4, r0
    1174:	4608      	mov	r0, r1
    1176:	602b      	str	r3, [r5, #0]
    1178:	f000 f9c8 	bl	150c <_close>
    117c:	1c43      	adds	r3, r0, #1
    117e:	d102      	bne.n	1186 <_close_r+0x1a>
    1180:	682b      	ldr	r3, [r5, #0]
    1182:	b103      	cbz	r3, 1186 <_close_r+0x1a>
    1184:	6023      	str	r3, [r4, #0]
    1186:	bd38      	pop	{r3, r4, r5, pc}
    1188:	000a02f8 	.word	0x000a02f8

0000118c <_reclaim_reent>:
    118c:	4b2d      	ldr	r3, [pc, #180]	; (1244 <_reclaim_reent+0xb8>)
    118e:	681b      	ldr	r3, [r3, #0]
    1190:	4283      	cmp	r3, r0
    1192:	b570      	push	{r4, r5, r6, lr}
    1194:	4604      	mov	r4, r0
    1196:	d053      	beq.n	1240 <_reclaim_reent+0xb4>
    1198:	69c3      	ldr	r3, [r0, #28]
    119a:	b31b      	cbz	r3, 11e4 <_reclaim_reent+0x58>
    119c:	68db      	ldr	r3, [r3, #12]
    119e:	b163      	cbz	r3, 11ba <_reclaim_reent+0x2e>
    11a0:	2500      	movs	r5, #0
    11a2:	69e3      	ldr	r3, [r4, #28]
    11a4:	68db      	ldr	r3, [r3, #12]
    11a6:	5959      	ldr	r1, [r3, r5]
    11a8:	b9b1      	cbnz	r1, 11d8 <_reclaim_reent+0x4c>
    11aa:	3504      	adds	r5, #4
    11ac:	2d80      	cmp	r5, #128	; 0x80
    11ae:	d1f8      	bne.n	11a2 <_reclaim_reent+0x16>
    11b0:	69e3      	ldr	r3, [r4, #28]
    11b2:	4620      	mov	r0, r4
    11b4:	68d9      	ldr	r1, [r3, #12]
    11b6:	f000 f863 	bl	1280 <_free_r>
    11ba:	69e3      	ldr	r3, [r4, #28]
    11bc:	6819      	ldr	r1, [r3, #0]
    11be:	b111      	cbz	r1, 11c6 <_reclaim_reent+0x3a>
    11c0:	4620      	mov	r0, r4
    11c2:	f000 f85d 	bl	1280 <_free_r>
    11c6:	69e3      	ldr	r3, [r4, #28]
    11c8:	689d      	ldr	r5, [r3, #8]
    11ca:	b15d      	cbz	r5, 11e4 <_reclaim_reent+0x58>
    11cc:	4629      	mov	r1, r5
    11ce:	4620      	mov	r0, r4
    11d0:	682d      	ldr	r5, [r5, #0]
    11d2:	f000 f855 	bl	1280 <_free_r>
    11d6:	e7f8      	b.n	11ca <_reclaim_reent+0x3e>
    11d8:	680e      	ldr	r6, [r1, #0]
    11da:	4620      	mov	r0, r4
    11dc:	f000 f850 	bl	1280 <_free_r>
    11e0:	4631      	mov	r1, r6
    11e2:	e7e1      	b.n	11a8 <_reclaim_reent+0x1c>
    11e4:	6961      	ldr	r1, [r4, #20]
    11e6:	b111      	cbz	r1, 11ee <_reclaim_reent+0x62>
    11e8:	4620      	mov	r0, r4
    11ea:	f000 f849 	bl	1280 <_free_r>
    11ee:	69e1      	ldr	r1, [r4, #28]
    11f0:	b111      	cbz	r1, 11f8 <_reclaim_reent+0x6c>
    11f2:	4620      	mov	r0, r4
    11f4:	f000 f844 	bl	1280 <_free_r>
    11f8:	6b21      	ldr	r1, [r4, #48]	; 0x30
    11fa:	b111      	cbz	r1, 1202 <_reclaim_reent+0x76>
    11fc:	4620      	mov	r0, r4
    11fe:	f000 f83f 	bl	1280 <_free_r>
    1202:	6b61      	ldr	r1, [r4, #52]	; 0x34
    1204:	b111      	cbz	r1, 120c <_reclaim_reent+0x80>
    1206:	4620      	mov	r0, r4
    1208:	f000 f83a 	bl	1280 <_free_r>
    120c:	6ba1      	ldr	r1, [r4, #56]	; 0x38
    120e:	b111      	cbz	r1, 1216 <_reclaim_reent+0x8a>
    1210:	4620      	mov	r0, r4
    1212:	f000 f835 	bl	1280 <_free_r>
    1216:	6ca1      	ldr	r1, [r4, #72]	; 0x48
    1218:	b111      	cbz	r1, 1220 <_reclaim_reent+0x94>
    121a:	4620      	mov	r0, r4
    121c:	f000 f830 	bl	1280 <_free_r>
    1220:	6c61      	ldr	r1, [r4, #68]	; 0x44
    1222:	b111      	cbz	r1, 122a <_reclaim_reent+0x9e>
    1224:	4620      	mov	r0, r4
    1226:	f000 f82b 	bl	1280 <_free_r>
    122a:	6ae1      	ldr	r1, [r4, #44]	; 0x2c
    122c:	b111      	cbz	r1, 1234 <_reclaim_reent+0xa8>
    122e:	4620      	mov	r0, r4
    1230:	f000 f826 	bl	1280 <_free_r>
    1234:	6a23      	ldr	r3, [r4, #32]
    1236:	b11b      	cbz	r3, 1240 <_reclaim_reent+0xb4>
    1238:	4620      	mov	r0, r4
    123a:	e8bd 4070 	ldmia.w	sp!, {r4, r5, r6, lr}
    123e:	4718      	bx	r3
    1240:	bd70      	pop	{r4, r5, r6, pc}
    1242:	bf00      	nop
    1244:	000a012c 	.word	0x000a012c

00001248 <__malloc_lock>:
    1248:	4801      	ldr	r0, [pc, #4]	; (1250 <__malloc_lock+0x8>)
    124a:	f7ff be26 	b.w	e9a <__retarget_lock_acquire_recursive>
    124e:	bf00      	nop
    1250:	000a02ec 	.word	0x000a02ec

00001254 <__malloc_unlock>:
    1254:	4801      	ldr	r0, [pc, #4]	; (125c <__malloc_unlock+0x8>)
    1256:	f7ff be26 	b.w	ea6 <__retarget_lock_release_recursive>
    125a:	bf00      	nop
    125c:	000a02ec 	.word	0x000a02ec

00001260 <_sbrk_r>:
    1260:	b538      	push	{r3, r4, r5, lr}
    1262:	2300      	movs	r3, #0
    1264:	4d05      	ldr	r5, [pc, #20]	; (127c <_sbrk_r+0x1c>)
    1266:	4604      	mov	r4, r0
    1268:	4608      	mov	r0, r1
    126a:	602b      	str	r3, [r5, #0]
    126c:	f000 f976 	bl	155c <_sbrk>
    1270:	1c43      	adds	r3, r0, #1
    1272:	d102      	bne.n	127a <_sbrk_r+0x1a>
    1274:	682b      	ldr	r3, [r5, #0]
    1276:	b103      	cbz	r3, 127a <_sbrk_r+0x1a>
    1278:	6023      	str	r3, [r4, #0]
    127a:	bd38      	pop	{r3, r4, r5, pc}
    127c:	000a02f8 	.word	0x000a02f8

00001280 <_free_r>:
    1280:	b538      	push	{r3, r4, r5, lr}
    1282:	4605      	mov	r5, r0
    1284:	2900      	cmp	r1, #0
    1286:	d041      	beq.n	130c <_free_r+0x8c>
    1288:	f851 3c04 	ldr.w	r3, [r1, #-4]
    128c:	1f0c      	subs	r4, r1, #4
    128e:	2b00      	cmp	r3, #0
    1290:	bfb8      	it	lt
    1292:	18e4      	addlt	r4, r4, r3
    1294:	f7ff ffd8 	bl	1248 <__malloc_lock>
    1298:	4a1d      	ldr	r2, [pc, #116]	; (1310 <_free_r+0x90>)
    129a:	6813      	ldr	r3, [r2, #0]
    129c:	b933      	cbnz	r3, 12ac <_free_r+0x2c>
    129e:	6063      	str	r3, [r4, #4]
    12a0:	6014      	str	r4, [r2, #0]
    12a2:	4628      	mov	r0, r5
    12a4:	e8bd 4038 	ldmia.w	sp!, {r3, r4, r5, lr}
    12a8:	f7ff bfd4 	b.w	1254 <__malloc_unlock>
    12ac:	42a3      	cmp	r3, r4
    12ae:	d908      	bls.n	12c2 <_free_r+0x42>
    12b0:	6820      	ldr	r0, [r4, #0]
    12b2:	1821      	adds	r1, r4, r0
    12b4:	428b      	cmp	r3, r1
    12b6:	bf01      	itttt	eq
    12b8:	6819      	ldreq	r1, [r3, #0]
    12ba:	685b      	ldreq	r3, [r3, #4]
    12bc:	1809      	addeq	r1, r1, r0
    12be:	6021      	streq	r1, [r4, #0]
    12c0:	e7ed      	b.n	129e <_free_r+0x1e>
    12c2:	461a      	mov	r2, r3
    12c4:	685b      	ldr	r3, [r3, #4]
    12c6:	b10b      	cbz	r3, 12cc <_free_r+0x4c>
    12c8:	42a3      	cmp	r3, r4
    12ca:	d9fa      	bls.n	12c2 <_free_r+0x42>
    12cc:	6811      	ldr	r1, [r2, #0]
    12ce:	1850      	adds	r0, r2, r1
    12d0:	42a0      	cmp	r0, r4
    12d2:	d10b      	bne.n	12ec <_free_r+0x6c>
    12d4:	6820      	ldr	r0, [r4, #0]
    12d6:	4401      	add	r1, r0
    12d8:	1850      	adds	r0, r2, r1
    12da:	6011      	str	r1, [r2, #0]
    12dc:	4283      	cmp	r3, r0
    12de:	d1e0      	bne.n	12a2 <_free_r+0x22>
    12e0:	6818      	ldr	r0, [r3, #0]
    12e2:	685b      	ldr	r3, [r3, #4]
    12e4:	4408      	add	r0, r1
    12e6:	6053      	str	r3, [r2, #4]
    12e8:	6010      	str	r0, [r2, #0]
    12ea:	e7da      	b.n	12a2 <_free_r+0x22>
    12ec:	d902      	bls.n	12f4 <_free_r+0x74>
    12ee:	230c      	movs	r3, #12
    12f0:	602b      	str	r3, [r5, #0]
    12f2:	e7d6      	b.n	12a2 <_free_r+0x22>
    12f4:	6820      	ldr	r0, [r4, #0]
    12f6:	1821      	adds	r1, r4, r0
    12f8:	428b      	cmp	r3, r1
    12fa:	bf02      	ittt	eq
    12fc:	6819      	ldreq	r1, [r3, #0]
    12fe:	685b      	ldreq	r3, [r3, #4]
    1300:	1809      	addeq	r1, r1, r0
    1302:	6063      	str	r3, [r4, #4]
    1304:	bf08      	it	eq
    1306:	6021      	streq	r1, [r4, #0]
    1308:	6054      	str	r4, [r2, #4]
    130a:	e7ca      	b.n	12a2 <_free_r+0x22>
    130c:	bd38      	pop	{r3, r4, r5, pc}
    130e:	bf00      	nop
    1310:	000a02f4 	.word	0x000a02f4

00001314 <_exit>:
    1314:	4601      	mov	r1, r0
    1316:	4a03      	ldr	r2, [pc, #12]	; (1324 <_exit+0x10>)
    1318:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
    131c:	b508      	push	{r3, lr}
    131e:	f000 f803 	bl	1328 <_kill_shared>
    1322:	bf00      	nop
    1324:	00020026 	.word	0x00020026

00001328 <_kill_shared>:
    1328:	b507      	push	{r0, r1, r2, lr}
    132a:	e9cd 2100 	strd	r2, r1, [sp]
    132e:	f000 fa5b 	bl	17e8 <_has_ext_exit_extended>
    1332:	2800      	cmp	r0, #0
    1334:	bf0c      	ite	eq
    1336:	2418      	moveq	r4, #24
    1338:	2420      	movne	r4, #32
    133a:	f000 fa55 	bl	17e8 <_has_ext_exit_extended>
    133e:	b120      	cbz	r0, 134a <_kill_shared+0x22>
    1340:	466d      	mov	r5, sp
    1342:	4620      	mov	r0, r4
    1344:	4629      	mov	r1, r5
    1346:	beab      	bkpt	0x00ab
    1348:	4604      	mov	r4, r0
    134a:	9d00      	ldr	r5, [sp, #0]
    134c:	e7f9      	b.n	1342 <_kill_shared+0x1a>
	...

00001350 <_kill>:
    1350:	2906      	cmp	r1, #6
    1352:	b508      	push	{r3, lr}
    1354:	bf0c      	ite	eq
    1356:	4a02      	ldreq	r2, [pc, #8]	; (1360 <_kill+0x10>)
    1358:	4a02      	ldrne	r2, [pc, #8]	; (1364 <_kill+0x14>)
    135a:	f7ff ffe5 	bl	1328 <_kill_shared>
    135e:	bf00      	nop
    1360:	00020023 	.word	0x00020023
    1364:	00020026 	.word	0x00020026

00001368 <findslot>:
    1368:	4b0a      	ldr	r3, [pc, #40]	; (1394 <findslot+0x2c>)
    136a:	b510      	push	{r4, lr}
    136c:	4604      	mov	r4, r0
    136e:	6818      	ldr	r0, [r3, #0]
    1370:	b118      	cbz	r0, 137a <findslot+0x12>
    1372:	6a03      	ldr	r3, [r0, #32]
    1374:	b90b      	cbnz	r3, 137a <findslot+0x12>
    1376:	f7ff fcbd 	bl	cf4 <__sinit>
    137a:	2c13      	cmp	r4, #19
    137c:	d807      	bhi.n	138e <findslot+0x26>
    137e:	4806      	ldr	r0, [pc, #24]	; (1398 <findslot+0x30>)
    1380:	f850 2034 	ldr.w	r2, [r0, r4, lsl #3]
    1384:	3201      	adds	r2, #1
    1386:	d002      	beq.n	138e <findslot+0x26>
    1388:	eb00 00c4 	add.w	r0, r0, r4, lsl #3
    138c:	bd10      	pop	{r4, pc}
    138e:	2000      	movs	r0, #0
    1390:	e7fc      	b.n	138c <findslot+0x24>
    1392:	bf00      	nop
    1394:	000a012c 	.word	0x000a012c
    1398:	000a030c 	.word	0x000a030c

0000139c <error>:
    139c:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
    139e:	4604      	mov	r4, r0
    13a0:	2613      	movs	r6, #19
    13a2:	f000 fb33 	bl	1a0c <__errno>
    13a6:	2700      	movs	r7, #0
    13a8:	4605      	mov	r5, r0
    13aa:	4630      	mov	r0, r6
    13ac:	4639      	mov	r1, r7
    13ae:	beab      	bkpt	0x00ab
    13b0:	4606      	mov	r6, r0
    13b2:	4620      	mov	r0, r4
    13b4:	602e      	str	r6, [r5, #0]
    13b6:	bdf8      	pop	{r3, r4, r5, r6, r7, pc}

000013b8 <checkerror>:
    13b8:	1c43      	adds	r3, r0, #1
    13ba:	d101      	bne.n	13c0 <checkerror+0x8>
    13bc:	f7ff bfee 	b.w	139c <error>
    13c0:	4770      	bx	lr

000013c2 <_swiread>:
    13c2:	b530      	push	{r4, r5, lr}
    13c4:	b085      	sub	sp, #20
    13c6:	2406      	movs	r4, #6
    13c8:	ad01      	add	r5, sp, #4
    13ca:	9203      	str	r2, [sp, #12]
    13cc:	e9cd 0101 	strd	r0, r1, [sp, #4]
    13d0:	4620      	mov	r0, r4
    13d2:	4629      	mov	r1, r5
    13d4:	beab      	bkpt	0x00ab
    13d6:	4604      	mov	r4, r0
    13d8:	4620      	mov	r0, r4
    13da:	f7ff ffed 	bl	13b8 <checkerror>
    13de:	b005      	add	sp, #20
    13e0:	bd30      	pop	{r4, r5, pc}

000013e2 <_read>:
    13e2:	b570      	push	{r4, r5, r6, lr}
    13e4:	460e      	mov	r6, r1
    13e6:	4614      	mov	r4, r2
    13e8:	f7ff ffbe 	bl	1368 <findslot>
    13ec:	4605      	mov	r5, r0
    13ee:	b930      	cbnz	r0, 13fe <_read+0x1c>
    13f0:	f000 fb0c 	bl	1a0c <__errno>
    13f4:	2309      	movs	r3, #9
    13f6:	6003      	str	r3, [r0, #0]
    13f8:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
    13fc:	bd70      	pop	{r4, r5, r6, pc}
    13fe:	4622      	mov	r2, r4
    1400:	4631      	mov	r1, r6
    1402:	6800      	ldr	r0, [r0, #0]
    1404:	f7ff ffdd 	bl	13c2 <_swiread>
    1408:	1c43      	adds	r3, r0, #1
    140a:	d0f5      	beq.n	13f8 <_read+0x16>
    140c:	686b      	ldr	r3, [r5, #4]
    140e:	1a20      	subs	r0, r4, r0
    1410:	4403      	add	r3, r0
    1412:	606b      	str	r3, [r5, #4]
    1414:	e7f2      	b.n	13fc <_read+0x1a>

00001416 <_swilseek>:
    1416:	b5f7      	push	{r0, r1, r2, r4, r5, r6, r7, lr}
    1418:	460c      	mov	r4, r1
    141a:	4616      	mov	r6, r2
    141c:	f7ff ffa4 	bl	1368 <findslot>
    1420:	4605      	mov	r5, r0
    1422:	b940      	cbnz	r0, 1436 <_swilseek+0x20>
    1424:	f000 faf2 	bl	1a0c <__errno>
    1428:	2309      	movs	r3, #9
    142a:	6003      	str	r3, [r0, #0]
    142c:	f04f 34ff 	mov.w	r4, #4294967295	; 0xffffffff
    1430:	4620      	mov	r0, r4
    1432:	b003      	add	sp, #12
    1434:	bdf0      	pop	{r4, r5, r6, r7, pc}
    1436:	2e02      	cmp	r6, #2
    1438:	d903      	bls.n	1442 <_swilseek+0x2c>
    143a:	f000 fae7 	bl	1a0c <__errno>
    143e:	2316      	movs	r3, #22
    1440:	e7f3      	b.n	142a <_swilseek+0x14>
    1442:	2e01      	cmp	r6, #1
    1444:	d112      	bne.n	146c <_swilseek+0x56>
    1446:	6843      	ldr	r3, [r0, #4]
    1448:	18e4      	adds	r4, r4, r3
    144a:	d4f6      	bmi.n	143a <_swilseek+0x24>
    144c:	682b      	ldr	r3, [r5, #0]
    144e:	260a      	movs	r6, #10
    1450:	466f      	mov	r7, sp
    1452:	e9cd 3400 	strd	r3, r4, [sp]
    1456:	4630      	mov	r0, r6
    1458:	4639      	mov	r1, r7
    145a:	beab      	bkpt	0x00ab
    145c:	4606      	mov	r6, r0
    145e:	4630      	mov	r0, r6
    1460:	f7ff ffaa 	bl	13b8 <checkerror>
    1464:	2800      	cmp	r0, #0
    1466:	dbe1      	blt.n	142c <_swilseek+0x16>
    1468:	606c      	str	r4, [r5, #4]
    146a:	e7e1      	b.n	1430 <_swilseek+0x1a>
    146c:	2e02      	cmp	r6, #2
    146e:	6803      	ldr	r3, [r0, #0]
    1470:	d1ec      	bne.n	144c <_swilseek+0x36>
    1472:	260c      	movs	r6, #12
    1474:	466f      	mov	r7, sp
    1476:	9300      	str	r3, [sp, #0]
    1478:	4630      	mov	r0, r6
    147a:	4639      	mov	r1, r7
    147c:	beab      	bkpt	0x00ab
    147e:	4606      	mov	r6, r0
    1480:	4630      	mov	r0, r6
    1482:	f7ff ff99 	bl	13b8 <checkerror>
    1486:	1c43      	adds	r3, r0, #1
    1488:	d0d0      	beq.n	142c <_swilseek+0x16>
    148a:	4404      	add	r4, r0
    148c:	e7de      	b.n	144c <_swilseek+0x36>

0000148e <_lseek>:
    148e:	f7ff bfc2 	b.w	1416 <_swilseek>

00001492 <_swiwrite>:
    1492:	b530      	push	{r4, r5, lr}
    1494:	b085      	sub	sp, #20
    1496:	2405      	movs	r4, #5
    1498:	ad01      	add	r5, sp, #4
    149a:	9203      	str	r2, [sp, #12]
    149c:	e9cd 0101 	strd	r0, r1, [sp, #4]
    14a0:	4620      	mov	r0, r4
    14a2:	4629      	mov	r1, r5
    14a4:	beab      	bkpt	0x00ab
    14a6:	4604      	mov	r4, r0
    14a8:	4620      	mov	r0, r4
    14aa:	f7ff ff85 	bl	13b8 <checkerror>
    14ae:	b005      	add	sp, #20
    14b0:	bd30      	pop	{r4, r5, pc}

000014b2 <_write>:
    14b2:	b570      	push	{r4, r5, r6, lr}
    14b4:	460e      	mov	r6, r1
    14b6:	4615      	mov	r5, r2
    14b8:	f7ff ff56 	bl	1368 <findslot>
    14bc:	4604      	mov	r4, r0
    14be:	b930      	cbnz	r0, 14ce <_write+0x1c>
    14c0:	f000 faa4 	bl	1a0c <__errno>
    14c4:	2309      	movs	r3, #9
    14c6:	6003      	str	r3, [r0, #0]
    14c8:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
    14cc:	bd70      	pop	{r4, r5, r6, pc}
    14ce:	462a      	mov	r2, r5
    14d0:	4631      	mov	r1, r6
    14d2:	6800      	ldr	r0, [r0, #0]
    14d4:	f7ff ffdd 	bl	1492 <_swiwrite>
    14d8:	1e03      	subs	r3, r0, #0
    14da:	dbf5      	blt.n	14c8 <_write+0x16>
    14dc:	6862      	ldr	r2, [r4, #4]
    14de:	1ae8      	subs	r0, r5, r3
    14e0:	42ab      	cmp	r3, r5
    14e2:	4402      	add	r2, r0
    14e4:	6062      	str	r2, [r4, #4]
    14e6:	d1f1      	bne.n	14cc <_write+0x1a>
    14e8:	2000      	movs	r0, #0
    14ea:	e8bd 4070 	ldmia.w	sp!, {r4, r5, r6, lr}
    14ee:	f7ff bf55 	b.w	139c <error>

000014f2 <_swiclose>:
    14f2:	b537      	push	{r0, r1, r2, r4, r5, lr}
    14f4:	2402      	movs	r4, #2
    14f6:	ad01      	add	r5, sp, #4
    14f8:	9001      	str	r0, [sp, #4]
    14fa:	4620      	mov	r0, r4
    14fc:	4629      	mov	r1, r5
    14fe:	beab      	bkpt	0x00ab
    1500:	4604      	mov	r4, r0
    1502:	4620      	mov	r0, r4
    1504:	f7ff ff58 	bl	13b8 <checkerror>
    1508:	b003      	add	sp, #12
    150a:	bd30      	pop	{r4, r5, pc}

0000150c <_close>:
    150c:	b538      	push	{r3, r4, r5, lr}
    150e:	4605      	mov	r5, r0
    1510:	f7ff ff2a 	bl	1368 <findslot>
    1514:	4604      	mov	r4, r0
    1516:	b930      	cbnz	r0, 1526 <_close+0x1a>
    1518:	f000 fa78 	bl	1a0c <__errno>
    151c:	2309      	movs	r3, #9
    151e:	6003      	str	r3, [r0, #0]
    1520:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
    1524:	bd38      	pop	{r3, r4, r5, pc}
    1526:	3d01      	subs	r5, #1
    1528:	2d01      	cmp	r5, #1
    152a:	d809      	bhi.n	1540 <_close+0x34>
    152c:	4b09      	ldr	r3, [pc, #36]	; (1554 <_close+0x48>)
    152e:	689a      	ldr	r2, [r3, #8]
    1530:	691b      	ldr	r3, [r3, #16]
    1532:	429a      	cmp	r2, r3
    1534:	d104      	bne.n	1540 <_close+0x34>
    1536:	f04f 33ff 	mov.w	r3, #4294967295	; 0xffffffff
    153a:	6003      	str	r3, [r0, #0]
    153c:	2000      	movs	r0, #0
    153e:	e7f1      	b.n	1524 <_close+0x18>
    1540:	6820      	ldr	r0, [r4, #0]
    1542:	f7ff ffd6 	bl	14f2 <_swiclose>
    1546:	2800      	cmp	r0, #0
    1548:	d1ec      	bne.n	1524 <_close+0x18>
    154a:	f04f 33ff 	mov.w	r3, #4294967295	; 0xffffffff
    154e:	6023      	str	r3, [r4, #0]
    1550:	e7e8      	b.n	1524 <_close+0x18>
    1552:	bf00      	nop
    1554:	000a030c 	.word	0x000a030c

00001558 <_getpid>:
    1558:	2001      	movs	r0, #1
    155a:	4770      	bx	lr

0000155c <_sbrk>:
    155c:	4a0d      	ldr	r2, [pc, #52]	; (1594 <_sbrk+0x38>)
    155e:	4603      	mov	r3, r0
    1560:	6811      	ldr	r1, [r2, #0]
    1562:	b510      	push	{r4, lr}
    1564:	b909      	cbnz	r1, 156a <_sbrk+0xe>
    1566:	490c      	ldr	r1, [pc, #48]	; (1598 <_sbrk+0x3c>)
    1568:	6011      	str	r1, [r2, #0]
    156a:	6810      	ldr	r0, [r2, #0]
    156c:	4669      	mov	r1, sp
    156e:	4403      	add	r3, r0
    1570:	428b      	cmp	r3, r1
    1572:	d806      	bhi.n	1582 <_sbrk+0x26>
    1574:	4909      	ldr	r1, [pc, #36]	; (159c <_sbrk+0x40>)
    1576:	4c0a      	ldr	r4, [pc, #40]	; (15a0 <_sbrk+0x44>)
    1578:	6809      	ldr	r1, [r1, #0]
    157a:	42a1      	cmp	r1, r4
    157c:	d008      	beq.n	1590 <_sbrk+0x34>
    157e:	428b      	cmp	r3, r1
    1580:	d906      	bls.n	1590 <_sbrk+0x34>
    1582:	f000 fa43 	bl	1a0c <__errno>
    1586:	230c      	movs	r3, #12
    1588:	6003      	str	r3, [r0, #0]
    158a:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
    158e:	bd10      	pop	{r4, pc}
    1590:	6013      	str	r3, [r2, #0]
    1592:	e7fc      	b.n	158e <_sbrk+0x32>
    1594:	000a02fc 	.word	0x000a02fc
    1598:	000a03b0 	.word	0x000a03b0
    159c:	000a017c 	.word	0x000a017c
    15a0:	cafedead 	.word	0xcafedead

000015a4 <_swistat>:
    15a4:	b570      	push	{r4, r5, r6, lr}
    15a6:	460c      	mov	r4, r1
    15a8:	f7ff fede 	bl	1368 <findslot>
    15ac:	4605      	mov	r5, r0
    15ae:	b930      	cbnz	r0, 15be <_swistat+0x1a>
    15b0:	f000 fa2c 	bl	1a0c <__errno>
    15b4:	2309      	movs	r3, #9
    15b6:	6003      	str	r3, [r0, #0]
    15b8:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
    15bc:	bd70      	pop	{r4, r5, r6, pc}
    15be:	6863      	ldr	r3, [r4, #4]
    15c0:	260c      	movs	r6, #12
    15c2:	f443 5300 	orr.w	r3, r3, #8192	; 0x2000
    15c6:	6063      	str	r3, [r4, #4]
    15c8:	f44f 6380 	mov.w	r3, #1024	; 0x400
    15cc:	64a3      	str	r3, [r4, #72]	; 0x48
    15ce:	4630      	mov	r0, r6
    15d0:	4629      	mov	r1, r5
    15d2:	beab      	bkpt	0x00ab
    15d4:	4605      	mov	r5, r0
    15d6:	4628      	mov	r0, r5
    15d8:	f7ff feee 	bl	13b8 <checkerror>
    15dc:	1c43      	adds	r3, r0, #1
    15de:	d0eb      	beq.n	15b8 <_swistat+0x14>
    15e0:	6120      	str	r0, [r4, #16]
    15e2:	2000      	movs	r0, #0
    15e4:	e7ea      	b.n	15bc <_swistat+0x18>

000015e6 <_fstat>:
    15e6:	460b      	mov	r3, r1
    15e8:	2258      	movs	r2, #88	; 0x58
    15ea:	2100      	movs	r1, #0
    15ec:	b510      	push	{r4, lr}
    15ee:	4604      	mov	r4, r0
    15f0:	4618      	mov	r0, r3
    15f2:	f7ff fa81 	bl	af8 <memset>
    15f6:	4601      	mov	r1, r0
    15f8:	4620      	mov	r0, r4
    15fa:	e8bd 4010 	ldmia.w	sp!, {r4, lr}
    15fe:	f7ff bfd1 	b.w	15a4 <_swistat>

00001602 <_stat>:
    1602:	b538      	push	{r3, r4, r5, lr}
    1604:	460d      	mov	r5, r1
    1606:	4604      	mov	r4, r0
    1608:	2258      	movs	r2, #88	; 0x58
    160a:	2100      	movs	r1, #0
    160c:	4628      	mov	r0, r5
    160e:	f7ff fa73 	bl	af8 <memset>
    1612:	4620      	mov	r0, r4
    1614:	2100      	movs	r1, #0
    1616:	f000 f811 	bl	163c <_swiopen>
    161a:	1c43      	adds	r3, r0, #1
    161c:	4604      	mov	r4, r0
    161e:	d00b      	beq.n	1638 <_stat+0x36>
    1620:	686b      	ldr	r3, [r5, #4]
    1622:	4629      	mov	r1, r5
    1624:	f443 4301 	orr.w	r3, r3, #33024	; 0x8100
    1628:	606b      	str	r3, [r5, #4]
    162a:	f7ff ffbb 	bl	15a4 <_swistat>
    162e:	4605      	mov	r5, r0
    1630:	4620      	mov	r0, r4
    1632:	462c      	mov	r4, r5
    1634:	f7ff ff6a 	bl	150c <_close>
    1638:	4620      	mov	r0, r4
    163a:	bd38      	pop	{r3, r4, r5, pc}

0000163c <_swiopen>:
    163c:	e92d 47f0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, lr}
    1640:	4607      	mov	r7, r0
    1642:	b096      	sub	sp, #88	; 0x58
    1644:	460e      	mov	r6, r1
    1646:	2400      	movs	r4, #0
    1648:	f8df 909c 	ldr.w	r9, [pc, #156]	; 16e8 <_swiopen+0xac>
    164c:	f859 3034 	ldr.w	r3, [r9, r4, lsl #3]
    1650:	ea4f 08c4 	mov.w	r8, r4, lsl #3
    1654:	3301      	adds	r3, #1
    1656:	d031      	beq.n	16bc <_swiopen+0x80>
    1658:	3401      	adds	r4, #1
    165a:	2c14      	cmp	r4, #20
    165c:	d1f6      	bne.n	164c <_swiopen+0x10>
    165e:	f000 f9d5 	bl	1a0c <__errno>
    1662:	2318      	movs	r3, #24
    1664:	e039      	b.n	16da <_swiopen+0x9e>
    1666:	f3c6 4500 	ubfx	r5, r6, #16, #1
    166a:	f240 6301 	movw	r3, #1537	; 0x601
    166e:	07b2      	lsls	r2, r6, #30
    1670:	4638      	mov	r0, r7
    1672:	9700      	str	r7, [sp, #0]
    1674:	bf48      	it	mi
    1676:	f045 0502 	orrmi.w	r5, r5, #2
    167a:	421e      	tst	r6, r3
    167c:	bf18      	it	ne
    167e:	f045 0504 	orrne.w	r5, r5, #4
    1682:	0733      	lsls	r3, r6, #28
    1684:	bf44      	itt	mi
    1686:	f025 0504 	bicmi.w	r5, r5, #4
    168a:	f045 0508 	orrmi.w	r5, r5, #8
    168e:	f000 f9c3 	bl	1a18 <strlen>
    1692:	e9cd 5001 	strd	r5, r0, [sp, #4]
    1696:	2501      	movs	r5, #1
    1698:	4628      	mov	r0, r5
    169a:	4651      	mov	r1, sl
    169c:	beab      	bkpt	0x00ab
    169e:	4605      	mov	r5, r0
    16a0:	2d00      	cmp	r5, #0
    16a2:	db06      	blt.n	16b2 <_swiopen+0x76>
    16a4:	44c8      	add	r8, r9
    16a6:	2300      	movs	r3, #0
    16a8:	f849 5034 	str.w	r5, [r9, r4, lsl #3]
    16ac:	f8c8 3004 	str.w	r3, [r8, #4]
    16b0:	e016      	b.n	16e0 <_swiopen+0xa4>
    16b2:	4628      	mov	r0, r5
    16b4:	f7ff fe72 	bl	139c <error>
    16b8:	4604      	mov	r4, r0
    16ba:	e011      	b.n	16e0 <_swiopen+0xa4>
    16bc:	f406 6320 	and.w	r3, r6, #2560	; 0xa00
    16c0:	46ea      	mov	sl, sp
    16c2:	f5b3 6f20 	cmp.w	r3, #2560	; 0xa00
    16c6:	d1ce      	bne.n	1666 <_swiopen+0x2a>
    16c8:	4651      	mov	r1, sl
    16ca:	4638      	mov	r0, r7
    16cc:	f7ff ff99 	bl	1602 <_stat>
    16d0:	3001      	adds	r0, #1
    16d2:	d0c8      	beq.n	1666 <_swiopen+0x2a>
    16d4:	f000 f99a 	bl	1a0c <__errno>
    16d8:	2311      	movs	r3, #17
    16da:	f04f 34ff 	mov.w	r4, #4294967295	; 0xffffffff
    16de:	6003      	str	r3, [r0, #0]
    16e0:	4620      	mov	r0, r4
    16e2:	b016      	add	sp, #88	; 0x58
    16e4:	e8bd 87f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, pc}
    16e8:	000a030c 	.word	0x000a030c

000016ec <_open>:
    16ec:	b40e      	push	{r1, r2, r3}
    16ee:	b500      	push	{lr}
    16f0:	9901      	ldr	r1, [sp, #4]
    16f2:	f7ff ffa3 	bl	163c <_swiopen>
    16f6:	f85d eb04 	ldr.w	lr, [sp], #4
    16fa:	b003      	add	sp, #12
    16fc:	4770      	bx	lr
	...

00001700 <_get_semihosting_exts>:
    1700:	e92d 43f7 	stmdb	sp!, {r0, r1, r2, r4, r5, r6, r7, r8, r9, lr}
    1704:	4606      	mov	r6, r0
    1706:	4615      	mov	r5, r2
    1708:	460f      	mov	r7, r1
    170a:	4829      	ldr	r0, [pc, #164]	; (17b0 <_get_semihosting_exts+0xb0>)
    170c:	2100      	movs	r1, #0
    170e:	f7ff ff95 	bl	163c <_swiopen>
    1712:	4604      	mov	r4, r0
    1714:	462a      	mov	r2, r5
    1716:	2100      	movs	r1, #0
    1718:	4630      	mov	r0, r6
    171a:	f7ff f9ed 	bl	af8 <memset>
    171e:	1c63      	adds	r3, r4, #1
    1720:	d014      	beq.n	174c <_get_semihosting_exts+0x4c>
    1722:	4620      	mov	r0, r4
    1724:	f04f 080c 	mov.w	r8, #12
    1728:	f7ff fe1e 	bl	1368 <findslot>
    172c:	4681      	mov	r9, r0
    172e:	4640      	mov	r0, r8
    1730:	4649      	mov	r1, r9
    1732:	beab      	bkpt	0x00ab
    1734:	4680      	mov	r8, r0
    1736:	4640      	mov	r0, r8
    1738:	f7ff fe3e 	bl	13b8 <checkerror>
    173c:	2803      	cmp	r0, #3
    173e:	dd02      	ble.n	1746 <_get_semihosting_exts+0x46>
    1740:	1ec3      	subs	r3, r0, #3
    1742:	42ab      	cmp	r3, r5
    1744:	dc07      	bgt.n	1756 <_get_semihosting_exts+0x56>
    1746:	4620      	mov	r0, r4
    1748:	f7ff fee0 	bl	150c <_close>
    174c:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
    1750:	b003      	add	sp, #12
    1752:	e8bd 83f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, pc}
    1756:	2204      	movs	r2, #4
    1758:	4620      	mov	r0, r4
    175a:	eb0d 0102 	add.w	r1, sp, r2
    175e:	f7ff fe40 	bl	13e2 <_read>
    1762:	2803      	cmp	r0, #3
    1764:	ddef      	ble.n	1746 <_get_semihosting_exts+0x46>
    1766:	f89d 3004 	ldrb.w	r3, [sp, #4]
    176a:	2b53      	cmp	r3, #83	; 0x53
    176c:	d1eb      	bne.n	1746 <_get_semihosting_exts+0x46>
    176e:	f89d 3005 	ldrb.w	r3, [sp, #5]
    1772:	2b48      	cmp	r3, #72	; 0x48
    1774:	d1e7      	bne.n	1746 <_get_semihosting_exts+0x46>
    1776:	f89d 3006 	ldrb.w	r3, [sp, #6]
    177a:	2b46      	cmp	r3, #70	; 0x46
    177c:	d1e3      	bne.n	1746 <_get_semihosting_exts+0x46>
    177e:	f89d 3007 	ldrb.w	r3, [sp, #7]
    1782:	2b42      	cmp	r3, #66	; 0x42
    1784:	d1df      	bne.n	1746 <_get_semihosting_exts+0x46>
    1786:	2201      	movs	r2, #1
    1788:	4639      	mov	r1, r7
    178a:	4620      	mov	r0, r4
    178c:	f7ff fe43 	bl	1416 <_swilseek>
    1790:	2800      	cmp	r0, #0
    1792:	dbd8      	blt.n	1746 <_get_semihosting_exts+0x46>
    1794:	462a      	mov	r2, r5
    1796:	4631      	mov	r1, r6
    1798:	4620      	mov	r0, r4
    179a:	f7ff fe22 	bl	13e2 <_read>
    179e:	4605      	mov	r5, r0
    17a0:	4620      	mov	r0, r4
    17a2:	f7ff feb3 	bl	150c <_close>
    17a6:	4628      	mov	r0, r5
    17a8:	f7ff fe06 	bl	13b8 <checkerror>
    17ac:	e7d0      	b.n	1750 <_get_semihosting_exts+0x50>
    17ae:	bf00      	nop
    17b0:	00001a78 	.word	0x00001a78

000017b4 <initialise_semihosting_exts>:
    17b4:	b537      	push	{r0, r1, r2, r4, r5, lr}
    17b6:	2100      	movs	r1, #0
    17b8:	2201      	movs	r2, #1
    17ba:	4d09      	ldr	r5, [pc, #36]	; (17e0 <initialise_semihosting_exts+0x2c>)
    17bc:	a801      	add	r0, sp, #4
    17be:	4c09      	ldr	r4, [pc, #36]	; (17e4 <initialise_semihosting_exts+0x30>)
    17c0:	6029      	str	r1, [r5, #0]
    17c2:	6022      	str	r2, [r4, #0]
    17c4:	f7ff ff9c 	bl	1700 <_get_semihosting_exts>
    17c8:	2800      	cmp	r0, #0
    17ca:	dd07      	ble.n	17dc <initialise_semihosting_exts+0x28>
    17cc:	f89d 3004 	ldrb.w	r3, [sp, #4]
    17d0:	f003 0201 	and.w	r2, r3, #1
    17d4:	f003 0302 	and.w	r3, r3, #2
    17d8:	602a      	str	r2, [r5, #0]
    17da:	6023      	str	r3, [r4, #0]
    17dc:	b003      	add	sp, #12
    17de:	bd30      	pop	{r4, r5, pc}
    17e0:	000a0184 	.word	0x000a0184
    17e4:	000a0180 	.word	0x000a0180

000017e8 <_has_ext_exit_extended>:
    17e8:	b510      	push	{r4, lr}
    17ea:	4c04      	ldr	r4, [pc, #16]	; (17fc <_has_ext_exit_extended+0x14>)
    17ec:	6823      	ldr	r3, [r4, #0]
    17ee:	2b00      	cmp	r3, #0
    17f0:	da01      	bge.n	17f6 <_has_ext_exit_extended+0xe>
    17f2:	f7ff ffdf 	bl	17b4 <initialise_semihosting_exts>
    17f6:	6820      	ldr	r0, [r4, #0]
    17f8:	bd10      	pop	{r4, pc}
    17fa:	bf00      	nop
    17fc:	000a0184 	.word	0x000a0184

00001800 <_has_ext_stdout_stderr>:
    1800:	b510      	push	{r4, lr}
    1802:	4c04      	ldr	r4, [pc, #16]	; (1814 <_has_ext_stdout_stderr+0x14>)
    1804:	6823      	ldr	r3, [r4, #0]
    1806:	2b00      	cmp	r3, #0
    1808:	da01      	bge.n	180e <_has_ext_stdout_stderr+0xe>
    180a:	f7ff ffd3 	bl	17b4 <initialise_semihosting_exts>
    180e:	6820      	ldr	r0, [r4, #0]
    1810:	bd10      	pop	{r4, pc}
    1812:	bf00      	nop
    1814:	000a0180 	.word	0x000a0180

00001818 <initialise_monitor_handles>:
    1818:	e92d 4ff0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
    181c:	2303      	movs	r3, #3
    181e:	b085      	sub	sp, #20
    1820:	f8df 90ac 	ldr.w	r9, [pc, #172]	; 18d0 <initialise_monitor_handles+0xb8>
    1824:	2400      	movs	r4, #0
    1826:	af01      	add	r7, sp, #4
    1828:	2501      	movs	r5, #1
    182a:	f8cd 9004 	str.w	r9, [sp, #4]
    182e:	9303      	str	r3, [sp, #12]
    1830:	9402      	str	r4, [sp, #8]
    1832:	4628      	mov	r0, r5
    1834:	4639      	mov	r1, r7
    1836:	beab      	bkpt	0x00ab
    1838:	4605      	mov	r5, r0
    183a:	f8df 8098 	ldr.w	r8, [pc, #152]	; 18d4 <initialise_monitor_handles+0xbc>
    183e:	4623      	mov	r3, r4
    1840:	f04f 32ff 	mov.w	r2, #4294967295	; 0xffffffff
    1844:	4c1f      	ldr	r4, [pc, #124]	; (18c4 <initialise_monitor_handles+0xac>)
    1846:	f8c8 5000 	str.w	r5, [r8]
    184a:	f844 2033 	str.w	r2, [r4, r3, lsl #3]
    184e:	3301      	adds	r3, #1
    1850:	2b14      	cmp	r3, #20
    1852:	d1fa      	bne.n	184a <initialise_monitor_handles+0x32>
    1854:	4d1c      	ldr	r5, [pc, #112]	; (18c8 <initialise_monitor_handles+0xb0>)
    1856:	f7ff ffd3 	bl	1800 <_has_ext_stdout_stderr>
    185a:	b1d0      	cbz	r0, 1892 <initialise_monitor_handles+0x7a>
    185c:	f04f 0a03 	mov.w	sl, #3
    1860:	2304      	movs	r3, #4
    1862:	f8cd 9004 	str.w	r9, [sp, #4]
    1866:	2601      	movs	r6, #1
    1868:	f8cd a00c 	str.w	sl, [sp, #12]
    186c:	9302      	str	r3, [sp, #8]
    186e:	4630      	mov	r0, r6
    1870:	4639      	mov	r1, r7
    1872:	beab      	bkpt	0x00ab
    1874:	4683      	mov	fp, r0
    1876:	4b15      	ldr	r3, [pc, #84]	; (18cc <initialise_monitor_handles+0xb4>)
    1878:	f8cd 9004 	str.w	r9, [sp, #4]
    187c:	f8c3 b000 	str.w	fp, [r3]
    1880:	2308      	movs	r3, #8
    1882:	f8cd a00c 	str.w	sl, [sp, #12]
    1886:	9302      	str	r3, [sp, #8]
    1888:	4630      	mov	r0, r6
    188a:	4639      	mov	r1, r7
    188c:	beab      	bkpt	0x00ab
    188e:	4606      	mov	r6, r0
    1890:	602e      	str	r6, [r5, #0]
    1892:	682b      	ldr	r3, [r5, #0]
    1894:	2600      	movs	r6, #0
    1896:	3301      	adds	r3, #1
    1898:	6066      	str	r6, [r4, #4]
    189a:	bf02      	ittt	eq
    189c:	4b0b      	ldreq	r3, [pc, #44]	; (18cc <initialise_monitor_handles+0xb4>)
    189e:	681b      	ldreq	r3, [r3, #0]
    18a0:	602b      	streq	r3, [r5, #0]
    18a2:	f8d8 3000 	ldr.w	r3, [r8]
    18a6:	6023      	str	r3, [r4, #0]
    18a8:	f7ff ffaa 	bl	1800 <_has_ext_stdout_stderr>
    18ac:	b130      	cbz	r0, 18bc <initialise_monitor_handles+0xa4>
    18ae:	4b07      	ldr	r3, [pc, #28]	; (18cc <initialise_monitor_handles+0xb4>)
    18b0:	681b      	ldr	r3, [r3, #0]
    18b2:	e9c4 3602 	strd	r3, r6, [r4, #8]
    18b6:	682b      	ldr	r3, [r5, #0]
    18b8:	e9c4 3604 	strd	r3, r6, [r4, #16]
    18bc:	b005      	add	sp, #20
    18be:	e8bd 8ff0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, pc}
    18c2:	bf00      	nop
    18c4:	000a030c 	.word	0x000a030c
    18c8:	000a0300 	.word	0x000a0300
    18cc:	000a0304 	.word	0x000a0304
    18d0:	00001a8e 	.word	0x00001a8e
    18d4:	000a0308 	.word	0x000a0308

000018d8 <_link>:
    18d8:	b508      	push	{r3, lr}
    18da:	f000 f897 	bl	1a0c <__errno>
    18de:	2358      	movs	r3, #88	; 0x58
    18e0:	6003      	str	r3, [r0, #0]
    18e2:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
    18e6:	bd08      	pop	{r3, pc}

000018e8 <_unlink>:
    18e8:	b537      	push	{r0, r1, r2, r4, r5, lr}
    18ea:	240e      	movs	r4, #14
    18ec:	9000      	str	r0, [sp, #0]
    18ee:	f000 f893 	bl	1a18 <strlen>
    18f2:	466d      	mov	r5, sp
    18f4:	9001      	str	r0, [sp, #4]
    18f6:	4620      	mov	r0, r4
    18f8:	4629      	mov	r1, r5
    18fa:	beab      	bkpt	0x00ab
    18fc:	4604      	mov	r4, r0
    18fe:	1c63      	adds	r3, r4, #1
    1900:	d104      	bne.n	190c <_unlink+0x24>
    1902:	4620      	mov	r0, r4
    1904:	f7ff fd4a 	bl	139c <error>
    1908:	b003      	add	sp, #12
    190a:	bd30      	pop	{r4, r5, pc}
    190c:	2000      	movs	r0, #0
    190e:	e7fb      	b.n	1908 <_unlink+0x20>

00001910 <_gettimeofday>:
    1910:	b5f0      	push	{r4, r5, r6, r7, lr}
    1912:	460d      	mov	r5, r1
    1914:	4604      	mov	r4, r0
    1916:	b148      	cbz	r0, 192c <_gettimeofday+0x1c>
    1918:	2700      	movs	r7, #0
    191a:	2611      	movs	r6, #17
    191c:	4630      	mov	r0, r6
    191e:	4639      	mov	r1, r7
    1920:	beab      	bkpt	0x00ab
    1922:	4606      	mov	r6, r0
    1924:	17f3      	asrs	r3, r6, #31
    1926:	60a7      	str	r7, [r4, #8]
    1928:	e9c4 6300 	strd	r6, r3, [r4]
    192c:	b115      	cbz	r5, 1934 <_gettimeofday+0x24>
    192e:	2300      	movs	r3, #0
    1930:	e9c5 3300 	strd	r3, r3, [r5]
    1934:	2000      	movs	r0, #0
    1936:	bdf0      	pop	{r4, r5, r6, r7, pc}

00001938 <_clock>:
    1938:	b530      	push	{r4, r5, lr}
    193a:	2410      	movs	r4, #16
    193c:	2500      	movs	r5, #0
    193e:	4620      	mov	r0, r4
    1940:	4629      	mov	r1, r5
    1942:	beab      	bkpt	0x00ab
    1944:	4604      	mov	r4, r0
    1946:	4620      	mov	r0, r4
    1948:	bd30      	pop	{r4, r5, pc}

0000194a <_times>:
    194a:	b510      	push	{r4, lr}
    194c:	4604      	mov	r4, r0
    194e:	f7ff fff3 	bl	1938 <_clock>
    1952:	b124      	cbz	r4, 195e <_times+0x14>
    1954:	2300      	movs	r3, #0
    1956:	6020      	str	r0, [r4, #0]
    1958:	e9c4 3301 	strd	r3, r3, [r4, #4]
    195c:	60e3      	str	r3, [r4, #12]
    195e:	bd10      	pop	{r4, pc}

00001960 <_isatty>:
    1960:	b570      	push	{r4, r5, r6, lr}
    1962:	f7ff fd01 	bl	1368 <findslot>
    1966:	2409      	movs	r4, #9
    1968:	4605      	mov	r5, r0
    196a:	b920      	cbnz	r0, 1976 <_isatty+0x16>
    196c:	f000 f84e 	bl	1a0c <__errno>
    1970:	6004      	str	r4, [r0, #0]
    1972:	2000      	movs	r0, #0
    1974:	bd70      	pop	{r4, r5, r6, pc}
    1976:	4620      	mov	r0, r4
    1978:	4629      	mov	r1, r5
    197a:	beab      	bkpt	0x00ab
    197c:	4604      	mov	r4, r0
    197e:	2c01      	cmp	r4, #1
    1980:	4620      	mov	r0, r4
    1982:	d0f7      	beq.n	1974 <_isatty+0x14>
    1984:	f000 f842 	bl	1a0c <__errno>
    1988:	2513      	movs	r5, #19
    198a:	4604      	mov	r4, r0
    198c:	2600      	movs	r6, #0
    198e:	4628      	mov	r0, r5
    1990:	4631      	mov	r1, r6
    1992:	beab      	bkpt	0x00ab
    1994:	4605      	mov	r5, r0
    1996:	6025      	str	r5, [r4, #0]
    1998:	e7eb      	b.n	1972 <_isatty+0x12>

0000199a <_system>:
    199a:	b537      	push	{r0, r1, r2, r4, r5, lr}
    199c:	b1c8      	cbz	r0, 19d2 <_system+0x38>
    199e:	2412      	movs	r4, #18
    19a0:	9000      	str	r0, [sp, #0]
    19a2:	f000 f839 	bl	1a18 <strlen>
    19a6:	466d      	mov	r5, sp
    19a8:	9001      	str	r0, [sp, #4]
    19aa:	4620      	mov	r0, r4
    19ac:	4629      	mov	r1, r5
    19ae:	beab      	bkpt	0x00ab
    19b0:	4604      	mov	r4, r0
    19b2:	4620      	mov	r0, r4
    19b4:	f7ff fd00 	bl	13b8 <checkerror>
    19b8:	28ff      	cmp	r0, #255	; 0xff
    19ba:	4603      	mov	r3, r0
    19bc:	d902      	bls.n	19c4 <_system+0x2a>
    19be:	b003      	add	sp, #12
    19c0:	bd30      	pop	{r4, r5, pc}
    19c2:	0040      	lsls	r0, r0, #1
    19c4:	2800      	cmp	r0, #0
    19c6:	d0fa      	beq.n	19be <_system+0x24>
    19c8:	f3c0 2207 	ubfx	r2, r0, #8, #8
    19cc:	429a      	cmp	r2, r3
    19ce:	d0f6      	beq.n	19be <_system+0x24>
    19d0:	e7f7      	b.n	19c2 <_system+0x28>
    19d2:	2001      	movs	r0, #1
    19d4:	e7f3      	b.n	19be <_system+0x24>

000019d6 <_rename>:
    19d6:	b530      	push	{r4, r5, lr}
    19d8:	460c      	mov	r4, r1
    19da:	b085      	sub	sp, #20
    19dc:	9000      	str	r0, [sp, #0]
    19de:	f000 f81b 	bl	1a18 <strlen>
    19e2:	e9cd 0401 	strd	r0, r4, [sp, #4]
    19e6:	4620      	mov	r0, r4
    19e8:	240f      	movs	r4, #15
    19ea:	f000 f815 	bl	1a18 <strlen>
    19ee:	466d      	mov	r5, sp
    19f0:	9003      	str	r0, [sp, #12]
    19f2:	4620      	mov	r0, r4
    19f4:	4629      	mov	r1, r5
    19f6:	beab      	bkpt	0x00ab
    19f8:	4604      	mov	r4, r0
    19fa:	4620      	mov	r0, r4
    19fc:	f7ff fcdc 	bl	13b8 <checkerror>
    1a00:	3800      	subs	r0, #0
    1a02:	bf18      	it	ne
    1a04:	2001      	movne	r0, #1
    1a06:	4240      	negs	r0, r0
    1a08:	b005      	add	sp, #20
    1a0a:	bd30      	pop	{r4, r5, pc}

00001a0c <__errno>:
    1a0c:	4b01      	ldr	r3, [pc, #4]	; (1a14 <__errno+0x8>)
    1a0e:	6818      	ldr	r0, [r3, #0]
    1a10:	4770      	bx	lr
    1a12:	bf00      	nop
    1a14:	000a012c 	.word	0x000a012c

00001a18 <strlen>:
    1a18:	4603      	mov	r3, r0
    1a1a:	f813 2b01 	ldrb.w	r2, [r3], #1
    1a1e:	2a00      	cmp	r2, #0
    1a20:	d1fb      	bne.n	1a1a <strlen+0x2>
    1a22:	1a18      	subs	r0, r3, r0
    1a24:	3801      	subs	r0, #1
    1a26:	4770      	bx	lr

00001a28 <__copy_table_start__>:
    1a28:	1aec      	subs	r4, r5, r3
    1a2a:	0000      	movs	r0, r0
    1a2c:	0000      	movs	r0, r0
    1a2e:	000a      	movs	r2, r1
    1a30:	0064      	lsls	r4, r4, #1
	...

00001a34 <__copy_table_end__>:
    1a34:	0190      	lsls	r0, r2, #6
    1a36:	000a      	movs	r2, r1
    1a38:	0087      	lsls	r7, r0, #2
	...

00001a3c <_init>:
    1a3c:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
    1a3e:	bf00      	nop
    1a40:	bcf8      	pop	{r3, r4, r5, r6, r7}
    1a42:	bc08      	pop	{r3}
    1a44:	469e      	mov	lr, r3
    1a46:	4770      	bx	lr

00001a48 <_fini>:
    1a48:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
    1a4a:	bf00      	nop
    1a4c:	bcf8      	pop	{r3, r4, r5, r6, r7}
    1a4e:	bc08      	pop	{r3}
    1a50:	469e      	mov	lr, r3
    1a52:	4770      	bx	lr

00001a54 <all_implied_fbits>:
    1a54:	413e 410c 4111 4127 4136 4103 4106 4115     >A.A.A'A6A.A.A.A
    1a64:	410f 410e 4126 4113 4129 4102 4119 410a     .A.A&A.A)A.A.A.A
    1a74:	410b 0000 733a 6d65 6869 736f 6974 676e     .A..:semihosting
    1a84:	662d 6165 7574 6572 0073 743a 0074 0000     -features.:tt...

00001a94 <all_implied_fbits>:
    1a94:	413e 410c 4111 4127 4136 4103 4106 4115     >A.A.A'A6A.A.A.A
    1aa4:	410f 410e 4126 4113 4129 4102 4119 410a     .A.A&A.A)A.A.A.A
    1ab4:	410b 0000                                   .A..

00001ab8 <__EH_FRAME_BEGIN__>:
    1ab8:	0010 0000 0000 0000 7a01 0052 7c02 010e     .........zR..|..
    1ac8:	0c1b 000d 0010 0000 0018 0000 ff44 ffff     ............D...
    1ad8:	0010 0000 0000 0000                         ........

00001ae0 <__FRAME_END__>:
    1ae0:	0000 0000                                   ....
