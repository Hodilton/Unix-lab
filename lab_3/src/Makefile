LIB_INPUT = $(DIR_INPUT)/lib_input.a
LIBS = $(LIB_INPUT)

DIR_INPUT = ../../input
DIR_TASK1 = ../task_1
DIR_TASK2 = ../task_2
DIR_TASK3 = ../task_3
DIR_TASK4 = ../task_4
DIRS = $(DIR_INPUT) $(DIR_TASK1) $(DIR_TASK2) $(DIR_TASK3) $(DIR_TASK4)

OBJ_TASK1 = $(DIR_TASK1)/task_1.o
OBJ_TASK2 = $(DIR_TASK2)/task_2.o
OBJ_TASK3 = $(DIR_TASK3)/task_3.o
OBJ_TASK4 = $(DIR_TASK4)/task_4.o
OBJS = $(OBJ_TASK1) $(OBJ_TASK2) $(OBJ_TASK3) $(OBJ_TASK4)


CC = gcc
CFLAGS = -Wall -Wextra -g $(addprefix -I, $(DIRS))
LFLAGS = -lm

TARGET = main
OBJ = main.o


all: $(TARGET)

$(TARGET): $(OBJ) $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)