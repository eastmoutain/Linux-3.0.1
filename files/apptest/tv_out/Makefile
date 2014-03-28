CROSS_COMPILE =/usr/local/arm/4.3.2/bin/arm-linux-
KERNELDIR =
CFLAGS = -I$(KERNELDIR)/include -O -Wall -static
CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar

ALL :  tv_out 

tv_out:  v4l2.c

	$(CC) -o  tv_out  v4l2.c $(CFLAGS) -L/usr/local/arm/4.3.2/arm-none-linux-gnueabi/libc/armv4t/usr/lib1/  -I/usr/local/arm/4.3.2/include
 	
clean :
	rm -rf tv_out
