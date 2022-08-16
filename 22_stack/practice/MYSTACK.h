#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node* prev;
        Node* next;
        Node(int val) {
            this->value = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

class Stack{
    private:
        Node* head;
        Node* top;
        int count = 0;
    
    public:
        Stack() {
            head = NULL;
            top = NULL;
        }
        
        void push(int val) {
            Node* new_node = new Node(val);

            if (head == NULL) {
                head = new_node;
                top = new_node;
                count++;
                return;
            }

            top->next = new_node;
            new_node->prev = top;
            top = new_node;
            count++;
        }

        int pop() {
            Node* del_node = top;
            int check;

            if(head == NULL) {
                cout << "List is empty, that's why you can't pop operation" << endl;
                return -1;
            }

            if (top == head) {
                check = head->value;
                head = NULL;
                top == NULL;
                count--;
                return check;
            }

            top = del_node->prev;
            del_node->prev->next = NULL;
            check = del_node->value;

            delete del_node;
            count--;

            return check;
        }

        bool empty() {
            if (head == NULL) return true;
            return false;
        }

        int top_value() {
            if (head == NULL) {
                return -1;
            }
            return top->value;
        }

        int size() {
            return count;
        } 
};