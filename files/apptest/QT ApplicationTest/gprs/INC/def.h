#ifndef __DEF_H__
#define __DEF_H__

#define U32 unsigned int
#define U16 unsigned short
#define S32 int
#define S16 short int
#define U8  unsigned char
#define	S8  signed char

#define	BYTE	char
#define	WORD 	short
#define	DWORD	int
#define	UINT	U32
//#define	LPSTR	(U8 *)	//???
typedef U8 * LPSTR;
#define	BOOL	int
#define	USHORT	U16

#define TRUE 	1   
#define FALSE 	0

#define ON 	1   
#define OFF 	0

#define	NULL	(void *)0

#define	SIZE_1K		0x00000400
#define	SIZE_2K		0x00000800
#define	SIZE_4K		0x00001000
#define	SIZE_8K		0x00002000
#define	SIZE_16K	0x00004000
#define	SIZE_32K	0x00008000
#define	SIZE_64K	0x00010000
#define	SIZE_128K	0x00020000
#define	SIZE_256K	0x00040000
#define	SIZE_512K	0x00080000
#define	SIZE_1M		0x00100000
#define	SIZE_2M		0x00200000
#define	SIZE_4M		0x00400000
#define	SIZE_8M		0x00800000
#define	SIZE_16M	0x01000000
#define	SIZE_32M	0x02000000
#define	SIZE_64M	0x04000000
#define	SIZE_128M	0x08000000
#define	SIZE_256M	0x10000000
#define	SIZE_512M	0x20000000
#define	SIZE_1G		0x40000000
#define	SIZE_2G		0x80000000

#define	ENTER_KEY	0x0d
#define	BACK_KEY	0x08
#define BEEP_KEY	0x07
#define UP_KEY		0x41
#define DOWN_KEY	0x42
#define RIGHT_KEY	0x43
#define LEFT_KEY	0x44
#define HOME_KEY	0x48
#define END_KEY		0x4b
#define	ESC_KEY		0x1b

typedef struct{
	char *name;
	U32 freq;
}SysClock;

typedef struct{
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char weekday;
	unsigned char hour;
	unsigned char min;
	unsigned char sec;
}TIME_STRUC;

typedef struct{
	U32 vStart;
	U32 vEnd;
	U32 pStart;
	U32 attr;
}MMU_Table;

struct Partition{
	U32 offset;
	U32 size;
	char *name;
};

typedef struct {
	unsigned char flag[8];
	struct {
		unsigned long ip;
		unsigned long mask;
		unsigned long gate;
	}nic_cfg;
	unsigned long baud;
	unsigned int  current_uart;
	unsigned long clk_para[4];
	unsigned long prog_s_addr;
	unsigned long prog_r_addr;
	struct Partition NandPartition[8];
	unsigned char boot_params[256];
	unsigned long boot_key;
	unsigned long saved_in;
	unsigned long initrd_addr;
	unsigned long machine;
	unsigned char name[32];
	unsigned char leng_name;
	unsigned char web[32];
	unsigned char leng_web;
}EnvParams;

typedef int (*TEST_PROGRAM)(U32 a1, U32 a2, U32 a3 ,U32 a4);

typedef struct {
	TEST_PROGRAM entry;
	char *title;
	char *tip;
	U32 lcd_info;
} TEST_PROGRAM_ITEM;

#endif /*__DEF_H__*/

