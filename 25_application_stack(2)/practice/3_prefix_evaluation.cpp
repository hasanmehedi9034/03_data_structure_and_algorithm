#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;

int precision_calc(char c) {
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

string infix_to_prefix(string chk) {
    reverse(chk.begin(), chk.end());
    cout << chk << endl;

    Stack <char> st;
    string result = "";

    for (int i = 0; i <chk.length(); i++) {
        if (chk[i] >= '0' && chk[i] <= '9') {
            result += chk[i];
        }
        else if (chk[i] == ')') {
            st.push(chk[i]);
        }
        else if (chk[i] == '(') {
            while(st.Top() != ')' && !st.empty()) {
                result += st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else {
            while(!st.empty() && precision_calc(st.Top()) >= precision_calc(chk[i])) {
                result += st.pop();
            }
            st.push(chk[i]);
        }
    }

    while(!st.empty()) {
        result += st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int prefix_evaluation(string chk) {
    Stack <int> st;

    for (int i = chk.length() - 1; i >= 0; i--) {
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
                    st.push(a - b);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    st.push(a / b);
                    break;
                case '^':
                    st.push(pow(a, b));
                    break;
                default:
                    break;
            }
        }
    }
    return st.Top();
}
int main() {
    cout << prefix_evaluation("+*423") << endl;
    cout << infix_to_prefix("2+(3*5)+2") << endl;
    cout << "result: " << prefix_evaluation(infix_to_prefix("2+(3*5)+2"));
}
