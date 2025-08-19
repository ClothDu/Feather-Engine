# ----------------------------
# Compiler and flags
# ----------------------------
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -I/usr/include -I/usr/local/include \
        	-Iexternal/imgui-master -Iexternal/imgui-master/backends \
        	-MMD -MP

DEBUGFLAGS = -g -O0
RELEASEFLAGS = -O3

# ----------------------------
# Linking
# ----------------------------
LDFLAGS = $(shell pkg-config --libs glfw3 freetype2) \
        	-lGL -ldl -lpthread -lopenal \
        	-lbox2d -lBulletDynamics -lBulletCollision -lLinearMath \
        	-lassimp

# ----------------------------
# Folders
# ----------------------------
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/main

# ----------------------------
# Sources
# ----------------------------
SRC := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.c) \
    	$(wildcard external/imgui-master/*.cpp) \
    	$(wildcard external/imgui-master/backends/*.cpp)

# ----------------------------
# Objects
# ----------------------------
OBJ := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRC)))
OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(OBJ))

# ----------------------------
# Dependencies
# ----------------------------
DEPS := $(OBJ:.o=.d)
-include $(DEPS)

# ----------------------------
# Default target
# ----------------------------
all: $(TARGET)

# ----------------------------
# Build target
# ----------------------------
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# ----------------------------
# Object compilation
# ----------------------------
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: external/imgui-master/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: external/imgui-master/backends/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

# ----------------------------
# Run
# ----------------------------
run: all
	./$(TARGET)

# ----------------------------
# Debug and Release builds
# ----------------------------
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean all

release: CXXFLAGS += $(RELEASEFLAGS)
release: clean all

# ----------------------------
# Clean
# ----------------------------
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# ----------------------------
# Aliases
# ----------------------------
.PHONY: all run clean debug release
