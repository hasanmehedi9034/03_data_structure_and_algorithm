#include <bits/stdc++.h>
using namespace std;

class treeNode {
    public:
        int data;
        treeNode* leftChild;
        treeNode* rightChild;

        treeNode(int value) {
            this->data = value;
            this->leftChild = NULL;
            this->rightChild = NULL;
        }
};

void print_tree(treeNode* root, int level);
void space_print(int level);
void inOrder(treeNode* root, string &chk);

void print_tree(treeNode* root, int level) {
    if (root == NULL) return; // tree empty

    if (root->leftChild == NULL && root->rightChild == NULL) { // 1
        cout << root->data << endl;
        return;
    }
    else { // 2
        cout << endl;
        space_print(level);
        cout << "Root: "  << root->data << endl;
    }

    if (root->leftChild != NULL) {
        space_print(level);
        cout << "Left: ";
        print_tree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL) {
        space_print(level);
        cout << "Right: ";
        print_tree(root->rightChild, level + 1);
    }
}

void space_print(int level) {
    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
}

void inOrder(treeNode* root, string &chk){
    if (root == NULL) return;

    inOrder(root->leftChild, chk);

    chk += to_string(root->data);

    inOrder(root->rightChild, chk);
}

int main() {
    int n;
    cin >> n;
    
    treeNode* allNodes[n];
    for (int i = 0; i < n; i++) {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++) {
        int value, left, right;
        cin >> value >> left >> right;

        allNodes[i]->data = value;

        if (left > n -1 || right  > n - 1) {
            cout << "Invalid index" << endl;
            break;
        }
        if (left != -1) {
            allNodes[i]->leftChild = allNodes[left];
        }

        if (right != -1) {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    // print_tree(allNodes[0], 0);
    string inorder = "";
    inOrder(allNodes[0], inorder);

    cout << inorder << endl;
}



/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1



Root: 0
Left:
    Root: 1
    Left: 3
    Right: 4
Right: 
    Root: 2
    Left:
        Root: 5
        Left: 7
        Right: 8
    Right: 6



*/