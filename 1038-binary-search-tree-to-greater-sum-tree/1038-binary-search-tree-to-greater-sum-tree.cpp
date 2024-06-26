class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = 0;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (!st.empty() or node != nullptr) {
            while (node != nullptr) {
                st.push(node);
                node = node->right;
            }

            // Store the top value of stack in node and pop it.
            node = st.top();
            st.pop();

            // Update value of node.
            nodeSum += node->val;
            node->val = nodeSum;

            // Move to the left child of node.
            node = node->left;
        }
        return root;
    }
};