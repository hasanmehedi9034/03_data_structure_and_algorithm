#include <bits/stdc++.h>
using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void bubble_sort(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        bool is_swap = false;

        cout << i << " iteration: " << endl;
        int step = 1;
        for (int j = 0; j < n - i; j++) {

            if (a[j] > a[j + 1]) {

                cout << "\t" << step << " step: ";
                print_array(a, n);
                cout << "---> ";

                swap(a[j], a[j + 1]);
                is_swap = true;

                print_array(a, n);
                cout << endl;
                step++;
            }
        }
        if (!is_swap) break;
    }
}

int main() {
    int a[] = {7, 2, 13, 2, 11, 4};
    int len = sizeof(a) / sizeof(a[0]);

    bubble_sort(a, len);
}