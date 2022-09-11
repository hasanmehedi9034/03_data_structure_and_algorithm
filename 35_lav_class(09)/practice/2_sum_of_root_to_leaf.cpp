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

int sum = 0;

int convert(string s) {
    int c = 1;

    int bi = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        bi += (s[i] - '0') * c;
        c *= 2;
    }
    return bi;
}

void solution(TreeNode* root, string s) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        int val = convert(s + to_string(root->value));
        sum += val;
    }

    solution(root->left, s + to_string(root->value));
    solution(root->right, s + to_string(root->value));
}

int main() {
    // cout << convert("101") << endl;
    string s = "";
    
}