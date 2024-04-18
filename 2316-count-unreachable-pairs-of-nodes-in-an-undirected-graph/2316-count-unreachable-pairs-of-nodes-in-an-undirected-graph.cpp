class Solution {
    void dfs(unordered_map<int, vector<int>>&adj, vector<bool>&visited, int node , long long& size){
        visited[node] = true;
        size++;
        for(int i : adj[node]){
            if(!visited[i]){
                dfs(adj,visited,i, size);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
        
        for(int i =0; i< edges.size() ; i++){
            int u= edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>visited(n,false);
        long long result = 0;
        long long size    = 0;
        long long currentRemaining = n;
        for(int i  = 0; i<n ; i++){
            if(!visited[i]){
                dfs(adj, visited, i , size);
                result += (size * (currentRemaining - size));
                currentRemaining = currentRemaining - size;
                size =0;
            }
        }
        return result;
    }
};