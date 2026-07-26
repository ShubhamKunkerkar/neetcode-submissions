/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool out = true;
        dfs(root, LONG_MIN, LONG_MAX, out);
        return out;
    }
    void dfs(TreeNode* root, long min, long max, bool& out) {
        if (root == nullptr || !out) {
            return;
        }

        if (!(root->val > min && root->val < max)) {
            out = false;
            return;
        }
        dfs(root->left, min, root->val, out);
        dfs(root->right, root->val, max, out);
    }
};