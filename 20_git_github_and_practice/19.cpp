#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node* prev;
        Node* next;
        Node (int val) {
            this->value = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

int list_size(Node* head);
void print_list(Node* head);
void insert_at_head(Node* &head, int val);
void insert_at_tail(Node* &head, int val);

int list_size(Node* head) {
    int size = 0;

    while(head != NULL) {
        head = head->next;
        size++;
    }
    return size;
}

void print_list(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->value;
            if (temp->next != NULL) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << "list size : " << list_size(head) << endl;
}

void insert_at_head(Node* &head, int val) {
    Node* new_node = new Node(val);

    if (head == NULL) head = new_node;
    else {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
}

void insert_at_tail(Node* &head, int val) {
    Node* new_node = new Node(val);

    if (head == NULL) {
        head = new_node;
    }
    else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

int main() {
    Node* head = NULL;
    insert_at_tail(head, 2);
    insert_at_tail(head, 4);
    insert_at_tail(head, 1);
    insert_at_tail(head, 10);
    insert_at_tail(head, 5);

    print_list(head);
}   