DIR_TASK5 = ../task_5
DIR_BUILD = ../bin
DIRS =

OBJ_TASK5 = $(DIR_BUILD)/task_5.o
OBJS = $(OBJ_TASK5)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS))

TARGET = $(OBJ_TASK5)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK5): $(DIR_TASK5)/task_5.c $(DIR_TASK5)/task_5.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
