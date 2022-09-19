#include <bits/stdc++.h>
using namespace std;

class treeNode {
    public:
        int data;
        treeNode* leftChild;
        treeNode*  rightChild;

        treeNode(int value) {
            this->data = value;
            this->leftChild = NULL;
            this->rightChild = NULL;
        }
};

void inOrder(treeNode* root, string &chk) {
    if (root == NULL) return;

    inOrder(root->leftChild, chk);
    chk += to_string(root->data) + " ";
    inOrder(root->rightChild, chk);
}

treeNode* bst(treeNode* root, int value) {
    treeNode* newNode = new treeNode(value);

    if (root == NULL) {
        root = newNode;
        return root;
    } 

    if (root->data > value) {
        root->leftChild = bst(root->leftChild, value);
    }
    else if (root->data < value) {
        root->rightChild = bst(root->rightChild, value);
    }

    return root;
}

void spacePrint(int level){
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
}

void printTree(treeNode* root, int level) {
    if (root == NULL) return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data << endl;
        return;
    }
    else {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL) {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->leftChild, level + 1);
    }
    if (root->rightChild != NULL) {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

treeNode* searchNode(treeNode* root, int value) {
    if (root == NULL) return NULL;

    if (root->data == value) {
        return root;
    }
    else if (root->data > value) {
        return searchNode(root->leftChild, value);
    }
    else {
        return searchNode(root->rightChild, value);
    }
}

int main() {
    int n;
    cin >> n;

    treeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        root = bst(root, value);
    }

    // string inO = "";
    // inOrder(root, inO);
    // cout << inO;

    // printTree(root, 0);

    if (searchNode(root, 0) == NULL) {
        cout << "value not founded" << endl;
    }
    else {
        cout << "founded" << endl;
    }
}


/*

9
11 5 9 43 34 1 2 7 21

*/