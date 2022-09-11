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

int depth (TreeNode* root){
    if (root == NULL) return 0;

    int x = depth(root->left);
    int y = depth(root->right);

    return max(x, y) + 1;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    int n = depth(root);
    vector<vector<int>> ans(n);

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        pair<TreeNode*, int> parent = q.front();
        q.pop();

        ans[parent.second].push_back(parent.first->value);

        if (parent.first->left) {
            q.push({parent.first->left, parent.second + 1});
        }

        if (parent.first->right) {
            q.push({parent.first->right, parent.second + 1});
        }
    }
    return ans;
}

int main() {
    TreeNode* root = NULL;

    int n = depth(root);
    vector<vector<pair<TreeNode*, int>>> v(n);

    
}