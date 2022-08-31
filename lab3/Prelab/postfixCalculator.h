#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <string>
#include <stack>


using namespace std;

// Liam Tolbert, lct4am, 9/13/2021, postfixCalculator.h

class PostFixCalculator {
 public:
  PostFixCalculator();
  ~PostFixCalculator();
  void input(string input);
  int result();
 private:
  stack<int> stack;
};

#endif
