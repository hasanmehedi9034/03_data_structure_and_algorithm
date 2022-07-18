#include <bits/stdc++.h>
using namespace std;

int main() {
    string st = "aaabxakadjahg";
    cout << st.find('b') << endl;
    cout << st.rfind('b') << endl;
    cout << st.find_first_of('b') << endl;
    cout << st.find_last_of('b') << endl;
    cout << st.find_first_not_of('b') << endl;
    cout << st.find_last_not_of('b') << endl;

    string sub_str = st.substr(2, 5);
    cout << st.substr(2, 5) << endl;
}