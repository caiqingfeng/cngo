#started with '#' are comments

#PROJECT_BASE=$(shell pwd)
PROJECT_BASE=$(GOPATH)/src/yiyifutures
LIBPATH=$(PROJECT_BASE)/lib

CTP_LIB_PATH = $(PROJECT_BASE)/ctplib/v6.3.15_20190220_api_tradeapi_se_linux64
CTP_TRADER_API_LIB = thosttraderapi_se
CTP_MDUSER_API_LIB = thostmduserapi_se

LIB_BASE = -L$(CTP_LIB_PATH)
#ARCH := $(shell getconf LONG_BIT)
#CXXFLAGS=$(CPP_FLAGS_$(ARCH)) -std=c++0x -Wall -Wno-unused-function -g

CXXFLAGS = $(CPP_FLAGS_$(ARCH)) -O2 -fPIC -g -Wall -fmessage-length=0 -Wno-unused-function
CXXFLAGS += -std=gnu++11
CXXFLAGS += -I$(CTP_LIB_PATH) -I$(PROJECT_BASE)/trading #-I/usr/local/include/ -I/usr/include/

AR  = ar
ARFLAGS = rv
RANLIB  = ranlib

CC=g++
CXX=g++
