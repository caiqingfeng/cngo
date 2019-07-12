#started with '#' are comments

#PROJECT_BASE=$(shell pwd)
PROJECT_BASE=$(GOPATH)/src/cngo
LIBPATH=$(PROJECT_BASE)/lib

C_LIB_PATH = $(PROJECT_BASE)/clib

LIB_BASE = -L$(C_LIB_PATH)

CXXFLAGS = $(CPP_FLAGS_$(ARCH)) -O2 -fPIC -g -Wall -fmessage-length=0 -Wno-unused-function
CXXFLAGS += -std=gnu++11
CXXFLAGS += -I$(C_LIB_PATH)/src  

AR  = ar
ARFLAGS = rv
RANLIB  = ranlib

CC=g++
CXX=g++
