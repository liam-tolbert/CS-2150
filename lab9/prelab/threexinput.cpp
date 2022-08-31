#include <iostream>
#include "timer.h"
#include <string>
using namespace std;

extern "C" long threexplusone(long x);

int main(){
  long x, n, once;
  double avg;
  double avgmilisec;
  timer time;
  once = 0;
  cout << "Enter a number: ";
  cin >> x;
  cout << "Enter iterations of subroutine: ";
  cin >> n;

  once = threexplusone(x);

  time.start();
  
  for(int i = 0; i < n; i++){
    threexplusone(x);
  }
  
  time.stop();
  
  cout << "Iterations: " + to_string(once) << endl;
  avg = time.getTime() / n;

  avgmilisec = avg * 1000;

  return 0;
}
