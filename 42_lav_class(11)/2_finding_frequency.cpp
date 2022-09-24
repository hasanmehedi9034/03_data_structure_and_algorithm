#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int array[n];

    for(int i = 0; i < n; i++) {
        cin >> array[n];
    }

    map<int, int> M;

    for (int i = 0; i < n; i++) {
        M[array[i]]++;
    }

    map<int, int>::iterator it;
    for (it = M.begin(); it != M.end(); it++) {
        cout << it->first << " | " << it->second << endl;
    }

}

/*

10
2 1 1 2 2 3 4 9 4 3 5

*/