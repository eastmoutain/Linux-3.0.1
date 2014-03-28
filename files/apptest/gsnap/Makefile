
CROSS_COMPILE =/usr/local/arm/4.3.2/bin/arm-linux-
KERNELDIR =
CFLAGS = -I$(KERNELDIR)/include -O -Wall -static
CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar

all:
	$(CC)  -g gsnap.c -ljpeg -o gsnap
clean:
	rm -f gsnap
