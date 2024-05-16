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
    bool traversal(TreeNode* root){
        
        // if(!root) return false;
        if(!root->left and !root->right) return root->val;
        
        
        return root->val ==2 ? (traversal(root->left) or traversal(root->right)) : (traversal(root->left) and traversal(root->right));
    }
public:
    bool evaluateTree(TreeNode* root) {
        return traversal(root);
    }
};