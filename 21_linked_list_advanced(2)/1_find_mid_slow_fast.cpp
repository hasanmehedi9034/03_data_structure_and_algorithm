#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
        Node(int val){
            this->value = val;
            this->next = NULL;
        }
};

void print_list(Node *head);
void insert_at_head(Node* &head, int val);
void insert_at_tail(Node* &head, int val);
int list_size(Node *head);
void insert_specific_position(Node* &head, int val, int pos);
int search_unique_value(Node *head, int key);
int *search_value(Node *head, int key);
void insert_after_specific_value(Node* &head, int key, int val);
void delete_head(Node* &head);
void delete_tail(Node* &head);
void delete_specific_position(Node* &head, int pos);
void delete_single_value(Node* &head, int key);
void delete_multiple_value(Node* &head, int key);
int find_mid(Node* &head);
void make_cycle(Node* &head, int pos);
bool detect_cycle(Node* &head);
void remove_cycle(Node* &head);

void print_list(Node *head)  {

    if (head == NULL) cout << "No Element in this linked list" << endl;
    else {
        cout << "List : [";
        Node *temp = head;

        while(temp != NULL) {
            cout << temp->value;
            if (temp->next  != NULL) cout << ", ";
            temp = temp->next;
        }
        cout << "]" << endl;
        cout << "List size: " << list_size(head) << endl;
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

int list_size(Node *head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return size;
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

int search_unique_value(Node *head, int key) {
    if (head == NULL) return -1;
    else {
        int pos = 1;
        while(head != NULL) {
            if (head->value == key) {
                return pos;
            } 
            pos++;
            head = head->next;
        }
    }
    return -1;
}

int *search_value(Node *head, int key) {
    int size = list_size(head);
    int *arr = new int[size + 1], k = 1;
    bool is_found = false;

    int pos = 1;
    while(head != NULL) {
        if(head->value == key) {
            arr[k] = pos;
            k++;
            is_found = true;
        }
        head = head->next;
        pos++;
    }
    if (!is_found) arr[0] = 1;
    else arr[0] = k;

    return arr;
}

void insert_after_value(Node* &head, int key, int val) {
    int *positions = search_value(head, key);

    if (*positions == 1) {
        cout << "value not found in this list" << endl;
    }
    else {
        int inserted = 0;
        for(int i = 1; i < *positions; i++) {
            insert_specific_position(head, val, (*(positions + i) + inserted + 1));
            inserted++;
        }
    }
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

void delete_single_value(Node* &head, int key) {
    int pos = search_unique_value(head, key);
    delete_specific_position(head, pos);
}

void delete_multiple_value(Node* &head, int key) {
    while(search_unique_value(head, key) != -1){
        int pos = search_unique_value(head, key);
        delete_specific_position(head, pos);
    }
}

int find_mid(Node* &head) {
    if (head == NULL) {
        return -1;
    }
    
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

void make_cycle(Node* &head, int pos) {
    Node* temp = head;
    Node* start_node;
    int count = 1;

    while(temp->next != NULL) {
        if (count == pos) start_node = temp;

        temp = temp->next;
        count++;
    }
    temp->next = start_node;
}

bool detect_cycle(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;

        if (slow ->next == fast->next) {
            return true;
        }
    }
    return false;
}

void remove_cycle(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    // step 1: fast = slow
    do {
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    // step 2: re initialization of fast
    fast = head;

    // step 3: fast->nest == slow->next
    while(fast->next != slow->next) {
        fast = fast->next;
        slow = slow->next;
    }

    // step 4
    slow->next = NULL;
}

int main() {
    Node *head = NULL;

    cout 
    << "1. print list" << endl
    << "2. insert at head" << endl
    << "3. insert at tail" << endl
    << "4. insert at specific position" << endl
    << "5. search unique value" << endl
    << "6. insert after value" << endl
    << "7. delete head" << endl
    << "8. delete tail" << endl
    << "9. delete specific postion" << endl
    << "10. delete specific single value" << endl
    << "11. delete specific multiple values" << endl
    << "12. Mid value" << endl
    << "13. Make cycle" << endl
    << "14. detect cycle" << endl
    << "15. remove cycle(if any)" << endl;

    int option_number = 2;

    while(option_number != 0) {
        cout << "select your option: ";
        cin >> option_number;
        int val;
        switch(option_number) {
            case 1:
                print_list(head);
                break;

            case 2:
                cout << "inserted value of the head: ";
                cin >> val;
                insert_at_head(head, val);
                print_list(head);
                break;

            case 3:
                cout << "inserted value of the tail: ";
                cin >> val;
                insert_at_tail(head, val);
                print_list(head);
                break;

            case 4:
                cout << "inserted position: ";
                int pos;
                cin >> pos;
                cout <<"inserted value of position " << pos << ": ";
                cin >> val;
                insert_specific_position(head, val, pos);
                print_list(head);
                break;

            case 5:
                cout << "Enter searched value: ";
                cin >> val;

                int *arr;
                arr = search_value(head, val);
                if (*arr == 1) cout << "Not Found in this linked list"<< endl;
                else {
                    cout << "positions of " << val << ": ";
                    for (int i = 1; i < *arr; i++) {
                        cout << *(arr + i) << " ";
                    }
                    cout << endl;
                }
                break;

            case 6:
                cout << "Enter the value, which after you inserted: ";
                cin >> val;

                int inserted_value;
                cout << "Enter the value, which inserted: ";
                cin >> inserted_value;

                insert_after_value(head, val, inserted_value);
                print_list(head);
                break;

            case 7:
                cout << "if you want to delete head press(1/0): ";
                int is_delete_head;
                cin >> is_delete_head;
                if (is_delete_head == 1) delete_head(head);
                print_list(head);
                break;

            case 8:
                cout << "if you want to delete tail press(1/0): ";
                int is_delete_tail;
                cin >> is_delete_tail;
                if (is_delete_tail == 1) delete_tail(head);
                print_list(head);
                break;

            case 9:
                cout << "which position do you want to  delete: ";
                int del_pos;
                cin >> del_pos;
                delete_specific_position(head, del_pos);
                print_list(head);
                break;

            case 10:
                cout << "which value do you want to  delete: ";
                int del_value;
                cin >> del_value;
                delete_single_value(head, del_value);
                print_list(head);
                break;

            case 11:
                cout << "which values(multiple) do you want to  delete: ";
                int del_values;
                cin >> del_values;
                delete_multiple_value(head, del_values);
                print_list(head);
                break;

            case 12:
                cout << "Mid value is : " << find_mid(head) << endl;
                print_list(head);
                break; 

            case 13:
                int poss;
                cout << "Enter the position to make cycle: ";
                cin >> poss;
                make_cycle(head, poss);
                print_list(head);
                break;
            
            case 14:
                bool is_cycle = detect_cycle(head);
                if(is_cycle) cout << "yes the list have a cycle" << endl;
                else cout << "No, the list havent a cycle" << endl;
                break;

            case 15:
                if(detect_cycle(head)) remove_cycle(head);
                else {
                    cout << "the list have not cycle" << endl;
                }

            default:
                print_list(head);
                break;
        }
    }
}