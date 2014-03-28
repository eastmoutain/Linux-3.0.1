#include "def.h"

extern int  SerialRxReady(void);
extern char SerialRxKey(void);


unsigned short ntohs(unsigned short s)
{
	return (s >> 8) | (s << 8);
}

unsigned long ntohl(unsigned long l)
{
	return  ((l >> 24) & 0x000000ff) |
		((l >>  8) & 0x0000ff00) |
		((l <<  8) & 0x00ff0000) |
		((l << 24) & 0xff000000);
}

unsigned short htons(unsigned short s)
{
	return (s >> 8) | (s << 8);
}

unsigned long htonl(unsigned long l)
{
	return ntohl(l);
}

/*unsigned char strupr( char *s )		//将一组字符串里面的小写字母变为大写
{
	while (*s != '\0') 
	{
		if (*s >= 'a' && *s <= 'z')
			*s = *s - 32;
		s++ ;
	}
	
	return 1 ;
}*/


char *strupr( char *Str )		//将一组字符串里面的小写字母变为大写
{
	char *cp;
	cp = Str;
	
	while (*cp != 0)
	{
		if (*cp >= 'a' && *cp <= 'z' )
		{
			*cp -= 'a' - 'A';
		}
	
		cp++;
	}
	
	return Str;
}


unsigned long strtobcd(char *s)
{
	unsigned long ret;
	int i;

	ret = 0;

	while (*s != '\0') {
		if (*s >= '0' && *s <= '9')
			i = *s - '0';
		else
			return -1;
		ret = (ret << 4) + i;
		s++;
	}

	return ret;
}

unsigned long strtodec(char *str, int cnt)
{
	unsigned long i, data = 0;	
	
	for(i=0; i<cnt; i++)
	{
		data *= 10;
		if(str[i]<'0'||str[i]>'9')
			return -1;
		data += str[i]-'0';			
	}	
	return data;
}

void ultostr(char *s, unsigned long data)
{
	int i;
	
	s[8] = 0;
	for(i=7; i>=0; i--, data >>=4)
	{
		if((data&0xf)<=9)
			s[i] = (data&0xf)+'0';
		else
			s[i] = (data&0xf)+'a'-0x0a;
	}	
}

#if 0

#include "utils.h"

unsigned long strtoul(char *s)
{
	unsigned long ret;
	int i;

	ret = 0;

	while (*s != '\0') {
		if (*s >= '0' && *s <= '9')
			i = *s - '0';
		else if (*s >= 'a' && *s <= 'f')
			i = *s - 'a' + 0xa;
		else if (*s >= 'A' && *s <= 'F')
			i = *s - 'A' + 0xa;
		else
			return -1;
		ret = (ret << 4) + i;
		s++;
	}

	return ret;
}

void putch(char ch)
{
	SerialTxChar(ch);
}

void puts(char *str)
{
	SerialTxString(str);
}

int kbhit(void)
{
	if(SerialRxReady())
		return 1;
	return ScanKeyDown();
}

int getkey(void)
{
	int c;
	
	c = SerialRxKey();
	if(!c)
		return GetScanKey();
}

char getch(void)
{
	int c;
	
	while(1) {
		c = getkey();
		if(c)
			return c;
	}
	//return SerialRxChar();
}

void memcpy(void *s1, const void *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
		((char *)(s1))[i] = ((const char *)(s2))[i];
}

void memset(void *s, const char ch, int n)
{
	int i;

	for (i = 0; i < n; i++)
		((char *)(s))[i] = ch;
}

int strlen(const char *s)
{
	int i = 0;

	for(; *s; s++)
		i++;
	
	return i;
}

int strncmp(const char *s1, const char *s2, int maxlen)
{
	int i;

	for(i = 0; i < maxlen; i++) {
		if(s1[i] != s2[i])
			return ((int) s1[i]) - ((int) s2[i]);
		if(s1[i] == 0)
			return 0;
	}

	return 0;
}

/*---------------------printf and support routines ---------------------*/
/* print c count times */
void PutRepChar(char c, int count)
{
	while (count--) putch(c);
}

/* put string reverse */
void PutStringReverse(char *s, int index)
{
  while ((index--) > 0) putch(s[index]);
}

/*-------------------------------------------------------------------------*/
/* 
   prints value in radix, in a field width width, with fill
   character fill
   if radix is negative, print as signed quantity
   if width is negative, left justify
   if width is 0, use whatever is needed
   if fill is 0, use ' '
 */

static void PutNumber(int value, int radix, int width, char fill)
{
  char buffer[40];
  int bi = 0;
  int unsigned uvalue;
  short int digit;
  short int left = FALSE;
  short int negative = FALSE;

  if (fill == 0) fill = ' ';

  if (width < 0) {
    width = -width;
    left = TRUE;
  }
  if (width < 0 || width > 80) width = 0;
  
  if (radix < 0) {
    radix = -radix;
    if (value < 0) {
      negative = TRUE;
      value = -value;
    }
  }
  uvalue = value;
  do {
    if (radix != 16) {
      digit = uvalue % radix ;
      uvalue = uvalue / radix ;
    }
    else {
      digit = uvalue & 0xf;
      uvalue = uvalue >> 4;
    }
    buffer[bi] = digit + ((digit <= 9) ? '0' : ('A' - 10));
    bi++;

    if (uvalue != 0) {
      if ((radix==10)&&((bi==3)||(bi==7)||(bi==11)|(bi==15))) {
	//buffer[bi++]=',';
      }
    }
  } while (uvalue != 0);

  if (negative) {
    buffer[bi] = '-';
    bi += 1;
  }
  if (width <= bi) PutStringReverse(buffer, bi);
  else {
    width -= bi;
    if (!left) PutRepChar(fill, width);
    PutStringReverse(buffer, bi);
    if (left) PutRepChar(fill, width);
  } 
}

/*-------------------------------------------------------------------------*/
static char *FormatItem(char *f, int a)
{
  char c;
  int fieldwidth = 0;
  int leftjust = FALSE;
  int radix = 0;
  char fill = ' ';

  if (*f == '0') fill = '0';
  while ((c = *f++)!=0) {
    if (c >= '0' && c <= '9') {
      fieldwidth = (fieldwidth * 10) + (c - '0');
    }
    else switch (c) {
    case '\000': return(--f);
    case '%': putch('%');
      return(f);
    case '-': leftjust = TRUE;
      break;
    case 'c': {
      if (leftjust) putch(a & 0x7f);
      if (fieldwidth > 0) PutRepChar(fill, fieldwidth - 1);
      if (!leftjust) putch(a & 0x7f);
      return(f);
    }
    case 's': {
      if (leftjust) puts((char *) a);
      if (fieldwidth > strlen((char *) a))
	PutRepChar(fill, fieldwidth - strlen((char *)a));
      if (!leftjust) puts((char *) a);
      return(f);
    }
    case 'd': 
    case 'i': radix = -10;break;
    case 'u': radix = 10;break;
    case 'x': radix = 16;break;
    case 'X': radix = 16;break;
    case 'o': radix = 8;break;
    default : radix = 3;break;/* unknown switch! */
    }
    if (radix) break;
  }
  if (leftjust) fieldwidth = -fieldwidth;
  PutNumber(a, radix, fieldwidth, fill);
  return(f);
}

#define vaStart(list, param) list = (char*)((int)&param + sizeof(param))
#define vaArg(list, type) ((type *)(list += sizeof(type)))[-1]
#define vaEnd(list)

void printf(char *f, ...)       /* variable arguments */
{
//	U32 mode ;
	char *argP;
	
	/* disable IRQs and FIQs */
//	mode = uHALir_ReadMode() ;
//	uHALir_WriteMode(mode | NoFIQ | NoIRQ) ;

	vaStart(argP,f);		/* point at the end of the format string */
	while (*f) {			/* this works because args are all ints */
		if (*f == '%')
			f = FormatItem(f + 1, vaArg(argP, int));
		else
			putch(*f++);
	}
	vaEnd(argP);

	/* restore the previous mode */
//	uHALir_WriteMode(mode) ;
}

#else

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void SerialTxChar(char ch);
void SerialTxString(char *s);
char SerialRxChar(void);

void putch(char ch)
{
//	char c[2];
	
	SerialTxChar(ch);

}

void puts(char *str)
{
	SerialTxString(str);
	
}

//If you don't use vsprintf(), the code size is reduced very much.
typedef int *__va_list[1];
int vsprintf(char * /*s*/, const char * /*format*/, __va_list /*arg*/);

void printf(char *fmt, ...)
{
	va_list ap;
	char string[1024];
	
	va_start(ap,fmt);
	vsprintf(string,fmt,ap);
	puts(string);
	va_end(ap);
}
/*
void sprintf(char *mem, char *fmt, ...)
{
	va_list ap;
	
	va_start(ap,fmt);
	vsprintf(mem,fmt,ap);
	va_end(ap);
}
*/
#endif

/*
int kbhit(void)
{
	if(SerialRxReady())
		return 1;
	return ScanKeyDown();
}
*/
int getkey(void)
{
	int c;
	
	c = SerialRxKey();
	if(c)
		return c;
	return 0;
//	return GetScanKey();
}

char getch(void)
{
	int c;
	
	while(1) {
		c = getkey();
		if(c) {
			//printf("get key!\n");
			return c;
		}
	}
	//return SerialRxChar();
}

int getyorn(void)
{
	char c;
	
	puts(" [y/n] ");
	while(1) {		
		c = getch();
		if((c=='y')||(c=='Y')||(c=='n')||(c=='N'))
			break;
	}
	putch(c);
	putch('\n');
	return c&1;	//y&Y are odd, n&N are even
}

int GetParameter(char *str, int cnt)
{
	int i, key;	
	
	i = 0;
	while(1)
	{
		key = getch();
		if(key)
		{
			if(key == ENTER_KEY)
			{
				str[i] = 0;
				return i;
			}
			else if(key == BACK_KEY && i>0)
			{
				i--;
				printf("\b \b");
			}
			else if(key == 0x1b)
			{
				//getch();
				//getch();
				return -1;
			}
			else if(key>=0x20 && key<=0x7e && i<cnt)
			{
				str[i++] = key;
				putch(key);
			}				
		}
	}	
}
