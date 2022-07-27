#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int target, int n) {
    int lower_index = 0;
    int higher_index = n;

    while(lower_index <= higher_index) {
        int mid_index = (lower_index + higher_index) / 2;

        if (a[mid_index] == target) return mid_index;

        if (target > a[mid_index]) lower_index = mid_index + 1;  
        else higher_index = mid_index - 1;
    }
    return -1;
}

int binary_search_recursive(int a[], int x, int lb, int ub) {
    if (lb <= lb) {
        int mid = (lb + ub) / 2;

        if (a[mid] == x) return mid;
        else if (x > a[mid]) return binary_search_recursive(a, x, mid + 1, ub);
        else return binary_search_recursive(a, x, lb, mid - 1);
    }
    else {
        return -1;
    }
}

int main() {
    int ar[] = {1, 3, 4, 5, 6, 10};
    int n = sizeof(ar) / sizeof(ar[0]);
    int target = 0;

    int ind = binary_search_recursive(ar, target, 0, n - 1);
    cout << ind;
}