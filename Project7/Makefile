CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -O2

PROG ?= Main
OBJS = quickSelect.o insertionSort.o Book.o MoveAll.o Main.o

all: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(EXEC) *.o *.out Main 

rebuild: clean all