# Makefile for tpmp-lab2-task3 project
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/worker

CFLAGS = -I$(INC_DIR)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $(CFLAGS)  -MD $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d
	rm -f $(TARGET)

-include $(wildcard $(OBJ_DIR)/*.d)

.PHONY: all clean
