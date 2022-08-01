#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    if((a != b) && (b != c) && (c != a)) cout << "3";
    else if((a = b) && (b = c) && (c = a)) cout << "1";
    else if((a = b) || (b = c) || (c = a)) cout << "2";
}