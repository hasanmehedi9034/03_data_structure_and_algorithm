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

void insert_at_tail(Node* &head, int val);
void insert_at_head(Node* &head, int val);
void print_linked_list(Node *head);
int  count_length(Node *head);
void insert_at_specific_position(Node* &head, int pos, int value);

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

}