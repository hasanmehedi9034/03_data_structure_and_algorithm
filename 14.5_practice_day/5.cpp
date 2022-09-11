#include <bits/stdc++.h>
using namespace std;

void print_1D_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print_2D_array(int *a[], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int row, col;
    cin >> row >> col;

    int a[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << endl;
    cout << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}