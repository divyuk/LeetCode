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
private:
    unordered_map<TreeNode*, int> robResult;
    unordered_map<TreeNode*, int> notRobResult;

    int helper(TreeNode* node, bool parentRobbed) {
        if (node == nullptr) return 0;
        
        if (parentRobbed) {
            if (robResult.find(node) != robResult.end()) return robResult[node];
            
            int result = helper(node->left, false) + helper(node->right, false);
            robResult[node] = result;
            return result;
        } else {
            if (notRobResult.find(node) != notRobResult.end()) return notRobResult[node];
            int rob = node->val + helper(node->left, true) + helper(node->right, true);
            int notRob = helper(node->left, false) + helper(node->right, false);
            int result = max(rob, notRob);
            notRobResult[node] = result;
            return result;
        }
    }
public:
    int rob(TreeNode* root) {
        return helper(root, false);
    }
};