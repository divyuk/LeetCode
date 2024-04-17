class Solution {
private:
        string smallestString;
        void dfs(TreeNode* root, string currentString) {
            if (!root)   return;
            currentString = char(root->val + 'a') + currentString; 

            if (!root->left && !root->right) { 
                // If the current string is smaller than the result 
                // or if the result is empty
                if (smallestString == "" || smallestString > currentString)
                    smallestString = currentString;
                
            }

            dfs(root->left, currentString);
            dfs(root->right, currentString);
            
        }
public:
        string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallestString;
    }
};