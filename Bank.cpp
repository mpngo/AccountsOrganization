
#include "Bank.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include "GreaterThan.h"
#include "UserAccount.h"
void fillVector (ifstream &input,vector<shared_ptr<UserAccount>> &accountsVector){
  std::string accountName, lastName, firstName, inputLine, type;
  int id,accountNumber;
  double accountBalance;

  while (!input.eof()){
    getline(input,inputLine);
    std::istringstream streamLine(inputLine);
    streamLine >> firstName >> lastName >> id >> accountNumber >> accountBalance >> type;
    accountName = firstName + " " + lastName;

    if (type == "S"){
      std::shared_ptr<UserAccount> temp = std::make_shared<SavingsAccount>(accountName,id,accountNumber,accountBalance);
      accountsVector.push_back(temp); //adds object to vector
    }
    else if (type == "C"){
      std::shared_ptr<UserAccount> temp = std::make_shared<CheckingAccount>(accountName,id,accountNumber,accountBalance);
      accountsVector.push_back(temp);
    }
  }
  
}
void Bank::displayAccounts(){
  std::cout<<" In display account "<<accountsVector.size()<<std::endl;
  for (int i = 0; i < accountsVector.size(); i++){
    cout << accountsVector[i] -> toString() << endl;
  }
}

Bank::Bank(const Bank &other){
  cout<<"In copy constructor  "<<endl;

  
  //cout<<accountsVector.size()<<endl;
  //create a cop constructor that copies the two vectors
  for (int i = 0; i < other.getSize(); i++){
       shared_ptr<UserAccount> temp = make_shared<UserAccount>();
       *temp = (other).getAccount(i);
       accountsVector.push_back(temp);
     }
}

int Bank::getSize()const{
  return accountsVector.size();
}

shared_ptr<UserAccount> Bank::getAccount(int index) const{
  return accountsVector[index];
}


Bank::Bank(string filename){
 // throw File Open Error - File Exception -99 if file cannot be opened
//use try catch statement
  ifstream inputFile(filename);
    try{
      if (inputFile){
        fillVector(inputFile, accountsVector);
      }
      else throw string("File Open Error -99");
    }
  catch (string message){
    cout << message << endl;
    exit(0); //exits program if file cannot be open
  }
}

void Bank::addAccount(shared_ptr<UserAccount> a)//should sort vector
{
  //add an account
  // be sure to keep vector sorted
 //use STL sort using Greater THan Function Object
  accountsVector.push_back(a);
  sort(accountsVector.begin(), accountsVector.end(), GreaterThan());
}
void Bank::sortAccounts(){
  
  // use the STL sort by passing the beginning, end and Greater Than Functor
  sort(accountsVector.begin(), accountsVector.end(), GreaterThan());
}

bool Bank::accountDeposit(shared_ptr<UserAccount> a, double amount){
 // return false if amount is negative
 // return true after depositing into account

  if (amount < 0){
    return false;
  }
  else {
    a -> setAccountBalance((a -> getAccountBalance()) + amount);
      if (amount > UserAccount::MIN_REWARD_AMOUNT){
        a -> addReward(amount);
      }
    return true;
  }
}
bool Bank::accountWithdraw(shared_ptr<UserAccount> a, double amount){
  if (amount > 0) {
    if ((a -> getAccountBalance() - amount) > UserAccount::MIN_BALANCE){
      a->setAccountBalance(a -> getAccountBalance() - amount);
      return true;
    }
    else {
      return false; // do nothing
    }
  }
  else {
    return false;
  }

}
bool Bank::checkSame( Bank &other){
 // check if this bank has the exact same accounts as the other bank
 //use equalTo method created in the UserAccount class (that implments Comparable)
 // return true if same, false otherwise  
  // equalTo should check if each and every field matches
  bool check = true;
  if (accountsVector.size() != other.getSize()){
    return false;
  }
  else {
    for (int i = 0; i < accountsVector.size(); i++){
      if (accountsVector[i] -> equalTo(other.getAccount(i)) == 0){
        check = false;
        cout << check;
      }
    }
  }
  return check;
}
bool Bank::removeAccount(shared_ptr<UserAccount> a){

  //search for the the given account a, if found
  //use vector.erase method to remove it and return true
  //otherwise return false
  
  int id = a -> getId();
  int number = a -> getAccountNumber();
  int index = -1;

  int i;
  for (i = 0; i < accountsVector.size(); i++){
    if (accountsVector[i] -> getAccountNumber() == number && accountsVector[i] -> getId() == id){
        index = i;
    }
  }



  if (index < 0){
    cout << "Account not found. " << endl;
    return false;
  }
  else {
    cout << "Account found, erasing... " << endl;
    accountsVector.erase(accountsVector.begin() + (index));
    return true;
  }
}

