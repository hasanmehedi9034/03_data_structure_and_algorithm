#include <bits/stdc++.h>
using namespace std;

int main() {
    string name = "Mehedi";

    cout << "----forward iteration----" << endl;
    for (string::iterator it = name.begin(); it != name.end(); it++) {
        cout << *it << endl;
    }

    cout << "-------backward iteration------" << endl;
    for (string::reverse_iterator rv_it = name.rbegin(); rv_it != name.rend(); rv_it++) {
        cout << *rv_it << endl;
    }

    cout << "----auto Forward------" <<endl;
    for (auto it = name.begin(); it != name.end(); it++) {
        cout << *it << endl;
    }

    cout << "----auto reverse------" <<endl;
    for (auto it = name.rbegin(); it != name.rend(); it++) {
        cout << *it << endl;
    }
}