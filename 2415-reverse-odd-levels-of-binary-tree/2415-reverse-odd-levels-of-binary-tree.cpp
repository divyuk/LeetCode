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
    void reverseMachine(TreeNode* root1,TreeNode* root2, int l){
        if(root1==NULL)
            return ;
        if(l%2==0)
            swap(root1->val , root2->val);
        reverseMachine(root1->left, root2->right, l+1);
        
        reverseMachine(root1->right , root2->left,l+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        reverseMachine(root->left , root->right,level);
        return root;
    }
};