#include <bits/stdc++.h>
using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[50];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "Given Array : ";
    print_array(array, n);
}