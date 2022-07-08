#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    int a[n];

    for (int i = 0; i < n; i++)  {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = 0;
    int diff = n - m;
    for (int i = diff; i < n; i++) {
        ans += a[i];
    }

    cout << ans;
}