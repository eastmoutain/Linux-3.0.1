/*
* sound.c
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <linux/soundcard.h>
//#include "sockpcm.h"

#define LENGTH 3     /* 存储秒数 */
#define RATE 8000   /* 采样频率 */
#define SIZE 16      /* 量化位数 */
#define CHANNELS 1   /* 声道数目 */
/* 用于保存数字音频数据的内存缓冲区 */
unsigned char buf[LENGTH*RATE*SIZE*CHANNELS/8];
int main(void)
{
  int fd;        /* 声音设备的文件描述符 */
  int arg;        /* 用于ioctl调用的参数 */
  int status;   /* 系统调用的返回值 */
  /* 打开声音设备 */
  fd = open("/dev/dsp", O_RDWR);
  if (fd < 0) {
    perror("open of /dev/dsp 1failed");
    exit(1);
  }
  
/* 设置采样时的量化位数 */
  arg = SIZE;
  status = ioctl(fd, SOUND_PCM_WRITE_BITS, &arg);
  if (status == -1)
    perror("SOUND_PCM_WRITE_BITS ioctl failed");
  if (arg != SIZE)
    perror("unable to set sample size");
  /* 设置采样时的声道数目 */
  arg = CHANNELS;
  status = ioctl(fd, SOUND_PCM_WRITE_CHANNELS, &arg);
  if (status == -1)
    perror("SOUND_PCM_WRITE_CHANNELS ioctl failed");
  if (arg != CHANNELS)
    perror("unable to set number of channels");
  /* 设置采样时的采样频率 */
  arg = RATE;
  status = ioctl(fd, SOUND_PCM_WRITE_RATE, &arg);
  if (status == -1)
    perror("SOUND_PCM_WRITE_WRITE ioctl failed");
  /* 循环，直到按下Control-C */
  
  status = ioctl(fd, SOUND_PCM_SYNC, 0);
  if (status == -1)
    perror("SOUND_PCM_SYNC ioctl failed");   

/*
  FILE *fp;
  fp = fopen("recopcmfile","w");
  if(fp==NULL) {
          printf("creat file failed!\n");
          exit 0;
  }
*/
  
  while (1) {
    ioctl(fd, SOUND_PCM_SYNC, 0);
    printf("Saying:\n");
    status = read(fd, buf, sizeof(buf)); /* 录音 */
    if (status != sizeof(buf))
        printf("read wrong number of bytes");
	else
		printf("saying mun %d",sizeof(buf));

    ioctl(fd, SOUND_PCM_SYNC, 0);
       
    printf("Said:\n");
    status = write(fd, buf, sizeof(buf)); /* 回放 */
    if (status != sizeof(buf))
        printf("wrote wrong number of bytes");
	else
	printf("saying mun %d",sizeof(buf));
        
  }  
    //ioctl(fd, SOUND_PCM_SYNC, 0);

return 0;
}
