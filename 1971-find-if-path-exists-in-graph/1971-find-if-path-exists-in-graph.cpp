class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int>q;
        vector<bool>visited(n,false);
        vector<int>adj_list[n];
        for(int i = 0 ;i < edges.size() ; i++){
            int j = edges[i][0];
            int k = edges[i][1];
            adj_list[k].push_back(j);
            adj_list[j].push_back(k);
        }
        // for(auto i : adj_list){
        //     for(auto l : i)
        //         cout<<l<<" ";
        //     cout<<"\n";
        // }
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int  u = q.front();
            q.pop();
            for(auto v : adj_list[u]){
                if(visited[v] == false){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return visited[destination];
    }
};