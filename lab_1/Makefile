CC = gcc
CFLAGS = -g
LIBS = -lm

TARGET = main
OBJS = calculate.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

calculate.o: calculate.c calculate.h
	$(CC) $(CFLAGS) -c $<

main.o: main.c calculate.h
	$(CC) $(CFLAGS) -c $<

clean:
	-rm -f $(TARGET) $(OBJS)