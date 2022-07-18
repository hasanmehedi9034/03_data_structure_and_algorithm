#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        int x;
        void say_hi() {
            cout << "Hi Mehedi!" << endl;
        }

    private:
        int y;

    protected:
        int z;
};

int main() {
    Student rahim;
    rahim.x = 10;
    rahim.say_hi();
}