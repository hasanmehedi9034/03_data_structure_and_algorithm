#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack <int> st;
    stack <int> min_stack;

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] <= min) {
            min_stack.push(a[i]);
            min = a[i];
        }
        st.push(a[i]);
    }

    while(!st.empty()) {
        if (min_stack.top() != st.top()) {
            st.pop();
            cout << min_stack.top() << " ";
        }
        else {
            cout << min_stack.top() << " ";
            min_stack.pop();
            st.pop();
        }
    }
}