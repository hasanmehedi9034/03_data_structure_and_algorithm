#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main() {
    // vector <int> v(3, -1);

    // v.push_back(3);
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " "; 
    // }
    // cout << endl;

    // for (auto value:v) {
    //     cout << value << " ";
    // }
    // cout << endl;

    priority_queue <int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(33);
    pq.push(35);
    pq.push(2);

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    priority_queue<P, vector<P>, greater<P>> p;


}