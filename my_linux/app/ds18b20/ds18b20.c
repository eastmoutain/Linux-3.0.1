#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <termios.h>
#include <sys/types.h>

int main(void)
{
    char temperature[2];
    int fd = open("/dev/ds18b20", O_RDWR | O_NDELAY | O_NOCTTY);
    if(fd == -1){
	printf("open device error");
	exit(1);
	return 0;

    }
    
    while(1){
	read(fd, &temperature, sizeof(temperature));
	printf("temperature is %d,%d\n", temperature[0], temperature[1]);
	sleep(1);
    }
    close(fd);
    return 0;

}

