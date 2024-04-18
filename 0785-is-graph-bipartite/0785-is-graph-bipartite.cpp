class Solution {
    
    bool bfs(unordered_map<int, vector<int>>& adj, vector<int> &visited, int start){
        queue<int>q;
        q.push(start);
        visited[start] = 0;
        while(!q.empty()){
            int u  = q.front();
            q.pop();
            for(int v : adj[u]){
                if(visited[v] == -1){
                    visited[v] = !visited[u];
                    q.push(v);
                }
                else if(visited[v] == visited[u]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i< n ; i++){
            for(int v : graph[i] ){
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }
        vector<int> visited(n, -1);
        for(int i = 0; i<n; i++){
            if(visited[i] == -1){
                if(bfs(adj, visited, i) == false) return false;
            }
        }
        
        return true;
    }
};