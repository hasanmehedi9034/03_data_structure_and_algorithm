#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

void insert_at_bottom(Stack<int> &chk, int chk_element) {
    if(chk.empty()) {
        chk.push(chk_element);
        return;
    }

    int top_element = chk.Top();
    chk.pop();

    insert_at_bottom(chk, chk_element);

    chk.push(top_element);
}

void reverse_stack(Stack<int> &chk) {
    if (chk.empty()) {
        return;
    }

    int top_element = chk.Top();
    chk.pop();
    reverse_stack(chk);

    insert_at_bottom(chk, top_element);
}

int main() {
    Stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverse_stack(st);

    while(!st.empty()) {
        cout << st.pop() << endl;
    }
}