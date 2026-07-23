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
        queue<pair<TreeNode*, int>> nodes;
        int level = 0;
        nodes.push({root, level});
        TreeNode* curr = root;
        vector<vector<int>> out;
        if(root == nullptr)
            return out;
        out.push_back({root->val});
        while (true) {
            level = nodes.front().second + 1;
            vector<int> inner;
            while(nodes.front().second == level -1) {
                curr = nodes.front().first;
                if(curr->left != nullptr){
                    nodes.push({curr->left, level});
                    inner.push_back(curr->left->val);
                }
                if(curr->right != nullptr){
                    nodes.push({curr->right, level});
                    inner.push_back(curr->right->val);
                }
                nodes.pop();
            }
            if(!inner.empty())
                out.push_back(inner);
            if(nodes.empty()){
                return out;
            }
        }
        return out;
    }
};