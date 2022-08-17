#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

int global_id = 100;

class Person {
    private:
        string name;
        int id = 100;
        float salary;

    public:
        Person() {
            this->name = "";
            this->salary = 0;
        }

        string get_name() {
            return this->name;
        }

        void set_name(string n) {
            this->name = n;
        }

        void set_id() {
            this->id = global_id;
            global_id++;
        }

        int get_id() {
            return this->id;
        }

        void set_salary(float s) {
            this->salary = s;
        }

        float get_salary() {
            return this->salary;
        }

        void print_details() {
            cout << get_id() << " -> " << get_name() << "-" << get_salary();
        }

        Person(string n, float s) {
            set_name(n);
            set_salary(s);
            set_id();
        }
};

int main() {
    // Stack <pair<int, string>> st;

    // st.push(make_pair(1, "Mehedi"));
    // st.push(make_pair(2, "Polash"));
    // st.push(make_pair(3, "Roni"));
    // st.push(make_pair(4, "Eti"));

    // while(!st.empty()) {
    //     pair <int, string> detail = st.pop();
    //     cout << detail.first <<  "->" << detail.second << endl;
    // }

    Stack <Person> st;

    Person a("Mehedi", 20.2);
    Person b("Polash", 21.2);
    Person c("Mehedi", 22.2);

    st.push(a);
    st.push(b);
    st.push(c);
    

    while(!st.empty()) {
        Person tp = st.top_value();
        cout << tp.get_id() << "->" << tp.get_name() << " - " << tp.get_salary() << endl;
        st.pop();
    }
}