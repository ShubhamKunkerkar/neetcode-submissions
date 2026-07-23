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
    int diameterOfBinaryTree(TreeNode* root) {
        int length = 0;
        diameter(root, length);
        return length;
    }
    int diameter(TreeNode* root, int& length) {
        if(root == nullptr){
            return 0;
        }
        int left = diameter(root->left, length);
        int right = diameter(root->right, length);
        length = max(length, left+right);
        return max(left, right) + 1;
    }
};