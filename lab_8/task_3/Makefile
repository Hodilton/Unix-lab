DIR_TASK3 = ../task_3
DIR_BUILD = ../bin
DIRS =

OBJ_TASK3 = $(DIR_BUILD)/task_3.o
OBJS = $(OBJ_TASK3)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS))

TARGET = $(OBJ_TASK3)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK3): $(DIR_TASK3)/task_3.c $(DIR_TASK3)/task_3.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
