#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x, y;
    cin >> n;
    cin >> k;
    cin >> x;
    cin >> y;

    int total;
    if (n >= k) {
        total = (k * x) + ((n - k) * y);
    }
    else {
        total = (n * x);
    }

    cout << total;
}