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

void print_linked_list(Node *head);
void insert_at_head(Node* &head, int val);
void insert_at_tail(Node* &head, int val);
int  count_length(Node *head);
void insert_at_specific_position(Node* &head, int pos, int value);
int search_by_value_unique(Node* &head, int key);
void search_by_value_duplicate(Node* &head, int value);

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

int search_by_value_unique(Node* &head, int key) {
    Node *temp = head;
    int count = 1;

    while(temp != NULL) {
        if (temp->value == key) return count;
        temp = temp->next;
        count++;
    }
    return -1;
}

void search_by_value_duplicate(Node* &head, int key) {
    int count = 1;
    int flag = false;

    int size = count_length(head);

    int position[size + 1];
    int k = 1;

    while(head != NULL) {
        if (head->value == key) {
            position[k] = count;
            k++;
            flag = true;
        }

        head = head->next;
        count++;
    }

    if (!flag) {
        cout << "The search value is not yet in this list" << endl;
    }
    else {
        position[0] = k;
        cout << "The value is found at Position : ";
        for(int i = 1; i < position[0]; i++) {
            cout << position[i];
            if (i < position[0] - 1) cout << ", ";
        }
    }
}

int main() {

}