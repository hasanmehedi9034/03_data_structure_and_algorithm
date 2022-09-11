#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans, prev_count = 0;
    for (int i = 1; i <= n; i++) {

        if (i % 2 != 0) continue;
        int count = 0;
        int j = i;

        while (j / 2 > 0) {
            if (j % 2 == 0) count++; 
            else count = 0;
            j = j / 2;
        }
        cout << i << ".count: " << count << endl;
        if (prev_count < count) {
            prev_count = count;
            ans = i;
        }
    }
    ans == 0 ? cout << 1 : cout << ans;
}