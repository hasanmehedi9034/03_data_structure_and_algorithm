#include <bits/stdc++.h>
using namespace std;

void input_array(int ar[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int delete_element(int ar[], int pos, int n) {
    if (pos == (n - 1)) return (n - 1);

    for (int i = pos + 1; i < n; i++) {
        ar[i -1] = ar[i];
    }
    return (n - 1);
}

int main() {
    int n;
    cin >> n;

    int ar[n];
    input_array(ar, n);

    int pos  = 0;
    
    // n = delete_element(ar, pos, n);
    // cout << n << endl;
    print_array(ar, delete_element(ar, pos, n));
}