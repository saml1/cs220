CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

cTreeTest: cTreeTest.o
	g++ -o cTreetest cTreeTest.o

cTreeTest.o: CTreeTest.cpp CTree.cpp CTree.h
	g++ -c CTreeTest.cpp CTree.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o main?  *~
