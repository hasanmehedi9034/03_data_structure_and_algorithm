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
treeNode* buildTreePreeIn(int preOrder[], int inOrder[], int start, int end);
int searchInOrder(int inOrder[], int current, int start, int end);

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

treeNode* buildTreePreeIn(int preOrder[], int inOrder[], int start, int end) {
    static int id = 0;

    int current = preOrder[id];
    id++;

    treeNode* newNode = new treeNode(current);

    if (start == end) {
        return newNode;
    }

    int pos = searchInOrder(inOrder, current, start, end);

    newNode->leftChild = buildTreePreeIn(preOrder, inOrder, start, pos - 1);

    newNode->rightChild = buildTreePreeIn(preOrder, inOrder, pos + 1, end);

    return newNode;
}

int searchInOrder(int inOrder[], int current, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == current){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    int pre_Order[n], in_Order[n];

    for (int i = 0; i < n; i++) {
        cin >> pre_Order[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> in_Order[i];
    }

    treeNode* root = buildTreePreeIn(pre_Order, in_Order, 0, n - 1);

    string  pre_chk = "";
    preOrder(root, pre_chk);
    cout << pre_chk << endl;
}

/*  
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6
*/