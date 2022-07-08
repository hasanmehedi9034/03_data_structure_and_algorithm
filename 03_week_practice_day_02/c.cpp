#include <iostream>
#include <string.h>
// #include <bits/stdc++.h>
using namespace std;

int main() {
    char s[100000];
    cin >> s;
    long long int len = strlen(s);
    int fr[26] = {0};

    for (int i = 0; i < len; i++) {
        fr[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        char ch = static_cast<char>(i) + 'a';
        if (fr[i] == 0) {
            cout << ch;
            return 0;
        }
    }
    cout << "None";
}

