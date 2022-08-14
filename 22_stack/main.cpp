#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

int main() {
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(4);

    while(!st.empty()) {
        cout << st.pop() << endl;
    }

    cout << st.size() << endl;
    cout << st.Top() << endl; 
}