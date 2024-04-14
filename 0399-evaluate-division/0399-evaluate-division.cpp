class Solution {
private:
    double bfs(unordered_map<string, vector<pair<string, double>>>& adj, const string& src, const string& dest) {
        if (adj.find(src) == adj.end() || adj.find(dest) == adj.end()) return -1.0;
        
        set<string> visit;
        queue<pair<string, double>> q;
        q.push({src, 1.0});
        visit.insert(src);
        
        while (!q.empty()) {
            string node = q.front().first;
            double weight = q.front().second;
            q.pop();
            
            if (node == dest) return weight;
            
            for (const auto& neighbor : adj[node]) {
                string next = neighbor.first;
                double edgeWeight = neighbor.second;
                
                if (visit.find(next) == visit.end()) {
                    q.push({next, weight * edgeWeight});
                    visit.insert(next);
                }
            }
        }
        
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        
        // Build the adjacency list graph
        for (int i = 0; i < equations.size(); ++i) {
            const string& u = equations[i][0];
            const string& v = equations[i][1];
            double value = values[i];
            
            adj[u].push_back({v, value});
            adj[v].push_back({u, 1.0 / value});
        }
        
        // Perform BFS for each query
        vector<double> result;
        for (int i = 0; i < queries.size(); ++i) {
            const string& src = queries[i][0];
            const string& dest = queries[i][1];
            
            result.push_back(bfs(adj, src, dest));
        }
        
        return result;
    }
};


