#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

void insert_at_bottom(Stack <int> &st, int value) {
    if (st.empty()) {
        st.push(value);
        return;
    }

    int top_val = st.top_value();
    st.pop();

    insert_at_bottom(st, value);
    st.push(top_val);

}

void reverse_stack(Stack <int> &st) {
    if (st.empty()) {
        return;
    }

    int top_value = st.top_value();
    st.pop();

    reverse_stack(st);

    insert_at_bottom(st, top_value);
}

int main() {
    Stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse_stack(st);

    while(!st.empty()) {
        cout << st.pop() << endl;
    }
}