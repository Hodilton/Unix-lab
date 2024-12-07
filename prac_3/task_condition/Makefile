DIR_TASK3 = ../task_condition
DIR_BUILD = ../bin
DIRS =

OBJ_TASK3 = $(DIR_BUILD)/task_condition.o
OBJS = $(OBJ_TASK3)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS)) -D_REENTERANT -lpthread

TARGET = $(OBJ_TASK3)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK3): $(DIR_TASK3)/task_condition.c $(DIR_TASK3)/task_condition.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
