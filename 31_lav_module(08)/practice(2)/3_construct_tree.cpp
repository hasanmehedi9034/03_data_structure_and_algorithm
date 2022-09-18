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

void print_tree(treeNode* root, int level);
void spacePrint(int level);
void inOrder(treeNode* root, string &chk);
void preOrder(treeNode* root, string &chk);
void levelOrderTravesal(treeNode* root, string &chk);
treeNode* buildTreePreIn(int preOrder[], int inOrder[], int start, int end);
int searcInorder(int inOrder[], int current, int start, int end);
 
void spacePrint(int level) {
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
}

void print_tree(treeNode* root, int level) {
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
        print_tree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL) {
        spacePrint(level);
        cout << "Right: ";
        print_tree(root->rightChild, level + 1);
    }
}

void print_tree2(treeNode* root, int level) {
    if (root == NULL) return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data;
        return;
    }
    else {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->data << endl;
    }

    cout << "Left: ";
    print_tree(root->leftChild, level + 1);

    cout << "Right: ";
    print_tree(root->rightChild, level + 1);
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

void levelOrderTravesal(treeNode* root) {
    if (root == NULL) return;

    queue <treeNode*> q;
    q.push(root);
    q.push(NULL);

    int level = 0;

    while(!q.empty()) {
        treeNode* chkNode = q.front();
        q.pop();

        if (chkNode != NULL) {
            cout << chkNode->data << " ";
            if (chkNode->leftChild != NULL) {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL) {
                q.push(chkNode->rightChild);
            }
        }
        else {
            if (!q.empty()) {
                q.push(NULL);
                level++;
            }
        }
    }
    cout << endl << "Total Level: " << level;
}

treeNode* buildTreePreIn(int preOrder[], int inOrder[], int start, int end) {
    static int id = 0;

    int current = preOrder[id];
    treeNode* newNode = new treeNode(current);

    id++;

    if (start == end) {
        return newNode;
    }

    int pos = searcInorder(inOrder, current, start, end);

    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos + 1, end);

    return newNode;
}

int searcInorder(int inOrder[], int current, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == current) {
            return i;
        }
    }
    return -1;
}



int main() {
    int n;
    cin >> n;

    int preOrderArray[n], inOrderArray[n];

    for (int i = 0; i < n; i++) {
        cin >> preOrderArray[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inOrderArray[i];
    }

    treeNode* root = buildTreePreIn(preOrderArray, inOrderArray, 0, n - 1);

    string preO = "";
    preOrder(root, preO);

    cout << preO << endl;
}

/*
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6




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