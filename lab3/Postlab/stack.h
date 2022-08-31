#ifndef STACK_H
#define STACK_H

#include "List.h"
#include "ListItr.h"

using namespace std;

// Liam Tolbert, lct4am, 9/15/2021, stack.h

class Stack {
 public:
   Stack();
   ~Stack();
   
   void push(int x);
   int top();
   void pop();
   int size();
   bool empty();
  private:
   List* list;
};

#endif
