;===========================================
; NAME: OPTION.A
; DESC: Configuration options for .S files
; HISTORY:
; 02.28.2002: ver 0.0
;===========================================

;SDRAM_END			EQU	0x34000000

		GBLL 	PLL_ON_START  
PLL_ON_START	SETL 	{TRUE}


		GBLL	ENDIAN_CHANGE
ENDIAN_CHANGE	SETL	{FALSE}

		GBLA	ENTRY_BUS_WIDTH
ENTRY_BUS_WIDTH	SETA	16	


;BUSWIDTH = 16,32
		GBLA    BUSWIDTH	;max. bus width for the GPIO configuration
BUSWIDTH	SETA    32


		GBLA	FCLK
FCLK		SETA	50000000

	[ FCLK = 50000000	
M_MDIV		EQU	92	;Fin=12.0MHz Fout=100.0MHz
M_PDIV		EQU	4
M_SDIV		EQU	1
    	]

	END
