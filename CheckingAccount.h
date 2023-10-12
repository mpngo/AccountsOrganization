#pragma once
#include "UserAccount.h"
 class CheckingAccount: public UserAccount{
   public:
const static  double  MIN_BALANCE_CHECKING;
public:
  CheckingAccount();  
  CheckingAccount(std::string accountName, int id,int accountNumber, double accountBalance);
  string toString();
  bool withdraw(double amount);
  void deposit(double amount);
   //virtual bool operator==(shared_ptr<CheckingAccount> a );
};