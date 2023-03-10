CXX=g++
CXXFLAGS=-W -Wall -std=c++2a 
LDFLAGS=-lstdc++ 
EXEC=tests
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
PARENTSRC:= $(filter-out ../main.cpp, $(wildcard ../*.cpp))
PARENTOBJ:= $(PARENTSRC:.cpp=.o)

all: $(EXEC)

tests: $(OBJ)
	$(CXX) -o $@ $^ $(PARENTOBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

