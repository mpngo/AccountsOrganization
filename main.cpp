#include <iostream>
#include "Bank.h"
int main() {
    shared_ptr<UserAccount> newAcc = make_shared<CheckingAccount>("John Smith",9999,1120,154.67);
    shared_ptr<UserAccount> remove = make_shared<CheckingAccount>("Fernando Diaz",323468, 1234,  250.0);
    shared_ptr<UserAccount> temp = make_shared<SavingsAccount>("Lily Zhaou",786534,1242,001.98);
    //temp->withdraw(100);
    shared_ptr<UserAccount> temp2= make_shared<CheckingAccount>("Vai vu",432657,1240,987.56);
    string filename;
    int action;
    cout << "What is the file name  ?";
    cin >> filename; // Bankdata.txt
    Bank WellsFargo(filename); //test action 1 : incorrect file name
    WellsFargo.sortAccounts();
    WellsFargo.displayAccounts();
    
    for (int i = 0; i <9 ; i++) { // a total of 9 tests from test 2 through test 10
        cout << "Which action would you like to test ?";
        cin >> action;
        if (action == 2) { // add a new account
            string accountName;
            WellsFargo.displayAccounts();
            WellsFargo.addAccount(newAcc);
            cout << "***** Adding New Account *****" << endl;
           // WellsFargo.displayAccount(temp);
          std::cout<<newAcc->toString()<<endl;
            cout << "***** Displaying Resulting Sorted Database *****" << endl;
            WellsFargo.displayAccounts();
            
        } else if (action == 3) { //remove and display
            WellsFargo.displayAccounts();
            WellsFargo.removeAccount(remove);
            cout << "***** Removing Account *****" << endl;
           // WellsFargo.displayAccount(temp);
          std::cout<<remove->toString()<<endl;
            cout << "***** Displaying Resulting Sorted Database *****" << endl;
            WellsFargo.displayAccounts();
            if (WellsFargo.removeAccount(remove))
                cout << "***** Account Does not Exist *****" << endl;
            
        } else if (action == 4) { // backing up accounts
            Bank Backup(WellsFargo);
            WellsFargo.displayAccounts();
            if (Backup.checkSame(WellsFargo))
                cout << "Verified Backup" << endl << endl; // verifying that they are same;
            else
                cout << "Backup Error " << endl << endl;
            
        } else if (action == 5) { // back up and remove account from original
            Bank Backup(WellsFargo);
            WellsFargo.displayAccounts();
            WellsFargo.removeAccount(temp2);

            /*
            WellsFargo.displayAccounts();
            std::cout<<"---- printing backup";
            Backup.displayAccounts();
          */
          
            if (Backup.checkSame(WellsFargo))
                cout << "Verified Backup" << endl << endl; // verifying that they are same;
            else
                cout << "Backup Error Databases do not match" << endl << endl;
            
        } else if (action == 6) { // withdraw money from CheckingAccount
            WellsFargo.addAccount(temp2);
            WellsFargo.displayAccounts();
            if (WellsFargo.accountWithdraw(temp2, 20))
                cout << "Withdraw Successful for this amount 20$" << endl;
            else
                cout << "Withdraw Unsuccessful for this amount 20$" << endl;
            //WellsFargo.displayAccounts(temp2);
           std::cout<<temp2->toString()<<endl;
            if (WellsFargo.accountWithdraw(temp2, -20))
                cout << "Withdraw Successful for this amount -20$" << endl;
            else
                cout << "Withdraw Unsuccessful for this amount -20$" << endl;
           // WellsFargo.displayAccounts(temp2);
            std::cout<<temp2->toString()<<endl;
        } else if (action == 7) { // action 7
            WellsFargo.displayAccounts();
            if (WellsFargo.accountWithdraw(temp, 100))
                cout << "Withdraw Successful for this amount 100$" << endl;
            else
                cout << "Withdraw Unsuccessful for this amount - Minimum funds 99.99" << endl;
           // WellsFargo.displayAccounts(temp);
          std::cout<<temp->toString()<<endl;
            if (WellsFargo.accountWithdraw(temp, 5000))
                cout << "Withdraw Successful for this amount 5000$" << endl;
            else
                cout << "Withdraw Unsuccessful - Insufficient funds for this amount 5000$" << endl;
          std::cout<<temp2->toString()<<endl;
           // WellsFargo.displayAccounts(temp);
            
        } else if (action == 8) { // withdraw money from savings account
            WellsFargo.displayAccounts();
            WellsFargo.accountWithdraw(temp,20);
            if (WellsFargo.accountWithdraw(temp, 20))
                cout << "Withdraw Successful" << endl;
            else
                cout << "Withdraw Unsuccessful - Cannot Withdraw from Savings Account" << endl;
           // WellsFargo.displayAccounts(temp);
          std::cout<<temp->toString()<<endl;
            
            
        } else if (action == 9) { // deposit money into savings
            WellsFargo.displayAccounts();
            if (WellsFargo.accountDeposit(temp, 1001))
                cout << "Deposit Successful for $1001 - rewards added" << endl;
            std::cout<<temp->toString()<<endl;
           // WellsFargo.displayAccounts(temp);
            if (WellsFargo.accountDeposit(temp, 20))
                cout << "Deposit Successful for $20" << endl;
          std::cout<<temp->toString()<<endl;
           // WellsFargo.displayAccount(temp);
            
        } else if (action == 10) { // deposit money into checking
            WellsFargo.displayAccounts();
            if (WellsFargo.accountDeposit(temp, -20))
                cout << "Deposit Successful" << endl;
            else
                cout << "Deposit Unsuccessful - Negative Amount: -$20" << endl;
            if (WellsFargo.accountDeposit(temp, 20))
                cout << "Deposit Successful for $20" << endl;
            else
                cout << "Deposit Unsuccessful" << endl;
        } else {
            cout << "Testing Ends" << endl;
            exit(0);
        }
    }
}