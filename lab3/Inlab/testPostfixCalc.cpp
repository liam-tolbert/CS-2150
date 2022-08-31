#include <iostream>
#include <string>
#include "postfixCalculator.h"
using namespace std;

// Liam Tolbert, lct4am, 9/15/2021, testPostFixCalc.cpp

int main(){
  string token;
  PostFixCalculator* p = new PostFixCalculator();
  while(cin >> token){
    p->input(token);
  }
  cout << p->result() << endl;
  delete p;
  return 0;
}
