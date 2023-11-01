class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(adjList, visited, i);
                provinces++;
            }
        }

        return provinces;
    }

    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int city) {
        visited[city] = true;
        for (int neighbor : adjList[city]) {
            if (!visited[neighbor]) {
                dfs(adjList, visited, neighbor);
            }
        }
    }
};
