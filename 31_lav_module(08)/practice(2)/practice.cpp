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

int search_value(int inOrder[], int value, int start, int end) {
    for (int i = start; i < end; i++) {
        if (inOrder[i] == value) {
            return i;
        }
    }
    return -1;
}

treeNode* constructPreIn(int preOrder[], int inOrder[], int start, int end) {
    static int id = 0;
    int value = preOrder[id];

    treeNode* current_node = new treeNode(value);

    id++;

    if (start == end) return current_node;

    int pos = search_value(inOrder, value, start, end);

    current_node->leftChild = constructPreIn(preOrder, inOrder, start, pos - 1);
    current_node->rightChild = constructPreIn(preOrder, inOrder, pos + 1, end);

    return current_node;
}

void leftNonLeaves(treeNode* root) {
    if (root == NULL) return;

    if (root->leftChild != NULL) {
        cout << root->data << " ";
        leftNonLeaves(root->leftChild);
    }
    else if(root->rightChild != NULL) {
        cout << root->data << " ";
        leftNonLeaves(root->rightChild);
    }
}

void rightNonLeaves(treeNode* root) {
    if (root == NULL) return;

    if (root->rightChild != NULL) {
        cout << root->data << " ";
        rightNonLeaves(root->rightChild);
    }
    else if (root->leftChild != NULL) {
        cout << root->data << " ";
        rightNonLeaves(root->leftChild);
    }
}

void leaves(treeNode* root) {
    if (root == NULL) return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data << " ";
    }

    leaves(root->leftChild);
    leaves(root->rightChild);
}

void boundaryTraversal(treeNode* root) {
    if (root == NULL) return;

    cout << root->data << " ";

    leftNonLeaves(root->leftChild);
    leaves(root->leftChild);
    leaves(root->rightChild);
    rightNonLeaves(root->rightChild);
}

int main() {
    int n;
    cin >> n;

    int preOrder[n], inOrder[n];
    for (int i = 0; i < n; i++) {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
    }

    treeNode* root = constructPreIn(preOrder, inOrder, 0, n - 1);

    // print_tree(root, 0);
    // levelOrderTravesal(root);

    boundaryTraversal(root);
}
