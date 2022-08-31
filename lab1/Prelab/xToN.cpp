#include <iostream>
using namespace std;

// Liam Tolbert, lct4am, 8/28/2021, xToN.cpp

int xton(int x, int n)
{
  if(n < 1)
    return 1;
  return x * xton(x, n - 1);
}

int main()
{
  int x, n;
  cin >> x;
  cin >> n;
  int z = xton(x, n);
  cout << z << endl;
  return 0;
}
