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
    int c =0;
    void preorder( TreeNode* root){
        /*
            In preorder:
            1) Visit Root
            2) preorder(root->left)
            3) prorder(root->right)
        */
        
        if(root == NULL){
            c++;
            return;
        }
        preorder(root->left);
        preorder(root->right);
    }
    
    int countNodes(TreeNode* root) {
        preorder(root);
        return c-1;
    }
};