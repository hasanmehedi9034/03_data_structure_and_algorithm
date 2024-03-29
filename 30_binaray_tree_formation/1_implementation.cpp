#include <bits/stdc++.h>
using namespace std;

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

void printTree(treeNode* root, int level);
void spacePrint(int levet);
void inOrder(treeNode* root, string &chk);
void preOrder(treeNode* root, string &chk);
void postOrder(treeNode* root, string &chk);
void levelOrderTraversal(treeNode* root, string &chk);


void printTree(treeNode* root, int level) {
    if (root == NULL) return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data << endl;
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

void spacePrint(int level) {
    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
}

void inOrder(treeNode* root, string &chk) {
    if (root == NULL) return;

    inOrder(root->leftChild, chk);

    chk += to_string(root->data);

    inOrder(root->rightChild, chk);
}

void preOrder(treeNode* root, string &chk) {
    if (root == NULL) return;

    chk += to_string(root->data);

    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
}

void postOrder(treeNode* root, string &chk) {
    if (root == NULL) return;

    postOrder(root->leftChild, chk);
    postOrder(root->rightChild, chk);

    chk += to_string(root->data);
}

void levelOrderTraversal(treeNode* root, string &chk) {
    if (root == NULL) return;

    queue <treeNode*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        treeNode* chkNode = q.front();
        q.pop();

        if (chkNode != NULL) {
            chk += to_string(chkNode->data);
            if(chkNode->leftChild != NULL) {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL) {
                q.push(chkNode->rightChild);
            }

        }
        else {
            if (!q.empty()) {
                q.push(NULL);
            }
        }
    }
}



int main(){
    int n;
    cin >> n;

    treeNode* allNodes[n];

    for (int i = 0; i < n; i++){
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++) {
        int value, left, right;
        cin >> value >> left >> right;

        allNodes[i]->data = value;

        if (left != -1) {
            allNodes[i]->leftChild = allNodes[left];
        }

        if (right != -1) {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    // printTree(allNodes[0], 0);

    string inorder_chk = "";
    inOrder(allNodes[0], inorder_chk);
    cout << "In order Traversal: " << inorder_chk << endl;

    string preorder_chk = "";
    preOrder(allNodes[0], preorder_chk);
    cout << "Pre Order traversal: " << preorder_chk << endl;

    string postorder_chk = "";
    postOrder(allNodes[0], postorder_chk);
    cout << "Post Order traversal: " << postorder_chk << endl;

    string level_chk = "";
    levelOrderTraversal(allNodes[0], level_chk);
    cout << "Level Order: " << level_chk << endl;
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