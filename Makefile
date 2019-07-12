#started with '#' are comments

DIRS=ctptest ctpgo
INSTALL_DIRS=bin
BINP=bin
CC=gcc
CXX=g++

#all: src test
#all: ctptest ctpgo trading
all: ctpgo trading

ctpgo: force_look
	@echo "make ctpgo"
	cd ctpgo; $(MAKE)
	@echo "build ctpgo end"

ctptest: force_look
	@echo "make ctptest"
	cd ctptest; $(MAKE)
	@echo "build ctptest end"

install:
	-for d in $(INSTALL_DIRS); do (cp $$d/bin/* bin); done

trading: force_look
	go build -o $(BINP)/trading trading/main.go

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


