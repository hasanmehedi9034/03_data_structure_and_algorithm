#include <bits/stdc++.h>
using namespace std;

template <typename N> class Node{
    public:
        N value;
        Node* next;
        Node* prev;

        Node(N val) {
            value = val;
            next = NULL;
            prev = NULL;
        }
};

template <typename S> class Stack{
    private:
        Node <S> * head;
        Node <S> * top;
        int count = 0;
    
    public:

        Stack() {
            head = NULL;
            top = NULL;
        }

        void push(S value) {
            Node <S> * new_node = new Node <S> (value);

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

        S pop() {
            Node <S> * del_node;
            del_node = top;
            S check;

            if (head == NULL) {
                cout << "Stack underflow" << endl;
                return check;
            }                

            if (head == top) {
                check = del_node->value;
                head = NULL;
                top = NULL;
                return check;
            }
            
            check = del_node->value;

            top = del_node->prev;
            del_node->prev->next = NULL;
            
            delete del_node;
            count--;
            return check;
        }

        bool empty() {
            if (head == NULL) return true;
            return false;
        }

        int size() {
            return count;
        }

        S top_value() {
            return top->value;
        }
};