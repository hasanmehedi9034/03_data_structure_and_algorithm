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

bool ans = true;

int depth (TreeNode* root){
    if (root == NULL) return 0;

    int x = depth(root->left);
    int y = depth(root->right);

    if (abs(x - y) > 1) ans = false;

    return max(x, y) + 1;
}

int main() {
    
}