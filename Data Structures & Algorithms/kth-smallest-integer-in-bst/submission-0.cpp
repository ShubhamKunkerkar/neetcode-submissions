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
        vector<int> out;
        DFS(root, k, out);
        return out[k-1];
    }
    void DFS(TreeNode* root, int k, vector<int>& out){
        if(root == nullptr || k == 0)
            return;
        
        int level;
        DFS(root->left, k, out);
        k--;
        out.push_back(root->val);
        DFS(root->right, k, out);
    }
};