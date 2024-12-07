DIR_TASK2 = ../task_2
DIR_BUILD = ../bin
DIRS =

OBJ_TASK2 = $(DIR_BUILD)/task_2.o
OBJS = $(OBJ_TASK2)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS))

TARGET = $(OBJ_TASK2)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK2): $(DIR_TASK2)/task_2.c $(DIR_TASK2)/task_2.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS) test.txt
