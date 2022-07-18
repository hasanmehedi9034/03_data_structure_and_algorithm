#include <bits/stdc++.h>
using namespace std;

int main() {
    string st; // dynamic array
    cout << st.capacity() << endl;
    cout << st.max_size() << endl;

    string st(10, 'z'); // initialize with 10 times z;
    cout << st << endl;

    string s1 = "Mehedi";
    string s2 = "Mehedi";
    string full_name = s1 + " " + s2;
    cout << full_name << endl;
    if(s1 == s2) {
        cout << "yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}