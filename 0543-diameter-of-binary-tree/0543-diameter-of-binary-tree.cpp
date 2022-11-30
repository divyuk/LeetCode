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
    int ans=0;
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        ans = max(ans,1+lh+rh);
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        // we will say go to each node calculate its left subtree height then right subtree height add 1 to include the root. Keep holding the max.
        
        int node = height(root);
        return ans-1;
    }
};