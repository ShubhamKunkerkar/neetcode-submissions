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
    int maxPathSum(TreeNode* root) {
        int length = root->val;
        diameter(root, length);
        return length;
    }
    int diameter(TreeNode* root, int& length) {
        if(root == nullptr){
            return 0;
        }
        int left = diameter(root->left, length);
        int right = diameter(root->right, length);
        length = max(length, left+right + root->val);
        length = max(length, left + root->val);
        length = max(length, right + root->val);
        length = max(length, root->val);
        return max(max(left, right), 0)+root->val;
    }
};