class Solution {
private:
    void dfs(TreeNode* node, string& currentPath, string& smallestPath) {
        if (!node) return;
        
        currentPath += char('a' + node->val);  // Append the current node's character to the path
        
        if (!node->left && !node->right) {  // Leaf node
            // Compare the current path with the smallest path found so far
            // Update smallestPath if the current path is smaller
            string currentRev = currentPath;
            reverse(currentRev.begin(), currentRev.end());
            if (currentRev < smallestPath) {
                smallestPath = currentRev;
            }
        }
        
        // Recur for left and right children
        dfs(node->left, currentPath, smallestPath);
        dfs(node->right, currentPath, smallestPath);
        
        // Backtrack: remove the current node's character from the path
        currentPath.pop_back();
    }
    
public:
    string smallestFromLeaf(TreeNode* root) {
        string currentPath = "";
        string smallestPath = "~";  // Initialize with a path that is lexicographically larger than any valid path
        
        dfs(root, currentPath, smallestPath);
        
        // reverse(smallestPath.begin(), smallestPath.end());  // Reverse the path to get the correct order
        return smallestPath;
    }
    
};