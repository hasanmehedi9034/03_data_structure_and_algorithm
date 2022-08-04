#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;

        // constructor creation
        Node(int val) {
            this->value = val;
            this->next = NULL;
        }
};

void display(Node *n) {
    while(n != NULL) {
        cout << n->value;
        if (n->next != NULL) cout << "--> ";
        n = n->next;
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
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

int main() {
    Node *head = NULL;

    int n;
    
    char choice = 'y';
    while(choice == 'Y' || choice == 'y') {
        cout << "Enter the value: ";
        cin >> n;
        insert_at_tail(head, n);
        display(head);
        cout << "Do you want to continue: (Y/N) ";
        cin >> choice;
    }

    display(head);
}