#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
        Node (int val){
            this->value = val;
            this->next = NULL;
        }
};

struct Test{
    int position[1000];
};

void print_linked_list(Node *head);
void insert_at_head(Node* &head, int val);
void insert_at_tail(Node* &head, int val);
int list_size(Node *head);
void insert_at_specific_position(Node* &head, int pos, int value);
int search_by_value_unique(Node* head, int key);
void search_by_value_duplicate(Node* head, int key);
int* search_duplicate(Node *head, int key);
Test search_by_val_dup(Node *head, int key);
void insert_after_specific_value(Node *head, int key, int value);
void insert_before_specific_value(Node *head, int key, int value);
void delete_at_head(Node* &head);
void delete_at_tail(Node* &head);
void delete_at_specific_position(Node* &head, int pos);

void print_linked_list(Node *head) {
    cout << "[";
    while(head != NULL) {
        cout << head->value;
        if (head->next != NULL) cout << ", ";
        head = head->next;
    }
    cout << "]";
    cout << endl;
}

void insert_at_head(Node* &head, int val) {
    Node *new_node = new Node(val);

    if (head == NULL) {
        head = new_node;
        return;
    }

    new_node->next = head;
    head = new_node;
}

void insert_at_tail(Node* &head, int val) {
    Node *new_node = new Node(val);

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

int list_size(Node *head) {
    int count = 0;
    while(head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

void insert_at_specific_position(Node* &head, int pos, int value) {
    Node *new_node = new Node(value);

    if (head == NULL) {
        cout << "The list is Empty. if you insert a value, the is inserted at head position" << endl;
        head = new_node;
        return;
    }

    Node *temp = head;
    int count = 1;
    while(count < pos - 1) {
        temp = temp->next;
        count++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

int search_by_value_unique(Node* head, int key) {
    int position = 1;

    while(head != NULL) {
        if (head->value == key) return position;
        head = head->next;
        position++;
    }
    return -1;
}

void search_by_value_duplicate(Node* head, int key) {
    int position = 1;
    bool is_found = false;

    while(head != NULL) {
        if (head->value == key) {
            cout << position << " ";
            is_found = true;
        }
        head = head->next;
        position++;
    }
    if(!is_found) cout << "The search value is not yet in this list" << endl;
}

int* search_duplicate(Node *head, int key) {
    int *ar = new int[list_size(head) + 1];
    int arr_index = 1;

    int position = 1;
    bool is_found = false;

    while(head != NULL) {
        if (head->value == key) {
            is_found = true;
            ar[arr_index] = position;
            arr_index++;
        }
        head = head->next;
        position++;
    }

    if (!is_found) {
        ar[0] = -1;
        return ar;
    }
    else {
        ar[0] = arr_index;
        return ar;
    }
}

Test search_by_val_dup(Node *head, int key) {
    Node *temp = head;
    int k = 1;
    int count = 1;

    Test T;
    while (temp != NULL) {
        if (temp->value == key) {
            T.position[k] = count;
            k++;
        }
        temp = temp->next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void insert_after_specific_value(Node *head, int key, int value) {
    int pos = search_by_value_unique(head, key);
    insert_at_specific_position(head, pos + 1, value);    
}

void insert_before_specific_value(Node *head, int key, int value) {
    int pos = search_by_value_unique(head, key);
    insert_at_specific_position(head, pos - 1, value);    
}

void delete_at_head(Node* &head) {
    if (head == NULL) return;

    Node *temp = head;
    head = temp->next;
    delete temp;
}

void delete_at_tail(Node* &head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete_at_head(head);
        return;
    }

    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *del_node = temp->next;
    temp->next = NULL;
    delete del_node;
}

void delete_at_specific_position(Node* &head, int pos) {
    int size = list_size(head);

    if (head == NULL) return;
    else if (pos > size) return;
    else if (pos == 1) {
        delete_at_head(head);
        return;
    }
    else if(size == pos) {
        delete_at_tail(head);
        return;
    }
    else {
        int i = 1;
        while(i < pos - 1) {
            head = head->next;
            i++;
        } 
        Node *del_node = head->next;
        head->next = del_node->next;
        delete del_node;
    }
}

int main() {
    Node *head = NULL;

    insert_at_head(head, 1);
    insert_at_head(head, 1);
    insert_at_head(head, 1);
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    insert_at_head(head, 30);
    insert_at_head(head, 1);
    insert_at_tail(head, 10);
    insert_at_tail(head, 1);

    insert_after_specific_value(head, 10, -1);
    insert_before_specific_value(head, 3, -3);

    print_linked_list(head);
    cout << "size: " << list_size(head) << endl;
    // delete_at_head(head);
    // delete_at_tail(head);
    // print_linked_list(head);
    delete_at_specific_position(head, list_size(head));
    delete_at_specific_position(head, 1);
    print_linked_list(head);
    cout << "size: " << list_size(head) << endl;

    // Test T = search_by_val_dup(head, 1);
    // if (T.position[0] == 1) cout << "Not Found" << endl;
    // else {
    //     for (int i = 1; i < T.position[0]; i++) {
    //         cout << T.position[i];
    //         if (i < T.position[0] - 1) cout << ", ";
    //     }
    //     cout << endl;
    // }
    // cout << "total list length: " << list_size(head) << endl;
}