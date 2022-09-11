#include <bits/stdc++.h>
using namespace std;

int binary(int a[], int lb, int ub, int target) {
    int mid = (lb + ub) / 2;

    if (lb > ub) return -1;

    if (a[mid] == target) return mid;
    else if (a[mid] < target) return binary(a, mid + 1, ub, target);
    else return binary(a, lb, mid - 1, target);
}

int main() {
    int a[] = {1, 2, 9, 11, 17, 24, 26, 31, 320, 45};
    int len_a = sizeof(a) / sizeof(a[0]);

    cout << binary(a, 0, len_a, 6);
}