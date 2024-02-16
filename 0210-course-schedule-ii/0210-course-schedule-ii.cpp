class Solution {
public:
    bool dfs(int crs, vector<bool>& visited, vector<bool>& cycle, vector<int>& ans, vector<vector<int>>& adj_list) {
        if (visited[crs]) return cycle[crs]; // If already visited and in current path, it means cycle exists.
        visited[crs] = true;
        for (int p : adj_list[crs]) {
            if (!dfs(p, visited, cycle, ans, adj_list)) return false;
        }
        cycle[crs] = true; // Mark in current path
        ans.push_back(crs); // After traversing children, push the course to result.
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses); // Adjacency list for representing the graph
        for (auto& pre : prerequisites) {
            adj_list[pre[1]].push_back(pre[0]); // Constructing the adjacency list
        }
        
        vector<int> ans; // Result vector
        vector<bool> visited(numCourses, false); // To track visited nodes
        vector<bool> cycle(numCourses, false); // To track nodes in current path (for cycle detection)
        
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, visited, cycle, ans, adj_list)) return {}; // If cycle detected, return empty array.
        }
        
        reverse(ans.begin(), ans.end()); // Since we are pushing courses after visiting children, we need to reverse the result.
        return ans;
    }
};
