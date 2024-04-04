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
    
    pair<int,int> avghelper(TreeNode* root, int &count){
        if(!root) return {0,0};
        
        pair<int,int>l = avghelper(root->left, count);
        pair<int,int>r = avghelper(root->right, count);
   
        int sum = (root->val + l.first +r.first);
        int nodeCount = l.second+r.second+1;
        if(sum/nodeCount == root->val) {count++;}
        cout<<sum<< " " <<nodeCount <<"\n"; 
        
        return {sum,nodeCount};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        avghelper(root, count);
        return count;
    }
};