#include <bits/stdc++.h>
using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int find_max(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

void update_counter(int a[], int len_a, int counter[], int len_counter) {
    for (int i = 0; i < len_counter; i++) {
        counter[i] = 0;
    }

    for (int i = 0; i < len_a; i++) {
        counter[a[i]]++;
    }
}

void q_sum(int a[], int n) {
    for (int i = 1; i < n; i++) {
        a[i] = a[i] + a[i - 1];
    }
}

void counting_sort(int a[], int len_a, int counter[], int final_array[]) {
    for (int i = len_a - 1; i >= 0; i--) {
        int key = a[i];
        counter[key] = counter[key] - 1;
        final_array[counter[key]] = a[i];
    }
}

int main() {
    int a[] = {7, 2, 9, 2, 7, 4, 5, 1, 0};
    int len_a = sizeof(a) / sizeof(a[0]);

    // step 1: find max from the main given array, and make array length of counter array.
    int len_counter = find_max(a, len_a) + 1;

    // step 2: make ready counter array
    int counter[len_counter];

    // step 3: update counter array
    update_counter(a, len_a, counter, len_counter);

    // step 4: update counter with prefix sum
    q_sum(counter, len_counter);

    // step 5.1: make final array which contain sorting element
    int final_array[len_a];

    //step 5.2: sorting array
    counting_sort(a, len_a, counter, final_array);

    // print array after sorting
    print_array(final_array, len_a);
}