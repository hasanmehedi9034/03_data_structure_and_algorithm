#include <bits/stdc++.h>
using namespace std;

void inpute_array_2D(int *a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> *(a + (col * i) + j);
        }
    }
}

void print_array_2D (int *a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(a + (row * i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;

    int a[n][n];
    inpute_array_2D(*a, n, n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == (n / 2)) {
                sum += a[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == (n / 2) && i != j) {
                sum += a[i][j];
            }
        }
    }

    for (int j = 0; j < n; j++) {
        if (j < (n / 2)) {
            sum += a[0][j];
        }
    }

    for (int j = 0; j < n; j++) {
        if (j > (n / 2)) {
            sum += a[n - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > (n / 2)) {
            sum += a[i][0];
        }
    }

    for (int i = 0; i < n; i++) {
        if (i < (n / 2)) {
            sum += a[i][n - 1];
        }
    }

    cout << sum << endl;
}