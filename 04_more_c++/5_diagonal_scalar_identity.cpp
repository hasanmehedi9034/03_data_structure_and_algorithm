#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    int a[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    if (row != col) {
        cout << "No, this is not diagonal Matrix";
        return 0;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == j) continue;

            if (a[i][j] > 0) {
                cout << "this is not diagonal";
                return 0;
            }
        }
    }
    cout << "this is diagonal Matrix" << endl;

    int save_first;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == j) {
                if (i == 0 && j == 0) save_first = a[i][j];
                else {
                    if (save_first != a[i][j]) {
                        cout << "this is not scalar matrix";
                        return 0;
                    }
                }
            }
        }
    }
    cout << save_first << endl;
    cout << "this is scalar matrix" << endl;
    if (save_first == 1) {
        cout << "this is identiy matrix" << endl;
    }
}