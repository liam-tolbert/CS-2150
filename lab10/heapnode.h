#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <string>
using namespace std;

class heapnode {
public:
	heapnode();
	heapnode(string str, int freq, heapnode* l, heapnode* r);
	~heapnode();
	int frequency;
	string data;
	heapnode* left;
	heapnode* right;
private:
	
};

#endif
