# making all .cpp files in the directory
# each one into its own target

CXX ?= g++

CXXFLAGS ?= -Wall

.PHONY: all clean

SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,%,$(SRCS))

all: $(PROGS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean: 
	rm -f $(PROGS)
