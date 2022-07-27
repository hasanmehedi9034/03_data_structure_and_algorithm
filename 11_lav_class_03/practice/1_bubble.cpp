#include <bits/stdc++.h>
using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int a[], int n) {
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
    int a[] = {5, 2, 7, 3, 0, 10, 4};
    int len_a = sizeof(a) / sizeof(a[0]);   

    bubble_sort(a, len_a);
    print_array(a, len_a);
}