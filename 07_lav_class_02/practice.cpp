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

        void add_money(string password, int amount) {
            if (amount < 0) {
                cout << "invalid amount" << endl;
                return;
            }
            if (password == this->password) this->balance += amount;
            else cout << "password didnt match for adding money" << endl;
        }

        void deposit_money(string password, int amount) {
            if (this->balance < amount) {
                cout << "insufficient balance " << endl;
                return;
            }
            if (password == this->password) {
                this->balance -= amount;
                cout << "Money withdraw successful" << endl;
            }
            else cout << "password didnt match" << endl;
        }

        friend class MyCash;
};

class MyCash {
    protected:
        int balance;
    
    public:
        MyCash() {
            this->balance = 0;
        }

        void add_money_form_bank(BankAccount *my_account, string password, int amount) {
            if (my_account->password == password) {
                this->balance += amount;
                my_account->balance -= amount;
                cout << "Add money from bank successful" << endl;
            }
            else {
                cout << "password didnt match inside myCash" << endl;
            }
        }

        int show_balance() {
            return this->balance;
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

void add_money (BankAccount *my_account) {
    string password;
    int amount;

    cout << "ADD MONEY : PASSWORD(string), AMOUNT(int)" << endl;
    cin >> password >> amount;
    my_account->add_money(password, amount);
}

void deposit_money(BankAccount *my_account) {
    string password;
    int amount;

    cout << "DEPOSIT MONEY : PASSWORD(string), AMOUNT(int)" << endl;
    cin >> password >> amount;
    my_account->deposit_money(password, amount);
}

void add_money_form_bank(MyCash *my_cash, BankAccount *myAccount) {
    string password;
    int amount;

    cout << "ADD MONEY TO MYCASH : PASSWORD(string), AMOUNT(int)" << endl;
    cin >> password >> amount;
    my_cash->add_money_form_bank(myAccount, password, amount);
}

int main() {
    BankAccount *myAccount = create_account();
    MyCash *myCash = new MyCash();
    
    while(true) {
        cout << "SELECT OPTION : " << endl;
        cout << "1. ADD MONEY TO BANK" << endl;
        cout << "2. DEPOSIT MONEY FROM BANK" << endl;
        cout << "3. ADD MONEY TO MYCAHS FROM BANK" << endl;

        int option;
        cin >> option;

        if (option == 1) {
            add_money(myAccount);
        }
        else if (option == 2) {
            deposit_money(myAccount)
        }
        else if (option == 3) {
            add_money_form_bank(myCash, myAccount);
        }
        else {
            cout << "Invalid  input " << endl;
        }
    }
}