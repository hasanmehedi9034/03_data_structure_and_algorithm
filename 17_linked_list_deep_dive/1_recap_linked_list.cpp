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

int count_length(Node *head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return  size;
}

void insert_at_specific_position(Node* &head, int pos, int value) {
    Node *new_node = new Node(value);

    int i = 0;
    Node *temp = head;

    while(i < pos - 2) {
        temp = temp->next;
        i++;
    }

    new_node->next = temp->next;
    temp->next = new_node; 
}

int main() {
    Node *head = NULL;
    if (head == NULL) cout << "there is no element in the linked list" << endl;

    while(true) {
        int n;
        cout << "do you more element insert(1/0): ";
        cin >> n;

        if (n != 1) break;

        cout << "which type of insert?"<< endl 
        << "1. head"<< endl 
        << "2. tail" << endl
        << "3. insert at specific position" << endl;
        int n2;
        cin >> n2;

        int n3;
        cout << "which value do you want insert :";
        cin >> n3;

        if (n2 == 1) insert_at_head(head, n3);
        if (n2 == 2) insert_at_tail(head, n3);
        if (n2 == 3) {
            int pos;
            cout << "which position: ";
            cin >> pos;
            insert_at_specific_position(head, pos, n3);
        }

        print_linked_list(head);
        cout << "Length: " << count_length(head) << endl;
    }
}