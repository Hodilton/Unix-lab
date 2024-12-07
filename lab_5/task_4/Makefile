DIR_INPUT = ../../input
DIR_TASK1 = ../task_1
DIRS = $(DIR_INPUT) $(DIR_TASK1)

LIBS = $(DIR_INPUT)/lib_input.a $(DIR_TASK1)/task_1.o

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIRS))

OBJ = task_4.o

$(OBJ): task_4.c task_4.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJ)
