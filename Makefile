#started with '#' are comments

DIRS=clib gobinding
INSTALL_DIRS=bin
BINP=bin
CC=gcc
CXX=g++

all: clib #gobinding

clib: force_look
	@echo "make clib"
	cd clib; $(MAKE)
	@echo "build clib end"

gobinding: force_look
	@echo "make gobinding"
	cd gobinding; $(MAKE)
	@echo "build gobinding end"

install:
	-for d in $(INSTALL_DIRS); do (cp $$d/bin/* bin); done

cngo: force_look
	go build -o $(BINP)/cngo cngo/main.go

gopackage:
	export GO111MODULE=on && go mod tidy && go mod vendor

clean:
	@echo "clean everything......"
	rm -f bin/*
	find . -name "core" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.out" -exec rm {} \;
	-for d in $(DIRS); do (cd $$d; make clean; cd ..); done

force_look :
	true

.phony: clean


