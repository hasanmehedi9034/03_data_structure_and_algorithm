#include <bits/stdc++.h>
#include "MYSTACKs.h"

using namespace std;

int main() {
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(0);

    while(!st.is_empty()) {
        cout << st.top_val() << endl;
        st.pop();
    }
}