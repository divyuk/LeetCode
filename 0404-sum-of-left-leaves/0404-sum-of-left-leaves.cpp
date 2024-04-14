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
    int leftSum(TreeNode* root,bool isLeft){
        if(!root) return 0;
        if(!root->left and !root->right and isLeft) return root->val;
        int l = leftSum(root->left, true);
        int r = leftSum(root->right, false);
        return l+r;
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return leftSum(root, false);
        
    }
};