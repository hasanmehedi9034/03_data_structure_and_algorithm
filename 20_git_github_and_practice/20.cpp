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

void displya(Node* head) {
    if (head == NULL) return;

    while(head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int list_size(Node *head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

void insert_tail(Node* &head, int val) {
    Node *new_node = new Node(val);

    if (head ==  NULL) {
        head = new_node;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
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

void sort_list(Node* &head) {
    Node *i, *j;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->value > j->value) {
                int temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
        }
    }
}

void sort2(Node* &head) {
    for (int i = 1; i <= list_size(head); i++) {
        bool is_found = false;
        for (Node* j = head; j->next != NULL; j = j->next) {
            if (j->value > j->next->value) {
                swap(j->value, j->next->value);
                is_found = true;
            }
        }
        if (!is_found) break;
    }
}

int main() {
    Node *head = NULL;

    insert_tail(head, 3);
    insert_tail(head, 4);
    insert_tail(head, 2);
    insert_tail(head, 5);
    // insert_tail(head, 1);
    // insert_tail(head, 2);
    // insert_tail(head, 3);

    sort2(head);
    
    // insert_at_tail(head, 10);
    // insert_at_tail(head, 1);
    // sort2(head);

    displya(head);
}