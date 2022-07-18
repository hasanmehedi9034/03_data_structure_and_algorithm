#include <bits/stdc++.h>
using namespace std;

class Parent {
    private:
        int taka;

    public:
        Parent(int tk, int ps) {
            taka = tk;
            password = ps;
        }
        friend class Abbur_bondhu;
        friend void tell_secret(Parent *ptr);
        
    protected:
        int password;
};

class Abbur_bondhu {
    public:
        void tell_secret(Parent *ptr) {
            cout << ptr->taka << endl;
        }
};

void tell_secret(Parent *ptr) {
    cout << ptr->taka << " " << ptr->password << endl;
}

int main() {
    Parent pt(1500, 2345);
    Abbur_bondhu a_bondhu;
    a_bondhu.tell_secret(&pt);
    tell_secret(&pt);
}