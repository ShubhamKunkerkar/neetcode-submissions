/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int mx = root->val;
        int out = 0;
        dfs(root, mx, out);
        return out;
    }
    void dfs(TreeNode* root, int mx, int &out){
        if(root == nullptr)
            return;
        if(root->val >= mx)
            out++;
        if (root->left != nullptr)
            dfs(root->left, max(mx, root->val),out);
        if (root->right != nullptr)
            dfs(root->right, max(mx, root->val),out);
    }
};