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
    int kthSmallest(TreeNode* root, int k) {
        int out;
        DFS(root, k, out);
        return out;
    }
    void DFS(TreeNode* root, int& k, int& out){
        if(root == nullptr || k == 0)
            return;
        DFS(root->left, k, out);
        if(k == 0)
            return;
        out = root->val;
        k--;
        DFS(root->right, k, out);
    }
};