#include <bits/stdc++.h>
using namespace std;

int main() {
    // string st = "abc";
    // st.assign("aaa");

    string s1 = "Mehedi";
    s1.push_back('x');
    s1.pop_back();
    string s2 = "Hasan";
    s1.append(s2);
    cout << s1 << endl;

    string ch = "abcd";
    ch.insert(1, "mehedi");
    ch.erase(1, 6);
    cout << ch << endl;

    swap(s1, s2);
    cout << s1 << endl;
}