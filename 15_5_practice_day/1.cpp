#include <bits/stdc++.h>
using namespace std;

void print_2d_array(int *a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(a + (col * i) + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int row = sqrt(n);
    int col = sqrt(n);

    int aa[row][col];

    int in = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            aa[i][j] = a[in];
            in++;
        }
    }

    print_2d_array(*aa, row, col);
}