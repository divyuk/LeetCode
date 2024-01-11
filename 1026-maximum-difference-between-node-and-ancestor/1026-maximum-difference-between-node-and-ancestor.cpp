
class Solution {
public:
    int func(TreeNode* root , int maxv, int minv){
        if(!root) return abs(maxv-minv);
        maxv = max(maxv , root->val);
        minv = min(minv, root->val);
        
        int l = func(root->left, maxv, minv);
        int r = func(root->right, maxv, minv);
        
        return max(l,r);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxv=root->val,minv=root->val;
        int ans = func(root, maxv , minv );
        return ans;
    }
};