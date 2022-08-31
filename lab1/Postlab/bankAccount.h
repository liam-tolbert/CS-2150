#include <iostream>
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
using namespace std;

// Liam Tolbert, lct4am, 8/28/2021, bankAccount.h

class bankAccount {
 public:
  bankAccount();
  bankAccount(double amount);
  ~bankAccount();

  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();

 private:
  double balance;
  
  
};

#endif
