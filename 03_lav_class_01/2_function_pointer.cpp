#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    // int *p = (int *)malloc(n * sizeof(int));
    // int *p = (int *)calloc(n, sizeof(int));
    // for (int i = 0; i < 10; i++) {
    //     cout << p[i] << " ";
    // }
    // free(p);

    int *ptr = new int[10]{2, 3, 3};
    for (int i = 0; i < 10; i++) {
        cout << ptr[i] << " ";
    }
    delete ptr;
}