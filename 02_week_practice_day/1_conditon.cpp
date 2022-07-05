#include <bits/stdc++.h>
using namespace std;

int main() {
    // int a, b;
    // cin >> a >> b;

    // if (a > b) cout << "A is greater" << endl;
    // else if (a < b) cout << "B is greater" << endl;
    // else cout << "A and B are equal";

    char x;
    cin >> x;
    // if (x % 2 != 0) cout << x << " is odd";
    // else {
    //     if (x < 10) cout << x << " is less than 10";
    //     else cout << x << " is Greater than equal 10";
    // }

    switch (x) {
        case 'a':
            cout << "vowel";
            break;
        case 'e':
            cout << "vowel";
            break;
        case 'i':
            cout << "vowel";
            break;
        case 'o':
            cout << "vowel";
            break;
        case 'u':
            cout << "vowel";
            break;
        default:
            cout << "consonent";
    }
}