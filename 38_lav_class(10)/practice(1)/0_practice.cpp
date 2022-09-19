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

treeNode* insertionBST(treeNode* root, int value) {
    treeNode* newNode = new treeNode(value);

    if (root == NULL) {
        root = newNode;
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

void zigzagTraversal(treeNode* root) {
    stack <treeNode*> currentLevel;
    stack <treeNode*> nextLevel;

    currentLevel.push(root);

    bool leftToRight = true;

    while(!currentLevel.empty()) {
        treeNode* x = currentLevel.top();
        currentLevel.pop();

        cout << x->data << " ";

        if (leftToRight) {
            if (x->leftChild != NULL) nextLevel.push(x->leftChild);
            if (x->rightChild != NULL) nextLevel.push(x->rightChild);
        }
        else {
            if (x->rightChild != NULL) nextLevel.push(x->rightChild);
            if (x->leftChild != NULL) nextLevel.push(x->leftChild);
        }

        if (currentLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main() {
    int n;
    cin >> n;

    treeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        root =  insertionBST(root, value);
    }

    zigzagTraversal(root);

}

/*

9
11 5 9 43 34 1 2 7 21

*/