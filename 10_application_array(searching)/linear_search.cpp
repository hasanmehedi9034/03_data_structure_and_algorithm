#include <bits/stdc++.h>
using namespace std;

int linear_search(int a[], int n, int x, int index) {
    if (index < n) {
        if (a[index] == x) return index;
        else linear_search(a, n, x, index + 1);
    }
    else return -1; 
}

int main(){
    int a[] ={1, 3, 4, 5, 10, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << linear_search(a, n, 0, 0);
}