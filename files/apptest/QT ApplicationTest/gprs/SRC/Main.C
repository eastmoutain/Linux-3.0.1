/****************************************************************************
【文  件  名  称】main.c
【功  能  描  述】三星S3C2410A板demo程序代码
【程  序  版  本】4.0
【创建人及创建日期】icesoar//2002年11月19日19:26
【修改人及修改日期】icesoar//2004-12-8 17:25
****************************************************************************/
#include "def.h"
#include "2410addr.h"
#include "config.h"
#include "board.h"
#include "utils.h"

extern void Test_GPRS_Q2403(void);
/*************************************************************/
void Main(void)
{

	BoardInitStart();
	SystemClockInit();
	TimerInit(TIMER_FREQ);
	MemCfgInit();
	PortInit();

	SerialSwitch(0);
	SerialChgBaud(115200);


	while( 1 )
	{
	printf("please Enter any key to run test\n");
	getch();
	Test_GPRS_Q2403();
	}
}