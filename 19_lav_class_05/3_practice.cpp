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

Node* reverse_list(Node* &head) {
    if (head == NULL) {
        cout << "list is empty" << endl;
        return head;
    }

    Node *prev = NULL;
    Node *current = head;
    Node *next = head->next;

    while(true) {
        current->next = prev;
        prev = current;
        current = next;

        if (current == NULL) break;
        next = next->next;
    }
    return prev;
}

Node* r_list_non_recursive(Node* &head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return head;
    }

    Node *prev = NULL;
    Node *current = head;
    Node *next = head->next;

    while(true) {
        current->next = prev;
        prev = current;
        current = next;

        if (current == NULL) break;

        next = next->next;
    }
    return prev;
}

Node *reverse_list_recursive(Node* &head) {
    if (head == NULL || head->next == NULL) {
        if (head == NULL) {
            cout << "The linked list is empty." << endl;
        }
        return head;
    }

    Node *new_head = reverse_list_recursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return new_head;
}

int main() {

}