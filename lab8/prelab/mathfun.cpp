// Liam Tolbert, lct4am, 11/1/2021, mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power(int, int);

int main(){
  int first, second;

  cout << "Enter Integer 1: ";
  cin >> first;
  cout << "Enter Integer 2: ";
  cin >> second;

  int prodRes = product(first, second);
  int powerRes = power(first, second);

  cout << "Product: " << prodRes << endl;
  cout << "Power: " << powerRes << endl;
  return 0;
}
