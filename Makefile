# Rules for making the NTFS-3G driver.


EXTRA_CFLAGS = -DNTFS3G_VERSION=\"0.0.1\"

obj-m += tdump.o
austin-objs +=	tdump.o
	  	   					
#KDIR = /home/alan.yu/PERFORCE/THEALE/RedLion/2.6.32.15/kernel
#KDIR = /home/alan.yu/PERFORCE/DAILEO/temp_branch/Supernova_His_J2/component_src/kernel/2.6.32.15/kernel
KDIR = /home/austin/workspace/source/perforce/austin.gao_ubuntu_theale_bm1286/perforce/THEALE/RedLion/3.1.10

all:
	make -C $(KDIR)/ SUBDIRS=$(PWD) modules
clean:
	make -C $(KDIR)/ SUBDIRS=$(PWD) clean
				
														
														

															
															
																											
