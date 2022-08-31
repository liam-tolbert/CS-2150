#include <iostream>
#include "bankAccount.h"
using namespace std;

// Liam Tolbert, lct4am, 8/28/2021, bankAccount.cpp

bankAccount::bankAccount()
{
  balance = 0;
}

bankAccount::bankAccount(double amount)
{
  balance = amount;
}

bankAccount::~bankAccount()
{
  
}

double bankAccount::withdraw(double amount)
{
  if(amount > balance)
    return balance;
  else
    {
      balance = balance - amount;
      return balance;
    }
}

double bankAccount::deposit(double amount)
{
  balance = balance + amount;
  return balance;
}

double bankAccount::getBalance()
{
  return balance;
}
  
