DIR_TASK1 = ../task_1
DIR_BUILD = ../bin
DIRS =

OBJ_TASK1 = $(DIR_BUILD)/task_1.o
OBJS = $(OBJ_TASK1)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS))

TARGET = $(OBJ_TASK1)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK1): $(DIR_TASK1)/task_1.c $(DIR_TASK1)/task_1.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
