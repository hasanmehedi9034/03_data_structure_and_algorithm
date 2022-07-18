#include <bits/stdc++.h>
using namespace std;

class Example {
    public:
        int add(int a, int b) {
            return a + b;
        }
        double add (double a, double b) {
            return a + b;
        }
};

int main() {
    Example ex;
    cout << ex.add(1.0, 2.01) << endl;
}