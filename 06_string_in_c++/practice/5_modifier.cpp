#include <bits/stdc++.h>
using namespace std;

int main() {
    string f1 = "Ripon";
    string f2 = "Mehedi";

    // assing
    f1.assign("Karim");
    f1 = "Keya";
    cout << f1 << endl;

    // push back a single char
    f1.push_back('m');
    cout << f1 << endl;
    
    // remove a char from last
    f1.pop_back();
    cout << f1 << endl;

    // add char or word to last
    f1.append(" khan");
    cout << f1 << endl;

    // swap number or you can string
    int a = 2;
    int b = 3;
    swap(a, b);
    cout << a << " " << b;

    // insert a word from index
    f1.insert(1, "Your ar best ");
    cout << f1 << endl;

    // erase word or char
    f1.erase(0, 2);
    cout << f1 << endl;
}