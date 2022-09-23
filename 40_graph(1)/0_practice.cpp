#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> edgeWeightPair;

class Graph {
    int V;
    list <edgeWeightPair> *adj;

    public:
        Graph(int v){
            this->V = v;
            adj = new list<edgeWeightPair> [V];
        }

        void addEdge(int u, int v, int w) {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        void printNeighbour(int chk) {
            cout << chk << ": ";
            for (auto i = adj[chk].begin(); i != adj[chk].end(); i++) {
                cout << "(" << (*i).first << ", " << (*i).second << ") ";
            }
            cout << endl;
        }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    for (int i = 0; i < V; i++) {
        g.printNeighbour(i);
    }
}