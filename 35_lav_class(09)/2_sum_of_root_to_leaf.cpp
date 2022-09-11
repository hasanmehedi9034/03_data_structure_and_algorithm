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

int ans = 0;

int convert(string s) {
    int converted_ans = 0, c = 1;

    for (int i = s.size() - 1; i >= 0; i--) {
        converted_ans += (s[i] - '0') * c;
        c *= 2;
    }

    return converted_ans;
}

void solution(TreeNode* root, string s){
    if (root == NULL) return;

    if (root->left == NULL && root->right) {
        int val =  convert(s + to_string(root->value));
        ans += val;
        return;
    }

    solution(root->left, s + to_string(root->value));
    solution(root->right, s + to_string(root->value));
}

int sum_root_to_leaf(TreeNode* root) {
    solution(root, "");
    return ans;
}

int again_convert(string s) {
    int bi = 0;
    int c = 1;

    for (int i = s.size() - 1; i >= 0; i--) {
        bi += (s[i] - '0') * c;
        c *= 2;
    }
    return bi;
}

void solution2(TreeNode* root, string s) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL){
        int s3 = again_convert(s + to_string(root->value));
        ans += s3;
        return;
    }

    solution2(root->left, s);
    solution2(root->right, s);
}

int main() {
    cout << again_convert("101") << endl;
}