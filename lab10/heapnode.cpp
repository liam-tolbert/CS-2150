#include "heapnode.h"

using namespace std;

heapnode::heapnode()
{
  data = "";
  frequency = 0;
  left = NULL;
  right = NULL;
}

heapnode::heapnode(string str, int freq, heapnode* l, heapnode* r){
  data = str;
  frequency = freq;
  left = l;
  right = r;
}

heapnode::~heapnode(){}
