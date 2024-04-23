class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1) return {0};
        
        unordered_map<int, vector<int>>adj;
        vector<int>indegree(n,0);
        vector<int>result;
        queue<int>q;
        
        for(vector<int>e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        
    
        for(int i = 0; i< n ; i++){
            if(indegree[i] == 1) q.push(i); // Theses are leaves
        }
        
        while(n>2){
            
            int size = q.size();
            n-=size;
            while(size--){
                
                int node = q.front();
                q.pop();
                
                for(int i : adj[node]){
                    indegree[i]--;
                    if(indegree[i] == 1) q.push(i); 
                }
            } 
        }
        
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};