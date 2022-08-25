#include <bits/stdc++.h>
using namespace std;

template<typename N> class Node {
    public:
        N value;
        Node* next;

        Node(N val) {
            this->value = val;
            this->next = NULL;
        }
};

template<typename Q> class Queue {
    Node<Q>* front;
    Node<Q>* rear;

    public:
        Queue() {
            front = NULL;
            rear = NULL;
        }

        // enqueue --> push(val)
        void push(Q val) {
            Node<Q>* new_node = new Node<Q>(val);

            if (front == NULL) {
                front = new_node;
                rear = new_node;
                return;
            }

            rear->next = new_node;
            // rear = new_node;
            rear = rear->next;
        }

        // dequeue -->> pop()
        Q pop() {
            // int chk = -1;;
            Q chk;

            if (rear == NULL) {
                cout << "queue underflow | there is no element" << endl;
                return chk;
            }

            Node<Q>* del_node = front;

            chk = del_node->value;

            front = front->next;
            
            if (front == NULL) {
                rear = NULL;
            }

            delete del_node;

            return chk;
        }

        // peek ---> front(), back()
        Q Front() {
            Q chk = front->value;

            return chk;
        }

        Q Back() {
            Q chk;

            chk = rear->value;
            return chk;
        }

        // empty ---> empty()
        bool empty() {
            if (front == NULL && rear == NULL) return true;
            return false;
        }
};
