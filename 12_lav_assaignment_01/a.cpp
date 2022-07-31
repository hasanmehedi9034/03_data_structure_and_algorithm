#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;
    if (a >= 10) ans++;
    if (b >= 10) ans++;
    if (c >= 10) ans++;
    if (d >= 10) ans++;

    cout << ans;
}