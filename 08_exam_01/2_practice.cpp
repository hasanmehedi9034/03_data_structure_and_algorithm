#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
 
class Restaurant {
    public:
        int food_item_codes[12];
        string food_item_names[12];
        int food_item_prices[12];
        double total_tax;
 
    public:
        Restaurant() {
            this->total_tax = 0.0;
        }
};
 
void take_input(Restaurant *restaurent, int n) {
    int code, price;
    string name;
   
    for (int i = 0; i < n; i++) {
        int code, price;
        string name;
 
        cin.ignore();
        cin >> code;
 
        cin.ignore();
        getline(cin, name);
 
        cin >> price;
 
        restaurent->food_item_codes[i] = code;
        restaurent->food_item_names[i] = name;
        restaurent->food_item_prices[i] = price;
    }
}

bool is_valid_item(Restaurant *res, int item, int  n) {
    for (int i = 0; i < n; i++) {
        if (res->food_item_codes[i] == n) return true;
    }
    return false;
}

int take_order(int item_codes[], int item_quantity[], int n, Restaurant *res) {
    int table_no, number_of_items;
    
    cout << "Enter Table No : ";
    cin >> table_no;

    cout << "Enter Number of Item : ";
    cin >> number_of_items;

    for (int i = 0; i < number_of_items; i++) {
        cout << "Enter Item " << i + 1 << " Code : ";
        cin >> item_codes[i];

        while (!is_valid_item(res, item_codes[i], n)) {
            cout << "invalid input Code, Please Enter again " << i + 1 << " Code : ";
            cin >> item_codes[i];
        }

        cout << "Enter Item " << i + 1 << " Quantity : ";
        cin >> item_quantity[i];
    }
    return table_no;
}

int ordered_index (Restaurant *res, int a, int n) {
    for (int i = 0; i < n; i++) {
        if (a == res->food_item_codes[i]) {
            return i;
        }
    }
    return -1;
}

int print_order_summary(Restaurant *res, int a[], int n, int table_no, int quantity[]) {
    cout << endl;
    cout << "\t\t\t\t\tOrder Summary\t\t\t\t\t" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "Table No : " << table_no << endl;
    cout << "-----------"<< endl;

    cout << "Item code\t" << "Item Name\t\t\t" << "Item price\t" << "Item Quantity\t" << "Total Price" << endl;
    cout << "----------\t" << "---------\t\t\t" << "---------- \t" << "-------------\t" << "------------" << endl;

    int total = 0;
    for (int i = 0; i < n; i++) {
        int o_item = ordered_index(res, a[i], n);
        if (o_item != -1 && quantity[i] != 0) {
            cout << res->food_item_codes[o_item] << "\t\t";
            cout << res->food_item_names[o_item] << "\t\t";
            cout << res->food_item_prices[o_item] << "\t\t";
            cout << quantity[i] << "\t\t";
            cout << quantity[i] * res->food_item_prices[o_item] << endl;
            total = total + quantity[i] * res->food_item_prices[o_item];
        }
    }
    double tax = (total * (0.05));
    res->total_tax = res->total_tax + tax;
    total = tax + total;
    cout << "TAX\t\t\t\t\t\t\t\t\t\t" << tax << endl;
    cout << "____________________________________________________________________________________________" << endl;
    cout << "Net Total                                                                       "<< total << endl;
    cout << endl;
    return total;
}
 
void print_all_menu(Restaurant *restaurant, int n) {
    cout << endl;
    cout << "\t\t\t" << "ALL ITEMS" << "\t\t" << endl;
    cout << "-----------------------------------------------------------" << endl;
 
    cout << "Item code\t" << "Item Name\t\t\t" << "Item price" << endl;
    cout << "----------\t" << "---------\t\t\t" << "----------" << endl;
    for (int i = 0; i < n; i++) {
        cout << restaurant->food_item_codes[i] << "\t\t" << restaurant->food_item_names[i] << "\t\t" << restaurant->food_item_prices[i] << endl;
    }
}

int main() {
int n;
    cin >> n;

    Restaurant *restaurant = new Restaurant();

    take_input(restaurant, n);

    while(true) {
        print_all_menu(restaurant, n);
        cout << endl;

        int ordered_codes[n] = {0};
        int ordered_item_quantity[n] = {0};
                
        int table_no = take_order(ordered_codes, ordered_item_quantity, n, restaurant);
        int total = print_order_summary(restaurant, ordered_codes, n, table_no, ordered_item_quantity);
        cout << "Total Shop Tax : " << restaurant->total_tax << endl;
        cout << "________________________" << endl;
        cout << endl;

        int is_taken_order_again;
        cout << "If You Want to take Order again give 1 nor 0 : ";
        cin >> is_taken_order_again;
        while(true) {
            if (!((is_taken_order_again == 0 || is_taken_order_again == 1))) {
                cout << "Please give 1 or 0 : ";
                cin >> is_taken_order_again;
            }
            else break;
        }
        if (!is_taken_order_again) break;
    }   
}