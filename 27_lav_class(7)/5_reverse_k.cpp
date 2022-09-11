#include <bits/stdc++.h>
using namespace std;

void reverse_k(queue<int> &q, int n, int k) {
    int x = n / k;
    int y = n % k;

    stack <int> st;
    
    // while(x > 0) {
    //     int chk = k;
        while(k > 0) {
            st.push(q.front());
            q.pop();
            k--;
        }


        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        while(k > 0) {
            st.push(q.front());
            q.pop();
            k--;
        }


        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    //     x--;
    // }

    // while(y > 0) {
    //     st.push(q.front());
    //     q.pop();
    //     y--;
    // }

    // while(!st.empty()) {
    //     q.push(st.top());
    //     st.pop();
    // }
}

int main() {
    int n, k; 
    cin >> n >> k;

    queue <int> q;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    reverse_k(q, n, k);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}