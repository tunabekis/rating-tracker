CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/main.c src/rating_list.c
TARGET = rating_tracker

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
