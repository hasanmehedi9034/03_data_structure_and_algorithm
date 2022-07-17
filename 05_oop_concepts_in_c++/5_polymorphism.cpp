#include <bits/stdc++.h>
using namespace std;

class Example {
    public:
        int add(int x, int y) {
            return x + y;
        }
        double add (double x, double y) {
            return x + y;
        }
        void add (char a) {
            cout << "hi " << a << endl;
        }
};

int main() {
    Example ex;
    // cout << ex.add(1.2, 2.2) << endl;
    ex.add('m');
}