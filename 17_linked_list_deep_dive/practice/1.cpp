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
int list_size(Node *head);
void insert_at_specific_position(Node* &head, int pos, int value);
int search_by_value_unique(Node* head, int key);

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

int list_size(Node *head) {
    int count = 0;
    while(head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

void insert_at_specific_position(Node* &head, int pos, int value) {
    Node *new_node = new Node(value);

    if (head == NULL) {
        cout << "The list is Empty. if you insert a value, the is inserted at head position" << endl;
        head = new_node;
        return;
    }

    Node *temp = head;
    int count = 1;
    while(count < pos - 1) {
        temp = temp->next;
        count++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

int search_by_value_unique(Node* head, int key) {
    int position = 1;

    while(head != NULL) {
        if (head->value == key) return position;
        head = head->next;
        position++;
    }
    return -1;
}

int main() {
    Node *head = NULL;

    insert_at_head(head, 1);
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    insert_at_tail(head, 10);
    insert_at_specific_position(head, 2, 30);
    print_linked_list(head);
    cout << "position: " << search_by_value_unique(head, 300) << endl;
    cout << "total list length: " << list_size(head) << endl;
}