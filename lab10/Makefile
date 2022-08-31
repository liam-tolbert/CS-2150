CXX=clang++ -std=c++11 $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g

heap: heap.o heapnode.o huffmanenc.o
	$(CXX) $(DEBUG) heap.o heapnode.o huffmanenc.o
heap.o: heap.cpp heap.h heapnode.h
heapnode.o: heapnode.cpp heapnode.h
huffmanenc.o: huffmanenc.cpp heap.h heapnode.h

.PHONY: clean
clean:
	-rm -f *.o *~a.out
