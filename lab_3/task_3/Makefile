DIR_INPUT = ../../input
LIBS = $(DIR_INPUT)/lib_input.a

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIR_INPUT))

OBJ = task_3.o

$(OBJ): task_3.c task_3.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJ)
