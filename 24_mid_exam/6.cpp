#include <bits/stdc++.h>
using namespace std;

void input_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

class Node{
    public:
        int value;
        Node* next;
        Node(int val) {
            this->value = val;
            this->next = NULL;
        }
};

void  print_list(Node* head) {
    if (head == NULL) {
        cout << "list is empty" << endl;
    }

    while(head != NULL) {
        cout << head->value;

        head = head->next;

        if (head != NULL) {
            cout << " -> ";
        }
    }
    cout << endl;
}

void insert_at_tail(Node* &head, int val) {
    int working_number = val;

    if (working_number % 2 == 0) {
        working_number = -1;
    }

    Node* new_node = new Node(working_number);

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    input_array(a, n);

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        insert_at_tail(head, a[i]);
    }

    print_list(head);
}