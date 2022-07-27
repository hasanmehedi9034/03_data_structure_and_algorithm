#include <bits/stdc++.h>
using namespace std;

void print_array (int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void  insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int a[] = {5, 2, 7, 3, 0, 10, 4};
    int len_a = sizeof(a) / sizeof(a[0]);

    cout << "Before sort: ";
    print_array(a, len_a);

    insertion(a, len_a);

    cout << "After sort: ";
    print_array(a, len_a);
}