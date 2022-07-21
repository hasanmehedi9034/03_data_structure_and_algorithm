#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        char section;
        int roll;
        void set_marks(int n) {
            english_marks = n;
        }
        void set_password(string p) {
            password = p;
        }
        int get_marks() {
            return english_marks;
        }
        void update_marks (int marks, string pas) {
            if (password == pas) {
                english_marks = marks;
                cout << "marks updated";
            }
            else cout << "show an error";
        }
        

    protected:
        int english_marks;

    private:
        string password;
};

int main() {

}