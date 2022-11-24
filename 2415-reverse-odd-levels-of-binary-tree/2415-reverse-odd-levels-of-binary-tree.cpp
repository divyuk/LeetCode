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
    void pre(TreeNode* root1, TreeNode* root2, int l){
    if (root1 == NULL)
        return;

    if (l%2 == 0)
        swap(root1->val, root2->val);
 
    pre(root1->left, root2->right, l+1);
    pre(root1->right, root2->left, l+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        pre(root->left,root->right,0);
        return root;
    }
};