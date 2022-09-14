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

treeNode* searchBST(treeNode* root, int value) {
    if (root == NULL) return NULL;

    if (root->data == value) {
        cout << root->data;
        return root;
    } 
    else if (value < root->data) {
        cout << root->data << "->";
        return searchBST(root->leftChild, value);
    }
    else {
        cout << root->data << "->";
        return searchBST(root->rightChild, value);
    } 
}

treeNode* inorderSucc(treeNode* root) {
    treeNode* current_node = root;

    while(current_node->leftChild != NULL) {
        current_node = current_node->leftChild;
    }
    return current_node;
}

treeNode* deletionBST(treeNode* root, int value) {
    if (value < root->data) {
        root->leftChild = deletionBST(root->leftChild, value);
    }
    else if (value > root->data) {
        root->rightChild = deletionBST(root->rightChild, value);
    }
    else {
        if (root->leftChild == NULL) {
            treeNode* temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL) {
            treeNode* temp = root->leftChild;
            free(root);
            return temp;
        }
        else {
            treeNode* temp = inorderSucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deletionBST(root->rightChild, temp->data);
        }
    }
    return root;
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

    int key;
    cin >> key;
    if (searchBST(root, key) == NULL) {
        cout << endl << "Not found" << endl;
    }
    else {
        cout << endl << "value founded" << endl;
    }
}


/*
9
11 5 9 43 34 1 2 7 21
*/