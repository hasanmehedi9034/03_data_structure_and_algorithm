#include <bits/stdc++.h>
using namespace std;

class Bank_account {
    public:
        string name;
        string address;
    protected:
        int balance;
        int account_number;
    private:
        string password;

    public:
        Bank_account(string name, string address, string password) {
            this->name = name;
            this->address = address;
            this->password = password;
            this->balance = 0;
            this->account_number = rand() % 10000000;
        }

        int get_account_number() {
            return this->account_number;
        }

        int get_balance(string password) {
            if (this->password ==password) return this->balance;
            else return -1;
        }

        void add_money(string password, int amount){
            if(this->password == password) {
                this->balance += amount;
                cout <<"Add money successfull" << endl;
            }
            else {
                cout << "Password didnt match " << endl;
            }
        }

        void withdraw(string pass, int amount) {
            if (this->password != pass) {
                cout << "Password didnt match for withdraw" << endl;
                return;
            }
            if (this->balance < amount) {
                cout << "insuficient balance" << endl;
                return;
            }
            this->balance -= amount;
            cout << "withdraw successful" << endl;
        }
        friend class My_cash;
};

class My_cash{
    protected:
        int balance;
    public:
        My_cash() {
            this->balance = 0;
        }
        void add_money_from_bank(Bank_account *bank, string password, int amount) {
            if (password == bank->password) {
                this->balance += amount;
                bank->balance -=  amount;
                cout << "add money from bank successfull" << endl;
            }
            else {
                cout << "password didnt mathch" << endl;
            }
        }
        int get_my_cash_balance() {
            return this->balance;
        }
};

Bank_account *create_account() {
    string name, address, password;
    cout << "CREATE ACCOUNT : NAME, ADDRESS, PASSWORD :" << endl;
    cin >> name >> address >> password;

    Bank_account *my_account = new Bank_account(name, address, password);
    return my_account;
}

void add_money(Bank_account *my_account) {
    cout << "ADD MONEY: PASSWORD, AMOUNT" << endl;

    string password;
    int amount;
    cin >> password >> amount;

    my_account->add_money(password, amount);
}

void withdraw(Bank_account *my_account) {
    cout << "WITHDRAW MONEY: PASSWORD, AMOUNT" << endl;

    string password;
    int amount;
    cin >> password >> amount;

    my_account->withdraw(password, amount);
}

void add_money_from_bank(Bank_account *bank, My_cash *my_cash) {
    cout << "ADD MONEY FROM BANK: PASSWORD, AMOUNT" << endl;

    string password;
    int amount;
    cin >> password >> amount;

    my_cash->add_money_from_bank(bank, password, amount);
}

int main() {
    Bank_account *my_account = create_account();
    My_cash *my_cash = new My_cash();

    add_money(my_account);
    withdraw(my_account);
    add_money_from_bank(my_account, my_cash);

    cout << "your bank balance is : " << my_account->get_balance("mehedi") << endl;
    cout << "your My_cash balance is : " << my_cash->get_my_cash_balance("mehedi") << endl;
}