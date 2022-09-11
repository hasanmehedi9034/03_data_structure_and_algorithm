#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node* lChild;
        Node* rChild;
        int data;

        Node(int value) {
            lChild = NULL;
            rChild = NULL;
            data = value;
        }
};

void tree_create() {
    int x;
    cout << "Enter Root value: ";
    cin >> x;

    Node* root = new Node(x);

    queue <Node *>  q;

    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << ": ";
        cin >> x;

        if (x != -1) {
            Node* n1 = new Node(x);
        }
    }
}

int main() {
    tree_create();
}