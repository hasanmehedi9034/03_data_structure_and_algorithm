#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
        Node(int val){
            this->value = val;
            this->next = NULL;
        }
};

int list_size(Node *head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

void print_list(Node *head)  {
    if (head == NULL) cout << "No Element in this linked list" << endl;
    else {
        cout << "List : [";
        Node *temp = head;

        while(temp != NULL) {
            cout << temp->value;
            if (temp->next  != NULL) cout << ", ";
            temp = temp->next;
        }
        cout << "]" << endl;
        cout << "List size: " << list_size(head) << endl;
    }
    
}

void insert_at_head(Node* &head, int val) {
    Node *new_node = new Node(val);
    if (head == NULL) {
        head = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
}

void insert_at_tail(Node* &head, int val) {
    Node *new_node = new Node(val);
    Node *temp = head;

    if (head == NULL) {
        head = new_node;
    }
    else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_specific_position(Node* &head, int val, int pos) {
    int size = list_size(head);
    if (head == NULL) insert_at_head(head, val);
    else if (pos == 1) insert_at_head(head, val);
    else if (size == pos) {
        Node *new_node = new Node(val);
        Node *temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    else if ((size + 1) == pos) {
        insert_at_tail(head, val);
    }
    else {
        Node *new_node = new Node(val);
        Node *temp = head;

        int p = 1;
        while(p < pos - 1) {
            temp = temp->next;
            p++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_tail(Node* &head) {
    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *del_node = temp->next;
    temp->next = NULL;
    delete del_node;
}

void delete_head(Node* &head) {
    Node *del_node = head;
    head = del_node->next;
    delete del_node;
    return;
}

void move_tail(Node* &head, int pos) {
    int tail_value = head->value;
    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    tail_value = temp->value;
    
    insert_specific_position(head, tail_value, pos);
    delete_tail(head);
}

void move_head(Node* &head, int pos) {
    int head_value = head->value;
    insert_specific_position(head, head_value, pos + 1);
    delete_head(head);
}

int main() {
    Node* head = NULL;

    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    insert_at_tail(head, 0);

    // print_list(head);
    // move_tail(head, 2);

    print_list(head);

    move_head(head, 3);
    print_list(head);
}