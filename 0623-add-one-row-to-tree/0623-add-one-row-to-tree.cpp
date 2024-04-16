class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        addHelper(root, val, depth);
        return root;
    }

    void addHelper(TreeNode* node, int val, int depth) {
        if (!node) return;
        
        if (depth == 2) {
            TreeNode* newLeft = new TreeNode(val);
            newLeft->left = node->left;
            node->left = newLeft;
            
            TreeNode* newRight = new TreeNode(val);
            newRight->right = node->right;
            node->right = newRight;
            
            return;
        }
        
        addHelper(node->left, val, depth - 1);
        addHelper(node->right, val, depth - 1);
    }
};
