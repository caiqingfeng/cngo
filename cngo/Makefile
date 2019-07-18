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

all: $(BINP)/cngo

$(BINP)/cngo: main.go
	go  build -o $(BINP)/cngo

clean:
	@echo "Removing linked and compiled files......"
	rm -f libcngo.*

.phony: clean

$(sort $(MKDIRS)):
	mkdir -p $@
