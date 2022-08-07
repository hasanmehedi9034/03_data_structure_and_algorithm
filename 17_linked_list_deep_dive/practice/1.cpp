#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
        Node (int val){
            this->value = val;
            this->next = NULL;
        }
};

void print_linked_list(Node *head);
void insert_at_head(Node* &head, int val);
void insert_at_tail(Node* &head, int val);

void print_linked_list(Node *head) {
    cout << "[";
    while(head != NULL) {
        cout << head->value;
        if (head->next != NULL) cout << ", ";
        head = head->next;
    }
    cout << "]";
    cout << endl;
}

void insert_at_head(Node* &head, int val) {
    Node *new_node = new Node(val);

    if (head == NULL) {
        head = new_node;
        return;
    }

    new_node->next = head;
    head = new_node;
}

void insert_at_tail(Node* &head, int val) {
    Node *new_node = new Node(val);

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

int main() {
    Node *head = NULL;

    insert_at_head(head, 1);
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    insert_at_tail(head, 10);
    print_linked_list(head);
}