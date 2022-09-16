#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> h;
int main() {
    vector <int> v(3, 0);
    v.push_back(3);

    vector<int>:: iterator it;

    // for (it = v.begin(); it != v.end(); it++) {
    //     cout << *it << " ";
    // }

    cout << endl;

    // auto resister
    // for (auto element:v) {
    //     cout << element << " ";
    // }

    priority_queue <int, vector<int>, greater<int>> PQ;
    PQ.push(1);
    PQ.push(6);
    PQ.push(4);
    PQ.push(7);
    PQ.push(0);

    // cout << endl;
    // while(!PQ.empty()) {
    //     cout << PQ.top() << " ";
    //     PQ.pop();
    // }
    // cout << endl;

    pair<int, int> p;
    priority_queue <h, vector<h>> pss;

    pss.push(make_pair(1, 2));
    pss.push(make_pair(3, 4));
    pss.push(make_pair(0, 0));

    while(!pss.empty()) {
        cout << "[" << pss.top().first << ", " << pss.top().second << "] ";
        pss.pop();
    }
    cout << endl;
}