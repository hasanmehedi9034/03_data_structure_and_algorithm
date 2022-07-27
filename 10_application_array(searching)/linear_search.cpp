#include <bits/stdc++.h>
using namespace std;

// int linear_search(int a[], int n, int x) {
//     // if (index < n) {
//     //     if (a[index] == x) return index;
//     //     else linear_search(a, n, x, index + 1);
//     // }
//     // else return -1; 
//     // if (n <= 0) return -1;

//     // int rest = linear_search(a, n - 1, x);
//     // if (a[n] != x) return rest;
//     // else if (a[n] == x) return n;
// }

void print_array(int a[], int n) {
    if (n < 0) return;
    print_array(a, n - 1);
    cout << a[n] << " ";
}

int linear(int a[], int n, int x) {
    if (n < 0) return -1;

    int rest = linear(a, n - 1, x);

    cout << n << " ";

    if (a[n] == x) return n;
    return rest;
}

int main(){
    int a[] ={3, 3, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << linear(a, n - 1, 3);
}