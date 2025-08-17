# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall \
           -Iinclude \
           -Iexternal/imgui-master \
           -Iexternal/imgui-master/backends \
           -I/home/chduda/enkiTS/src \
           $(shell pkg-config --cflags glfw3 freetype2) \
           -MMD -MP

# Linking
LDFLAGS = $(shell pkg-config --libs glfw3 freetype2) \
          -lGL -ldl -lpthread -lopenal \
          -L/usr/local/lib -lbox2d \
          -L$(HOME)/enkiTS/build -lenkiTS \
          -lassimp \
          -lBulletDynamics -lBulletCollision -lLinearMath

# Folders
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/main

# Project sources
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/glad.c \
      external/imgui-master/imgui.cpp \
      external/imgui-master/imgui_draw.cpp \
      external/imgui-master/imgui_tables.cpp \
      external/imgui-master/imgui_widgets.cpp \
      external/imgui-master/backends/imgui_impl_glfw.cpp \
      external/imgui-master/backends/imgui_impl_opengl3.cpp

# Objects
OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRC)))
OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(OBJ))

# Dependency files
DEPS = $(OBJ:.o=.d)
-include $(DEPS)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: external/imgui-master/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: external/imgui-master/backends/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run
run: all
	./$(TARGET)

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all run clean
