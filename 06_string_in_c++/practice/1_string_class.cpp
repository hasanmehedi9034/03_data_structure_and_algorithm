#include <bits/stdc++.h>
using namespace std;

int main() {
    string name2(10, 'x');
    cout << name2 << endl;

    string name = "Mehedihasan eti and kjafajf";
    cout << name << endl;
    cout << name.length() << endl;
    cout << name.size() << endl;
    cout << name.capacity() << endl;

    cout << "-----------" << endl;

    name = "hasan";
    cout << name << endl;
    cout << name.length() << endl;
    cout << name.size() << endl;
    cout << name.capacity() << endl;

    string f1 = "Ripon";
    string f2 = "Ripon";
    string f_name = f1 + ", " + f2;
    cout << f_name << endl;
    // f1 += " " + f2;
    // f1.append(f2);
    cout << f1 << endl;


    cout << "----compare----" << endl;
    if (f1 == f2) {
        cout << "this is the same friend" << endl;
    }
    else {
        cout<< "this is not same friend" << endl;
    }
}