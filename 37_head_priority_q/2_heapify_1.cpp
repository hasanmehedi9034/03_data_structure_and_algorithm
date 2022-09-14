// #include <bits/stdc++.h>
// using namespace std;


// void heapify(int array[], int n, int current) {
//     int largest = current;
//     int leftChild = 2 * current + 1;
//     int rightChild = 2 * current + 2;

//     if (leftChild < n && array[leftChild] > array[largest]) {
//         largest = leftChild;
//     }

//     if (rightChild < n && array[rightChild] > array[largest]) {
//         largest = rightChild;
//     }

//     if (largest != current) {
//         swap(array[largest], array[current]);
//         heapify(array, n, largest);
//     }
// }

// void print_array(int a[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int n;
//     cin >> n;

//     int array[n];
//     for (int i = 0; i < n; i++) {
//         cin >> array[i];
//     }

//     int nonLeafStart = (n / 2) - 1;

//     print_array(array, n);

//     for (int i = nonLeafStart; i >= 0; i--) {
//         heapify(array, n, i);
//     }

    
//     print_array(array, n);
// }



#include <bits/stdc++.h>
using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heapify(int array[], int n, int current) {
    int largest = current;
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2;

    if (leftChild < n && array[leftChild] > array[largest]) {
        largest = leftChild;
    }

    if (rightChild < n && array[rightChild] > array[largest]) {
        largest = rightChild;
    }

    if (largest != current) {
        swap(array[largest], array[current]);
        heapify(array, n, largest);
    }
}

int main() {
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int nonLeafStart = (n / 2) - 1;
    for (int i = nonLeafStart; i >= 0; i--) {
        heapify(array, n, i);
    }

    print_array(array, n);

}

/*
9
2 10 1 5 4 8 3 8 7
*/