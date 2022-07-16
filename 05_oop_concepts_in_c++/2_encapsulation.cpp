#include <bits/stdc++.h>
using namespace std;

class Student {
    public: // accessed anyone
        int x;
        void say_hi() {
            cout << "Hi " << x << endl;
        }
    
    private: // accessed only friend
        int y;
        void say_bye() {
            cout << "good bye " << endl;
        }

    protected: // this can accessed child
        int z;
};

int main() {
    Student rahim;
    rahim.x = 10;
    rahim.say_hi();
}