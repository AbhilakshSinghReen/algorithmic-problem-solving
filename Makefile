CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17

SRC := $(shell find src -name "*.cpp")
OBJDIR := build

# Convert source path to object path: e.g. src/foo.cpp -> build/src/foo.o
OBJ := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

TARGET = build/main

all: $(TARGET)

# Link all object files to create executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile each source file to object file in build/
# Create necessary directories with mkdir -p
$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

run: all
	./$(TARGET)
