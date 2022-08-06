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

void print_node(Node *head) {
    while(head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *first = new Node(5);
    Node *second = new Node(7);
    Node *third = new Node(1);
    Node *fourth = new Node(14);
    Node *fifth = new Node(3);
    Node *sixth = new Node(11);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    int sum = 0;
    Node *temp = first;

    while(temp->value != 3) {
        sum += temp->value;
        temp = temp->next;
    }

    sum -= temp->value;
    cout << sum << endl;

    print_node(first);
}


// All Answer;
/*
    1. Value of Head is 5;
    2. 1020 is In place of Question(?) mark
    3. 1 is the value of Head->Next->Next->Value.
    4. 24 is total sum value.
*/