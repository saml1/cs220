CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

CTreeTest: CTree.o CTreeTest.o
	g++ -o CTreetest CTree.o CTreeTest.o

CTreeTest.o: CTreeTest.cpp CTree.h
	g++ -c CTreeTest.cpp $(CFLAGS)

CTree.o: CTree.cpp CTree.h
	g++ -c CTree.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o main?  *~
