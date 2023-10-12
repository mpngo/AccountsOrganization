#pragma once
 #include "CheckingAccount.h"
#include "UserAccount.h"
 //#include "Helper.h"
 #include<iostream>
 CheckingAccount::CheckingAccount(){}

CheckingAccount::CheckingAccount(std::string accountName, int id, int accountNumber, double accountBalance) : UserAccount(accountName, id, accountNumber, accountBalance){}

 string CheckingAccount::toString(){
    return  "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
               "Account Balance: "+fixPoint(std::to_string(getAccountBalance()))+"\n"
               +
               "Account Type: Checking \n";
     }
bool CheckingAccount::withdraw(double amount){
  if (amount > 0){
    if (getAccountBalance()-amount>MIN_BALANCE){
      double temp = getAccountBalance()-amount;
      setAccountBalance(temp);
      return true;
      }
    else 
      return false;
  }
  else {
    return false;
  }
}
 
void CheckingAccount::deposit(double amount){
  setAccountBalance(getAccountBalance() + amount);
        if (amount > MIN_REWARD_AMOUNT)
           addReward(amount);
}
const  double  CheckingAccount::MIN_BALANCE_CHECKING=99.99;

