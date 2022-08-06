#include <bits/stdc++.h>
using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        // checking which is the suitable palace of key element
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        // placing key element of his right place
        a[j + 1] = key;
    }
}

int main() {
    int a[] = {10, 3, 2, 2, 7, 5};
    int len = sizeof(a) / sizeof(a[0]);

    print_array(a, len);
    cout << endl;
    insertion_sort(a, len);
    print_array(a, len);
}