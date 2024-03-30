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
    void find (TreeNode* root , int &ans, int depth ){
        if(!root) return;
        if(!root->left and !root->right){
            ans = min(ans,depth);
            return;
        }
        find(root->left , ans , depth+1);
        find(root->right, ans , depth+1);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MAX;
        find(root, ans, 1);
        return ans;
    }
};