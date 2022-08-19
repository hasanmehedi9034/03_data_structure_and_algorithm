#include <bits/stdc++.h>
using namespace std;

void input_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int find_max(int a, int b) {
    if (a > b) return a;
    return b;
}

int find_max_in_array(int a[], int n) {
    int max = a[0];

    for(int i = 1; i < n; i++) {
        max = find_max(max, a[i]);
    }

    return max;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    input_array(a, n);

    int count[find_max_in_array(a, n) + 1] = {0};

    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    for (int i = 0; i <= find_max_in_array(a, n); i++) {
        if (count[i] != 0) {
            cout << i << " => " << count[i] << endl;
        }
    }
}