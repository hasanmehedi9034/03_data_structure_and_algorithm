#include <bits/stdc++.h>
using namespace std;

void print_2d_array(int *a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(a + (col * i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
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

    cout << "Printing 2D Array: " << endl;
    print_2d_array(*a, row, col);
}