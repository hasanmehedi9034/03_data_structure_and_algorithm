#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s = to_string(n);
    int len = s.length() - 1;

    int new_number = 0;
    while (n > 0) {
        int digit = n % 10;
        n = n / 10;
        new_number = new_number + (digit * pow(10, len));
        len--;
    }

    if (n == new_number) cout << "Yes";
    else cout << "No";
}