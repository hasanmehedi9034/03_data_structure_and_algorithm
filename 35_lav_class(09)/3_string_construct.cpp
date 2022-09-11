#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode (int val) {
            value = val;
            left = NULL;
            right = NULL;
        }
};

void solution(TreeNode* root, string &s) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        s += to_string(root->value);
        return;
    }

    s += to_string(root->value);

    s += '(';
    solution(root->left, s);
    s += ')';

    if (root->right != NULL) {
        s += '(';
        solution(root->right, s);
        s += ')';
    }
}

string tree2str(TreeNode* root) {
    string s = "";
    solution(root, s);
    return s;
}

int main() {

}