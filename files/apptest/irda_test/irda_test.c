/*
forlinx
*/
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <sys/time.h>
//#include<unistd.h>
int main(void)
{
	int fd;
	unsigned char buf[1];

	if ((fd=open("/dev/irda0",O_RDONLY)) < 0)
	{
   	     printf("Open Device IRDA failed.\r\n");
   	     exit(1);
	}
	else
	{
        	printf("Open Device IRDA successed.\r\n");

        	while (1)
        	{
         		read(fd, buf, 1);
			if (buf[0] == 0)
				printf("0\n");
			else	printf("1\n");
		
			//sleep(1);
        	}
        close(fd);

    	}

	return 0;
}

