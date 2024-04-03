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
    
    int dia(TreeNode* root , int &ans){
        if(!root) return 0;
        int lh = dia(root->left, ans);
        int rh = dia(root->right, ans);
        ans = max(ans, 1+lh+rh);
        return  1 + max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;
        int x = dia(root,ans);
        return ans-1;
    }
};