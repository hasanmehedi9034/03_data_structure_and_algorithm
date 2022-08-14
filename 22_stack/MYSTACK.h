#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node (int val) {
            this->value = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

class Stack {
    private:
        Node* head;
        Node* top;
        int count = 0;

    public:
        Stack() {
            this->head = NULL;
            this->top == NULL;
        }

        // PUSH
        void push(int val) {
            Node* new_node = new Node(val);

            if (head == NULL) {
                head = top = new_node;
                count++;
                return;
            }
            
            top->next = new_node;
            new_node->prev = top;
            top = new_node;
            count++;
        }

        // POP
        int pop() {
            Node* del_node;
            del_node = top;
            int check = -1;

            if (head == NULL) {
                cout << "Stack Underflow" << endl;
                return check;
            }

            if (top == head) {
                check = head->value;
                head = top = NULL;
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
        
        // EMPTY
        bool empty() {
            if (head == NULL) return true;
            return false;
        }

        // TOP
        int Top() {
            if (head == NULL) {
                cout << "Stack Underflow, There is no element in the stack" << endl;
                return -1;
            }
            return top->value;
        }

        // SIZE
        int size() {
            if (head == NULL) return 0;
            return count;
        }

};
