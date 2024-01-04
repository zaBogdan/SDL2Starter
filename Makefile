SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(shell find $(SRC_DIR) -name '*.cpp' -type f)
OBJ_NAME = play
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib
COMPILER_FLAGS = -std=c++20 -Wall -O0 -g
LINKER_FLAGS = -lsdl2

all:
	mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)