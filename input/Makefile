CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = lib_input.a
OBJ = input.o

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^

input.o: input.c input.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)