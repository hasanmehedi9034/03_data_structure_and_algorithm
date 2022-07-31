// problem c slove;
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void input_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main()
{
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {   
        int n;
        cin >> n;
        int a[n];
        input_array(a, n);

        sort(a, a + n);
        // int size = n / 2;
        // while (a[size - 2] != a[size - 1])
        // {
        //     size = size / 2;
        // }
        // for (int j = size - 2; j < n; j++)
        // {
        //     if (a[j] > a[size - 1])
        //     {
        //         couter = n - j + 2;
        //     }
        // }

        int first_index = 0;
        int first_element = a[first_index];
        while(true) {
            if (first_element != a[0]) {
                break;
            }
            first_index++;
        }
        // first_index -= 1;
        cout << n - first_index + 1 << endl;
    }
}