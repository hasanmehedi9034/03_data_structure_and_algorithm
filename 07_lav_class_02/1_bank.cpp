#include <bits/stdc++.h>
using namespace std;

class Bank_Account {
    public:
        string account_holder;
        string address;
        int age;
        int account_number;
        Bank_Account(string account_holder, string address, int age, string password) {
            this->account_holder = account_holder;
            this->address = address;
            this->age = age;
            this->password = password;
            this->account_number = rand() % 100000000;
            this->balance = 0;
        }

        int show_balance (string password) {
            if (this->password == password) {
                return this->balance;
            }
            else {
                return -1;
            }
        }

        void add_money(string password, int amount) {
            if (this->password == password) {
                this->balance += amount;
                cout << "Add money successfull";
            }
            else {
                cout << "Password didnt match, ";
            }
        }

    protected:
        int balance;

    private:
        string password;
};

Bank_Account *create_account() {
    string account_holder, password, address;
    int age;
    cout << "CREATE ACCOUNT" << endl;
    cin >> account_holder >> address >> age >> password;

    Bank_Account *my_account = new Bank_Account(account_holder, address, age, password);
    return my_account;
}

void add_money(Bank_Account *my_account) {
    string password;
    int amount;
    cout << "ADD MONEY"<< endl;

    cin >> password >> amount;
    my_account->add_money(password, amount);
}

int main() {
    Bank_Account *my_account = create_account();

    // if (my_account->show_balance("mehedi") == -1) {
    //     cout << "password didnt match";
    // }
    // else {
    //     cout << my_account->show_balance("mehedi") << endl;
    // }


    add_money(my_account);
    cout << "Your balance is :" << my_account->show_balance("mehedi") << endl;
}