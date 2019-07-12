#started with '#' are comments
include ../Makefile.inc

SRCP=src
TSTP=test
OBJP=obj
MKDIRS += $(OBJP)
LIBP=lib
MKDIRS += $(LIBP)
BINP=bin
MKDIRS += $(BINP)

CURP=$(CURDIR)

#src
CPPSRCS := $(wildcard $(SRCP)/*.cpp)
CPPOBJS := $(patsubst $(SRCP)/%.cpp,$(OBJP)/%.o,$(CPPSRCS)) 
TSTSRCS := $(wildcard $(TSTP)/*.cpp)
TSTOBJS := $(patsubst $(TSTP)/%.cpp,$(OBJP)/%.o,$(TSTSRCS))

DEPFILES := $(patsubst %.cpp,$(OBJP)/%.d,$(CPPSRCS))
-include $(DEPFILES)

#src depend dirs
# COMMONP=../common
# DPDIRS += $(COMMONP)
# TIMERP := ../timer
# DPDIRS += $(TIMERP)
# PERSISTENCEP := ../persistence
# DPDIRS += $(PERSISTENCEP)

#src depend objs and libs
# DPCPPSRCS := $(wildcard $(COMMONP)/src/*.cpp)
# DPOBJS := $(patsubst %.cpp,$(COMMONP)/obj/%.o,$(notdir $(DPCPPSRCS)))
# DPCCSRCS := $(wildcard $(COMMONP)/src/*.cc)
# DPOBJS += $(patsubst %.cc,$(COMMONP)/obj/%.o,$(notdir $(DPCCSRCS)))
# DPOBJS += $(TIMEROBJS)

LIBCTPGOOBJS := $(OBJP)/gobinding.o
LIBCTPGOOBJS += $(OBJP)/TraderSpi.o
LIBCTPGOOBJS += $(OBJP)/MdSpi.o

all: $(LIBP)/libctpgo.so

objs: $(CPPOBJS) $(CCOBJS) $(TSTOBJS)
	@echo "make backend depend objs"
	-for d in $(DPDIRS); do (cd $$d; $(MAKE) objs || exit "$$?");done
	cd $(CURP)

$(LIBP)/libctpgo.so: $(LIBCTPGOOBJS) | $(LIBP)
	$(CXX) $(CXXFLAGS) $(LIBCTPGOOBJS) -MMD -shared -o $@
	rm -f $(LIBPATH)/libctpgo.so && cp $(LIBP)/libctpgo.so $(LIBPATH)/libctpgo.so
	rm -f $(LIBPATH)/libthosttraderapi_se.so && ln -s $(CTP_LIB_PATH)/libthosttraderapi_se.so $(LIBPATH)/libthosttraderapi_se.so
	rm -f $(LIBPATH)/libthostmduserapi_se.so && ln -s $(CTP_LIB_PATH)/libthostmduserapi_se.so $(LIBPATH)/libthostmduserapi_se.so

$(CPPOBJS): $(OBJP)/%.o:$(SRCP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

$(CCOBJS): $(OBJP)/%.o:$(SRCP)/%.cc | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

$(TSTOBJS): $(OBJP)/%.o:$(TSTP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

$(DPOBJS): $(DPSRCS)
	cd $(COMMONP); make

clean:
	@echo "Removing linked and compiled files......"
	rm -f $(CPPOBJS)
	rm -f $(CCOBJS)
	rm -f $(TSTOBJS)
	rm -f $(BINP)/*

.phony: clean

$(sort $(MKDIRS)):
	mkdir -p $@
