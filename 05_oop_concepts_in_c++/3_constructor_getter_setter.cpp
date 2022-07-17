#include <bits/stdc++.h>
using namespace std;

class Example {
    private:
        int x;
        int pass;
    public:
        void setter (int a) {
            x = a;
        }
        int getter () {
            return x;
        }
        // Example (int a, int b, int c) {
        //     x = a;
        // }
};

int main() {
    // Example a(10, 20, 30);
    // cout << a.x << " " << a.y << " " << a.z;

    Example a;
    a.setter(1500);
    cout << a.getter();
}