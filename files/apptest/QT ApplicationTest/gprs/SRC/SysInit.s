	INCLUDE	option.inc
	INCLUDE	memcfg.inc
	INCLUDE	2410addr.inc
	
	INCLUDE	 vector.s
	
;	AREA    reset, CODE, READONLY
	
;	EXPORT	InitSystem
InitSystem
	
	ldr	r0,=WTCON       ;watch dog disable 
	ldr	r1,=0x0         
	str	r1,[r0]

	ldr	r0,=INTMSK
	ldr	r1,=0xffffffff  ;all interrupt disable
	str	r1,[r0]

	ldr	r0,=INTSUBMSK
	ldr	r1,=0x3ff		;all sub interrupt disable
	str	r1,[r0]
	
	;To reduce PLL lock time, adjust the LOCKTIME register. 
	ldr	r0,=LOCKTIME
	ldr	r1,=0xffffff
	str	r1,[r0]
	
	 [ PLL_ON_START
	;Configure MPLL
	ldr	r0,=MPLLCON
	ldr	r1,=((M_MDIV<<12)+(M_PDIV<<4)+M_SDIV)  ;Fin=12MHz,Fout=50MHz
	str	r1,[r0]
	]
	
	ldr	r0, =CLKCON
	ldr	r1, =0xffff0
	str	r1, [r0]		;使能所有功能单元块时钟,复位后缺省为全部使能

	;Check if the boot is caused by the wake-up from POWER_OFF mode.
;	ldr	r1,=GSTATUS2
;	ldr	r0,[r1]
;	tst	r0,#0x2
	;In case of the wake-up from POWER_OFF mode, go to POWER_OFF_WAKEUP handler. 
;	bne	WAKEUP_POWER_OFF

	adr	r0, SMRDATA	;can not use ldr r0, =xxxx important!!!
	ldr	r1, =BWSCON	;BWSCON Address
	add	r2, r0, #52	;End address of SMRDATA
0       					
	ldr	r3, [r0], #4    
	str	r3, [r1], #4    
	cmp	r2, r0		
	bne	%B0
	
	;ldr	r0, =IrqSvcVector	
	;ldr	r1, =IRQ_SERVICE		
	;str	r1, [r0]
	
	ldr	r0, =BWSCON
	ldr	r0, [r0]
	ands	r0, r0, #6		;OM[1:0] != 0, NOR FLash boot
	bne	InitSystem_exit		;do not read nand flash	
	adr	r0, __ENTRY			;OM[1:0] == 0, NAND FLash boot	
	cmp	r0, #0				;if use Multi-ice,
	bne	InitSystem_exit		;do not read nand flash for boot
	
	mov	r5, #NFCONF
	ldr	r0,	=(1<<15)|(1<<12)|(1<<11)|(7<<8)|(7<<4)|(7)
	str	r0,	[r5]
	
	bl	ReadNandID
	mov	r6, #0
	ldr	r0, =0xec73
	cmp	r5,	r0
	beq	%F1
	ldr	r0, =0xec75
	cmp	r5, r0
	beq	%F1
	mov	r6, #1
1	
	bl	ReadNandStatus	
	
	mov	r8, #0
	ldr	r9, =__ENTRY	
2	
	ands	r0, r8, #0x1f
	bne		%F3
	mov		r0, r8
	bl		CheckBadBlk
	cmp		r0, #0
	addne	r8, r8, #32
	bne		%F4
3	
	mov	r0, r8
	mov	r1, r9
	bl	ReadNandPage
	add	r9, r9, #512
	add	r8, r8, #1
4	
	cmp	r8, #256			;128K
	bcc	%B2
	
	mov	r5, #NFCONF			;DsNandFlash
	ldr	r0, [r5]
	and	r0, r0, #~0x8000
	str	r0, [r5]
	ldr	pc, =InitSystem_exit

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	EXPORT	IRQ_SERVICE	
IRQ_SERVICE  
	sub	sp, sp, #4       ;reserved for PC
	stmfd	sp!, {r8-r9}
	
	ldr	r9, =INTOFFSET
	ldr	r9, [r9]
	ldr	r8, =HandleEINT0
	add	r8, r8,r9,lsl #2
	ldr	r8, [r8]
	str	r8, [sp,#8]
	ldmfd	sp!,{r8-r9,pc}
	
ReadNandID
	mov		 r7,#NFCONF	
	ldr      r0,[r7,#0]		;NFChipEn();
	bic      r0,r0,#0x800
	str      r0,[r7,#0]	
	mov      r0,#0x90		;WrNFCmd(RdIDCMD);
	strb     r0,[r7,#4]	
	mov      r4,#0			;WrNFAddr(0);
	strb     r4,[r7,#8]	
1							;while(NFIsBusy());
	ldr      r0,[r7,#0x10]	
	tst      r0,#1
	beq      %B1
	ldrb     r0,[r7,#0xc]	;id  = RdNFDat()<<8;
	mov      r0,r0,lsl #8	
	ldrb     r1,[r7,#0xc]	;id |= RdNFDat();
	orr      r5,r1,r0	
	ldr      r0,[r7,#0]		;NFChipDs();
	orr      r0,r0,#0x800
	str      r0,[r7,#0]	
	mov		 pc,lr	
	
ReadNandStatus
	mov		 r7,#NFCONF
	ldr      r0,[r7,#0]		;NFChipEn();
	bic      r0,r0,#0x800
	str      r0,[r7,#0]
	mov      r0,#0x70		;WrNFCmd(QUERYCMD);
	strb     r0,[r7,#4]	
	ldrb     r1,[r7,#0xc]	;r1 = RdNFDat();
	ldr      r0,[r7,#0]		;NFChipDs();
	orr      r0,r0,#0x800
	str      r0,[r7,#0]
	mov		 pc,lr

WaitNandBusy
	mov      r0,#0x70		;WrNFCmd(QUERYCMD);
	mov      r1,#NFCONF
	strb     r0,[r1,#4]
1							;while(!(RdNFDat()&0x40));	
	ldrb     r0,[r1,#0xc]
	tst      r0,#0x40
	beq		 %B1
	mov      r0,#0			;WrNFCmd(READCMD0);
	strb     r0,[r1,#4]
	mov      pc,lr

CheckBadBlk
	mov		r7, lr
	mov		r5, #NFCONF
	
	bic		r0, r0, #0x1f	;addr &= ~0x1f;
	ldr      r1,[r5,#0]		;NFChipEn()
	bic      r1,r1,#0x800
	str      r1,[r5,#0]	

	mov      r1,#0x50		;WrNFCmd(READCMD2)
	strb     r1,[r5,#4]	
	mov		 r1, #5
	strb     r1,[r5,#8]		;WrNFAddr(5)
	strb     r0,[r5,#8]		;WrNFAddr(addr)
	mov      r1,r0,lsr #8	;WrNFAddr(addr>>8)
	strb     r1,[r5,#8]	
	cmp      r6,#0			;if(NandAddr)		
	movne    r0,r0,lsr #16	;WrNFAddr(addr>>16)
	strneb   r0,[r5,#8]
	
	bl		WaitNandBusy	;WaitNFBusy()

	ldrb	r0, [r5,#0xc]	;RdNFDat()
	sub		r0, r0, #0xff
	
	mov      r1,#0			;WrNFCmd(READCMD0)
	strb     r1,[r5,#4]	
	
	ldr      r1,[r5,#0]		;NFChipDs()
	orr      r1,r1,#0x800
	str      r1,[r5,#0]
	
	mov		pc, r7

ReadNandPage
	mov		 r7,lr
	mov      r4,r1
	mov      r5,#NFCONF

	ldr      r1,[r5,#0]		;NFChipEn()
	bic      r1,r1,#0x800
	str      r1,[r5,#0]	

	mov      r1,#0			;WrNFCmd(READCMD0)
	strb     r1,[r5,#4]	
	strb     r1,[r5,#8]		;WrNFAddr(0)
	strb     r0,[r5,#8]		;WrNFAddr(addr)
	mov      r1,r0,lsr #8	;WrNFAddr(addr>>8)
	strb     r1,[r5,#8]	
	cmp      r6,#0			;if(NandAddr)		
	movne    r0,r0,lsr #16	;WrNFAddr(addr>>16)
	strneb   r0,[r5,#8]
	
	ldr      r0,[r5,#0]		;InitEcc()
	orr      r0,r0,#0x1000
	str      r0,[r5,#0]	
	
	bl       WaitNandBusy	;WaitNFBusy()
	
	mov      r0,#0			;for(i=0; i<512; i++)
1
	ldrb     r1,[r5,#0xc]	;buf[i] = RdNFDat()
	strb     r1,[r4,r0]
	add      r0,r0,#1
	bic      r0,r0,#0x10000
	cmp      r0,#0x200
	bcc      %B1
	
	ldr      r0,[r5,#0]		;NFChipDs()
	orr      r0,r0,#0x800
	str      r0,[r5,#0]
		
	mov		 pc,r7

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	LTORG	
	
SMRDATA DATA
; Memory configuration should be optimized for best performance 
; The following parameter is not optimized.                     
; Memory access cycle parameter strategy
; 1) The memory settings is  safe parameters even at HCLK=75Mhz.
; 2) SDRAM refresh period is for HCLK=75Mhz. 

        DCD (0+(B1_BWSCON<<4)+(B2_BWSCON<<8)+(B3_BWSCON<<12)+(B4_BWSCON<<16)+(B5_BWSCON<<20)+(B6_BWSCON<<24)+(B7_BWSCON<<28))
    	DCD ((B0_Tacs<<13)+(B0_Tcos<<11)+(B0_Tacc<<8)+(B0_Tcoh<<6)+(B0_Tah<<4)+(B0_Tacp<<2)+(B0_PMC))   ;GCS0
    	DCD ((B1_Tacs<<13)+(B1_Tcos<<11)+(B1_Tacc<<8)+(B1_Tcoh<<6)+(B1_Tah<<4)+(B1_Tacp<<2)+(B1_PMC))   ;GCS1 
    	DCD ((B2_Tacs<<13)+(B2_Tcos<<11)+(B2_Tacc<<8)+(B2_Tcoh<<6)+(B2_Tah<<4)+(B2_Tacp<<2)+(B2_PMC))   ;GCS2
    	DCD ((B3_Tacs<<13)+(B3_Tcos<<11)+(B3_Tacc<<8)+(B3_Tcoh<<6)+(B3_Tah<<4)+(B3_Tacp<<2)+(B3_PMC))   ;GCS3
    	DCD ((B4_Tacs<<13)+(B4_Tcos<<11)+(B4_Tacc<<8)+(B4_Tcoh<<6)+(B4_Tah<<4)+(B4_Tacp<<2)+(B4_PMC))   ;GCS4
    	DCD ((B5_Tacs<<13)+(B5_Tcos<<11)+(B5_Tacc<<8)+(B5_Tcoh<<6)+(B5_Tah<<4)+(B5_Tacp<<2)+(B5_PMC))   ;GCS5
    	DCD ((B6_MT<<15)+(B6_Trcd<<2)+(B6_SCAN))    ;GCS6
    	DCD ((B7_Tacs<<13)+(B7_Tcos<<11)+(B7_Tacc<<8)+(B7_Tcoh<<6)+(B7_Tah<<4)+(B7_Tacp<<2)+(B7_PMC))	;GCS7
    	DCD ((REFEN<<23)+(TREFMD<<22)+(Trp<<20)+(Trc<<18)+(Tchr<<16)+REFCNT)

		DCD 0x32            ;SCLK power saving mode, BANKSIZE 128M/128M

    	DCD 0x30            ;MRSR6 CL=3clk
    	DCD 0x30            ;MRSR7
;    	DCD 0x20            ;MRSR6 CL=2clk
;    	DCD 0x20            ;MRSR7

;***********************************************

DRAM_END	EQU	0x33ffc000

	AREA RamData, DATA, READWRITE

	^	(DRAM_END - 0x800)
UserStack	#	256
SVCStack	#	256
UndefStack	#	256
AbortStack	#	256
IRQStack	#	256
FIQStack	#	256
	EXPORT	UserStack
	EXPORT	SVCStack
	EXPORT	UndefStack
	EXPORT	AbortStack
	EXPORT	IRQStack
	EXPORT	FIQStack

	MAP	(DRAM_END - 0x100)
SysRstVector	#	4	
UdfInsVector	#	4	
SwiSvcVector	#	4
InsAbtVector	#	4
DatAbtVector	#	4
ReservedVector	#	4
IrqSvcVector	#	4
FiqSvcVector	#	4
	EXPORT	SysRstVector
	EXPORT	UdfInsVector
	EXPORT	SwiSvcVector
	EXPORT	InsAbtVector
	EXPORT	DatAbtVector
	EXPORT	ReservedVector
	EXPORT	IrqSvcVector
	EXPORT	FiqSvcVector
	
;Do not use the label 'IntVectorTable',
;The value of IntVectorTable is different with the address you think it may be.
;IntVectorTable
HandleEINT0   	#   4
HandleEINT1   	#   4
HandleEINT2   	#   4
HandleEINT3   	#   4
HandleEINT4_7	#   4
HandleEINT8_23	#   4
HandleRSV6		#   4
HandleBATFLT   	#   4
HandleTICK   	#   4
HandleWDT		#   4
HandleTIMER0 	#   4
HandleTIMER1 	#   4
HandleTIMER2 	#   4
HandleTIMER3 	#   4
HandleTIMER4 	#   4
HandleUART2  	#   4
HandleLCD 		#   4
HandleDMA0		#   4
HandleDMA1		#   4
HandleDMA2		#   4
HandleDMA3		#   4
HandleMMC		#   4
HandleSPI0		#   4
HandleUART1		#   4
HandleRSV24		#   4
HandleUSBD		#   4
HandleUSBH		#   4
HandleIIC   	#   4
HandleUART0 	#   4
HandleSPI1 		#   4
HandleRTC 		#   4
HandleADC 		#   4

	MAP	(DRAM_END - 0x20)
pIrqStart		#	4
pIrqHandler		#	4
pIrqFinish		#	4
	EXPORT	pIrqStart
	EXPORT	pIrqHandler
	EXPORT	pIrqFinish
	
	END