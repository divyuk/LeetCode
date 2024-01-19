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
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> ans;

    TreeNode* current = root;

    while (current != nullptr || !stk.empty()) {
        // Traverse left until you reach the leftmost leaf
        while (current != nullptr) {
            stk.push(current);
            current = current->left;
        }

        // Process the current node
        current = stk.top();
        stk.pop();
        ans.push_back(current->val);

        // Move to the right subtree
        current = current->right;
    }

    return ans;
}
};