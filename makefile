INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin

CC = clang++
CFLAGS = -std=c++11 -I $(INCDIR)
TARGET = $(BINDIR)/pl0

_OBJS = main.o Parse.o Vm.o Error.o Token.o Code.o Identifier.o \
	    Lexer.o Symbol.o ObjCode.o Word.o Num.o

OBJS = $(patsubst %, $(OBJDIR)/%, $(_OBJS))

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o  $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY : clean
clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*
