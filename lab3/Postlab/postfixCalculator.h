#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "stack.h"

using namespace std;

// Liam Tolbert, lct4am, 9/15/2021, postfixCalculator.h

class PostFixCalculator {
 public:
  PostFixCalculator();
  ~PostFixCalculator();
  void input(string input);
  int result();
 private:
  Stack* stack;
};

#endif
