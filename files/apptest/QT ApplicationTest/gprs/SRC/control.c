#include "../inc/def.h"
#include "../inc/config.h"
#include "../inc/board.h"
#include "../inc/slib.h"
#include "../inc/utils.h"
#include "2410addr.h"

EnvParams Env;

#define	ROM_SIZE	SIZE_2M

void PortInit(void)
{
    //CAUTION:Follow the configuration order for setting the ports. 
    // 1) setting value(GPnDAT) 
    // 2) setting control register  (GPnCON)
    // 3) configure pull-up resistor(GPnUP)  

    //32bit data bus configuration  
    //*** PORT A GROUP
    //Ports  : GPA22 GPA21  GPA20 GPA19 GPA18 GPA17 GPA16 GPA15 GPA14 GPA13 GPA12  
    //Signal : nFCE   OUT   nFRE   nFWE  ALE   CLE  nGCS5 nGCS4 nGCS3 nGCS2 nGCS1 
    //Binary :  1     0      1  , 1   1   1    1   ,  1     1     1     1
    //Ports  : GPA11   GPA10  GPA9   GPA8   GPA7   GPA6   GPA5   GPA4   GPA3   GPA2   GPA1  GPA0
    //Signal : ADDR26 ADDR25 ADDR24 ADDR23 ADDR22 ADDR21 ADDR20 ADDR19 ADDR18 ADDR17 ADDR16 ADDR0 
    //Binary :  1       1      1      1   , 1       1      1      1   ,  1       1     1      1
    rGPACON = 0x5fffff ; 

    //**** PORT B GROUP
    //Ports  : GPB10    GPB9    GPB8    GPB7    GPB6     GPB5    GPB4   GPB3   GPB2     GPB1      GPB0
    //Signal : nXDREQ0 nXDACK0 nXDREQ1 nXDACK1 nSS_KBD nDIS_OFF L3CLOCK L3DATA L3MODE nIrDATXDEN Keyboard
    //Setting: INPUT  OUTPUT   INPUT  OUTPUT   INPUT   OUTPUT   OUTPUT OUTPUT OUTPUT   OUTPUT    OUTPUT 
    //Binary :   00  ,  01       00  ,   01      00   ,  01       01  ,   01     01   ,  01        01  
    rGPBCON = 0x044555 ;
    rGPBUP  = 0x7ff ;     // The pull up function is disabled GPB[10:0]

    //*** PORT C GROUP
    //Ports  : GPC15 GPC14 GPC13 GPC12 GPC11 GPC10 GPC9 GPC8  GPC7   GPC6   GPC5 GPC4 GPC3  GPC2  GPC1 GPC0
    //Signal : VD7   VD6   VD5   VD4   VD3   VD2   VD1  VD0 LCDVF2 LCDVF1 LCDVF0 VM VFRAME VLINE VCLK LEND  
    //Binary :  10   10  , 10    10  , 10    10  , 10   10  , 10     10  ,  10   10 , 10     10 , 10   10
    rGPCCON = 0xaaaaaaaa;       
    rGPCUP  = 0xffff;     // The pull up function is disabled GPC[15:0] 

    //*** PORT D GROUP
    //Ports  : GPD15 GPD14 GPD13 GPD12 GPD11 GPD10 GPD9 GPD8 GPD7 GPD6 GPD5 GPD4 GPD3 GPD2 GPD1 GPD0
    //Signal : VD23  VD22  VD21  VD20  VD19  VD18  VD17 VD16 VD15 VD14 VD13 VD12 VD11 VD10 VD9  VD8
    //Binary : 10    10  , 10    10  , 10    10  , 10   10 , 10   10 , 10   10 , 10   10 ,10   10
    rGPDCON = 0xaaaaaaaa;       
    rGPDUP  = 0xffff;     // The pull up function is disabled GPD[15:0]

    //*** PORT E GROUP
    //Ports  : GPE15  GPE14 GPE13   GPE12   GPE11   GPE10   GPE9    GPE8     GPE7  GPE6  GPE5   GPE4  
    //Signal : IICSDA IICSCL SPICLK SPIMOSI SPIMISO SDDATA3 SDDATA2 SDDATA1 SDDATA0 SDCMD SDCLK I2SSDO 
    //Binary :  10     10  ,  10      10  ,  10      10   ,  10      10   ,   10    10  , 10     10  ,     
    //-------------------------------------------------------------------------------------------------------
    //Ports  :  GPE3   GPE2  GPE1    GPE0    
    //Signal : I2SSDI CDCLK I2SSCLK I2SLRCK     
    //Binary :  10     10  ,  10      10 
    rGPECON = 0xa66aaaaa;	//GPE11 input, GPE13 output
    rGPEUP  = 0xffff;		// The pull up function is disabled GPE[15:0]
    rGPEDAT = 0;		//GPE11,13 output 0

    //*** PORT F GROUP
    //Ports  : GPF7   GPF6   GPF5   GPF4      GPF3     GPF2  GPF1   GPF0
    //Signal : nLED_8 nLED_4 nLED_2 nLED_1 nIRQ_PCMCIA EINT2 KBDINT EINT0
    //Setting: Output Output Output Output    EINT3    EINT2 EINT1  EINT0
    //Binary :  01      01 ,  01     01  ,     10       10  , 10     10
    rGPFCON = 0x5500;	// GPF0~3 input
    rGPFUP  = 0xff;     // The pull up function is disabled GPF[7:0]

    //*** PORT G GROUP
    //Ports  : GPG15 GPG14 GPG13 GPG12 GPG11    GPG10    GPG9     GPG8     GPG7      GPG6    
    //Signal : nYPON  YMON nXPON XMON  EINT19 DMAMODE1 DMAMODE0 DMASTART KBDSPICLK KBDSPIMOSI
    //Setting: nYPON  YMON nXPON XMON  Input  Intput   Input   	Input	 SPICLK1   SPIMOSI1
    //Binary :   11    11 , 11    11  , 00      00    ,   00       00   ,    11         11
    //-----------------------------------------------------------------------------------------
    //Ports  :    GPG5       GPG4    GPG3    GPG2    GPG1    GPG0    
    //Signal : KBDSPIMISO LCD_PWREN EINT11 nSS_SPI IRQ_LAN IRQ_PCMCIA
    //Setting:  SPIMISO1  LCD_PWRDN Input   Input   Input    Input
    //Binary :     11         11   ,  00      00  ,  00        00
    rGPGCON = 0xff001318;	//GPG0,1,3 input, GPG2,6 output GPG5,7,8,9,10,11 input
    rGPGUP  = 0xffff;	// The pull up function is disabled GPG[15:0]
	rGPGDAT = 0;	//GPG2,6 output0

    //*** PORT H GROUP
    //Ports  :  GPH10    GPH9  GPH8 GPH7  GPH6  GPH5 GPH4 GPH3 GPH2 GPH1  GPH0 
    //Signal : CLKOUT1 CLKOUT0 UCLK nCTS1 nRTS1 RXD1 TXD1 RXD0 TXD0 nRTS0 nCTS0
    //Binary :   10   ,  10     10 , 11    11  , 10   10 , 10   10 , 10    10
    rGPHCON = 0x2afaaa;
    //rGPHUP  = 0x7ff;    // The pull up function is disabled GPH[10:0]
    rGPHUP  = 0x000;    // The pull up function is enabled GPH[10:0]
    
    //External interrupt will be falling edge triggered. 
    rEXTINT0 = 0x22222222;    // EINT[7:0]
    rEXTINT1 = 0x22222242;    // EINT[15:8],EINT9 rising edge
    rEXTINT2 = 0x22222222;    // EINT[23:16]
}


void MemCfgInit(void)
{
	//rCLKCON |= 0xffff0;
	
	//enable nand flash control, initilize ecc, chip disable,
	rNFCONF = (1<<15)|(1<<12)|(1<<11)|(7<<8)|(7<<4)|(7);	
}

#include "../inc/mmu.h"

/*
SDRAM地址范围:0x30000000~0x33ffffff 共64M
0x30000000~0x337fffff为非cache区,可用作LCD缓冲,
USB的DMA方式接收数据的缓冲和音频输入输出DMA缓冲及其它DMA方式的实验
0x33800000~0x33ffffff为cache区,可为程序及变量和栈空间
*/
//以M对齐
static MMU_Table mmu_table[] = {
	{0x00000000, 0x00100000, DRAM_END-SIZE_1M, RW_CB}, //inter-rom ram
//	{0x00000000, 0x00100000, (U32)__ENTRY, RW_CB}, //inter-rom ram
//!!! Important note, redirect IRQ vector to reset entry !!!
	{0x08000000, 0x0ff00000, 0x00000000, RW_NCNB}, //bank0
	{0x10000000, 0x17f00000, 0x10000000, RW_NCNB}, //bank2	
	{0x18000000, 0x1ff00000, 0x18000000, RW_NCNB}, //bank3
	{0x20000000, 0x27f00000, 0x20000000, RW_NCNB}, //bank4
	{0x28000000, 0x2ff00000, 0x28000000, RW_NCNB}, //bank5
	{0x30000000, 0x33800000, 0x30000000, (AP_RO|DOMAIN0|NCNB|DESC_SEC)},   //bank6-1
	{0x33800000, 0x33f00000, 0x33800000, RW_CB},   //bank6-2
	{0x38000000, 0x3ff00000, 0x38000000, RW_NCNB}, //bank7	
	{0x40000000, 0x5af00000, 0x40000000, RW_NCNB}, //SFR
	{0x5b000000, 0x7ff00000, 0x5b000000, RW_FAULT}, //not used
	{0x80000000, 0x87f00000, 0x08000000, RW_NCNB}, //bank1
	{0x88000000, 0xfff00000, 0x88000000, RW_FAULT}, //not used
	{0, 0, 0, 0}
};

void BoardInitStart(void)
{
	MMU_Init(mmu_table);
	memcpy((char *)(DRAM_END-SIZE_1M), (char *)__ENTRY, 0x1000);
}

void BoardInitEnd(void)
{
}

void CacheDisable(void)
{
	MMU_DisableDCache();
}

void CacheEnable(void)
{
	MMU_EnableDCache();
}

void CacheFlush(void)
{
	MMU_DCacheCleanInvalidateAll();
}

void EnableIrq(int bit)
{
	rINTMSK &= ~(bit);
}

void DisableIrq(int bit)
{
	rINTMSK |= (bit);
}

/***********************下面是时钟相关函数**********************************/


#define	EXT_OSC_CLK	12000000

static struct{
	U32 mclk;
	U32 pclk;
	U32 sclk;
	U32 freq;
} ClkPara;

static U32 clk_div_val;

static void ChangeClockDivider(void)
{
     // hdivn,pdivn FCLK:HCLK:PCLK
     //     0,0         1:1:1 
     //     0,1         1:1:2 
     //     1,0         1:2:2
     //     1,1         1:2:4
    rCLKDIVN = clk_div_val ;//(hclk_div<<1) | pclk_div;

    if(clk_div_val&2)
        MMU_SetAsyncBusMode();
    else 
        MMU_SetFastBusMode();
}

static void set_pll(void)
{
	U32 old_freq;
	
	if(ClkPara.mclk>255)
		ClkPara.mclk = 255;
	if(ClkPara.pclk>63)
		ClkPara.pclk = 63;
	if(ClkPara.sclk>3)
		ClkPara.sclk = 3;
	old_freq = ClkPara.freq;
	ClkPara.freq = (EXT_OSC_CLK*(ClkPara.mclk+8))/((ClkPara.pclk+2)<<ClkPara.sclk);
	if((ClkPara.freq>=270000000)||(ClkPara.freq<5*EXT_OSC_CLK)) {
		ClkPara.mclk = 192;
		ClkPara.pclk = 4;
		ClkPara.sclk = 1;
		ClkPara.freq = EXT_OSC_CLK*180U/12U;
	}
	
	clk_div_val = 0;
	if(ClkPara.freq>=80000000) {
		if(ClkPara.freq>=120000000) {
			clk_div_val |= 2;
			if(ClkPara.freq>=160000000)
				clk_div_val |= 1;
		} else
			clk_div_val |= 1;		//80~120MHz
	}
	
	if(old_freq<ClkPara.freq)
		ChangeClockDivider();
	rMPLLCON = (ClkPara.mclk << 12) | (ClkPara.pclk << 4) | ClkPara.sclk;
	ChangeClockDivider();
}

void SystemClockInit(void)
{
	ClkPara.mclk = 192;
	ClkPara.pclk = 4;
	ClkPara.sclk = 1;
	set_pll();
}

U32 GetCpuClock(void)
{
	return ClkPara.freq;
}

U32 GetMasterClock(void)
{
	U32 clk;
	
	clk = GetCpuClock();
	
	if(rCLKDIVN&2)
		clk >>= 1;
		
	if(rCLKDIVN&1)
		clk >>= 1;
		
	return clk;
}


U32 GetSysClock(SysClock pSysClock[])
{
	pSysClock[0].name = "CPU";
	pSysClock[0].freq = GetCpuClock();
	pSysClock[1].name = "HCLK";
	pSysClock[1].freq = GetCpuClock()>>((rCLKDIVN&2)>>1);
	pSysClock[2].name = "PCLK";
	pSysClock[2].freq = GetMasterClock();

	return 3;
}

void SetSysClockPara(void *addr)
{
	U32 *pData = addr;
	
	ClkPara.mclk = pData[0];
	ClkPara.pclk = pData[1];
	ClkPara.sclk = pData[2];
	
	set_pll();
}

void GetSysClockPara(void *addr)
{
	U32 *pData = addr;
	
	pData[0] = ClkPara.mclk;
	pData[1] = ClkPara.pclk;
	pData[2] = ClkPara.sclk;
	pData[3] = ClkPara.freq;
}

void TimerInit(U32 HZ)
{
	rTCFG0 &= 0xffff00ff;
	rTCFG0 |= 1<<8;					//1/2 prescaler
	rTCFG1 &= 0xfff0ffff;
	rTCFG1 |= 3<<16;				//mux = 1/16
	rTCNTB4 = GetMasterClock()/( HZ*2*16 ) - 1 ;
	rTCON  &= 0xff0fffff;			//stop Timer4
	rTCON  |= 0x00700000;			//auto-reload, update TCNTB4, start Timer4
	rTCON  &= 0xffdfffff;
}

void Delay(U32 ms)
{
	U16 i;
	
	i = rTCNTB4>>1;		//1000us/2	
	rTCON &= ~(1<<20);
	rTCON |= (1<<20);	//停止再启动,重装初值,减计数
	
	while(ms--) {
		while(rTCNTO4>=i);
		while(rTCNTO4<i);
	}
}
/***************************************************************************************************/
/************************下面是串口通讯相关函数***********************************************************/
/***************************************************************************************************/


static U16 SerialPortSel;

U16 SerialSwitch(U16 port)
{
#ifdef	SERIAL_PORTS_SWITCH
//	U16 old_sel = SerialPortSel;
	
	SerialPortSel = port?1:0;
#else
	SerialPortSel = 0;
#endif
	return SerialPortSel;
}

void SerialChgBaud(U32 baud)
{
	U32 mclk =  GetMasterClock();
	
	rUFCON0 = 0x0;		//FIFO disable
	rUFCON1 = 0x0;
	rUMCON0 = 0x0;
	rUMCON1 = 0x0;

//UART0
//	rULCON0  = 0x7;		//Normal,No parity,2 stop,8 bit
	rULCON0  = 0x3;		//Normal,No parity,1 stop,8 bit
	rUCON0   = 0x245;	//rx=edge,tx=level,disable timeout int.,enable rx error int.,normal,interrupt or polling
	rUBRDIV0 = ((int)(mclk/16./baud + 0.5) -1);

//UART1
//	rULCON1  = 0x7;		//Normal,No parity,2 stop,8 bit
	rULCON1  = 0x3;
	rUCON1   = 0x245;
	rUBRDIV1 = ((int)(mclk/16./baud + 0.5) -1);
}

void SerialTxEmpty(void)
{
//	if(SerialPortSel)
		while(!(rUTRSTAT1 & 0x4)); //wait until tx shifter is empty.
//	else
		while(!(rUTRSTAT0 & 0x4));	//Wait until tx shifter is empty.

}

void SerialTxChar(char data)
{
	if(SerialPortSel) {
		if(data=='\n') {
			while(!(rUTRSTAT1 & 0x4));
	    	//Delay(1);	//because the slow response of hyper_terminal 
			WrUTXH1('\r');
		}
		while(!(rUTRSTAT1 & 0x4)); //Wait until THR is empty.
//		Delay(1);
		WrUTXH1(data);
    } else {
		if(data=='\n') {
			while(!(rUTRSTAT0 & 0x4));
			//Delay(1);	//because the slow response of hyper_terminal 
			WrUTXH0('\r');
		}
		while(!(rUTRSTAT0 & 0x4));  //Wait until THR is empty.
//		Delay(1);
		WrUTXH0(data);
    }
}

int SerialRxReady(void)
{
	if(SerialPortSel)
		return (rUTRSTAT1 & 0x1);	//Receive data ready
	else 
		return (rUTRSTAT0 & 0x1);	//Receive data ready
}

char SerialRxKey(void)
{
	if(SerialPortSel) {
		if((rUTRSTAT1 & 0x1)) //Receive data ready
			return RdURXH1();
	} else {
		if((rUTRSTAT0 & 0x1)) //Receive data ready
			return RdURXH0();
	}
	return 0;
}

char SerialRxChar(void)
{
	if(SerialPortSel) {
		while(!(rUTRSTAT1 & 0x1)); //Receive data ready
		return RdURXH1();
	} else {
		while(!(rUTRSTAT0 & 0x1)); //Receive data ready
		return RdURXH0();
	}
}

int SerialRxToBuf(char *b)
{
	if(SerialPortSel) {
		if(rUTRSTAT1 & 0x1)    //Receive data ready
			*b = RdURXH1();
		else
		    return 0;
    } else {
		if(rUTRSTAT0 & 0x1)    //Receive data ready
		    *b = RdURXH0();
		else
		    return 0;
    }
    
    return 1;
}

void SerialTxString(char *s)
{
	 while(*s)
		SerialTxChar(*s++);
}


//*****************************************************************************
//get a number for the uart
//*****************************************************************************
int Uart_GetIntNum(void)
{
    char string[256] ;
    char *p_string = string ;
    char c;
    int i = 0 ;
    int data = 0 ;

    while(   (c=getch()/*SerialRxChar()*/) != '\r'  )
    {
		if(c=='\b')		p_string--;
		else		*p_string++=c;
		//printf("get input:");
		putch(c)/*SerialTxChar( c )*/ ;
    }

    *p_string = '\0';

	i = 0 ;
	while( string[i] != '\0' )
	{
		data = data * 10 ;
		if( string[i]<'0'||string[i]>'9' )
			return -1 ;
		data = data + ( string[i]-'0' ) ;
		i++ ;		
	}	
	
	return data ;
}
//*****************************************************************************


