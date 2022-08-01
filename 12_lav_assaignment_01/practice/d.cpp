#include <bits/stdc++.h>
using namespace std;

void input_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int f(int a[], int n) {
    int fr[10];
    for (int i = 0; i < n; i++) {
        fr[a[i]]++;
    }

    int max = 0;
    for (int i = 0; i < 10; i++) {
        if (max < fr[i]) max = fr[i];
    }

    return max;
}

int main() {
    int total_test_case;
    cin >> total_test_case;

    for (int i = 0; i < total_test_case; i++) {
        int n;
        cin >> n;

        int a[n];
        input_array(a, n);

        int max = f(a, n);

        cout << n - max << endl;
    }
}