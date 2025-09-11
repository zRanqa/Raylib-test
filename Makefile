.default: all

BIN_DIR = bin
EXEC = $(BIN_DIR)/Main

# Raylib paths (updated for your system)
RAYLIB_DIR = /opt/homebrew/Cellar/raylib/5.5
RAYLIB_INCLUDE = $(RAYLIB_DIR)/include
RAYLIB_LIB = $(RAYLIB_DIR)/lib

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17 -g -O
LDFLAGS = -L$(RAYLIB_LIB) -lraylib -lm -lpthread -ldl -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Source and object files
SRC_DIR = src
OBJ_DIR = $(BIN_DIR)
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Target for building the executable
all: $(EXEC)

# Linking
$(EXEC): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(RAYLIB_INCLUDE) -c $< -o $@

# Clean up
clean:
	rm -f $(EXEC) $(OBJ_DIR)/*.o
