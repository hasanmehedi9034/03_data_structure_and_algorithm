#include <bits/stdc++.h>
using namespace std;

void input_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    input_array(a, n);

    int m;
    cin >> m;
    int b[m];
    input_array(b, m);

    for (int i = 0; i < n; i++) {
        bool is_found = false;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                is_found = true;
            }
        }

        if(!is_found) {
            cout <<a[i] << " ";
        }
    }
}