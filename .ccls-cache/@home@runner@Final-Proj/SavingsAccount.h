#pragma once
#include "UserAccount.h" 
//#include "Helper.h"        
class SavingsAccount: public UserAccount{
  //const static  double  MIN_BALANCE;
  
  public:
      SavingsAccount();
      SavingsAccount(std::string accountName, int id,int accountNumber, double accountBalance);
      string toString();
      bool withdraw(double amount);
      void deposit(double amount);
      //virtual bool operator==(shared_ptr<SavingsAccount> a );
};