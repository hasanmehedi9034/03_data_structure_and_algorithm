#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heapify(int a[], int n, int current) {
    int largest = current;
    int leftChild = (current * 2) + 1;
    int rightChild = (current * 2) + 2;

    if (leftChild <= n && a[largest] < a[leftChild]) {
        largest = leftChild;
    }

    if (rightChild <= n && a[largest] < a[rightChild]) {
        largest = rightChild;
    }

    if (largest != current) {
        swap(a[largest], a[current]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i - 1, 0);
    }
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int nonLeaf = (n / 2) - 1;
    for (int i = nonLeaf; i >= 0; i--) {
        heapify(a, n, i);
    }

    heapSort(a, n);

    printArray(a, n);
}

/*
9
2 10 1 5 4 8 3 8 7



*/