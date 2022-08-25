#include <bits/stdc++.h>
#include "MYQUEUE.h"

using namespace std;

int main() {
    typedef pair <string, int> mytype;

    Queue <mytype> q;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int roll;

        cin >> name >> roll;

        q.push(make_pair(name, roll));
    }

    while(!q.empty()) {
        mytype chk;
        chk = q.pop();

        cout << chk.first << "-" << chk.second << endl;
    }
    cout << endl;
}