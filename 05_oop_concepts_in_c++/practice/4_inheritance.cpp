#include <bits/stdc++.h>
using namespace std;

class Parent {
    public:
        int x;
        char name[100];
        Parent(char n[100], int a, int b, int c) {
            x = a;
            y = b;
            z = c;
            strcpy(name, n);
        }

    private:
        int y;

    protected:
        int z;
};

class Child: public Parent {
    public:
        int xx;
        Child(int aa, char n[100], int a, int b, int c): Parent(n, a, b, c) {
            xx = aa;
        }
        void tell_me() {
            cout << "Portected value: " << z << endl;
        }
};

int main() {
    Parent pt("Mehedi", 10, 20, 30);
    Child ch(100, "Mehedi", 10, 20, 30);

    cout << ch.name << endl;
    ch.tell_me();
}