#include <bits/stdc++.h>
using namespace std;

class BankAccount {
    public:
        string account_holder;
        string address;
        int age;
        int account_number;
    protected:
        int balance;
    private:
        string password;
    
    public:
        BankAccount(string account_holder, string address, int age, string password) {
            this->account_holder = account_holder;
            this->address = address;
            this->age = age;
            this->password = password;
            this->account_number = rand() % 1000000000;
            this->balance = 0;
        }
        int show_balance(string password) {
            if (password == this->password) return this->balance;
            return -1;
        }
};

BankAccount *create_account () {
    string account_holder;
    string address;
    string password;
    int age;

    cout << "CREATE ACCOUNT : NAME(string), ADDRESS(string), AGE(age), PASSWORD(string)" << endl;
    cin >> account_holder >> address >> age >> password;

    BankAccount *my_account = new BankAccount(account_holder, address, age, password);
    return my_account;
}

int main() {
    BankAccount *myAccount = create_account();
    
    // if (!myAccount->show_balance("mehedi") == -1) cout << "password didnt match" << endl;
    // else cout << "Your balance is : " << myAccount->show_balance("mehedi") << endl;
}