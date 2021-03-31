//
//  main.cpp
//  Bank Software
//
//  Created by jason eastman on 3/30/21.
/*
 Menu features:
 Make account
 deposit money
 withdrawl money
 display account information
 print all accounts
 */



#include <iostream>
#include <vector>
using namespace std;

struct customer_account{
    int customer_id;
    float balance;
    string customer_name;
};

int findAccount(vector<customer_account>&);

void menu(vector<customer_account>&);
void depositMoney(vector<customer_account>&);
void withdrawlMoney(vector<customer_account>&);
void displayInfo(vector<customer_account>&);
void displayAccounts(vector<customer_account>&);
void createAccount(vector<customer_account>&);


int main(int argc, const char * argv[]) {
    vector <customer_account> database;
    menu(database);
    return 0;
}

void menu(vector<customer_account>&accounts){
    cout << "Enter menu selection: \n(1) Create Account \n(2) Deposit Money\n(3) Withdrawl Money\n(4) Display Account Info\n(5) Display All Accounts\n(6) End Program\n";
    int input;
    cin >> input;
    while(input < 7 && input > 0){
        if(input == 1){createAccount(accounts);}
        if(input == 2) {depositMoney(accounts);}
        if(input == 3) {withdrawlMoney(accounts);}
        if(input == 4) {displayInfo(accounts); }
        if(input == 5) {displayAccounts(accounts);}
        if(input == 6) {exit(3);  }
    }
    menu(accounts);
}
int findAccount(vector<customer_account>& accounts){
    int id = 0;
    cout << "Enter ID:";
    cin >> id;
    customer_account temp = {0,0,"nothing"};
    for(int i = 0; i < accounts.size();i++){
        if(accounts[i].customer_id == id){
            return i;
        }
    }
    cout << "ID is invalid\n";
    menu(accounts);
    return 0;
}
void displayAccounts(vector<customer_account>&accounts){
    for(int i = 0; i<accounts.size(); i++){
        cout << accounts[i].customer_id << endl << accounts[i].balance << endl << accounts[i].customer_name << endl;
    }
    menu(accounts); 
}
void depositMoney(vector<customer_account>&accounts){
    int temp = findAccount(accounts);
    int amt;
    cout << "Enter amount: \n";
    cin >> amt;
    accounts[temp].balance += amt;
    cout << accounts[temp].balance << endl;
    menu(accounts);
}
void withdrawlMoney(vector<customer_account>&accounts){
    int temp = findAccount(accounts);
    int amt;
    cout << "Enter amount: \n";
    cin >> amt;
    accounts[temp].balance -= amt;
    menu(accounts);
}

void displayInfo(vector<customer_account>&accounts){
    int temp = findAccount(accounts);
    cout << accounts[temp].customer_id << endl << accounts[temp].balance << endl << accounts[temp].customer_name << endl;
    menu(accounts);
}
void createAccount(vector<customer_account>&accounts){
    int newID = 100 + int(accounts.size()); // vector is zero-based so the size will give use index size + one, int cast to clear warning
    if(newID == 0){
        newID = 1;
    }
    string newName;
    cout << "Enter name\n";
    cin >> newName;
    customer_account temp = {newID,0,newName};
    accounts.push_back(temp);
    cout << temp.balance << endl << temp.customer_id << endl << temp.customer_name << endl; 
    menu(accounts);
}
