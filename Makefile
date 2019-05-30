COMPILADOR := gcc
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin

MAIN := program/main.c
TESTER := program/tester.c

SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

# -g debug, --coverage para cobertura
FLAGS := --coverage -std=c11 
INC := -I include/ -I third_party/
INC_MATH := -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(COMPILADOR) $(FLAGS) $(INC)  -c -o $@  $< 

tp1: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(COMPILADOR) $(FLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/tp1 $(INC_MATH)

tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(COMPILADOR) $(FLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester 
	$(BINDIR)/tester

all: tp1

run: tp1
	$(BINDIR)/tp1

coverage:
	@mkdir -p coverage/
	@gcov $(SOURCES) -rlpo build/
	@$(RM) *.gcda *.gcno

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno

.PHONY: clean coverage
