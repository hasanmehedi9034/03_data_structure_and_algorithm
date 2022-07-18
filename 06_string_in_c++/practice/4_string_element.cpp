#include <bits/stdc++.h>
using namespace std;

int main() {
    string name = "Mehedi";
    cout << name.at(1) << endl;
    cout << name[1] << endl;

    cout << name.front() << endl;
    cout << name.at(0) << endl;

    cout << name[name.length() - 1] << endl;
    cout << name.back() << endl;
}