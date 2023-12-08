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
    
    void pre(TreeNode* root , string &ans){
        if(root==NULL) {
            return;
        }
        ans+= "(" + to_string(root->val);
        
        if(root->left == NULL and root->right) ans+="()";
        pre( root->left,ans);
        pre(root->right,ans);
        ans+=")";
    }
    
    string tree2str(TreeNode* root) {
        string ans="";
        pre(root,ans);
        string k = ans.substr(1,ans.size()-2);
        return k;
    }
};