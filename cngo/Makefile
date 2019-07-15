#started with '#' are comments
include ../Makefile.inc

SRCP=src
OBJP=obj
MKDIRS += $(OBJP)
LIBP=lib
MKDIRS += $(LIBP)
BINP=bin
MKDIRS += $(BINP)

CURP=$(CURDIR)

#src

all: libcngo.h $(BINP)/cngo

libcngo.h: main.go
	go  build -buildmode=c-shared -o libcngo.so main.go 

$(BINP)/cngo: main.go
	go  build main.go -o $(BINP)/cngo

clean:
	@echo "Removing linked and compiled files......"
	rm -f libcngo.*

.phony: clean

$(sort $(MKDIRS)):
	mkdir -p $@
