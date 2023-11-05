PWD := $(shell pwd)
KDIR := /lib/modules/$(shell uname -r)/build 
DRVNAME :=  ihook_syscall

#ccflags-y = -DQAX_KERNEL  $(QAX_KMOD_FLAGS)

obj-m := $(DRVNAME).o
obj-y := libudis86/

$(DRVNAME)-y = ihook_test.o mem.o syscalls.o libudis86/built-in.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD)
#	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean: 
	rm -rf *.o *.cmd Module.symvers Module.markers
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean

