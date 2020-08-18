
SRCS = $(wildcard *.c)
OBJ_DIR = obj
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCLUDES = $(wildcard *.h)
CC = gcc

TARGET = exe.out
LDFALGS = -Wall
CFLAGS = -c -Wall -ggdb


%.o: %.c $(INCLUDES)
	$(CC) -c $< $(CFLAGS) -o $@


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) *.o $(TARGET)