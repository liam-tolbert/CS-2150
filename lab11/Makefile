CXX=clang++ -std=c++11 $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
DOXYGEN=doxygen

puzzle: 8numPuzzle.o
	$(CXX) $(DEBUG) 8numPuzzle.o
	$(DOXYGEN)
8numPuzzle.o: 8numPuzzle.cpp

.PHONY: clean
clean:
	-rm -f *.o *~a.out
