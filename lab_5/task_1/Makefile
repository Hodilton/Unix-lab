DIR_INPUT = ../../input
LIBS = $(DIR_INPUT)/lib_input.a

CC = gcc
CFLAGS = -g $(addprefix -I, $(DIR_INPUT))

OBJ = task_1.o

$(OBJ): task_1.c task_1.h $(LIBS)
	$(CC) $(CFLAGS) -c $<

clean:
	-rm -f $(OBJ)
