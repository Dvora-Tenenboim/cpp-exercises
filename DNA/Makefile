TARGET=main
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)
INC_DIR=../include
CC=g++
CFLAGS=  -pedantic -Wall -Werror -Wconversion -ansi -g $(INC_FLAGS)
CXXFLAGS=$(CFLAGS)
LDFLAGS=-g

$(TARGET): $(OBJS)

#inter.o: funcs.h
#main.o: defs.h funcs.h

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

.PHONY: clean run gd


include .depends
.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

val:
	valgrind--leak-check=Full./$(TARGET)

