DIR_TASK1 = ../task_mutex
DIR_BUILD = ../bin
DIRS =

OBJ_TASK1 = $(DIR_BUILD)/task_mutex.o
OBJS = $(OBJ_TASK1)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS)) -D_REENTERANT -lpthread

TARGET = $(OBJ_TASK1)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK1): $(DIR_TASK1)/task_mutex.c $(DIR_TASK1)/task_mutex.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
