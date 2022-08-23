#include <bits/stdc++.h>
using namespace std;

template <typename N> class Node {
    public:
        N value;
        Node* next;
        Node* prev;

        Node (N val) {
            this->value = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <typename S> class Stack {
    private:
        Node <S> * head;
        Node <S> * top;
        int count = 0;

    public:
        Stack() {
            this->head = NULL;
            this->top == NULL;
        }

        // PUSH
        void push(S val) {
            Node <S> * new_node = new Node <S> (val);

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
        S pop() {
            Node <S> * del_node;
            del_node = top;
            S check;

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
        S Top() {
            S check;
            if (head == NULL) {
                cout << "Stack Underflow, There is no element in the stack" << endl;
                return check;
            }
            return top->value;
        }

        // SIZE
        int size() {
            if (head == NULL) return 0;
            return count;
        }
};