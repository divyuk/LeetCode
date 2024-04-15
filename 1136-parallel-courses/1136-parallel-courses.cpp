class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>>adj;
        vector<int>indegree(n+1,0);
        
        for(int i = 0; i< relations.size() ; i++){
            int prevCourse = relations[i][0];
            int nextCourse = relations[i][1];
            adj[prevCourse].push_back(nextCourse);
            indegree[nextCourse]++;
        }
        
        queue<int>q;
      
        for(int i = 1; i<=n ; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        int sem=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();
                for(auto i : adj[curr]){
                    if(--indegree[i]==0)
                        q.push(i);

                }
            }
            sem++;
        }
        for(int i = 1; i<=n; i++){
            if(indegree[i] !=0) return -1;
        }
        return sem;
    }
};