DIR_SRC = ../src
DIR_TASK1 = ../task_1
DIR_TASK2 = ../task_2
DIR_TASK3 = ../task_3
DIR_TASK4 = ../task_4
DIR_TASK5 = ../task_5
DIR_TASK6 = ../task_6
DIR_BUILD = ../bin
DIRS = $(DIR_TASK1) $(DIR_TASK2) $(DIR_TASK3) $(DIR_TASK4) $(DIR_TASK5) $(DIR_TASK6)

OBJ_MAIN = $(DIR_BUILD)/main.o
OBJ_TASK1 = $(DIR_BUILD)/task_1.o
OBJ_TASK2 = $(DIR_BUILD)/task_2.o
OBJ_TASK3 = $(DIR_BUILD)/task_3.o
OBJ_TASK4 = $(DIR_BUILD)/task_4.o
OBJ_TASK5 = $(DIR_BUILD)/task_5.o
OBJ_TASK6 = $(DIR_BUILD)/task_6.o
OBJS = $(OBJ_TASK1) $(OBJ_TASK2) $(OBJ_TASK3) $(OBJ_TASK4) $(OBJ_TASK5) $(OBJ_TASK6) $(OBJ_MAIN)



CC = gcc
CFLAGS = -Wall -Wextra -g $(addprefix -I, $(DIRS))
LFLAGS = -lm

TARGET = $(DIR_BUILD)/main

all: $(TARGET)

$(TARGET): $(OBJ_MAIN) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_MAIN): $(DIR_SRC)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
