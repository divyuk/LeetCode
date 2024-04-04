class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        helper(root, toDelete, forest, true);
        return forest;
    }

private:
    TreeNode* helper(TreeNode* node, unordered_set<int>& toDelete, vector<TreeNode*>& forest, bool isRoot) {
        if (!node) return nullptr;

        bool deleted = toDelete.find(node->val) != toDelete.end();
        if (isRoot && !deleted) {
            forest.push_back(node);
        }

        node->left = helper(node->left, toDelete, forest, deleted);
        node->right = helper(node->right, toDelete, forest, deleted);

        return deleted ? nullptr : node;
    }
};