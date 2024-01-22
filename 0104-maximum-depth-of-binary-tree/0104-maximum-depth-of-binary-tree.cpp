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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode* , int>>stk;
        int res=0,d=0;
        stk.push({root,1});
        while(!stk.empty()){
            TreeNode* node = stk.top().first;
            d = stk.top().second;
            stk.pop();
            if(node){
                res=max(res,d);
                d=d+1;
                if(node->right) stk.push({node->right , d});
                if(node->left) stk.push({node->left ,d});
            }
        }
        return res;
    }
    
};