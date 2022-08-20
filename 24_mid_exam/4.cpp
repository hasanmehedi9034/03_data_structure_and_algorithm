#include <bits/stdc++.h>
using namespace std;

void inpute_array_2D(int *a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> *(a + (row * j) + i);
        }
    }
}

void print_array_2D (int *a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(a + (row * j) + i) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int max_in_array(int *a, int n, int m) {
    int max = *a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (max < *(a + (n * i) + j)) {
                max = *(a + (n * i) + j);
            }
        }
    }
    return max;
}

void replace_array(int *a, int row, int col, int number, int times) {
    for (int i = row - 1; i >= 0; i--) {
        for (int j = col - 1; j >= 0; j--) {
            if (number == *(a + (col * i) + j)) {
                if (times != 0) {
                    *(a + (col * i) + j) = -1;
                    times--;
                }
            }
        }
    }
}

int main() {
    int row, col;
    cin >> row >> col;

    int a[row][col];
    inpute_array_2D(*a, row, col);

    int max_number = max_in_array(*a, row, col);
    int counter[max_number + 1] = {0};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            counter[a[i][j]]++;
        }
    }

    for (int i = 0; i < max_number + 1; i++) {
        if (counter[i] > 1) {
            replace_array(*a, row, col, i, counter[i] - 1);
        }
    }

    cout << "Replaced Array :" << endl;
    print_array_2D(*a, row, col);
}