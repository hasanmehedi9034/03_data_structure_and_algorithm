#include <bits/stdc++.h>
using namespace std;

int main() {
    string names = "Mehedi Hasan Polash Hamid Roni Eti";
    stringstream stream(names);

    string w;
    int total_names = 0;
    while(stream >> w) {
        cout << w << endl;
        total_names++;
    }
    cout << total_names << endl;
}