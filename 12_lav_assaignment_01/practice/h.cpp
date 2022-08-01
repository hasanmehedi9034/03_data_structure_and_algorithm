#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    
    int pos1, pos2;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            pos1 = i;
            break;
        }
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            pos2 = i;
            break;
        }
    }

    cout << pos2 - pos1 + 1 << "\n";

    return 0;
}