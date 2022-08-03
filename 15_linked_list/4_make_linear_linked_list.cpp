#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
};

void display(Node *n) {
    while(n != NULL) {
        cout << n->value;
        if (n->next != NULL) cout << "--> ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->value = 1;
    second->value = 5;
    third->value = 8;
    fourth->value = 9;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    display(head);
}