#include <bits/stdc++.h>
using namespace std;

template <typename N> class Node {
    public:
        N num;
        Node* next;
        Node* prev;

        Node(N num) {
            this->num = num; 
            this->next = NULL;
            this->prev = NULL;
        }
};
 
template <typename S> class Stack {
    Node<S>* head = NULL;
    Node<S>* mid = NULL;
    Node<S>* top = NULL;

    int size = 0;
 
public:
    void push(S data) {
        Node<S>* temp = new Node<S>(data);

        if (size == 0) {
            head = temp;
            mid = temp;
            top = temp;

            size++;
            return;
        }

        if (top == head) {
            top->next = temp;
            temp->prev = top;
            top = temp;
            size++;
        }
 
        top->next = temp;
        temp->prev = top;
 
        top = temp;
        size++;
        if (size % 2 == 1) {
            mid = mid->next;
        }
    }
 
    S pop() {
        S data;
    
        if (size != 0) {
            data = top->num;

            if (size == 1) {
                head = NULL;
                mid = NULL;
                top = NULL;
            }
            else {
                top = top->prev;
                top->next = NULL;

                if (size % 2 == 0) {
                    mid = mid->prev;
                }
            }
            size--;
        }
      return data;
    }

 
    S findMiddle() {
        S check;

        if (head == NULL) {
            return check;
        }

        return mid->num;
    }
 
    void deleteMiddle() {
        if (size != 0) {
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2) {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
                else {
                    mid = mid->next;
                }
            }
            size--;
        }
    }

    S Top() {
        return top->num;
    }

    bool is_empty() {
        if (head == NULL) return true;
        return false;
    }

    int length() {
        return size;
    }
};