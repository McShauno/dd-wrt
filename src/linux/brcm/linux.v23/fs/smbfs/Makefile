#
# Makefile for the linux smb-filesystem routines.
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#
# Note 2! The CFLAGS definitions are now in the main makefile...

O_TARGET := smbfs.o

obj-y   := proc.o dir.o cache.o sock.o inode.o file.o ioctl.o getopt.o symlink.o
obj-m   := $(O_TARGET)

# If you want debugging output, you may add these flags to the EXTRA_CFLAGS
# SMBFS_PARANOIA should normally be enabled.

EXTRA_CFLAGS += -DSMBFS_PARANOIA
#EXTRA_CFLAGS += -DSMBFS_DEBUG
#EXTRA_CFLAGS += -DSMBFS_DEBUG_VERBOSE
#EXTRA_CFLAGS += -DDEBUG_SMB_MALLOC
#EXTRA_CFLAGS += -DDEBUG_SMB_TIMESTAMP
#EXTRA_CFLAGS += -Werror

include $(TOPDIR)/Rules.make

#
# Maintainer rules
#

# getopt.c not included. It is intentionally separate
SRC = proc.c dir.c cache.c sock.c inode.c file.c ioctl.c symlink.c

proto:
	-rm -f proto.h
	@echo >  proto2.h "/*"
	@echo >> proto2.h " *  Autogenerated with cproto on: " `date`
	@echo >> proto2.h " */"
	@echo >> proto2.h ""
	cproto -E "gcc -E" -e -v -I $(TOPDIR)/include -DMAKING_PROTO -D__KERNEL__ $(SRC) >> proto2.h
	mv proto2.h proto.h
