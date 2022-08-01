#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cin >> size;

    int array[size];

    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // step 1
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // step 2, initialization of count array
    int count[max + 1] = {0};

    // step 3, frequency calculation
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // step 4, cumulative sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // step 5, Final array --> backward traversal of basic array
    int final[size];
    for (int i = size - 1; i >= 0; i++) {
        count[array[i]]--;
        int k = count[array[i]];
        final[k] = array[i];
    }
}