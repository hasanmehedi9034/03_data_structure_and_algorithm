#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

int global_id = 100;

class Person {
    string name;
    int id;
    float salary;

    public:
        Person() {
            name = "";
            id = -1;
            salary = -1.0;
        }

        void set_name(string name) {
            this->name = name;
        }

        void set_salary(float salary) {
            this->salary = salary;
        }

        Person(string name, float salary) {
            set_name(name);
            set_salary(salary);
            this->id = global_id;
            global_id++;
        }

        int get_id() {
            return id;
        }

        string get_name() {
            return name;
        }

        float get_salary() {
            return salary;
        }

        void print() {
            cout << id << "->" << name << "->" << salary << endl;
        }
};



int main() {
    // Stack <pair<int, char>> st;

    // st.push(make_pair(1, 'M'));
    // st.push(make_pair(2, 'E'));
    // st.push(make_pair(3, 'H'));
    // // st.push(4.2);
    // // st.push(4.2);

    // while(!st.empty()) {
    //     pair<int, char> value;
    //     value = st.pop();

    //     cout << value.first << "-" << value.second << endl;
    // }

    // cout << st.size() << endl;
    // cout << st.Top() << endl; 

    Stack <Person> st;
    Person a ("Mehedi", 200.5);
    Person b ("Parvez", 201.5);
    Person c ("Eti", 202.5);

    st.push(a);
    st.push(b);
    st.push(c);

    // while(!st.empty()) {
    //     Person print_object = st.pop();
    //     print_object.print();
    // }

    Person p_ob = st.Top();
    cout << p_ob.get_id() << " " << p_ob.get_name() << " " << p_ob.get_salary() << endl;
}