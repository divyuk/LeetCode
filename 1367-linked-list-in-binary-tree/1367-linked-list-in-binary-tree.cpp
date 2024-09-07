class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return checkPath(root, head);
    }

private:
    bool checkPath(TreeNode* node, ListNode* head) {
        if (!node) return false;
        if (dfs(node, head)) return true;  // If a matching path is found
        // Recursively check left and right subtrees
        return checkPath(node->left, head) || checkPath(node->right, head);
    }

    bool dfs(TreeNode* node, ListNode* head) {
        if (!head) return true;  // All nodes in the list matched
        if (!node)
            return false;  // Reached end of tree without matching all nodes
        if (node->val != head->val) return false;  // Value mismatch
        return dfs(node->left, head->next) || dfs(node->right, head->next);
    }
};