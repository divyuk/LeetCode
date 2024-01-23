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
    bool check(TreeNode* root , long min , long max){
        if(!root) return 1;
        if( !(root->val <max and root->val>min  ) ) return 0;
        return (check(root->left, min , root->val ) and 
                check(root->right , root->val , max ));
    }
    
    bool isValidBST(TreeNode* root) {
     long min = LONG_MIN;
     long max = LONG_MAX;

     return check(root,min,max);
    
    }
};