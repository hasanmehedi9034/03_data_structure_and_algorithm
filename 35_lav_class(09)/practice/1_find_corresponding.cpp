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

TreeNode* get_target_copy (TreeNode* original, TreeNode*  cloned, TreeNode* target) {
    if (cloned == NULL) return NULL;

    if (cloned->value == target->value) return cloned;

    TreeNode* x = get_target_copy(original, cloned->left, target);
    TreeNode* y = get_target_copy(original, cloned->right, target);

    if(x != NULL) return x;
    else if (y != NULL) return y;
    else NULL;
}

int main() {

}