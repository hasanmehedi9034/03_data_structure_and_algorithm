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

void print_list(Node *head);
void insert_at_head(Node* &head, int val);
void insert_at_tail(Node* &head, int val);
int list_size(Node *head);

void print_list(Node *head)  {
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

int list_size(Node *head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

int main() {
    Node *head = NULL;

    cout 
    << "1. print list" << endl
    << "2. insert at head" << endl
    << "3. insert at tail" << endl
    << "4. insert at specific position" << endl;


    int option_number = 2;

    while(option_number != 0) {
        cout << "select your option: ";
        cin >> option_number;
        int val;
        switch(option_number) {
            case 1:
                print_list(head);
                break;
            case 2:
                cout << "inserted value of the head: ";
                cin >> val;
                insert_at_head(head, val);
                print_list(head);
                break;
            case 3:
                cout << "inserted value of the tail: ";
                cin >> val;
                insert_at_tail(head, val);
                print_list(head);
                break;
            default:
                print_list(head);
                break;
        }
    }
}