#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) {
            value = val;
            left = NULL;
            right = NULL;
        }
};

string s = "";

void construct_str(TreeNode* root, string &s) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        s += to_string(root->value);
        return;
    }

    s += to_string(root->value);
    
    s += '(';
    construct_str(root->left, s);
    s += ')';

    if (root->right != NULL)  {
        s += '(';
        construct_str(root->right, s);
        s += ')';
    }
}

int main() {
    
}