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
private:
    TreeNode* traversal(TreeNode* root, int target){
        if(!root) return NULL;
        if(!root->left and  !root->right and root->val ==target) return NULL;
        if(!root->left and  !root->right and root->val !=target) return root;
        TreeNode* l  = traversal(root->left , target);
        TreeNode* r = traversal(root->right, target);
        if(!l ) root->left  = NULL;
        if(!r ) root->right  = NULL;
       
        return root->val == target and !root->left and !root->right ? NULL: root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        traversal(root,target);
         if(!root->left and  !root->right and root->val ==target) return NULL;
        return root;
    }
};