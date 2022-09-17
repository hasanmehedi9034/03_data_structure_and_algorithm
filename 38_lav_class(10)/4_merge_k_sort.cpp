#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> PAIR;

int main() {
    int k;
    cin >> k;

    vector<vector<int>> allValues(k);

    for (int i = 0; i < k; i++) {
        int size;
        cin >> size;

        allValues[i] = vector<int> (size);

        for (int j = 0; j < size; j++) {
            cin >> allValues[i][j];
        }
    }

    vector<int>indexTracker(k, 0);

    priority_queue <PAIR, vector<PAIR>, greater<PAIR>> PQ;

    for (int i = 0; i < k; i++) {
        PQ.push(make_pair(allValues[i][0], i));
    }

    while(!PQ.empty()) {
        PAIR x = PQ.top();
        PQ.pop();

        indexTracker[x.second] + 1 < allValues[x.second].size()
        
    }


}

/*
3
3
1 4 7
2
3 5
3
2 6 7
*/