#include "GreaterThan.h"
#include "UserAccount.h"
  bool GreaterThan::operator()( shared_ptr<UserAccount> a, shared_ptr<UserAccount>b){
    return a->getAccountNumber()<b->getAccountNumber();
  }