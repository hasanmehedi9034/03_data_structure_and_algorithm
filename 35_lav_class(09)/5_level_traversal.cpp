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

int depth (TreeNode* root) {
    if (root == NULL) return 0;

    int x = depth(root->left);
    int y = depth(root->right);

    return max(x, y) + 1;
}

vector <vector <int> > level_order(TreeNode* root) {
    int n = depth(root);

    vector <vector <int> > ans(n);
    if (root == NULL) return ans;
    
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});
    while(!q.empty()){
        pair<TreeNode*, int> parent_node = q.front();
        q.pop();

        ans[parent_node.second].push_back(parent_node.first->value);

        if (parent_node.first->left) {
            q.push({parent_node.first->left, parent_node.second + 1});
        }

        if (parent_node.first->right) {
            q.push({parent_node.first->right, parent_node.second + 1});
        }
    }
    ans;
}

int main() {

}