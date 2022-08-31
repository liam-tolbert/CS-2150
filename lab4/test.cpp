#include <iostream>

using namespace std;

bool b = true;
char c = '0';
char c1 = '1';
unsigned int i = 1;
double d = 0.0;
float f = 1.0;

int axis = 100;
int* ip = NULL;
char* ch = NULL;
double* db = NULL;

int IntArray[5] = {1, 2, 3, 4, 5};
char CharArray[5] = {'a','b','c','d','e'};

int IntArray2D[6][5] ={{1,2,3,4,5},
		       {6,7,8,9,10},
		       {11,12,13,14,15},
		       {16,17,18,19,20},
		       {21, 22, 23, 24, 25},
		       {26, 27, 28, 29, 30}
};

int main(){
  cout << "printing" << endl;
  cout << sizeof(double*) << endl;
  cout << b << "\n" << c << "\n" << d << "\n" << ip << endl;
}
