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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> nodes;
        TreeNode* curr = root;
        nodes.push({root});
        vector<int> out;
        if(root == nullptr)
            return out;
        out.push_back(root->val);
        while (!nodes.empty()) {
            int size = nodes.size();
            for(int i =0; i < size; i++){
                curr = nodes.front();
                if(curr->left != nullptr){
                    nodes.push({curr->left});
                }
                if(curr->right != nullptr){
                    nodes.push({curr->right});
                }
                nodes.pop();
            }
            if(!nodes.empty())
                out.push_back(nodes.back()->val);
        }
        return out;
    }
};