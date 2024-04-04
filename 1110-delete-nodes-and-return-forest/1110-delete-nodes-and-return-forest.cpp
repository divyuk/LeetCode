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
    
    TreeNode* deleteHelper(TreeNode*root, unordered_set<int>&del, vector<TreeNode*>&result){
        if(!root) return nullptr;
        root->left = deleteHelper(root->left, del, result);
        root->right = deleteHelper(root->right, del, result);
        
        if(del.find(root->val)!=del.end()){
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
            return NULL;
        }        
        else return root;
    }
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>del(to_delete.begin(), to_delete.end());
        vector<TreeNode*>result;
        
        deleteHelper(root,del,result);
        if(del.find(root->val) == del.end() ) result.push_back(root);
        return result;
    }
};