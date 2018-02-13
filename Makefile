# building the euler library and executable running all problems

CXX ?= g++

CXXFLAGS ?= -Wall -std=c++14 -O3

.PHONY: all clean

LIBOBJS = problem1 \
	   problem2 \
	   problem3 \
	   problem4 \
	   problem5

_LIBOBJS = $(addsuffix .o, $(LIBOBJS))

LIB = euler
_LIB = $(addsuffix .a, $(addprefix lib, $(LIB)))

PROG = problems

TESTS = problem1 \
		problem2

_TESTS = $(addsuffix _test.cpp, $(TESTS))

TEST_RUNNER = runner
_TEST_RUNNER_SRC = $(addsuffix .cpp, $(TEST_RUNNER))

all: $(PROG)

$(PROG): $(addsuffix .cpp, $(PROG)) $(addsuffix .h, $(PROG)) $(_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< -L . -l$(LIB)

$(_LIB): $(_LIBOBJS)
	ar -rcs $@ $(_LIBOBJS)

$(_LIBOBJS): $(addsuffix .cpp, $(LIBOBJS)) $(addsuffix .h, $(LIB))
	$(CXX) $(CXXFLAGS) -c -o $@ $(@:%.o=%.cpp)

test: $(TEST_RUNNER)
	@./$(TEST_RUNNER)

$(TEST_RUNNER): $(_TEST_RUNNER_SRC) $(_LIB)
	$(CXX) -o $@ $< -L . -l$(LIB)

$(_TEST_RUNNER_SRC): $(_TESTS)
	cxxtestgen -o $@ --error-printer $^

clean: 
	rm -f $(PROG) $(_LIB) $(_LIBOBJS) $(TEST_RUNNER) $(_TEST_RUNNER_SRC)

