#include <bits/stdc++.h>
using namespace std;

int main() {
    string name = "Mehedi Hasan";
    cout << name << endl;
    cout << name.length() << endl;
    cout << name.size() << endl;

    name.resize(6);
    cout << name << endl;

    name.clear();
    cout << "name is: "<< name << endl;
    cout << name.length() << endl;
    cout << name.size() << endl;

    if (name.empty()) {
        cout << "this is empty string" << endl;
    }
    else {
        cout << "this is not empty string" << endl;
    }
}