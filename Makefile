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

all: Main

Main: $(MAIN_OBJ) $(OBJ)
	@echo [Compiling Main demo]
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXEC) $(MAIN_OBJ) $(OBJ)
	@echo [Running Main demo]
	./$(MAIN_EXEC)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TEST_OBJ): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test: $(TEST_OBJ) $(OBJ)
	@echo [Compiling Test suite]
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(OBJ)
	@echo [Running tests]
	./$(TEST_EXEC)

valgrind:
	@echo [Compiling Main demo]
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXEC) $(MAIN_OBJ) $(OBJ)
	@echo [Running Main demo]
	./$(MAIN_EXEC)
	@echo [Running valgrind]
	valgrind --leak-check=full ./$(MAIN_EXEC)

valgrind-test:
	@echo [Compiling Test for valgrind]
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(OBJ)
	@echo [Running valgrind on tests]
	valgrind --leak-check=full ./$(TEST_EXEC)

clean:
	@echo [Cleaning up build files]
	rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(MAIN_EXEC) $(TEST_EXEC)
