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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        int level = 0;
        nodes.push({root});
        TreeNode* curr = root;
        vector<vector<int>> out;
        if(root == nullptr)
            return out;
        out.push_back({root->val});
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> inner;
            for(int i =0; i < size; i++){
                curr = nodes.front();
                if(curr->left != nullptr){
                    nodes.push({curr->left});
                    inner.push_back(curr->left->val);
                }
                if(curr->right != nullptr){
                    nodes.push({curr->right});
                    inner.push_back(curr->right->val);
                }
                nodes.pop();
            }
            if(!inner.empty())
                out.push_back(inner);
        }
        return out;
    }
};