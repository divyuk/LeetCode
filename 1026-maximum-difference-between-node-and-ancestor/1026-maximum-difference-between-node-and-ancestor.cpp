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
    int maxD=0;
    
    void performCalc(TreeNode* root, TreeNode* child){
        if(root==NULL or child==NULL) return;
        maxD = max(maxD  , abs(root->val - child->val) );
        performCalc(root, child->left);
        performCalc(root , child->right);
    }
    
    void mainFun(TreeNode* root){
        if(root==NULL) return;
        performCalc(root, root->left);
        performCalc(root, root->right);
        
        mainFun(root->left);
        mainFun(root->right);
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        mainFun(root);
        return maxD;
    }
};