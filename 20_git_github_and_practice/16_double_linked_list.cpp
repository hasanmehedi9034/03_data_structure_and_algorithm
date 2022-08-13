#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node* prev;
        Node* next;

        Node(int val) {
            this->value = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

int list_size(Node* head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

void print_list(Node* head) {
    if(head == NULL) {
        cout << "list is empty." << endl;
    }
    else {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << "list size: " << list_size(head) << endl;
}

void insert_at_head(Node* &head, int val) {
    Node* new_node = new Node(val);
    if (head == NULL) {
        head = new_node;
    }
    else {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
}

void insert_at_tail(Node* &head, int val) {
    Node* new_node = new Node(val);

    if (head == NULL) head = new_node;
    else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insert_specific_position(Node* &head, int val, int pos) {
    Node* new_node = new Node(val);

    if (head == NULL || pos == 1) insert_at_head(head, val);
    else if (pos == list_size(head) + 1) insert_at_tail(head, val);
    else if (pos == list_size(head)) {
        Node* temp = head;

        while(temp->next->next != NULL) {
            temp = temp->next;
        }

        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }
    else {
        int p = 1;
        Node* temp2 = head;

        while(p < pos - 1) {
            temp2 = temp2->next;
            p++;
        }
        new_node->next = temp2->next;
        temp2->next = new_node;
    }
}

void delete_head(Node* &head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
    }
    else if (list_size(head) == 1) {
        Node* del_node = head;
        head = NULL;
        delete del_node;
    }
    else {
        Node* del_n = head;
        head = head->next;
        head->prev = NULL;
        delete del_n;
    }
}

void delete_tail(Node* &head) {
    if (list_size(head) == 1) delete_head(head);
    else {
        Node* del_node = head;
        while(del_node->next->next != NULL) {
            del_node = del_node->next;
        }
        del_node->next = NULL;
        delete del_node->next;
    }
}

void delete_node_by_position(Node* &head, int pos) {
    if (head == NULL) cout << "List is empty" << endl;
    else if (pos > list_size(head)) cout << "out of bound" << endl;
    else if (pos == 1) delete_head(head);
    else if (pos == list_size(head)) delete_tail(head);
    else {
        int p = 1;
        Node* temp = head;

        while(true) {
            temp = temp->next;
            p++;
            if (p == pos) break;
        }
        cout << temp->value << endl;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
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

    print_list(head);
    cout << endl;

    move_head(head, 4);
    // insert_specific_position(head, 0, 2);
    print_list(head);
}