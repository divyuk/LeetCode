/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        if(root == p or root == q)
            return root;
        TreeNode* leftt = lowestCommonAncestor(root->left, p ,q);
        TreeNode* rightt = lowestCommonAncestor(root->right, p , q);
        
        if(leftt != NULL and rightt!= NULL)
            return root;
        else if(leftt!=NULL)
            return leftt;
        else
            return rightt;
    }
};