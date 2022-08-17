#include <bits/stdc++.h>
using namespace std;

template<typename T>  T my_max(T a, T b) {
    return (a > b) ? a: b;
}

int main() {
    cout << my_max<int>(3, 7) << endl;
    cout << my_max<float>(3.5, 7.5) << endl;
    cout << my_max<char>('a', 'f') << endl;
}