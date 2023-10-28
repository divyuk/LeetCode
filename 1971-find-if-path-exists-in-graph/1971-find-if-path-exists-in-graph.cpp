class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>visited(n,false);
        // Converting it into adjancy list
        vector<int>adj_list[n];
        for(int j =0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
            
        }
        queue<int>q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj_list[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return visited[destination];
    }
};