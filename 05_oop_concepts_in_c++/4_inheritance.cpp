#include <bits/stdc++.h>
using namespace std;

class Parent {
    public:
        int x;
        Parent(int a, int b, int c) {
            x = a;
            y = b;
            z = c;
        }
    
    private:
        int y;
    
    protected:
        int z;
};

class Child: public Parent {
    public:
        int xx;
        Child(int aa, int a, int b, int c): Parent(a, b, c) {
            xx = aa;
        }
        void tell_me() {
            cout << "Protected value  : " << z << endl;
        }
};

int main() {
    Parent pt(10, 20, 30);
    Child ch(1, 10, 20, 30);

    ch.tell_me();
}