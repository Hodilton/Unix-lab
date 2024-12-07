DIR_TASK4 = ../task_4
DIR_BUILD = ../bin
DIRS =

OBJ_TASK4 = $(DIR_BUILD)/task_4.o
OBJS = $(OBJ_TASK4)

LIBS =

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS))

TARGET = $(OBJ_TASK4)

all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TASK4): $(DIR_TASK4)/task_4.c $(DIR_TASK4)/task_4.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
