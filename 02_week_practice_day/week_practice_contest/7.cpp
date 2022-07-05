#include <bits/stdc++.h>
using namespace std;

int main() {
    int  a, b, c, d;

    cin >> a >> b >> c >> d;
    int ans;

    if ((a * b) > (c * d)) {
        ans = (a * b);
    }
    else if ((a * b) < (c * d)) {
        ans = (c * d);
    }
    else {
        ans = (a * b);
    }  

    cout << ans;  
}