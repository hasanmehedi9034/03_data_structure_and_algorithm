#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node (int val) {
            this->value = val;
            this->next = NULL;
        }
};

void print_list(Node* head);
int list_size(Node *head);
void insert_at_tail(Node* &head, int val);
void delete_head(Node* &head);
void delete_tail(Node* &head);
void delete_specific_position(Node* &head, int pos);
void remove_duplicate(Node* &head);

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

int list_size(Node *head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return size;
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

void delete_head(Node* &head) {
    Node *del_node = head;
    head = del_node->next;
    delete del_node;
    return;
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

void delete_specific_position(Node* &head, int pos) {
    int size = list_size(head);
    if (head == NULL) return;
    else if (pos == 1) delete_head(head);
    else if (pos == size) delete_tail(head);
    else {
        Node *temp = head;
        int position = 1;
        while(position < pos - 1) {
            temp = temp->next;
            position++;
        }
        Node *del_node = temp->next;
        temp->next = del_node->next;
        delete del_node;
    }
}

void remove_duplicate(Node* &head) {
    Node* i;
    Node* j;
    int pos = 0;
    int pos2 = 0;

    for (i = head; i->next != NULL; i = i->next) {
        pos++;

        for (j = i->next; j->next != NULL; j->next) {
            pos2 = pos;
            pos2++;

            if(i->value == j->value) {
                delete_specific_position(head, pos2);
            }
        }
    }
}

int main() {
    Node* head = NULL;

    insert_at_tail(head, 2);
    insert_at_tail(head, 2);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);

    print_list(head);
}