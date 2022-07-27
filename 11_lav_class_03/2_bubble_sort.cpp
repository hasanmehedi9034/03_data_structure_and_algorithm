#include <bits/stdc++.h>
using namespace std;

void print_array (int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

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
        int flag = 0;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

int main() {
    int a[] = {1, 3, 4, 5, 6};
    int len_a = sizeof(a) / sizeof(a[0]);

    cout << "Before sort: ";
    print_array(a, len_a);

    bubble2(a, len_a);

    cout << "After sort: ";
    print_array(a, len_a);
}