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
void insert_specific_position(Node* &head, int val, int pos);
int search_unique_value(Node *head, int key);

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

int list_size(Node *head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

void insert_specific_position(Node* &head, int val, int pos) {
    int size = list_size(head);
    if (head == NULL) insert_at_head(head, val);
    else if (pos == 1) insert_at_head(head, val);
    else if (size == pos) insert_at_tail(head, val);
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

int search_unique_value(Node *head, int key) {
    if (head == NULL) return -1;
    else {
        int pos = 1;
        while(head != NULL) {
            if (head->value == key) {
                return pos;
            } 
            pos++;
            head = head->next;
        }
    }
    return -1;
}

int main() {
    Node *head = NULL;

    cout 
    << "1. print list" << endl
    << "2. insert at head" << endl
    << "3. insert at tail" << endl
    << "4. insert at specific position" << endl
    << "5. search unique value" << endl;

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

            case 4:
                cout << "inserted position: ";
                int pos;
                cin >> pos;
                cout <<"inserted value of position " << pos << ": ";
                cin >> val;
                insert_specific_position(head, val, pos);
                print_list(head);
                break;

            case 5:
                cout << "Enter searched value: ";
                cin >> val;
                int position;
                position = search_unique_value(head, val);
                if (position == -1) cout << "Not Found in this linked list"<< endl;
                else cout << "The position of value :" << position << endl;
                break;

            default:
                print_list(head);
                break;
        }
    }
}