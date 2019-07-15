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
CPPSRCS := $(wildcard $(SRCP)/*.cpp)
CPPOBJS := $(patsubst $(SRCP)/%.cpp,$(OBJP)/%.o,$(CPPSRCS)) 

DEPFILES := $(patsubst %.cpp,$(OBJP)/%.d,$(CPPSRCS))
-include $(DEPFILES)

LIBBINDINGOBJS := $(OBJP)/gobinding.o
LIBBINDINGOBJS += ../clib/obj/clib.o

all: $(LIBP)/libgobinding.so

objs: $(CPPOBJS) $(CCOBJS) $(TSTOBJS)
	@echo "make lib objs"
	-for d in $(DPDIRS); do (cd $$d; $(MAKE) objs || exit "$$?");done
	cd $(CURP)

$(LIBP)/libgobinding.so: $(LIBBINDINGOBJS) | $(LIBP)
	$(CXX) $(CXXFLAGS) $(LIBBINDINGOBJS) -MMD -shared -o $@

$(CPPOBJS): $(OBJP)/%.o:$(SRCP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

$(CCOBJS): $(OBJP)/%.o:$(SRCP)/%.cc | $(OBJP)
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
