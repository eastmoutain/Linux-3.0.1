/****************************************************************************
【文  件  名  称】GPRS_Q2403.C
【功  能  描  述】三星S3C2410A板demo程序代码
【程  序  版  本】4.0
【创建人及创建日期】icesoar//2002年11月19日19:26
【修改人及修改日期】icesoar//2004-12-8 17:25
****************************************************************************/

//***************************************************************************
#include "def.h"
#include "2410addr.h"
#include "config.h"
#include "board.h"
#include "utils.h"

//extern unsigned char LoadEnv_OK ;
//extern EnvParams Env;
//***************************************************************************

#define	RX_BUF_SIZE		1024
static char rx_buf[RX_BUF_SIZE];
static U16 rx_buf_head, rx_buf_tail;

#define	RX_BUF_EMPTY()	(rx_buf_head==rx_buf_tail)
#define	RX_BUF_INC()	(rx_buf_head = (rx_buf_head+1)&(RX_BUF_SIZE-1));
#define	RX_BUF_DEC()	(rx_buf_tail = (rx_buf_tail+1)&(RX_BUF_SIZE-1));


//串口1接收中断处理
static void __irq Uart1RxInt(void)
{
    ClearSubPending(BIT_SUB_RXD1); //rSUBSRCPND = BIT_SUB_RXD0;          //Clear pending bit (Requested)
    ClearPending(BIT_UART1);

	//printf("URT1 rx interrupt!\n");
	rx_buf[rx_buf_head] = RdURXH1();
	RX_BUF_INC();
	if(RX_BUF_EMPTY())
		RX_BUF_DEC();
}

static void Echo_Rx_Data(void)
{
	while(!RX_BUF_EMPTY()) {
		putch(rx_buf[rx_buf_tail]);
		RX_BUF_DEC();
	}
}

/****************************************************************************
【功能说明】串口发送命令字符串并等待回显
****************************************************************************/
void GPRS_Cmd( char *pt )
{	
	int i=0;
//	char ch[1];

	while( pt[i] )
	{
		SerialSwitch( 1 ) ;		//选择UART通道为串口1
	
		//if( pt[i]=='\n' )		SerialTxChar('\r');
		SerialTxChar( pt[i] );

		SerialSwitch( 0 ) ;		//选择UART通道为串口0
	
		i++;
	}
	
	Delay(10);
	Echo_Rx_Data();
}

/****************************************************************************
【功能说明】回显模块送回的信息
****************************************************************************/
void GPRS_KeyUartPoll()
{
	char ch[1];

	//while( getkey() != ESC_KEY )
	{
		if(rUTRSTAT1 & 0x1)
		{
			SerialSwitch( 1 ) ;		//选择UART通道为串口1
			//ch[0] = SerialRxChar() ;
			ch[0] = SerialRxKey();
			SerialSwitch( 0 ) ;		//选择UART通道为串口0
			//SerialTxChar( ch[0] );
			if(ch[0])
				printf("%c", ch[0]);
		}
	}
}

/****************************************************************************
【功能说明】设置开发平台的串口1波特率
****************************************************************************/
void Test_GPRS_Init()
{ 
	printf("Initialize GPRS modem...\n");
	
	rGPGCON &= ~((3<<4)|(3<<12));
	rGPGCON |= (1<<4)|(1<<12);
	rGPGDAT &= ~(1<<2);
	rGPGDAT &= ~(1<<6);
	
	rGPHCON |= 0xf<<12;		//RTS1, CTS1
    rGPHUP  |= 3<<6;		//Uart port pull-up disable

	SerialChgBaud( 115200 ) ;
		
	rx_buf_head = rx_buf_tail = 0;

   	pISR_UART1 = (U32)Uart1RxInt;		//串口接收数据中断
	ClearSubPending(BIT_SUB_RXD1);
	ClearPending(BIT_UART1);
	EnableSubIrq(BIT_SUB_RXD1);
	EnableIrq(BIT_UART1);

	GPRS_Cmd("AT\n");
	Delay(500);
//	GPRS_Cmd("AT\n");
//	Delay(500);

//下面选择通道1，使用带麦克的耳机
	GPRS_Cmd("AT+SPEAKER=1\n"); //设置通话通道为1
	Delay(500);
	GPRS_Cmd("AT+VGR=255\n");//设置受话器音量最大
	Delay(500);
	GPRS_Cmd("AT+VGT=255\n");//设置通道1的话筒增益
	Delay(500);

//下面选择通道0，使用普通电话话柄
/*
	GPRS_Cmd("AT+CHFA=0\n"); //设置通话通道为0
	Delay(1000);
	GPRS_Cmd("AT+CLVL=100\n");//设置受话器音量最大
	Delay(1000);
	GPRS_Cmd("AT+CMIC=0,10\n");//设置通道0的话筒增益
	Delay(1000);
*/
}

static void Test_GPRS_Exit(void)
{
   	DisableSubIrq(BIT_SUB_RXD1);
	DisableIrq(BIT_UART1);
}

/****************************************************************************
【功能说明】发送挂机命令ATH
****************************************************************************/
void GPRS_HOLD()
{
	GPRS_Cmd("AT\r");
	Delay(500);
	GPRS_Cmd("ATH\r");
}

/****************************************************************************
【功能说明】发送接听命令ATA
****************************************************************************/
void GPRS_ANSWER()
{
	GPRS_Cmd("AT\r");
	Delay(500);
	GPRS_Cmd("ATA\r");
}

/****************************************************************************
【功能说明】发送拨打命令ATD
****************************************************************************/
void GPRS_CALL(char *number)
{
	GPRS_Cmd("AT\r");
	Delay(500);
	GPRS_Cmd("ATD"); 
	GPRS_Cmd(number);
	GPRS_Cmd(";\r");
}

/****************************************************************************
【功能说明】发送短信
****************************************************************************/
static void GPRS_MGS(char *number, char *text)
{
	GPRS_Cmd("AT\r");
	Delay(500);

	GPRS_Cmd("AT+CMGF=1\r");//发送修改字符集命令,TEXT模式
	Delay(500);
	GPRS_Cmd("AT+CMGS=");	//发送发短信命令
	GPRS_Cmd(number);
	GPRS_Cmd("\n");
	
	GPRS_Cmd(text);
	
	SerialSwitch( 1 ) ;		//选择UART通道为串口1
	SerialTxChar( 26 ); 	//"CTRL+Z"的ASCII码
	SerialSwitch( 0 ) ;		//选择UART通道为串口0
	
	Delay(100);
	Echo_Rx_Data();
}

/****************************************************************************
【功能说明】输入一组数字用作电话号码
****************************************************************************/
static int InputNumber(char *num)
{
	int key;
	int i=0;
	
	for(i=0; i<20; i++)
		num[i] = 0;
	i = 0;
	
	printf("Please input the number:\n");
	while(1)
	{
		key = getch();
		switch(key)
		{
		    case '0':
		    case '1':
		    case '2':
		    case '3':
		    case '4':
		    case '5':
		    case '6':
		    case '7':
		    case '8':
		    case '9':
		    	num[i++] = key;
				printf("%c",key);
				break;
			case ENTER_KEY:		//数字输入完毕
				//num[i++] = key;
				return i;
				break;
			default:		//数字输入错误!!!
				printf( "输入错误，请重新输入!!!\n");
				return 0;
				break ;		
	    }
	}
}

/****************************************************************************
【功能说明】GPRS模块Q2403实验程序
****************************************************************************/
void Test_GPRS_Q2403(void)
{
	U16 key ;
	char number[20];
	char Message[64] = {"Hello! "} ;
	
	//if( LoadEnv_OK == 1 )
	//for( key = 0; key < Env.leng_web; key++ )
	//{
	//	Message[7+key] =  Env.web[key] ;
	//}
	//Message[7+Env.leng_web] = 0 ;
	//printf( "%s\n", Message );
	
	Test_GPRS_Init();
	
Test_Again:
	printf( "\nGSM/GPRS TEST, press ESC key to exit !\n" ) ;
	printf(" 1 : Send short message\n");
	printf(" 2 : Call the number\n");
	printf(" 3 : Ring off\n");
	printf(" 4 : Pick up\n");
   
	while(1)
	{
		key = getkey();
		if(key==ESC_KEY)
			break;
/*		if(key) {
			putch(key);
			WrUTXH1(key);
		}
*/		
		Echo_Rx_Data();
		
		switch( key )
		{
			case '1': printf("Send short message\t\t\n");
				if( !InputNumber(number) )break;
				printf("\nNow send short message...\n");
				GPRS_MGS( number, Message );
				//printf("\n");
				//break;
				goto Test_Again;
      		case '2': printf("Call the number\t\t\n");
                if( !InputNumber(number) )		break;
                printf("\nNow send a call...\n");
                GPRS_CALL(number);
                //printf("\n");
                //break;
                goto Test_Again;
      		case '3': printf("Ring off\t\t\n");
                GPRS_HOLD();
                //break;
                goto Test_Again;
      		case '4': printf("Pick up\t\t\n");
                GPRS_ANSWER();
                //break;
                goto Test_Again;
		}
 	}
	
    Test_GPRS_Exit();
}
