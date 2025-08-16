# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall \
           -Iinclude \
           -I$(HOME)/enkiTS/src \
           $(shell pkg-config --cflags sfml-all) \
           -MMD -MP

# Linking
LDFLAGS = $(shell pkg-config --libs sfml-all) \
          -L/usr/local/lib -lbox2d \
          -L$(HOME)/enkiTS/build -lenkiTS

# Folders and file lists
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/main

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Include dependency files (.d)
DEPS = $(OBJ:.o=.d)
-include $(DEPS)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: all
	./$(TARGET)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all run clean
