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
void level_order_traversal(treeNode* root, string &chk);
treeNode* build_tree_pre_in(int pre[], int in[], int start, int end);
int search_inOrder(int in[], int current, int start, int end);


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

void level_order_traversal(treeNode* root, string &chk) {
    if (root == NULL) return;

    queue <treeNode *> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        treeNode* chkNode = q.front();
        q.pop();

        if (chkNode != NULL) {
            // cout << chkNode->data << " ";
            chk += to_string(chkNode->data);
            if (chkNode->leftChild != NULL) {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL) {
                q.push(chkNode->rightChild);
            }
        }
        else {
            if (!q.empty()) q.push(NULL);
        }
    }
}

int max_in_kth_level(treeNode* root, int level) {
    if (root == NULL) return  -1;

    int l = 0;

    int max = -99999;

    queue <treeNode *> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        treeNode* chkNode = q.front();
        q.pop();

        if (chkNode != NULL) {
            if (l == level) {
                if (max < chkNode->data) {
                    max = chkNode->data;
                }
            }
            if (chkNode->leftChild != NULL) {
                q.push(chkNode->leftChild);
            }
            if (chkNode->rightChild != NULL) {
                q.push(chkNode->rightChild);
            }
        }
        else {
            if (!q.empty()) q.push(NULL);
            l++;
        }
    }

    return max;
}

int sum_of_kth_level(treeNode* root, int level){
    if (root == 0) return -1;

    int sum = 0;
    int l = 0;

    queue <treeNode *> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        treeNode* current_node = q.front();

        q.pop();

        if (current_node != NULL) { 
            if (l == level) {
                sum += current_node->data;
            }

            if (current_node->leftChild != NULL) {
                q.push(current_node->leftChild);
            }
            if (current_node->rightChild != NULL) {
                q.push(current_node->rightChild);
            }
        }
        else {
            if (!q.empty()) {
                q.push(NULL);
            }
            l++;
        }
    }

    return sum;
}

treeNode* build_tree_pre_in(int pre[], int in[], int start, int end) {
    static int id = 0;

    int current = pre[id];

    id++;

    treeNode* new_node = new treeNode(current);

    if (start == end) new_node;

    int pos = search_inOrder(in, current, start, end);

    new_node->leftChild = build_tree_pre_in(pre, in, start, pos - 1);

    new_node->rightChild = build_tree_pre_in(pre, in, pos + 1, end);

    return new_node;
}

int search_inOrder(int in[], int current, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (current == in[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int pre[n], in[n];

    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    treeNode* root = build_tree_pre_in(pre, in, 0, n - 1);

    string chk = "";
    preOrder_traversal(root, chk);
    cout << chk << endl;
}

/*

9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

*/