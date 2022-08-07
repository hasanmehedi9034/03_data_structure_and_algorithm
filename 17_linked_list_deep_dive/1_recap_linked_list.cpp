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

void print_linked_list(Node *head) {
    cout << "Now linked list is : ";
    while(head != NULL) {
        cout << head->value;
        
        if (head->next != NULL) cout << ", ";

        head = head->next; 
    }
    cout << endl;
}

void insert_at_tail(Node* &head, int value) {
    Node *new_node = new Node(value);

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *temp = head;
    while (head->next != NULL) {
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
    if (head == NULL) cout << "there is no element in the linked list" << endl;

    while(true) {
        int n;
        cout << "do you more element insert(1/0): ";
        cin >> n;

        if (n != 1) break;

        cout << "which type of insert?"<< endl << "1. head"<< endl << "2. tail" << endl;
        int n2;
        cin >> n2;

        int n3;
        cout << "which value do you want insert :";
        cin >> n3;

        if (n2 == 1) insert_at_head(head, n3);
        if (n2 == 2) insert_at_tail(head, n3);

        print_linked_list(head);
    }
}