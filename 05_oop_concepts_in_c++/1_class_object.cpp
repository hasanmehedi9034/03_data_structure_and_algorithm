#include <bits/stdc++.h>
using namespace std;

class Student {
    public: // access modifier or specifier
        char name[100];
        int roll;
};

int main() {
    Student rahim;
    strcpy(rahim.name, "Rahim Akbar");
    rahim.roll = 56;

    cout << rahim.name << " " << rahim.roll;
}