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

TreeNode* get_target_copy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (cloned == NULL) return NULL;
    if (cloned->value == target->value) return cloned;

    TreeNode* a = get_target_copy(original, cloned->left, target);
    TreeNode* b = get_target_copy(original, cloned->right, target);

    if (a != NULL) return a;
    else if (b != NULL) return b;
    else return NULL;
}

int main() {

}