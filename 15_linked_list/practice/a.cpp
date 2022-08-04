#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
        Node (int val) {
            this->value = val;
            this->next = NULL;
        }
};

void print_linked_list(Node* n) {
    while(n != NULL) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

void  insert_at_tail(Node* &head, int value) {
    Node* new_node = new Node(value);

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = new_node;
}

void insert_at_head(Node* &head, int value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

int main() {
    Node *head = NULL;
    insert_at_head(head, 1);
    insert_at_tail(head, 10);
    insert_at_head(head, -100);
    print_linked_list(head);
}