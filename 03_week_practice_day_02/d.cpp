#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char str[100];
    cin >> str;
    int len_str = strlen(str);

    cout << str[0] << (len_str - 2) << str[len_str - 1];
}