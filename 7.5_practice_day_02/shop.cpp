#include <bits/stdc++.h>
using namespace std;

class Shop {
    public:
        string product_name[10];
        int product_price[10];
        int product_quantity[10];
        int total_number_of_product;

    private:
        int total_income;

    public:
        Shop() {
            this->total_income = 0;
            this->total_number_of_product = 0;
        }

        int get_total_income() {
            return this->total_income;
        }

        bool buy_product(int quantity, int product_index) {
            if (quantity <= this->product_quantity[product_index]) {
                this->total_income += product_price[product_index] * quantity;
                this->product_quantity[product_index] -= quantity;
                cout << "Your total income : " << this->get_total_income() << endl;
                return true;
            }
            else {
                cout << "insuficient Quantity" << endl;
                return false;
            }
        }
};

bool buy_product(Shop *shop, int n) {
    int pd_index;
    cout << "which product do you want? from 1 to " << n << ": ";
    cin >> pd_index;

    int pd_quantity;
    cout << "what is the quantity that you want to " << shop->product_name[pd_index - 1] << ": ";
    cin >> pd_quantity;

    bool is_bought = shop->buy_product(pd_quantity, (pd_index - 1));
    return is_bought;
}


void take_product(Shop *shop, int n) {
    string name;
    int price, quantity;

    cout << "input products : name, price, quantity :" << endl;
    for (int i = 0; i < n; i++) {
        cin >> name >> price >> quantity;
        shop->product_name[i] = name;
        shop->product_price[i] = price;
        shop->product_quantity[i] = quantity;
    }
}

void  print_product(Shop *shop, int n) {
    cout << "ALL PRODUCTS " << endl;
    cout << "-------------" << endl;

    cout << "Product index\t";
    for (int i = 0; i < n; i++) {
        cout << "\t" << i + 1;
    }
    cout << endl;

    cout << "Product Name\t";
    for(int i = 0; i < n; i++) {
        cout << "\t" << shop->product_name[i] ;
    }
    cout << endl;

    cout << "Product Price \t";
    for(int i = 0; i < n; i++) {
        cout << "\t" << shop->product_price[i] ;
    }
    cout << endl;

    cout << "Product Quantity\t";
    for(int i = 0; i < n; i++) {
        cout << shop->product_quantity[i] << "\t";
    }
    cout << endl;
}

int main() {
    Shop *shop = new Shop();

    int n;
    cout << "Number of Products : ";
    cin >> n;

    take_product(shop, n);
    print_product(shop, n);
    buy_product(shop, n);
    print_product(shop, n);
    cout << shop->get_total_income() << endl;
}