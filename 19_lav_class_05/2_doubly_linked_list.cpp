#include <bits/stdc++.h>
using namespace std;

class Doubly_node {
    public:
        int value;
        Doubly_node *prev;
        Doubly_node *next;
        Doubly_node(int val) {
            this->value = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

void insert_at_head(Doubly_node* &head, int val);
void insert_at_tail(Doubly_node* &head, int val);
void print_list(Doubly_node *head);
int list_size(Doubly_node *head);

void insert_at_tail(Doubly_node* &head, int val) {
    Doubly_node *new_node = new Doubly_node(val);

    if (head == NULL) {
        head == new_node;
        return;
    }

    Doubly_node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

void insert_at_head(Doubly_node* &head, int val) {
    Doubly_node *new_node = new Doubly_node(val);
    
    if (head == NULL) {
        head = new_node;
        return;
    }

    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void print_list(Doubly_node *head) {
    if (head == NULL) {
        cout << "list is empty" << endl;
    }

    Doubly_node *temp = head;
    while(temp != NULL) {
        cout << temp->value;
        if (temp->next != NULL) cout << "--->";

        temp = temp->next;
    }
    cout << endl;
}

int list_size(Doubly_node *head) {
    int size = 0;
    while(head != NULL) {
        head = head->next;
        size++;
    }
    return size;
}

int main() {

}

