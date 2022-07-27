#include <bits/stdc++.h>
using namespace std;

void bubble(int a[], int len_a) {
    for (int i = 0; i < len_a - 1; i++) {
        for (int j = i + 1; j < len_a; j++) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void bubble2(int a[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void print_array (int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {14, 11, 1, 5, 4, 0};
    int len_a = sizeof(a) / sizeof(a[0]);

    cout << "Before sort: ";
    print_array(a, len_a);

    bubble2(a, len_a);

    cout << "After sort: ";
    print_array(a, len_a);
}