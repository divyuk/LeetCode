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
    void pre(TreeNode* root , int maxValue , int &res){
        if(!root) return;
        if(maxValue<=root->val) res++;
        maxValue = max(root->val, maxValue);
        pre(root->left , maxValue, res);
        pre(root->right, maxValue,res);
    }
    
    int goodNodes(TreeNode* root) {
        int res=0;
        pre(root,root->val, res);
        return res;
    }
};