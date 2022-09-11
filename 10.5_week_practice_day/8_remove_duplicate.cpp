#include <bits/stdc++.h>
using namespace std;

int remove_duplicate(int a[], int n){
    for (int i = 0; i < n- 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if(a[i] == a[j]) {
                
                for (int k = j; k < n; k++) {
                    a[k] = a[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    return n;
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {2, 8, 1, 3, 2, 6, 4, 3};
    int len_a = sizeof(a) / sizeof(a[0]);

    int b[] = {3, 3, 3};
    int len_b = sizeof(b) / sizeof(b[0]);

    int c[] = {6, 7, 8, 9};
    int len_c = sizeof(c) / sizeof(c[0]);

    print_array(a, len_a);
    
    len_a = remove_duplicate(a, len_a);
    print_array(a, len_a);
}