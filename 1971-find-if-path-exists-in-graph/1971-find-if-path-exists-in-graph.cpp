class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int>q;
        vector<bool>visited(n+1,false);
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int src = q.front();
            q.pop();
            for(auto i : adj[src]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        return visited[destination];
    }
};