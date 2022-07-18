#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "ab ab cd          cd xy xy mehedi      ";
    stringstream stream(s);
    //stream << s;

    string w;
    while(stream >> w) {
        cout << w << endl;
    }
}