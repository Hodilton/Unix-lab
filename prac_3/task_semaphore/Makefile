DIR_TASK2 = ../task_semaphore
DIR_BUILD = ../bin
DIRS =

OBJ_TASK2 = $(DIR_BUILD)/task_semaphore.o
OBJS = $(OBJ_TASK2)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS)) -D_REENTERANT -lpthread

TARGET = $(OBJ_TASK2)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK2): $(DIR_TASK2)/task_semaphore.c $(DIR_TASK2)/task_semaphore.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS) file.txt
