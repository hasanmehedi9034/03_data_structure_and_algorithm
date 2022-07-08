#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char s[100000];
    cin >> s;
    long long int len = strlen(s);

    for (int i = 0; i < len; i += 2) {
        cout << s[i];
    }
}
