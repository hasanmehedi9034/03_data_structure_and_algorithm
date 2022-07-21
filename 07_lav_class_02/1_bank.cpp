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

        void deposit_money(string password, int amount) {
            if (this->password == password) {
                this->balance -= amount;
            }
            else {
                cout << "password didnt match ";
            }
        }
    friend class My_cash;
    protected:
        int balance;

    private:
        string password;
};

class My_cash {
    protected:
        int balance;
    
    public:
        My_cash() {
            this->balance = 0;
        }
        void add_money_form_bank(Bank_Account *my_account, string password, int amount) {
            if (my_account->password == password) {
                this->balance += amount;
                my_account->balance -= amount;
                cout << "Add money from bank successful" << endl;
            }
            else {
                cout << "Password didnt match" << endl;
            }
        }
        int show_balance() {
            return balance;
        }
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

void deposit_money(Bank_Account *my_accout) {
    string password;
    int amount;
    cout << "DEPOSIT MONEY" << endl;

    cin >> password >> amount;
    my_accout->deposit_money(password, amount);
}

void add_money_from_bank(My_cash *my_cash, Bank_Account *my_account) {
    string password;
    int amount;
    cout << "ADD MONEY FROM BANK" << endl;

    cin >> password >> amount;
    my_cash->add_money_form_bank(my_account, password, amount);
    cout << "Your balance is :" << my_account->show_balance("mehedi") << endl;
    cout << "My cash balance :" << my_cash->show_balance() << endl;
}

int main() {
    Bank_Account *my_account = create_account();

    while (true) {
        cout << "Select option" << endl;
        cout << "1. Add money to bank" << endl;
        cout << "2. deposit money to bank" << endl;
        cout << "3. Add money to MyCash from bank" << endl;
        int option;
        cin >> option;
    }

    // if (my_account->show_balance("mehedi") == -1) {
    //     cout << "password didnt match";
    // }
    // else {
    //     cout << my_account->show_balance("mehedi") << endl;
    // }


    // add_money(my_account);
    // cout << "Your balance is :" << my_account->show_balance("mehedi") << endl;


    add_money(my_account);
    cout << "Your balance is :" << my_account->show_balance("mehedi") << endl;

    My_cash *my_cash = new My_cash();
    add_money_from_bank(my_cash, my_account);
    cout << "Your balance is :" << my_account->show_balance("mehedi") << endl;
    
}