#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++){
        int number = i;
        int count = 0;
        
        for (int j = 2; j <= i; j++) {
            if (number % j == 0) {
                count++;
            }
        }

        if (count <= 1) cout << number << " ";
    }
}