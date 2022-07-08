#include <bits/stdc++.h>
using namespace std;

int main() {
    char a[10], b[10], c[10];
    cin >> a >> b >> c;
    
    int len_a = strlen(a);
    int len_b = strlen(b);

    bool n = ((a[len_a - 1] == b[0]) && (b[len_b - 1] == c[0]));
    n ? cout << "YES" : cout << "NO";    
}