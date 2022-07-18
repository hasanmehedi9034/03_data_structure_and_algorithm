#include <bits/stdc++.h>
using namespace std;

int main() {
    string name = "mehedihasnpolashronieti";

    cout << name.find('e') << endl;
    cout << name.rfind('e') << endl;

    cout << name.find_first_of('e') << endl;
    cout << name.find_last_of('e') << endl;

    cout << name.find_first_not_of('e') << endl;
    cout << name.find_last_not_of('e') << endl;

    cout << name.substr(0, 6) << endl;
}