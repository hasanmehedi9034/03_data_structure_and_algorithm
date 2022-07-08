#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[27];
    cin >> str;

    int n = strlen(str);
    int fr[27] = {0};

    for (int i = 0; i < n; i++) {
        fr[str[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
        if (fr[i] > 1) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes";
}