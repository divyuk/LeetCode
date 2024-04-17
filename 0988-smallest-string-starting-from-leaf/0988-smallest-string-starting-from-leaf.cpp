class Solution {
private:
        string smallestString;
        void dfs(TreeNode* root, string currentString) {


            if (!root)   return;


            // Construct the current string by appending 
            // the character corresponding to the node's value
            currentString = char(root->val + 'a') + currentString; 

            if (!root->left && !root->right) { 
                // If the current string is smaller than the result 
                // or if the result is empty
                if (smallestString == "" || smallestString > currentString) { 
                    smallestString = currentString;
                }
            }

            // Recursively traverse the left subtree
            // if (root->left) {
                dfs(root->left, currentString);
            // }

            // Recursively traverse the right subtree
            if (root->right) {
                dfs(root->right, currentString);
            }
        }
public:
        string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallestString;
    }
};