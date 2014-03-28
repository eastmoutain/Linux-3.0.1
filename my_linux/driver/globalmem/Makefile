KERNELDIR = /home/dsh/arm11/linux/linux-3.0.1
PWD := $(shell pwd)
CROSS_COMPILE = /usr/local/arm/4.3.2/bin/arm-linux-
CC    = $(CROSS_COMPILE)gcc

obj-m := globalmem.o 

modules:
	    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	    rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

.PHONY: modules clean
