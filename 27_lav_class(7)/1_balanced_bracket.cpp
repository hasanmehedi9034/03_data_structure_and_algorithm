#include <bits/stdc++.h>
using namespace std;

bool balanced_parenthesis(string s) {
    int n = s.size();

    stack <char> st;
    bool is_balanced = true;

    if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
        return false;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            if (st.top() == '(') {
                st.pop();
            }
            else {
                is_balanced = false;
            }
        }
        else if(s[i] == '}') {
            if (st.top() == '{') {
                st.pop();
            }
            else {
                is_balanced = false;
            }
        }
        else if(s[i] == ']') {
            if (st.top() == '[') {
                st.pop();
            }
            else {
                is_balanced = false;
            }
        }
    }
    if (!st.empty()) is_balanced = false;

    return is_balanced;
}

int main() {
    string chk;
    cin >> chk;

    if (balanced_parenthesis(chk))  {
        cout << "yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}