#include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
        char letter;
        Node* next;
        Node(char val) {
            this->letter = val;
            this->next = NULL;
        }
};

void print_list(Node* head) {
    if(head == NULL) {
        cout << "List is  Empty" << endl;
        return;
    }

    while(head != NULL) {
        cout << head->letter;
        head = head->next;
    }
    cout << endl;
}

void insert_at_tail(Node* &head, char val) {
    Node* new_node = new Node(val);
    Node* temp = head;

    if (head == NULL) {
        head = new_node;
        return;
    }

    
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

Node* reverse_list(Node* &head) {
    if (head == NULL) {
        cout << "List is empty, that's why it may not revese" << endl;
        return head;
    }
    

    Node* prev = NULL;
    Node* current = head;
    Node* current_next = head->next;

    while(true) {
        current->next = prev;
        prev = current;
        current = current_next;

        if (current == NULL) break;;
        current_next = current_next->next;
    }
    return prev;
}

bool is_palindrome(Node* &head) {
    string first = "";
    Node* temp1 = head;

    while(temp1 != NULL) {
        first.push_back(temp1->letter);
        temp1 = temp1->next;
    }

    string second = "";
    Node* p = head;
    Node* temp2 = reverse_list(p);

    while(temp2 != NULL) {
        second.push_back(temp2->letter);
        temp2 = temp2->next;
    }

    print_list(p);
    cout << """""""" << endl;

    if (first == second) return true;
    return false;
}

int main() {
    Node* head = NULL;

    insert_at_tail(head, 'r');
    insert_at_tail(head, 'a');
    insert_at_tail(head, 'd');
    insert_at_tail(head, 'a');
    insert_at_tail(head, 'r');

    // print_list(head);

    // head = reverse_list(head);
    // print_list(head);

    bool is_p = is_palindrome(head);
    if(is_p) cout << "Palindrom" << endl;
    else cout << "Not palindrom" << endl;

    print_list(head);
}