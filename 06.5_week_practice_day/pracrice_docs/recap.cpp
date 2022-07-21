#include <bits/stdc++.h>
using namespace std;

class Student {
    public:
        string name;
        char section;
        int roll;
    protected:
        int english_marks;
    private:
        string password;

    public:
        void set_password(string pass) {
            this->password = pass;
        }
        void set_marks (int marks) {
            this->english_marks = marks;
        }
        int get_marks() {
            return this->english_marks;
        }
        void  update_marks(string pass, int marks) {
            if (pass == this->password) english_marks = marks;
            else cout << "password didnt mathch!" << endl;
        }
};

int main() {
    int n;
    cout << "Number of Student " << endl;
    cin >> n;

    cout << "Student input : name(string), section(charectar), roll(int), marks(int), password(string)" << endl;
    Student st[n];
    for (int i = 0; i < n; i++) {
        string name, password;
        char section;
        int roll, marks;

        cin >> name >> section >> roll >> marks >> password;
        st[i].name = name;
        st[i].section = section;
        st[i].roll = roll;
        st[i].set_marks(marks);
        st[i].set_password(password);
    }


    cout << "for update marks : roll(int), marks(int), password(string) : " << endl;
    int roll, marks;
    string password;
    cin >> roll >> marks >> password;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (st[i].roll == roll) {
            found = true;
            st[i].update_marks(password, marks);
        }
    }

    if (!found) {
        cout << "Student Not  found" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << st[i].name << " " << st[i].section << " " << st[i].roll << " " << st[i].get_marks() << endl;
    }
}