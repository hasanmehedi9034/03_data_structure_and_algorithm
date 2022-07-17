#include <bits/stdc++.h>
using namespace std;

class Parent {
    private:
        int taka;
    public:
        Parent(int tk) {
            taka = tk;
        }
        friend class Abbur_bondhu;
};

class Abbur_bondhu{
    public:
        void tell_secret(Parent *ptr) {
            cout << ptr->taka;
        }
};

int main() {
    Parent pt(1500);
    Abbur_bondhu a_bondhu;
    a_bondhu.tell_secret(&pt);
    
}