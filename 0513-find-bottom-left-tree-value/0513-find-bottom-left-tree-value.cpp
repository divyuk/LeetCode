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
    // Helper function to find the leftmost value in the last row
    void findLeftmost(TreeNode* root, int depth, int& maxDepth, int& leftmostValue) {
        if (!root) return;

        // If we have reached a new deeper level
        if (depth > maxDepth) {
            maxDepth = depth;
            leftmostValue = root->val;
        }

        // Traverse left before right to get the leftmost value
        findLeftmost(root->left, depth + 1, maxDepth, leftmostValue);
        findLeftmost(root->right, depth + 1, maxDepth, leftmostValue);
    }

    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int leftmostValue = root->val; // Initialize with root value
        findLeftmost(root, 1, maxDepth, leftmostValue);
        return leftmostValue;
    }
};
