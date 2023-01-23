OUTFILEEXT=

ifeq ($(OS), Windows_NT)
	OUTFILEEXT=.exe
endif

CXX=gcc
CC=$(CROSS_COMPILE)$(CXX)

INCDIR=../commons
CFLAGS=-O3 -g -I $(INCDIR)/intf -I "src/intf"
LFLAGS=-lm

SRCDIR=src
OBJDIR=obj
BINDIR=bin
OUTFILE=hexvsl

rwildcard=$(foreach d, $(wildcard $(1:=/*)), $(call rwildcard ,$d, $2) $(filter $(subst *, %, $2), $d))

INC=$(call rwildcard, $(INCDIR)/impl, *.c)
SRC=$(call rwildcard, $(SRCDIR)/impl, *.c)

OBJS=$(patsubst $(SRCDIR)/impl/%.c, $(OBJDIR)/%.o, $(SRC))
OBJS+=$(patsubst $(INCDIR)/impl/%.c, $(OBJDIR)/%.o, $(INC))

$(OBJDIR)/%.o: $(SRCDIR)/impl/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJDIR)/%.o: $(INCDIR)/impl/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJS) link

link:
	$(CC) -o $(BINDIR)/$(OUTFILE)$(OUTFILEEXT) $(OBJS) $(LFLAGS)

setup:
	@ mkdir $(BINDIR)
	@ mkdir $(OBJDIR)
