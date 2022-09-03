#include <bits/stdc++.h>
using namespace std;

class treeNode {
    public:
        int data;
        treeNode* leftChild;
        treeNode* rightChild;

        treeNode(int value) {
            data = value;
            leftChild = NULL;
            rightChild = NULL;
        }
};

void printTree(treeNode* root, int level);
void spacePrint(int level);
void inOrder_traversal(treeNode* root, string &chk);
void preOrder_traversal(treeNode* root, string &chk);
void postOrder_traversal(treeNode* root, string &chk);

void printTree(treeNode* root, int level) {
    if (root == NULL) return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data;
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
        cout << endl;
    }

    if (root->rightChild != NULL) {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->rightChild, level + 1);
    }
}

void spacePrint(int level) {
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
}

void inOrder_traversal(treeNode* root, string &chk) {
    if (root == NULL) return;

    inOrder_traversal(root->leftChild, chk);

    chk += to_string(root->data);

    inOrder_traversal(root->rightChild, chk);
}

void preOrder_traversal(treeNode* root, string &chk) {
    if (root == NULL) return;

    chk += to_string(root->data);

    preOrder_traversal(root->leftChild, chk);
    preOrder_traversal(root->rightChild, chk);
}

void postOrder_traversal(treeNode* root, string &chk) {
    if (root == NULL) return;

    postOrder_traversal(root->leftChild, chk);
    postOrder_traversal(root->rightChild, chk);

    chk += to_string(root->data);
}

int main() {
    int n;
    cin >> n;


}

/*

9
inOrder Traversal: 3 1 4 0 7 5 8 2 6
preOrder Traversal: 0 1 3 4 2 5 7 8 6
postOrder Traversal: 3 4 1 7 8 5 6 2 0
*/