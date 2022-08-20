#include <bits/stdc++.h>
using namespace std;

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
    Node* new_node = new Node(val);

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

void skipMdeleteN(Node *head, int M, int N) 
{ 
    Node *curr = head, *t; 
    int count; 
  
    // The main loop that traverses
    // through the whole list 
    while (curr) 
    { 
        // Skip M nodes 
        for (count = 1; count < M && 
                curr!= NULL; count++) 
            curr = curr->next; 
  
        // If we reached end of list, then return 
        if (curr == NULL) 
            return; 
  
        // Start from next node and delete N nodes 
        t = curr->next; 
        for (count = 1; count<=N && t!= NULL; count++) 
        { 
            Node *temp = t; 
            t = t->next; 
            free(temp); 
        } 
          
        // Link the previous list with remaining nodes 
        curr->next = t; 
  
        // Set current pointer for next iteration 
        curr = t; 
    } 
} 

int main() {
    Node* head = NULL;

    int k, m, n;
    cin >> k >> m >> n;

    for (int i = 0; i < k; i++) {
        int value;
        cin >> value;

        insert_at_tail(head, value);
    }

    skipMdeleteN(head, m, n);

    print_list(head);
}

