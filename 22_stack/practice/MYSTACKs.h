#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int val) {
            this->value = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

class Stack {
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
            }

            top->next = new_node;
            new_node->prev = top;
            top = new_node;
            count++;
        }

        void pop() {
            if (head == NULL) {
                cout << "there is nothing for pop operation, list is empty" << endl;
                return;
            }

            if(top == head) {
                head = NULL;
                top = NULL;
                return;
            }

            Node* del_node = top;

            top = del_node->prev;
            del_node->prev->next = NULL;
            
            delete del_node;
        }

        int top_val() {
            return top->value;
        }

        bool is_empty() {
            if (head == NULL) return true;
            return false;
        }
};