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
void inOrder(treeNode* root, string &chk);
void preOrder(treeNode* root, string &chk);
treeNode* buildTreePreIn(int preOrder[], int inOrder[], int start, int end);
void boundaryTraversal(treeNode* root);
treeNode* insertionBST(treeNode* root, int value);
 
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
    chk += to_string(root->data) + " ";
    inOrder(root->rightChild, chk);
}

void preOrder(treeNode* root, string &chk) {
    if (root == NULL) return;

    chk += to_string(root->data);
    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
}

int searcInorder(int inOrder[], int current, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == current) {
            return i;
        }
    }
    return -1;
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

void printLeaves(treeNode* root) {
    if (root == NULL) return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data << " ";
        return;
    }

    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void  printLeftNonLeaves(treeNode* root) {
    if (root == NULL) return;

    if (root->leftChild != NULL) {
        cout << root->data << " ";
        printLeftNonLeaves(root->leftChild);
    }
    else if (root->rightChild != NULL) {
        cout << root->data << " ";
        printLeftNonLeaves(root->rightChild);
    }
}

void printRightNonLeaves(treeNode* root) {
    if (root == NULL) return;

    if (root->rightChild != NULL) {
        cout << root->data << " ";
        printRightNonLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL) {
        cout << root->data << " ";
        printRightNonLeaves(root->leftChild);
    }
}

void boundaryTraversal(treeNode* root) {
    if (root == NULL) return;

    cout << root->data << " ";

    printLeftNonLeaves(root->leftChild);

    printLeaves(root->leftChild);

    printLeaves(root->rightChild);

    printRightNonLeaves(root->rightChild);
}

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

treeNode* searchBST(treeNode* root, int value) {
    if (root == NULL) return NULL;

    if (root->data == value){
        cout << root->data << endl;
        return root;
    }
    else if (value < root->data) {
        cout << root->data << " -> ";
        return searchBST(root->leftChild, value);
    }
    else {
        cout << root->data << " -> ";
        return searchBST(root->rightChild, value);
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

    // string inO = "";
    // inOrder(root, inO);
    // cout << inO;

    if (searchBST(root, 34) == NULL) {
        cout << "Not founded" << endl;
    }
    else {
        cout << "Founded" << endl;
    }
}

/*

9
11 5 9 43 34 1 2 7 21

*/