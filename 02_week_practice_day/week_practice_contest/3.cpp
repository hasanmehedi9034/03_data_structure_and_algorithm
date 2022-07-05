#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    char op;

    cin >> a >> op >> b;

    int ans;
    switch(op) {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
    }
    cout << ans;
}