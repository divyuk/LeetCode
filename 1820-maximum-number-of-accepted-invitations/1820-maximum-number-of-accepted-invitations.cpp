class Solution {
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Construct the bipartite graph
        vector<vector<int>> graph(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    graph[i].push_back(j);
                }
            }
        }
        
        // Perform maximum matching using bipartite graph algorithm (e.g., Hopcroft-Karp)
        vector<int> match(n, -1); // match[i] stores the index of the girl matched with boy i
        int result = 0;
        for (int i = 0; i < m; ++i) {
            vector<bool> visited(n, false);
            if (dfs(i, graph, visited, match)) {
                ++result;
            }
        }
        
        return result;
    }
    
    bool dfs(int u, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& match) {
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                if (match[v] == -1 || dfs(match[v], graph, visited, match)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
};