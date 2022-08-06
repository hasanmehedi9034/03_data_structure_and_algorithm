#include <bits/stdc++.h>
using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void bubble_sort(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        bool is_swap = false;

        cout << i << " iteration: " << endl;
        int step = 1;
        for (int j = 0; j < n - i; j++) {

            if (a[j] > a[j + 1]) {

                cout << "\t" << step << " step: ";
                print_array(a, n);
                cout << "---> ";

                swap(a[j], a[j + 1]);
                is_swap = true;

                print_array(a, n);
                cout << endl;
                step++;
            }
        }
        if (!is_swap) break;
    }
}

int main() {
    int a[] = {7, 2, 13, 2, 11, 4};
    int len = sizeof(a) / sizeof(a[0]);

    bubble_sort(a, len);
}

/*
    Limiton of bubble sort approach;
    
    1. if array already sorted even then loop execute (n * n) time, to get rid of this problem i can take a variable whice name is is_swap if the valu is not swap at least one time then loop berak. following this process i can reduce the loop.

    2. in the nested second loop no need to n iteration all of the time(first loop). i can give this control (j < n - i). so that decreases our loopl
*/