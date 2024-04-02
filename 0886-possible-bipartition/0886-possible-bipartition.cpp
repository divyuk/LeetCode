class Solution {
public:
    bool bfsPossibleParition(unordered_map<int,vector<int>>&adj, int node, vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node]=1;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                if(color[v] == color[u]) return false;
                if(color[v] == -1) 
                {
                    color[v]= 1-color[u];
                    q.push(v);
                }
            }
            
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // Convert this to adjancy list
        unordered_map<int , vector<int>> adjList;
        vector<int>color(n+1, -1);
        for(vector<int>&vec : dislikes){
            int u = vec[0];
            int v = vec[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        for(int i = 1 ;i<=n; i++){
            
            if(color[i] == -1){
                if(bfsPossibleParition(adjList, i, color) == false) return false;
            }
        }
        
        return true;
    }
};