# Liam Tolbert, lct4am, 10/7/2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g

avl: AVLNode.o AVLPathTest.o AVLTree.o
	$(CXX) $(DEBUG) AVLNode.o AVLPathTest.o AVLTree.o

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h


.PHONY: clean
clean:
	-rm -f *.o *~a.out
