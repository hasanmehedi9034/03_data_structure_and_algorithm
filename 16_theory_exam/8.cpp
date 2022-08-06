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

void print_forward_way(Node *head) {
    while(head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void reversedListPrint(Node *head) {
    if (head == NULL) return;

    reversedListPrint(head->next);

    cout << head->value << " ";
}

void insert_at_tail(Node* &head, int value) {
    Node *new_node = new Node(value);
    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void insert_at_head(Node* &head, int value) {
    Node *new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

int main() {
    Node *head = NULL;

    // insert at the tail
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);

    // insert at the head
    insert_at_head(head, -1);
    insert_at_head(head, -2);

    // print forward way
    print_forward_way(head);

    // print reverse way.
    reversedListPrint(head);
}