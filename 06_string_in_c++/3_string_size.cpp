#include <bits/stdc++.h>
using namespace std;

int main() {
    string st = "Mehedi";
    cout << st.length() << endl;
    cout << st.size() << endl;
    st.resize(4);
    st.clear();
    if (st.empty()) {
        cout << "this is empty string" << endl;
    }
}