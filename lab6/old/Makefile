# Liam Tolbert, lct4am, 3/30/2021

CXX=clang++ -O2 $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g

hash: HashTable.o wordPuzzle.o
	$(CXX) $(DEBUG) HashTable.o wordPuzzle.o

HashTable.o: HashTable.cpp HashTable.h
wordPuzzle.o: wordPuzzle.cpp


.PHONY: clean
clean:
	-rm -f *.o *~a.out
