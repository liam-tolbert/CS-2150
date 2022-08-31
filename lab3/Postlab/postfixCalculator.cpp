#include <string>
#include <iostream>

#include "postfixCalculator.h"
#include "stack.h"

using namespace std;

// Liam Tolbert, lct4am, 9/15/2021, postfixCalculator.cpp

PostFixCalculator::PostFixCalculator(){
  stack = new Stack();
}

PostFixCalculator::~PostFixCalculator(){
  delete stack;
}

void PostFixCalculator::input(string input){
  if(input != "-"
     && input != "+"
     && input != "*"
     && input != "/"
     && input != "~"){
    stack->push(stoi(input));
  }
  else{
    if(!stack->empty()){
      int operand1 = 0;
      int operand2 = 0;
      if(input == "+"){
	operand1 = stack->top();
	stack->pop();
	operand2 = stack->top();
	stack->pop();
	stack->push(operand1 + operand2);
      }
      else if(input == "-"){
        operand1 = stack->top();
	stack->pop();
	operand2 = stack->top();
	stack->pop();
	stack->push(operand2 - operand1);
      }
      else if(input == "*"){
	operand1 = stack->top();
	stack->pop();
	operand2 = stack->top();
	stack->pop();
	stack->push(operand1 * operand2);
      }
      else if(input == "/"){
	operand1 = stack->top();
	stack->pop();
	operand2 = stack->top();
	stack->pop();
	stack->push(operand2 / operand1);
      }
      else if(input == "~"){
        operand1 = stack->top();
	stack->pop();
	stack->push(operand1 * -1);
      }
    }
  }
}

int PostFixCalculator::result(){
  return !stack->empty() ? stack->top() : 0;
}


