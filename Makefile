CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17

SRC = src/main.cpp src/math_utils.cpp src/string_utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)
