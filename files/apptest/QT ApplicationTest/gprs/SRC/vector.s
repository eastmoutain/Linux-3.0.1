
USERMODE		EQU	0x10
FIQMODE			EQU	0x11
IRQMODE			EQU	0x12
SVCMODE			EQU	0x13
ABORTMODE		EQU	0x17
UNDEFMODE		EQU	0x1B
MODEMASK 		EQU	0x1F
I_BIT			EQU	0x80
F_BIT			EQU	0x40
T_BIT			EQU	0x20
NOINT	    	EQU	0xc0
;**********************************************************
;检查是否使用tasm.exe进行编译
	
 GBLL    THUMBCODE
    [ {CONFIG} = 16	
THUMBCODE SETL	{TRUE}
    CODE32
    |   
THUMBCODE SETL	{FALSE}
    ]

    [ THUMBCODE
    CODE32   ;for start-up code for Thumb mode
    ]
    
	MACRO		
	MOV_PC_LR
	[ THUMBCODE
    	bx lr
	|
		mov pc, lr
	]
	MEND
 	    
;******************************************************
	AREA	reset, CODE, READONLY

	ENTRY	
	
	EXPORT	__ENTRY
__ENTRY	
ResetEntry
	b	SYS_RST_HANDLER
	b	UDF_INS_HANDLER
	b	SWI_SVC_HANDLER
	b	INS_ABT_HANDLER
	b	DAT_ABT_HANDLER
	b	.
	b	IRQ_SVC_HANDLER
	b	FIQ_SVC_HANDLER

;******************************************************
	MACRO
$HandlerLabel HANDLER $HandleLabel
$HandlerLabel
	sub	sp,sp,#4        ;decrement sp(to store jump address)
	stmfd	sp!,{r0}        ;PUSH the work register to stack(lr does not push because it return to original address)
	ldr     r0,=$HandleLabel;load the address of HandleXXX to r0
	ldr     r0,[r0]         ;load the contents(service routine start address) of HandleXXX
	str     r0,[sp,#4]      ;store the contents(ISR) of HandleXXX to stack
	ldmfd   sp!,{r0,pc}     ;POP the work register and pc(jump to ISR)
	MEND
	
;UDF_INS_HANDLER
;	stmfd	sp!, {r0-r3, lr}
;	ldr	r0, =UdfInsVector
;	mov	lr, pc
;	ldr	pc, [r0]
;	ldmfd	sp!, {r0-r3, pc}^
;SWI_SVC_HANDLER
;	stmfd	sp!, {r0-r3, lr}
;	ldr	r0, =SwiSvcVector
;	mov	lr, pc
;	ldr	pc, [r0]
;	ldmfd	sp!, {r0-r3, pc}^
;INS_ABT_HANDLER
;	sub	lr, lr, #4
;	stmfd	sp!, {r0-r3, lr}
;	ldr	r0, =InsAbtVector
;	mov	lr, pc
;	ldr	pc, [r0]
;	ldmfd	sp!, {r0-r3, pc}^
;DAT_ABT_HANDLER
;	sub	lr, lr, #4
;	stmfd	sp!, {r0-r3, lr}
;	ldr	r0, =DatAbtVector
;	mov	lr, pc
;	ldr	pc, [r0]
;	ldmfd	sp!, {r0-r3, pc}^
;IRQ_SVC_HANDLER
;	sub	lr, lr, #4
;	stmfd	sp!, {r0-r12, lr}	
;	mrs	r0, spsr
;	stmfd	sp!, {r0}
;	ldr	r0, =IrqSvcVector
;	ldr	pc, [r0]	
;FIQ_SVC_HANDLER
;	sub	lr, lr, #4
;	stmfd	sp!, {r0-r12, lr}	
;	mrs	r0, spsr
;	stmfd	sp!, {r0}
;	ldr	r0, =FiqSvcVector
;	ldr	pc, [r0]

UDF_INS_HANDLER	HANDLER	UdfInsVector
SWI_SVC_HANDLER	HANDLER	SwiSvcVector
INS_ABT_HANDLER	HANDLER	InsAbtVector
DAT_ABT_HANDLER	HANDLER	DatAbtVector
IRQ_SVC_HANDLER	HANDLER	IrqSvcVector
FIQ_SVC_HANDLER	HANDLER	FiqSvcVector
				
;*******************************************************
SYS_RST_HANDLER
	mrs	r0, cpsr				;enter svc mode and disable irq,fiq
	bic	r0, r0, #MODEMASK
	orr	r0, r0, #(SVCMODE :OR: I_BIT :OR: F_BIT)
	msr	cpsr_c, r0
	
;	IMPORT	InitSystem
	b	InitSystem
	
InitSystem_exit	
	
;****************************************************	
;初始化堆栈
	;Do not use DRAM,such as stmfd,ldmfd......
	;SVCstack is initialized before
	;Under toolkit ver 2.50, 'msr cpsr,r1' can be used instead of 'msr cpsr_cxsf,r1'
	
	mrs	r0, cpsr
	bic	r0, r0, #(MODEMASK|NOINT)
	
	orr	r1, r0, #UNDEFMODE|NOINT
	msr	cpsr_cxsf, r1		;UndefMode
	ldr	sp, =UndefStack
	
	orr	r1, r0, #ABORTMODE|NOINT
	msr	cpsr_cxsf, r1		;AbortMode
	ldr	sp, =AbortStack
	
	orr	r1, r0, #IRQMODE|NOINT
	msr	cpsr_cxsf, r1		;IRQMode
	ldr	sp, =IRQStack
	
	orr	r1, r0, #FIQMODE|NOINT
	msr	cpsr_cxsf, r1		;FIQMode
	ldr	sp, =FIQStack	
		
;	orr	r1, r0, #SVCMODE		;enable irq,fiq
	orr	r1, r0, #SVCMODE|NOINT	;disable irq, fiq
	msr	cpsr_cxsf,r1		;SVCMode
	ldr	sp, =SVCStack

	;USER mode is not initialized.
	;未初始化用户模式栈,程序使用SVC模式

;****************************************************	
	adr	r0, ResetEntry
	ldr	r2, BaseOfROM
	cmp	r0, r2
	ldreq	r0, TopOfROM
	beq	InitRam	
	ldr r3, TopOfROM
0	
	ldmia	r0!, {r4-r7}
	stmia	r2!, {r4-r7}
	cmp	r2, r3
	bcc	%B0
	
	sub	r2, r2, r3
	sub	r0, r0, r2				
		
InitRam	
	ldr	r2, BaseOfBSS
	ldr	r3, BaseOfZero	
0
	cmp	r2, r3
	ldrcc	r1, [r0], #4
	strcc	r1, [r2], #4
	bcc	%B0	

	mov	r0,	#0
	ldr	r3,	EndOfBSS
1	
	cmp	r2,	r3
	strcc	r0, [r2], #4
	bcc	%B1
	
;****************************************************
;设置IQR处理程序入口, 在配置好RAM后设置	
;	IMPORT	IRQ_SERVICE

	ldr	r0, =IrqSvcVector	
	ldr	r1, =IRQ_SERVICE		
	str	r1, [r0]

;****************************************************

_main
__main
	EXPORT	_main
	EXPORT	__main
	
;	IMPORT	PortInit
;	IMPORT	TimerInit
;	IMPORT	LedDisp
;	bl	PortInit
;	ldr	r0, =0x1d20014
;	ldr	r1, [r0]
;0	
;	bic	r1, r1, #0xe
;	str	r1, [r0]
;	mov	r2, #0x100000
;1
;	subs	r2, r2, #1
;	bne	%B1
;	orr	r1, r1, #0xe
;	str	r1, [r0]
;	mov	r2, #0x100000
;2
;	subs	r2, r2, #1
;	bne	%B2
;	b	%B0	
	
;	bl	TimerInit
;1
;	bl	LedDisp
;	b	%B1
	
	ldr	lr, GotoMain
	MOV_PC_LR

	GBLS	MainEntry
MainEntry	SETS	"Main"
	IMPORT	$MainEntry

GotoMain	DCD	$MainEntry

	EXPORT DisableInt
DisableInt
	mrs	r0,	cpsr
	orr	r0,	r0, #NOINT
	msr	cpsr_cf, r0
	MOV_PC_LR
	
	EXPORT EnableInt
EnableInt
	mrs	r0,	cpsr
	bic	r0,	r0, #NOINT
	msr	cpsr_cf, r0
	MOV_PC_LR
	
;save cpsr and disable int, r0 = address to save cpsr
	EXPORT	EnterCritical
EnterCritical   
	mrs	r1, cpsr
	str	r1, [r0]
	orr	r1, r1, #NOINT
	msr	cpsr_cxsf, r1		
	MOV_PC_LR
;restore cpsr, r0 = address to restore cpsr	
	EXPORT	ExitCritical
ExitCritical
	ldr	r1, [r0]
	msr	cpsr_cxsf, r1	
	MOV_PC_LR	

	EXPORT	outportb
outportb	strb	r0, [r1]
	MOV_PC_LR
	
	EXPORT	outportw
outportw	strh	r0, [r1]
	MOV_PC_LR
	
	EXPORT	outportl
outportl	str	r0, [r1]
	MOV_PC_LR
	
	EXPORT	inportb
inportb	ldrb	r0, [r0]
	MOV_PC_LR

	EXPORT	inportw
inportw	ldrh	r0, [r0]
	MOV_PC_LR

	EXPORT	inportl
inportl	ldr	r0, [r0]
	MOV_PC_LR

;***********************************************
	IMPORT	|Image$$RO$$Base|	; ROM code start	
	IMPORT	|Image$$RO$$Limit|	; RAM data starts after ROM program
	IMPORT	|Image$$RW$$Base|	; Pre-initialised variables
	IMPORT	|Image$$ZI$$Base|	; uninitialised variables
	IMPORT	|Image$$ZI$$Limit|	; End of variable RAM space


BaseOfROM	DCD	|Image$$RO$$Base|
TopOfROM	DCD	|Image$$RO$$Limit|
BaseOfBSS	DCD	|Image$$RW$$Base|
BaseOfZero	DCD	|Image$$ZI$$Base|
EndOfBSS	DCD	|Image$$ZI$$Limit|
	
;***********************************************

;	IMPORT	UserStack
;	IMPORT	SVCStack
;	IMPORT	UndefStack
;	IMPORT	AbortStack
;	IMPORT	IRQStack
;	IMPORT	FIQStack
	
;	IMPORT	SysRstVector
;	IMPORT	UdfInsVector
;	IMPORT	SwiSvcVector
;	IMPORT	InsAbtVector
;	IMPORT	DatAbtVector
;	IMPORT	ReservedVector
;	IMPORT	IrqSvcVector
;	IMPORT	FiqSvcVector
	
;***********************************************	
	
	END