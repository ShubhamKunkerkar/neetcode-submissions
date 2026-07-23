/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr) return nullptr;
        DFS(root);
        return root;
    }

    TreeNode* DFS(TreeNode*& node){
        if(node == nullptr) return nullptr;

        TreeNode* left = DFS(node->left);
        TreeNode* right = DFS(node->right);

        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        return node;
    }
};