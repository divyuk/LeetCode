class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>indegree(n,0);
        vector<int>ans;
        for(auto it : pre){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(auto i : adj){
            for(int q : i) cout<< q <<" ";
            cout<<"\n";
        }
        queue<int>q;
        for(int i =0 ;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(ans.size()==n) return ans;
        return {};
    }
};