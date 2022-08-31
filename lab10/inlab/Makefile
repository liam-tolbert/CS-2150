CXX=clang++ -std=c++11 $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g

heap: huffmandec.o
	$(CXX) $(DEBUG) huffmandec.o
huffmandec.o: huffmandec.cpp

.PHONY: clean
clean:
	-rm -f *.o *~a.out
