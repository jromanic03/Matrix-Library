CC = gcc
CFLAGS = -std=c99 -Wall -O2
TARGET = matrix_c_program

SRCS = main.c matrix.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)
