INPUT_DIR = ../../input

CC = gcc
CFLAGS = -Wall -Wextra -g -I$(INPUT_DIR)

OBJ = main.o
OBJ_INPUT = $(INPUT_DIR)/input.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ) $(OBJ_INPUT)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)