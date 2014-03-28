/****************************************************************************
����  ��  ��  �ơ�GPRS_Q2403.C
����  ��  ��  ��������S3C2410A��demo�������
����  ��  ��  ����4.0
�������˼��������ڡ�icesoar//2002��11��19��19:26
���޸��˼��޸����ڡ�icesoar//2004-12-8 17:25
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


//����1�����жϴ���
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
������˵�������ڷ��������ַ������ȴ�����
****************************************************************************/
void GPRS_Cmd( char *pt )
{	
	int i=0;
//	char ch[1];

	while( pt[i] )
	{
		SerialSwitch( 1 ) ;		//ѡ��UARTͨ��Ϊ����1
	
		//if( pt[i]=='\n' )		SerialTxChar('\r');
		SerialTxChar( pt[i] );

		SerialSwitch( 0 ) ;		//ѡ��UARTͨ��Ϊ����0
	
		i++;
	}
	
	Delay(10);
	Echo_Rx_Data();
}

/****************************************************************************
������˵��������ģ���ͻص���Ϣ
****************************************************************************/
void GPRS_KeyUartPoll()
{
	char ch[1];

	//while( getkey() != ESC_KEY )
	{
		if(rUTRSTAT1 & 0x1)
		{
			SerialSwitch( 1 ) ;		//ѡ��UARTͨ��Ϊ����1
			//ch[0] = SerialRxChar() ;
			ch[0] = SerialRxKey();
			SerialSwitch( 0 ) ;		//ѡ��UARTͨ��Ϊ����0
			//SerialTxChar( ch[0] );
			if(ch[0])
				printf("%c", ch[0]);
		}
	}
}

/****************************************************************************
������˵�������ÿ���ƽ̨�Ĵ���1������
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

   	pISR_UART1 = (U32)Uart1RxInt;		//���ڽ��������ж�
	ClearSubPending(BIT_SUB_RXD1);
	ClearPending(BIT_UART1);
	EnableSubIrq(BIT_SUB_RXD1);
	EnableIrq(BIT_UART1);

	GPRS_Cmd("AT\n");
	Delay(500);
//	GPRS_Cmd("AT\n");
//	Delay(500);

//����ѡ��ͨ��1��ʹ�ô���˵Ķ���
	GPRS_Cmd("AT+SPEAKER=1\n"); //����ͨ��ͨ��Ϊ1
	Delay(500);
	GPRS_Cmd("AT+VGR=255\n");//�����ܻ����������
	Delay(500);
	GPRS_Cmd("AT+VGT=255\n");//����ͨ��1�Ļ�Ͳ����
	Delay(500);

//����ѡ��ͨ��0��ʹ����ͨ�绰����
/*
	GPRS_Cmd("AT+CHFA=0\n"); //����ͨ��ͨ��Ϊ0
	Delay(1000);
	GPRS_Cmd("AT+CLVL=100\n");//�����ܻ����������
	Delay(1000);
	GPRS_Cmd("AT+CMIC=0,10\n");//����ͨ��0�Ļ�Ͳ����
	Delay(1000);
*/
}

static void Test_GPRS_Exit(void)
{
   	DisableSubIrq(BIT_SUB_RXD1);
	DisableIrq(BIT_UART1);
}

/****************************************************************************
������˵�������͹һ�����ATH
****************************************************************************/
void GPRS_HOLD()
{
	GPRS_Cmd("AT\r");
	Delay(500);
	GPRS_Cmd("ATH\r");
}

/****************************************************************************
������˵�������ͽ�������ATA
****************************************************************************/
void GPRS_ANSWER()
{
	GPRS_Cmd("AT\r");
	Delay(500);
	GPRS_Cmd("ATA\r");
}

/****************************************************************************
������˵�������Ͳ�������ATD
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
������˵�������Ͷ���
****************************************************************************/
static void GPRS_MGS(char *number, char *text)
{
	GPRS_Cmd("AT\r");
	Delay(500);

	GPRS_Cmd("AT+CMGF=1\r");//�����޸��ַ�������,TEXTģʽ
	Delay(500);
	GPRS_Cmd("AT+CMGS=");	//���ͷ���������
	GPRS_Cmd(number);
	GPRS_Cmd("\n");
	
	GPRS_Cmd(text);
	
	SerialSwitch( 1 ) ;		//ѡ��UARTͨ��Ϊ����1
	SerialTxChar( 26 ); 	//"CTRL+Z"��ASCII��
	SerialSwitch( 0 ) ;		//ѡ��UARTͨ��Ϊ����0
	
	Delay(100);
	Echo_Rx_Data();
}

/****************************************************************************
������˵��������һ�����������绰����
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
			case ENTER_KEY:		//�����������
				//num[i++] = key;
				return i;
				break;
			default:		//�����������!!!
				printf( "�����������������!!!\n");
				return 0;
				break ;		
	    }
	}
}

/****************************************************************************
������˵����GPRSģ��Q2403ʵ�����
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
