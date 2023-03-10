CXX=g++
CXXFLAGS=-W -Wall -std=c++2a -fconcepts -g -ggdb
LDFLAGS=-lstdc++ 
EXEC=mplay
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

mplay: $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

