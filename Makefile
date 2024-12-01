CFLAGS = -MMD -Wall -Wextra -Wpedantic -std=c99 -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:%.c=%.o)
DEP = $(OBJ:%.o=%.d)

EXE = aoc2024
DESTDIR ?= /usr/local/bin

all: $(EXE)

clean:
	$(RM) $(OBJ) $(DEP) $(EXE)

debug: CFLAGS += -g
debug: clean all

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEP)
