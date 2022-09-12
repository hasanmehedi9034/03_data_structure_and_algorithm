#include <bits/stdc++.h>
using namespace  std;

class treeNode {
    public:
        int data;
        treeNode* leftChild;
        treeNode*  rightChild;

        treeNode(int val) {
            data = val;
            leftChild = NULL;
            rightChild = NULL;
        }
};

treeNode* insertionBST(treeNode* root, int value) {
    treeNode* new_node = new treeNode(value);

    if (root == NULL) {
        root = new_node;
        return root;
    }

    if (value < root->data) {
        root->leftChild = insertionBST(root->leftChild, value);
    }
    else if (value > root->data) {
        root->rightChild = insertionBST(root->rightChild, value);
    }

    return root;
}

void inOrder(treeNode* root, string &chk) {
    if (root == NULL) return;

    inOrder(root->leftChild, chk);

    chk += (to_string(root->data) + " ");

    inOrder(root->rightChild, chk);
}

int main() {
    int n;
    cin >> n;

    treeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        root = insertionBST(root, value);
    }

    string chk_inorder = "";
    inOrder(root, chk_inorder);
    cout << chk_inorder << endl;
}


/*
9
11 5 9 43 34 1 2 7 21
*/