DIR_INPUT = ../../input
LIBS = $(DIR_INPUT)/lib_input.a

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIR_INPUT))

OBJ = task_2.o

$(OBJ): task_2.c task_2.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJ)
