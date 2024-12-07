DIR_INPUT = ../../input
LIBS = $(DIR_INPUT)/lib_input.a

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIR_INPUT))

OBJ = task_4.o

$(OBJ): task_4.c task_4.h $(LIBS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJ)
