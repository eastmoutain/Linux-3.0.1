#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{
    int fd = open("/dev/leds", O_RDWR);
    if(fd==-1){
	printf("open device error\n");
	return 0;
    }

    while(1){
	sleep(1);
	ioctl(fd,0,0);
	sleep(1);
	ioctl(fd,0,1);
	sleep(1);
	ioctl(fd,0,2);
	sleep(1);
	ioctl(fd,0,3);
	sleep(1);
	ioctl(fd,1,0);
	sleep(1);
	ioctl(fd,1,1);
	sleep(1);
	ioctl(fd,1,2);
	sleep(1);
	ioctl(fd,1,3);
    }
}
