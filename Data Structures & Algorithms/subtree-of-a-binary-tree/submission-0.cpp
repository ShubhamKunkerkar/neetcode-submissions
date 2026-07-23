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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool out = false;
        
        return isSubtree2(root, subRoot, out);
    }

    bool isSubtree2(TreeNode* &root, TreeNode* &subRoot, bool& out) {
        if (root == nullptr)
            return false;
        if (root->val == subRoot->val) {
            bool left = isSubtree3(root->left, subRoot->left);
            bool right = isSubtree3(root->right, subRoot->right);
            if (left && right)
                out = true;
        }
        if(!out){
            isSubtree2(root->left, subRoot, out);
            isSubtree2(root->right, subRoot, out);
        }
        return out;
    }
    bool isSubtree3(TreeNode* &root, TreeNode* &subRoot) {
        if (root == nullptr ^ subRoot == nullptr)
            return false;
        else if (root == nullptr && subRoot == nullptr)
            return true;
        if (root->val == subRoot->val) {
            bool left = isSubtree3(root->left, subRoot->left);
            bool right = isSubtree3(root->right, subRoot->right);
            if (left && right)
                return true;
        }
        return false;
    }
};