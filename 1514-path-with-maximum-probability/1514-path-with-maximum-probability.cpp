class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start,int end){
       
        // data into adjList
        unordered_map<int, vector<pair<int, double> >> adj;
        for(int i =0; i<edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        
        typedef pair<double,int>P;
        priority_queue<P> pq;
        vector<double>ans(n,0);
        ans[start] = 1;
        pq.push({1,start});
        
        while(!pq.empty()){
            int node = pq.top().second;
            double currp = pq.top().first;
            pq.pop();
            for(auto x : adj[node]){
                int vertex = x.first;
                double prob =  x.second;
                double newProb = prob*currp;
                if(ans[vertex] < newProb){
                    ans[vertex] = newProb;
                    pq.push({newProb, vertex });
                }
                
            }
        }
        return ans[end];
    }
};

