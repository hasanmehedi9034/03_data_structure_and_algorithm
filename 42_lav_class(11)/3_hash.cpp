#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,int> M;

    M[3] = 9;
    M[2] = 3;

    for (auto i:M) {
        cout << i.first << " | " << i.second << endl;
    }
}