#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

int precision_calculation(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infix_to_postfix(string chk) {
    Stack <char> st;

    string result = "";

    for (int i = 0; i < chk.length(); i++) {
        if (chk[i] >= '0' && chk[i] <= '9') {
            result += chk[i];
        }
        else if(chk[i] == '(') {
            st.push(chk[i]);
        }
        else if (chk[i] == ')') {
            while(!st.empty() && st.Top() != '(') {
                result += st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && precision_calculation(st.Top()) >= precision_calculation(chk[i])) {
                result += st.pop();
            }
            st.push(chk[i]);
        }
    }

    while(!st.empty()) {
        result += st.pop();
    }

    return result;
}

int postfix_evaluation(string chk) {
    Stack <int> st;

    for (int i = 0; i < chk.length(); i++) {
        if (chk[i] >= '0' && chk[i] <= '9') {
            st.push(chk[i] - '0');
        }
        else {
            int a = st.pop();
            int b = st.pop();

            switch(chk[i]) {
                case '+':
                    st.push(a + b);
                    break;
                case '-':
                    st.push(b - a);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    st.push(b / a);
                    break;
                default:
                    break;
            }
        }
    }
    return st.Top();
}

int main() {
    cout << postfix_evaluation("435*-2+") << endl;
    cout << infix_to_postfix("4*(3+5)-(2+0)") << endl;
}