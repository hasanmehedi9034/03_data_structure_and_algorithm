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
        cout << "this is not symetric matrix";
        return 0;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (a[i][j] != a[j][i]) {
                cout << "this is not symetric matrix";
                return 0;
            }
        }
    }
    cout << "this is symetric matrix";
}