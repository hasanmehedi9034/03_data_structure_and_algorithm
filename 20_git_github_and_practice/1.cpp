#include <bits/stdc++.h>
using namespace std;

void take_input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int k_min (int a[], int n, int k) {
    int count = 1;
    int min = a[0];

    for (int i = 0; i < n; i++) {
        if (min < a[i]) {
            count++;
            min = a[i];
        }
        if (count == k) return min;
    }
    return min;
}

int k_max(int a[], int n, int k) {
    int count = 1;
    int max = a[n - 1];

    for (int i = n - 1; i >= 0; i--){
        if (max > a[i]) {
            count++;
            max = a[i];
        }
        if (count == k) return max;
    }
    return max;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    int a[n];
    take_input(a, n);

    sort(a, a + n);
    print_array(a, n);

    cout << k_min(a, n, k) << " " << k_max(a, n, k) << endl;
}