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
    vector<int> helper(TreeNode* node) {
        // return {rob this node, not rob this node}
        if (node == nullptr) {
            return {0, 0};
        }
        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);
        // if we rob this node, we cannot rob its children
        int rob = node->val + left[1] + right[1];
        // else, we are free to choose to rob its children or not
        int notRob = max(left[0], left[1]) + max(right[0], right[1]);

        return {rob, notRob};
    }
public:
    int rob(TreeNode* root) {
        vector<int> answer = helper(root);
        return max(answer[0], answer[1]);
    }
};