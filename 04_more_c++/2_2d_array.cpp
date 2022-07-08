#include <bits/stdc++.h>
using namespace std;

int main() {
    // int row = 3, col = 3;
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << "[" << i << "," << j << "]" << " ";
    //     }
    //     cout << endl;
    // }

    int row = 4, col = 4;
    int a[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}