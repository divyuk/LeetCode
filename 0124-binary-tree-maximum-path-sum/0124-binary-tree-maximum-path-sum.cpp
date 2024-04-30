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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumRecursive(root, maxSum);
        return maxSum;
    }
    
    int maxPathSumRecursive(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        
        // Calculate the maximum path sum in the left and right subtrees
        int leftSum = max(maxPathSumRecursive(node->left, maxSum), 0);
        int rightSum = max(maxPathSumRecursive(node->right, maxSum), 0);
        
        // Update the maximum path sum if the path through the current node is larger
        maxSum = max(maxSum, leftSum + rightSum + node->val);
        
        // Return the maximum sum of paths from the current node
        return max(leftSum, rightSum) + node->val;
    }
};