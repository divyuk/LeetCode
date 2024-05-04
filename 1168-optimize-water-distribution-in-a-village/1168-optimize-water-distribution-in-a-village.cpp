class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        typedef pair<int,int> P;
        unordered_map<int, vector<P>>adj;
        priority_queue<P,vector<P>,greater<P>>pq;
  
        // adding virtual edge
        
        for(int i =0;i< wells.size() ; ++i){
            adj[0].push_back({wells[i],i+1}); // cost, node
            pq.push({wells[i], i+1});
        }
      
        for(int i =0; i< pipes.size(); i++){
            int house1 = pipes[i][0];
            int house2 = pipes[i][1];
            int cost   = pipes[i][2];
            
            adj[house1].push_back({cost,house2});
            adj[house2].push_back({cost,house1});
        }
        vector<bool>visited(n+1,false);
        int cost = 0;
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