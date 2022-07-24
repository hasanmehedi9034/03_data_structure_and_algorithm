#include <bits/stdc++.h>
using namespace std;

void insert(int ar[], int index, int insert_number, int n) {
    for (int i = n; i >= index; i--) {
        ar[i] = ar[i - 1];
    }
    ar[index] = insert_number;
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int ar[50] = {1, 3, 4, 5};
    // insert(ar, 1, 2, 5);
    // position -> size;
    // arr[size] = arr_pos
    // two technic of insertion
    print_array(ar, 5);
}