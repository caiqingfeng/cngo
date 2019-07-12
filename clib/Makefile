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

CLIBOBJS := $(OBJP)/clib.o

all: $(LIBP)/libclib.so

objs: $(CPPOBJS) $(CCOBJS) $(TSTOBJS)
	@echo "make clib depend objs"
	-for d in $(DPDIRS); do (cd $$d; $(MAKE) objs || exit "$$?");done
	cd $(CURP)

$(LIBP)/libclib.so: $(CLIBOBJS) | $(LIBP)
	$(CXX) $(CXXFLAGS) $(CLIBOBJS) -MMD -shared -o $@

$(CPPOBJS): $(OBJP)/%.o:$(SRCP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

$(CCOBJS): $(OBJP)/%.o:$(SRCP)/%.cc | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

clean:
	@echo "Removing linked and compiled files......"
	rm -f $(CPPOBJS)
	rm -f $(CCOBJS)
	rm -f $(TSTOBJS)
	rm -f $(BINP)/*

.phony: clean

$(sort $(MKDIRS)):
	mkdir -p $@
