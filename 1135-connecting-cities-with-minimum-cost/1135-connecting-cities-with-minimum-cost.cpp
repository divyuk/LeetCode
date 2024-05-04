class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // Create an adjacency list to represent the graph
        vector<vector<pair<int, int>>> adjList(n + 1);
        // Fill the adjacency list from the given connections
        for (const auto& conn : connections) {
            int from = conn[0];
            int to = conn[1];
            int weight = conn[2];
            adjList[from].push_back({to, weight});
            adjList[to].push_back({from, weight}); // Undirected
        }

        // Use Prim's Algorithm to find the minimum spanning tree
        typedef pair<int, int> M;
        priority_queue<M, vector<M>, greater<M>> pq;
        vector<bool> visited(n + 1, false);
        int ans = 0;

        // Start from city 1
        pq.push({0, 1});

        while (!pq.empty()) {
            int w = pq.top().first;
            int c = pq.top().second;
            pq.pop();

            if (!visited[c]) {
                ans += w;
                visited[c] = true;

                for (const auto& neighbor : adjList[c]) {
                    int node = neighbor.first;
                    int weight = neighbor.second;
                    if (!visited[node])  pq.push({weight, node});
                }
            }
        }

        // Check if all cities are visited
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                return -1;
            }
        }

        return ans;
    }
};
