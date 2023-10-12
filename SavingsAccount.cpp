#pragma once
#include "SavingsAccount.h"
#include<iostream>
#include "UserAccount.h"
//#include "Helper.h"
 SavingsAccount::SavingsAccount(){}
     
SavingsAccount::SavingsAccount(std::string accountName, int id, int accountNumber, double accountBalance) : UserAccount(accountName, id, accountNumber, accountBalance){}

 string SavingsAccount::toString(){
      return "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
              "Account Balance: " +fixPoint(std::to_string(getAccountBalance()))+"\n"
              +
               "Account Type: Savings \n";
    }
 bool SavingsAccount::withdraw(double amount){
    return false; // do nothing
}
void SavingsAccount::deposit(double amount){
        setAccountBalance(getAccountBalance() + amount);
        if (amount > MIN_REWARD_AMOUNT)
           addReward(amount);
    }
   