# Nitzanwa@gmail.com
# Makefile - Project CPP_EX1_25

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Iinclude

# Source and object files
SRC = src/Graph.cpp src/Algorithms.cpp src/Queue.cpp src/PriorityQueue.cpp src/UnionFind.cpp
OBJ = $(SRC:.cpp=.o)

# Main and Test sources
MAIN_SRC = demo/main.cpp
MAIN_OBJ = demo/main.o
TEST_SRC = tests/test.cpp
TEST_OBJ = tests/test.o

# Executables
MAIN_EXEC = Main
TEST_EXEC = Test

# Default target
all: Main

# Compile and run the main demo
Main: $(MAIN_OBJ) $(OBJ)
	@echo [Compiling Main demo]
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXEC) $(MAIN_OBJ) $(OBJ)
	@echo [Running Main demo]
	./$(MAIN_EXEC)

# Compile main.o
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Compile test.o
$(TEST_OBJ): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Compile object files in src/
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Build and run the tests
test: $(TEST_OBJ) $(OBJ)
	@echo [Compiling Test suite]
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(OBJ)
	@echo [Running tests]
	./$(TEST_EXEC)

# Run valgrind on the main demo
valgrind: Main
	@echo [Running valgrind]
	valgrind --leak-check=full ./$(MAIN_EXEC)

# Compile tests and run valgrind on them
valgrind-test: $(TEST_OBJ) $(OBJ)
	@echo [Compiling Test for valgrind]
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(OBJ)
	@echo [Running valgrind on tests]
	valgrind --leak-check=full ./$(TEST_EXEC)

# Clean all build files
clean:
	@echo [Cleaning up build files]
	rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(MAIN_EXEC) $(TEST_EXEC)
