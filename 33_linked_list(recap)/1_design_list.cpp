#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
    public:
        int val;
        MyLinkedList* next;
        MyLinkedList* head;

        MyLinkedList () {
            head = NULL;
        }

        MyLinkedList(int value) {
            this->val = value;
            this->next = NULL;
        }

        int get (int index) {
            MyLinkedList* temp = head;
            if (head == NULL) return -1;

            for (int i = 1; i < index; i++) {
                temp = temp->next;

                if (temp == NULL) break;;
            }

            if (temp == NULL) return -1;
            else return temp->val;
        }

        void addAtHead(int val) {
            MyLinkedList* newNode = new MyLinkedList(val);

            newNode->next = head;
            head = newNode;
        }

        void addAtTail(int val) {

            MyLinkedList* newNode = new MyLinkedList(val);

            if (head == NULL) head = newNode;

            MyLinkedList* temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;

        }

        void addAtIndex(int pos, int val) {
            if (pos == 0) {
                addAtHead(val);
                return;
            }

            MyLinkedList* temp = head;

            for (int i = 0; i < pos; i++) {
                temp = temp->next;
                if (temp == NULL) {
                    break;
                }
            }

            if (temp == NULL) {
                cout << "Invalid index to insert" << endl;
            }
            else {
                MyLinkedList* newNode = new MyLinkedList(val);
                newNode->next = temp->next;

                temp->next = newNode;
            }
        }

        void deleteAtIndex(int pos) {
            
        }
};  

int main() {
    
}