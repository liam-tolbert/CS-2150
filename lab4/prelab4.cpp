#include <iostream>
using namespace std;

void sizeOfTest();
void overflow();
void outputBinary(unsigned int x);

// Liam Tolbert, lct4am, 9/17/2021, prelab4.cpp

int main()
{
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);

  return 0;
}

void sizeOfTest(){
  cout << "Size of int: " << sizeof(int)  << "\n"
       << "Size of unsigned int: " << sizeof(unsigned int)  << "\n"
       << "Size of float: " << sizeof(float)  << "\n"
       << "Size of double: " << sizeof(double)  << "\n"
       << "Size of char: " << sizeof(char) << "\n"
       << "Size of bool: " << sizeof(bool)  << "\n"
       << "Size of int*: " << sizeof(int*)  << "\n"
       << "Size of char*: " << sizeof(char*)  << "\n"
       << "Size of double*: " << sizeof(double*)  << "\n";
}
void overflow(){
  unsigned int x = 4294967295;
  cout << "4294967295 + 1 = " << x+1 <<endl;
}
void outputBinary(unsigned int x){
  int num[32] = {0};

  int i = 0;
  for(;x > 0;x /= 2){
    num[i++] = x % 2;
  }

  int k = 0;
  for(int j = 31; j >= 0; j--){
    cout << num[j];
    k++;
    if(k == 4){
      cout << " ";
      k = 0;
    }
  }
  cout << endl;
}
