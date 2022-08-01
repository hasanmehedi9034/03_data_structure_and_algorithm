#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int i, j;

    for (i = 0; i < s.length(); i++) {
        if (s[i] == 'A') break;
    }

    for (j = s.length() - 1; j >= 0; j--) {
        if (s[j] == 'Z') break;
    }

    cout << i << " " << j;
}