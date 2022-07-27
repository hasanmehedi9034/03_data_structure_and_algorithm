#include <bits/stdc++.h>
using namespace std;

void print_arrray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert(int a[], int n, int key) {
    int j = n - 1;
    while (j >= 0 && a[j] > key) {
        a[j + 1] = a[j];
        j--;
        print_arrray(a, n);
    }
    a[j + 1] = key;
    cout << j + 1 << endl;
}

int main() {
    int a[10] = {-1};
    int n = sizeof(a) / sizeof(a[0]);

    insert(a, n, -2);
    print_arrray(a, n);
}