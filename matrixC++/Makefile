# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Target executable name
TARGET = matrix_program

# Source files
SRCS = main.cpp Matrix.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Optional: make run
run: all
	./$(TARGET)
