#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        char name[100];
        int roll;
};

int main() {
    Student rahim;
    strcpy(rahim.name, "Rahim");
    rahim.roll = 26;

    cout << rahim.name << endl;
}