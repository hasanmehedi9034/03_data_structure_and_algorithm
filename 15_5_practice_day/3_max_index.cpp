#include <bits/stdc++.h>
using namespace std;

void find_max (int *a, int row, int col) {
    int max = *a;
    int index_i = 0;
    int index_j = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (max < *(a + (col * i) + j)) {
                max = *(a + (col * i) + j);
                index_i = i;
                index_j = j;
            }
        }
    }
    cout << "Max: " << max << endl;
    cout << "Location: [" << index_i << "][" << index_j << "]" << endl;
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

    find_max(*a, row, col);
}