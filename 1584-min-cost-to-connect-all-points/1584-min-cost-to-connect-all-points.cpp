class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        typedef pair<int,int>P;
        int n = points.size();
        unordered_map<int,vector<P>>adj; // i -> {cost,node}
        int cost =0;
        for(int i = 0;i<n;i++) {
            int x1 = points[i][0],y1 = points[i][1];
            for(int j = i+1; j< n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                int w = abs(x2-x1) + abs(y2-y1);
                adj[i].push_back({w,j});
                adj[j].push_back({w,i});
            }
        }
        
        
         // Printing the adjacency list
        // for (auto &[vertex, neighbors] : adj) {
        //     cout << "Vertex " << vertex << ": ";
        //     for (auto &[cost, node] : neighbors) {
        //         cout << "(" << cost << ", " << node << ") ";
        //     }
        //     cout << endl;
        // }
        
        // Prims algo 
        vector<bool>visited(n,false);
        priority_queue<P,vector<P>, greater<P>>pq;
        pq.push({0,0});// 0 weight , 0 index;

        while(!pq.empty()){
            P curr = pq.top();
            int wt = curr.first;
            int node = curr.second;
            pq.pop();
            if(!visited[node]){
                cost+=wt;
                visited[node] = true;
                for(auto i : adj[node]){
                    int c = i.first;
                    int v = i.second;
                    if(!visited[v]) pq.push({c,v});
                    
                }
            }
            
        }
        
        
        
       return cost; 
    }
};