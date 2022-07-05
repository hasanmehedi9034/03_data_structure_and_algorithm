#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans;

    int a = n / 15;
    if (n <= 15) {
        ans = (800 * n);
    } 
    else {
        ans = (800 * n) - (a * 200);
    }  
    cout << ans;
}