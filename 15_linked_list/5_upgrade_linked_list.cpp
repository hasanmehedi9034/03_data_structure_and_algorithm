#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;

        // constructor creation
        Node(int val) {
            this->value = val;
            this->next = NULL;
        }
};

void display(Node *n) {
    while(n != NULL) {
        cout << n->value;
        if (n->next != NULL) cout << "--> ";
        n = n->next;
    }
    cout << endl;
}

void insertion_at_tail(Node* &head, int value) {
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

void insertion_at_head(Node* &head, int val) {
    // step: 1 -> new node creation
    Node *new_node = new Node(val);

    // step: 2 -> update new node next
    new_node->next = head;

    // step: 3 -> update to head
    head = new_node;
}

int main() {
    Node *head = NULL;

    int n;
    
    cout << "Choice 1: Insertion at Head" << endl << "Choice 2: Insertion at tail" << endl << "Choice 3: Exit" << endl;

    int choice = 2;

    while(choice == 1 || choice == 2) {
        cout << "Enter the value: ";
        cin >> n;
        // insertion_at_tail(head, n);
        if (choice == 1) insertion_at_head(head, n);
        else if (choice == 2) insertion_at_tail(head, n);
        display(head);
        cout << "Next Choice: (1/2) ";
        cin >> choice;
    }

    display(head);
}