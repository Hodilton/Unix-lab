DIR_TASK6 = ../task_6
DIR_BUILD = ../bin
DIRS =

OBJ_TASK6 = $(DIR_BUILD)/task_6.o
OBJS = $(OBJ_TASK6)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS))

TARGET = $(OBJ_TASK6)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK6): $(DIR_TASK6)/task_6.c $(DIR_TASK6)/task_6.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
