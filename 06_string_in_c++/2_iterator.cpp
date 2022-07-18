#include <bits/stdc++.h>
using namespace std;

int main() {
    string st = "abcdefghij";
    string:: iterator it;
    for(it = st.begin(); it != st.end(); it++) {
        cout << *it << endl;
    }
    cout << "--------------" << endl;

    string:: reverse_iterator r_it;
    for(r_it = st.rbegin(); r_it != st.rend(); r_it++) {
        cout << *r_it << endl;
    }
    cout << "--------Another------" << endl;

    for(string:: reverse_iterator rv_it = st.rbegin(); rv_it != st.rend(); rv_it++) {
        cout << *rv_it << endl;
    }

    cout << "-----auto----------" << endl;
    for(auto a = st.rbegin(); a != st.rend(); a++) {
        cout << *a << endl;
    }
}