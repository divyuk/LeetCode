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
    int minDepth(TreeNode* root) {
        if (!root) return 0; // Check for empty tree

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1; // Start depth at 1, as we are counting nodes

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check if this node is a leaf
                if (!node->left && !node->right) {
                    return depth; // Return the current depth as soon as we find a leaf
                }

                // Add child nodes to the queue if they exist
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            depth++; // Increment depth for each level of the tree
        }
        return depth;
    }
};