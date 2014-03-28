#ifndef __BOARD_H
#define __BOARD_H

#include "../inc/def.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void __ENTRY(void);

void DisableInt(void);
void EnableInt(void);
void EnterCritical(U32 *);
void ExitCritical(U32 *);
void outportb(U8, U32);
void outportw(U16, U32);
void outportl(U32, U32);
U8  inportb(U32);
U16 inportw(U32);
U32 inportl(U32);

extern U32 SysRstVector;
extern U32 UdfInsVector;
extern U32 SwiSvcVector;
extern U32 InsAbtVector;
extern U32 DatAbtVector;
extern U32 ReservedVector;
extern U32 IrqSvcVector;
extern U32 FiqSvcVector;

void CacheDisable(void);
void CacheEnable(void);
void CacheFlush(void);

#define min(x1,x2) ((x1<x2)? x1:x2)
#define max(x1,x2) ((x1>x2)? x1:x2)
#define	abs(x)				(((x)>=0)?(x):-(x))
#define	abs_diff(x1, x2)	(((x1)>(x2))?((x1)-(x2)):((x2)-(x1)))

void PortInit(void);

void SystemClockInit(void);
U32  GetSysClock(SysClock *);
void SetSysClockPara(void *);
void GetSysClockPara(void *);
int  SetSysClock(void);
U32  GetCpuClock(void);
U32  GetMasterClock(void);

void SerialTxChar(char);
void SerialTxString(char *);
void SerialTxEmpty(void);
int  SerialRxReady(void);
char SerialRxKey(void);
char SerialRxChar(void);
int  SerialRxToBuf(char *);
void SerialChgBaud(U32);
U16  SerialSwitch(U16);
int Uart_GetIntNum(void) ;

int kbhit(void);
int getkey(void);
//#define	kbhit	SerialRxReady
//#define	getkey	SerialRxKey
void putch(char ch);
void puts(char *str);
char getch(void);
//#define	getch	SerialRxChar
//#define	putch	SerialTxChar
#define	putchar	putch
//#define	puts	SerialTxString

#define DebugOut	printf
#define	ERROR		printf

//led,key,buzzer,etc...
void Beep(U32 freq, U32 time);	//·äÃùÆ÷Ãù½Ð
void LedSet(U32 LedStatus);		//ËÄ¸öLED µãÁÁ/Ï¨Ãð×´Ì¬ÉèÖÃ
U32  LedGet(void);
void LedDisp(void);				//ÅÜÂíµÆ³ÌÐò
U16  GetKeyStatus(void);

#define	KEY1_DOWN()	(!(GetKeyStatus()&1))
#define	KEY2_DOWN()	(!(GetKeyStatus()&2))
#define	KEY3_DOWN()	(!(GetKeyStatus()&4))
#define	KEY4_DOWN()	(!(GetKeyStatus()&8))

//Timer
void TimerInit(U32);
void Delay(U32 time);
int  WaitEventWithTimeout(int (*event)(void), int cond, U32 ms);

//RTC timer
void RtcSetDay(TIME_STRUC *time);
void RtcSetWeek(TIME_STRUC *time);
void RtcSetTime(TIME_STRUC *time);
void RtcGetTime(TIME_STRUC *time);
void RtcAlarm(TIME_STRUC *time);

//
//extern void (*pNorFlashInit)(void);
//extern void (*pNorFlashProg)(U32, U32, U32);
void NorFlashInit(void);
void NorFlashStatusRep(void);
void NorFlashProg(U32 dst, U32 src, U32 size);
#define	NorFlashRead(dst, src, size)	memcpy((char *)(dst), (char *)(ROM_BASE+(src)), (int)(size))
U32 NFSaveParams(char *pEnv);
U32 NFSearchParams(char *pEnv);

//
int eth_init(void);
int arp_init(void);

//
void EnableIrq(int);
void DisableIrq(int);
void AckAndClrIrq(int);

//
void MemCfgInit(void);
//
void BoardInitStart(void);
void BoardInitEnd(void);
void BoardPrepareRun(void);

//Show boot information
void ShowBootInfo(void);

//Shell
void ShellIn(void);

#ifdef __cplusplus
}
#endif

#endif /*__BOARD_H*/
