# Variáveis do compilador
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Iinclude \
            -Iexternal/glm-0.9.9 \
            -Iexternal/glfw/include \
            -Iexternal/box2d/include \
            -Iexternal/bullet3/src \
            -Iexternal/enkiTS/include \
            -Iexternal/assimp/include

SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp,obj/%.o,$(SRC))
TARGET := bin/main

# Função para buscar todos os .a recursivamente e filtrar exemplos/testes/macOS
define find_libs
$(shell find $1 -name "*.a" ! -path "*/examples/*" ! -path "*/test/*" ! -path "*/osx64/*")
endef

GLFW_LIBS := $(call find_libs,external/glfw)
BOX2D_LIBS := $(call find_libs,external/box2d)
BULLET_LIBS := $(call find_libs,external/bullet3)
BGFX_LIBS := $(call find_libs,external/bgfx)
ENKITS_LIBS := $(call find_libs,external/enkiTS)
ASSIMP_LIBS := $(call find_libs,external/assimp)

LDFILES := $(GLFW_LIBS) $(BOX2D_LIBS) $(BULLET_LIBS) $(BGFX_LIBS) $(ENKITS_LIBS) $(ASSIMP_LIBS)

# Regras
all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CXX) $(OBJ) -o $(TARGET) $(LDFILES)

obj/%.o: src/%.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf obj/*.o $(TARGET)
