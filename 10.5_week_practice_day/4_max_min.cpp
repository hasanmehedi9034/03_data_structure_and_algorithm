#include <bits/stdc++.h>
using namespace std;

void max_a(int a[], int n, int index) {

}

int linear(int a[], int n, int x) {
    if (n == 1) return 0;
    int i = linear(a, n - 1, x);
    cout << i << endl;
    return i;

    // if (a[i] == x) {
    //     return i;
    // }
}

int findMinRec(int a[], int n) {
    if (n <= 1) return 0;

    int i = findMinRec(a, n - 1);
    cout << "i." << i << ", n." << n << endl;
    return a[n] < a[i] ? n : i;
}

int main() {
    int a[] = {3, 2, 1, 1};
    int len_a = sizeof(a) / sizeof(a[0]);

    cout << findMinRec(a, len_a);
}