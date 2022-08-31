CXX = clang $(CXXFLAGS)
CXXFLAGS = -Wall -g
OBJECTS = linkedlist.o

linkedlist: linkedlist.o
	$(CXX) $(CXXFLAGS) $(OBJECTS)

linkedlist.o: linkedlist.c

.PHONY: clean
clean:
	-rm -f *.o *.~ linkedlist
