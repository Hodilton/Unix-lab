DIR_SRC = ./src
DIR_TASK1 = ./src
DIR_TASK2 = ./src
DIR_BUILD = ./bin
DIRS = $(DIR_TASK1) $(DIR_TASK2)

OBJ_MAIN = $(DIR_BUILD)/main.o
OBJ_TASK1 = $(DIR_BUILD)/task_1.o
OBJ_TASK2 = $(DIR_BUILD)/task_2.o
OBJS = $(OBJ_TASK1) $(OBJ_TASK2) $(OBJ_MAIN)



CC = gcc
CFLAGS = -Wall -Wextra -g $(addprefix -I, $(DIRS))
LFLAGS = -lm

TARGET = $(DIR_BUILD)/main

all: $(DIR_BUILD) $(TARGET)


$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)


$(TARGET): $(OBJS) | $(DIR_BUILD)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)


$(OBJ_TASK1): $(DIR_TASK1)/task_1.c $(DIR_TASK1)/task_1.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_TASK2): $(DIR_TASK2)/task_2.c $(DIR_TASK2)/task_2.h
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_MAIN): $(DIR_SRC)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(DIR_BUILD)
