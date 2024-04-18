class Solution {
    bool dfs(int u, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& match) {
        for (int v : graph[u]) { 
            if (!visited[v]) { // if the person has not visited
                visited[v] = true;
                // if girl is not yet taken
                if (match[v] == -1 || dfs(match[v], graph, visited, match)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        int m = grid.size(); // m boys (person)
        int n = grid[0].size(); // n girls (jobs)
        
        // Construct the bipartite graph
        vector<vector<int>> graph(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)  graph[i].push_back(j);
            }
        }
        
        // Perform maximum matching using bipartite graph algorithm (e.g., Hopcroft-Karp)
        vector<int> match(n, -1); // match[i] stores the index of the girl matched with boy i
        int result = 0;
        for (int i = 0; i < m; ++i) {
            vector<bool> visited(n, false); // start fresh for the new person
            if (dfs(i, graph, visited, match)) ++result;
        }
        return result;
    }

};


// https://www.youtube.com/watch?v=LpRaOYy8Ogw